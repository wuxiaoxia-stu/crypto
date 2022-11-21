local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s hashAlgo salt iterCount id length pwd",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\thashAlgo：Hash算法，例如:SHA-1"))
    print(ToANSIString("\tsalt：Hex编码的salt值"))
    print(ToANSIString("\titerCount：迭代次数"))
    print(ToANSIString("\tid：ID"))
    print(ToANSIString("\tlengtht：产生的Key长度"))
    print(ToANSIString("\tpwd：密码"))
    print(ToANSIString("\tv1：表示使用PBKDF1"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行PKCS#12的KDF"))
end

function GetHashAlgo(hashAlgo)
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

local argCount=#arg
if argCount~=6 then
    Usage(arg[0])
    os.exit(-1)
end

local hashAlgo=GetHashAlgo(arg[1])
if hashAlgo==nil then
    Usage(arg[0])
    os.exit(-1)
end

local salt=CryptCore.HexDecode(arg[2])
if not salt then
    print(ToANSIString("salt不是Hex编码的"));
    os.exit(-1)
end

local iter=tonumber(arg[3])
local id=tonumber(arg[4])
local length=tonumber(arg[5])

local pwd=CryptCore.ACPToUTF8(arg[6])
if pwd==nil then
    print(ToANSIString("密码转换为UTF-8编码失败"));
    os.exit(-1)
end

local algo=CryptCore.Const.KDF_PKCS12
local flag=0
local key=CryptCore.KDF{
    ["algo"]=algo,
    ["data"]=pwd,
    ["length"]=length,
    ["hashalgo"]=hashAlgo,
    ["salt"]=salt,
    ["id"]=id,
    ["flag"]=flag,
    ["iter"]=iter
}
if key==nil then
	print(ToANSIString("KDF失败"));
	os.exit(-1)
end

print(CryptCore.HexEncode(key))

