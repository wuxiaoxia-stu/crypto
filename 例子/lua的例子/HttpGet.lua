local CryptCore=require("CryptCore")

function usage(filename)
	print(string.format("Usage: lua %s url outputFileName",filename))
	os.exit(-1)
end

function save(outFileName,data)
	local fOut=assert(io.open(outFileName,"wb"))
	fOut:write(data)
	fOut:close()
end

local argCount=#arg
if argCount~=2 then
	usage(arg[0])
end

local url=arg[1]
local fileName=arg[2]




local status,contentType,data=assert(CryptCore.HttpGet(url))
print(string.format("status:%d",status))
if status>=200 and status<300 then
    print(string.format("Content-Type:%s",contentType))
	save(fileName,data)
end



