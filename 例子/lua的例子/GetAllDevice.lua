local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function FreeDeviceSet(deviceSet)
	for i,device in ipairs(deviceSet) do
		device:Free()
	end
end

local deviceSet=CryptCore.NewDeviceSet{ ["type"]=-1 }

local deviceCount=#deviceSet

if deviceCount==0 then
	print(ToANSIString("没有设备"));
	os.exit(-1)
end

for i=1,deviceCount do
	print(ToANSIString(string.format("%d\t设备类型：%d,设备序列号:%s",i,deviceSet[i]:Type(),deviceSet[i]:SerialNumber())))
end
FreeDeviceSet(deviceSet)
