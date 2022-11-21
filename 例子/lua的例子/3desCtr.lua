﻿local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s /e|/d key iv bits inFileName outFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\t/e：表示加密"))
    print(ToANSIString("\t/d：表示解密"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tiv：Hex编码的IV值"))
    print(ToANSIString("\tbits：CTR使用的IV位数，也就是计数器位数"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行3DES CTR模式的加密或者解密运算，结果保存到outFileName文件中"))
end

function New3desCtr(enc,key,iv,bits)
    return CryptCore.NewCTRCipher(enc,CryptCore.Const.TDES_CTR,key,iv,bits)
end

local argCount=#arg
if argCount~=6 then
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
if keyBits~=128 and keyBits~=192 then
    print(ToANSIString("3DES密钥必须是128或者192位的"));
    os.exit(-1)
end

local iv=CryptCore.HexDecode(arg[3])
if not iv then
    print(ToANSIString("IV不是Hex编码的"));
    os.exit(-1)
end

if #iv~=8 then
    print(ToANSIString("IV必须是8字节的"));
    os.exit(-1)
end

local countBits=tonumber(arg[4])
if countBits<=0 then
    Usage(arg[0]);
    os.exit(-1)
end

if countBits>64 then
    print(ToANSIString("计数器位数必须不大于64"));
    os.exit(-1)
end

local inFileName=arg[5]
local outFileName=arg[6]

local cipherObj
local fIn
local fOut
local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

cipherObj=assert(New3desCtr(enc,key,iv,countBits))

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=cipherObj:Update(data)
    fOut:write(outData)
end

fIn:close()

outData=cipherObj:Final()
cipherObj:Free()
if outData==nil then
    if enc then
        print(ToANSIString("加密失败"))
    else
        print(ToANSIString("解密失败"))
    end
    fOut:close()
    os.exit(-1)
end

fOut:write(outData)
fOut:close()

if enc then
    print(ToANSIString("加密成功"))
else
    print(ToANSIString("解密成功"))
end

