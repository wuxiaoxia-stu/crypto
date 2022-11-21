local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-nest] cert signAlgo protectedheaderFileName outFileName innerJWTFileName|claimName1 claimValue1 ... claimNameN claimValueN",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-nest：使用嵌套的JWT"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\tsignAlgo：签名算法，比如:SHA256WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tprotectedheaderFileName：输入保护头文件名，\"\"为不存在附加的保护头信息"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tinnerJWTFileName：输入的JWT文件名"))
    print(ToANSIString("\tclaimName1：输入的claim名"))
    print(ToANSIString("\tclaimValue1：输入的claim值"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWT签名，结果保存到outFileName文件中"))
end

function GetSignAlgo(signAlgo)
    signAlgo=signAlgo:upper()
    if  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" or signAlgo== "RS256" then
        return CryptCore.Const.SHA256WITHRSA
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" or signAlgo== "RS384" then
        return CryptCore.Const.SHA384WITHRSA
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" or signAlgo== "RS512" then
        return CryptCore.Const.SHA512WITHRSA
    elseif  signAlgo== "SM3WITHSM2" or signAlgo== "SM2" or signAlgo== "SM2_1" then
        return CryptCore.Const.SM3WITHSM2
    elseif  signAlgo== "ECDSAWITHSHA256" or signAlgo== "ES256" then
        return CryptCore.Const.ECDSAWITHSHA256
    elseif  signAlgo== "ECDSAWITHSHA384" or signAlgo== "ES384" then
        return CryptCore.Const.ECDSAWITHSHA384
    elseif  signAlgo== "ECDSAWITHSHA512" or signAlgo== "ES512" then
        return CryptCore.Const.ECDSAWITHSHA512
    elseif  signAlgo== "PS256" then
        return 22,{mgfalgo=3,saltlen=32,hashalgo=CryptCore.Const.SHA256}
    elseif  signAlgo== "PS384" then
        return 22,{mgfalgo=4,saltlen=48,hashalgo=CryptCore.Const.SHA384}
    elseif  signAlgo== "PS512" then
        return 22,{mgfalgo=5,saltlen=64,hashalgo=CryptCore.Const.SHA512}
    else
        return nil;
    end
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



if #arg<6 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local isNest=false
if arg[pos]=="-nest" or arg[pos]=="/nest" then
    pos=pos+1
    isNest=true
end

local cert=GetFileConetent(arg[pos])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end
pos=pos+1

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

local algo,param=GetSignAlgo(arg[pos])
if algo==nil then
    certObj:Free()
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end
pos=pos+1

local protectedheaderFileName=arg[pos]
pos=pos+1

local outFileName=arg[pos]
pos=pos+1

local keypair
keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN)

if keypair==nil then
    certObj:Free()
    print(ToANSIString("证书不在有效期内或者没有私钥"));
    os.exit(-1)
end
keypair:Free()

local jwtObj=CryptCore.NewJWT(1)
if jwtObj==nil then
    certObj:Free()
    print(ToANSIString("创建JWT签名对象失败"));
    os.exit(-1)
end
if isNest then
    if pos~=#arg then
        certObj:Free()
        Usage(arg[0])
        os.exit(-1)
    end
    local data=GetFileConetent(arg[pos])
    if data==nil then
        certObj:Free()
        jwtObj:Free()
        print(ToANSIString("读内部JWT文件失败"));
        os.exit(-1)
    end
    local innerJwtObj=CryptCore.DecodeJWT(data)
    if innerJwtObj==nil then
        certObj:Free()
        jwtObj:Free()
        print(ToANSIString("内部JWT文件不是JWT格式"));
        os.exit(-1)
    end
    
    if not jwtObj:SetNestedJWT(innerJwtObj) then
        certObj:Free()
        jwtObj:Free()
        innerJwtObj:Free()
        print(ToANSIString("SetNestedJWT失败"));
        os.exit(-1)
    end
    innerJwtObj:Free()
else
    if pos==#arg then
        certObj:Free()
        Usage(arg[0])
        os.exit(-1)
    end
    if (#arg-pos)%2~=1 then
        certObj:Free()
        Usage(arg[0])
        os.exit(-1)
    end
    
    for i=pos,#arg,2 do
        if not jwtObj:SetClaim(arg[i],arg[i+1]) then
            certObj:Free()
            jwtObj:Free()
            print(ToANSIString("SetClaim失败"));
            os.exit(-1)
        end
    end
end

local header
if protectedheaderFileName~="" then
    header=GetFileConetent(protectedheaderFileName)
    if header==nil then
        certObj:Free();
        jwtObj:Free();
        print(ToANSIString("读保护头文件失败"));
        os.exit(-1)
    end
    if not jwtObj:SetAdditionalProtectedHeader(header) then
        certObj:Free();
        jwtObj:Free();
        print(ToANSIString("设置保护头文件失败"));
        os.exit(-1)
    end
end

local certTypeId=4
local signValue=jwtObj:Sign(algo,certObj,certTypeId,param)
certObj:Free()
jwtObj:Free()
if signValue==nil then
    print(ToANSIString("签名失败"));
    os.exit(-1)
end

if Save(outFileName,signValue)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("签名成功"));


