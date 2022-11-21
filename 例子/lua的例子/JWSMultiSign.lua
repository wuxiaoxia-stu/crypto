local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s oldjwsFileName cert signAlgo protectedheaderFileName unprotectedheaderFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\toldjwsFileName：旧的JWS文件名"))
    print(ToANSIString("\tsignAlgo：签名算法，比如:SHA256WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tprotectedheaderFileName：输入保护头文件名，\"\"为不存在附加的保护头信息"))
    print(ToANSIString("\tunprotectedheaderFileName：输入不保护头文件名，\"\"为不存在不保护头信息"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWS签名，结果保存到outFileName文件中"))
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



if #arg~=6 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local type=2

local data=GetFileConetent(arg[pos])
pos=pos+1
if data==nil then
    print(ToANSIString("读旧JWS文件失败"));
    os.exit(-1)
end

local jwsObj=CryptCore.DecodeJWS(type,data)
if jwsObj==nil then
    print(ToANSIString("JWS格式错误"));
    os.exit(-1)
end

local cert=GetFileConetent(arg[pos])
if cert==nil then
    jwsObj:Free()
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end
pos=pos+1

local certObj=CryptCore.NewCert(cert)
if certObj==nil then
    jwsObj:Free()
    print(ToANSIString("不是证书文件"));
    os.exit(-1)
end

if certObj:Match("CertType='Signature'")==false then
    jwsObj:Free()
    certObj:Free()
    print(ToANSIString("不是签名证书"));
    os.exit(-1)
end

local algo,param=GetSignAlgo(arg[pos])
if algo==nil then
    jwsObj:Free()
    certObj:Free()
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end
pos=pos+1

local protectedheaderFileName=arg[pos]
pos=pos+1

local unprotectedheaderFileName=arg[pos]
pos=pos+1

local outFileName=arg[pos]


local keypair
keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN)

if keypair==nil then
    jwsObj:Free()
    certObj:Free()
    print(ToANSIString("证书不在有效期内或者没有私钥"));
    os.exit(-1)
end
keypair:Free()

assert(jwsObj:SetCertIdType(4))

local header
if protectedheaderFileName~="" then
    header=GetFileConetent(protectedheaderFileName)
    if header==nil then
        certObj:Free();
        jwsObj:Free();
        print(ToANSIString("读保护头文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetAdditionalProtectedHeader(header) then
        certObj:Free();
        jwsObj:Free();
        print(ToANSIString("设置保护头文件失败"));
        os.exit(-1)
    end
end

if unprotectedheaderFileName~="" then
    header=GetFileConetent(unprotectedheaderFileName)
    if header==nil then
        certObj:Free();
        jwsObj:Free();
        print(ToANSIString("读不保护头文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetUnprotectedHeader(header) then
        certObj:Free();
        jwsObj:Free();
        print(ToANSIString("设置不保护头文件失败"));
        os.exit(-1)
    end
end

local signValue=jwsObj:Sign(algo,certObj,param)
certObj:Free()
jwsObj:Free()
if signValue==nil then
    print(ToANSIString("签名失败"));
    os.exit(-1)
end

if Save(outFileName,signValue)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("签名成功"));

