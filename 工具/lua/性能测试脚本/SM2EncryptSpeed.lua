local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s certFileName clearLen count [deviceType deviceSn [pwd]]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\tcertFileName：SM2加密证书文件名"))
    print(toANSIString("\tclearLen：加密的明文长度"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t使用SM2加密证书里的公钥进行不填充的RSA加密运算，重复执行count次。如果指定设备类型和序列号，则使用指定的设备进行加密运算"))
    print(toANSIString("\t成功运行后产生SM2EncryptSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，每一列是加密时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s sm2.cer 10 100",scriptName))
    print(toANSIString("\t使用sm2.cer的公钥进行不填充的RSA加密运算100次"))
    print(string.format("\tlua %s sm2.cer 10 100 11 openssl",scriptName))
    print(toANSIString("\t使用openssl软设备导入rsa.cer的公钥进行不填充的RSA加密运算100次"))
end

function GetMaxValue(records,index)
    local maxValue=records[1][index]
    for i=2,#records do
        if records[i][index] > maxValue then
            maxValue=records[i][index]
        end
    end
    return maxValue
end

function GetMinValue(records, index)
    local minValue=records[1][index]
    for i=2,#records do
        if records[i][index] < minValue then
            minValue=records[i][index]
        end
    end
    return minValue
end

function GetAvgValue(records, index)
    local sum=0
    local count=#records
    for i=1,count do
        sum=sum+records[i][index]
    end
    return sum/count
end

function GetCsvFileName()
    local t=os.date("*t")
    return string.format("SM2EncryptSpeed_%04d%02d%02d%02d%02d%02d.csv",
        t.year,t.month,t.day,t.hour,t.min,t.sec)
end

function SaveTimeFile(records)
    local fileName=GetCsvFileName()
    local fOut=assert(io.open(fileName,"w"))
    for i=1,#records do
        fOut:write(records[i][1],"\n")
    end
    fOut:close()
end

function GetCert(filename)
    local fIn=io.open(filename,"rb")
    if fIn==nil then
        return nil
    end
    local inData=fIn:read("*a")
    fIn:close()
    
    return CryptCore.NewCert(inData)
end

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local argCount=#arg
if argCount~=3 and argCount~=5 and argCount~=6 then
    usage(arg[0])
    os.exit(-1)
end

local count=tonumber(arg[3])

local certObj=GetCert(arg[1])
if certObj==nil then
    print(toANSIString("读文件失败或者文件不是证书"));
    os.exit(-1)
end

local algo=certObj:GetPublicKeyAlgorithm()
if algo~=CryptCore.Const.ECC then
    certObj:Free()
    print(toANSIString("不是SM2证书"));
    os.exit(-1)
end

local curve=certObj:GetPublicKeyEccCurve()
if curve~=CryptCore.Const.ECC_CURVE_SM2 then
    certObj:Free()
    print(toANSIString("不是SM2证书"));
    os.exit(-1)
end

local ku=certObj:GetKeyUsage()
if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_KEYENCIPHERMENT,CryptCore.Const.KEYUSAGE_DATAENCIPHERMENT)~=0 then
    certObj:Free()
    print(toANSIString("不是加密证书"));
    os.exit(-1)
end

if not certObj:InValidity() then
    certObj:Free()
    print(toANSIString("证书不在有效期内"));
    os.exit(-1)
end

local publicKey=certObj:PublicKey()
certObj:Free()
if publicKey==nil then
    print(toANSIString("获取公钥失败"));
    os.exit(-1)
end


local inLen=tonumber(arg[2])
local deviceObj=CryptCore.NewDevice()
local inData=deviceObj:GenerateRandom(inLen)
deviceObj:Free()
deviceObj=nil
if inData==nil then
    publicKey:Free()
    print(toANSIString("产生随机数失败"));
    os.exit(-1)
end

local deviceType
local deviceSn
local devicePwd


local connectTime=nil
local connectTimer


if argCount>3 then
    deviceType=tonumber(arg[4])
    deviceSn=arg[5]
    
    connectTimer=CryptCore.NewTimer()
    connectTimer:Start()
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
    if not deviceObj then
        publicKey:Free()
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    if argCount==6 then
        devicePwd=arg[6]
        local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
        if result==false then
            publicKey:Free()
            deviceObj:Free()
            if retryNumer==0 then
                print(toANSIString("验证密码失败，设备已经锁死"))
            else
                print(toANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
            end
            os.exit(-1)
        elseif result==nil then
            print(toANSIString("验证密码出错"))
            os.exit(-1)
        end
        
    end
    connectTimer:Stop()
    connectTime=connectTimer:Time()
    
	--[[
    inData=assert(deviceObj:GenerateRandom(inLen))
    --]]
	
    local publicKeyEncode=publicKey:Encode()
    publicKey:Free()
    if publicKeyEncode==nil then
        deviceObj:Free()
        print(toANSIString("公钥编码出错"))
        os.exit(-1)
    end
    publicKey=deviceObj:ImportPublicKey(publicKeyEncode)
    local errNumber=CryptCore.GetLastError();
    deviceObj:Free()
    if publicKey==nil then
        print(toANSIString("导入公钥出错"))
        os.exit(-1)
    end
    
    if deviceType~=0 and errNumber==0x20015 then
        publicKey:Free()
        print(toANSIString("设备不支持导入公钥"))
        os.exit(-1)
    end
    
end

local cipherTimer=CryptCore.NewTimer()
local fIn
local data


local records={}

for i=1,count do
    cipherTimer:Reset()
        
    cipherTimer:Start()
    data=assert(publicKey:Encrypt { ["algo"]=CryptCore.Const.SM2_ENC,["clear"]=inData })
    cipherTimer:Stop()
    
    records[i]={cipherTimer:Time()}
end

publicKey:Free()

sumTimer:Stop()
local time
time=sumTimer:Time()

print(toANSIString(string.format("总运行时间:%f毫秒",time)))
if connectTime then
    print(toANSIString(string.format("设备连接时间:%.3f毫秒",connectTime)))
end

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)

print(toANSIString(string.format("加密最大时间:%.3f毫秒,加密最小时间:%.3f毫秒,加密平均时间:%.3f毫秒,加密平均速度:%.3fMB/s,每秒加密%.1f次",maxTime,minTime,avgTime,inLen/1024/1024/avgTime*1000,1000/avgTime)))

SaveTimeFile(records)
