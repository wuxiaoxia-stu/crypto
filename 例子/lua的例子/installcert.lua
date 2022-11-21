local CryptCore=require("CryptCore")

function usage(filename)
	print(string.format("Usage: lua %s deviceType deviceSN pwd [encCert] signCert",filename))
	os.exit(-1)
end

function getcert(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return CryptCore.NewCert(inData)
end

if #arg~=4 and #arg~=5 then
	usage(arg[0])
end

local deviceType=tonumber(arg[1])
local deviceSN=arg[2]
local pwd=arg[3]

local keypairType

keypairType=CryptCore.Const["ENCKEYPAIR_TYPE_NONE"]

local encCert
local signCert
local pos
pos=4
if #arg==5 then
	encCert=getcert(arg[pos])
	pos=pos+1
	if encCert==nil then
		print("bad encCert")
		os.exit(-1)
	end
end
signCert=getcert(arg[pos])
if signCert==nil then
	print("bad signCert")
	os.exit(-1)
end


local device

device=CryptCore.GetDevice(deviceType,deviceSN)
if device==nil then
	print("no such device")
	os.exit(-1)
end

---[[
if not device:VerifyPwd(pwd) then
	device:Free()
	print("pwd error")
	os.exit(-1)
end
--]]
--
--
local rv
if encCert~=nil then
	rv=device:InstallCert{
		["type"]=keypairType,
		["enccert"]=encCert:Encode(),
		["signcert"]=signCert:Encode()
	}
	encCert:Free()
else
	rv=device:InstallCert{
		["type"]=keypairType,
		["signcert"]=signCert:Encode()
	}
end

signCert:Free()
device:Free()
if not rv then
	print("install fail")
	os.exit(-1)
end

print("success")

