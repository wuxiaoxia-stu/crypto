local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s /e|/d key count bearer direction inFileName outFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\t/e：表示加密"))
    print(ToANSIString("\t/d：表示解密"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tcount：计数器"))
    print(ToANSIString("\tbearer：承载层标识"))
    print(ToANSIString("\tdirection：传输方向标识"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行ZUC的加密或者解密运算，结果保存到outFileName文件中"))
end

function NewZuc(enc,key,count,bearer,direction)
    return CryptCore.NewCipher { 
        algo=CryptCore.Const["ZUC"],
        ["enc"]=enc,
        ["key"]=key,
        ["count"]=count,
        ["bearer"]=bearer,
        ["direction"]=direction}
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

local count=tonumber(arg[3])
local bearer=tonumber(arg[4])
local direction=tonumber(arg[5])

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


cipherObj=assert(NewZuc(enc,key,count,bearer,direction))
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
