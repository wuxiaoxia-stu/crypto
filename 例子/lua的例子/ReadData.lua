local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s deviceType deviceSn id offset length outFileName [user|so pwd]",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tid：持久数据的ID"))
    print(toANSIString("\toffset：位移"))
    print(toANSIString("\tlength：长度，-1为文件长度-位移，也就是读到文件尾"))
    print(toANSIString("\toutFileName：输出文件名"))
    print(toANSIString("\tuser：表示用户密码"))
    print(toANSIString("\tso：表示管理员密码"))
    print(toANSIString("\tpwd：设备的密码，默认为用户密码"))
    print(toANSIString("说明"))
    print(toANSIString("\t读持久数据"))
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
if argCount~=6 and argCount~=8 then
    usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local id=tonumber(arg[3])
local offset=tonumber(arg[4])
local length=tonumber(arg[5])
local outFileName=arg[6]

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end

if  argCount==8 then
    local devicePwd=arg[8]
    local pwdType=getPwdType(arg[7])
    local result,retryNumer= deviceObj:VerifyPwd(pwdType,devicePwd)
    if result==false then
        if retryNumer==0 then
            print(toANSIString("验证密码失败，设备已经锁死"))
        else
            print(toANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
        end
        deviceObj:Free()
        os.exit(-1)
    elseif result==nil then
        print(toANSIString("验证密码出错"))
        deviceObj:Free()
        os.exit(-1)
    end
end

if length==-1 then
    length=deviceObj:GetDataLength(id)
    if length <0 then
        print(toANSIString("获取持久数据的长度出错"))
        deviceObj:Free()
        os.exit(-1)
    end
    if length< offset then
        print(toANSIString("位移超出文件尾了"))
        deviceObj:Free()
        os.exit(-1)
    end
    length=length-offset
end

if length <0 then
    print(toANSIString("长度不能是负数"))
    deviceObj:Free()
    os.exit(-1)
end

local data=deviceObj:ReadData(id,offset,length)
deviceObj:Free()

if data==nil then
    print(toANSIString("读持久数据失败"))
end

local fOut=io.open(outFileName,"wb")
if fOut==nil then
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

fOut:write(data)
fOut:close()
print(toANSIString("读持久数据成功"))
