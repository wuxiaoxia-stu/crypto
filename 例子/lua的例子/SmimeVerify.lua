local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tinFileName：要进行验证的S/MIME文件名"))
    print(ToANSIString("\toutFileName：解码得到的原文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行S/MIME进行验证运算，原文保存到outFileName文件中"))
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


local data=GetFileConetent(inFileName)
if data==nil then
    print(ToANSIString(string.format("读文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

local mime=CryptCore.NewMime(data)
if mime==nil then
    print(ToANSIString(string.format("文件(%s)不是MIME文件",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

if not mime:IsSign() then
    mime:Free()
    print(ToANSIString(string.format("文件(%s)不是签名的S/MIME文件",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end


local outData=mime:Verify()

mime:Free()
if outData==nil then
    print(ToANSIString("验证失败"))
    os.exit(-1)
end

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("验证成功"))
