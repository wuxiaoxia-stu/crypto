local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-compact] macAlgo key protectedheaderFileName unprotectedheaderFileName payloadFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-compact：使用JWS Compact Serialization，不存在则使用JWS JSON Serialization"))
    print(ToANSIString("\tmacAlgo：MAC算法，比如:HMAC-SHA-256之类"))
    print(ToANSIString("\tkey：Hex编码的Key"))
    print(ToANSIString("\tprotectedheaderFileName：输入保护头文件名，\"\"为不存在附加的保护头信息"))
    print(ToANSIString("\tunprotectedheaderFileName：输入不保护头文件名，\"\"为不存在不保护头信息"))
    print(ToANSIString("\tpayloadFileName：输入载荷文件名，\"\"为不存在载荷"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWS的MAC运算，结果保存到outFileName文件中"))
end

function getMacAlgo(macAlgo)
    macAlgo=macAlgo:upper()
    if macAlgo== "HMAC-SHA-256" or macAlgo=="HMAC-SHA256" or macAlgo=="HS256" then
        return CryptCore.Const["HMAC-SHA-256"],32
    elseif macAlgo== "HMAC-SHA-384" or macAlgo=="HMAC-SHA384" or macAlgo=="HS384" then
        return CryptCore.Const["HMAC-SHA-384"],48
    elseif macAlgo== "HMAC-SHA-512" or macAlgo=="HMAC-SHA512"  or macAlgo=="HS512" then
        return CryptCore.Const["HMAC-SHA-512"],64
    elseif macAlgo== "HMAC-SM3" or macAlgo=="HSM3" then
        return CryptCore.Const["HMAC-SM3"],32
    else
        return nil;
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



if #arg~=6 and #arg~=7 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local type=2
if #arg==7 then
    if arg[pos]=="-compact" or arg[pos]=="/compact" then
        type=1
        pos=pos+1
    else
        Usage(arg[0])
        os.exit(-1)
    end
end

local algo,keyLen=getMacAlgo(arg[pos])
if algo==nil then
    print(ToANSIString("不支持的MAC算法"));
    os.exit(-1)
end
pos=pos+1

local hexKey=arg[pos]
pos=pos+1
if #hexKey<keyLen*2 then
    print(ToANSIString("MAC的密钥太短"));
    os.exit(-1)
end
local key=CryptCore.HexDecode(hexKey)
if not key then
    print(ToANSIString("MAC的密钥不是Hex编码"));
    os.exit(-1)
end

local protectedheaderFileName=arg[pos]
pos=pos+1

local unprotectedheaderFileName=arg[pos]
pos=pos+1

local payloadFileName=arg[pos]
pos=pos+1

local outFileName=arg[pos]

local jwsObj=CryptCore.NewJWS(type)
if jwsObj==nil then
    print(ToANSIString("创建JWS签名对象失败"));
    os.exit(-1)
end

local header
if protectedheaderFileName~="" then
    header=GetFileConetent(protectedheaderFileName)
    if header==nil then
        jwsObj:Free();
        print(ToANSIString("读保护头文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetAdditionalProtectedHeader(header) then
        jwsObj:Free();
        print(ToANSIString("设置保护头文件失败"));
        os.exit(-1)
    end
end

if unprotectedheaderFileName~="" then
    header=GetFileConetent(unprotectedheaderFileName)
    if header==nil then
        jwsObj:Free();
        print(ToANSIString("读不保护头文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetUnprotectedHeader(header) then
        jwsObj:Free();
        print(ToANSIString("设置不保护头文件失败"));
        os.exit(-1)
    end
end

local payload
if payloadFileName~="" then
    payload=GetFileConetent(payloadFileName)
    if payload==nil then
        jwsObj:Free();
        print(ToANSIString("读载荷文件失败"));
        os.exit(-1)
    end
    if not jwsObj:SetPayLoad(payload) then
        jwsObj:Free();
        print(ToANSIString("设置载荷文件失败"));
        os.exit(-1)
    end
end

local signValue=jwsObj:Mac(algo,key)
jwsObj:Free()
if signValue==nil then
    print(ToANSIString("MAC失败"));
    os.exit(-1)
end

if Save(outFileName,signValue)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("MAC成功"));


