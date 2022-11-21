local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s tbsFileName oldSignFileName newSignFileName tsaCertFileName -crl crlFileName1 ... -crl crlFileNamen -ocsp ocspFileName1 ... -ocsp ocspFileNamen",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\ttbsFileName：原文文件名"))
    print(ToANSIString("\toldSignFileName：CAdES-C文件名"))
    print(ToANSIString("\tnewSignFileName：生成的CAdES-X Long文件名"))
    print(ToANSIString("\ttsaCertFileName：信任的时间戳证书文件名,如果为\"\"则没有信任的时间戳证书文件"))
    print(ToANSIString("\tcrlFileName1：第一个CRL文件"))
    print(ToANSIString("\tcrlFileNamen：第n个CRL文件"))
    print(ToANSIString("\tocspFileName1：第一个OCSP文件"))
    print(ToANSIString("\tocspFileNamen：第n个OCSP文件"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t在不带原文的CAdES-C中添加证书和CRL、OCSP响应，构成CAdES-X Long"))
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

local argCount=#arg
if argCount<6 then
    Usage(arg[0])
    os.exit(-1)
end

if argCount%2~=0 then
    Usage(arg[0])
    os.exit(-1)
end

local tbsFileName=arg[1]
local oldSignFileName=arg[2]
local newSignFileName=arg[3]

local sign=assert(CryptCore.NewSignedData(false))

local data
local BLOCK_LEN=8192

local fSign=io.open(oldSignFileName,"rb")
if fSign==nil then
    sign:Free()
    print(ToANSIString(string.format("打开签名文件(%s)失败",CryptCore.ACPToUTF8(oldSignFileName))));
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

local tsaCertFileName=arg[4]
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
local crls={}
local ocsp
local ocsps={}

for i=5,argCount-1,2 do
    if arg[i]:upper()=="-CRL" then
        crl=GetFileConetent(arg[i+1])
        if not crl then
            sign:Free()
            print(ToANSIString("读CRL文件(%s)失败",CryptCore.ACPToUTF8(arg[i+1])));
            os.exit(-1)
        end
        crls[#crls+1]=crl
        assert(sign:AddCRL(crl))    
    elseif arg[i]:upper()=="-OCSP" then
        ocsp=GetFileConetent(arg[i+1])
        if not ocsp then
            sign:Free()
            print(ToANSIString("读OCSP文件(%s)失败",CryptCore.ACPToUTF8(arg[i])));
            os.exit(-1)
        end
        ocsps[#ocsps+1]=ocsp
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

local count=sign:GetEscTimestampCount(0)
if count>0 then
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
    
end

count=sign:GetCertCrlTimestampCount(0)
if count>0 then
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
end


cert=sign:GetSignCert(0)
local certPath=cert:GetCertPath()
if certPath==nil then
    sign:Free()
    cert:Free()
    print(ToANSIString("构造证书链失败"));
    os.exit(-1)
end
cert:Free()

table.remove(certPath)

if not sign:SetCertificateValues(0,certPath) then
    sign:Free()
    print(ToANSIString("设置完全证书属性失败"));
    os.exit(-1)
end



if not sign:SetRevocationValues(0,crls,ocsps) then
    sign:Free()
    print(ToANSIString("设置完全证书作废信息属性失败"));
    os.exit(-1)
end

outData=sign:Encode()
sign:Free()

if not outData then
    print(ToANSIString("SignedData编码失败"))
    os.exit(-1)
end

if Save(newSignFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("构造CAdES-X Long成功"));

