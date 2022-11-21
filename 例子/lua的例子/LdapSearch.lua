local CryptCore=require("CryptCore")

function usage(filename)
	print(string.format("Usage: lua %s host dn filter attr1 [attr2 ....]",filename))
	os.exit(-1)
end

function save(outFileName,data)
	local fOut=assert(io.open(outFileName,"wb"))
	fOut:write(data)
	fOut:close()
end

local argCount=#arg
if argCount<4 then
	usage(arg[0])
end

local host=arg[1]
local dn=arg[2]
local filter=arg[3]

local attrs={}
for i=4,argCount do
    attrs[i-3]=arg[i]
end

local data=CryptCore.LdapSearch{
    ["host"]=host,
    ["baseDN"]=dn,
    ["scope"]=2,
    ["filter"]=filter,
    ["sizeLimit"]=100,
    ["attributes"]= attrs
}

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

