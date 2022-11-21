local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s cert hashAlgo mgfAlgo label inFileName outFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(ToANSIString("\tmgfAlgo：MGF算法，比如:MGF1_SHA-1、MGF1_SHA256之类"))
    print(ToANSIString("\tlabel：label"))
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


function getHashAlgo(hashAlgo)
    hashAlgo=hashAlgo:upper()
    if hashAlgo== "SHA-1" or hashAlgo=="SHA1" then
        return CryptCore.Const.SHA1
    elseif  hashAlgo== "SM3" then
        return CryptCore.Const.SM3
    elseif  hashAlgo== "MD5" then
        return CryptCore.Const.MD5
    elseif hashAlgo== "SHA-224" or hashAlgo=="SHA224" then
        return CryptCore.Const.SHA224
    elseif hashAlgo== "SHA-256" or hashAlgo=="SHA256" then
        return CryptCore.Const.SHA256
    elseif hashAlgo== "SHA-384" or hashAlgo=="SHA384" then
        return CryptCore.Const.SHA384
    elseif hashAlgo== "SHA-512" or hashAlgo=="SHA512" then
        return CryptCore.Const.SHA512
    elseif hashAlgo== "SHA-512/224" then
        return CryptCore.Const["SHA-512/224"]
    elseif hashAlgo== "SHA-512/256" then
        return CryptCore.Const["SHA-512/256"]
    elseif hashAlgo== "SHA3-224" then
        return CryptCore.Const["SHA3-224"]
    elseif hashAlgo== "SHA3-256" then
        return CryptCore.Const["SHA3-256"]
    elseif hashAlgo== "SHA3-384" then
        return CryptCore.Const["SHA3-384"]
    elseif hashAlgo== "SHA3-512" then
        return CryptCore.Const["SHA3-512"]
    else
        return nil;
    end
end

function getMGFAlgo(mgfAlgo)
    mgfAlgo=mgfAlgo:upper()
    if mgfAlgo== "MGF1_SHA-1" or mgfAlgo=="MGF1_SHA1" then
        return CryptCore.Const.MGF1SHA1
    elseif mgfAlgo== "MGF1_SHA-224" or hashAlgo=="MGF1_SHA224" then
        return CryptCore.Const.MGF1SHA224
    elseif mgfAlgo== "MGF1_SHA-256" or hashAlgo=="MGF1_SHA256" then
        return CryptCore.Const.MGF1SHA256
    elseif mgfAlgo== "MGF1_SHA-384" or hashAlgo=="MGF1_SHA384" then
        return CryptCore.Const.MGF1SHA384
    elseif mgfAlgo== "MGF1_SHA-512" or hashAlgo=="MGF1_SHA512" then
        return CryptCore.Const.MGF1SHA512
    elseif mgfAlgo== "MGF1_SHA-512/224" then
        return CryptCore.Const["MGF1SHA512/224"]
    elseif mgfAlgo== "MGF1_SHA-512/256" then
        return CryptCore.Const["MGF1SHA512/256"]
    elseif mgfAlgo== "MGF1_SHA3-224" then
        return CryptCore.Const["MGF1SHA3_224"]
    elseif mgfAlgo== "MGF1_SHA3-256" then
        return CryptCore.Const["MGF1SHA3_256"]
    elseif mgfAlgo== "MGF1_SHA3-384" then
        return CryptCore.Const["MGF1SHA3_384"]
    elseif mgfAlgo== "MGF1_SHA3-512" then
        return CryptCore.Const["MGF1SHA3_512"]
    else
        return nil;
    end
end


if #arg~=6 and #arg~=7 then
    Usage(arg[0])
    os.exit(-1)
end

local hashAlgo=getHashAlgo(arg[2])
if hashAlgo==nil then
    print(ToANSIString("未知的Hash算法"));
    os.exit(-1)
end

local mgfAlgo=getMGFAlgo(arg[3])
if mgfAlgo==nil then
    print(ToANSIString("未知的MGF算法"));
    os.exit(-1)
end

local label=arg[4]

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


if certObj:Match("CertType='Encrypt'")==false then
    certObj:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local algo=CryptCore.Const.RSA_PKCS1_OAEP

local inFileName=arg[5]
local outFileName=arg[6]

local inData=GetFileConetent(inFileName)
if inData==nil then
    certObj:Free()
    print(ToANSIString("读输入文件失败"));
    os.exit(-1)
end


local keypair
local pwd=nil
--如果需要从证书库里获取私钥，则使用CryptCore.Const.SEARCH_KEYPAIR_FLAG_CURRENTUSER代替CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE
if #arg==7 then
    pwd=arg[7]
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_ENCRYPT,pwd)
else
    keypair=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_ENCRYPT)
end

certObj:Free()
if keypair==nil then
    if pwd==nil then
        print(ToANSIString("证书没有私钥"));
    else
        print(ToANSIString("证书没有私钥，或者密码错误"));
    end
    os.exit(-1)
end


local outData
outData=keypair:Decrypt{ ["algo"]=algo,["cipher"]=inData,
    ["mgfalgo"]=mgfAlgo,["hashalgo"]=hashAlgo,["label"]=label}
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


