local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s tbsFileName signFileName tsaCertFileName -crl crlFileName1 ... -crl crlFileNamen -ocsp ocspFileName1 ... -ocsp ocspFileNamen",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\ttbsFileName：原文文件名"))
    print(ToANSIString("\tsignFileName：CAdES-C文件名"))
    print(ToANSIString("\ttsaCertFileName：信任的时间戳证书文件名，如果为\"\"则没有信任的时间戳证书文件"))
    print(ToANSIString("\tcrlFileName1：第一个CRL文件"))
    print(ToANSIString("\tcrlFileNamen：第n个CRL文件"))
    print(ToANSIString("\tcrlFileName1：第一个OCSP文件"))
    print(ToANSIString("\tcrlFileNamen：第n个OCSP文件"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证不带原文的CAdES-C"))
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

local argCount=#arg
if argCount <5 then
    Usage(arg[0])
    os.exit(-1)
end

if argCount%2~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local tbsFileName=arg[1]
local signFileName=arg[2]


local sign=assert(CryptCore.NewSignedData(false))

local data
local BLOCK_LEN=8192

data=GetFileConetent(signFileName)
if data==nil then
    sign:Free()
    print(ToANSIString(string.format("读签名文件(%s)失败",CryptCore.ACPToUTF8(signFileName))));
    os.exit(-1)
end

local fIn=io.open(tbsFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开原文文件(%s)失败",CryptCore.ACPToUTF8(tbsFileName))));
    os.exit(-1)
end

assert(sign:SetVerifyLevel(4))
assert(sign:SetUseSystemStoreForVerify(true))

local tsaCertFileName=arg[3]
local tsaCert=nil
if #tsaCertFileName>0 then
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

local crl
local ocsp
for i=4,argCount-1,2 do
    if arg[i]:upper()=="-CRL" then
        crl=GetFileConetent(arg[i+1])
        if not crl then
            sign:Free()
            print(ToANSIString("读CRL文件(%s)失败",CryptCore.ACPToUTF8(arg[i])));
            os.exit(-1)
        end
        assert(sign:AddCRL(crl))
    elseif arg[i]:upper()=="-OCSP" then
        ocsp=GetFileConetent(arg[i+1])
        if not ocsp then
            sign:Free()
            print(ToANSIString("读OCSP文件(%s)失败",CryptCore.ACPToUTF8(arg[i])));
            os.exit(-1)
        end
        assert(sign:AddOCSP(ocsp))
    else
        sign:Free()
        print(ToANSIString("参数错误"))
        Usage(arg[0])
        os.exit(-1)
    end
end

if not sign:DetachedVerifyInit(data) then
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

if not sign:HasCompleteCertificateRefs(0) then
    print(ToANSIString("\t没有完全证书引用属性"));
    sign:Free()
    os.exit(-1)
end

if sign:VerifyCompleteCertificateRefs(0)~=1 then
    print(ToANSIString("\t验证完全证书引用属性失败"));
    sign:Free()
    os.exit(-1)
end

if not sign:HasCompleteRevocationRefs(0) then
    print(ToANSIString("\t没有完全证书作废信息引用属性"));
    sign:Free()
    os.exit(-1)
end

if sign:VerifyCompleteRevocationRefs(0)~=1 then
    print(ToANSIString("\t验证完全证书作废信息引用属性失败"));
    sign:Free()
    os.exit(-1)
end

print(ToANSIString("验证CAdES-C成功"))

local count=sign:GetEscTimestampCount(0)
if count>0 then
    print(ToANSIString("是CAdES-X Type1"))
    local timeStamp
    for i=1,count do
        if tsaCert==nil then
            timeStamp=sign:VerifyEscTimeStamp(0,i-1)
        else
            timeStamp=sign:VerifyEscTimeStamp(0,i-1,tsaCert)
        end
        if timeStamp==nil then
            print(ToANSIString("验证CAdES-X Type1失败"))
            sign:Free()
            os.exit(-1)
        end
        print(ToANSIString(string.format("第%d个CAdES-C-time-stamp时间:%s",i,timeStamp:GetTime())))
        timeStamp:Free()
    end
    print(ToANSIString("验证CAdES-X Type1成功"))
end

count=sign:GetCertCrlTimestampCount(0)
if count>0 then
    print(ToANSIString("是CAdES-X Type2"))
    local timeStamp
    for i=1,count do
        if tsaCert==nil then
            timeStamp=sign:VerifyCertCRLTimeStamp(0,i-1)
        else
            timeStamp=sign:VerifyCertCRLTimeStamp(0,i-1,tsaCert)
        end
        if timeStamp==nil then
            print(ToANSIString("验证CAdES-X Type2失败"))
            sign:Free()
            os.exit(-1)
        end
        print(ToANSIString(string.format("第%d个time-stamped-certs-crls-references时间:%s",i,timeStamp:GetTime())))
        timeStamp:Free()
    end
    print(ToANSIString("验证CAdES-X Type2成功"))
end

sign:Free()
