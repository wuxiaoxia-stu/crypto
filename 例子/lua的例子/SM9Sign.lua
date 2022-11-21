local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s userKeypairFileName tbsFileName signatureFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tuserKeypairFileName：用户密钥对文件名"))
    print(toANSIString("\ttbsFileName：要签名的文件名"))
    print(toANSIString("\tsignatureFileName：签名值文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\tSM9签名"))
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


local userKeypairFileName=arg[1]
local tbsFileName=arg[2]
local signFileName=arg[3]


local userKeyData=getFileContent(userKeypairFileName)
if userKeyData==nil then
    print(toANSIString("读取用户密钥对文件失败"))
    os.exit(-1)
end

local tbsData=getFileContent(tbsFileName)
if tbsData==nil then
    print(toANSIString("读取要签名的文件失败"))
    os.exit(-1)
end

local userKey
local hashAlgo=CryptCore.Const.SM3

userKey=CryptCore.ImportSM9UserKey(userKeyData)
if userKey==nil then
    print(toANSIString("错误的SM9主密钥"))
    os.exit(-1)
end

local sign

sign=userKey:Sign(hashAlgo,tbsData)
if sign==nil then
    print(toANSIString("签名失败"))
    os.exit(-1)
end

userKey:Free()

if not Save(signFileName,sign) then
    print(toANSIString("保存签名失败"))
    os.exit(-1)
end

print(toANSIString("SM9签名成功"))

