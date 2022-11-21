local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s isSender certFileName pwd len zFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tisSender：是否发送方，true为发送方，false为接收方"))
    print(ToANSIString("\tcertFileName：证书文件名"))
    print(ToANSIString("\tpwd：对应的密码"))
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
if argCount~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local isSender
if arg[1] =="true" then
    isSender=true
elseif arg[1] =="false" then
    isSender=false
else
    Usage(arg[0])
    os.exit(-1)
end

local senderCertObj

local cert=GetFileConetent(arg[2])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

local senderCertObj=CryptCore.NewCert(cert)
if senderCertObj==nil then
    print(ToANSIString("证书文件不是证书文件"));
    os.exit(-1)
end

if senderCertObj:Match("CertType='KeyAgreement' && Algorithm='SM2' ")==false then
    senderCertObj:Free()
    print(ToANSIString("证书文件不是SM2的密钥协商证书"));
    os.exit(-1)
end

local senderKeypair
local senderPwd=arg[3]
--如果需要从证书库里获取私钥，则使用CryptCore.Const.SEARCH_KEYPAIR_FLAG_CURRENTUSER代替CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE
senderKeypair=senderCertObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_KEYAGREEMENT,senderPwd)
senderCertObj:Free()
if senderKeypair==nil then
    print(ToANSIString("获取证书私钥失败，没有私钥或者密码错误"));
    os.exit(-1)
end


local zLen=tonumber(arg[4])
local zFileName=arg[5]


local senderPublicKey=assert(senderKeypair:PublicKey())
local senderPublicKeyEncode=assert(senderPublicKey:GetSubjectPublicKeyInfoEncode())
senderPublicKey:Free()
print(ToANSIString(string.format("证书公钥:\n\t%s",CryptCore.HexEncode(senderPublicKeyEncode))))


local senderDeviceObj=assert(senderKeypair:Device())
local senderTempKeypair=GenTempSM2KeyPair(senderDeviceObj)
if senderTempKeypair==nil then
    senderKeypair:Free()
    senderDeviceObj:Free()
    print(ToANSIString("产生临时SM2密钥对错误"));
    os.exit(-1)
end

print(ToANSIString("产生临时SM2密钥对成功"));
local senderTempPublicKey=assert(senderTempKeypair:PublicKey())

local senderTempPublicKeyEncode=assert(senderTempPublicKey:GetSubjectPublicKeyInfoEncode())
senderTempPublicKey:Free()
print(ToANSIString(string.format("临时SM2公钥:\n\t%s",CryptCore.HexEncode(senderTempPublicKeyEncode))))

local receiverDeviceObj=assert(CryptCore.NewDevice())
local receiverKeypair=GenTempSM2KeyPair(receiverDeviceObj)
if receiverKeypair==nil then
    senderKeypair:Free()
    senderTempKeypair:Free()
    senderDeviceObj:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("软件产生SM2密钥对错误"));
    os.exit(-1)
end

local receiverPublicKey=assert(receiverKeypair:PublicKey())
local receiverPublicKeyEncode=assert(receiverPublicKey:GetSubjectPublicKeyInfoEncode())
receiverPublicKey:Free()
print(ToANSIString(string.format("软件公钥:\n\t%s",CryptCore.HexEncode(receiverPublicKeyEncode))))

local receiverTempKeypair=GenTempSM2KeyPair(receiverDeviceObj)
if receiverTempKeypair==nil then
    senderKeypair:Free()
    receiverKeypair:Free()
    senderTempKeypair:Free()
    senderDeviceObj:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("软件产生临时SM2密钥对错误"));
    os.exit(-1)
end

print(ToANSIString("软件产生临时SM2密钥对成功"));
local receiverTempPublicKey=assert(receiverTempKeypair:PublicKey())

local receiverTempPublicKeyEncode=assert(receiverTempPublicKey:GetSubjectPublicKeyInfoEncode())
receiverTempPublicKey:Free()
print(ToANSIString(string.format("软件的临时SM2公钥:\n\t%s",CryptCore.HexEncode(receiverTempPublicKeyEncode))))


receiverPublicKey=senderDeviceObj:ImportSubjectPublicKeyInfo(receiverPublicKeyEncode)
if receiverPublicKey==nil then
    senderKeypair:Free()
    receiverKeypair:Free()
    senderTempKeypair:Free()
    receiverTempKeypair:Free()
    senderDeviceObj:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("导入接收方公钥失败"));
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
    print(ToANSIString("导入接收方临时公钥失败"));
    os.exit(-1)
end

local z=senderKeypair:KeyAgreement{
    ["algo"]=0x50000000,
    ["resppublickey"]=receiverPublicKey,
    ["keylen"]=zLen,
    ["tempkeypair"]=senderTempKeypair,
    ["tempresppublickey"]=receiverTempPublicKey,
    ["issender"]=isSender
}
senderKeypair:Free()
receiverPublicKey:Free()
senderTempKeypair:Free()
receiverTempPublicKey:Free()

if z==nil then
    receiverKeypair:Free()
    receiverTempKeypair:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("计算共享信息失败"));
    os.exit(-1)
end
print(ToANSIString(string.format("计算得到的共享信息:\n\t%s",CryptCore.HexEncode(z))))


senderPublicKey=receiverDeviceObj:ImportSubjectPublicKeyInfo(senderPublicKeyEncode)
if senderPublicKey==nil then
    receiverKeypair:Free()
    receiverTempKeypair:Free()
    receiverDeviceObj:Free()
    print(ToANSIString("软件导入发送方公钥失败"));
    os.exit(-1)
end

senderTempPublicKey=receiverDeviceObj:ImportSubjectPublicKeyInfo(senderTempPublicKeyEncode)
receiverDeviceObj:Free()
if senderTempPublicKey==nil then
    receiverKeypair:Free()
    receiverTempKeypair:Free()
    receiverDeviceObj:Free()
    senderPublicKey:Free()
    print(ToANSIString("软件导入发送方临时公钥失败"));
    os.exit(-1)
end

local z2=receiverKeypair:KeyAgreement{
    ["algo"]=0x50000000,
    ["resppublickey"]=senderPublicKey,
    ["keylen"]=zLen,
    ["tempkeypair"]=receiverTempKeypair,
    ["tempresppublickey"]=senderTempPublicKey,
    ["issender"]=not isSender
}
receiverKeypair:Free()
senderPublicKey:Free()
receiverTempKeypair:Free()
senderTempPublicKey:Free()

if z2==nil then
    print(ToANSIString("软件计算共享信息失败"));
    os.exit(-1)
end
print(ToANSIString(string.format("软件计算得到的共享信息:\n\t%s",CryptCore.HexEncode(z2))))

if z~=z2 then
    print(ToANSIString("双方计算共享信息不同"));
    os.exit(-1)
end

if Save(zFileName,z)==false then
    print(ToANSIString("保存共享数据文件失败"));
    os.exit(-1)
end

print(ToANSIString("密钥协商成功"));

