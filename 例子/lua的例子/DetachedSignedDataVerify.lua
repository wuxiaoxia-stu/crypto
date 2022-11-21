local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s tbsFileName signatureFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\ttbsFileName：原文文件名"))
    print(ToANSIString("\tsignatureFileName：要验证的签名文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对不带原文的signatureFileName文件进行验证，原文为tbsFileName文件"))
end


local argCount=#arg
if argCount~=2 then
    Usage(arg[0])
    os.exit(-1)
end


local tbsFileName=arg[1]
local signFileName=arg[2]

local sign=assert(CryptCore.NewSignedData(false))


local data
local BLOCK_LEN=8192

local fSign=io.open(signFileName,"rb")
if fSign==nil then
    sign:Free()
    print(ToANSIString(string.format("打开签名文件(%s)失败",CryptCore.ACPToUTF8(signFileName))));
    os.exit(-1)
end
data=fSign:read("*a")
fSign:close()

local fIn=io.open(tbsFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开原文文件(%s)失败",CryptCore.ACPToUTF8(tbsFileName))));
    os.exit(-1)
end

if not sign:DetachedVerifyInit(data) then
    sign:Free()
    fIn:close()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    if not sign:DetachedVerifyUpdate(data) then
        sign:Free()
        fIn:close()
        print(ToANSIString("验证签名失败"))
        os.exit(-1)
    end
    
end

fIn:close()

if not sign:DetachedVerifyFinal() then
    sign:Free()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end

print(ToANSIString("验证签名成功"))

local SignerCount=sign:GetSignerCount()
print(ToANSIString(string.format("一共%d个签名",SignerCount)));

local cert
local counterSignCount;
for i=0,SignerCount-1 do
    print(ToANSIString(string.format("第%d个签名:",i+1)));
    cert=assert(sign:GetSignCert(i))
    print(ToANSIString(string.format("\t签名证书CN:%s",cert:GetSubjectCN())));
    cert:Free()
    
    if sign:HasSignatureTimeStamp(i) then
        if sign:VerifyTimeStamp(i) then
            print(ToANSIString(string.format("\t签名时间戳时间:%s",sign:GetStringAttribute(12,i))));
        else
            print(ToANSIString("\t验证签名时间戳失败"));
        end
    else
        print(ToANSIString(("\t没有签名时间戳")))
    end
    
    counterSignCount=sign:GetCounterSignatureCount(i)
    if counterSignCount>0 then
        print(ToANSIString(string.format("\t联署签名个数:%d",counterSignCount)))
        
        for j=0,counterSignCount-1 do
            if sign:VerifyCounterSign(i,j) then
                print(ToANSIString(string.format("\t验证第%d个联署签名成功",j+1)));
            else
                print(ToANSIString(string.format("\t验证第%d个联署签名失败",j+1)));
            end
        end
    else
        print(ToANSIString(("\t没有联署签名")))
    end
end

sign:Free()



