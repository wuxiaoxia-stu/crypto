local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName algo inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：签名证书文件"))
    print(ToANSIString("\talgo：签名算法，比如:SHA1WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tinFileName：要进行签名的原文文件名"))
    print(ToANSIString("\toutFileName：签名得到的签名文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行不带原文的SignedData签名运算，结果保存到outFileName文件中"))
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

function GetSignAlgo(signAlgo)
    signAlgo=signAlgo:upper()
    if signAlgo== "SHA1WITHRSA" or hashAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA1WITHRSA,CryptCore.Const.SHA1
    elseif  signAlgo== "SHA224WITHRSA" or signAlgo== "SHA224WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA224WITHRSA,CryptCore.Const.SHA224
    elseif  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA256WITHRSA,CryptCore.Const.SHA256
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA384WITHRSA,CryptCore.Const.SHA384
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA512WITHRSA,CryptCore.Const.SHA512
    elseif  signAlgo== "MD5WITHRSA" or signAlgo== "MD5WITHRSAENCRYPTION" then
        return CryptCore.Const.MD5WITHRSA,CryptCore.Const.MD5
    elseif  signAlgo== "SHA512/224WITHRSA" or signAlgo== "SHA512/224WITHRSAENCRYPTION" then
        return 34,0x8000
    elseif  signAlgo== "SHA512/256WITHRSA" or signAlgo== "SHA512/256WITHRSAENCRYPTION" then
        return 35,0x9000
    elseif  signAlgo== "SHA3-224WITHRSA" or signAlgo== "SHA3-224WITHRSAENCRYPTION" then
        return 36,0xA000
    elseif  signAlgo== "SHA3-256WITHRSA" or signAlgo== "SHA3-256WITHRSAENCRYPTION" then
        return 37,0xB000
    elseif  signAlgo== "SHA3-384WITHRSA" or signAlgo== "SHA3-384WITHRSAENCRYPTION" then
        return 38,0xC000
    elseif  signAlgo== "SHA3-512WITHRSA" or signAlgo== "SHA3-512WITHRSAENCRYPTION" then
        return 39,0xD000
    elseif  signAlgo== "SM3WITHSM2" then
        return CryptCore.Const.SM3WITHSM2,CryptCore.Const.SM3
    elseif  signAlgo== "ECDSAWITHSHA1" then
        return CryptCore.Const.ECDSAWITHSHA1,CryptCore.Const.SHA1
    elseif  signAlgo== "ECDSAWITHSHA224" then
        return CryptCore.Const.ECDSAWITHSHA224,CryptCore.Const.SHA224
    elseif  signAlgo== "ECDSAWITHSHA256" then
        return CryptCore.Const.ECDSAWITHSHA256,CryptCore.Const.SHA256
    elseif  signAlgo== "ECDSAWITHSHA384" then
        return CryptCore.Const.ECDSAWITHSHA384,CryptCore.Const.SHA384
    elseif  signAlgo== "ECDSAWITHSHA512" then
        return CryptCore.Const.ECDSAWITHSHA512,CryptCore.Const.SHA512
    elseif  signAlgo== "ECDSAWITHSHA3-224" then
        return 40,0xA000
    elseif  signAlgo== "ECDSAWITHSHA3-256" then
        return 41,0xB000
    elseif  signAlgo== "ECDSAWITHSHA3-384" then
        return 42,0xC000
    elseif  signAlgo== "ECDSAWITHSHA3-512" then
        return 43,0xD000
    else
        return nil;
    end
end

local argCount=#arg
if argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end


local cert=GetCert(arg[1])

if cert==nil then
    print(ToANSIString("读文件失败或者不是证书文件"));
    os.exit(-1)
end

if cert:InValidity()==false then
    cert:Free()
    print(ToANSIString("证书不在有效期内"));
    os.exit(-1)
end

if cert:Match("CertType='Signature'")==false then
    cert:Free()
    print(ToANSIString("不是签名证书"));
    os.exit(-1)
end

local algo,hashAlgo=GetSignAlgo(arg[2])
if algo==nil then
    cert:Free()
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end

local inFileName=arg[3]
local outFileName=arg[4]

local sign=assert(CryptCore.NewSignedData(true))
local keypair=cert:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN)
if keypair==nil then
    cert:Free()
    print(ToANSIString("没有私钥"));
    os.exit(-1)
end
keypair:Free()
assert(sign:SetSignCert(cert))
cert:Free()

assert(sign:SetDetached(true))
assert(sign:SetSignAlgorithm(algo,0))
assert(sign:SetUseSigningTime(false,0))


local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local hashObj=assert(CryptCore.NewHash(hashAlgo))


while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    hashObj:Update(data)
end

fIn:close()

local hashValue=hashObj:Final()
hashObj:Free()
assert(sign:SetHashValue(0,hashValue))
local outData=sign:Sign("")
sign:Free()
if not outData then
    fOut:close()
    print(ToANSIString("签名失败"))
    os.exit(-1)
end

local fOut=assert(io.open(outFileName,"wb"))
fOut:write(outData)
fOut:close()
print(ToANSIString("签名成功"))


