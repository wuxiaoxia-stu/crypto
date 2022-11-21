local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s cert [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\tpwd：使用私钥需要的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t注册证书到个人证书库。注意，不会注册到微软的个人证书库"))
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

if #arg~=1 and #arg~=2 then
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

local ku=certObj:GetKeyUsage()
local purpose=-1
if CryptCore.BitAnd(ku,0xC)~=0 then
    purpose=CryptCore.Const.CERT_PURPOSE_ENCRYPT
elseif CryptCore.BitAnd(ku,0x10)~=0 then
    purpose=CryptCore.Const.CERT_PURPOSE_KEYAGREEMENT
elseif CryptCore.BitAnd(ku,0x63)~=0 then
    purpose=CryptCore.Const.CERT_PURPOSE_SIGN
end


local keypair
local pwd=nil
if #arg==2 then
    pwd=arg[2]
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,purpose,pwd)
else
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,purpose)
end    

if keypair==nil then
    if pwd==nil then
        print(ToANSIString("证书没有私钥"));
    else
        print(ToANSIString("证书没有私钥，或者密码错误"));
    end
    certObj:Free()
    os.exit(-1)
end
keypair:Free()


local store=CryptCore.OpenStore(0,"my")
if store==nil then
    certObj:Free()
    print(ToANSIString("打开个人证书库失败"));
    os.exit(-1)
end


while (true) do
    if not store:Delete(certObj) then
        break
    end
end

if not store:Add(certObj) then
    certObj:Free()
    print(ToANSIString("注册证书失败"));
    os.exit(-1)
end

certObj:Free()
store:Close()
print(ToANSIString("注册证书成功"));


