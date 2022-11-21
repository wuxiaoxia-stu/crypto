local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s randBytes count",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\trandBytes：一次产生的随机数的字节数"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("说明"))
    print(toANSIString("\t重复执行count次产生randBytes字节的随机数"))
    print(toANSIString("\t成功运行后产生GenRandSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s 1024 100",scriptName))
    print(toANSIString("\t重复产生1024字节的随机数100次"))
end

function GetMaxValue(records)
    local maxValue=records[1]
    for i=2,#records do
        if records[i]> maxValue then
            maxValue=records[i]
        end
    end
    return maxValue
end

function GetMinValue(records)
    local minValue=records[1]
    for i=2,#records do
        if records[i] < minValue then
            minValue=records[i]
        end
    end
    return minValue
end

function GetAvgValue(records)
    local sum=0
    local count=#records
    for i=1,count do
        sum=sum+records[i]
    end
    return sum/count
end

function GetCsvFileName()
    local t=os.date("*t")
    return string.format("GenRandSpeed_%04d%02d%02d%02d%02d%02d.csv",
        t.year,t.month,t.day,t.hour,t.min,t.sec)
end

function SaveTimeFile(records)
    local fileName=GetCsvFileName()
    local fOut=assert(io.open(fileName,"w"))
    for i=1,#records do
        fOut:write(records[i],"\n")
    end
    fOut:close()
end

local argCount=#arg
if argCount~=2 then
    usage(arg[0])
    os.exit(-1)
end

local randLength=tonumber(arg[1])
if randLength<=0 then
    usage(arg[0])
    os.exit(-1)
end

local count=tonumber(arg[2])
if count<=0 then
    usage(arg[0])
    os.exit(-1)
end

local deviceObj=nil

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

deviceObj=assert(CryptCore.NewDevice())


local randTimer=CryptCore.NewTimer()
local data

local records={}

for i=1,count do
    randTimer:Reset()
        
    randTimer:Start()
    data=assert(deviceObj:GenerateRandom(randLength))
    randTimer:Stop()
    
    records[i]=randTimer:Time()
end


sumTimer:Stop()
local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒,速度:%.1fMB/s",time,randLength*count/1024/1024/time*1000)))

local avgTime=GetAvgValue(records)
local minTime=GetMinValue(records)
local maxTime=GetMaxValue(records)

print(toANSIString(string.format("产生随机数最大时间:%.3f毫秒,最小时间:%.3f毫秒,平均时间:%.3f毫秒,平均速度:%.1fMB/s",maxTime,minTime,avgTime,randLength/1024/1024/avgTime*1000)))

SaveTimeFile(records)
