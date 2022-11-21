local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s [-old] tbsFileName signFileName newSignFileName url tsaHashAlgo atsHashIndexHashAlgo [tsaCertFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-old：使用旧的ats-hash-index属性"))
    print(ToANSIString("\ttbsFileName：原文文件名"))
    print(ToANSIString("\tsignFileName：CAdES-X Long文件名"))
    print(ToANSIString("\tnewSignFileName：生成的CAdES-A ATSv2文件名"))
    print(ToANSIString("\turl：时间戳服务器URL"))
    print(ToANSIString("\ttsaHashAlgo：时间戳请求使用的Hash算法，例如:SHA-1、SHA-256等"))
    print(ToANSIString("\tatsHashIndexHashAlgo：ats-hash-index-v3或者ats-hash-index使用的Hash算法，例如:SHA-1、SHA-256等"))
    print(ToANSIString("\ttsaCertFileName：信任的时间戳证书文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t在不带原文的CAdES中添加归档时间戳ATSv3"))
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


local argCount=#arg
if argCount~=8 and argCount~=6 and argCount~=7 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local useAtsHashIndexV3=true

if arg[pos]:upper()=='-OLD' then
    useAtsHashIndexV3=false
    pos=pos+1
end

local tbsFileName=arg[pos]
pos=pos+1
local signFileName=arg[pos]
pos=pos+1
local newSignFileName=arg[pos]
pos=pos+1

local url=arg[pos]
pos=pos+1
local tsaHashAlgo=getHashAlgo(arg[pos])
pos=pos+1
if not tsaHashAlgo then
    print(ToANSIString("未知时间戳请求Hash算法"));
    os.exit(-1)
end

local atsHashIndexHashAlgo=getHashAlgo(arg[pos])
pos=pos+1
if not atsHashIndexHashAlgo then
    print(ToANSIString("未知ats-hash-index-v3属性的Hash算法"));
    os.exit(-1)
end

local sign=assert(CryptCore.NewSignedData(false))

local data
local BLOCK_LEN=8192

local fSign=io.open(signFileName,"rb")
if fSign==nil then
    sign:Free()
    print(ToANSIString(string.format("打开签名文件(%s)失败",CryptCore.ACPToUTF8(signFileName))));
    os.exit(-1)
end
data=fSign:read("*a")
fSign:close()

local fIn=io.open(tbsFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开原文文件(%s)失败",CryptCore.ACPToUTF8(tbsFileName))));
    os.exit(-1)
end

assert(sign:SetVerifyLevel(4))
assert(sign:SetUseSystemStoreForVerify(true))
assert(sign:SetKeepTbs(true))

local tsaCert=nil
if argCount==pos then
    local tsaCertFileName=arg[pos]
    local certData=GetFileConetent(tsaCertFileName)
    if certData==nil then
        sign:Free()
        print(ToANSIString(string.format("读时间戳证书文件(%s)失败",CryptCore.ACPToUTF8(tsaCertFileName))));
        os.exit(-1)
    end
    tsaCert=CryptCore.NewCert(certData)
    if tsaCert==nil then
        sign:Free()
        print(ToANSIString("不是证书文件"));
        os.exit(-1)
    end
    
    assert(CryptCore.AddTSACert(tsaCert))
end

local signedData=data
if not sign:DetachedVerifyInit(signedData) then
    sign:Free()
    fIn:close()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    if not sign:DetachedVerifyUpdate(data) then
        sign:Free()
        fIn:close()
        print(ToANSIString("验证签名失败"))
        os.exit(-1)
    end
    
end

fIn:close()

if not sign:DetachedVerifyFinal() then
    sign:Free()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end

print(ToANSIString("验证签名成功"))

local hasSigningCertAttribute=sign:HasSigningCertAttribute(0)
local hashAlgo=sign:GetSigningCertV2HashAlgorithm(0)
if (not hasSigningCertAttribute) and hashAlgo==-1 then
    print(ToANSIString("不是CAdES-BES"))
    sign:Free()
    os.exit(-1)
end

if not sign:HasSignatureTimeStamp(0) then
    print(ToANSIString("不是CAdES-T"))
    sign:Free()
    os.exit(-1)
end

if not sign:VerifyTimeStamp(0) then
    print(ToANSIString("\t验证签名时间戳失败"));
    sign:Free()
    os.exit(-1)
end
print(ToANSIString(string.format("签名时间戳时间:%s",sign:GetStringAttribute(12,0))))

if useAtsHashIndexV3 then
    if not sign:AttachATSHashIndexV3(0,atsHashIndexHashAlgo) then
        sign:Free()
        print(ToANSIString("添加ats-hash-index-v3失败"));
        os.exit(-1)
    end
else
    if not sign:AttachATSHashIndex(0,atsHashIndexHashAlgo) then
        sign:Free()
        print(ToANSIString("添加ats-hash-index失败"));
        os.exit(-1)
    end
end

if not sign:AddArchiveTimeStampV3(0,tsaHashAlgo,url) then
    sign:Free()
    print(ToANSIString("添加archiveTimestampV3时间戳失败"));
    os.exit(-1)
end

outData=sign:Encode()
if not outData then
    print(ToANSIString("SignedData编码失败"))
    os.exit(-1)
end

count=sign:GetArchiveTimestampV3Count(0)
local timeStamp
if tsaCert==nil then
    timeStamp=assert(sign:VerifyArchiveTimeStampV3(0,count-1))
else
    timeStamp=assert(sign:VerifyArchiveTimeStampV3(0,count-1,nil,tsaCert))
end
print(ToANSIString(string.format("archiveTimestampV3时间:%s",timeStamp:GetTime())))
timeStamp:Free()

sign:Free()

if Save(newSignFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("构造带ATSv3的CAdES成功"));

