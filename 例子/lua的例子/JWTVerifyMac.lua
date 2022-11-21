local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s key jwtFileName [payloadFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tkey：Hex编码的Key"))
    print(ToANSIString("\tjwtFileName：JWT文件名"))
    print(ToANSIString("\tpayloadFileName：可选，输出载荷文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWT验证MAC，载荷结果保存到payloadFileName文件中"))
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



if #arg~=3 and #arg~=2 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local hexKey=arg[pos]
pos=pos+1
local key=CryptCore.HexDecode(hexKey)
if not key then
    print(ToANSIString("MAC的密钥不是Hex编码"));
    os.exit(-1)
end

local jwtFileName=arg[pos]
pos=pos+1

local payloadFileName=nil
if pos==#arg then
    payloadFileName=arg[pos]
    pos=pos+1
end

local data=GetFileConetent(jwtFileName)
if data==nil then
    print(ToANSIString("读JWT文件失败"));
    os.exit(-1)
end

local jwtObj=CryptCore.DecodeJWT(data)
if jwtObj==nil then
    print(ToANSIString("JWT格式错误"));
    os.exit(-1)
end

if jwtObj:GetType()~=1 then
    jwtObj:Free()
    print(ToANSIString("JWT不是JWS"));
    os.exit(-1)
end

if not jwtObj:VerifyMac(key) then
    jwtObj:Free()
    print(ToANSIString("验证JWT失败"));
    os.exit(-1)
end

if jwtObj:IsNestedJWT() then
    if payloadFileName~=nil then
        local innerJwtObj=assert(jwtObj:GetInnerJWT())
        if Save(payloadFileName,innerJwtObj:Encode())==false then
            jwtObj:Free()
            innerJwtObj:Free()
            print(ToANSIString("保存文件失败"));
            os.exit(-1)
        end
        innerJwtObj:Free()
    end
    jwtObj:Free()
    print(ToANSIString("验证JWT成功"));
    os.exit(-1)
end

local value
local names={
    "iss","sub","aud","exp","nbf","iat","jti"
}

for _,name in ipairs(names) do
    value=jwtObj:GetClaimValue(name)
    if value then
       print(ToANSIString(string.format("%s:%s",name,value)))
    else
        if CryptCore.GetLastError()==-7 then
            print(ToANSIString(string.format("%s不存在",name)))
        else
            print(ToANSIString(string.format("获取%s失败",name)))
        end
    end
end

if payloadFileName~=nil then
    value=assert(jwtObj:GetClaims())
    if Save(payloadFileName,value)==false then
        jwtObj:Free()
        print(ToANSIString("保存文件失败"));
        os.exit(-1)
    end
end

jwtObj:Free()
print(ToANSIString("验证JWT成功"))


