local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-nest] cekAlgo kekAlgo key protectedheaderFileName outFileName innerJWTFileName|claimName1 claimValue1 ... claimNameN claimValueN",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-nest：使用嵌套的JWT"))
    print(ToANSIString("\tcekAlgo：加密内容的算法，比如:A128CBC-HS256、A128GCM之类"))
    print(ToANSIString("\tkekAlgo：加密CEK的算法，比如:A128KW、A128GCMKW之类"))
    print(ToANSIString("\tkey：Hex编码的Key"))
    print(ToANSIString("\tprotectedheaderFileName：输入保护头文件名，\"\"为不存在附加的保护头信息"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("\tinnerJWTFileName：输入的JWT文件名"))
    print(ToANSIString("\tclaimName1：输入的claim名"))
    print(ToANSIString("\tclaimValue1：输入的claim值"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行JWE的加密，结果保存到outFileName文件中"))
end

function getCEKAlgo(algo)
    algo=algo:upper()
    if algo== "A128CBC-HS256" then
        return 1
    elseif algo== "A192CBC-HS384" then
        return 2
    elseif algo== "A256CBC-HS512" then
        return 3
    elseif algo== "A128GCM" then
        return 4
    elseif algo== "A192GCM" then
        return 5
    elseif algo== "A256GCM" then
        return 6
    elseif algo== "SM4CBC-SM3" then
        return 7
    else
        return nil;
    end
end


function getKEKAlgo(algo)
    algo=algo:upper()
    if algo== "RSA1_5" then
        return 1
    elseif algo== "RSA-OAEP" then
        return 2
    elseif algo== "RSA-OAEP-256" then
        return 3
    elseif algo== "A128KW" then
        return 4
    elseif algo== "A192KW" then
        return 5
    elseif algo== "A256KW" then
        return 6
    elseif algo== "DIR" then
        return 7
    elseif algo== "ECDH-ES" then
        return 8
    elseif algo== "ECDH-ES+A128KW" then
        return 9
    elseif algo== "ECDH-ES+A192KW" then
        return 10
    elseif algo== "ECDH-ES+A256KW" then
        return 11
    elseif algo== "A128GCMKW" then
        return 12
    elseif algo== "A192GCMKW" then
        return 13
    elseif algo== "A256GCMKW" then
        return 14
    elseif algo== "PBES2-HS256+A128KW" then
        return 15
    elseif algo== "PBES2-HS384+A192KW" then
        return 16
    elseif algo== "PBES2-HS512+A256KW" then
        return 17
    elseif algo== "SM2_3" or algo== "SM2" then
        return 18
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



if #arg<7 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local isNest=false
if arg[pos]=="-nest" or arg[pos]=="/nest" then
    pos=pos+1
    isNest=true
end

local cekAlgo=getCEKAlgo(arg[pos])
if cekAlgo==nil then
    print(ToANSIString("不支持的CEK算法"));
    os.exit(-1)
end
pos=pos+1

local kekAlgo=getKEKAlgo(arg[pos])
if kekAlgo==nil then
    print(ToANSIString("不支持的KEK算法"));
    os.exit(-1)
end
pos=pos+1

local hexKey=arg[pos]
pos=pos+1

local key=CryptCore.HexDecode(hexKey)
if not key then
    print(ToANSIString("密钥不是Hex编码"));
    os.exit(-1)
end

local protectedheaderFileName=arg[pos]
pos=pos+1

local outFileName=arg[pos]
pos=pos+1

local jwtObj=CryptCore.NewJWT(2)
if jwtObj==nil then
    print(ToANSIString("创建JWT加密对象失败"));
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

local jwtValue=jwtObj:EncryptByKey(cekAlgo,kekAlgo,key)
jwtObj:Free()
if jwtValue==nil then
    print(ToANSIString("加密失败"));
    os.exit(-1)
end

if Save(outFileName,jwtValue)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("加密成功"));
