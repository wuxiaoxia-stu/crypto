local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s inFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tinFileName：MIME文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t在标准输出打印MIME文件内容"))
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

function PrintIndent(indent)
    if indent>0 then
        local str=string.rep(" ",indent)
        io.stdout:write(str)
    end
end 

function PrintMimeHeader(indent,mime)
    PrintIndent(indent)
    print("Header")
    
    local header=mime:GetHeader()
    
    for i,v in ipairs(header) do
        PrintIndent(indent)
        print(v["str"])
    end
end

function PrintBasicMime(indent,mime)
    PrintIndent(indent)
    print("Type:Basic\n")
    
    PrintMimeHeader(indent,mime)
    print("")
    
    PrintIndent(indent)
    print("Body")
    PrintIndent(indent)
    print(mime:GetBody())
    print("")
end

local PrintMime
function PrintMultiPart(indent,mime)
    PrintIndent(indent)
    print("Type:MultiPart\n")
    
    PrintMimeHeader(indent,mime)
    print("")
    
    local subMimes=mime:GetSubEntity()
    for i,subMime in ipairs(subMimes) do
        PrintIndent(indent)
        print(string.format("SubMime %d",i))
        
        PrintMime(indent+1,subMime)
        subMime:Free()
    end
    subMimes=nil
end

PrintMime=function (indent,mime)
    local type=mime:GetType()
    if type==0 then
        PrintBasicMime(indent,mime)
    elseif type==1 then
        PrintMultiPart(indent,mime)
    else
        PrintIndent(indent)
        print(string.format("Type:Unkown Type(%d)\n",type))
    end
end

local argCount=#arg
if argCount~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local inFileName=arg[1]

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

PrintMime(0,mime)
mime:Free()

