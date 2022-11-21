local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s aes128|sm4 sha256|sm3 saltLen iterCount pwd inFileName outFileName [q7]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\taes128|sm4：加密算法"))
    print(ToANSIString("\tsha256|sm3：Hash算法"))
	print(ToANSIString("\tsaltLen：盐值长度"))
	print(ToANSIString("\titerCount：迭代次数"))
	print(ToANSIString("\tpwd：口令"))
	print(ToANSIString("\tinFileName：明文文件名"))
	print(ToANSIString("\toutFileName：密文文件名"))
	print(ToANSIString("\tq7：可选，如果存在表示使用Q7格式"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t使用pwd加密inFileName得到EncrypedData格式的数据保存在outFileName中"))
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

function getEncAlgo(encAlgo)
    encAlgo=encAlgo:upper()
    if encAlgo== "AES-128" or encAlgo=="AES128" then
        return 2
    elseif  encAlgo== "AES-192" or encAlgo=="AES192" then
        return 3
    elseif  encAlgo== "AES-256" or encAlgo=="AES256" then
        return 4
    elseif encAlgo== "3DES" or encAlgo=="TDES" then
        return 1
    elseif encAlgo== "SM4" then
        return 5
    elseif encAlgo== "SM1" then
        return 6
    elseif encAlgo== "SSF33" then
        return 7
    else
        return nil;
    end
end

function save(outFileName,data)
	local fOut=assert(io.open(outFileName,"wb"))
	fOut:write(data)
	fOut:close()
end

if #arg~=7 and #arg~=8 then
    Usage(arg[0])
    os.exit(-1)
end

local encAlgo=getEncAlgo(arg[1])
if encAlgo==nil then
	print(ToANSIString("不支持的加密算法"))
	os.exit(-1)
end
local hashAlgo=getHashAlgo(arg[2])
if hashAlgo==nil then
	print(ToANSIString("不支持的Hash算法"))
	os.exit(-1)
end
local saltLen=tonumber(arg[3])
local iterCount=tonumber(arg[4])
local pwd=arg[5]
local inFileName=arg[6]
local outFileName=arg[7]
local flag=0
if #arg==8 then
	if arg[8]=="q7" then
		flag=1
	else
		Usage(arg[0])
		os.exit(-1)
	end
end

local clear=GetFileConetent(inFileName)
if clear==nil then
    print(ToANSIString("读明文文件失败"));
    os.exit(-1)
end

local encrypedData=CryptCore.EncryptedDataEncrypt(flag,encAlgo,hashAlgo,saltLen,iterCount,pwd,clear)
if encrypedData==nil then
	print(ToANSIString("加密失败"));
    os.exit(-1)
end
save(outFileName,encrypedData)
print(ToANSIString("加密成功"));


