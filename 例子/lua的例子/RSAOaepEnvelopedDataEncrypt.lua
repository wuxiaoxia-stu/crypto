local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName algo hashAlgo mgfAlgo label inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：加密证书文件"))
    print(ToANSIString("\talgo：对称加密算法，比如:aes-128、sm1等"))
    print(ToANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(ToANSIString("\tmgfAlgo：MGF算法，比如:MGF1_SHA-1、MGF1_SHA256之类"))
    print(ToANSIString("\tlabel：Hex编码的label"))
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
    elseif mgfAlgo== "MGF1_SHA-224" or mgfAlgo=="MGF1_SHA224" then
        return CryptCore.Const.MGF1SHA224
    elseif mgfAlgo== "MGF1_SHA-256" or mgfAlgo=="MGF1_SHA256" then
        return CryptCore.Const.MGF1SHA256
    elseif mgfAlgo== "MGF1_SHA-384" or mgfAlgo=="MGF1_SHA384" then
        return CryptCore.Const.MGF1SHA384
    elseif mgfAlgo== "MGF1_SHA-512" or mgfAlgo=="MGF1_SHA512" then
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
if argCount~=7 then
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

if cert:Match("CertType='Encrypt' && Algorithm='RSA'")==false then
    cert:Free()
    print(ToANSIString("不是RSA加密证书"));
    os.exit(-1)
end

local algo=GetAlgo(arg[2])
if algo==nil then
    cert:Free()
    print(ToANSIString("不支持的加密算法"));
    os.exit(-1)
end

local hashAlgo=getHashAlgo(arg[3])
if hashAlgo==nil then
    cert:Free()
    print(ToANSIString("未知的Hash算法"));
    os.exit(-1)
end

local mgfAlgo=getMGFAlgo(arg[4])
if mgfAlgo==nil then
    cert:Free()
    print(ToANSIString("未知的MGF算法"));
    os.exit(-1)
end

local label=arg[5]

local inFileName=arg[6]
local outFileName=arg[7]

local env=assert(CryptCore.NewEnvelopedData(true))
assert(env:SetEncAlgorithm(algo))
assert(env:AddCert(cert))

if not env:SetStringAttribute(9,string.format([[ {"label":"%s","hashAlgo":%d,"mgfAlgo":%d } ]],label,hashAlgo,mgfAlgo) )then
    cert:Free()
    env:Free()
    print(ToANSIString("设置OAEP算法参数失败"));
    os.exit(-1)
end

cert:Free()

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


