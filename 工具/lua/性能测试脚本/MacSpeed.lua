local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s macAlgo key inFileName count [deviceType deviceSn [pwd]]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\tmacAlgo：Mac算法，比如:HMAC-SHA-1、HMAC-SM3之类"))
    print(toANSIString("\tkey：Hex编码的密钥"))
    print(toANSIString("\tinFileName：文件名，其内容要进行Mac运算"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t对inFileName文件进行Mac运算，Mac算法使用macAlgo，重复执行count次。如果指定设备类型和序列号，则使用指定的设备进行Mac运算"))
    print(toANSIString("\t成功运行后产生MacSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，一行有两列，第一列是Mac时间，第二列是读文件时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s HMAC-SHA-1 1234ABCD 1.pdf 100",scriptName))
    print(toANSIString("\t使用密钥1234ABCD对1.pdf文件进行HMAC-SHA-1运算100次"))
    print(string.format("\tlua %s HMAC-SHA-1 1234ABCD 1.pdf 100 11 openssl",scriptName))
    print(toANSIString("\t使用openssl软设备对1.pdf文件进行HMAC-SHA-1运算100次"))
end

function getMacAlgo(macAlgo)
    macAlgo=macAlgo:upper()
    if macAlgo== "HMAC-SHA-1" or macAlgo=="HMAC-SHA1" then
        return CryptCore.Const["HMAC-SHA-1"]
    elseif  macAlgo== "HMAC-SM3" then
        return CryptCore.Const["HMAC-SM3"]
    elseif  macAlgo== "HMAC-MD5" then
        return CryptCore.Const["HMAC-MD5"]
    elseif macAlgo== "HMAC-SHA-224" or macAlgo=="HMAC-SHA224" then
        return CryptCore.Const["HMAC-SHA-224"]
    elseif macAlgo== "HMAC-SHA-256" or macAlgo=="HMAC-SHA256" then
        return CryptCore.Const["HMAC-SHA-256"]
    elseif macAlgo== "HMAC-SHA-384" or macAlgo=="HMAC-SHA384" then
        return CryptCore.Const["HMAC-SHA-384"]
    elseif macAlgo== "HMAC-SHA-512" or macAlgo=="HMAC-SHA512" then
        return CryptCore.Const["HMAC-SHA-512"]
    elseif macAlgo== "HMAC-SHA-512/224" then
        return CryptCore.Const["HMAC-SHA-512/224"]
    elseif macAlgo== "HMAC-SHA-512/256" then
        return CryptCore.Const["HMAC-SHA-512/256"]
    elseif macAlgo== "HMAC-SHA3-224" then
        return CryptCore.Const["HMAC-SHA3-224"]
    elseif macAlgo== "HMAC-SHA3-256" then
        return CryptCore.Const["HMAC-SHA3-256"]
    elseif macAlgo== "HMAC-SHA3-384" then
        return CryptCore.Const["HMAC-SHA3-384"]
    elseif macAlgo== "HMAC-SHA3-512" then
        return CryptCore.Const["HMAC-SHA3-512"]
    elseif macAlgo== "AES-CMAC" then
        return CryptCore.Const["AES-CMAC"]
    elseif macAlgo== "3DES-CMAC" or hashAlgo=="TDES-CMAC" then
        return CryptCore.Const["TDES-CMAC"]
    elseif macAlgo== "SM4-CMAC" then
        return CryptCore.Const["SM4-CMAC"]
    else
        return nil;
    end
end

function NewMac(deviceObj,macAlgo,key)
    if deviceObj then
        return deviceObj:NewMac(macAlgo,key)
    else
        return CryptCore.NewMac(macAlgo,key)
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
    return string.format("MacSpeed_%04d%02d%02d%02d%02d%02d.csv",
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
if argCount~=4 and argCount~=6 and argCount~=7 then
    usage(arg[0])
    os.exit(-1)
end

local macAlgo=getMacAlgo(arg[1])
if not macAlgo then
    print(toANSIString("未知Mac算法"));
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[2])
if not key then
    print(toANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local fileName=arg[3]
local count=tonumber(arg[4])

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

if argCount>4 then
    deviceType=tonumber(arg[5])
    deviceSn=arg[6]
    
    connectTimer=CryptCore.NewTimer()
    connectTimer:Start()
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
    if not deviceObj then
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    if argCount==7 then
        devicePwd=arg[7]
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
    
    
    if not deviceObj:IsSupportedAlgorithm{["algo"]=macAlgo,["usage"]="mac",["keybits"]=#key*8} then
        print(toANSIString(string.format("设备不支持%s算法",arg[1])))
        os.exit(-1)
    end
end

local fileTimer=CryptCore.NewTimer()
local macTimer=CryptCore.NewTimer()
local macObj
local fIn
local data
local BLOCK_LEN=1024*1024
local macValue

local records={}

for i=1,count do
    macTimer:Reset()
    fileTimer:Reset()
    
    macTimer:Start()
    macObj=assert(NewMac(deviceObj,macAlgo,key))
    macTimer:Stop()
    
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

        macTimer:Start()
        macObj:Update(data)
        macTimer:Stop()
    end
    
    fileTimer:Start()
    fIn:close()
    fileTimer:Stop()

    macTimer:Start()
    macValue=macObj:Final()
    macObj:Free()
    macTimer:Stop()
    
    records[i]={macTimer:Time(),fileTimer:Time()}
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
print(toANSIString(string.format("Mac值:%s",CryptCore.HexEncode(true,macValue))))
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

print(toANSIString(string.format("Mac最大时间:%.1f毫秒,Mac最小时间:%.1f毫秒,Mac平均时间:%.1f毫秒,Mac平均速度:%.1fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))

avgTime=GetAvgValue(records,2)
minTime=GetMinValue(records,2)
maxTime=GetMaxValue(records,2)
print(toANSIString(string.format("读文件最大时间:%.1f毫秒,读文件最小时间:%.1f毫秒,读文件平均时间:%.1f毫秒",maxTime,minTime,avgTime)))

SaveTimeFile(records)
