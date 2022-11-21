local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end


function Usage(filename)
    print(string.format("Usage: lua %s tbsFileName sealFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\ttbsFileName：原文的文件名"))
    print(ToANSIString("\tsealFileName：电子签章的文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证电子签章"))
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

function HashFile(hashObj,fileObj)
    local data
	local BLOCK_LEN=8192
	while (true) do
 		data=fileObj:read(BLOCK_LEN)
		if not data then
			break
		end

		hashObj:Update(data)
	end
    return hashObj:Final()
end


function GetHashLength(hashAlgo)
	if hashAlgo==0x1000 then
		return 16
	elseif hashAlgo==0x2000 then
		return 20
	elseif hashAlgo==0x3000 then
		return 28
	elseif hashAlgo==0x4000 then
		return 32
	elseif hashAlgo==0x5000 then
		return 48
	elseif hashAlgo==0x6000 then
		return 64
	elseif hashAlgo==0x7000 then
		return 32
	elseif hashAlgo==0x8000 then
		return 28
	elseif hashAlgo==0x9000 then
		return 32
	elseif hashAlgo==0xA000 then
		return 28
	elseif hashAlgo==0xB000 then
		return 32
	elseif hashAlgo==0xC000 then
		return 48
	elseif hashAlgo==0xD000 then
		return 64
	else
		return -1
	end
end

if #arg~=2 then
    Usage(arg[0])
    os.exit(-1)
end

local tbsFileName=arg[1]
local sealFileName=arg[2]
local sealEncode=GetFileConetent(sealFileName)
if sealEncode==nil then
    print(ToANSIString("读电子签章文件失败"));
    os.exit(-1)
end

local seal=CryptCore.NewSeal(sealEncode)
if seal==nil then
    print(ToANSIString("不是电子签章文件"));
    os.exit(-1)
end

local format=seal:GetFormat()
if format==CryptCore.Const["GB/T 38540"] then
    print(ToANSIString("符合GB/T 38540的电子签章"))
else
    print(ToANSIString("符合GM/T 0031的电子签章"))
end

print(ToANSIString("版本号：".. seal:GetVersion()))

local stamp=seal:GetStamp()
print(ToANSIString("电子印章版本号：".. stamp:GetVersion()))
print(ToANSIString("电子印章Vid：".. stamp:GetVid()))
print(ToANSIString("电子印章Id：".. stamp:GetId()))
print(ToANSIString("电子印章类型：".. stamp:GetType()))
print(ToANSIString("电子印章名称：".. stamp:GetName()))
local certListType=stamp:GetCertListType()
if certListType==CryptCore.Const.STAMP_CERTLIST_TYPE_CERT then
    local certs=stamp:GetCertList()
    for i,cert in ipairs(certs) do
        print(ToANSIString("电子印章证书"..i..":" ..cert:GetSubject()))
        cert:Free()
    end
else
    local certDigestList=stamp:GetCertDigestList()
    for i,certDigest in ipairs(certDigestList) do
        print(ToANSIString("电子印章证书"..i.."的杂凑类型:"..certDigest.type..",杂凑值:" ..CryptCore.HexEncode(certDigest.value)))
    end
end

print(ToANSIString("电子印章创建时间：".. stamp:GetCreateDate()))
print(ToANSIString("电子印章有效期开始时间：".. stamp:GetValidStart()))
print(ToANSIString("电子印章有效期结束时间：".. stamp:GetValidEnd()))

local pictureType,pictureData,pictureWidth,pictureHeigth=stamp:GetPicture()
print(ToANSIString("电子印章图片类型：".. pictureType))
print(ToANSIString("电子印章图片宽度：".. pictureWidth))
print(ToANSIString("电子印章图片高度：".. pictureHeigth))


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
            print(ToANSIString(string.format("电子印章关键扩展(%s)：%s", oid,CryptCore.HexEncode(extValue))))
        else
            print(ToANSIString(string.format("电子印章非关键扩展(%s)：%s", oid,CryptCore.HexEncode(extValue))))
        end
    end
else
    print(ToANSIString("电子印章没有扩展"))
end

local signCert=stamp:GetSignCert()
print(ToANSIString("电子印章制章人证书：".. signCert:GetSubject()))
signCert:Free()

print(ToANSIString("电子印章签名算法：".. stamp:GetSignAlgorithm()))
stamp:Free()

print(ToANSIString("签名时间：".. seal:GetTime()))

local hashValue=seal:GetDataHash()
local signAlgo=seal:GetSignAlgorithm()
local hashAlgo=CryptCore.GetHashAlgorithmFromSignAlgorithm(signAlgo)

if tbsFileName~="" then
	local fIn=io.open(tbsFileName,"rb")
	if fIn==nil then
		seal:Free()
		print(ToANSIString("打开原文文件失败"));
		os.exit(-1)
	end

	local hashObj=assert(CryptCore.NewHash(hashAlgo))
	local hashValue2=HashFile(hashObj,fIn)
	fIn:close()
	hashObj:Free()

	if hashValue~=hashValue2 then
		seal:Free()
		print(ToANSIString("原文的Hash验证失败"));
		os.exit(-1)
	end
else
	if GetHashLength(hashAlgo)~=#hashValue then
		seal:Free()
		print(ToANSIString("原文的Hash长度验证失败"));
		os.exit(-1)
	end
end
print(ToANSIString("原文属性：".. seal:GetProperty()))

exts=seal:GetExtension()
if #exts~=0 then
    local oid
    local critical
    local extValue
    for i,ext in ipairs(exts) do
        oid=ext[1]
        critical=ext[2]
        extValue=ext[3]
        if critical then
            print(ToANSIString(string.format("电子签章关键扩展(%s)：%s", oid,CryptCore.HexEncode(extValue))))
        else
            print(ToANSIString(string.format("电子签章非关键扩展(%s)：%s", oid,CryptCore.HexEncode(extValue))))
        end
    end
else
    print(ToANSIString("电子签章没有扩展"))
end

local signCert=seal:GetSignCert()
print(ToANSIString("签名证书：" ..signCert:GetSubject()))
signCert:Free()

print(ToANSIString("签名算法：".. signAlgo))

local tsaTime=nil

local hasTimeStamp=seal:HasTimeStamp()
if hasTimeStamp then
    if seal:VerifyTimeStamp() then
        print(ToANSIString("验证电子签章的时间戳成功"));
        local timeStampObj=assert(seal:GetTimeStamp())
        tsaTime=timeStampObj:GetTime()
        print(ToANSIString(string.format("时间戳时间：%s",tsaTime)))
        cert=assert(timeStampObj:GetTSACert())
        print(ToANSIString(string.format("时间戳证书:%s",cert:GetSubject())))
        cert:Free()
        timeStampObj:Free()
    else
        print(ToANSIString("验证电子签章的时间戳失败"));
    end
else
    print(ToANSIString("电子签章没有时间戳"))
end

if tsaTime then
    if seal:Verify(tsaTime) then
        print(ToANSIString("验证电子签章成功"));
    else
        print(ToANSIString("验证电子签章失败"));
    end
else 
    if seal:Verify() then
        print(ToANSIString("验证电子签章成功"));
    else
        print(ToANSIString("验证电子签章失败"));
    end
end

seal:Free()
