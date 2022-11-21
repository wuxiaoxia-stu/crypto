local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s fileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tfileName：SignedData文件"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t判断是否SignedData文件"))
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
local isSign,detached=CryptCore.IsSignedData(data)
if isSign then
    if detached then
        print(ToANSIString("可能是不带原文的SignedData文件"))
    else
        print(ToANSIString("可能是带原文的SignedData文件"))
    end
else
    print(ToANSIString("不是SignedData文件"))
end



