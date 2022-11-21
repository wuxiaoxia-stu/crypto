local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s certFileName jwtFileName [payloadFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：证书文件名，\"\"为不使用附加的证书"))
    print(ToANSIString("\tjwtFileName：JWT文件名"))
    print(ToANSIString("\tpayloadFileName：可选，输出载荷文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWT验证签名，载荷结果保存到payloadFileName文件中"))
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

if #arg~=3 and #arg~=2 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1

local certObj=nil
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

local jwtFileName=arg[pos]
pos=pos+1

local payloadFileName=nil
if pos==#arg then
    payloadFileName=arg[pos]
    pos=pos+1
end


local data=GetFileConetent(jwtFileName)
if data==nil then
    if certObj then
        certObj:Free()
    end
    print(ToANSIString("读JWT文件失败"));
    os.exit(-1)
end

local jwtObj=CryptCore.DecodeJWT(data)
if jwtObj==nil then
    if certObj then
        certObj:Free()
    end
    print(ToANSIString("JWT格式错误"));
    os.exit(-1)
end

if jwtObj:GetType()~=1 then
    if certObj then
        certObj:Free()
    end
    jwtObj:Free()
    print(ToANSIString("JWT不是JWS"));
    os.exit(-1)
end

local verifyOk
if certObj then
    verifyOk=jwtObj:VerifySignature(certObj)
    certObj:Free()
else
    verifyOk=jwtObj:VerifySignature()
end
if verifyOk then
    print(ToANSIString("验证JWT签名成功"))
else
    print(ToANSIString("验证JWT签名失败"))
    jwtObj:Free()
    os.exit(-1)
end

if jwtObj:IsNestedJWT() then
    if payloadFileName~=nil then
        local innerJwtObj=assert(jwtObj:GetInnerJWT())
        if Save(payloadFileName,innerJwtObj:Encode())==false then
            jwtObj:Free()
            innerJwtObj:Free()
            print(ToANSIString("保存文件失败"));
            os.exit(-1)
        end
        innerJwtObj:Free()
    end
    jwtObj:Free()
    
    os.exit(-1)
end

local value
local names={
    "iss","sub","aud","exp","nbf","iat","jti"
}

for _,name in ipairs(names) do
    value=jwtObj:GetClaimValue(name)
    if value then
       print(ToANSIString(string.format("%s:%s",name,value)))
    else
        if CryptCore.GetLastError()==-7 then
            print(ToANSIString(string.format("%s不存在",name)))
        else
            print(ToANSIString(string.format("获取%s失败",name)))
        end
    end
end

if payloadFileName~=nil then
    value=assert(jwtObj:GetClaims())
    if Save(payloadFileName,value)==false then
        jwtObj:Free()
        print(ToANSIString("保存文件失败"));
        os.exit(-1)
    end
end

jwtObj:Free()



