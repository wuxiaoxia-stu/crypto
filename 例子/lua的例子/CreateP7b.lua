local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s p7bFileName [cert1FileName cert2FileName ...]",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tp7bFileName：P7b文件名"))
    print(ToANSIString("\tcert1FileName：证书文件名1"))
    print(ToANSIString("\tcert2FileName：证书文件名2"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t构造P7b"))
	os.exit(-1)
end

function GetCert(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return CryptCore.NewCert(inData)
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
if argCount<1 then
	Usage(arg[0])
    os.exit(-1)
end

local p7BFileName=arg[1]

local store=CryptCore.OpenStore(CryptCore.Const.CERTSTORE_TYPE_MEMORY)
if not store then
    
end

local certObj
for i=2,argCount do
    certObj=GetCert(arg[i])
    if certObj==nil then
        store:Close()
        print(ToANSIString(string.format("读证书文件(%s)失败",arg[i])));
        os.exit(-1)
    end
    
    assert(store:Add(certObj))
    certObj:Free()
end

local p7b=assert(store:ExportP7c())
store:Close()

if Save(p7BFileName,p7b)==false then
    print(ToANSIString("保存P7b文件失败"))
    os.exit(-1)
end

print(ToANSIString("产生P7b文件成功"))
