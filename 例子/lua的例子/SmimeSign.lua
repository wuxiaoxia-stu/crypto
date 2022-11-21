local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s [-detached] certFileName algo inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-detached：如果存在表示分离式，否则为包含式"))
    print(ToANSIString("\tcertFileName：签名证书文件"))
    print(ToANSIString("\talgo：签名算法，比如:SHA1WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tinFileName：要进行签名的MIME文件名"))
    print(ToANSIString("\toutFileName：签名得到的签名S/MIME文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行带原文的SignedData签名运算，结果保存到outFileName文件中"))
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

function GetCert(filename)
    
    local inData=GetFileConetent(filename)
    if inData==nil then
        return nil
    end
    
    return CryptCore.NewCert(inData)
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

function GetSignAlgo(signAlgo)
    signAlgo=signAlgo:upper()
    if signAlgo== "SHA1WITHRSA" or hashAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA1WITHRSA
    elseif  signAlgo== "SHA224WITHRSA" or signAlgo== "SHA224WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA224WITHRSA
    elseif  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA256WITHRSA
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA384WITHRSA
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA512WITHRSA
    elseif  signAlgo== "MD5WITHRSA" or signAlgo== "MD5WITHRSAENCRYPTION" then
        return CryptCore.Const.MD5WITHRSA
    elseif  signAlgo== "SHA512/224WITHRSA" or signAlgo== "SHA512/224WITHRSAENCRYPTION" then
        return 34
    elseif  signAlgo== "SHA512/256WITHRSA" or signAlgo== "SHA512/256WITHRSAENCRYPTION" then
        return 35
    elseif  signAlgo== "SHA3-224WITHRSA" or signAlgo== "SHA3-224WITHRSAENCRYPTION" then
        return 36
    elseif  signAlgo== "SHA3-256WITHRSA" or signAlgo== "SHA3-256WITHRSAENCRYPTION" then
        return 37
    elseif  signAlgo== "SHA3-384WITHRSA" or signAlgo== "SHA3-384WITHRSAENCRYPTION" then
        return 38
    elseif  signAlgo== "SHA3-512WITHRSA" or signAlgo== "SHA3-512WITHRSAENCRYPTION" then
        return 39
    elseif  signAlgo== "SM3WITHSM2" then
        return CryptCore.Const.SM3WITHSM2
    elseif  signAlgo== "ECDSAWITHSHA1" then
        return CryptCore.Const.ECDSAWITHSHA1
    elseif  signAlgo== "ECDSAWITHSHA224" then
        return CryptCore.Const.ECDSAWITHSHA224
    elseif  signAlgo== "ECDSAWITHSHA256" then
        return CryptCore.Const.ECDSAWITHSHA256
    elseif  signAlgo== "ECDSAWITHSHA384" then
        return CryptCore.Const.ECDSAWITHSHA384
    elseif  signAlgo== "ECDSAWITHSHA512" then
        return CryptCore.Const.ECDSAWITHSHA512
    elseif  signAlgo== "ECDSAWITHSHA3-224" then
        return 40
    elseif  signAlgo== "ECDSAWITHSHA3-256" then
        return 41
    elseif  signAlgo== "ECDSAWITHSHA3-384" then
        return 42
    elseif  signAlgo== "ECDSAWITHSHA3-512" then
        return 43
    else
        return nil;
    end
end

local argCount=#arg
if argCount~=4 and argCount~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local detached=false
if argCount==5 then
    if arg[1]~="-detached" and arg[1]~="/detached" then
        Usage(arg[0])
        os.exit(-1)
    end
    detached=true
    pos=2
end

local cert=GetCert(arg[pos])
pos=pos+1

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

local algo=GetSignAlgo(arg[pos])
pos=pos+1
if algo==nil then
    cert:Free()
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end

local inFileName=arg[pos]
pos=pos+1
local outFileName=arg[pos]

local sign=assert(CryptCore.NewSignedData(true))
assert(sign:SetSignCert(cert))
cert:Free()

assert(sign:SetDetached(detached))
assert(sign:SetSignAlgorithm(algo,0))

local data=GetFileConetent(inFileName)
if data==nil then
    sign:Free()
    print(ToANSIString(string.format("读文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local mime=CryptCore.NewMime(data)
if mime==nil then
    sign:Free()
    print(ToANSIString(string.format("文件(%s)不是MIME文件",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local smime=mime:Sign(sign,detached)
sign:Free()
mime:Free()

if smime==nil then
    print(ToANSIString("签名失败"))
    os.exit(-1)
end

if detached then
    assert(smime:AddHeader("MIME-Version:1.0"))
end
local outData=smime:Encode()
smime:Free()

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("签名成功"))

