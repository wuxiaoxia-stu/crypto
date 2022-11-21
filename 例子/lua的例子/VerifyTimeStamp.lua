local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s dataFileName timestampTokenFileName [certFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tdataFileName：要进行时间戳的文件名"))
    print(ToANSIString("\ttimestampTokenFileName：时间戳Token的文件名"))
    print(ToANSIString("\tcertFileName：时间戳证书的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证证书请求"))
end


function GetFileConetent(fileName)
    local fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end
    local data=fIn:read("*a")
    fIn:close()
    
    return data
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

local argCount=#arg
if argCount~=2 and argCount~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local dataFileName=arg[1]
local tokenFileName=arg[2]
local token=GetFileConetent(tokenFileName)
if token==nil then
    print(ToANSIString("读时间戳Token文件失败"));
    os.exit(-1)
end

local cert
local timestampObj
if argCount==2 then
    timestampObj=CryptCore.VerifyTimeStampToken(token)
else
    local certFileName=arg[3]
    local data=GetFileConetent(certFileName)
    if data==nil then
        print(ToANSIString("读时间戳证书文件失败"));
        os.exit(-1)
    end
    cert=CryptCore.NewCert(data)
    if cert==nil then
        print(ToANSIString("不是证书文件"));
        os.exit(-1)
    end
    timestampObj=CryptCore.VerifyTimeStampToken(token,cert)
    cert:Free()
end

if timestampObj==nil then
    print(ToANSIString("验证时间戳证书文件失败"));
    os.exit(-1)
end

local hashValue=HashFile(timestampObj:GetHashAlgorithm(),dataFileName)
if hashValue==nil then
    timestampObj:Free()
    print(ToANSIString("对要进行时间戳的文件进行Hash失败"));
    os.exit(-1)
end

local hashValue2=timestampObj:GetHashValue()
if hashValue~=hashValue2 then
    timestampObj:Free()
    print(ToANSIString("Hash值不匹配"));
    os.exit(-1)
end

print(ToANSIString("验证时间戳证书文件成功"));

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

cert=assert(timestampObj:GetTSACert())
print(ToANSIString(string.format("时间戳证书的主体:%s",cert:GetSubject())))
cert:Free()

local token=timestampObj:GetTimeStampToken()
timestampObj:Free()

if token==nil then
    print(ToANSIString("获取时间戳Token失败"))
    os.exit(-1)
end
