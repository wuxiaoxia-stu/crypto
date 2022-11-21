local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s pfxFileName signAlgo inFileName outFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tpfxFileName：PFX文件名"))
    print(ToANSIString("\tsignAlgo：签名算法，比如:SHA1WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tinFileName：输入文件名，要进行签名的文件"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tpwd：使用私钥需要的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行签名，结果保存到outFileName文件中"))
end

function GetSignAlgo(signAlgo)
    signAlgo=signAlgo:upper()
    if signAlgo== "SHA1WITHRSA" or hashAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA1WITHRSA
    elseif  signAlgo== "SHA224WITHRSA" or signAlgo== "SHA224WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA224WITHRSA
    elseif  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA256WITHRSA
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA384WITHRSA
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA512WITHRSA
    elseif  signAlgo== "MD5WITHRSA" or signAlgo== "MD5WITHRSAENCRYPTION" then
        return CryptCore.Const.MD5WITHRSA
    elseif  signAlgo== "SHA512/224WITHRSA" or signAlgo== "SHA512/224WITHRSAENCRYPTION" then
        return 34
    elseif  signAlgo== "SHA512/256WITHRSA" or signAlgo== "SHA512/256WITHRSAENCRYPTION" then
        return 35
    elseif  signAlgo== "SHA3-224WITHRSA" or signAlgo== "SHA3-224WITHRSAENCRYPTION" then
        return 36
    elseif  signAlgo== "SHA3-256WITHRSA" or signAlgo== "SHA3-256WITHRSAENCRYPTION" then
        return 37
    elseif  signAlgo== "SHA3-384WITHRSA" or signAlgo== "SHA3-384WITHRSAENCRYPTION" then
        return 38
    elseif  signAlgo== "SHA3-512WITHRSA" or signAlgo== "SHA3-512WITHRSAENCRYPTION" then
        return 39
    elseif  signAlgo== "SM3WITHSM2" then
        return CryptCore.Const.SM3WITHSM2
    elseif  signAlgo== "ECDSAWITHSHA1" then
        return CryptCore.Const.ECDSAWITHSHA1
    elseif  signAlgo== "ECDSAWITHSHA224" then
        return CryptCore.Const.ECDSAWITHSHA224
    elseif  signAlgo== "ECDSAWITHSHA256" then
        return CryptCore.Const.ECDSAWITHSHA256
    elseif  signAlgo== "ECDSAWITHSHA384" then
        return CryptCore.Const.ECDSAWITHSHA384
    elseif  signAlgo== "ECDSAWITHSHA512" then
        return CryptCore.Const.ECDSAWITHSHA512
    elseif  signAlgo== "ECDSAWITHSHA3-224" then
        return 40
    elseif  signAlgo== "ECDSAWITHSHA3-256" then
        return 41
    elseif  signAlgo== "ECDSAWITHSHA3-384" then
        return 42
    elseif  signAlgo== "ECDSAWITHSHA3-512" then
        return 43
    else
        return nil;
    end
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

function FreeCerts(certs)
    for _,cert in ipairs(certs) do
        cert:Free()
    end
end

local argCount=#arg
if argCount~=4 and argCount~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pfx=GetFileConetent(arg[1])
if pfx==nil then
    print(ToANSIString("读PFX文件失败"));
    os.exit(-1)
end

local pfxStore
if argCount==4 then
    pfxStore=CryptCore.LoadPFX(pfx)
else
    local pwd=arg[5]
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
    if cert:Match("CertType='Signature' && HasPrivKey='True' && InValidity='True' ")==true then
        certObj=cert
        break
    end
end

if certObj==nil then
    FreeCerts(certs)
    print(ToANSIString("PFX文件中没有带私钥的签名证书"));
    os.exit(-1)
end


local algo
algo=GetSignAlgo(arg[2])
if algo==nil then
    FreeCerts(certs)
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end

local inFileName=arg[3]
local outFileName=arg[4]

local keypair
keypair=certObj:GetPrivateKey(0,CryptCore.Const.CERT_PURPOSE_SIGN)

FreeCerts(certs)
if keypair==nil then
    print(ToANSIString("获取私钥失败"));
    os.exit(-1)
end

local signObj=keypair:NewSign { ["algo"]=algo }
keypair:Free()
if signObj==nil then
    print(ToANSIString("创建签名对象失败，可能是证书与签名算法不匹配"));
    os.exit(-1)
end

local fIn=io.open(inFileName,"rb")
if fIn==nil then
    signObj:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local data
local BLOCK_LEN=8192
while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    signObj:Update(data)
end

fIn:close()

local outData=signObj:Final()
signObj:Free()
if outData==nil then
    print(ToANSIString("签名失败"));
    os.exit(-1)
end

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("签名成功"));


