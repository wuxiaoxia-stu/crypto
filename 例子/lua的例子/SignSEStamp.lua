local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s issuerCertFileName templateFileName stampFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tissuerCertFileName：制章人证书文件名"))
    print(ToANSIString("\ttemplateFileName：模板文件名"))
    print(ToANSIString("\tstampFileName：输出的电子印章的文件名"))
    print(ToANSIString("\tpwd：使用私钥需要的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t根据templateFileName文件的信息进行签名产生电子印章，结果保存到stampFileName文件中"))
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
    if signAlgo==nil then
        return nil
    end
    signAlgo=signAlgo:upper()
    if signAlgo== "SHA1WITHRSA" or signAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.5"then
        return CryptCore.Const.SHA1WITHRSA
    elseif  signAlgo== "SHA224WITHRSA" or signAlgo== "SHA224WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.14" then
        return CryptCore.Const.SHA224WITHRSA
    elseif  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.11" then
        return CryptCore.Const.SHA256WITHRSA
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.12" then
        return CryptCore.Const.SHA384WITHRSA
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.13" then
        return CryptCore.Const.SHA512WITHRSA
    elseif  signAlgo== "MD5WITHRSA" or signAlgo== "MD5WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.4" then
        return CryptCore.Const.MD5WITHRSA
    elseif  signAlgo== "SHA512/224WITHRSA" or signAlgo== "SHA512/224WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.15" then
        return 34
    elseif  signAlgo== "SHA512/256WITHRSA" or signAlgo== "SHA512/256WITHRSAENCRYPTION" or signAlgo=="1.2.840.113549.1.1.16" then
        return 35
    elseif  signAlgo== "SHA3-224WITHRSA" or signAlgo== "SHA3-224WITHRSAENCRYPTION" or signAlgo=="2.16.840.1.101.3.4.3.13" then
        return 36
    elseif  signAlgo== "SHA3-256WITHRSA" or signAlgo== "SHA3-256WITHRSAENCRYPTION" or signAlgo=="2.16.840.1.101.3.4.3.14" then
        return 37
    elseif  signAlgo== "SHA3-384WITHRSA" or signAlgo== "SHA3-384WITHRSAENCRYPTION" or signAlgo=="2.16.840.1.101.3.4.3.15" then
        return 38
    elseif  signAlgo== "SHA3-512WITHRSA" or signAlgo== "SHA3-512WITHRSAENCRYPTION" or signAlgo=="2.16.840.1.101.3.4.3.16" then
        return 39
    elseif  signAlgo== "SM3WITHSM2" or signAlgo=="1.2.156.10197.1.501" then
        return CryptCore.Const.SM3WITHSM2
    elseif  signAlgo== "ECDSAWITHSHA1" or signAlgo=="1.2.840.10045.4.1" then
        return CryptCore.Const.ECDSAWITHSHA1
    elseif  signAlgo== "ECDSAWITHSHA224" or signAlgo=="1.2.840.10045.4.3.1" then
        return CryptCore.Const.ECDSAWITHSHA224
    elseif  signAlgo== "ECDSAWITHSHA256" or signAlgo=="1.2.840.10045.4.3.2"  then
        return CryptCore.Const.ECDSAWITHSHA256
    elseif  signAlgo== "ECDSAWITHSHA384" or signAlgo=="1.2.840.10045.4.3.3" then
        return CryptCore.Const.ECDSAWITHSHA384
    elseif  signAlgo== "ECDSAWITHSHA512" or signAlgo=="1.2.840.10045.4.3.4" then
        return CryptCore.Const.ECDSAWITHSHA512
    elseif  signAlgo== "ECDSAWITHSHA3-224" or signAlgo=="2.16.840.1.101.3.4.3.9" then
        return 40
    elseif  signAlgo== "ECDSAWITHSHA3-256" or signAlgo=="2.16.840.1.101.3.4.3.10" then
        return 41
    elseif  signAlgo== "ECDSAWITHSHA3-384" or signAlgo=="2.16.840.1.101.3.4.3.11" then
        return 42
    elseif  signAlgo== "ECDSAWITHSHA3-512" or signAlgo=="2.16.840.1.101.3.4.3.12" then
        return 43
    else
        return nil;
    end
end

