local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s enc|sign hid keypairFileName publickeyFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tenc：加密主密钥"))
    print(toANSIString("\tsign：签名主密钥"))
    print(toANSIString("\thid：一个字节的hid"))
    print(toANSIString("\tkeypairFileName：保存的密钥对文件名"))
    print(toANSIString("\tpublickeyFileName：保存的公钥文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\t产生SM9主密钥"))
end

function getKeypairType(name)
    name=name:upper()
    if name=="ENC" or name=="ENCRYPT" then
        return CryptCore.Const.KEYPAIRTYPE_ENCRYPT
    elseif name=="SIGN" or name=="SIGNATURE" then
        return CryptCore.Const.KEYPAIRTYPE_SIGNATURE
    elseif name=="KEYAGREEMENT" then
        return CryptCore.Const.KEYPAIRTYPE_KEYAGREEMENT
    else
        return tonumber(name)
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

local argCount=#arg
if argCount~=4 then
    usage(arg[0])
    os.exit(-1)
end


local type=getKeypairType(arg[1])
local hid=tonumber(arg[2])
local keypairFileName=arg[3]
local publickeyFileName=arg[4]

local key


key=CryptCore.GenerateSM9MasterKey(type,hid)
if key==nil then
    print(toANSIString("产生SM9主密钥失败"))
    os.exit(-1)
end

local keypairData=assert(key:ExportKeypair())
local publicKeyData=assert(key:ExportPublicKey())
key:Free()

if not Save(keypairFileName,keypairData) then
    print(toANSIString("保存密钥对失败"))
    os.exit(-1)
end

if not Save(publickeyFileName,publicKeyData) then
    print(toANSIString("保存公钥失败"))
    os.exit(-1)
end
print(toANSIString("产生SM9主密钥成功"))
