local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName hashAlgo mgfAlgo saltLen inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：签名证书文件"))
    print(ToANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(ToANSIString("\tmgfAlgo：MGF算法，比如:MGF1_SHA-1、MGF1_SHA256之类"))
    print(ToANSIString("\tsaltLen：盐的长度"))
    print(ToANSIString("\tinFileName：要进行签名的原文文件名"))
    print(ToANSIString("\toutFileName：签名得到的签名文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行带原文的SignedData签名运算，结果保存到outFileName文件中"))
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

function checkPssParam(pssParam,hashAlgo,mgfAlgo,saltLen)
    local json=CryptCore.Json.Decode(pssParam)
    if json==nil then
        return false
    end
    if json.hashAlgo~=hashAlgo then
        return false
    end
    
    if json.mgfAlgo~=mgfAlgo then
        return false
    end
    
    local pssSaltLen=json.saltLen
    if pssSaltLen==nil or type(pssSaltLen)~="number" or pssSaltLen>saltLen then
        return false
    end
    
    return true
end



local argCount=#arg
if argCount~=6 then
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

local saltLen=tonumber(arg[4])

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

if cert:Match("CertType='Signature'")==false then
    cert:Free()
    print(ToANSIString("不是签名证书"));
    os.exit(-1)
end

local algo=CryptCore.Const.RSA_PSS

local publicAlgo=cert:GetPublicKeyAlgorithm()
if publicAlgo==CryptCore.Const.RSA_ONLY_PSS then
    local pssParam=cert:GetAttribute(107)
    if pssParam==nil then
        if CryptCore.GetLastError()~=-7 then
            cert:Free()
            print(ToANSIString("获取证书的PSS参数失败"));
            os.exit(-1)
        end
    elseif checkPssParam(pssParam,hashAlgo,mgfAlgo,saltLen)==false then
        cert:Free()
        print(ToANSIString("验证PSS参数失败"));
        os.exit(-1)
    end
elseif publicAlgo~=CryptCore.Const.RSA then
    cert:Free()
    print(ToANSIString("不是RSA证书"));
    os.exit(-1)
end

local inFileName=arg[5]
local outFileName=arg[6]

local sign=assert(CryptCore.NewSignedData(true))
assert(sign:SetSignCert(cert))
cert:Free()

assert(sign:SetDetached(false))

assert(sign:SetStringAttribute(71,0,string.format([[{"hashAlgo":%d,"mgfAlgo":%d,"saltLen":%d}]],hashAlgo,mgfAlgo,saltLen)))
assert(sign:SetSignAlgorithm(algo,0))

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    sign:Free()
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

outData=sign:SignInit()
if not outData then
    sign:Free()
    fIn:close()
    fOut:close()
    print(ToANSIString("签名失败"))
    os.exit(-1)
end

fOut:write(outData)

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=sign:SignUpdate(data)
    if not outData then
        sign:Free()
        fIn:close()
        fOut:close()
        print(ToANSIString("签名失败"))
        os.exit(-1)
    end
    fOut:write(outData)
end

fIn:close()

outData=sign:SignFinal()
sign:Free()

if not outData then
    fOut:close()
    print(ToANSIString("签名失败"))
    os.exit(-1)
end

fOut:write(outData)
fOut:close()
print(ToANSIString("签名成功"))


