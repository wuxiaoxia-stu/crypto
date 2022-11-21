local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s oldSealFileName tsaUrl hashAlgo newSealFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\toldSealFileName：电子签章的文件名"))
    print(ToANSIString("\ttsaUrl：时间戳URL"))
    print(ToANSIString("\thashAlgo：时间戳使用的Hash算法"))
    print(ToANSIString("\tnewSealFileName：追加时间戳后的电子签章"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t电子签章追加时间戳"))
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

function GetHashAlgo(algo)
    if algo==nil then
        return nil
    end
    algo=algo:upper()
    if algo== "SHA1" or algo=="SHA-1" or algo=="1.3.14.3.2.26" then
        return CryptCore.Const.SHA1
    elseif  algo== "SHA224" or algo=="SHA-224" or algo=="2.16.840.1.101.3.4.2.4" then
        return CryptCore.Const.SHA224
    elseif  algo== "SHA256" or algo=="SHA-256" or algo=="2.16.840.1.101.3.4.2.1" then
        return CryptCore.Const.SHA256
    elseif  algo== "SHA384" or algo=="SHA-384" or algo=="2.16.840.1.101.3.4.2.2" then
        return CryptCore.Const.SHA384
    elseif  algo== "SHA512" or algo=="SHA-512" or algo=="2.16.840.1.101.3.4.2.3" then
        return CryptCore.Const.SHA512
    elseif  algo== "MD5" or algo=="1.2.840.113549.2.5" then
        return CryptCore.Const.MD5
    elseif  algo== "SHA512/224" or algo== "SHA-512/224" or algo=="2.16.840.1.101.3.4.2.5" then
        return CryptCore.Const["SHA-512/224"]
    elseif  algo== "SHA512/256" or algo== "SHA-512/256" or algo=="2.16.840.1.101.3.4.2.6" then
        return CryptCore.Const["SHA-512/256"]
    elseif  algo== "SHA3-224" or algo=="2.16.840.1.101.3.4.2.7" then
        return CryptCore.Const["SHA3-224"]
    elseif  algo== "SHA3-256" or algo=="2.16.840.1.101.3.4.2.8" then
        return CryptCore.Const["SHA3-256"]
    elseif  algo== "SHA3-384" or algo=="2.16.840.1.101.3.4.2.9" then
        return CryptCore.Const["SHA3-384"]
    elseif  algo== "SHA3-512" or algo=="2.16.840.1.101.3.4.2.10" then
        return CryptCore.Const["SHA3-512"]
    elseif  algo== "SM3" or algo=="1.2.156.10197.1.401" then
        return CryptCore.Const.SM3
    else
        return nil;
    end
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

if #arg~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local oldSealFileName=arg[1]
local url=arg[2]
local hashAlgoStr=arg[3]
local newSealFileName=arg[4]
local sealEncode=GetFileConetent(oldSealFileName)
if sealEncode==nil then
    print(ToANSIString("读电子签章文件失败"));
    os.exit(-1)
end

local seal=CryptCore.NewSeal(sealEncode)
if seal==nil then
    print(ToANSIString("不是电子签章文件"));
    os.exit(-1)
end

local format=seal:GetFormat()
if format~=CryptCore.Const["GB/T 38540"] then
    print(ToANSIString("不是符合GB/T 38540的电子签章"))
    seal:Free()
    os.exit(-1)
end

if not seal:Verify() then
    print(ToANSIString("验证电子签章失败"));
    seal:Free()
    os.exit(-1)
end

local hashAlgo=GetHashAlgo(hashAlgoStr)
if hashAlgo==nil then
    print(ToANSIString("不支持的Hash算法"));
    seal:Free()
    os.exit(-1)
end
sealEncode=seal:AttachTimeStamp(hashAlgo,url)
seal:Free()
if sealEncode==nil then
    print(ToANSIString("追加时间戳失败"));
    os.exit(-1)
end
if not Save(newSealFileName,sealEncode) then
    print(ToANSIString("保存电子签章失败"));
    os.exit(-1)
end
print(ToANSIString("追加时间戳成功"));
