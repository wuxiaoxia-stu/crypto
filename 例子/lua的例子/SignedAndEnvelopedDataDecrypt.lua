local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s decCertFileName signCertFileName inFileName outFileName [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tdecCertFileName：解密证书文件"))
    print(ToANSIString("\tsignCertFileName：签名证书文件，可以为\"\""))
    print(ToANSIString("\tinFileName：要进行解密验证的文件名"))
    print(ToANSIString("\toutFileName：明文文件名"))
    print(ToANSIString("\tpwd：解密证书的密码"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行解密验证，结果保存到outFileName文件中"))
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
    print(ToANSIString("读解密证书文件失败或者不是证书文件"));
    os.exit(-1)
end

if encCert:Match("CertType='Encrypt'")==false then
    encCert:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local signCert=nil
if arg[2]~="" then
    signCert=GetCert(arg[2])
    if signCert==nil then
        encCert:Free()
        print(ToANSIString("读签名证书文件失败或者不是证书文件"));
        os.exit(-1)
    end
end

local inFileName=arg[3]
local outFileName=arg[4]

local inData=GetFileConetent(inFileName)
if inData==nil then
    encCert:Free()
    if signCert~=nil then
        signCert:Free()
    end
    print(ToANSIString("读文件失败"));
    os.exit(-1)
end

local pwd=nil
local keypairObj
if argCount==5 then
    pwd=arg[5]
    keypairObj=encCert:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_ENCRYPT,pwd)
else
    keypairObj=encCert:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_ENCRYPT)
end

if keypairObj==nil then
    encCert:Free()
    if signCert~=nil then
        signCert:Free()
    end
    print("no keypair or password error")
    os.exit(-1)
end
keypairObj:Free()

local signAndEnvObj=assert(CryptCore.NewSignedAndEnvelopedData(false))
if signCert~=nil then
    assert(signAndEnvObj:AddCert(signCert))
    signCert:Free()
end

local store=assert(CryptCore.OpenStore(2))
assert(store:Add(encCert))
encCert:Free()

assert(signAndEnvObj:AddStore(store))
store:Close()

local outData=signAndEnvObj:DecryptAndVerify(true,inData)

if outData==nil then
    signAndEnvObj:Free()
    print(ToANSIString("解密验证失败"))
    os.exit(-1)
end

signAndEnvObj:Free()

fOut=io.open(outFileName,"wb")
if fOut==nil then
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

fOut:write(outData)
fOut:close()
print(ToANSIString("解密验证成功"))


