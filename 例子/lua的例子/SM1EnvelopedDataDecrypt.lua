local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName inFileName outFileName deviceType deviceSn [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：证书文件名"))
    print(ToANSIString("\tinFileName：要进行解密的文件名"))
    print(ToANSIString("\toutFileName：解密得到的明文文件名"))
    print(ToANSIString("\tdeviceType：设备类型，是个整数"))
    print(ToANSIString("\tdeviceSn：设备序列号"))
    print(ToANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t解密SM1的数字信封"))
end

function GetEncAlgoName(algo)
    if algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES128CBC then
        return "AES-128"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES192CBC then
        return "AES-192"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_AES256CBC then
        return "AES-256"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_DESCBC then
        return "DES"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_TDESCBC then
        return "3DES"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_RC2CBC then
        return "RC2"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SSF33CBC then
        return "SSF33"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM1CBC then
        return "SM1"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM4CBC then
        return "SM4"
    elseif algo==CryptCore.Const.ENVELOPEDDATA_ALGORITHM_RC4 then
        return "RC4"
    else
        return string.format("unknwon algo(%d)",algo)
    end
end

function GetFileConetent(fileName)
    local fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end
    local data=fIn:read("*a")
    fIn:close()
    
    return data
end

function GetCert(filename)
    local inData=GetFileConetent(filename)
    if inData==nil then
        return nil
    end
    
    return CryptCore.NewCert(inData)
end

local argCount=#arg
if argCount~=5 and  argCount~=6 then
    Usage(arg[0])
    os.exit(-1)
end

local inFileName=arg[2]
local outFileName=arg[3]

local deviceType=tonumber(arg[4])
local deviceSn=arg[5]
local devicePwd=arg[6]

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(ToANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
if argCount==6 then
    local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
    if result==false then
        if retryNumer==0 then
            print(ToANSIString("验证密码失败，设备已经锁死"))
        else
            print(ToANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
        end
        deviceObj:Free()
        os.exit(-1)
    elseif result==nil then
        deviceObj:Free()
        print(ToANSIString("验证密码出错"))
        os.exit(-1)
    end
elseif deviceObj:MustLogin() then
    deviceObj:Free()
    print(ToANSIString("必须输入密码"))
    os.exit(-1)
end

if not deviceObj:IsSupportedAlgorithm{["algo"]=CryptCore.Const.SM1_CBC,
    ["usage"]="decrypt",["keybits"]=128,["iv"]="1234567812345678"} then
    deviceObj:Free()
    print(ToANSIString("设备不支持SM1 CBC算法",keyBits))
    os.exit(-1)
end

local cert=GetCert(arg[1])

if cert==nil then
    deviceObj:Free()
    print(ToANSIString("读文件失败或者不是证书文件"));
    os.exit(-1)
end

--如果证书的私钥在设备中，则不需要这一步
--[[
local keypair=cert:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_ENCRYPT)
if keypair==nil then
    deviceObj:Free()
    cert:Free()
    print(ToANSIString("证书没有私钥或者不是加密证书"));
    os.exit(-1)
end
keypair:Free()
--]]

local env=assert(CryptCore.NewEnvelopedData(false))

assert(env:SetDevice(deviceObj))
deviceObj:Free()
assert(env:AddCert(cert))
cert:Free()

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    env:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    env:Free()
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

assert(env:DecryptInit())

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=env:DecryptUpdate(data)
    if outData==nil then
        env:Free()
        fIn:close()
        fOut:close()
        print(ToANSIString("解密失败"))
        os.exit(-1)
    end
    fOut:write(outData)
end

fIn:close()
fOut:close()
outData=env:DecryptFinal(data)

if outData==false then
    env:Free()
    print(ToANSIString("解密失败"))
    os.exit(-1)
end

print(ToANSIString("解密成功"))
print(ToANSIString(string.format("对称加密算法:%s",GetEncAlgoName(env:GetEncAlgorithm()))))
print(ToANSIString(string.format("解密证书的主体:%s",env:GetCert():GetSubject())))
env:Free()

