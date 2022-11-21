local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s attachmentFileName outFileName",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\tattachmentFileName：附件文件名"))
    print(ToANSIString("\toutFileName：输出的MIME文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对附件构造成MIME保存到outFileName文件中"))
end

function CreateCotentMime()
    local mime=assert(CryptCore.NewMime(0))
    assert(mime:AddHeader("Content-Type:text/plain;charset=\"gbk\""))
    assert(mime:AddHeader("Content-Transfer-Encoding: quoted-printable"))
    assert(mime:SetBody(CryptCore.QuotedPrintableEncode(CryptCore.UTF8ToACP("附件测试","gbk"))))
    return mime
end

function IsAscII(str)
    local num
    for i=1,#str do
        num=string.byte(str,i)
        if num<0 or num>127 then
            return false
        end
    end
    return true
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

local attachmentFileName=arg[1]
local outFileName=arg[2]

local mime=assert(CryptCore.NewMime(1))
local boundary=mime:GetBoundary()
assert(mime:AddHeader("Content-Type","multipart/mixed",{"boundary=\"" .. boundary .."\""}))

local contentMime=CreateCotentMime()
assert(mime:AddSubEntity(contentMime))
contentMime:Free()

local charset=nil
if not IsAscII(attachmentFileName) then
    charset="gbk"
end
local attachMime=CryptCore.NewAttachMime { 
        ["fileName"]=CryptCore.ACPToUTF8(attachmentFileName),
        ["charset"]=charset,
        }
if attachMime==nil then
    mime:Free()
    print(ToANSIString("创建附件失败"))
    os.exit(-1)
end

assert(mime:AddSubEntity(attachMime))
attachMime:Free()

local outData=mime:Encode()
mime:Free()

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("创建附件成功"));

