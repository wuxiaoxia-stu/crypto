local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s userKeyFileName keyLen encKeyFileName keyFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tuserKeyFileName：用户密钥对文件名"))
    print(toANSIString("\tkeyLen：要产生的密钥长度，字节数"))
    print(toANSIString("\tencKeyFileName：密文的密钥文件名"))
    print(toANSIString("\tkeyFileName：产生的明文密钥的文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\tSM9解密会话密码"))
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
if argCount~=4 then
    usage(arg[0])
    os.exit(-1)
end

local userKeyFileName=arg[1]
local keyLen=tonumber(arg[2])
local keyFileName=arg[4]
local encFileName=arg[3]


local userkeyData=getFileContent(userKeyFileName)
if userkeyData==nil then
    print(toANSIString("读取用户密钥对文件失败"))
    os.exit(-1)
end

local encKey=getFileContent(encFileName)
if encKey==nil then
    print(toANSIString("读取加密的会话密钥文件失败"))
    os.exit(-1)
end

local userKey
local hashAlgo=CryptCore.Const.SM3

userKey=CryptCore.ImportSM9UserKey(userkeyData)
if userKey==nil then
    print(toANSIString("错误的用户密钥对"))
    os.exit(-1)
end

local key

key=userKey:DecryptKey(hashAlgo,encKey,keyLen)
if key==nil then
    userKey:Free()
    print(toANSIString("解密会话密钥失败"))
    os.exit(-1)
end

userKey:Free()

if not Save(keyFileName,key) then
    print(toANSIString("保存明文密钥失败"))
    os.exit(-1)
end

print(toANSIString("解密会话密钥成功"))


