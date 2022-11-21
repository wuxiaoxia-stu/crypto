local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s key count bearer direction unusedBits inFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tcount：计数器"))
    print(ToANSIString("\tbearer：承载层标识"))
    print(ToANSIString("\tdirection：传输方向标识"))
    print(ToANSIString("\tunusedBits：未使用位的个数"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行Mac运算"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行ZUC Mac运算"))
end

function NewZucMac(key,count,bearer,direction,unusedBits)
    return CryptCore.NewMac(CryptCore.Const.ZUC_MAC,key,
		{
			["count"]=count,	
			["bearer"]=bearer,	
			["direction"]=direction,
			["unusedBits"]=unusedBits,
		})
end

local argCount=#arg
if argCount~=6 then
    Usage(arg[0])
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[1])
if not key then
    print(ToANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local count=tonumber(arg[2])
local bearer=tonumber(arg[3])
local direction=tonumber(arg[4])
local unusedBits=tonumber(arg[5])

local fileName=arg[6]

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

macObj=assert(NewZucMac(key,count,bearer,direction,unusedBits))

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

