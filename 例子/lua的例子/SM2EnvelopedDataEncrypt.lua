local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName  algo inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：加密证书文件"))
    print(ToANSIString("\talgo：对称加密算法，比如:aes-128、sm1等"))
    print(ToANSIString("\tinFileName：要进行加密的明文文件名"))
    print(ToANSIString("\toutFileName：加密得到的密文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行数字信封加密运算，结果保存到outFileName文件中"))
end



function GetCert(filename)
    local fIn=io.open(filename,"rb")
    if fIn==nil then
        return nil
    end
    local inData=fIn:read("*a")
    fIn:close()
    
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
    elseif algo=="RC4" then
        return CryptCore.Const.ENVELOPEDDATA_ALGORITHM_RC4
    else
        return nil
    end
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

if cert:Match("CertType='Encrypt'")==false then
    cert:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

if cert:Match("Algorithm='SM2'")==false then
    cert:Free()
    print(ToANSIString("不是SM2证书"));
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
assert(env:SetUseQ7())

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    env:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    env:Free()
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

outData=env:EncryptInit()
fOut:write(outData)

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=env:EncryptUpdate(data)
    fOut:write(outData)
end

fIn:close()

outData=env:EncryptFinal()
env:Free()

fOut:write(outData)
fOut:close()
print(ToANSIString("加密成功"))


