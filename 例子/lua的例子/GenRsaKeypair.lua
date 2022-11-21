local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(toANSIString(string.format("lua %s deviceType deviceSn bits keypairLabel keypairType [pwd]",scriptName)))
    print(toANSIString("参数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tbits：要产生的RSA密钥位数"))
    print(toANSIString("\tkeypairLabel：密钥对标签"))
    print(toANSIString("\tkeypairType：密钥对类型，enc为加密，sign为签名"))
    print(toANSIString("\tpwd：设备的用户密码"))
    print(toANSIString("说明"))
    print(toANSIString("\t产生bits位的RSA密钥对"))
end

function getKeypairType(name)
    name=name:upper()
    if name=="ENC" or name=="ENCRYPT" then
        return CryptCore.Const.KEYPAIRTYPE_ENCRYPT
    elseif name=="SIGN" or name=="SIGNATURE" then
        return CryptCore.Const.KEYPAIRTYPE_SIGNATURE
    elseif name=="KEYAGREEMENT" then
        return CryptCore.Const.KEYPAIRTYPE_KEYAGREEMENT
    else
        return tonumber(name)
    end
end

local argCount=#arg
if argCount~=5 and argCount~=6 then
    usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local bits=tonumber(arg[3])

if bits<1024 then
    print(toANSIString("密钥对长度太短，必须不小于1024位"))
    os.exit(-1)
end

local label=arg[4]
local keypairType=getKeypairType(arg[5])

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
if argCount==6 then
    local result,retryNumer= deviceObj:VerifyPwd(arg[6])
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
    
local keypair=deviceObj:GenerateKeyPair {
    ["algo"]=CryptCore.Const.GENKEYPAIR_RSA,
    ["bits"]=bits,
    ["type"]=keypairType,
    ["label"]=label,
}
deviceObj:Free()

if keypair==nil then
    if CryptCore.GetLastError()== -6 then
        print(toANSIString("密钥对已经存在"))
    else
        print(toANSIString("产生RSA密钥对失败"))
    end
    os.exit(-1)
end

keypair:Free()
print(toANSIString("产生RSA密钥对成功"))
