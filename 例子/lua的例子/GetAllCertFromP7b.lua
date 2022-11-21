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
    print(ToANSIString(string.format("lua %s p7bFileName",scriptName)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tstoreName：设备类型，是个整数"))
    print(ToANSIString("\tcurrent_user：当前用户"))
    print(ToANSIString("\tlocal_machine：本机"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t获取证书库所有的证书"))
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

local argCount=#arg
if argCount~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local p7b=GetFileConetent(arg[1])
if p7b==nil then
    print(ToANSIString("读P7b文件失败"))
    os.exit(-1)
end


local store=CryptCore.LoadP7c(p7b)
if not store then
    print(ToANSIString("P7b文件格式错误"))
    os.exit(-1)
end
    
local certs=store:GetCerts()
store:Close()
local certCount=#certs
if certCount==0 then
    print(ToANSIString("P7b文件中没有证书"))
    os.exit(-1)
end
for i=1,certCount do
    PrintCertInfo(certs[i])
end
FreeCerts(certs)


