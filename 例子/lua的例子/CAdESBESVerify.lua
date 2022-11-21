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

local hasSigningCertAttribute=sign:HasSigningCertAttribute(0)
local hashAlgo=sign:GetSigningCertV2HashAlgorithm(0)
if hasSigningCertAttribute or hashAlgo~=-1 then
    print(ToANSIString("是CAdES-BES"))
else
    print(ToANSIString("不是CAdES-BES"))
end

sign:Free()


