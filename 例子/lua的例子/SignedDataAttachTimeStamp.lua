local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s oldSignFileName url hasAlgo newSignFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\toldSignFileName：SignedData文件"))
    print(ToANSIString("\turl：时间戳URL"))
    print(ToANSIString("\talgo：HASH算法，比如:SHA-256之类"))
    print(ToANSIString("\tnewSignFileName：追加时间戳后的SignedData文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对带原文的SignedData文件oldSignFileName追加时间戳，结果保存到newSignFileName文件中"))
end



function GetCert(filename)
    local fIn=io.open(filename,"rb")
    if fIn==nil then
        return nil
    end
    local inData=fIn:read("*a")
    fIn:close()
    
    return CryptCore.NewCert(inData)
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

local argCount=#arg
if argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end


local url=arg[2]

local algo=GetHashAlgo(arg[3])
if algo==nil then
    print(ToANSIString("不支持的Hash算法"));
    os.exit(-1)
end

local inFileName=arg[1]
local outFileName=arg[4]

local sign=assert(CryptCore.NewSignedData(false))

assert(sign:SetKeepTbs(true))

local data
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

data=fIn:read("*a")
fIn:close()

if not sign:Verify(data) then
    cert:Free()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end


if not sign:AttachSignatureTimeStamp(0,algo,url) then
	sign:Free()
    print(ToANSIString("追加时间戳失败"))
    os.exit(-1)
end

local outData=sign:Encode()
sign:Free()
if outData==nil then
	print(ToANSIString("重新编码SignedData失败"))
    os.exit(-1)
end
fOut=io.open(outFileName,"wb")
if fOut==nil then
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

fOut:write(outData)
fOut:close()

print(ToANSIString("签名成功"))


