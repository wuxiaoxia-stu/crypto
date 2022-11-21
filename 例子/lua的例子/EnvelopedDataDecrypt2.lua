local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tinFileName：要进行解密的文件名"))
    print(ToANSIString("\toutFileName：解密得到的明文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行数字信封解密运算，结果保存到outFileName文件中"))
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

local argCount=#arg
if argCount~=2 then
    Usage(arg[0])
    os.exit(-1)
end


local inFileName=arg[1]
local outFileName=arg[2]


local inData=GetFileConetent(inFileName)
if inData==nil then
    print(ToANSIString(string.format("读文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local env=assert(CryptCore.NewEnvelopedData(false))

local outData=env:Decrypt(inData)
if outData==nil then
    env:Free()
    print(ToANSIString("解密失败"))
    os.exit(-1)
end

if Save(outFileName,outData)==false then
    env:Free()
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("解密成功"))
print(ToANSIString(string.format("对称加密算法:%s",GetEncAlgoName(env:GetEncAlgorithm()))))
print(ToANSIString(string.format("解密证书的主体:%s",env:GetCert():GetSubject())))
env:Free()

