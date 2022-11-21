local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s id masterKeypairFileName userKeypairFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tid：标识"))
    print(toANSIString("\tmasterKeypairFileName：主密钥对文件名"))
    print(toANSIString("\tuserKeypairFileName：保存的用户密钥对文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\t产生SM9用户密钥"))
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
if argCount~=3 then
    usage(arg[0])
    os.exit(-1)
end


local id=arg[1]
local masterKeypairFileName=arg[2]
local userKeypairFileName=arg[3]


local masterKeyData=getFileContent(masterKeypairFileName)
if masterKeyData==nil then
    print(toANSIString("读取主密钥对文件失败"))
    os.exit(-1)
end

local masterKey
local hashAlgo=CryptCore.Const.SM3
masterKey=CryptCore.ImportSM9MasterKeypair(masterKeyData)
if masterKey==nil then
    print(toANSIString("错误的SM9主密钥"))
    os.exit(-1)
end

local userKey
userKey=masterKey:GenerateUserKey(hashAlgo,id)
if userKey==nil then
    print(toANSIString("产生SM9用户密钥失败"))
    os.exit(-1)
end

local userKeypairData=assert(userKey:Export())
userKey:Free()
masterKey:Free()

if not Save(userKeypairFileName,userKeypairData) then
    print(toANSIString("保存用户密钥对失败"))
    os.exit(-1)
end

print(toANSIString("产生SM9用户密钥成功"))

