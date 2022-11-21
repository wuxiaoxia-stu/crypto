local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s cert expr",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\texpr：条件表达式"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t判断证书是否符合某个条件"))
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

if #arg~=2 then
	Usage(arg[0])
    os.exit(-1)
end

local cert=GetCert(arg[1])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end
local expr=arg[2]

local rv,msg=cert:Match(expr)
cert:Free()

if rv==true then
    print(ToANSIString("证书符合条件"));
elseif rv==false then
    print(ToANSIString("证书不符合条件"));
else
    print(msg)
end
