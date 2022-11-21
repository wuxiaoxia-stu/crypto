local CryptCore=require("CryptCore")

function usage(filename)
	print(string.format("Usage: lua %s url",filename))
	os.exit(-1)
end

function save(outFileName,data)
	local fOut=assert(io.open(outFileName,"wb"))
	fOut:write(data)
	fOut:close()
end

local argCount=#arg
if argCount~=1 then
	usage(arg[0])
end

local url=arg[1]
local data=CryptCore.LdapGetAttributes(url)

if data==nil then
    print("ldap search fail")
	os.exit(-1)
end

local fileName
for name,t in pairs(data) do
	print(string.format("%s(%d)",name,#t))
    for i,data in ipairs(t) do
		fileName=name..i;
        save(fileName,data)
	end
end

print("Success")

