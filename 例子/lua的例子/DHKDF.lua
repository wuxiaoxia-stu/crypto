local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s hashAlgo kekoid length pwd [partyaInfo]",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\thashAlgo：Hash算法，例如:SHA-1"))
    print(ToANSIString("\tkekoid：kek算法的oid"))
    print(ToANSIString("\tlengtht：产生的Key长度"))
    print(ToANSIString("\tpwd：Hex编码的密码"))
    print(ToANSIString("\tpartyaInfo：Hex编码的partyaInfo"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行DH的KDF"))
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
if argCount~=5 and argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local hashAlgo=GetHashAlgo(arg[1])
if hashAlgo==nil then
    Usage(arg[0])
    os.exit(-1)
end

local kekOid=arg[2]
local length=tonumber(arg[3])

local pwd=CryptCore.HexDecode(arg[4])
if not pwd then
    print(ToANSIString("密码不是Hex编码的"));
    os.exit(-1)
end

local partyaInfo=nil
if argCount==5 then
    partyaInfo=CryptCore.HexDecode(arg[5])
    if partyaInfo==nil then
        print(ToANSIString("partyaInfo不是Hex编码的"));
        os.exit(-1)
    end
end

local algo=CryptCore.Const.KDF_DH_RFC2631

local key=CryptCore.KDF{
    ["algo"]=algo,
    ["data"]=pwd,
    ["length"]=length,
    ["hashalgo"]=hashAlgo,
    ["kekoid"]=kekOid,
    ["partyainfo"]=partyaInfo
}
if key==nil then
	print(ToANSIString("KDF失败"));
	os.exit(-1)
end

print(CryptCore.HexEncode(key))

