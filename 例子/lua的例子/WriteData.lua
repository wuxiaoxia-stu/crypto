local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s deviceType deviceSn id offset  inFileName [user|so pwd]",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tid：持久数据的ID"))
    print(toANSIString("\toffset：位移"))
    print(toANSIString("\tinFileName：输入文件名"))
    print(toANSIString("\tuser：表示用户密码"))
    print(toANSIString("\tso：表示管理员密码"))
    print(toANSIString("\tpwd：设备的密码，默认为用户密码"))
    print(toANSIString("说明"))
    print(toANSIString("\t写持久数据"))
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
if argCount~=5 and argCount~=7 then
    usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local id=tonumber(arg[3])
local offset=tonumber(arg[4])
local inFileName=arg[5]

local fIn=io.open(inFileName,"rb")
if fIn==nil then
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end
local data=fIn:read("*a")
fIn:close()

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end

if  argCount==7 then
    local devicePwd=arg[7]
    local pwdType=getPwdType(arg[6])
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
end


local rv=deviceObj:WriteData(id,offset,data)
deviceObj:Free()

if rv==1 then
    print(toANSIString("写持久数据成功"))
else
    print(toANSIString(string.format("写持久数据失败，错误号为:%d",rv)))
end
