local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s stampFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tstampFileName：电子印章的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证stampFileName的电子印章"))
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

if #arg~=1 then
    Usage(arg[0])
    os.exit(-1)
end

local stampFileName=arg[1]
local stampEncode=GetFileConetent(stampFileName)
if stampEncode==nil then
    print(ToANSIString("读电子印章文件"));
    os.exit(-1)
end

local stamp=CryptCore.NewStamp(stampEncode)
if stamp==nil then
    print(ToANSIString("不是电子印章文件失败"));
    os.exit(-1)
end

local format=stamp:GetFormat()
if format==CryptCore.Const["GB/T 38540"] then
    print(ToANSIString("符合GB/T 38540的电子印章"))
else
    print(ToANSIString("符合GM/T 0031的电子印章"))
end

print(ToANSIString("版本号：".. stamp:GetVersion()))
print(ToANSIString("Vid：".. stamp:GetVid()))
print(ToANSIString("Id：".. stamp:GetId()))
print(ToANSIString("类型：".. stamp:GetType()))
print(ToANSIString("名称：".. stamp:GetName()))


local certListType=stamp:GetCertListType()
if certListType==CryptCore.Const.STAMP_CERTLIST_TYPE_CERT then
    local certs=stamp:GetCertList()
    for i,cert in ipairs(certs) do
        print(ToANSIString("证书"..i..":" ..cert:GetSubject()))
        cert:Free()
    end
else
    local certDigestList=stamp:GetCertDigestList()
    for i,certDigest in ipairs(certDigestList) do
        print(ToANSIString("证书"..i.."的杂凑类型:"..certDigest.type..",杂凑值:" ..CryptCore.HexEncode(certDigest.value)))
    end
end

print(ToANSIString("创建时间：".. stamp:GetCreateDate()))
print(ToANSIString("有效期开始时间：".. stamp:GetValidStart()))
print(ToANSIString("有效期结束时间：".. stamp:GetValidEnd()))

local pictureType,pictureData,pictureWidth,pictureHeigth=stamp:GetPicture()
print(ToANSIString("图片类型：".. pictureType))
print(ToANSIString("图片宽度：".. pictureWidth))
print(ToANSIString("图片高度：".. pictureHeigth))


local exts=stamp:GetExtension()
if #exts~=0 then
    local oid
    local critical
    local extValue
    for i,ext in ipairs(exts) do
        oid=ext[1]
        critical=ext[2]
        extValue=ext[3]
        if critical then
            print(ToANSIString(string.format("关键扩展(%s)：%s", oid,CryptCore.HexEncode(extValue))))
        else
            print(ToANSIString(string.format("非关键扩展(%s)：%s", oid,CryptCore.HexEncode(extValue))))
        end
    end
else
    print(ToANSIString("没有扩展"))
end

local signCert=stamp:GetSignCert()
print(ToANSIString("制章人证书：".. signCert:GetSubject()))
signCert:Free()

print(ToANSIString("签名算法：".. stamp:GetSignAlgorithm()))

if stamp:Verify() then
    print(ToANSIString("验证电子印章成功"))
else
    print(ToANSIString("验证电子印章失败"))
end

stamp:Free()
