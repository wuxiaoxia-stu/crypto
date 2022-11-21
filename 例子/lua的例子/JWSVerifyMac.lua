local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-compact] key jwsFileName payloadFileName [index]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-compact：使用JWS Compact Serialization，不存在则使用JWS JSON Serialization"))
    print(ToANSIString("\tkey：Hex编码的Key"))
    print(ToANSIString("\tjwsFileName：JWS文件名"))
    print(ToANSIString("\tpayloadFileName：载荷文件名"))
    print(ToANSIString("\tindex：索引值从0算起，默认为0"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWS验证MAC，载荷结果保存到payloadFileName文件中"))
end

function getMacAlgoName(macAlgo)
    if macAlgo== CryptCore.Const["HMAC-SHA-256"] then
        return "HS256"
    elseif macAlgo== CryptCore.Const["HMAC-SHA-384"] then
        return "HS384"
    elseif macAlgo== CryptCore.Const["HMAC-SHA-512"] then
        return "HS512"
    elseif macAlgo== CryptCore.Const["HMAC-SM3"] then
        return "HSM3"
    else
        return "unknown mac algo(" .. macAlgo ..")";
    end
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

function Save(fileName,data)
    local fOut=io.open(fileName,"wb")
    if fOut==nil then
        return false
    end
    fOut:write(data)
    fOut:close()    
    return true
end



if #arg~=3 and #arg~=4 and #arg~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local type=2
if arg[pos]=="-compact" or arg[pos]=="/compact" then
    type=1
    pos=pos+1
end

local hexKey=arg[pos]
pos=pos+1
local key=CryptCore.HexDecode(hexKey)
if not key then
    print(ToANSIString("MAC的密钥不是Hex编码"));
    os.exit(-1)
end

local jwsFileName=arg[pos]
pos=pos+1

local payloadFileName=arg[pos]
pos=pos+1

local index=0

if pos==#arg then
    index=tonumber(arg[pos])
end

local data=GetFileConetent(jwsFileName)
if data==nil then
    print(ToANSIString("读JWS文件失败"));
    os.exit(-1)
end

local jwsObj=CryptCore.DecodeJWS(type,data)
if jwsObj==nil then
    print(ToANSIString("JWS格式错误"));
    os.exit(-1)
end

local isDetached=jwsObj:IsDetached()
local payload
if isDetached then
    payload=GetFileConetent(payloadFileName)
    if payload==nil then
        jwsObj:Free()
        print(ToANSIString("读有效载荷文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetPayLoad(payload) then
        jwsObj:Free()
        print(ToANSIString("设置有效载荷失败"));
        os.exit(-1)
    end
else
    payload=jwsObj:GetPayLoad()
    if payload==nil then
        jwsObj:Free()
        print(ToANSIString("获取载荷失败"));
        os.exit(-1)
    end
end

local count=jwsObj:GetSignCount()
print(ToANSIString(string.format("一共有%d个JWS签名",count)))

local algo,isSign,param
local header
algo,isSign,param=jwsObj:GetAlgo(index)
if isSign then
    jwsObj:Free()
    print(ToANSIString(string.format("第%d个JWS签名不是MAC",index+1)))
    os.exit(-1)
end
print(ToANSIString(string.format("第%d个JWS签名的Mac算法为:%s",index+1,getMacAlgoName(algo))))
header=jwsObj:GetProtectedHeader(index)
if header==nil or #header==0 then
    print(ToANSIString(string.format("第%d个JWS签名没有保护头",index+1)))
else
    print(ToANSIString(string.format("第%d个JWS签名的保护头为:\n%s",index+1,header)))
end
    
if type==2 then
    header=jwsObj:GetUnprotectedHeader(index)
    if header==nil or #header==0 then
        print(ToANSIString(string.format("第%d个JWS签名没有不保护头",index+1)))
    else
        print(ToANSIString(string.format("第%d个JWS签名的不保护头为:\n%s",index+1,header)))
    end
end
    
if jwsObj:VerifyMac(index,key) then
    print(ToANSIString(string.format("验证第%d个JWS的MAC成功",index+1)))
else
    print(ToANSIString(string.format("验证第%d个JWS的MAC失败",index+1)))
end

jwsObj:Free()
if isDetached==false then
    if Save(payloadFileName,payload)==false then
        print(ToANSIString("保存文件失败"));
        os.exit(-1)
    end
end


