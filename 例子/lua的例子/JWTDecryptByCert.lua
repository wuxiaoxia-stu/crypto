local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s cert jwtFileName [clearFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-compact：使用JWE Compact Serialization，不存在则使用JWE JSON Serialization"))
    print(ToANSIString("\tcert：解密证书文件"))
    print(ToANSIString("\tjwtFileName：JWT文件名"))
    print(ToANSIString("\tclearFileName：可选，解密得到明文的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWT解密运算，得到的明文保存到clearFileName文件中"))
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

    if certObj:Match("CertType='Encrypt' || CertType='KeyAgreement'")==false then
        certObj:Free()
        print(ToANSIString("不是加密证书"));
        os.exit(-1)
    end
    local keypair
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,5)
    if keypair==nil then
        certObj:Free()
        print(ToANSIString("证书没有私钥"));
        os.exit(-1)
    end
    keypair:Free()

end
pos=pos+1

local jweFileName=arg[pos]
pos=pos+1

local clearFileName=nil
if pos==#arg then
    clearFileName=arg[pos]
    pos=pos+1
end

local jwtData=GetFileConetent(jweFileName)
if jwtData==nil then
    if certObj then
        certObj:Free()
    end
    print(ToANSIString("读JWT文件失败"));
    os.exit(-1)
end

local jwtObj=CryptCore.DecodeJWT(jwtData)
if jwtObj==nil then
    if certObj then
        certObj:Free()
    end
    print(ToANSIString("错误的JWT格式"));
    os.exit(-1)
end

if jwtObj:GetType()~=2 then
    if certObj then
        certObj:Free()
    end
    jwtObj:Free()
    print(ToANSIString("JWT不是JWE"));
    os.exit(-1)
end

if certObj then
    if not jwtObj:DecryptByCert(certObj) then
        certObj:Free()
        jwtObj:Free()
        print(ToANSIString("解密失败"));
        os.exit(-1)
    end
    certObj:Free()
else
    if not jwtObj:DecryptByCert() then
        jwtObj:Free()
        print(ToANSIString("解密失败"));
        os.exit(-1)
    end
end

if jwtObj:IsNestedJWT() then
    if clearFileName~=nil then
        local innerJwtObj=assert(jwtObj:GetInnerJWT())
        if Save(clearFileName,innerJwtObj:Encode())==false then
            jwtObj:Free()
            innerJwtObj:Free()
            print(ToANSIString("保存文件失败"));
            os.exit(-1)
        end
        innerJwtObj:Free()
    end
    jwtObj:Free()
    print(ToANSIString("解密成功"))
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

if clearFileName~=nil then
    value=assert(jwtObj:GetClaims())
    if Save(clearFileName,value)==false then
        jwtObj:Free()
        print(ToANSIString("保存文件失败"));
        os.exit(-1)
    end
end

jwtObj:Free()

print(ToANSIString("解密成功"))