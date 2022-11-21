local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s pwd length hashAlgo salt iter count",scriptName))
    print(toANSIString("参数"))
	print(toANSIString("\tpwd：密码"))
	print(toANSIString("\tlength：输出的长度"))
    print(toANSIString("\thashAlgo：Hash算法，比如:SHA-1、SM3之类"))
	print(toANSIString("\tsalt：Hex编码的盐"))
    print(toANSIString("\titer：迭代次数"))
    print(toANSIString("说明"))
    print(toANSIString("\t进行PKCS#5 PBKDF2导出密钥，重复执行count次"))
    print(toANSIString("\t成功运行后产生PKCS5PBKDF2Speed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的KDF时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s password 20 SHA-1 ab 10 100",scriptName))
    print(toANSIString("\t进行PKCS#5 PBKDF2导出密钥运算100次"))    
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

function PKCS5KDF(pwd,length,hashalgo,salt,iter)
	return CryptCore.KDF { ["algo"]=CryptCore.Const.KDF_PKCS5_PBKDF2,
		data=pwd,["length"]=length,["hashalgo"]=hashalgo,
		["salt"]=salt,["iter"]=iter }
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
    return string.format("PKCS5PBKDF2Speed_%04d%02d%02d%02d%02d%02d.csv",
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

local argCount=#arg
if argCount~=6 then
    usage(arg[0])
    os.exit(-1)
end

local pwd=arg[1]
local length=tonumber(arg[2])
local hashAlgo=getHashAlgo(arg[3])
if not hashAlgo then
    print(toANSIString("未知Hash算法"));
    os.exit(-1)
end

local salt=arg[4]
if #salt~=0 then
	salt=CryptCore.HexDecode(salt)
	if salt==nil then
		print(toANSIString("salt不是Hex编码的"));
		os.exit(-1)
	end
end

local iter=tonumber(arg[5])
local count=tonumber(arg[6])

if count<=0 then
    usage(arg[0]);
    os.exit(-1)
end

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local kdfTimer=CryptCore.NewTimer()
local key

local records={}

for i=1,count do
    kdfTimer:Reset()
        
    kdfTimer:Start()
    key=assert(PKCS5KDF(pwd,length,hashAlgo,salt,iter))
    kdfTimer:Stop()
    
    records[i]={kdfTimer:Time()}
end

sumTimer:Stop()
print(toANSIString(string.format("导出的密钥值:%s",CryptCore.HexEncode(true,key))))
local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒",time)))

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)
print(toANSIString(string.format("KDF最大时间:%.3f毫秒,KDF最小时间:%.3f毫秒,KDF平均时间:%.3f毫秒,每秒%.2f次",maxTime,minTime,avgTime,1000/avgTime)))

SaveTimeFile(records)
