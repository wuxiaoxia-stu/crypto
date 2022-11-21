local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s cert publicKeyFileName zFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\tpublicKeyFileName：对方公钥保存的文件名"))
    print(ToANSIString("\tzFileName：共享信息保存的文件名"))
    print(ToANSIString("\tpwd：使用私钥需要的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t使用证书对应的密钥对与EC公钥进行密钥协商，结果保存到zFileName文件中"))
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


local argCount=#arg
if argCount~=3 and argCount~=4 then
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

local keypair
local pwd=nil
--如果需要从证书库里获取私钥，则使用CryptCore.Const.SEARCH_KEYPAIR_FLAG_CURRENTUSER代替CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE
if #arg==4 then
    pwd=arg[4]
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_KEYAGREEMENT,pwd)
else
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_KEYAGREEMENT)
end    
certObj:Free()
if keypair==nil then
    print(ToANSIString("获取私钥失败，没有私钥或者密码错误"));
    os.exit(-1)
end

local publicKeyEncode=GetFileConetent(arg[2])
if publicKeyEncode==nil then
    keypair:Free()
    print(ToANSIString("读公钥文件失败"));
    os.exit(-1)
end
local deviceObj=assert(keypair:Device())
local publicKey=deviceObj:ImportSubjectPublicKeyInfo(publicKeyEncode)
deviceObj:Free()
if publicKey==nil then
    keypair:Free()
    print(ToANSIString("错误的公钥编码"));
    os.exit(-1)
end

local bits=publicKey:Length()

local z=keypair:KeyAgreement{
    ["algo"]=0x30000000,
    ["resppublickey"]=publicKey,
    ["keylen"]=math.floor((bits+7)/8)
}
publicKey:Free()
keypair:Free()
if z==nil then
    print(ToANSIString("密钥协商失败"));
    os.exit(-1)
end

if Save(arg[3],z)==false then
    print(ToANSIString("保存共享数据文件失败"));
    os.exit(-1)
end

print(ToANSIString("密钥协商成功"));

