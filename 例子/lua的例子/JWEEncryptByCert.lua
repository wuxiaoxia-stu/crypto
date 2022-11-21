local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s [-compact] cekAlgo kekAlgo cert protectedheaderFileName sharedUnprotectedheaderFileName recipientUnprotectedheaderFileName aadFileName clearFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-compact：使用JWS Compact Serialization，不存在则使用JWS JSON Serialization"))
    print(ToANSIString("\tcekAlgo：加密内容的算法，比如:A128CBC-HS256、A128GCM之类"))
    print(ToANSIString("\tkekAlgo：加密CEK的算法，比如:RSA1_5、RSA-OAEP之类"))
    print(ToANSIString("\tcert：加密证书文件名"))
    print(ToANSIString("\tprotectedheaderFileName：输入保护头文件名，\"\"为不存在附加的保护头信息"))
    print(ToANSIString("\tsharedUnprotectedheaderFileName：输入共享不保护头文件名，\"\"为不存在共享不保护头信息"))
    print(ToANSIString("\trecipientUnprotectedheaderFileName：输入接收者不保护头文件名，\"\"为不存在接收者不保护头信息"))
    print(ToANSIString("\taadFileName：输入AAD文件名，\"\"为不存在AAD"))
    print(ToANSIString("\tclearFileName：输入明文文件名"))
    print(ToANSIString("\toutFileName：输出文件名"))
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



if #arg~=9 and #arg~=10 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local type=2
if #arg==10 then
    if arg[pos]=="-compact" or arg[pos]=="/compact" then
        type=1
        pos=pos+1
    else
        Usage(arg[0])
        os.exit(-1)
    end
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

local cert=GetFileConetent(arg[pos])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end
pos=pos+1

local certObj=CryptCore.NewCert(cert)
if certObj==nil then
    print(ToANSIString("不是证书文件"));
    os.exit(-1)
end

if certObj:Match("CertType='Encrypt' || CertType='KeyAgreement'")==false then
    certObj:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local protectedheaderFileName=arg[pos]
pos=pos+1

local sharedUnprotectedheaderFileName=arg[pos]
pos=pos+1

local recipientUnprotectedheaderFileName=arg[pos]
pos=pos+1

local aadFileName=arg[pos]
pos=pos+1

local clearFileName=arg[pos]
pos=pos+1

local outFileName=arg[pos]

local jweObj=CryptCore.NewJWE(type)
if jweObj==nil then
    certObj:Free()
    print(ToANSIString("创建JWE加密对象失败"));
    os.exit(-1)
end

assert(jweObj:SetContentEncAlgo(cekAlgo))

local certIdType=4
local header
if recipientUnprotectedheaderFileName~="" then
    header=GetFileConetent(recipientUnprotectedheaderFileName)
    if header==nil then
        certObj:Free()
        jweObj:Free();
        print(ToANSIString("读接收者不保护头文件失败"));
        os.exit(-1)
    end
    
    if not jweObj:AddCert(certObj,kekAlgo,certIdType,header) then
        jweObj:Free();
        certObj:Free()
        print(ToANSIString("添加证书失败"));
        os.exit(-1)
    end
else
    if not jweObj:AddCert(certObj,kekAlgo,certIdType) then
	--if not jweObj:AddCert(certObj,kekAlgo,certIdType,"",{PartyVInfo="abcd",PartyUInfo="1234abcd"}) then
        jweObj:Free();
        certObj:Free()
        print(ToANSIString("添加证书失败"));
        os.exit(-1)
    end
end
certObj:Free()

if protectedheaderFileName~="" then
    header=GetFileConetent(protectedheaderFileName)
    if header==nil then
        jweObj:Free();
        print(ToANSIString("读保护头文件失败"));
        os.exit(-1)
    end
    if not jweObj:SetAdditionalProtectedHeader(header) then
        jweObj:Free();
        print(ToANSIString("设置保护头文件失败"));
        os.exit(-1)
    end
end


if sharedUnprotectedheaderFileName~="" then
    header=GetFileConetent(sharedUnprotectedheaderFileName)
    if header==nil then
        jweObj:Free();
        print(ToANSIString("读共享不保护头文件失败"));
        os.exit(-1)
    end
    if not jweObj:SetSharedUnprotectedHeader(header) then
        jweObj:Free();
        print(ToANSIString("设置共享不保护头文件失败"));
        os.exit(-1)
    end
end

local aad
if aadFileName~="" then
    aad=GetFileConetent(aadFileName)
    if aad==nil then
        jweObj:Free();
        print(ToANSIString("读AAD文件失败"));
        os.exit(-1)
    end
    if not jweObj:SetAAD(aad) then
        jweObj:Free();
        print(ToANSIString("设置AAD失败"));
        os.exit(-1)
    end
end


local clear
clear=GetFileConetent(clearFileName)
if clear==nil then
    jweObj:Free();
    print(ToANSIString("读载荷文件失败"));
    os.exit(-1)
end

local jweData=jweObj:Encrypt(clear)
jweObj:Free()
if jweData==nil then
    print(ToANSIString("加密失败"));
    os.exit(-1)
end

if Save(outFileName,jweData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("加密成功"));


