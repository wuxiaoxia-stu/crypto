local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s key inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tkey：Hex编码的对称密钥"))
    print(ToANSIString("\tinFileName：要进行解密的文件名"))
    print(ToANSIString("\toutFileName：解密得到的明文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t直接输入对称密钥对数字信封进行解密"))
end

function GetEncAlgoName(algo)
    if algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES128CBC then
        return "AES-128"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES192CBC then
        return "AES-192"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES256CBC then
        return "AES-256"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_DESCBC then
        return "DES"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_TDESCBC then
        return "3DES"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_RC2CBC then
        return "RC2"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SSF33CBC then
        return "SSF33"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM1CBC then
        return "SM1"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM4CBC then
        return "SM4"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_RC4 then
        return "RC4"
    else
        return string.format("unknwon algo(%d)",algo)
    end
end

local argCount=#arg
if argCount~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[1])
if key==nil then
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end
local inFileName=arg[2]
local outFileName=arg[3]


local env=assert(CryptCore.NewEnvelopedData(false))
assert(env:SetKey(key))
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

assert(env:DecryptInit())

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=env:DecryptUpdate(data)
    if outData==nil then
        env:Free()
        fIn:close()
        fOut:close()
        print(ToANSIString("解密失败"))
        os.exit(-1)
    end
    fOut:write(outData)
end

fIn:close()
fOut:close()
outData=env:DecryptFinal(data)

if outData==false then
    env:Free()
    print(ToANSIString("解密失败"))
    os.exit(-1)
end

print(ToANSIString("解密成功"))
print(ToANSIString(string.format("对称加密算法:%s",GetEncAlgoName(env:GetEncAlgorithm()))))
env:Free()

