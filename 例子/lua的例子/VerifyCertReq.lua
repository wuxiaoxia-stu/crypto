local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s p10FileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tp10FileName：要验证的证书请求文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证证书请求"))
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

function GetPublicKeyType(publicKey)
    local algo=publicKey:Algorithm()
    if algo==CryptCore.Const.RSA then
        return "RSA"
    elseif algo==CryptCore.Const.ECC then
        local curve=publicKey:ECCCurve()
        if curve==CryptCore.Const.ECC_CURVE_SM2 then
            return "SM2"
        elseif curve==CryptCore.Const.ECC_CURVE_P192 then
            return "P-192"
        elseif curve==CryptCore.Const.ECC_CURVE_P224 then
            return "P-224"
        elseif curve==CryptCore.Const.ECC_CURVE_P256 then
            return "P-256"
        elseif curve==CryptCore.Const.ECC_CURVE_P384 then
            return "P-384"
        elseif curve==CryptCore.Const.ECC_CURVE_P521 then
            return "P-521"
        elseif curve==CryptCore.Const.ECC_CURVE_WAPI then
            return "WAPI"
        elseif curve==8 then
            return "brainpoolP192r1"
        elseif curve==9 then
            return "brainpoolP224r1"
        elseif curve==10 then
            return "brainpoolP256r1"
        elseif curve==11 then
            return "brainpoolP320r1"
        elseif curve==12 then
            return "brainpoolP384r1"
        elseif curve==13 then
            return "brainpoolP512r1"
        elseif curve==14 then
            return "FRP256V1"
        else
            return "Unknown ECC("..curve..")"
        end
    else
        return "Unknown"
    end
end

function PrintPublicKeyInfo(publicKey)
    local publicKeyType=GetPublicKeyType(publicKey)
    local str=string.format("公钥算法：%s（%d位）",
        publicKeyType,publicKey:Length())
    print(ToANSIString(str))
end

function PrintSignAlgo(algo)
	if algo==CryptCore.Const.MD5WITHRSA then
        print(ToANSIString("签名算法: MD5WithRSA"))
    elseif algo==CryptCore.Const.SHA1WITHRSA then
        print(ToANSIString("签名算法: SHA1WithRSA"))
    elseif algo==CryptCore.Const.SHA224WITHRSA then
        print(ToANSIString("签名算法: SHA224WithRSA"))
    elseif algo==CryptCore.Const.SHA256WITHRSA then
        print(ToANSIString("签名算法: SHA256WithRSA"))
    elseif algo==CryptCore.Const.SHA384WITHRSA then
        print(ToANSIString("签名算法: SHA384WithRSA"))
    elseif algo==CryptCore.Const.SHA512WITHRSA then
        print(ToANSIString("签名算法: SHA512WithRSA"))
    elseif algo==CryptCore.Const.DSAWITHSHA1 then
        print(ToANSIString("签名算法: DSAWithSHA1"))
    elseif algo==CryptCore.Const.DSAWITHSHA224 then
        print(ToANSIString("签名算法: DSAWithSHA224"))
    elseif algo==CryptCore.Const.DSAWITHSHA256 then
        print(ToANSIString("签名算法: DSAWithSHA256"))
    elseif algo==CryptCore.Const.ECDSAWITHSHA1 then
        print(ToANSIString("签名算法: ECDSAWithSHA1"))
    elseif algo==CryptCore.Const.ECDSAWITHSHA224 then
        print(ToANSIString("签名算法: ECDSAWithSHA224"))
    elseif algo==CryptCore.Const.ECDSAWITHSHA256 then
        print(ToANSIString("签名算法: ECDSAWithSHA256"))
    elseif algo==CryptCore.Const.ECDSAWITHSHA384 then
        print(ToANSIString("签名算法: ECDSAWithSHA384"))
    elseif algo==CryptCore.Const.ECDSAWITHSHA512 then
        print(ToANSIString("签名算法: ECDSAWithSHA512"))
    elseif algo==CryptCore.Const.SM3WITHSM2 then
        print(ToANSIString("签名算法: SM3WithSM2"))
    else
        print(ToANSIString(string.format("签名算法: Unknown Sign Algorithm(%d)",algo)))
    end
end



local argCount=#arg
if argCount~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local p10=GetFileConetent(arg[1])
if p10==nil then
    print(ToANSIString("读证书请求文件失败"));
    os.exit(-1)
end

local certReqObj=CryptCore.NewCertReq(p10)
if certReqObj==nil then
    print(ToANSIString("不是证书请求"))
    os.exit(-1)
end
if not certReqObj:Verify() then
    certReqObj:Free()
    print(ToANSIString("验证证书请求失败"))
    os.exit(-1)
end
print(ToANSIString("验证证书请求成功"))

local publicKey=assert(certReqObj:GetPublicKey())
PrintPublicKeyInfo(publicKey)
publicKey:Free()
print(ToANSIString(string.format("版本号:%s",certReqObj:GetAttribute(CryptCore.Const.CERTREQ_VERSION))))

local algo=certReqObj:GetAttribute(CryptCore.Const.CERTREQ_SIGN_ALGO)
PrintSignAlgo(algo)

print(ToANSIString(string.format("主体:%s",certReqObj:GetAttribute(CryptCore.Const.CERTREQ_SUBJECT))))

local attrCount=certReqObj:GetAttribute(CryptCore.Const.CERTREQ_ATTRIBUTE_COUNT)
if attrCount==0 then
    certReqObj:Free()
    print(ToANSIString("没有属性"))
    os.exit(-1)
end

local attrs=assert(certReqObj:GetAttribute())
certReqObj:Free()

for i,attr in ipairs(attrs) do
    print(ToANSIString(string.format("属性 %d，类型:%s，值:%s",i,attr["type"],CryptCore.HexEncode(attr["value"]))))
end
