local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s deviceType deviceSn count [pwd]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t重复执行count次连接设备"))
    print(toANSIString("\t成功运行后产生ConnectDeviceSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，一行有两列或者三列，第一列是连接设备时间，第二列是释放设备时间，第三列如果存在的话，表示验证密码的时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s 11 openssl 100",scriptName))
    print(toANSIString("\t连接openssl软设备100次"))
    print(string.format("\tlua %s 102 sjj0929 100 12345678",scriptName))
    print(toANSIString("\t连接sjj0929的得安加密机100次，并验证用户密码，密码为12345678"))
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
    return string.format("ConnectDevicSpeed_%04d%02d%02d%02d%02d%02d.csv",
        t.year,t.month,t.day,t.hour,t.min,t.sec)
end

function SaveTimeFile(records)
    local fileName=GetCsvFileName()
    local fOut=assert(io.open(fileName,"w"))
    for i=1,#records do
        fOut:write(table.concat(records[i],","),"\n")
    end
    fOut:close()
end

local argCount=#arg
if argCount~=3 and argCount~=4 then
    usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local count=tonumber(arg[3])
local devicePwd=arg[4]

if count<=0 then
    usage(arg[0]);
    os.exit(-1)
end


local deviceObj=nil

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local connectTime
local disconnectTime
local connectTimer=CryptCore.NewTimer()
local disconnectTimer=CryptCore.NewTimer()
local verifyPwdTime
local verifyPwdTimer

if argCount==4 then
    verifyPwdTimer=CryptCore.NewTimer()
end

local records={}

for i=1,count do
    connectTimer:Reset()
    connectTimer:Start()
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
    connectTimer:Stop()
    if not deviceObj then
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    if argCount==4 then
        verifyPwdTimer:Reset()
        verifyPwdTimer:Start()
        local result,retryNumer= deviceObj:VerifyPwd(devicePwd)
        verifyPwdTimer:Stop()
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
        
        disconnectTimer:Reset()
        disconnectTimer:Start()
        deviceObj:Free()
        disconnectTimer:Stop()
        records[i]={connectTimer:Time(),disconnectTimer:Time(),verifyPwdTimer:Time()}
    else
        disconnectTimer:Reset()
        disconnectTimer:Start()
        deviceObj:Free()
        disconnectTimer:Stop()
        records[i]={connectTimer:Time(),disconnectTimer:Time()}
    end
end

sumTimer:Stop()
local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒,速度:%.1f次/秒",time,count/time*1000)))

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)

print(toANSIString(string.format("设备连接最大时间:%.3f毫秒,设备连接最小时间:%.3f毫秒,设备连接平均时间:%.3f毫秒,设备连接平均速度:%.1f次/秒",maxTime,minTime,avgTime,1/avgTime*1000)))

avgTime=GetAvgValue(records,2)
minTime=GetMinValue(records,2)
maxTime=GetMaxValue(records,2)
print(toANSIString(string.format("设备断开连接最大时间:%.4f毫秒,设备断开连接最小时间:%.4f毫秒,设备断开连接平均时间:%.4f毫秒,设备断开连接平均速度:%.1f次/秒",maxTime,minTime,avgTime,1/avgTime*1000)))

if argCount==4 then
    avgTime=GetAvgValue(records,3)
    minTime=GetMinValue(records,3)
    maxTime=GetMaxValue(records,3)
    print(toANSIString(string.format("验证密码最大时间:%.3f毫秒,验证密码最小时间:%.3f毫秒,验证密码平均时间:%.3f毫秒,验证密码平均速度:%.1f次/秒",maxTime,minTime,avgTime,1/avgTime*1000)))
end
SaveTimeFile(records)
