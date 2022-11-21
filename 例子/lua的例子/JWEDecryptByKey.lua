local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-compact] key jweFileName clearFileName [index]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-compact：使用JWE Compact Serialization，不存在则使用JWE JSON Serialization"))
    print(ToANSIString("\tkey：Hex编码的Key"))
    print(ToANSIString("\tjweFileName：JWE文件名"))
    print(ToANSIString("\tclearFileName：解密得到明文的文件名"))
    print(ToANSIString("\tindex：索引值从0算起，默认为0"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWE解密运算，得到的明文保存到clearFileName文件中"))
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



if #arg~=3 and #arg~=4 and #arg~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local type=2
if arg[pos]=="-compact" or arg[pos]=="/compact" then
    type=1
    pos=pos+1
end

local hexKey=arg[pos]
pos=pos+1

local key=CryptCore.HexDecode(hexKey)
if not key then
    print(ToANSIString("密钥不是Hex编码"));
    os.exit(-1)
end

local jweFileName=arg[pos]
pos=pos+1

local clearFileName=arg[pos]
pos=pos+1

local index=0

if pos==#arg then
    index=tonumber(arg[pos])
end

local jweData=GetFileConetent(jweFileName)
if jweData==nil then
    print(ToANSIString("读JWE文件失败"));
    os.exit(-1)
end


local jweObj=CryptCore.DecodeJWE(type,jweData)
if jweObj==nil then
    print(ToANSIString("错误的JWE格式"));
    os.exit(-1)
end

if not jweObj:SetKey(index,key) then
    jweObj:Free()
    print(ToANSIString("设置密钥失败"));
    os.exit(-1)
end

local clear=jweObj:Decrypt()
jweObj:Free()    
if clear==nil then
    print(ToANSIString("解密失败"));
    os.exit(-1)
end

if Save(clearFileName,clear)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("解密成功"));


