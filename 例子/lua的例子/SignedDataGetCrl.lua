local CryptCore=require("CryptCore")
local Asn1=require("Asn1")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s signatureFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tsignatureFileName：SignedData文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t从SignedData文件中获取CRL和OCSP，保存为crl[n].crl和ocsp[n].ors"))
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

function IsCRL(data)
    if data:sub(1,1)=="0" then
        return true
    else
        return false
    end
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

local crls=sign:GetRevocationInfoChoices();
sign:Free()
if crls==nil then
    print(ToANSIString("没有CRL"))
    os.exit(-1)
end

if #crls==0 then
    print(ToANSIString("没有CRL"))
    os.exit(-1)
end

print(ToANSIString(string.format("有%d个作废信息",#crls)))
local fileName
for i=1,#crls do
    if IsCRL(crls[i]) then
        fileName=string.format("crl%d.crl",i)
        if not Save(fileName,crls[i]) then
            print(ToANSIString(string.format("保存CRL%d失败",i)))
        end
    else
        local seq=Asn1.Decode(crls[i]):GetImplicitObject("SEQUENCE").Value
        if seq[1].Value=="1.3.6.1.5.5.7.16.2" then
            fileName=string.format("ocsp%d.ors",i)
            if not Save(fileName,seq[2]:Encode()) then
                print(ToANSIString(string.format("保存OCSP%d失败",i)))
            end
        else
            fileName=string.format("OtherRevocationInfoFormat%d",i)
            if not Save(fileName,crls[i]) then
                print(ToANSIString(string.format("保存作废信息%d失败",i)))
            end
        end
    end
    
end



