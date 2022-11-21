local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s pfxFileName inFileName outFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tpfxFileName：PFX文件名"))
    print(ToANSIString("\tinFileName：输入文件名，要解密的文件"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tpwd：使用私钥需要的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件解密，结果保存到outFileName文件中"))
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


function GetEncryptAlgo(certObj)
    if certObj:Match("Algorithm='RSA'") then
        return CryptCore.Const.RSA_PKCS1_V1_5_ENC
    elseif certObj:Match("Algorithm='SM2'") then
        return CryptCore.Const.SM2_ENC
    else
        return -1
    end
end

function FreeCerts(certs)
    for _,cert in ipairs(certs) do
        cert:Free()
    end
end

local argCount=#arg
if argCount~=3 and argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local pfx=GetFileConetent(arg[1])
if pfx==nil then
    print(ToANSIString("读PFX文件失败"));
    os.exit(-1)
end

local pfxStore
if argCount==3 then
    pfxStore=CryptCore.LoadPFX(pfx)
else
    local pwd=arg[4]
    pfxStore=CryptCore.LoadPFX(pfx,CryptCore.ACPToUTF8(pwd))
end

if pfxStore==nil then
    print(ToANSIString("PFX文件格式错误或者密码错误"));
    os.exit(-1)
end
local certs=pfxStore:GetCerts()
pfxStore:Close()

local certObj
for _,cert in ipairs(certs) do
    if cert:Match("CertType='Encrypt' && HasPrivKey='True' ")==true then
        certObj=cert
        break
    end
end

if certObj==nil then
    FreeCerts(certs)
    print(ToANSIString("PFX文件中没有带私钥的加密证书"));
    os.exit(-1)
end

local algo
algo=GetEncryptAlgo(certObj)
if algo==-1 then
    FreeCerts(certs)
    print(ToANSIString("不支持的证书类型"));
    os.exit(-1)
end

local inFileName=arg[2]
local outFileName=arg[3]

local inData=GetFileConetent(inFileName)
if inData==nil then
    FreeCerts(certs)
    print(ToANSIString("读输入文件失败"));
    os.exit(-1)
end


local keypair
keypair=certObj:GetPrivateKey(0,CryptCore.Const.CERT_PURPOSE_ENCRYPT)

FreeCerts(certs)
if keypair==nil then
    print(ToANSIString("获取私钥失败"));
    os.exit(-1)
end


local outData
if algo==CryptCore.Const.SM2_ENC then
    outData=keypair:Decrypt{ ["algo"]=algo,["cipher"]=inData,["der"]=true}
else
    outData=keypair:Decrypt{ ["algo"]=algo,["cipher"]=inData }
end

keypair:Free()
if outData==nil then
    print(ToANSIString("解密失败"));
    os.exit(-1)
end

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("解密成功"));


