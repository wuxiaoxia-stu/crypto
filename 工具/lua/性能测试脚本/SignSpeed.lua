local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s signAlgo certFileName tbsFileName count pwd",scriptName))
    print(toANSIString("参数"))
    print(ToANSIString("\tsignAlgo：签名算法，比如:SHA1WithRSA、SM3WithSM2之类"))
    print(toANSIString("\tcertFileName：签名证书文件名"))
    print(toANSIString("\ttbsFileName：要签名的文件"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tpwd：使用证书签名需要的用户密码"))
    print(toANSIString("说明"))
    print(toANSIString("\t使用签名证书对应的私钥进行签名运算，重复执行count次。"))
    print(toANSIString("\t成功运行后产生SignSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，一行有两列，第一列是签名时间，第二列是读文件时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s SM3WithSM2 sm2.cer tbs.txt 100 12345678",scriptName))
    print(toANSIString("\t使用sm2.cer的私钥对tbs.txt进行签名运算100次"))
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
    return string.format("SignSpeed_%04d%02d%02d%02d%02d%02d.csv",
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

function GetCert(filename)
    local fIn=io.open(filename,"rb")
    if fIn==nil then
        return nil
    end
    local inData=fIn:read("*a")
    fIn:close()
    
    return CryptCore.NewCert(inData)
end

function GetSignAlgo(signAlgo)
    signAlgo=signAlgo:upper()
    if signAlgo== "SHA1WITHRSA" or hashAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA1WITHRSA
    elseif  signAlgo== "SHA224WITHRSA" or signAlgo== "SHA224WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA224WITHRSA
    elseif  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA256WITHRSA
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA384WITHRSA
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA512WITHRSA
    elseif  signAlgo== "MD5WITHRSA" or signAlgo== "MD5WITHRSAENCRYPTION" then
        return CryptCore.Const.MD5WITHRSA
    elseif  signAlgo== "SHA512/224WITHRSA" or signAlgo== "SHA512/224WITHRSAENCRYPTION" then
        return 34
    elseif  signAlgo== "SHA512/256WITHRSA" or signAlgo== "SHA512/256WITHRSAENCRYPTION" then
        return 35
    elseif  signAlgo== "SHA3-224WITHRSA" or signAlgo== "SHA3-224WITHRSAENCRYPTION" then
        return 36
    elseif  signAlgo== "SHA3-256WITHRSA" or signAlgo== "SHA3-256WITHRSAENCRYPTION" then
        return 37
    elseif  signAlgo== "SHA3-384WITHRSA" or signAlgo== "SHA3-384WITHRSAENCRYPTION" then
        return 38
    elseif  signAlgo== "SHA3-512WITHRSA" or signAlgo== "SHA3-512WITHRSAENCRYPTION" then
        return 39
    elseif  signAlgo== "SM3WITHSM2" then
        return CryptCore.Const.SM3WITHSM2
    else
        return nil;
    end
end

local argCount=#arg
if argCount~=5 then
    usage(arg[0])
    os.exit(-1)
end

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local algo
algo=GetSignAlgo(arg[1])
if algo==nil then
    certObj:Free()
    print(ToANSIString("不支持的签名算法"));
    os.exit(-1)
end

local fileName=arg[3]
local count=tonumber(arg[4])

local certObj=GetCert(arg[2])
if certObj==nil then
    print(toANSIString("读文件失败或者文件不是证书"));
    os.exit(-1)
end

local pwd=arg[5]

local ku=certObj:GetKeyUsage()
if CryptCore.BitAnd(ku,CryptCore.Const.KEYUSAGE_DIGITALSIGNATURE,CryptCore.Const.KEYUSAGE_NONREPUDIATION)~=0 then
    certObj:Free()
    print(toANSIString("不是签名证书"));
    os.exit(-1)
end

if not certObj:InValidity() then
    certObj:Free()
    print(toANSIString("证书不在有效期内"));
    os.exit(-1)
end

local keypairObj=certObj:GetPrivateKey(CryptCore.Const.SEARCH_KEYPAIR_FLAG_DEVICE,CryptCore.Const.CERT_PURPOSE_SIGN,pwd)
certObj:Free()
if keypairObj==nil then
    print(toANSIString("获取私钥失败，没有对应的私钥或者密码错误"));
    os.exit(-1)
end

local fileTimer=CryptCore.NewTimer()
local signTimer=CryptCore.NewTimer()
local signObj
local fIn
local data
local BLOCK_LEN=1024*1024
local records={}

for i=1,count do
    signTimer:Reset()
    fileTimer:Reset()
    
    signTimer:Start()
    signObj=assert(keypairObj:NewSign { ["algo"]=algo })
    signTimer:Stop()
    
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

        signTimer:Start()
        signObj:Update(data)
        signTimer:Stop()
    end
    
    fileTimer:Start()
    fIn:close()
    fileTimer:Stop()

    signTimer:Start()
    assert(signObj:Final())
    signObj:Free()
    signTimer:Stop()
    
    records[i]={signTimer:Time(),fileTimer:Time()}
end

keypairObj:Free()

local fileLength=CryptCore.GetFileLength(CryptCore.ACPToUTF8(fileName))
sumTimer:Stop()

print(toANSIString(string.format("文件长度:%d字节",fileLength)))

local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%.1f毫秒,速度:%.3fMB/s",time,fileLength*count/1024/1024/time*1000)))

--table.remove(records,1)

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)

print(toANSIString(string.format("签名最大时间:%.1f毫秒,签名最小时间:%.1f毫秒,签名平均时间:%.1f毫秒,签名平均速度:%.3fMB/s",maxTime,minTime,avgTime,fileLength/1024/1024/avgTime*1000)))

avgTime=GetAvgValue(records,2)
minTime=GetMinValue(records,2)
maxTime=GetMaxValue(records,2)
print(toANSIString(string.format("读文件最大时间:%.1f毫秒,读文件最小时间:%.1f毫秒,读文件平均时间:%.1f毫秒",maxTime,minTime,avgTime)))


SaveTimeFile(records)
