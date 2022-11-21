local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s /e|/d key iv aad tLen inFileName outFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\t/e：表示加密"))
    print(ToANSIString("\t/d：表示解密"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tiv：Hex编码的IV值"))
    print(ToANSIString("\taad：附加的认证数据"))
    print(ToANSIString("\ttLen：Mac的字节数"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行AES GCM模式的加密或者解密运算，结果保存到outFileName文件中"))
end

function NewAesGcm(enc,key,iv,tLen,aad)
    return CryptCore.NewGCMCipher(enc,CryptCore.Const.AES_GCM,key,tLen,iv,aad)
end

local argCount=#arg
if argCount~=7 then
    Usage(arg[0])
    os.exit(-1)
end

local enc

if arg[1]=="/e" or arg[1]=="-e" then
    enc=true
elseif arg[1]=="/d" or arg[1]=="-d" then
    enc=false
else
    Usage(arg[0]);
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[2])
if not key then
    print(ToANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local keyBits=#key*8
if keyBits~=128 and keyBits~=192 and keyBits~=256 then
    print(ToANSIString("AES密钥必须是128、192或者256位的"));
    os.exit(-1)
end

local iv=CryptCore.HexDecode(arg[3])
if not iv then
    print(ToANSIString("Nonce不是Hex编码的"));
    os.exit(-1)
end


local aad=arg[4]

local tLen=tonumber(arg[5])
if tLen~=4 and tLen~=8 and tLen~=12 and tLen~=13 and tLen~=14 and tLen~=15 and tLen~=16 then
    print(ToANSIString("Mac长度必须是4、8、12、13、14、15、16字节的"));
    os.exit(-1)
end

local inFileName=arg[6]
local outFileName=arg[7]

local cipherObj
local fIn
local data


fIn=io.open(inFileName,"rb")
if fIn==nil then
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end
data=fIn:read("*a")
fIn:close()


cipherObj=assert(NewAesGcm(enc,key,iv,tLen,aad))
local outData=cipherObj:Cipher(data)
cipherObj:Free()
if outData==nil then
    if enc then
        print(ToANSIString("加密失败"))
    else
        print(ToANSIString("解密失败"))
    end
    os.exit(-1)
end

local fOut=io.open(outFileName,"wb")
if fOut==nil then
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

fOut:write(outData)
fOut:close()

if enc then
    print(ToANSIString("加密成功"))
else
    print(ToANSIString("解密成功"))
end

