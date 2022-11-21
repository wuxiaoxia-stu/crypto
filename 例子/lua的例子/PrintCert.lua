local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s cert",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t输出证书的详细信息"))
	os.exit(-1)
end

function GetCert(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return CryptCore.NewCert(inData)
end


function PrintVersion(cert)
	local version=cert:GetVersion()
    if version==CryptCore.Const.CERT_VERSION_V1 then
        print("Version: V1")
    elseif version==CryptCore.Const.CERT_VERSION_V2 then
        print("Version: V2")
    elseif version==CryptCore.Const.CERT_VERSION_V3 then
        print("Version: V3")
    else
        print(string.format("Version: Unknown Version(%d)",version))
    end
end

function PrintSignAlgo(cert)
	local algo=cert:GetSignAlgorithm()
    if algo==CryptCore.Const.MD5WITHRSA then
        print("Sign Algorithm: MD5WithRSA")
    elseif algo==CryptCore.Const.SHA1WITHRSA then
        print("Sign Algorithm: SHA1WithRSA")
    elseif algo==CryptCore.Const.SHA224WITHRSA then
        print("Sign Algorithm: SHA224WithRSA")
    elseif algo==CryptCore.Const.SHA256WITHRSA then
        print("Sign Algorithm: SHA256WithRSA")
    elseif algo==CryptCore.Const.SHA384WITHRSA then
        print("Sign Algorithm: SHA384WithRSA")
    elseif algo==CryptCore.Const.SHA512WITHRSA then
        print("Sign Algorithm: SHA512WithRSA")
    elseif algo==CryptCore.Const.DSAWITHSHA1 then
        print("Sign Algorithm: DSAWithSHA1")
    elseif algo==CryptCore.Const.DSAWITHSHA224 then
        print("Sign Algorithm: DSAWithSHA224")
    elseif algo==CryptCore.Const.DSAWITHSHA256 then
        print("Sign Algorithm: DSAWithSHA256")
    elseif algo==CryptCore.Const.ECDSAWITHSHA1 then
        print("Sign Algorithm: ECDSAWithSHA1")
    elseif algo==CryptCore.Const.ECDSAWITHSHA224 then
        print("Sign Algorithm: ECDSAWithSHA224")
    elseif algo==CryptCore.Const.ECDSAWITHSHA256 then
        print("Sign Algorithm: ECDSAWithSHA256")
    elseif algo==CryptCore.Const.ECDSAWITHSHA384 then
        print("Sign Algorithm: ECDSAWithSHA384")
    elseif algo==CryptCore.Const.ECDSAWITHSHA512 then
        print("Sign Algorithm: ECDSAWithSHA512")
    elseif algo==CryptCore.Const.SM3WITHSM2 then
        print("Sign Algorithm: SM3WithSM2")
    else
        print(string.format("Sign Algorithm: Unknown Sign Algorithm(%d)",algo))
    end
end


function PrintPublicKeyAlgo(cert)
	local algo=cert:GetPublicKeyAlgorithm()
    if algo==CryptCore.Const.RSA then
        print("PublicKey Algorithm: RSA")
    elseif algo==CryptCore.Const.DSA then
        print("PublicKey Algorithm: DSA")
    elseif algo==CryptCore.Const.DH then
        print("PublicKey Algorithm: DH")
    elseif algo==CryptCore.Const.ECC then
        local curve=cert:GetPublicKeyEccCurve()
        if curve==CryptCore.Const.ECC_CURVE_SM2 then
            print("PublicKey Algorithm: SM2")
        elseif curve==CryptCore.Const.ECC_CURVE_P192 then
            print("PublicKey Algorithm: ECC P-192")
        elseif curve==CryptCore.Const.ECC_CURVE_P224 then
            print("PublicKey Algorithm: ECC P-224")
        elseif curve==CryptCore.Const.ECC_CURVE_P384 then
            print("PublicKey Algorithm: ECC P-384")
        elseif curve==CryptCore.Const.ECC_CURVE_P521 then
            print("PublicKey Algorithm: ECC P-521")
        else
            print(string.format("PublicKey Algorithm: ECC Unknown Curve(%d)",curve))
        end
    else
        print(string.format("PublicKey Algorithm: Unknown PublicKey Algorithm(%d)",algo))
    end
end

function PrintKeyUsage(cert)
    local ku=cert:GetKeyUsage()
    if ku==-1 then
        print("KeyUsage: No KeyUsage Extension")
        return
    end
    local t={}
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_DIGITALSIGNATURE)~=0 then
        t[#t+1]="digitalSignature"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_NONREPUDIATION)~=0 then
        t[#t+1]="nonRepudiation/contentCommitment"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_KEYENCIPHERMENT)~=0 then
        t[#t+1]="keyEncipherment"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_DATAENCIPHERMENT)~=0 then
        t[#t+1]="dataEncipherment"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_KEYAGREEMENT)~=0 then
        t[#t+1]="keyAgreement"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_KEYCERTSIGN)~=0 then
        t[#t+1]="keyCertSign"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_CRLSIGN)~=0 then
        t[#t+1]="cRLSign"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_ENCIPHERONLY)~=0 then
        t[#t+1]="encipherOnly"
    end
    
    if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_DECIPHERONLY)~=0 then
        t[#t+1]="decipherOnly"
    end
    
    print(string.format("KeyUsage: %s",table.concat(t,",")))
end

if #arg~=1 then
	Usage(arg[0])
    os.exit(-1)
end

local cert=GetCert(arg[1])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

PrintVersion(cert)

local sn=cert:GetSerialNumber()
print(string.format("SerialNumber: %s",sn))

PrintSignAlgo(cert)

local issuer=cert:GetIssuer()
print(ToANSIString(string.format("Issuer: %s",issuer)))

local notBefore=cert:GetNotBefore()
print(string.format("NotBefore: %s",notBefore))

local notAfter=cert:GetNotAfter()
print(string.format("NotAfter: %s",notAfter))

local subject=cert:GetSubject()
print(ToANSIString(string.format("Subject: %s",subject)))

PrintPublicKeyAlgo(cert)
local bits=cert:GetPublicKeyBits()
print(string.format("PublicKey Bits: %d",bits))

PrintKeyUsage(cert)

cert:Free()
