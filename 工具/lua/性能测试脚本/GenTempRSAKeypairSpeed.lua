local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s bits count [deviceType deviceSn [pwd]]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\tbits：RSA密钥对的位数"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t产生bits位的临时RSA密钥对，重复执行count次。如果指定设备类型和序列号，则使用指定的设备产生临时RSA密钥对"))
    print(toANSIString("\t成功运行后产生GenTempRSAKeypairSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，一行有两列，第一列是产生密钥对时间，第二列是释放密钥对的时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s 1024 100",scriptName))
    print(toANSIString("\t产生1024位的临时RSA密钥对100次"))
    print(string.format("\tlua %s 1024 100 11 openssl",scriptName))
    print(toANSIString("\t使用openssl软设备产生1024位的临时RSA密钥对100次"))
end

function GenTempRSAKeypair(deviceObj,bits)
    return deviceObj:GenerateKeyPair {
        ["algo"]=CryptCore.Const.GENKEYPAIR_RSA,
        ["bits"]=bits,
        ["tempkeypair"]=true,
    }
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
    return string.format("GenTempRSAKeypairSpeed_%04d%02d%02d%02d%02d%02d.csv",
        t.year,t.month,t.day,t.hour,t.min,t.sec)
end

function SaveTimeFile(records)
    local fileName=GetCsvFileName()
    local fOut=assert(io.open(fileName,"w"))
    for i=1,#records do
        fOut:write(records[i][1],",",records[i][2],"\n")
    end
    fOut:close()
end

local argCount=#arg
if argCount~=2 and argCount~=4 and argCount~=5 then
    usage(arg[0])
    os.exit(-1)
end

local enc

local bits=tonumber(arg[1])
if bits<=0 then
    usage(arg[0]);
    os.exit(-1)
end

local count=tonumber(arg[2])
if count<=0 then
    usage(arg[0]);
    os.exit(-1)
end

local deviceType
local deviceSn
local devicePwd
local deviceObj=nil
local algo=CryptCore.Const.GENKEYPAIR_RSA
local usage
usage="genkeypair"

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local connectTime=nil
local disconnectTime
local connectTimer
local disconnectTimer

connectTimer=CryptCore.NewTimer()

if argCount>2 then
    deviceType=tonumber(arg[3])
    deviceSn=arg[4]
    
    connectTimer:Start()
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
    if not deviceObj then
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    if argCount==5 then
        devicePwd=arg[5]
        local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
        if result==false then
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
    
    
    if not deviceObj:IsSupportedAlgorithm{["algo"]=algo,["usage"]=usage,["keybits"]=bits,["tempkeypair"]=true} then
        print(toANSIString(string.format("设备不支持产生%d位的临时RSA密钥对",bits)))
        os.exit(-1)
    end
else
    connectTimer:Start()
    deviceObj=assert(CryptCore.NewDevice());
    connectTimer:Stop()
    connectTime=connectTimer:Time()
end

local genKeypairTimer=CryptCore.NewTimer()
local keypairObj
local freeKeypairTimer=CryptCore.NewTimer()

local records={}

for i=1,count do
    genKeypairTimer:Reset()
    freeKeypairTimer:Reset()
    
    genKeypairTimer:Start()
    keypairObj=assert(GenTempRSAKeypair(deviceObj,bits))
    genKeypairTimer:Stop()
    
    freeKeypairTimer:Start()
    keypairObj:Free()
    freeKeypairTimer:Stop()
    
    records[i]={genKeypairTimer:Time(),freeKeypairTimer:Time()}
end

disconnectTimer=CryptCore.NewTimer()
disconnectTimer:Start()
    
deviceObj:Free()
    
disconnectTimer:Stop()
disconnectTime=disconnectTimer:Time()

sumTimer:Stop()

local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒,速度:%.1f次/s",time,count/time*1000)))

if connectTime then
    print(toANSIString(string.format("设备连接时间:%.3f毫秒,断开时间:%.4f毫秒",connectTime,disconnectTime)))
end

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)

print(toANSIString(string.format("产生密钥对最大时间:%.1f毫秒,产生密钥对最小时间:%.1f毫秒,产生密钥对平均时间:%.1f毫秒,产生密钥对平均速度:%.1f次/s",maxTime,minTime,avgTime,1/avgTime*1000)))

avgTime=GetAvgValue(records,2)
minTime=GetMinValue(records,2)
maxTime=GetMaxValue(records,2)
print(toANSIString(string.format("释放密钥对最大时间:%.3f毫秒,释放密钥对最小时间:%.3f毫秒,释放密钥对平均时间:%.3f毫秒,释放密钥对平均速度:%.1f次/s",maxTime,minTime,avgTime,1/avgTime*1000)))

SaveTimeFile(records)
