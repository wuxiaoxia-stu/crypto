local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s userKey1FileName userKey2FileName keyLen confirm keyFileName",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tuserKey1FileName：用户1密钥对文件名"))
    print(toANSIString("\tuserKey2FileName：用户2密钥对文件名"))
    print(toANSIString("\tkeyLen：要产生的密钥长度，字节数"))
    print(toANSIString("\tcomfirm：true表示要确认，false表示不用"))
    print(toANSIString("\tkeyFileName：产生的明文密钥的文件名"))
    print(toANSIString("说明"))
    print(toANSIString("\tSM9密钥交换"))
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


function getBooleanValue(str)
    str=str:upper()
    if str=="TRUE" then
        return true
    elseif str=="FALSE" then
        return false
    else
        return nil
    end
end

local argCount=#arg
if argCount~=5 then
    usage(arg[0])
    os.exit(-1)
end

local userKey1FileName=arg[1]
local userKey2FileName=arg[2]
local keyLen=tonumber(arg[3])
local confirm=getBooleanValue(arg[4])
if confirm==nil then
    usage(arg[0])
    os.exit(-1)
end
local keyFileName=arg[5]


local userkey1Data=getFileContent(userKey1FileName)
if userkey1Data==nil then
    print(toANSIString("读取用户1密钥对文件失败"))
    os.exit(-1)
end

local userkey2Data=getFileContent(userKey2FileName)
if userkey2Data==nil then
    print(toANSIString("读取用户2密钥对文件失败"))
    os.exit(-1)
end


local userKey1
local userKey2
local hashAlgo=CryptCore.Const.SM3

userKey1=CryptCore.ImportSM9UserKey(userkey1Data)
if userKey1==nil then
    print(toANSIString("错误的用户1密钥对"))
    os.exit(-1)
end

userKey2=CryptCore.ImportSM9UserKey(userkey2Data)
if userKey2==nil then
    userKey1:Free()
    print(toANSIString("错误的用户2密钥对"))
    os.exit(-1)
end

local masterKey1=assert(userKey1:GetMasterKey())

local id1=userKey1:GetId()
local id2=userKey2:GetId()

local ra,Ra=masterKey1:Sender_Keyexchange_Prepare(id2,hashAlgo)
masterKey1:Free()
if ra==nil then
    print(toANSIString("密钥交换第一步失败"))
    os.exit(-1)
end

print("ra:"..CryptCore.HexEncode(ra))
print("Ra:"..CryptCore.HexEncode(Ra))


local key2,Rb,Sa2,Sb2=userKey2:Receiver_Keyexchange(id1,hashAlgo,Ra,keyLen,confirm)
userKey2:Free()
if key2==nil then
    print(toANSIString("响应方密钥交换失败"))
    os.exit(-1)
end
print("Rb:"..CryptCore.HexEncode(Rb))
print("key2:"..CryptCore.HexEncode(key2))
if confirm then
    print("Sa2:"..CryptCore.HexEncode(Sa2))
    print("Sb2:"..CryptCore.HexEncode(Sb2))
end

local key1,Sa1,Sb1=userKey1:Sender_Keyexchange(id2,hashAlgo,ra,Ra,Rb,keyLen,confirm)
userKey1:Free()
if key1==nil then
    print(toANSIString("发起方密钥交换失败"))
    os.exit(-1)
end
print("key1:"..CryptCore.HexEncode(key1))
if confirm then
    print("Sa1:"..CryptCore.HexEncode(Sa1))
    print("Sb1:"..CryptCore.HexEncode(Sb1))
end

if key1~=key2 then
    print(toANSIString("发起方密钥交换的结果和响应方不同"))
    os.exit(-1)
end

if confirm then
    if Sa1~=Sa2 then
        print(toANSIString("发起方Sa的结果和响应方不同"))
        os.exit(-1)
    end
    
    if Sb1~=Sb2 then
        print(toANSIString("发起方Sb的结果和响应方不同"))
        os.exit(-1)
    end
end

if not Save(keyFileName,key1) then
    print(toANSIString("保存密钥失败"))
    os.exit(-1)
end

print(toANSIString("密钥交换成功"))

