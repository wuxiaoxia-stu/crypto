local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
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


function Usage(scriptName)
    print(ToANSIString(string.format("lua %s storeName [current_user|local_machine]",scriptName)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tstoreName：设备类型，是个整数"))
    print(ToANSIString("\tcurrent_user：当前用户"))
    print(ToANSIString("\tlocal_machine：本机"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t获取证书库所有的证书"))
end

local argCount=#arg
if argCount~=1 and argCount~=2 then
    Usage(arg[0])
    os.exit(-1)
end

local name=arg[1]
local type
if argCount==1 then
    type=CryptCore.Const.CERTSTORE_TYPE_CURRENTUSER
elseif arg[2]=="current_user" then
    type=CryptCore.Const.CERTSTORE_TYPE_CURRENTUSER
elseif arg[2]=="local_machine" then
    type=CryptCore.Const.CERTSTORE_TYPE_LOCALMACHINE
else
    Usage(arg[0])
    os.exit(-1)
end

local store=CryptCore.OpenStore(type,name)
if not store then
    print(ToANSIString("打开证书库失败"))
    os.exit(-1)
end
    
local certs=store:GetCerts()
store:Close()
local certCount=#certs
for i=1,certCount do
    PrintCertInfo(certs[i])
end
FreeCerts(certs)


