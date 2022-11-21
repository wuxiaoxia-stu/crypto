local CryptCore=require("CryptCore")
local Asn1=require("Asn1")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tinFileName：要进行解密的文件名"))
    print(ToANSIString("\toutFileName：解密得到的明文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行数字信封解密运算，结果保存到outFileName文件中"))
end

local argCount=#arg
if argCount~=2 then
    Usage(arg[0])
    os.exit(-1)
end


local inFileName=arg[1]
local outFileName=arg[2]


local env=assert(CryptCore.NewEnvelopedData(false))

function GetCurveAsn1(curve)
    local oid=nil
    if curve==CryptCore.Const.ECC_CURVE_P192 then
        oid=Asn1.NewOid("1.2.840.10045.3.1.1")
    elseif curve==CryptCore.Const.ECC_CURVE_P224 then
        oid=Asn1.NewOid("1.3.132.0.33")
    elseif curve==CryptCore.Const.ECC_CURVE_P256 then
        oid=Asn1.NewOid("1.2.840.10045.3.1.7")
    elseif curve==CryptCore.Const.ECC_CURVE_P384 then
        oid=Asn1.NewOid("1.3.132.0.34")    
    elseif curve==CryptCore.Const.ECC_CURVE_P521 then
        oid=Asn1.NewOid("1.3.132.0.35")
    elseif curve==CryptCore.Const.ECC_CURVE_SM2 then
        oid=Asn1.NewOid("1.2.156.10197.1.301")
    end
    
    return oid
end
function GetTrueSubjectPublicKeyEncode(curve,publickeyEncode)
    local param=GetCurveAsn1(curve)
    if param==nil then
        return nil
    end
    local asn1=Asn1.Decode(publickeyEncode)
    if asn1==nil then
        return nil
    end
    
    if asn1.Type~="SEQUENCE" then
        return nil
    end
    local items=asn1.Value
    if #items~=2 then
        return nil
    end
    
    local algo=items[1]
    local publicKey=items[2]
    if algo.Type~="SEQUENCE" then
        return nil
    end
    
    local items=algo.Value
    local itemCount=#items
    if itemCount~=1 and itemCount~=2 then
        return nil
    end
        
    if itemCount==2 then
        if items[2].Type=="NULL" then
            items[2]=param
        elseif items[2]:Encode()==param:Encode() then
            return publickeyEncode
        else
            return nil
        end
    else
        items[2]=param
    end
    
    return asn1:Encode()
end

function ECDH(keypair,publickeyEncode,algo,cipher)
    local curve=keypair:ECCCurve()
    publickeyEncode=GetTrueSubjectPublicKeyEncode(curve,publickeyEncode)
    if publickeyEncode==nil then
        return nil
    end
    local device=keypair:Device()
    local publicKey=device:ImportSubjectPublicKeyInfo(publickeyEncode)
    device:Free()
    if publicKey==nil then
        return nil
    end
    local z=keypair:KeyAgreement{
        ["algo"]=algo,["resppublickey"]=publicKey,
        ["keylen"]=math.floor((keypair:Length()+7)/8)
    }
    publicKey:Free()
    return z
end
function DecryptKeyFromCertificate(keypair,cert,ridType,ridEncode,algo,param,cipher)
    if ridType==1 then
        local a=cert:GetAttribute(96)
        if CryptCore.HexDecode(cert:GetAttribute(96)) ~=ridEncode then
            return -7
        end
    elseif ridType==2 then
        local a=cert:GetAttribute(66)
        if CryptCore.HexDecode(cert:GetAttribute(66)) ~=ridEncode then
            return -7
        end
    else
        return -7
    end
        
    if algo==0x30000000 or algo==0x60000000 then
        return ECDH(keypair,param,algo,cipher)
    end
    
    if algo==0x20 then
        return keypair:Decrypt{ ["algo"]=algo,["cipher"]=cipher,
            ["mgfalgo"]=param.mgfalgo,["hashalgo"]=param.hashalgo,
            ["label"]=param.label}
    end
    
    return keypair:Decrypt{ ["algo"]=algo,["cipher"]=cipher,["der"]=true}
end

function DecryptKeyFromKeypair(keypair,ridType,ridEncode,algo,param,cipher)
    local certs=keypair:GetCerts()
    local rv
    for _,cert in ipairs(certs) do
        rv=DecryptKeyFromCertificate(keypair,cert,ridType,ridEncode,algo,param,cipher)
        if rv~=-7 then
            for _,cert in ipairs(certs) do
                cert:Free()
            end
            return rv
        end
    end
    
    for _,cert in ipairs(certs) do
        cert:Free()
    end
    return -7
end

function DecryptKeyFromDevice(device,ridType,ridEncode,algo,param,cipher)
    local keypairs=device:GetKeyPairs()
    local rv
    for _,keypair in ipairs(keypairs) do
        rv=DecryptKeyFromKeypair(keypair,ridType,ridEncode,algo,param,cipher)
        if rv~=-7 then
            for _,keypair in ipairs(keypairs) do
                keypair:Free()
            end
            return rv
        end
    end
    
    for _,keypair in ipairs(keypairs) do
        keypair:Free()
    end
    return -7
end

function DecryptKeyFromAllDevice(ridType,ridEncode,algo,param,cipher)
    local deviceSet=CryptCore.NewDeviceSet{ ["type"]=-1,["flag"]=0x100 }
    local rv
    for _,device in ipairs(deviceSet) do
        rv=DecryptKeyFromDevice(device,ridType,ridEncode,algo,param,cipher)
        if rv~=-7 then
            for _,device in ipairs(deviceSet) do
                device:Free()
            end
            return rv
        end
    end
    
    for _,device in ipairs(deviceSet) do
        device:Free()
    end
    return -7
end

env:SetDecryptKeyCallback(DecryptKeyFromAllDevice)

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    env:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    env:Free()
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

assert(env:DecryptInit())

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=env:DecryptUpdate(data)
    if outData==nil then
        env:Free()
        fIn:close()
        fOut:close()
        print(ToANSIString("解密失败"))
        os.exit(-1)
    end
    fOut:write(outData)
end

fIn:close()
fOut:close()
outData=env:DecryptFinal(data)
env:Free()
if outData==false then
    print(ToANSIString("解密失败"))
    os.exit(-1)
end

print(ToANSIString("解密成功"))
