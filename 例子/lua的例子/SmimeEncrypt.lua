local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName algo inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：加密证书文件"))
    print(ToANSIString("\talgo：对称加密算法，比如:aes-128、sm1等"))
    print(ToANSIString("\tinFileName：要进行加密的MIME文件名"))
    print(ToANSIString("\toutFileName：加密得到的SMIME密文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行SMIME加密运算，结果保存到outFileName文件中"))
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

function GetAlgo(algoName)
    local algo=algoName:upper()
    if algo=="AES-128" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES128CBC
    elseif algo=="AES-192" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES192CBC
    elseif algo=="AES-256" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES256CBC
    elseif algo=="DES" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_DESCBC
    elseif algo=="3DES" or algo=="TDES" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_TDESCBC
    elseif algo=="RC2" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_RC2CBC
    elseif algo=="SSF33" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SSF33CBC
    elseif algo=="SM1" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM1CBC
    elseif algo=="SM4" or algo=="SMS4" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM4CBC
    else
        return nil
    end
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
if argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end


local cert=GetCert(arg[1])

if cert==nil then
    print(ToANSIString("读文件失败或者不是证书文件"));
    os.exit(-1)
end

if cert:InValidity()==false then
    cert:Free()
    print(ToANSIString("证书不在有效期内"));
    os.exit(-1)
end

if cert:Match("CertType='Encrypt' || CertType='KeyAgreement'")==false then
    cert:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local algo=GetAlgo(arg[2])
if algo==nil then
    cert:Free()
    print(ToANSIString("不支持的加密算法"));
    os.exit(-1)
end

local inFileName=arg[3]
local outFileName=arg[4]

local env=assert(CryptCore.NewEnvelopedData(true))
assert(env:SetEncAlgorithm(algo))
assert(env:AddCert(cert))
cert:Free()

local data=GetFileConetent(inFileName)
if data==nil then
    env:Free()
    print(ToANSIString(string.format("读文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local mime=CryptCore.NewMime(data)
if mime==nil then
    env:Free()
    print(ToANSIString(string.format("文件(%s)不是MIME文件",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local smime=mime:Encrypt(env)
env:Free()
mime:Free()

if smime==nil then
    print(ToANSIString("加密失败"))
    os.exit(-1)
end

local outData=smime:Encode()
smime:Free()

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("加密成功"))


