local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s /e|/d key nonce adata tLen inFileName count [deviceType deviceSn [pwd]]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\t/e：表示加密"))
    print(toANSIString("\t/d：表示解密"))
    print(toANSIString("\tkey：Hex编码的密钥"))
    print(toANSIString("\tnonce：Hex编码的Nonce值"))
    print(toANSIString("\tadata：Adata"))
    print(toANSIString("\ttLen：Mac的字节数"))
    print(toANSIString("\tinFileName：文件名，其内容要进行加密或者解密运算"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tdeviceType：设备类型，是个整数"))
    print(toANSIString("\tdeviceSn：设备序列号"))
    print(toANSIString("\tpwd：设备的用户密码，如果提供则验证"))
    print(toANSIString("说明"))
    print(toANSIString("\t对inFileName文件进行AES CCM模式的加密或者解密运算，重复执行count次。如果指定设备类型和序列号，则使用指定的设备进行加解密运算"))
    print(toANSIString("\t成功运行后产生AesCcmSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的加密或者解密时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s /e 1234567812345678123456  12345678123456781234567812345678 \"\" 16 1.pdf 100",scriptName))
    print(toANSIString("\t对1.pdf文件进行AES CCM加密100次"))
    print(string.format("\tlua %s /d 1234567812345678123456 12345678123456781234567812345678 \"\" 16 1.enc 100",scriptName))
    print(toANSIString("\t对1.enc文件进行AES CCM解密100次"))
    print(string.format("\tlua %s /e 1234567812345678123456 12345678123456781234567812345678 \"\" 16 1.pdf 100 11 openssl",scriptName))
    print(toANSIString("\t使用openssl软设备对1.pdf文件进行AES CCM加密100次"))
end

function NewAesCcm(deviceObj,enc,key,nonce,tLen,aad,p)
    if deviceObj then
        return deviceObj:NewCCMCipher(enc,CryptCore.Const.AES_CCM,key,tLen,nonce,aad,p)
    else
        return CryptCore.NewCCMCipher(enc,CryptCore.Const.AES_CCM,key,tLen,nonce,aad,p)
    end
end

function GetMaxValue(records)
    local maxValue=records[1]
    for i=2,#records do
        if records[i] > maxValue then
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
    return string.format("AesCcmSpeed_%04d%02d%02d%02d%02d%02d.csv",
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
if argCount~=7 and argCount~=9 and argCount~=10 then
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
if keyBits~=128 and keyBits~=192 and keyBits~=256 then
    print(toANSIString("AES密钥必须是128、192或者256位的"));
    os.exit(-1)
end

local nonce=CryptCore.HexDecode(arg[3])
if not nonce then
    print(toANSIString("Nonce不是Hex编码的"));
    os.exit(-1)
end

if #nonce<7 or #nonce>13 then
    print(toANSIString("Nonce必须是7-13字节的"));
    os.exit(-1)
end

local adata=arg[4]

local tLen=tonumber(arg[5])
if tLen~=4 and tLen~=6 and tLen~=8 and tLen~=10 and tLen~=12 and tLen~=14 and tLen~=16 then
    print(toANSIString("Mac长度必须是4、6、8、10、12、14、16字节的"));
    os.exit(-1)
end

local fileName=arg[6]
local count=tonumber(arg[7])

if count<=0 then
    usage(arg[0]);
    os.exit(-1)
end



local deviceType
local deviceSn
local devicePwd
local deviceObj=nil
local algo=CryptCore.Const.AES_CCM
local usage
if enc then
    usage="encrypt"
else
    usage="decrypt"
end

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local fileLength=CryptCore.GetFileLength(CryptCore.ACPToUTF8(fileName))
if not fileLength then
    print(toANSIString("获取文件长度失败"));
    os.exit(-1)
end

local connectTime=nil
local disconnectTime
local connectTimer
local disconnectTimer

if argCount>7 then
    deviceType=tonumber(arg[8])
    deviceSn=arg[9]
    
    connectTimer=CryptCore.NewTimer()
    connectTimer:Start()
    deviceObj=CryptCore.GetDevice(deviceType,deviceSn) 
    if not deviceObj then
        print(toANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
        os.exit(-1)
    end
    
    if argCount==10 then
        devicePwd=arg[10]
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
    
    
    if not deviceObj:IsSupportedAlgorithm{["algo"]=algo,["usage"]=usage,["keybits"]=keyBits,["tlen"]=tLen,["nonce"]=nonce,["adata"]=adata,["p"]=fileLength} then
        print(toANSIString("设备不支持AES CCM算法"))
        os.exit(-1)
    end
    
end

local fileTimer=CryptCore.NewTimer()
local cipherTimer=CryptCore.NewTimer()
local cipherObj
local fIn
local data



fileTimer:Start()
fIn=assert(io.open(fileName,"rb"))
data=fIn:read("*a")
fIn:close()
fileTimer:Stop()

if #data~=fileLength then
    print(toANSIString("读文件失败，长度不符"));
    os.exit(-1)
end

local records={}

for i=1,count do
    cipherTimer:Reset()
        
    cipherTimer:Start()
    cipherObj=assert(NewAesCcm(deviceObj,enc,key,nonce,tLen,adata,fileLength))
    assert(cipherObj:Cipher(data))
    cipherObj:Free()
    cipherTimer:Stop()
    
    records[i]=cipherTimer:Time()
end

if deviceObj then
    disconnectTimer=CryptCore.NewTimer()
    disconnectTimer:Start()
    
    deviceObj:Free()
    
    disconnectTimer:Stop()
    disconnectTime=disconnectTimer:Time()
end

sumTimer:Stop()
print(toANSIString(string.format("文件长度:%d字节",fileLength)))
local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒,速度:%.1fMB/s",time,fileLength*count/1024/1024/time*1000)))

if connectTime then
    print(toANSIString(string.format("设备连接时间:%.3f毫秒,断开时间:%.4f毫秒",connectTime,disconnectTime)))
end

local avgTime=GetAvgValue(records)
local minTime=GetMinValue(records)
local maxTime=GetMaxValue(records)

if enc then
    print(toANSIString(string.format("加密最大时间:%.1f毫秒,加密最小时间:%.1f毫秒,加密平均时间:%.1f毫秒,加密平均速度:%.1fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))
else
    print(toANSIString(string.format("解密最大时间:%.1f毫秒,解密最小时间:%.1f毫秒,解密平均时间:%.1f毫秒,解密平均速度:%.1fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))
end

time=fileTimer:Time()
print(toANSIString(string.format("读文件时间:%.1f毫秒",time)))

SaveTimeFile(records)
