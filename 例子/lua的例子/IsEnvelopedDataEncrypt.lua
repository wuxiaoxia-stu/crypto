local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s fileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tfileName：数字信封文件"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t判断是否数字信封文件"))
end

local argCount=#arg
if argCount~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local fileName=arg[1]
local fIn=io.open(fileName,"rb")
if fIn==nil then
    print(ToANSIString("打开文件失败"));
    os.exit(-1)
end

local len=8192
local data=fIn:read(len)
fIn:close()
if CryptCore.IsEnvelopedData(data) then
    print(ToANSIString("可能是数字信封文件"))
else
    print(ToANSIString("不是数字信封文件"))
end



