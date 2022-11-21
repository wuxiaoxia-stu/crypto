local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName inFileName outFileName deviceType deviceSn [pwd]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：加密证书文件"))
    print(ToANSIString("\tinFileName：要进行加密的明文文件名"))
    print(ToANSIString("\toutFileName：加密得到的密文文件名"))
    print(ToANSIString("\tdeviceType：设备类型，是个整数"))
    print(ToANSIString("\tdeviceSn：设备序列号"))
    print(ToANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t使用指定的设备进行SM1算法的数字信封"))
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
if argCount~=5 and argCount~=6 then
    Usage(arg[0])
    os.exit(-1)
end

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
    ["usage"]="encrypt",["keybits"]=128,["iv"]="1234567812345678"} then
    deviceObj:Free()
    print(ToANSIString("设备不支持SM1 CBC算法",keyBits))
    os.exit(-1)
end

local algo=CryptCore.Const.ENVELOPEDDATA_ALGORITHM_SM1CBC
local cert=GetCert(arg[1])

if cert==nil then
    deviceObj:Free()
    print(ToANSIString("读文件失败或者不是证书文件"));
    os.exit(-1)
end

if cert:InValidity()==false then
    cert:Free()
    deviceObj:Free()
    print(ToANSIString("证书不在有效期内"));
    os.exit(-1)
end

if cert:Match("CertType='Encrypt' || CertType='KeyAgreement'")==false then
    cert:Free()
    deviceObj:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local inFileName=arg[2]
local outFileName=arg[3]

local env=assert(CryptCore.NewEnvelopedData(true))
assert(env:SetEncAlgorithm(algo))
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

outData=env:EncryptInit()
fOut:write(outData)

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=env:EncryptUpdate(data)
    fOut:write(outData)
end

fIn:close()

outData=env:EncryptFinal()
env:Free()

fOut:write(outData)
fOut:close()
print(ToANSIString("加密成功"))


