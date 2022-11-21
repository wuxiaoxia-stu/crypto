local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s key iv tlen inFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tiv：Hex编码的IV值"))
    print(ToANSIString("\ttlen：Mac的长度"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行Mac运算"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行AES-GMAC Mac运算"))
end

function NewAesGmac(key,iv,tlen)
    return CryptCore.NewMac(CryptCore.Const["AES-GMAC"],key,
		{
			["tlen"]=tlen,	
			["iv"]=iv,	
		})
end

local argCount=#arg
if argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[1])
if not key then
    print(ToANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local iv=CryptCore.HexDecode(arg[2])
if not iv then
    print(ToANSIString("IV不是Hex编码的"));
    os.exit(-1)
end

if #iv==0 then
    print(ToANSIString("IV不能是空串"));
    os.exit(-1)
end

local tlen=tonumber(arg[3])
if tlen~=16 and tlen~=15 and tlen~=14 and tlen~=13
    and tlen~=12 and tlen~=8 and tlen~=4 then
    print(ToANSIString("MAC的长度必须是4、8、12、13、14、15或16字节"));
    os.exit(-1)
end

local fileName=arg[4]

local macObj
local fIn
local data
local BLOCK_LEN=8192
local macValue

fIn=io.open(fileName,"rb")
if fIn==nil then
	print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(fileName))));
	os.exit(-1)
end

macObj=assert(NewAesGmac(key,iv,tlen))

while (true) do
 
	data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    macObj:Update(data)
end

fIn:close()

macValue=macObj:Final()
macObj:Free()

print(ToANSIString(CryptCore.HexEncode(macValue)))

