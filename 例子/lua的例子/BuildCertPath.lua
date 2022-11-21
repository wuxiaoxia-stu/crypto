local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s cert",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证证书"))
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

function FreeCerts(certs)
	for _,cert in ipairs(certs) do
		cert:Free()
	end
end

function GetCertType(ku)
    if CryptCore.BitAnd(ku,
        CryptCore.BitOr(CryptCore.Const.KEYUSAGE_DIGITALSIGNATURE,CryptCore.Const.KEYUSAGE_NONREPUDIATION)
        )~=0 and 
        CryptCore.BitAnd(ku,
            CryptCore.BitNot(
                CryptCore.BitOr(CryptCore.Const.KEYUSAGE_DIGITALSIGNATURE,CryptCore.Const.KEYUSAGE_NONREPUDIATION)
            )
        )==0 then
         return "Signature"
    end
    
    if CryptCore.BitAnd(ku,
        CryptCore.BitOr(CryptCore.Const.KEYUSAGE_KEYENCIPHERMENT,CryptCore.Const.KEYUSAGE_DATAENCIPHERMENT)
        )~=0 and 
        CryptCore.BitAnd(ku,
            CryptCore.BitNot(
                CryptCore.BitOr(CryptCore.Const.KEYUSAGE_KEYENCIPHERMENT,CryptCore.Const.KEYUSAGE_DATAENCIPHERMENT)
            )
        )==0 then
         return "Encrypt"
    end
    
    return "Unknown"
end

function GetPublicKeyType(cert)
    local algo=cert:GetPublicKeyAlgorithm()
    if algo==CryptCore.Const.RSA then
        return "RSA"
    elseif algo==CryptCore.Const.ECC then
        local curve=cert:GetAttribute(43)
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
        else
            return "Unknown ECC"
        end
    else
        return "Unknown"
    end
end

function PrintCertInfo(cert)
    local subject=cert:GetSubject()
    local ku=cert:GetKeyUsage()
    local certType=GetCertType(ku)
    local publicKeyType=GetPublicKeyType(cert)
    local str=string.format("%s(%s:%s)",subject,publicKeyType,certType)
    print(ToANSIString(str))
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

local certs=cert:GetCertPath()
cert:Free()

if certs==nil then
    print(ToANSIString("构造证书路径失败"));
    os.exit(-1)
end

local certCount=#certs
for i=1,certCount do
    PrintCertInfo(certs[i])
end
FreeCerts(certs)


