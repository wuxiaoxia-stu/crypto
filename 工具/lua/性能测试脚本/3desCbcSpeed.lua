local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s /e|/d key iv inFileName count [deviceType deviceSn [pwd]]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\t/e：表示加密"))
    print(toANSIString("\t/d：表示解密"))
    print(toANSIString("\tkey：Hex编码的密钥"))
    print(toANSIString("\tiv：Hex编码的IV值"))
    print(toANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t对inFileName文件进行3DES CBC模式的加密或者解密运算，重复执行count次。如果指定设备类型和序列号，则使用指定的设备进行加解密运算"))
    print(toANSIString("\t成功运行后产生3desCbcSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，一行有两列，第一列是加密或者解密时间，第二列是读文件时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s /e 123456781234567812345678ABCDEF901234567890ABCDEF 1234567812345678 1.pdf 100",scriptName))
    print(toANSIString("\t使用密钥123456781234567812345678ABCDEF901234567890ABCDEF，IV 1234567812345678对1.pdf文件进行3DES CBC加密100次"))
    print(string.format("\tlua %s /d 123456781234567812345678ABCDEF901234567890ABCDEF 1234567812345678 1.enc 100",scriptName))
    print(toANSIString("\t使用密钥123456781234567812345678ABCDEF901234567890ABCDEF，IV 1234567812345678对1.enc文件进行3DES CBC解密100次"))
    print(string.format("\tlua %s /e 123456781234567812345678ABCDEF901234567890ABCDEF 1234567812345678 1.pdf 100 11 openssl",scriptName))
    print(toANSIString("\t使用openssl软设备对1.pdf文件进行3DES CBC加密100次"))
end

function New3desCbc(deviceObj,enc,key,iv)
    if deviceObj then
        return deviceObj:NewCBCCipher(enc,CryptCore.Const.TDES_CBC,key,iv,CryptCore.Const.PADDING_PKCS7)
    else
        return CryptCore.NewCBCCipher(enc,CryptCore.Const.TDES_CBC,key,iv,CryptCore.Const.PADDING_PKCS7)
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
    return string.format("3desCbcSpeed_%04d%02d%02d%02d%02d%02d.csv",
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
if argCount~=5 and argCount~=7 and argCount~=8 then
    usage(arg[0])
    os.exit(-1)
end

local enc

if arg[1]=="/e" or arg[1]=="-e" then
    enc=true
elseif arg[1]=="/d" or arg[1]=="-d" then
    enc=false
else
    usage(arg[0]);
    os.exit(-1)
end

local key=CryptCore.HexDecode(arg[2])
if not key then
    print(toANSIString("密钥不是Hex编码的"));
    os.exit(-1)
end

local keyBits=#key*8
if keyBits~=128 and keyBits~=192 then
    print(toANSIString("3DES密钥必须是128或者192位的"));
    os.exit(-1)
end

local iv=CryptCore.HexDecode(arg[3])
if not iv then
    print(toANSIString("IV不是Hex编码的"));
    os.exit(-1)
end

if #iv~=8 then
    print(toANSIString("IV必须是8字节的"));
    os.exit(-1)
end

local fileName=arg[4]
local count=tonumber(arg[5])

if count<=0 then
    usage(arg[0]);
    os.exit(-1)
end

local deviceType
local deviceSn
local devicePwd
local deviceObj=nil
local algo=CryptCore.Const.TDES_CBC
local usage
if enc then
    usage="encrypt"
else
    usage="decrypt"
end

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local connectTime=nil
local disconnectTime
local connectTimer
local disconnectTimer

if argCount>5 then
    deviceType=tonumber(arg[6])
    deviceSn=arg[7]
    
    connectTimer=CryptCore.NewTimer()
    connectTimer:Start()
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
    if not deviceObj then
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    if argCount==8 then
        devicePwd=arg[8]
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
    
    
    if not deviceObj:IsSupportedAlgorithm{["algo"]=algo,["usage"]=usage,["keybits"]=keyBits,["iv"]=iv} then
        print(toANSIString(string.format("设备不支持%d位的3DES CBC算法",keyBits)))
        os.exit(-1)
    end
end

local fileTimer=CryptCore.NewTimer()
local cipherTimer=CryptCore.NewTimer()
local cipherObj
local fIn
local data
local BLOCK_LEN=1024*1024


local records={}

for i=1,count do
    cipherTimer:Reset()
    fileTimer:Reset()
    
    cipherTimer:Start()
    cipherObj=assert(New3desCbc(deviceObj,enc,key,iv))
    cipherTimer:Stop()
    
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

        cipherTimer:Start()
        assert(cipherObj:Update(data))
        cipherTimer:Stop()
    end
    
    fileTimer:Start()
    fIn:close()
    fileTimer:Stop()

    cipherTimer:Start()
    assert(cipherObj:Final())
    cipherObj:Free()
    cipherTimer:Stop()
    
    records[i]={cipherTimer:Time(),fileTimer:Time()}
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

if enc then
    print(toANSIString(string.format("加密最大时间:%.1f毫秒,加密最小时间:%.1f毫秒,加密平均时间:%.1f毫秒,加密平均速度:%.1fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))
else
    print(toANSIString(string.format("解密最大时间:%.1f毫秒,解密最小时间:%.1f毫秒,解密平均时间:%.1f毫秒,解密平均速度:%.1fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))
end

avgTime=GetAvgValue(records,2)
minTime=GetMinValue(records,2)
maxTime=GetMaxValue(records,2)
print(toANSIString(string.format("读文件最大时间:%.1f毫秒,读文件最小时间:%.1f毫秒,读文件平均时间:%.1f毫秒",maxTime,minTime,avgTime)))

SaveTimeFile(records)
