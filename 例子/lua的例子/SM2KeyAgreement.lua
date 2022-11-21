local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s certFileName1 pwd1 certFileName2 pwd2 len zFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName1：发送方的证书文件名"))
    print(ToANSIString("\tpwd1：发送方的证书对应的密码"))
    print(ToANSIString("\tcertFileName2：接收方的证书文件名"))
    print(ToANSIString("\tpwd2：接收方的证书对应的密码"))
    print(ToANSIString("\tlen：共享信息的长度"))
    print(ToANSIString("\tzFileName：共享信息保存的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行SM2进行密钥协商，结果保存到zFileName文件中"))
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

function GenTempSM2KeyPair(deviceObj)
    return deviceObj:GenerateKeyPair {
        ["algo"]=CryptCore.Const.GENKEYPAIR_ECC,
        ["bits"]=256,
        ["curve"]=CryptCore.Const.ECC_CURVE_SM2,
        ["tempkeypair"]=true,
    }

end

local argCount=#arg
if argCount~=6 then
    Usage(arg[0])
    os.exit(-1)
end

local senderCertObj

local cert=GetFileConetent(arg[1])
if cert==nil then
    print(ToANSIString("读发送方证书文件失败"));
    os.exit(-1)
end

local senderCertObj=CryptCore.NewCert(cert)
if senderCertObj==nil then
    print(ToANSIString("发送方证书文件不是证书文件"));
    os.exit(-1)
end

if senderCertObj:Match("CertType='KeyAgreement' && Algorithm='SM2' ")==false then
    senderCertObj:Free()
    print(ToANSIString("发送方证书文件不是SM2的密钥协商证书"));
    os.exit(-1)
end

local senderKeypair
local senderPwd=arg[2]
--如果需要从证书库里获取私钥，则使用CryptCore.Const.SEARCH_KEYPAIR_FLAG_CURRENTUSER代替CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE
senderKeypair=senderCertObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_KEYAGREEMENT,senderPwd)
senderCertObj:Free()
if senderKeypair==nil then
    print(ToANSIString("获取发送方证书私钥失败，没有私钥或者密码错误"));
    os.exit(-1)
end


local receiverCertObj

cert=GetFileConetent(arg[3])
if cert==nil then
    senderKeypair:Free()
    print(ToANSIString("读接收方证书文件失败"));
    os.exit(-1)
end

local receiverCertObj=CryptCore.NewCert(cert)
if receiverCertObj==nil then
    senderKeypair:Free()
    print(ToANSIString("接收方证书文件不是证书文件"));
    os.exit(-1)
end

if receiverCertObj:Match("CertType='KeyAgreement' && Algorithm='SM2' ")==false then
    receiverCertObj:Free()
    senderKeypair:Free()
    print(ToANSIString("接收方证书文件不是SM2的密钥协商证书"));
    os.exit(-1)
end

local receiverKeypair
local receiverPwd=arg[4]
--如果需要从证书库里获取私钥，则使用CryptCore.Const.SEARCH_KEYPAIR_FLAG_CURRENTUSER代替CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE
receiverKeypair=receiverCertObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_KEYAGREEMENT,receiverPwd)
receiverCertObj:Free()
if receiverKeypair==nil then
    senderKeypair:Free()
    print(ToANSIString("获取接收方证书私钥失败，没有私钥或者密码错误"));
    os.exit(-1)
end


local zLen=tonumber(arg[5])
local zFileName=arg[6]


local senderPublicKey=assert(senderKeypair:PublicKey())
local senderPublicKeyEncode=assert(senderPublicKey:GetSubjectPublicKeyInfoEncode())
senderPublicKey:Free()
print(ToANSIString(string.format("发送方的公钥:\n\t%s",CryptCore.HexEncode(senderPublicKeyEncode))))


local senderDeviceObj=assert(senderKeypair:Device())
local senderTempKeypair=GenTempSM2KeyPair(senderDeviceObj)
if senderTempKeypair==nil then
    senderKeypair:Free()
    receiverKeypair:Free()
    senderDeviceObj:Free()
    print(ToANSIString("发送方产生临时SM2密钥对错误"));
    os.exit(-1)
end

print(ToANSIString("发送方产生临时SM2密钥对成功"));
local senderTempPublicKey=assert(senderTempKeypair:PublicKey())

local senderTempPublicKeyEncode=assert(senderTempPublicKey:GetSubjectPublicKeyInfoEncode())
senderTempPublicKey:Free()
print(ToANSIString(string.format("发送方的临时SM2公钥:\n\t%s",CryptCore.HexEncode(senderTempPublicKeyEncode))))


