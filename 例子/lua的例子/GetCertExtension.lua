local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s cert oid",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\toid：扩展OID"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t输出证书的详细信息"))
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
    print(ToANSIString("读证书文件失败"))
    os.exit(-1)
end

local oid=arg[2]

local value,critical=cert:GetExtension(oid)
if value==nil then
    if CryptCore.GetLastError()==-7 then
        print(ToANSIString("没有该扩展"))
    else
        print(ToANSIString("获取扩展失败"))
    end
    os.exit(-1)
end
if critical then
    print(ToANSIString("关键扩展"))
else
    print(ToANSIString("非关键扩展"))
end

local str=cert:GetStringExtension(oid)
if str~=nil then
    print(ToANSIString(string.format("扩展值：%s",str)))
else
    print(ToANSIString(string.format("Hex扩展值：%s",CryptCore.HexEncode(value))))
end

cert:Free()
