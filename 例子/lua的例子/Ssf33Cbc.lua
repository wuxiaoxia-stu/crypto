local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s /e|/d key iv inFileName outFileName deviceType deviceSn [pwd]",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\t/e：表示加密"))
    print(ToANSIString("\t/d：表示解密"))
    print(ToANSIString("\tkey：Hex编码的密钥"))
    print(ToANSIString("\tiv：Hex编码的IV值"))
    print(ToANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tdeviceType：设备类型，是个整数"))
    print(ToANSIString("\tdeviceSn：设备序列号"))
    print(ToANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件使用指定的设备进行SSF33 CBC模式的加密或者解密运算，结果保存到outFileName文件中"))
end

function NewSsf33Cbc(deviceObj,enc,key,iv)
    return deviceObj:NewCBCCipher(enc,CryptCore.Const.SSF33_CBC,key,iv,CryptCore.Const.PADDING_PKCS7)
end


local argCount=#arg
if argCount~=7 and argCount~=8 then
    Usage(arg[0])
    os.exit(-1)
end

local enc

if arg[1]=="/e" or arg[1]=="-e" then
    enc=true
elseif arg[1]=="/d" or arg[1]=="-d" then
    enc=false
else
    Usage(arg[0]);
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[2])
if not key then
    print(ToANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local keyBits=#key*8
if keyBits~=128 then
    print(ToANSIString("SSF33密钥必须是128位的"));
    os.exit(-1)
end

local iv=CryptCore.HexDecode(arg[3])
if not iv then
    print(ToANSIString("IV不是Hex编码的"));
    os.exit(-1)
end

if #iv~=16 then
    print(ToANSIString("IV必须是16字节的"));
    os.exit(-1)
end

local inFileName=arg[4]
local outFileName=arg[5]

local deviceType
local deviceSn
local devicePwd
local deviceObj=nil
local algo=CryptCore.Const.SSF33_CBC
local usage
if enc then
    usage="encrypt"
else
    usage="decrypt"
end

deviceType=tonumber(arg[6])
deviceSn=arg[7]
    
deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
if not deviceObj then
    print(ToANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
if argCount==8 then
    devicePwd=arg[8]
    local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
    if result==false then
        if retryNumer==0 then
            print(ToANSIString("验证密码失败，设备已经锁死"))
        else
            print(ToANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
        end
        os.exit(-1)
    elseif result==nil then
        print(ToANSIString("验证密码出错"))
        os.exit(-1)
    end
        
end
    
if not deviceObj:IsSupportedAlgorithm{["algo"]=algo,["usage"]=usage,["keybits"]=keyBits,["iv"]=iv} then
    print(ToANSIString("设备不支持SSF33 CBC算法",keyBits))
    os.exit(-1)
end

local cipherObj
local fIn
local fOut
local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    deviceObj:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    fIn:close()
    deviceObj:Free()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

cipherObj=assert(NewSsf33Cbc(deviceObj,enc,key,iv))
deviceObj:Free()

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=cipherObj:Update(data)
    fOut:write(outData)
end

fIn:close()

outData=cipherObj:Final()
cipherObj:Free()
if outData==nil then
    if enc then
        print(ToANSIString("加密失败"))
    else
        print(ToANSIString("解密失败"))
    end
    fOut:close()
    os.exit(-1)
end

fOut:write(outData)
fOut:close()

if enc then
    print(ToANSIString("加密成功"))
else
    print(ToANSIString("解密成功"))
end

