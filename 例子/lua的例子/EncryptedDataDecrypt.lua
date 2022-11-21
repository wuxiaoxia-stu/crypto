local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s pwd inFileName outFileName",filename))
    print(ToANSIString("参数"))
	print(ToANSIString("\tpwd：口令"))
	print(ToANSIString("\tinFileName：密文文件名"))
	print(ToANSIString("\toutFileName：明文文件名"))
	print(ToANSIString("说明"))
    print(ToANSIString("\t使用pwd解密inFileName的EncrypedData格式的数据，结果保存在outFileName中"))
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

function save(outFileName,data)
	local fOut=assert(io.open(outFileName,"wb"))
	fOut:write(data)
	fOut:close()
end

if #arg~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local pwd=arg[1]
local inFileName=arg[2]
local outFileName=arg[3]

local encrypedData=GetFileConetent(inFileName)
if encrypedData==nil then
    print(ToANSIString("读密文文件失败"));
    os.exit(-1)
end

local clear=CryptCore.EncryptedDataDecrypt(pwd,encrypedData)
if clear==nil then
	print(ToANSIString("解密失败"));
    os.exit(-1)
end
save(outFileName,clear)
print(ToANSIString("解密成功"));


