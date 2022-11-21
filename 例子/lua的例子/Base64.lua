local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s /e|/d  inFileName outFileName [no_nl|strict]",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\t/e：表示编码"))
    print(ToANSIString("\t/d：表示解码"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行编码或者解码运算"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tno_nl：表示编码时，不用换行"))
    print(ToANSIString("\tstrict：表示解码时，不接受换行"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行Base64编码或者解码运算，结果保存到outFileName文件中"))
end

function GetBase64Flag(str)
    if str=="no_nl" then
        return 1
    elseif str=="strict" then
        return 2
    elseif str=="no_padding" then
        return 0x80
    elseif str=="no_nl_no_padding" then
        return 0x81
    elseif str=="strict_no_padding" then
        return 0x82
    else
        return nil
    end
end

local argCount=#arg
if argCount~=3 and argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local enc

if arg[1]=="/e" or arg[1]=="-e" then
    enc=true
elseif arg[1]=="/d" or arg[1]=="-d" then
    enc=false
else
    Usage(arg[0]);
    os.exit(-1)
end

local inFileName=arg[2]
local outFileName=arg[3]

local flag=0
if argCount==4 then
    flag=GetBase64Flag(arg[4])
    if flag==nil then
        Usage(arg[0]);
        os.exit(-1)
    end
end


local base64Obj
local fIn
local fOut
local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

base64Obj=assert(CryptCore.NewBase64(enc,flag))

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=base64Obj:Update(data)
    if outData==nil then
        if enc then
            print(ToANSIString("编码失败"))
        else
            print(ToANSIString("解码失败"))
        end
        base64Obj:Free()
        fIn:close()
        fOut:close()
        os.exit(-1)
    end
    fOut:write(outData)
end

fIn:close()

outData=base64Obj:Final()
base64Obj:Free()
if outData==nil then
    if enc then
        print(ToANSIString("编码失败"))
    else
        print(ToANSIString("解码失败"))
    end
    fOut:close()
    os.exit(-1)
end

fOut:write(outData)
fOut:close()

if enc then
    print(ToANSIString("编码成功"))
else
    print(ToANSIString("解码成功"))
end


