local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s hashAlgo inFileName1 [... inFileNamen]",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(ToANSIString("\tinFileName1：第一个文件名，其内容要进行Hash运算"))
	print(ToANSIString("\tinFileNamen：第n个文件名，其内容要进行Hash运算"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对文件inFileName1到文件inFileNamen进行Hash运算，Hash算法使用hashAlgo"))
end

function getHashAlgo(hashAlgo)
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


function hashUpdate(hashObj,fileObj)
	local data
	local BLOCK_LEN=8192
	while (true) do
 		data=fileObj:read(BLOCK_LEN)
		if not data then
			break
		end

		hashObj:Update(data)
	end
end

function NewHash(hashAlgo)
    return CryptCore.NewHash(hashAlgo)
end

local argCount=#arg
if argCount<2 then
    Usage(arg[0])
    os.exit(-1)
end

local hashAlgo=getHashAlgo(arg[1])
if not hashAlgo then
    print(ToANSIString("未知Hash算法"));
    os.exit(-1)
end


local hashValue

hashObj=assert(NewHash(hashAlgo))
for i=2,argCount do
	fileName=arg[i]
	fIn=io.open(fileName,"rb")
	if fIn==nil then
		hashObj:Free()
		print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(fileName))));
		os.exit(-1)
	end
	hashUpdate(hashObj,fIn)
	fIn:close()
end

hashValue=hashObj:Final()
hashObj:Free()

print(ToANSIString(CryptCore.HexEncode(hashValue)))
