local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s cert publicKeyFileName zFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：对方证书文件名"))
    print(ToANSIString("\tpublicKeyFileName：临时产生的公钥保存的文件名"))
    print(ToANSIString("\tzFileName：共享信息保存的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t产生临时密钥对与证书的EC公钥进行密钥协商，结果保存到zFileName文件中"))
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



if #arg~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local cert=GetFileConetent(arg[1])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

local certObj=CryptCore.NewCert(cert)
if certObj==nil then
    print(ToANSIString("不是证书文件"));
    os.exit(-1)
end

if certObj:Match("CertType='KeyAgreement' && Algorithm='ECC' ")==false then
    certObj:Free()
    print(ToANSIString("不是ECC的密钥协商证书"));
    os.exit(-1)
end

local publicKey=certObj:PublicKey()
certObj:Free()
if publicKey==nil then
    print(ToANSIString("获取证书公钥失败"));
    os.exit(-1)
end

local curve=publicKey:ECCCurve()
local bits=publicKey:Length()

if  curve==-1 then
    publicKey:Free()
    print(ToANSIString("不支持的椭圆曲线"));
    os.exit(-1)
end


local deviceObj=assert(CryptCore.NewDevice())
local publicKey2=assert(deviceObj:ImportPublicKey(publicKey:Encode()))
publicKey:Free()
publicKey=publicKey2
local keypair=deviceObj:GenerateKeyPair {
    ["algo"]=CryptCore.Const.GENKEYPAIR_ECC,
    ["bits"]=bits,
    ["curve"]=curve,
    ["tempkeypair"]=true,
}
deviceObj:Free()
if keypair==nil then
    publicKey:Free()
    print(ToANSIString("产生临时密钥对失败"));
    os.exit(-1)
end

local z=keypair:KeyAgreement{
    ["algo"]=0x30000000,
    ["resppublickey"]=publicKey,
    ["keylen"]=math.floor((bits+7)/8)
}
publicKey:Free()
if z==nil then
    keypair:Free()
    print(ToANSIString("密钥协商失败"));
    os.exit(-1)
end
publicKey=assert(keypair:PublicKey())
keypair:Free()
local publicKeyEncode=assert(publicKey:GetSubjectPublicKeyInfoEncode())
publicKey:Free()

if Save(arg[2],publicKeyEncode)==false then
    print(ToANSIString("保存公钥文件失败"));
    os.exit(-1)
end

if Save(arg[3],z)==false then
    print(ToANSIString("保存共享数据文件失败"));
    os.exit(-1)
end

print(ToANSIString("密钥协商成功"));


