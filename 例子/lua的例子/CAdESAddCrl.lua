local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s signFileName newSignFileName -crl crlFileName1 ... -crl crlFileNamen -ocsp ocspFileName1 ... -ocsp ocspFileNamen -cert certFileName1 ... -cert certFileNamen",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tsignFileName：SignedData文件名"))
    print(ToANSIString("\tnewSignFileName：生成的新SignedData文件名"))
    print(ToANSIString("\tcrlFileName1：第一个CRL文件"))
    print(ToANSIString("\tcrlFileNamen：第n个CRL文件"))
    print(ToANSIString("\tocspFileName1：第一个OCSP文件"))
    print(ToANSIString("\tocspFileNamen：第n个OCSP文件"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t在SignedData中添加证书、CRL和OCSP信息"))
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


local argCount=#arg
if argCount<2 or argCount%2~=0 then
    Usage(arg[0])
    os.exit(-1)
end

local signFileName=arg[1]
local newSignFileName=arg[2]


local sign=assert(CryptCore.NewSignedData(false))

local data
data=GetFileConetent(signFileName)
if not data then
    sign:Free()
    print(ToANSIString(string.format("读签名文件(%s)失败",CryptCore.ACPToUTF8(signFileName))));
    os.exit(-1)
end

assert(sign:SetVerifyLevel(0))
assert(sign:SetKeepTbs(true))

if not sign:Verify(data) then
    sign:Free()
    print(ToANSIString("解析SignedData失败"))
    os.exit(-1)
end

local hasCert
local hasCrl
local hasOcsp
local certObj
for i=3,argCount-1,2 do
    if arg[i]:upper()=="-CRL" then
        crl=GetFileConetent(arg[i+1])
        if not crl then
            sign:Free()
            print(ToANSIString("读CRL文件(%s)失败",CryptCore.ACPToUTF8(arg[i+1])));
            os.exit(-1)
        end
        assert(sign:AddCRL(crl))
        hasCrl=true
    elseif arg[i]:upper()=="-OCSP" then
        ocsp=GetFileConetent(arg[i+1])
        if not ocsp then
            sign:Free()
            print(ToANSIString("读OCSP文件(%s)失败",CryptCore.ACPToUTF8(arg[i])));
            os.exit(-1)
        end
        assert(sign:AddOCSP(ocsp,nil,1))
        hasOcsp=true
    elseif arg[i]:upper()=="-CERT" then
        cert=GetFileConetent(arg[i+1])
        if not cert then
            sign:Free()
            print(ToANSIString("读证书文件(%s)失败",CryptCore.ACPToUTF8(arg[i])));
            os.exit(-1)
        end
        certObj=assert(CryptCore.NewCert(cert))
        assert(sign:AddCert(certObj))
        hasCert=true
        certObj:Free()
    else
        sign:Free()
        print(ToANSIString("参数错误"))
        Usage(arg[0])
        os.exit(-1)
    end
end


local outData=sign:Encode()
sign:Free()
if not outData then
    print(ToANSIString("SignedData编码失败"))
    os.exit(-1)
end

if Save(newSignFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

if hasCert then
    print(ToANSIString("添加证书成功"))
elseif hasCrl then
    print(ToANSIString("添加CRL成功"))
elseif hasOcsp then
    print(ToANSIString("添加OCSP成功"))
end

