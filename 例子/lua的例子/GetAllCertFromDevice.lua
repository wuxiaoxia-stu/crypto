local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function FreeKeyPairs(keypairs)
	for _,keypair in ipairs(keypairs) do
		keypair:Free()
	end
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
    print(ToANSIString(string.format("lua %s deviceType deviceSn [pwd]",scriptName)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tdeviceType：设备类型，是个整数"))
    print(ToANSIString("\tdeviceSn：设备序列号"))
    print(ToANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t获取指定设备里所有的证书"))
end

local argCount=#arg
if argCount~=3 and argCount~=2 then
    Usage(arg[0])
    os.exit(-1)
end

local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local devicePwd=arg[3]

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(ToANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
if argCount==3 then
    local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
    if result==false then
        if retryNumer==0 then
            print(ToANSIString("验证密码失败，设备已经锁死"))
        else
            print(ToANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
        end
        deviceObj:Free()
        os.exit(-1)
    elseif result==nil then
        deviceObj:Free()
        print(ToANSIString("验证密码出错"))
        os.exit(-1)
    end
elseif deviceObj:MustLogin() then
    deviceObj:Free()
    print(ToANSIString("必须输入密码"))
    os.exit(-1)
end

local keypairs=deviceObj:GetKeyPairs()
local keypairCount=#keypairs
for i=1,keypairCount do
    local certs=keypairs[i]:GetCerts()
    local certCount=#certs
    for j=1,certCount do
        PrintCertInfo(certs[j])
    end
    FreeCerts(certs)
end
FreeKeyPairs(keypairs)

deviceObj:Free()
