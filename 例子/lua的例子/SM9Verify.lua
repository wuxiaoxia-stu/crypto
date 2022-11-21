local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s id masterPublicKeyFileName tbsFileName signatureFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tid：标识"))
    print(toANSIString("\tmasterPublicKeyFileName：主公钥文件名"))
    print(toANSIString("\ttbsFileName：要签名的文件名"))
    print(toANSIString("\tsignatureFileName：签名值文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\t验证SM9签名"))
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

local id=arg[1]
local masterPublicKeyFileName=arg[2]
local tbsFileName=arg[3]
local signFileName=arg[4]


local masterPublickeyData=getFileContent(masterPublicKeyFileName)
if masterPublickeyData==nil then
    print(toANSIString("读取主公钥文件失败"))
    os.exit(-1)
end

local tbsData=getFileContent(tbsFileName)
if tbsData==nil then
    print(toANSIString("读取要签名的文件失败"))
    os.exit(-1)
end

local sign=getFileContent(signFileName)
if sign==nil then
    print(toANSIString("读取签名值的文件失败"))
    os.exit(-1)
end

local masterKey
local hashAlgo=CryptCore.Const.SM3

masterKey=CryptCore.ImportSM9MasterPublicKey(masterPublickeyData)
if masterKey==nil then
    print(toANSIString("错误的SM9主公钥"))
    os.exit(-1)
end

if not masterKey:Verify(id,hashAlgo,tbsData,sign) then
    masterKey:Free()
    print(toANSIString("验证SM9签名失败"))
    os.exit(-1)
end

masterKey:Free()
print(toANSIString("验证SM9签名成功"))


