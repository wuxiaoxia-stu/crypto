local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s cert inFileName outFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\tinFileName：输入文件名，要加密的文件，文件必须很小"))
    print(ToANSIString("\toutFileName：输出文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t对inFileName文件加密，结果保存到outFileName文件中"))
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


function GetEncryptAlgo(certObj)
    if certObj:Match("Algorithm='RSA'") then
        return CryptCore.Const.RSA_PKCS1_V1_5_ENC
    elseif certObj:Match("Algorithm='SM2'") then
        return CryptCore.Const.SM2_ENC
    else
        return -1
    end
end


if #arg~=3 then
    Usage(arg[0])
    os.exit(-1)
end

local cert=GetFileConetent(arg[1])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

local certObj=CryptCore.NewCert(cert)
if certObj==nil then
    print(ToANSIString("不是证书文件"));
    os.exit(-1)
end

if certObj:InValidity()==false then
    certObj:Free()
    print(ToANSIString("证书不在有效期内"));
    os.exit(-1)
end

if certObj:Match("CertType='Encrypt'")==false then
    certObj:Free()
    print(ToANSIString("不是加密证书"));
    os.exit(-1)
end

local algo
algo=GetEncryptAlgo(certObj)
if algo==-1 then
    certObj:Free()
    print(ToANSIString("不支持的证书类型"));
    os.exit(-1)
end

local inFileName=arg[2]
local outFileName=arg[3]

local inData=GetFileConetent(inFileName)
if inData==nil then
    certObj:Free()
    print(ToANSIString("读输入文件失败"));
    os.exit(-1)
end

local publicKey=assert(certObj:PublicKey())
certObj:Free()

local outData
if algo==CryptCore.Const.SM2_ENC then
    outData=publicKey:Encrypt{ ["algo"]=algo,["clear"]=inData,["der"]=true }
else
    outData=publicKey:Encrypt{ ["algo"]=algo,["clear"]=inData }
end
publicKey:Free()
if outData==nil then
    print(ToANSIString("加密失败"));
    os.exit(-1)
end

if Save(outFileName,outData)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("加密成功"));


