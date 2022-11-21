local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s deviceType deviceSn [pwd]",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t测试连接设备"))
end


local argCount=#arg
if argCount~=3 and argCount~=2 then
    usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local devicePwd=arg[3]

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
if argCount==3 then
    local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
    if result==false then
        if retryNumer==0 then
            print(toANSIString("验证密码失败，设备已经锁死"))
        else
            print(toANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
        end
        deviceObj:Free()
        os.exit(-1)
    elseif result==nil then
        deviceObj:Free()
        print(toANSIString("验证密码出错"))
        os.exit(-1)
    end
elseif deviceObj:MustLogin() then
    deviceObj:Free()
    print(toANSIString("必须输入密码"))
    os.exit(-1)
end
    
deviceObj:Free()
print(toANSIString("连接设备成功"))