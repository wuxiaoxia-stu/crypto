local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s randBytes",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\trandBytes：产生的随机数的字节数"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t产生randBytes字节的随机数"))
end

local argCount=#arg
if argCount~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local randLength=tonumber(arg[1])
if randLength<0 then
    Usage(arg[0])
    os.exit(-1)
end

local deviceObj=nil

deviceObj=assert(CryptCore.NewDevice())

local data=assert(deviceObj:GenerateRandom(randLength))

deviceObj:Free()

print(CryptCore.HexEncode(data))

