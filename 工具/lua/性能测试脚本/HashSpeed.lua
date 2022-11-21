local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s hashAlgo inFileName count [deviceType deviceSn [pwd]]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
    print(toANSIString("\tinFileName：文件名，其内容要进行Hash运算"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t对inFileName文件进行Hash运算，Hash算法使用hashAlgo，重复执行count次。如果指定设备类型和序列号，则使用指定的设备进行Hash运算"))
    print(toANSIString("\t成功运行后产生HashSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，一行有两列，第一列是Hash时间，第二列是读文件时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s SHA-1 1.pdf 100",scriptName))
    print(toANSIString("\t对1.pdf文件进行SHA-1运算100次"))
    print(string.format("\tlua %s SHA-1 1.pdf 100 11 openssl",scriptName))
    print(toANSIString("\t使用openssl软设备对1.pdf文件进行SHA-1运算100次"))
    print(string.format("\tlua %s SM3 1.pdf 100 102 sjj0929 12345678",scriptName))
    print(toANSIString("\t使用序列号sjj0929的得安加密机对1.pdf文件进行SM3运算100次，密码为12345678"))
end

function getHashAlgo(hashAlgo)
    hashAlgo=hashAlgo:upper()
    if hashAlgo== "SHA-1" or hashAlgo=="SHA1" then
        return CryptCore.Const.SHA1
    elseif  hashAlgo== "SM3" then
        return CryptCore.Const.SM3
    elseif  hashAlgo== "MD5" then
        return CryptCore.Const.MD5
    elseif hashAlgo== "SHA-224" or hashAlgo=="SHA224" then
        return CryptCore.Const.SHA224
    elseif hashAlgo== "SHA-256" or hashAlgo=="SHA256" then
        return CryptCore.Const.SHA256
    elseif hashAlgo== "SHA-384" or hashAlgo=="SHA384" then
        return CryptCore.Const.SHA384
    elseif hashAlgo== "SHA-512" or hashAlgo=="SHA512" then
        return CryptCore.Const.SHA512
    elseif hashAlgo== "SHA-512/224" then
        return CryptCore.Const["SHA-512/224"]
    elseif hashAlgo== "SHA-512/256" then
        return CryptCore.Const["SHA-512/256"]
    elseif hashAlgo== "SHA3-224" then
        return CryptCore.Const["SHA3-224"]
    elseif hashAlgo== "SHA3-256" then
        return CryptCore.Const["SHA3-256"]
    elseif hashAlgo== "SHA3-384" then
        return CryptCore.Const["SHA3-384"]
    elseif hashAlgo== "SHA3-512" then
        return CryptCore.Const["SHA3-512"]
    else
        return nil;
    end
end

function NewHash(deviceObj,hashAlgo)
    if deviceObj then
        return deviceObj:NewHash(hashAlgo)
    else
        return CryptCore.NewHash(hashAlgo)
    end
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
    return string.format("HashSpeed_%04d%02d%02d%02d%02d%02d.csv",
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
if argCount~=3 and argCount~=5 and argCount~=6 then
    usage(arg[0])
    os.exit(-1)
end

local hashAlgo=getHashAlgo(arg[1])
if not hashAlgo then
    print(toANSIString("未知Hash算法"));
    os.exit(-1)
end

local fileName=arg[2]
local count=tonumber(arg[3])

if count<=0 then
    usage(arg[0]);
    os.exit(-1)
end

local deviceType
local deviceSn
local devicePwd
local deviceObj=nil

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local connectTime=nil
local disconnectTime
local connectTimer
local disconnectTimer

if argCount>3 then
    deviceType=tonumber(arg[4])
    deviceSn=arg[5]
    
    connectTimer=CryptCore.NewTimer()
    connectTimer:Start()
    
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
    if not deviceObj then
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    --print(toANSIString(string.format("连接设备成功,设备类型:%d，设备序列号:%s",deviceType,deviceSn)))
    
    if argCount==6 then
        devicePwd=arg[6]
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
        --else
            --print(toANSIString("验证密码成功"))
        end
        
    end
    connectTimer:Stop()
    connectTime=connectTimer:Time()
    
    if not deviceObj:IsSupportedAlgorithm{["algo"]=hashAlgo,["usage"]="hash"} then
        print(toANSIString(string.format("设备不支持%s算法",arg[1])))
        os.exit(-1)
    end
end

local fileTimer=CryptCore.NewTimer()
local hashTimer=CryptCore.NewTimer()
local hashObj
local fIn
local data
local BLOCK_LEN=1024*1024
local hashValue

local records={}

for i=1,count do
    hashTimer:Reset()
    fileTimer:Reset()
    
    hashTimer:Start()
    hashObj=assert(NewHash(deviceObj,hashAlgo))
    hashTimer:Stop()
    
    fileTimer:Start()
    fIn=assert(io.open(fileName,"rb"))
    fileTimer:Stop()
    
    while(true) do
        fileTimer:Start()
        data=fIn:read(BLOCK_LEN)
        fileTimer:Stop()

        if not data then
            break
        end

        hashTimer:Start()
        hashObj:Update(data)
        hashTimer:Stop()
    end
    
    fileTimer:Start()
    fIn:close()
    fileTimer:Stop()

    hashTimer:Start()
    hashValue=hashObj:Final()
    hashObj:Free()
    hashTimer:Stop()
    
    records[i]={hashTimer:Time(),fileTimer:Time()}
end

if deviceObj then
    disconnectTimer=CryptCore.NewTimer()
    disconnectTimer:Start()
    
    deviceObj:Free()
    
    disconnectTimer:Stop()
    disconnectTime=disconnectTimer:Time()
end

local fileLength=CryptCore.GetFileLength(CryptCore.ACPToUTF8(fileName))
sumTimer:Stop()
print(toANSIString(string.format("Hash值:%s",CryptCore.HexEncode(true,hashValue))))
print(toANSIString(string.format("文件长度:%d字节",fileLength)))
local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒,速度:%.1fMB/s",time,fileLength*count/1024/1024/time*1000)))

if connectTime then
    print(toANSIString(string.format("设备连接时间:%.3f毫秒,断开时间:%.4f毫秒",connectTime,disconnectTime)))
end

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)
print(toANSIString(string.format("Hash最大时间:%.1f毫秒,Hash最小时间:%.1f毫秒,Hash平均时间:%.1f毫秒,Hash平均速度:%.1fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))

avgTime=GetAvgValue(records,2)
minTime=GetMinValue(records,2)
maxTime=GetMaxValue(records,2)
print(toANSIString(string.format("读文件最大时间:%.1f毫秒,读文件最小时间:%.1f毫秒,读文件平均时间:%.1f毫秒",maxTime,minTime,avgTime)))

SaveTimeFile(records)
