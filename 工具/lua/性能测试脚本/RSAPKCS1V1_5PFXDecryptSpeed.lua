local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(scriptName)
    print(string.format("lua %s pfxFileName count [pwd]",scriptName))
    print(toANSIString("参数"))
    print(toANSIString("\tpfxFileName：PFX文件名"))
    print(toANSIString("\tcount：重复执行的次数"))
    print(toANSIString("\tpwd：使用PFX的密码"))
    print(toANSIString("说明"))
    print(toANSIString("\t使用PFX文件里的第一张证书对应的私钥进行PKCS#1V1.5填充的RSA解密运算，重复执行count次。"))
    print(toANSIString("\t成功运行后产生RSAPKCS1V1_5PFXDecryptSpeed_YYYYMMDDhhmmss.csv文件，其中每行表示一次的运行结果，每一列是解密时间"))
    print(toANSIString("例子"))
    print(string.format("\tlua %s rsa.pfx 100 12345678",scriptName))
    print(toANSIString("\t使用rsa.pfx的第一张证书对应的私钥进行进行PKCS#1V1.5填充的RSA解密运算100次"))
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
    return string.format("RSAPKCS1V1_5PFXDecryptSpeed_%04d%02d%02d%02d%02d%02d.csv",
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

function GetFileConetent(fileName)
    local fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end
    local data=fIn:read("*a")
    fIn:close()
    
    return data
end

local argCount=#arg
if argCount~=3 and argCount~=2 then
    usage(arg[0])
    os.exit(-1)
end

local sumTimer=CryptCore.NewTimer()
sumTimer:Start()

local count=tonumber(arg[2])

local pfx=GetFileConetent(arg[1])
if pfx==nil then
    print(toANSIString("读文件失败"));
    os.exit(-1)
end


local pfxStore
if argCount==2 then
    pfxStore=CryptCore.LoadPFX(pfx)
else
    local pwd=arg[3]
    pfxStore=CryptCore.LoadPFX(pfx,CryptCore.ACPToUTF8(pwd))
end

if pfxStore==nil then
    print(toANSIString("PFX文件格式错误或者密码错误"));
    os.exit(-1)
end

local certs=pfxStore:GetCerts()
pfxStore:Close()

local certObj
for i=1,#certs do
    if certs[i]:HasPrivateKey() then
        certObj=certs[i]
        break
    end
end

if certObj==nil then
    print(toANSIString("PFX文件中没有带私钥的证书"));
    os.exit(-1)
end

local algo=certObj:GetPublicKeyAlgorithm()
if algo~=CryptCore.Const.RSA then
    certObj:Free()
    print(toANSIString("不是RSA证书"));
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
if publicKey==nil then
    certObj:Free()
    print(toANSIString("获取公钥失败"));
    os.exit(-1)
end

local keyBits=certObj:GetPublicKeyBits()

local deviceObj=CryptCore.NewDevice()
local keyLen=math.floor((keyBits+7)/8) 
local clearData= deviceObj:GenerateRandom(10)
deviceObj:Free()
deviceObj=nil
if clearData==nil then
    publicKey:Free()
    certObj:Free()
    print(toANSIString("产生随机数失败"));
    os.exit(-1)
end

local cipherData=assert(publicKey:Encrypt { ["algo"]=CryptCore.Const.RSA_PKCS1_V1_5_ENC,["clear"]=clearData })
publicKey:Free()

local keypairObj=certObj:GetPrivateKey(0,CryptCore.Const.CERT_PURPOSE_ENCRYPT)
certObj:Free()
if keypairObj==nil then
    print(toANSIString("获取私钥失败，没有对应的私钥或者密码错误"));
    os.exit(-1)
end

local cipherTimer=CryptCore.NewTimer()
local data

local records={}

for i=1,count do
    cipherTimer:Reset()
        
    cipherTimer:Start()
    data=assert(keypairObj:Decrypt { ["algo"]=CryptCore.Const.RSA_PKCS1_V1_5_ENC,["cipher"]=cipherData })
    cipherTimer:Stop()
    
    records[i]={cipherTimer:Time()}
end

keypairObj:Free()

sumTimer:Stop()
local time
time=sumTimer:Time()
print(toANSIString(string.format("总运行时间:%f毫秒",time)))

local avgTime=GetAvgValue(records,1)
local minTime=GetMinValue(records,1)
local maxTime=GetMaxValue(records,1)

print(toANSIString(string.format("解密最大时间:%.3f毫秒,解密最小时间:%.3f毫秒,解密平均时间:%.3f毫秒,解密平均速度:%.1fKB/s,每秒解密%.1f次",maxTime,minTime,avgTime,keyLen/1024/avgTime*1000,1000/avgTime)))

SaveTimeFile(records)
