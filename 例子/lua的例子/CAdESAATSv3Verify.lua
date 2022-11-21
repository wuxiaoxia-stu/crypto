local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s tbsFileName signFileName [tsaCertFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\ttbsFileName：原文文件名"))
    print(ToANSIString("\tsignFileName：CAdES-A ATSv3文件名"))
    print(ToANSIString("\ttsaCertFileName：信任的时间戳证书文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证不带原文的CAdES-A ATSv3"))
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

function inHashTable(hashValue,hashValueTable)
    for _,hashValue2 in ipairs(hashValueTable) do
        if hashValue2==hashValue then
            return true
        end
    end
    return false
end
function inAttributeTableV2(hashAlgo,hashValueTable,attrEncode)
    local hashValue=CryptCore.HexEncode(true,CryptCore.Hash(hashAlgo,attrEncode))
    return inHashTable(hashValue,hashValueTable)
end

function inAttributeTableV3(hashAlgo,hashValueTable,attrEncode)
    local attrs=assert(CryptCore.DecodeAttributeForATSHashIndexV3(attrEncode))
    local hashValue
    for _,attr in ipairs(attrs) do
        hashValue=CryptCore.HexEncode(true,CryptCore.Hash(hashAlgo,attr))
        if not inHashTable(hashValue,hashValueTable) then
            return false
        end
    end
    return true
end

function inAttributeTable(isAtsHashIndexV3,hashAlgo,hashValueTable,attrEncode)
    if isAtsHashIndexV3 then
        return inAttributeTableV3(hashAlgo,hashValueTable,attrEncode)
    else
        return inAttributeTableV2(hashAlgo,hashValueTable,attrEncode)
    end
end

function CheckUnsignedAttr(isAtsHashIndexV3,atsHashIndex,unsignedAttrs,index)
    local json=assert(CryptCore.Json.Decode(atsHashIndex))
    local hashAlgo=assert(getHashAlgo(json[1]))
    local hashValueTable=json[4]
    local t
    local attrOid
    local attrValue
    for i=1,index do
        t=unsignedAttrs[i]
        attrOid=t["type"]
        if attrOid=="1.2.840.113549.1.9.16.2.14" or 
            attrOid=="1.2.840.113549.1.9.16.2.21" or
            attrOid=="1.2.840.113549.1.9.16.2.22" or
            attrOid=="1.2.840.113549.1.9.16.2.23" or
            attrOid=="1.2.840.113549.1.9.16.2.24" then
            if inAttributeTable(isAtsHashIndexV3,hashAlgo,hashValueTable,t["encode"])==false then
                return false
            end
        end
    end
    return true
end

local argCount=#arg
if argCount~=2 and argCount~=3 then
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

assert(sign:SetVerifyLevel(4))
assert(sign:SetUseSystemStoreForVerify(true))
--assert(sign:SetKeepTbs(true))

local tsaCert=nil
if argCount==3 then
    local tsaCertFileName=arg[3]
    local certData=GetFileConetent(tsaCertFileName)
    if certData==nil then
        sign:Free()
        print(ToANSIString(string.format("读时间戳证书文件(%s)失败",CryptCore.ACPToUTF8(tsaCertFileName))));
        os.exit(-1)
    end
    tsaCert=CryptCore.NewCert(certData)
    if tsaCert==nil then
        sign:Free()
        print(ToANSIString("不是证书文件"));
        os.exit(-1)
    end
    
    assert(CryptCore.AddTSACert(tsaCert))
end

local signedData=data

local fIn=io.open(tbsFileName,"rb")
if fIn==nil then
    sign:Free()
    print(ToANSIString(string.format("打开原文文件(%s)失败",CryptCore.ACPToUTF8(tbsFileName))));
    os.exit(-1)
end
data=fIn:read("*a")
fIn:close()

if not sign:DetachedVerify(data,signedData) then
    sign:Free()
    print(ToANSIString("验证签名失败"))
    os.exit(-1)
end

print(ToANSIString("验证签名成功"))

local hasSigningCertAttribute=sign:HasSigningCertAttribute(0)
local hashAlgo=sign:GetSigningCertV2HashAlgorithm(0)
if (not hasSigningCertAttribute) and hashAlgo==-1 then
    print(ToANSIString("不是CAdES-BES"))
    sign:Free()
    os.exit(-1)
end

if not sign:HasSignatureTimeStamp(0) then
    print(ToANSIString("不是CAdES-T"))
    sign:Free()
    os.exit(-1)
end

if not sign:VerifyTimeStamp(0) then
    print(ToANSIString("\t验证签名时间戳失败"));
    sign:Free()
    os.exit(-1)
end
print(ToANSIString(string.format("签名时间戳时间:%s",sign:GetStringAttribute(12,0))))

count=sign:GetArchiveTimestampV3Count(0)
if count<1 then
    print(ToANSIString("不是CAdES-A ATSv3"))
    sign:Free()
    os.exit(-1)
end

for i=1,count do
    if tsaCert==nil then
        timeStamp=sign:VerifyArchiveTimeStampV3(0,i-1)
    else
        timeStamp=sign:VerifyArchiveTimeStampV3(0,i-1,nil,tsaCert)
    end
    if timeStamp==nil then
        print(ToANSIString("验证CAdES-A ATSv3失败"))
        sign:Free()
        os.exit(-1)
    end
    print(ToANSIString(string.format("第%d个archiveTimestampV3时间:%s",i,timeStamp:GetTime())))
    timeStamp:Free()
    local result,isAtsHashIndexV3,index=sign:VerifyAtsHashIndex(0)
    if result~=1 then
        print(ToANSIString("ats-hash-index中的某项数据不存在"))
    else
        if type(index)~="number" or index<0 then
            print(ToANSIString("获取ats-hash-index的位置失败"))
        else
            local atsHashIndex=assert(sign:GetStringAttribute(65,0))
            local unsignedAttrs=assert(sign:GetUnsignedAttribute(0))
            if not CheckUnsignedAttr(isAtsHashIndexV3,atsHashIndex,unsignedAttrs,index) then
                print(ToANSIString("ats-hash-index没有覆盖完相关的属性"))
            end
        end
    end
end
print(ToANSIString("验证CAdES-A ATSv3成功"))
sign:Free()
