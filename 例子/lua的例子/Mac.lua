local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s macAlgo key inFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\tmacAlgo：Mac算法，比如:HMAC-SHA-1、HMAC-SM3之类"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行Mac运算"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行Mac运算，Mac算法使用macAlgo"))
end

function getMacAlgo(macAlgo)
    macAlgo=macAlgo:upper()
    if macAlgo== "HMAC-SHA-1" or macAlgo=="HMAC-SHA1" then
        return CryptCore.Const["HMAC-SHA-1"]
    elseif  macAlgo== "HMAC-SM3" then
        return CryptCore.Const["HMAC-SM3"]
    elseif  macAlgo== "HMAC-MD5" then
        return CryptCore.Const["HMAC-MD5"]
    elseif macAlgo== "HMAC-SHA-224" or macAlgo=="HMAC-SHA224" then
        return CryptCore.Const["HMAC-SHA-224"]
    elseif macAlgo== "HMAC-SHA-256" or macAlgo=="HMAC-SHA256" then
        return CryptCore.Const["HMAC-SHA-256"]
    elseif macAlgo== "HMAC-SHA-384" or macAlgo=="HMAC-SHA384" then
        return CryptCore.Const["HMAC-SHA-384"]
    elseif macAlgo== "HMAC-SHA-512" or macAlgo=="HMAC-SHA512" then
        return CryptCore.Const["HMAC-SHA-512"]
    elseif macAlgo== "HMAC-SHA-512/224" then
        return CryptCore.Const["HMAC-SHA-512/224"]
    elseif macAlgo== "HMAC-SHA-512/256" then
        return CryptCore.Const["HMAC-SHA-512/256"]
    elseif macAlgo== "HMAC-SHA3-224" then
        return CryptCore.Const["HMAC-SHA3-224"]
    elseif macAlgo== "HMAC-SHA3-256" then
        return CryptCore.Const["HMAC-SHA3-256"]
    elseif macAlgo== "HMAC-SHA3-384" then
        return CryptCore.Const["HMAC-SHA3-384"]
    elseif macAlgo== "HMAC-SHA3-512" then
        return CryptCore.Const["HMAC-SHA3-512"]
    elseif macAlgo== "AES-CMAC" then
        return CryptCore.Const["AES-CMAC"]
    elseif macAlgo== "3DES-CMAC" or hashAlgo=="TDES-CMAC" then
        return CryptCore.Const["TDES-CMAC"]
    elseif macAlgo== "SM4-CMAC" then
        return CryptCore.Const["SM4-CMAC"]
    else
        return nil;
    end
end

function NewMac(macAlgo,key)
    return CryptCore.NewMac(macAlgo,key)
end

local argCount=#arg
if argCount~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local macAlgo=getMacAlgo(arg[1])
if not macAlgo then
    print(ToANSIString("未知Mac算法"));
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[2])
if not key then
    print(ToANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local fileName=arg[3]

local macObj
local fIn
local data
local BLOCK_LEN=8192
local macValue

fIn=io.open(fileName,"rb")
if fIn==nil then
	print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(fileName))));
	os.exit(-1)
end

macObj=assert(NewMac(macAlgo,key))

while (true) do
 
	data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    macObj:Update(data)
end

fIn:close()

macValue=macObj:Final()
macObj:Free()

print(ToANSIString(CryptCore.HexEncode(macValue)))

