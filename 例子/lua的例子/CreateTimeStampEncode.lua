local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s hashAlgo inFileName policy hasCert reqFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(ToANSIString("\tinFileName：要进行时间戳的文件名"))
    print(ToANSIString("\tpolicy：时间戳策略OID，空串则不编码"))
    print(ToANSIString("\thasCert：true为要求响应带证书，false为要求响应不带证书"))
    print(ToANSIString("\treqFileName：时间戳请求的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t编码时间戳请求"))
end

function GetHashAlgo(hashAlgo)
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


local argCount=#arg
if argCount~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local hashAlgo=GetHashAlgo(arg[1])
if not hashAlgo then
    print(ToANSIString("未知Hash算法"));
    os.exit(-1)
end

local fileName=arg[2]
local policy=arg[3]
local hasCert=arg[4]:upper()
if hasCert=="TRUE" then
    hasCert=true
elseif hasCert=="FALSE" then
    hasCert=false
else
    Usage(arg[0])
    os.exit(-1)
end
local reqFileName=arg[5]

local hashValue=HashFile(hashAlgo,fileName)
if hashValue==nil then
    print(ToANSIString("Hash文件失败"));
    os.exit(-1)
end

local timestampObj=assert(CryptCore.NewTimeStamp())

assert(timestampObj:SetHashAlgorithm(hashAlgo))
assert(timestampObj:SetHashValue(hashValue))
assert(timestampObj:SetCertReq(hasCert))
if #policy~=0 then
    if not timestampObj:SetPolicy(policy) then
        timestampObj:Free()
        print(ToANSIString("设置策略OID失败"));
        os.exit(-1)
    end
end

--assert(timestampObj:SetNoNonce())
--assert(timestampObj:AddReqExt("1.2.3.4.5",false,CryptCore.HexDecode("0500")))

local data=timestampObj:EncodeReq()
timestampObj:Free()
if data==nil then
    print(ToANSIString("时间戳请求编码失败"))
    os.exit(-1)
end

if not Save(reqFileName,data) then
    print(ToANSIString("保存时间戳请求失败"))
end
print(ToANSIString("成功"))
