local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s signatureFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tsignatureFileName：SignedData文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t从SignedData文件中获取证书，保存为cert[n].cer"))
end

function Save(fileName,data)
    local fOut=io.open(fileName,"wb")
    if fOut==nil then
        return false
    end
    fOut:write(data)
    fOut:close()    
    return true
end


local argCount=#arg
if argCount~=1 then
    Usage(arg[0])
    os.exit(-1)
end


local signFileName=arg[1]

local sign=assert(CryptCore.NewSignedData(false))
assert(sign:SetVerifyLevel(0))

local data
local BLOCK_LEN=8192
local outData

fIn=io.open(signFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开文件(%s)失败",CryptCore.ACPToUTF8(signFileName))));
    os.exit(-1)
end

outData=sign:VerifyInit()
if not outData then
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

    outData=sign:VerifyUpdate(data)
    if not outData then
        sign:Free()
        fIn:close()
        print(outData)
        print(ToANSIString("验证签名失败"))
        os.exit(-1)
    end
    
end

fIn:close()

outData=sign:VerifyFinal()
if not outData then
    sign:Free()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end

local certs=sign:GetCertificateSet();
sign:Free()
if certs==nil then
    print(ToANSIString("没有证书"))
    os.exit(-1)
end
print(ToANSIString(string.format("有%d张证书",#certs)))
local fileName
for i=1,#certs do
    fileName=string.format("cert%d.cer",i)
    if not Save(fileName,certs[i]) then
        print(ToANSIString(string.format("保存证书%d失败",i)))
    end
end




