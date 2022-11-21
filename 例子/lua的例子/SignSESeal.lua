local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s signCertFileName tbsFileName stampFileName sealFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tsignCertFileName：签章人证书文件名"))
    print(ToANSIString("\ttbsFileName：原文文件名"))
    print(ToANSIString("\tstampFileName：电子印章的文件名"))
    print(ToANSIString("\tsealFileName：输出的电子签章的文件名"))
    print(ToANSIString("\tpwd：使用私钥需要的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t使用电子印章stampFileName对原文tbsFileNamee进行签名产生电子签章，结果保存到sealFileName文件中"))
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

function GetNowString()
    local t=os.date("!*t")
    return string.format("%04d%02d%02d%02d%02d%02dZ",t.year,t.month,t.day,t.hour,t.min,t.sec)
end

function GetHashAlgo(algo)
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

function Hash(type,data)
    local hashAlgo=GetHashAlgo(type)
    if hashAlgo==nil then
        return nil
    end
    local hashObj=CryptCore.NewHash(hashAlgo)
    if hashObj==nil then
        return nil
    end
    hashObj:Update(data)
    local hashValue=hashObj:Final()
    hashObj:Free()
    return hashValue
end

function IsCertInStamp(stamp,certObj)
    local certListType=stamp:GetCertListType()
    if certListType==CryptCore.Const.STAMP_CERTLIST_TYPE_CERT then
        local certs=stamp:GetCertList()
        local certEncode=certObj:Encode(1)
        local found=false
        for i,cert in ipairs(certs) do
            if certEncode==cert:Encode(1) then
                cert:Free()
                found=true
                break
            end
            cert:Free()
        end
        return found
    else
        local certDigestList=stamp:GetCertDigestList()
        local certEncode=certObj:Encode(1)
        local found=false
        local hashValue
        for i,certDigest in ipairs(certDigestList) do
            hashValue=Hash(certDigest.type,certEncode)
            if hashValue==certDigest.value then
                found=true
                break
            end
        end
        return found
    end
end

function GetSignAlgo(certObj)
    if certObj:Match("Algorithm='SM2'") then
        return CryptCore.Const.SM3WITHSM2
    elseif certObj:Match("Algorithm='RSA'") then
        return CryptCore.Const.SHA256WITHRSA
    elseif certObj:Match("Algorithm='ECC'") then
        return CryptCore.Const.ECDSAWITHSHA256
    else
        return -1
    end
end

function HashFile(hashObj,fileObj)
    local data
	local BLOCK_LEN=8192
	while (true) do
 		data=fileObj:read(BLOCK_LEN)
		if not data then
			break
		end

		hashObj:Update(data)
	end
    return hashObj:Final()
end

if #arg~=4 and #arg~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local signCertFileName=arg[1]
local tbsFileName=arg[2]
local stampFileName=arg[3]
local sealFileName=arg[4]

local cert=GetFileConetent(signCertFileName)
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
if #arg==5 then
    pwd=arg[5]
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

local version=8
local time=GetNowString()
local propertyInfo="Sign file"


local stampData=GetFileConetent(stampFileName)
if stampData==nil then
	certObj:Free()
    print(ToANSIString("读电子印章文件失败"));
    os.exit(-1)
end

local stamp=CryptCore.NewStamp(stampData)
if stamp==nil then
	certObj:Free()
    print(ToANSIString("电子印章文件格式错误"));
    os.exit(-1)
end

if not stamp:Verify(time) then
    stamp:Free()
    certObj:Free()
    print(ToANSIString("电子印章验证失败"));
    os.exit(-1)
end

if IsCertInStamp(stamp,certObj)==false then
    stamp:Free()
    certObj:Free()
    print(ToANSIString("签名证书不在电子印章内"));
    os.exit(-1)
end

local signAlgo=GetSignAlgo(certObj)
if signAlgo==-1 then
    stamp:Free()
    certObj:Free()
    print(ToANSIString("不支持的签名证书"));
    os.exit(-1)
end

local hashAlgo=CryptCore.GetHashAlgorithmFromSignAlgorithm(signAlgo)

local fIn=io.open(tbsFileName,"rb")
if fIn==nil then
    stamp:Free()
    certObj:Free()
    print(ToANSIString("打开原文文件失败"));
    os.exit(-1)
end

local hashObj=assert(CryptCore.NewHash(hashAlgo))
local hashValue=HashFile(hashObj,fIn)
fIn:close()
hashObj:Free()

local format=stamp:GetFormat()

local seal=assert(CryptCore.NewSeal(format))
if format==CryptCore.Const["GM/T 0031"] then
    seal:SetVersion(version)
else
    seal:SetVersion(stamp:GetVersion())
end
seal:SetStamp(stamp)
stamp:Free()
seal:SetTime(time)
seal:SetDataHash(hashValue)
seal:SetProperty(propertyInfo)

--[[
if format==CryptCore.Const["GB/T 38540"] then
    seal:AddExtension("1.2.3.4.5.6",false,"abcd")
    seal:AddExtension("1.2.129",true,"123")
end
--]]

local sealEncode=seal:Sign(certObj,signAlgo)
certObj:Free()
seal:Free()
if sealEncode==nil then
    print(ToANSIString("签名失败"));
    os.exit(-1)
end

if not Save(sealFileName,sealEncode) then
    print(ToANSIString("保存电子签章失败"));
    os.exit(-1)
end
print(ToANSIString("签电子签章成功"))