function GetHashAlgo(algo)
    if algo==nil then
        return nil
    end
    algo=algo:upper()
    if algo== "SHA1" or algo=="SHA-1" or algo=="1.3.14.3.2.26" then
        return CryptCore.Const.SHA1
    elseif  algo== "SHA224" or algo=="SHA-224" or algo=="2.16.840.1.101.3.4.2.4" then
        return CryptCore.Const.SHA224
    elseif  algo== "SHA256" or algo=="SHA-256" or algo=="2.16.840.1.101.3.4.2.1" then
        return CryptCore.Const.SHA256
    elseif  algo== "SHA384" or algo=="SHA-384" or algo=="2.16.840.1.101.3.4.2.2" then
        return CryptCore.Const.SHA384
    elseif  algo== "SHA512" or algo=="SHA-512" or algo=="2.16.840.1.101.3.4.2.3" then
        return CryptCore.Const.SHA512
    elseif  algo== "MD5" or algo=="1.2.840.113549.2.5" then
        return CryptCore.Const.MD5
    elseif  algo== "SHA512/224" or algo== "SHA-512/224" or algo=="2.16.840.1.101.3.4.2.5" then
        return CryptCore.Const["SHA-512/224"]
    elseif  algo== "SHA512/256" or algo== "SHA-512/256" or algo=="2.16.840.1.101.3.4.2.6" then
        return CryptCore.Const["SHA-512/256"]
    elseif  algo== "SHA3-224" or algo=="2.16.840.1.101.3.4.2.7" then
        return CryptCore.Const["SHA3-224"]
    elseif  algo== "SHA3-256" or algo=="2.16.840.1.101.3.4.2.8" then
        return CryptCore.Const["SHA3-256"]
    elseif  algo== "SHA3-384" or algo=="2.16.840.1.101.3.4.2.9" then
        return CryptCore.Const["SHA3-384"]
    elseif  algo== "SHA3-512" or algo=="2.16.840.1.101.3.4.2.10" then
        return CryptCore.Const["SHA3-512"]
    elseif  algo== "SM3" or algo=="1.2.156.10197.1.401" then
        return CryptCore.Const.SM3
    else
        return nil;
    end
end


if #arg~=4 and #arg~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local issuerCertFileName=arg[1]
local templateFileName=arg[2]
local stampFileName=arg[3]
local cert=GetFileConetent(issuerCertFileName)
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

local certObj=CryptCore.NewCert(cert)
if certObj==nil then
    print(ToANSIString("不是证书文件"));
    os.exit(-1)
end


if certObj:Match("CertType='Signature'")==false then
    certObj:Free()
    print(ToANSIString("不是签名证书"));
    os.exit(-1)
end

local keypair
local pwd=nil
--如果需要从证书库里获取私钥，则使用CryptCore.Const.SEARCH_KEYPAIR_FLAG_CURRENTUSER代替CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE
if #arg==4 then
    pwd=arg[4]
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN,pwd)
else
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN)
end
if keypair==nil then
	certObj:Free()
    if pwd==nil then
        print(ToANSIString("证书没有私钥"));
    else
        print(ToANSIString("证书没有私钥，或者密码错误"));
    end
    os.exit(-1)
end
keypair:Free()


local jsonData=GetFileConetent(templateFileName)
if jsonData==nil then
	certObj:Free()
    print(ToANSIString("读模板文件失败"));
    os.exit(-1)
end

local json=CryptCore.Json.Decode(jsonData)
if json==nil then
	certObj:Free()
	print(ToANSIString("模板文件不是JSON"));
    os.exit(-1)
end

local format
local formatStr=json.format
if formatStr==nil or formatStr=="GB/T 38540" then
    format=CryptCore.Const["GB/T 38540"]
elseif formatStr=="GM/T 0031" then
    format=CryptCore.Const["GM/T 0031"]
else
    certObj:Free()
	print(ToANSIString("模板文件的format出错"));
    os.exit(-1)
end

local stamp=assert(CryptCore.NewStamp(format))
if format==CryptCore.Const["GM/T 0031"] then
    stamp:SetVersion(json.version)
end
stamp:SetVid(json.vid)
stamp:SetId(json.id)
stamp:SetType(json.type)
stamp:SetName(json.name)

local useCertDigest=false
local hashAlgo
if format==CryptCore.Const["GM/T 0031"] then
    useCertDigest=false
else 
    useCertDigest=json.useCertDigest
    if useCertDigest then
        hashAlgo=GetHashAlgo(json.certDigestAlgo)
        if hashAlgo==nil then
            stamp:Free()
            certObj:Free()
            print(ToANSIString("不支持的Hash算法"));
            os.exit(-1)
        end
    end
end

certs=json.certs
local certObj2
for i,cert in ipairs(certs) do
    certObj2=CryptCore.NewCert(cert)
    if certObj2==nil then
        stamp:Free()
        certObj:Free()
        print(ToANSIString("签章证书格式错误"));
        os.exit(-1)
    end
    if useCertDigest then
        stamp:AddCertDigest(hashAlgo,certObj2)
    else
        stamp:AddCert(certObj2)
    end
    certObj2:Free()
end

stamp:SetCreateDate(json.createDate)
stamp:SetValidStart(json.validStart)
stamp:SetValidEnd(json.validEnd)

local picture=json.picture
stamp:SetPicture(picture.type,picture.data,picture.width,picture.heigth)

local exts=json.exts
if exts~=nil then
    for i,ext in ipairs(exts) do
        stamp:AddExtension(ext.extnID,ext.critical,CryptCore.HexDecode(ext.extnValue))
    end
end

local signAlgo=GetSignAlgo(json.signAlgo)
if signAlgo==nil then
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end
local stampEncode=stamp:Sign(certObj,signAlgo)
stamp:Free()
certObj:Free()

if stampEncode==nil then
    print(ToANSIString("签名失败"));
    os.exit(-1)
end

if not Save(stampFileName,stampEncode) then
    print(ToANSIString("保存电子印章失败"));
    os.exit(-1)
end
print(ToANSIString("签电子印章成功"));