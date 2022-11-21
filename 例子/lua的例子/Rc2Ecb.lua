local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s /e|/d key effectiveBits inFileName outFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\t/e：表示加密"))
    print(ToANSIString("\t/d：表示解密"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\teffectiveBits：有效密钥位数"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行RC2 ECB模式的加密或者解密运算，结果保存到outFileName文件中"))
end

function NewRc2Ecb(enc,key,bits)
    return CryptCore.NewCipher{
            ["algo"]=CryptCore.Const.RC2_ECB,
            ["enc"]=enc,
            ["key"]=key,
            ["padding"]=CryptCore.Const.PADDING_PKCS7,
            ["effectivebits"]=bits}
end

local argCount=#arg
if argCount~=5 then
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

local effectiveBits=tonumber(arg[3])
if effectiveBits<=0 then
    Usage(arg[0]);
    os.exit(-1)
end


local inFileName=arg[4]
local outFileName=arg[5]

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

cipherObj=assert(NewRc2Ecb(enc,key,effectiveBits))

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

