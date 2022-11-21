local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s id masterPublicKeyFileName keyLen keyFileName encKeyFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tid：对方标识"))
    print(toANSIString("\tmasterPublicKeyFileName：主公钥文件名"))
    print(toANSIString("\tkeyLen：要产生的密钥长度，字节数"))
    print(toANSIString("\tkeyFileName：产生的明文密钥的文件名"))
    print(toANSIString("\tencKeyFileName：密文的密钥文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\tSM9产生会话密码"))
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

function getFileContent(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return inData
end

local argCount=#arg
if argCount~=5 then
    usage(arg[0])
    os.exit(-1)
end

local id=arg[1]
local masterPublicKeyFileName=arg[2]
local keyLen=tonumber(arg[3])
local keyFileName=arg[4]
local encFileName=arg[5]


local masterPublickeyData=getFileContent(masterPublicKeyFileName)
if masterPublickeyData==nil then
    print(toANSIString("读取主公钥文件失败"))
    os.exit(-1)
end

local masterKey
local hashAlgo=CryptCore.Const.SM3

masterKey=CryptCore.ImportSM9MasterPublicKey(masterPublickeyData)
if masterKey==nil then
    print(toANSIString("错误的SM9主公钥"))
    os.exit(-1)
end

local key
local encKey

key,encKey=masterKey:GenerateKey(id,hashAlgo,keyLen)
if key==nil then
    masterKey:Free()
    print(toANSIString("产生会话密钥失败"))
    os.exit(-1)
end

masterKey:Free()

if not Save(keyFileName,key) then
    print(toANSIString("保存明文密钥失败"))
    os.exit(-1)
end

if not Save(encFileName,encKey) then
    print(toANSIString("保存密文密钥失败"))
    os.exit(-1)
end

print(toANSIString("产生会话密钥成功"))


