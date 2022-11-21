local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-nest] macAlgo key protectedheaderFileName outFileName innerJWTFileName|claimName1 claimValue1 ... claimNameN claimValueN",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-nest：使用嵌套的JWT"))
    print(ToANSIString("\tmacAlgo：MAC算法，比如:HMAC-SHA-256之类"))
    print(ToANSIString("\tkey：Hex编码的Key"))
    print(ToANSIString("\tprotectedheaderFileName：输入保护头文件名，\"\"为不存在附加的保护头信息"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tinnerJWTFileName：输入的JWT文件名"))
    print(ToANSIString("\tclaimName1：输入的claim名"))
    print(ToANSIString("\tclaimValue1：输入的claim值"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWT的MAC运算，结果保存到outFileName文件中"))
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



if #arg<6 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local isNest=false
if arg[pos]=="-nest" or arg[pos]=="/nest" then
    pos=pos+1
    isNest=true
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


local outFileName=arg[pos]
pos=pos+1

local jwtObj=CryptCore.NewJWT(1)
if jwtObj==nil then
    print(ToANSIString("创建JWT签名对象失败"));
    os.exit(-1)
end
if isNest then
    if pos~=#arg then
        Usage(arg[0])
        os.exit(-1)
    end
    local data=GetFileConetent(arg[pos])
    if data==nil then
        jwtObj:Free()
        print(ToANSIString("读内部JWT文件失败"));
        os.exit(-1)
    end
    local innerJwtObj=CryptCore.DecodeJWT(data)
    if innerJwtObj==nil then
        jwtObj:Free()
        print(ToANSIString("内部JWT文件不是JWT格式"));
        os.exit(-1)
    end
    
    if not jwtObj:SetNestedJWT(innerJwtObj) then
        jwtObj:Free()
        innerJwtObj:Free()
        print(ToANSIString("SetNestedJWT失败"));
        os.exit(-1)
    end
    innerJwtObj:Free()
else
    if pos==#arg then
        Usage(arg[0])
        os.exit(-1)
    end
    if (#arg-pos)%2~=1 then
        Usage(arg[0])
        os.exit(-1)
    end
    
    for i=pos,#arg,2 do
        if not jwtObj:SetClaim(arg[i],arg[i+1]) then
            jwtObj:Free()
            print(ToANSIString("SetClaim失败"));
            os.exit(-1)
        end
    end
end

local header
if protectedheaderFileName~="" then
    header=GetFileConetent(protectedheaderFileName)
    if header==nil then
        jwtObj:Free();
        print(ToANSIString("读保护头文件失败"));
        os.exit(-1)
    end
    if not jwtObj:SetAdditionalProtectedHeader(header) then
        jwtObj:Free();
        print(ToANSIString("设置保护头文件失败"));
        os.exit(-1)
    end
end

local signValue=jwtObj:Mac(algo,key)
jwtObj:Free()
if signValue==nil then
    print(ToANSIString("MAC失败"));
    os.exit(-1)
end

if Save(outFileName,signValue)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("MAC成功"));


