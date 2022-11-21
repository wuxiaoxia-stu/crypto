local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s certFileName inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：签名证书文件"))
    print(ToANSIString("\tinFileName：要进行签名的原文文件名"))
    print(ToANSIString("\toutFileName：签名得到的签名文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件进行带原文的SignedData签名运算，结果保存到outFileName文件中"))
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

local argCount=#arg
if argCount~=3 then
    Usage(arg[0])
    os.exit(-1)
end


local cert=GetCert(arg[1])

if cert==nil then
    print(ToANSIString("读文件失败或者不是证书文件"));
    os.exit(-1)
end

if cert:InValidity()==false then
    cert:Free()
    print(ToANSIString("证书不在有效期内"));
    os.exit(-1)
end

if cert:Match("CertType='Signature'")==false then
    cert:Free()
    print(ToANSIString("不是签名证书"));
    os.exit(-1)
end

if cert:Match("Algorithm='SM2'")==false then
    cert:Free()
    print(ToANSIString("不是SM2证书"));
    os.exit(-1)
end

local algo=CryptCore.Const.SM3WITHSM2

local inFileName=arg[2]
local outFileName=arg[3]

local sign=assert(CryptCore.NewSignedData(true))
assert(sign:SetSignCert(cert))
cert:Free()

assert(sign:SetDetached(false))
assert(sign:SetSignAlgorithm(algo,0))

assert(sign:SetUseSM2Q7(true,0))

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(inFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(inFileName))));
    os.exit(-1)
end

fOut=io.open(outFileName,"wb")
if fOut==nil then
    sign:Free()
    fIn:close()
    print(ToANSIString(string.format("打开输出文件(%s)失败",CryptCore.ACPToUTF8(outFileName))));
    os.exit(-1)
end

outData=sign:SignInit()
if not outData then
    sign:Free()
    fIn:close()
    fOut:close()
    print(ToANSIString("签名失败"))
    os.exit(-1)
end

fOut:write(outData)

while (true) do
 
    data=fIn:read(BLOCK_LEN)
    if not data then
        break
    end

    outData=sign:SignUpdate(data)
    if not outData then
        sign:Free()
        fIn:close()
        fOut:close()
        print(ToANSIString("签名失败"))
        os.exit(-1)
    end
    fOut:write(outData)
end

fIn:close()

outData=sign:SignFinal()
sign:Free()

if not outData then
    fOut:close()
    print(ToANSIString("签名失败"))
    os.exit(-1)
end

fOut:write(outData)
fOut:close()
print(ToANSIString("签名成功"))