local receiverPublicKey=assert(receiverKeypair:PublicKey())
local receiverPublicKeyEncode=assert(receiverPublicKey:GetSubjectPublicKeyInfoEncode())
receiverPublicKey:Free()
print(ToANSIString(string.format("接收方的公钥:\n\t%s",CryptCore.HexEncode(receiverPublicKeyEncode))))

local receiverDeviceObj=assert(receiverKeypair:Device())
local receiverTempKeypair=GenTempSM2KeyPair(receiverDeviceObj)
if receiverTempKeypair==nil then
    senderKeypair:Free()
    receiverKeypair:Free()
    senderTempKeypair:Free()
    senderDeviceObj:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("接收方产生临时SM2密钥对错误"));
    os.exit(-1)
end

print(ToANSIString("接收方产生临时SM2密钥对成功"));
local receiverTempPublicKey=assert(receiverTempKeypair:PublicKey())

local receiverTempPublicKeyEncode=assert(receiverTempPublicKey:GetSubjectPublicKeyInfoEncode())
receiverTempPublicKey:Free()
print(ToANSIString(string.format("接收方的临时SM2公钥:\n\t%s",CryptCore.HexEncode(receiverTempPublicKeyEncode))))


receiverPublicKey=senderDeviceObj:ImportSubjectPublicKeyInfo(receiverPublicKeyEncode)
if receiverPublicKey==nil then
    senderKeypair:Free()
    receiverKeypair:Free()
    senderTempKeypair:Free()
    receiverTempKeypair:Free()
    senderDeviceObj:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("发送方导入接收方公钥失败"));
    os.exit(-1)
end

receiverTempPublicKey=senderDeviceObj:ImportSubjectPublicKeyInfo(receiverTempPublicKeyEncode)
senderDeviceObj:Free()
if receiverTempPublicKey==nil then
    senderKeypair:Free()
    receiverKeypair:Free()
    senderTempKeypair:Free()
    receiverTempKeypair:Free()
    receiverPublicKey:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("发送方导入接收方临时公钥失败"));
    os.exit(-1)
end

local z=senderKeypair:KeyAgreement{
    ["algo"]=0x50000000,
    ["resppublickey"]=receiverPublicKey,
    ["keylen"]=zLen,
    ["tempkeypair"]=senderTempKeypair,
    ["tempresppublickey"]=receiverTempPublicKey,
    ["issender"]=true
}
senderKeypair:Free()
receiverPublicKey:Free()
senderTempKeypair:Free()
receiverTempPublicKey:Free()

if z==nil then
    receiverKeypair:Free()
    receiverTempKeypair:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("发送方计算共享信息失败"));
    os.exit(-1)
end
print(ToANSIString(string.format("发送方计算得到的共享信息:\n\t%s",CryptCore.HexEncode(z))))


senderPublicKey=receiverDeviceObj:ImportSubjectPublicKeyInfo(senderPublicKeyEncode)
if senderPublicKey==nil then
    receiverKeypair:Free()
    receiverTempKeypair:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("接收方导入发送方公钥失败"));
    os.exit(-1)
end

senderTempPublicKey=receiverDeviceObj:ImportSubjectPublicKeyInfo(senderTempPublicKeyEncode)
receiverDeviceObj:Free()
if senderTempPublicKey==nil then
    receiverKeypair:Free()
    receiverTempKeypair:Free()
    receiverDeviceObj:Free()
    senderPublicKey:Free()
    print(ToANSIString("接收方导入发送方临时公钥失败"));
    os.exit(-1)
end

local z2=receiverKeypair:KeyAgreement{
    ["algo"]=0x50000000,
    ["resppublickey"]=senderPublicKey,
    ["keylen"]=zLen,
    ["tempkeypair"]=receiverTempKeypair,
    ["tempresppublickey"]=senderTempPublicKey,
    ["issender"]=false
}
receiverKeypair:Free()
senderPublicKey:Free()
receiverTempKeypair:Free()
senderTempPublicKey:Free()

if z2==nil then
    print(ToANSIString("接收方计算共享信息失败"));
    os.exit(-1)
end
print(ToANSIString(string.format("接收方计算得到的共享信息:\n\t%s",CryptCore.HexEncode(z2))))

if z~=z2 then
    print(ToANSIString("发送方和接收方计算共享信息不同"));
    os.exit(-1)
end

if Save(zFileName,z)==false then
    print(ToANSIString("保存共享数据文件失败"));
    os.exit(-1)
end

print(ToANSIString("密钥协商成功"));

