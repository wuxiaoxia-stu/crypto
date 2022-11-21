local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s hashAlgo length pwd [sharedInfo]",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\thashAlgo：Hash算法，例如:SHA-1"))
    print(ToANSIString("\tlengtht：产生的Key长度"))
    print(ToANSIString("\tpwd：Hex编码的密码"))
    print(ToANSIString("\tsharedInfo：Hex编码的sharedInfo"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行ECC ANSI X9.63的KDF"))
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
if argCount~=3 and argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local hashAlgo=GetHashAlgo(arg[1])
if hashAlgo==nil then
    Usage(arg[0])
    os.exit(-1)
end

local length=tonumber(arg[2])

local pwd=CryptCore.HexDecode(arg[3])
if not pwd then
    print(ToANSIString("密码不是Hex编码的"));
    os.exit(-1)
end

local sharedInfo=nil
if argCount==4 then
    sharedInfo=CryptCore.HexDecode(arg[4])
    if sharedInfo==nil then
        print(ToANSIString("sharedInfo不是Hex编码的"));
        os.exit(-1)
    end
end

local algo=CryptCore.Const.KDF_ECC_ANSI_X9_63

local key=CryptCore.KDF{
    ["algo"]=algo,
    ["data"]=pwd,
    ["length"]=length,
    ["hashalgo"]=hashAlgo,
    ["sharedinfo"]=sharedInfo
}
if key==nil then
	print(ToANSIString("KDF失败"));
	os.exit(-1)
end

print(CryptCore.HexEncode(key))

