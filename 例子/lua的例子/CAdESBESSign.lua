local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s [-detached] certFileName  algo inFileName outFileName",filename))
    print(ToANSIString("参数"))
	print(ToANSIString("\t-detached：使用不带原文的签名"))
    print(ToANSIString("\tcertFileName：签名证书文件"))
	print(ToANSIString("\talgo：签名算法，比如:SHA1WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tinFileName：要进行签名的原文文件名"))
    print(ToANSIString("\toutFileName：签名得到的签名文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行不带原文的SignedData签名得到CAdES-BES，结果保存到outFileName文件中"))
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
	local data=GetFileConetent(filename)
    if data==nil then
        return nil
    end
    
    return CryptCore.NewCert(data)
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
    if signAlgo== "SHA1WITHRSA" or signAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" then
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
	pos=2
	detached=true
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
local outFileName=arg[pos+1]

local tbs=GetFileConetent(inFileName)
if tbs==nil then
	cert:Free()
    print(ToANSIString("读原文文件失败"));
    os.exit(-1)
end

local sign=assert(CryptCore.NewSignedData(true))
assert(sign:SetSignCert(cert))


assert(sign:SetDetached(detached))
assert(sign:SetSignAlgorithm(algo,0))

local certPath=cert:GetCertPath()
if certPath==nil then
    sign:Free()
    cert:Free()
    print(ToANSIString("构造证书链失败"));
    os.exit(-1)
end
cert:Free()

assert(sign:SetIncludeCertOption(CryptCore.Const.SIGNEDDATA_INCLUDECERTOPTION_NONE))

for i,v in ipairs(certPath) do
    assert(sign:AddCert(v))
end

if not sign:SetSigningCertificateAttribute(0,CryptCore.Const.SHA256,true,certPath) then
    sign:Free()
    print(ToANSIString("设置V2签名证书属性失败"));
    os.exit(-1)
end


local outData=sign:Sign(tbs)
sign:Free()
if outData==nil then
    print(ToANSIString("签名失败"));
    os.exit(-1)
end

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("签名成功"))


