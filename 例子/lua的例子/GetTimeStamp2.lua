local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s url hashAlgo certFileName inFileName timeTokenFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\turl：时间戳服务器的URL"))
    print(ToANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(ToANSIString("\tcertFileName：时间戳证书的文件名"))
    print(ToANSIString("\tinFileName：要进行时间戳的文件名"))
    print(ToANSIString("\ttimeTokenFileName：时间戳Token的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t获取时间戳"))
end

function getHashAlgo(hashAlgo)
    hashAlgo=hashAlgo:upper()
    if hashAlgo== "SHA-1" or hashAlgo=="SHA1" then
        return CryptCore.Const.SHA1
    elseif  hashAlgo== "SM3" then
        return CryptCore.Const.SM3
    elseif  hashAlgo== "MD5" then
        return CryptCore.Const.MD5
    elseif hashAlgo== "SHA-224" or hashAlgo=="SHA224" then
        return CryptCore.Const.SHA224
    elseif hashAlgo== "SHA-256" or hashAlgo=="SHA256" then
        return CryptCore.Const.SHA256
    elseif hashAlgo== "SHA-384" or hashAlgo=="SHA384" then
        return CryptCore.Const.SHA384
    elseif hashAlgo== "SHA-512" or hashAlgo=="SHA512" then
        return CryptCore.Const.SHA512
    elseif hashAlgo== "SHA-512/224" then
        return CryptCore.Const["SHA-512/224"]
    elseif hashAlgo== "SHA-512/256" then
        return CryptCore.Const["SHA-512/256"]
    elseif hashAlgo== "SHA3-224" then
        return CryptCore.Const["SHA3-224"]
    elseif hashAlgo== "SHA3-256" then
        return CryptCore.Const["SHA3-256"]
    elseif hashAlgo== "SHA3-384" then
        return CryptCore.Const["SHA3-384"]
    elseif hashAlgo== "SHA3-512" then
        return CryptCore.Const["SHA3-512"]
    else
        return nil;
    end
end

function NewHash(hashAlgo)
    return CryptCore.NewHash(hashAlgo)
end

function HashFile(hashAlgo,fileName)
    local hashObj
    local fIn
    local data
    local BLOCK_LEN=8192
    local hashValue

    fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end

    hashObj=assert(NewHash(hashAlgo))

    while (true) do
     
        data=fIn:read(BLOCK_LEN)
        if not data then
            break
        end

        hashObj:Update(data)
    end

    fIn:close()

    hashValue=hashObj:Final()
    hashObj:Free()
    
    return hashValue
end

function Save(fileName,data)
    local fOut=io.open(fileName,"wb")
    if fOut==nil then
        return false
    end
    fOut:write(data)
    fOut:close()    
    return true
end

function GetCert(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return CryptCore.NewCert(inData)
end

local argCount=#arg
if argCount~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local url=arg[1]

local hashAlgo=getHashAlgo(arg[2])
if not hashAlgo then
    print(ToANSIString("未知Hash算法"));
    os.exit(-1)
end

local cert=GetCert(arg[3])
if cert==nil then
    print(toANSIString("读证书文件失败"));
    os.exit(-1)
end

local fileName=arg[4]
local tsTokenFileName=arg[5]
local hashValue=HashFile(hashAlgo,fileName)

if hashValue==nil then
    cert:Free()
    print(ToANSIString("Hash文件失败"));
    os.exit(-1)
end


local timestampObj=assert(CryptCore.NewTimeStamp())
if not timestampObj:SetTSA(url) then
    cert:Free()
    timestampObj:Free()
    print(ToANSIString("设置时间戳URL失败"));
    os.exit(-1)
end

assert(timestampObj:SetHashAlgorithm(hashAlgo))
assert(timestampObj:SetHashValue(hashValue))

assert(timestampObj:SetCertReq(false))
assert(timestampObj:SetTSACert(cert))
cert:Free()
local respCode=timestampObj:GetResponse()

if respCode==nil then
    timestampObj:Free()
    print(ToANSIString("获取时间戳响应失败"))
    os.exit(-1)
end

if respCode~=CryptCore.Const.TIMESTAMP_RESP_STATUS_GRANTED
    and respCode~=CryptCore.Const.TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS then
    timestampObj:Free()
    print(ToANSIString(string.format("获取时间戳响应失败，错误代码：%d",respCode)))
    os.exit(-1)
end

print(ToANSIString(string.format("时间戳策略：%s",timestampObj:GetPolicy())))
print(ToANSIString(string.format("时间戳时间：%s",timestampObj:GetTime())))
local second,millis,micros=timestampObj:GetAccuracy()

if second==nil then
    print(ToANSIString("获取时间误差失败"))
elseif second==false then
    print(ToANSIString("响应中没有时间误差"))
else
    if millis==0 and micros==0 then
        print(ToANSIString(string.format("时间误差为%d秒",second)))
    else
        print(ToANSIString(string.format("时间误差为%f秒",second+millis/1000+micros/1000000)))
    end
end

print(ToANSIString(string.format("时间戳序列号：%s",timestampObj:GetSerialNumber())))

local cert=assert(timestampObj:GetTSACert())
print(ToANSIString(string.format("时间戳证书的主体:%s",cert:GetSubject())))
cert:Free()

local token=timestampObj:GetTimeStampToken()
timestampObj:Free()

if token==nil then
    print(ToANSIString("获取时间戳Token失败"))
    os.exit(-1)
end

if not Save(tsTokenFileName,token) then
    print(ToANSIString("保存时间戳Token失败"))
end
