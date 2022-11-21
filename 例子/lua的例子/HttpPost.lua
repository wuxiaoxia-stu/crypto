local CryptCore=require("CryptCore")

function usage(filename)
	print(string.format("Usage: lua %s url contentType inputFileName outputFileName",filename))
	os.exit(-1)
end

function save(outFileName,data)
	local fOut=assert(io.open(outFileName,"wb"))
	fOut:write(data)
	fOut:close()
end

function getFileConetent(fileName)
    local fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end
    local data=fIn:read("*a")
    fIn:close()
    
    return data
end

local argCount=#arg
if argCount~=4 then
	usage(arg[0])
end

local url=arg[1]
local contentType=arg[2]
local inputFileName=arg[3]
local outputFileName=arg[4]

local inData=getFileConetent(inputFileName)
if inData==nil then
    print(string.format("read file %s fail",filename))
	os.exit(-1)
end

local contentTypeHeader=string.format("Content-Type:%s",contentType)

local status,contentType,data=assert(CryptCore.HttpPost(url,inData,{contentTypeHeader}))
print(string.format("status:%d",status))
if status>=200 and status<300 then
    print(string.format("Content-Type:%s",contentType))
	save(outputFileName,data)
end



