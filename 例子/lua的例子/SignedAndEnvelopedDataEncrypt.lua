local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s enCertFileName signCertFileName inFileName outFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tenCertFileName：加密证书文件"))
    print(ToANSIString("\tsignCertFileName：签名证书文件"))
    print(ToANSIString("\tinFileName：要进行签名加密的明文文件名"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tpwd：签名证书的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行签名加密，结果保存到outFileName文件中"))
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

function GetCert(filename)
    local inData=GetFileConetent(filename)
    if inData==nil then
        return nil
    end
    
    return CryptCore.NewCert(inData)
end


function GetEncAlgo(encCert)
    if encCert:Match("Algorithm='SM2'") then
        return 4
    else
        return 1
    end
end


function GetSignAlgo(signCert)
    if signCert:Match("Algorithm='SM2'") then
        return 25
    elseif signCert:Match("Algorithm='RSA'") then
        return 4
    elseif signCert:Match("Algorithm='ECC'") then
        return 18
    else
        return -1
    end
end

local argCount=#arg
if argCount~=4 and argCount~=5 then
    Usage(arg[0])
    os.exit(-1)
end


local encCert=GetCert(arg[1])

if encCert==nil then
    print(ToANSIString("读加密证书文件失败或者不是证书文件"));
    os.exit(-1)
end

if encCert:InValidity()==false then
    encCert:Free()
    print(ToANSIString("加密证书不在有效期内"));
    os.exit(-1)
end

if encCert:Match("CertType='Encrypt'")==false then
    encCert:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local signCert=GetCert(arg[2])
if signCert==nil then
    encCert:Free()
    print(ToANSIString("读签名证书文件失败或者不是证书文件"));
    os.exit(-1)
end
if signCert:InValidity()==false then
    encCert:Free()
    signCert:Free()
    print(ToANSIString("签名证书不在有效期内"));
    os.exit(-1)
end

if signCert:Match("CertType='Signature'")==false then
    encCert:Free()
    signCert:Free()
    print(ToANSIString("不是签名证书"));
    os.exit(-1)
end

local inFileName=arg[3]
local outFileName=arg[4]

local inData=GetFileConetent(inFileName)
if inData==nil then
    encCert:Free()
    signCert:Free()
    print(ToANSIString("读文件失败"));
    os.exit(-1)
end

local encAlgo=GetEncAlgo(encCert)
local signAlgo=GetSignAlgo(signCert)

local pwd=nil
local keypairObj
if argCount==5 then
    pwd=arg[5]
    keypairObj=signCert:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN,pwd)
else
    keypairObj=signCert:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN)
end

if keypairObj==nil then
    encCert:Free()
    signCert:Free()
    print("no keypair or password error")
    os.exit(-1)
end

local signAndEnvObj=assert(CryptCore.NewSignedAndEnvelopedData(true))
assert(signAndEnvObj:SetEncAlgorithm(encAlgo))
assert(signAndEnvObj:AddEncCert(encCert))
encCert:Free()

assert(signAndEnvObj:SetClearText(inData))
local outData=signAndEnvObj:SignAndEncrypt(signAlgo,signCert)
signCert:Free()
signAndEnvObj:Free()

if outData==nil then
    print(ToANSIString("签名加密失败"))
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

fOut:write(outData)
fOut:close()
print(ToANSIString("签名加密成功"))


