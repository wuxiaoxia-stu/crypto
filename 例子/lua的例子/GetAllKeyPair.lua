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

function GetPublicKeyType(keypair)
    local algo=keypair:Algorithm()
    if algo==CryptCore.Const.RSA then
        return "RSA"
    elseif algo==CryptCore.Const.ECC then
        local curve=keypair:ECCCurve()
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

function GetKeyPairTypeName(type)
    if type==CryptCore.Const.KEYPAIRTYPE_ENCRYPT then
        return "Encrypt"
    elseif type==CryptCore.Const.KEYPAIRTYPE_SIGNATURE then
        return "Signature"
    elseif type==CryptCore.Const.KEYPAIRTYPE_KEYAGREEMENT then
        return "KeyAgreement"
    else
        return "Unknown"
    end
end

function PrintKeypairInfo(keypair)
    local publicKeyType=GetPublicKeyType(keypair)
    local typeName=GetKeyPairTypeName(keypair:Type())
    local certs=keypair:GetCerts()
    local certCount=#certs
    
    local str=string.format("\tLabel:%s,Type:%s,Algo:%s,Bits:%d,CertCount:%d",
        keypair:Label(),typeName,publicKeyType,keypair:Length(),certCount)
    print(ToANSIString(str))
    if certCount>0 then
        for i,cert in ipairs(certs) do
            print(string.format("\tCert %d:",i))
            print(ToANSIString(string.format("\t\tSubject:%s",cert:GetSubject())))
            print(string.format("\t\tThumbprint:%s",CryptCore.HexEncode(cert:GetThumbprint())))
        end
    end
    FreeCerts(certs)
    print("")
end

local deviceSet=CryptCore.NewDeviceSet{ ["type"]=-1,["flag"]=CryptCore.Const.DEVICE_FLAG_SILENT }

local deviceCount=#deviceSet

if deviceCount==0 then
	print(ToANSIString("没有设备"));
	os.exit(-1)
end

for i=1,deviceCount do
    local device=deviceSet[i]
    local keypairs=device:GetKeyPairs()
    local keypairCount=#keypairs
    print(ToANSIString(string.format("Device %d,Type:%d,SerialNumber=%s",i,device:Type(),device:SerialNumber())))
    for j=1,keypairCount do
        PrintKeypairInfo(keypairs[j])
    end
    FreeKeyPairs(keypairs)
end
FreeDeviceSet(deviceSet)
