local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tinFileName：数字信封的文件名"))
    print(ToANSIString("\toutFileName：数字信封的RecipientInfos的编码文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t获取数字信封的RecipientInfos的编码"))
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

local argCount=#arg
if argCount~=2 then
    Usage(arg[0])
    os.exit(-1)
end


local inFileName=arg[1]
local outFileName=arg[2]


local env=assert(CryptCore.NewEnvelopedData(false))
env:DontDecrypt()

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    env:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

assert(env:DecryptInit())

local recipientInfosEncode
local errCode
while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        env:Free()
        fIn:close()
        print(ToANSIString("不是数字信封"))
        os.exit(-1)
    end

    outData=env:DecryptUpdate(data)
    if outData==nil then
        env:Free()
        fIn:close()
        print(ToANSIString("不是数字信封"))
        os.exit(-1)
    end
    
    recipientInfosEncode,errCode=env:GetRecipientInfosEncode()
    if recipientInfosEncode then
        break
    end
    
    if errCode==false then
        env:Free()
        fIn:close()
        print(ToANSIString("不是数字信封"))
        os.exit(-1)
    end
end

fIn:close()
env:Free()

if not Save(outFileName,recipientInfosEncode) then
    print(ToANSIString("保存文件失败"))
else
    print(ToANSIString("成功"))
end
