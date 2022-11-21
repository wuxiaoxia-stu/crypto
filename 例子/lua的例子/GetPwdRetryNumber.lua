local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s deviceType deviceSn [user|so]",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tuser：表示用户密码"))
    print(toANSIString("\tso：表示管理员密码"))
    print(toANSIString("说明"))
    print(toANSIString("\t获取设备密码的重试次数"))
end

function getPwdType(name)
    if name==nil then
        return CryptCore.Const.USER_PWD
    end
    name=name:upper()
    if name=="USER" then
        return CryptCore.Const.USER_PWD
    elseif name=="SO" then
        return CryptCore.Const.SO_PWD
    else
        return tonumber(name)
    end
end

local argCount=#arg
if argCount~=3 and argCount~=2 then
    usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local pwdType=getPwdType(arg[3])

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
local retryNumer= deviceObj:PwdRetryNum(pwdType)
deviceObj:Free()
if retryNumer==nil then
    print(toANSIString("获取密码重试次数失败，可能设备不支持"))
    os.exit(-1)
end
    

print(toANSIString(string.format("密码重试次数为%d",retryNumer)))