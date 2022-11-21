local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-compact] certFileName jwsFileName payloadFileName [index]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-compact：使用JWS Compact Serialization，不存在则使用JWS JSON Serialization"))
    print(ToANSIString("\tcertFileName：证书文件名，\"\"为不使用附加的证书"))
    print(ToANSIString("\tjwsFileName：JWS文件名"))
    print(ToANSIString("\tpayloadFileName：载荷文件名"))
    print(ToANSIString("\tindex：索引值从0算起，默认为0"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWS验证签名，载荷结果保存到payloadFileName文件中"))
end

function getSignAlgoName(signAlgo,param)
    if signAlgo== CryptCore.Const.SHA256WITHRSA then
        return "RS256"
    elseif signAlgo== CryptCore.Const.SHA384WITHRSA then
        return "RS384"
    elseif signAlgo== CryptCore.Const.SHA512WITHRSA then
        return "RS512"
    elseif signAlgo== CryptCore.Const.SM3WITHSM2 then
        return "SM2_1"
    elseif signAlgo== CryptCore.Const.ECDSAWITHSHA256 then
        return "ES256"
    elseif signAlgo== CryptCore.Const.ECDSAWITHSHA384 then
        return "ES384"
    elseif signAlgo== CryptCore.Const.ECDSAWITHSHA512 then
        return "ES512"
    elseif signAlgo== 22 then
        if param.hashalgo==CryptCore.Const.SHA256 then
            return "PS256"
        elseif param.hashalgo==CryptCore.Const.SHA384 then
            return "PS384"
        elseif param.hashalgo==CryptCore.Const.SHA512 then
            return "PS512"
        end
    end
    return "unknown sign algo(" .. signAlgo ..")";
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

if #arg~=3 and #arg~=4 and #arg~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local type=2
if arg[pos]=="-compact" or arg[pos]=="/compact" then
    type=1
    pos=pos+1
end

local certObj

if arg[pos]~="" then
    local cert=GetFileConetent(arg[pos])
    if cert==nil then
        print(ToANSIString("读证书文件失败"));
        os.exit(-1)
    end
    
    certObj=CryptCore.NewCert(cert)
    if certObj==nil then
        print(ToANSIString("不是证书文件"));
        os.exit(-1)
    end

    if certObj:Match("CertType='Signature'")==false then
        certObj:Free()
        print(ToANSIString("不是签名证书"));
        os.exit(-1)
    end
end
pos=pos+1

local jwsFileName=arg[pos]
pos=pos+1

local payloadFileName=arg[pos]
pos=pos+1

local index=0

if pos==#arg then
    index=tonumber(arg[pos])
end

local data=GetFileConetent(jwsFileName)
if data==nil then
    if certObj then
        certObj:Free()
    end
    print(ToANSIString("读JWS文件失败"));
    os.exit(-1)
end

local jwsObj=CryptCore.DecodeJWS(type,data)
if jwsObj==nil then
    if certObj then
        certObj:Free()
    end
    print(ToANSIString("JWS格式错误"));
    os.exit(-1)
end
local isDetached=jwsObj:IsDetached()
local payload

if isDetached then
    payload=GetFileConetent(payloadFileName)
    if payload==nil then
        jwsObj:Free()
        print(ToANSIString("读有效载荷文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetPayLoad(payload) then
        jwsObj:Free()
        print(ToANSIString("设置有效载荷失败"));
        os.exit(-1)
    end
else
    payload=jwsObj:GetPayLoad()
    if payload==nil then
        if certObj then
            certObj:Free()
        end
        jwsObj:Free()
        print(ToANSIString("获取载荷失败"));
        os.exit(-1)
    end
end
local count=jwsObj:GetSignCount()
print(ToANSIString(string.format("一共有%d个JWS签名",count)))

local algo,isSign,param
local header
local verifyOk,isInValidity
algo,isSign,param=jwsObj:GetAlgo(index)
if not isSign then
    if certObj then
        certObj:Free()
    end
    jwsObj:Free()
    print(ToANSIString(string.format("第%d个JWS签名不是签名",index+1)))
    os.exit(-1)
end
print(ToANSIString(string.format("第%d个JWS签名的签名算法为:%s",index+1,getSignAlgoName(algo,param))))
header=jwsObj:GetProtectedHeader(index)
if header==nil or #header==0 then
    print(ToANSIString(string.format("第%d个JWS签名没有保护头",index+1)))
else
    print(ToANSIString(string.format("第%d个JWS签名的保护头为:\n%s",index+1,header)))
end
    
if type==2 then
    header=jwsObj:GetUnprotectedHeader(index)
    if header==nil or #header==0 then
        print(ToANSIString(string.format("第%d个JWS签名没有不保护头",index+1)))
    else
        print(ToANSIString(string.format("第%d个JWS签名的不保护头为:\n%s",index+1,header)))
    end
end
  
if certObj then
    verifyOk,isInValidity=jwsObj:VerifySignature(index,certObj)
else
    verifyOk,isInValidity=jwsObj:VerifySignature(index)
end
if verifyOk then
    if isInValidity then
        print(ToANSIString(string.format("验证第%d个JWS的签名成功",index+1)))
    else
        print(ToANSIString(string.format("验证第%d个JWS的签名成功,但签名证书的不再有效期内",index+1)))
    end
    local signCertObj=jwsObj:GetSignCert(index)
    if signCertObj==nil then
        print(ToANSIString(string.format("第%d个JWS的签名没有签名证书",index+1)))
    else
        print(ToANSIString(string.format("第%d个JWS的签名的签名证书的主体：%s",index+1,signCertObj:GetSubject())))
        signCertObj:Free()
    end
else
    print(ToANSIString(string.format("验证第%d个JWS的签名失败",index+1)))
end
if certObj then
    certObj:Free()
end
jwsObj:Free()
if isDetached==false then
    if Save(payloadFileName,payload)==false then
        print(ToANSIString("保存文件失败"));
        os.exit(-1)
    end
end


