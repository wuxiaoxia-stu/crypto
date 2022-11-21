local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function FreeDeviceSet(deviceSet)
	for _,device in ipairs(deviceSet) do
		device:Free()
	end
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

local deviceSet=CryptCore.NewDeviceSet{ ["type"]=-1,["flag"]=CryptCore.Const.DEVICE_FLAG_SILENT }

local deviceCount=#deviceSet

if deviceCount==0 then
	print(ToANSIString("没有设备"));
	os.exit(-1)
end

for i=1,deviceCount do
    local keypairs=deviceSet[i]:GetKeyPairs()
    local keypairCount=#keypairs
    for j=1,keypairCount do
        local certs=keypairs[j]:GetCerts()
        local certCount=#certs
        for k=1,certCount do
            PrintCertInfo(certs[k])
        end
        FreeCerts(certs)
    end
    FreeKeyPairs(keypairs)
end
FreeDeviceSet(deviceSet)
