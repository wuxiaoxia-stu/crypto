local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function ToUTF8String(str)
    return CryptCore.ACPToUTF8(str)
end

function Usage(filename)
    print(string.format("Usage: lua %s [-verbose] url subject publicKeyFileName p10FileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-verbose：输出中间过程"))
    print(ToANSIString("\turl：服务器的URL"))
    print(ToANSIString("\tsubject：证书请求的主体名"))
    print(ToANSIString("\tpublicKeyFileName：保存的公钥文件名"))
    print(ToANSIString("\tp10FileName：保存的P10文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t产生基于云计算的SM2证书请求"))
end

local n=assert(CryptCore.NewBigInteger(true,"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123"))
local p=assert(CryptCore.NewBigInteger(true,"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF"))
local Gx=assert(CryptCore.NewBigInteger(true,"32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7"))
local Gy=assert(CryptCore.NewBigInteger(true,"BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0"))

local G=assert(CryptCore.NewPoint("SM2",Gx,Gy))

function genrand()
    local device=assert(CryptCore.NewDevice())
    local value
    local bn
    while true do
        value=assert(device:GenerateRandom(32))
        bn=assert(CryptCore.NewBigInteger(true,CryptCore.HexEncode(value)))
        bn=assert(bn:Mod(n))
        if bn:Sign()~=0 then
            break
        end
    end
    return bn
end

function genkeypair(verbose,url)
    local d1=genrand()
    if verbose then
        print("d1:"..d1:Encode(32))
    end
    local d1Inv=d1:InvMod(n)
    
    if verbose then
        print("d1Inv:"..d1Inv:Encode(32))
    end
    
    local P1=assert(G:Mul(d1Inv))
    local x=P1:GetX()
    local y=P1:GetY()
    if verbose then
        print(ToANSIString("P1的x坐标:"..x:Encode(32)))
        print(ToANSIString("P1的y坐标:"..y:Encode(32)))
    end
    
    local t={["function"]="GenerateKeypair",
        ["arguement"]={
            ["P1"]={
                ["x"]=x:Encode(32),
                ["y"]=y:Encode(32),
            }
        }}
    local jsonData=CryptCore.Json.Encode(t)
    if verbose then
        print(ToANSIString(string.format("向服务器(%s)发送请求:\n%s",url,jsonData)))
    end
    
    local status,contentType,outData=CryptCore.HttpPost(url,jsonData,{})
    if status==nil then
        print(ToANSIString("向服务器发送产生密钥对请求失败"))
        return nil
    end
    if status<200 or status>=300 then
        print(ToANSIString(string.format("向服务器发送产生密钥对请求失败,服务器返回响应码:%s",status)))
        return nil
    end
    if verbose then
        print(ToANSIString(string.format("服务器返回的状态码:%d",status)))
        print(ToANSIString(string.format("服务器返回的响应:%s",outData)))
    end
    
    local jsonObj=CryptCore.Json.Decode(outData)
    local id=jsonObj["return"]["id"]
    local P=jsonObj["return"]["P"]
    x=P.x
    y=P.y
    if verbose then
        print(ToANSIString("公钥ID:"..id))
        print(ToANSIString("公钥P的x坐标:".. x))
        print(ToANSIString("公钥P的y坐标:".. y))
    end
    
    return d1,id,x,y
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

if #arg~=4 and #arg~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local verbose=false
if #arg==5 then
    if arg[pos]=="-verbose" or arg[pos]=="/verbose" then
        pos=pos+1
        verbose=true
    else
        Usage(arg[0])
        os.exit(-1)
    end
end
--local url="http://127.0.0.1:8080/test/SM2Server"
local url=arg[pos]
pos=pos+1
local subject=assert(ToUTF8String(arg[pos]))
pos=pos+1
local publicKeyFileName=arg[pos]
pos=pos+1
local p10FileName=arg[pos]
pos=pos+1
local d1,id,x,y=genkeypair(verbose,url)

local device=assert(CryptCore.NewDevice())
local encode=assert(CryptCore.ECCPublicKeyEncode(CryptCore.HexDecode(x),CryptCore.HexDecode(y)))
local publicKey=assert(device:ImportPublicKey(encode))
local spki=publicKey:GetSubjectPublicKeyInfoEncode()


function trySign(index,url,d1,e)
    if verbose then
        print(ToANSIString(string.format("第%d次尝试签名",index)))
    end
    local k1=genrand()
    if verbose then
        print("k1:"..k1:Encode(32))
    end
    
    local Q1=assert(G:Mul(k1))
    local x=Q1:GetX()
    local y=Q1:GetY()
    if verbose then
        print(ToANSIString("Q1的x坐标:"..x:Encode(32)))
        print(ToANSIString("Q1的y坐标:"..y:Encode(32)))
    end
    
    local t={["function"]="Sign",
        ["arguement"]={
            ["Q1"]={
                ["x"]=x:Encode(32),
                ["y"]=y:Encode(32),
            },
            ["id"]=id,
            ["e"]=CryptCore.HexEncode(e)
        }}
    local jsonData=CryptCore.Json.Encode(t)
    if verbose then
        print(ToANSIString(string.format("向服务器(%s)发送请求:\n%s",url,jsonData)))
    end
    
    local status,contentType,outData=CryptCore.HttpPost(url,jsonData,{})
    if status==nil then
        print(ToANSIString("向服务器发送签名请求失败"))
        return nil
    end
    if status<200 or status>=300 then
        print(ToANSIString(string.format("向服务器发送签名请求失败,服务器返回响应码:%s",status)))
        return nil
    end
    if verbose then
        print(ToANSIString(string.format("服务器返回的状态码:%d",status)))
        print(ToANSIString(string.format("服务器返回的响应:%s",outData)))
    end
    
    local jsonObj=CryptCore.Json.Decode(outData)
    local r=jsonObj["return"]["r"]
    local s2=jsonObj["return"]["s2"]
    local s3=jsonObj["return"]["s3"]
    if verbose then
        print("r:"..r)
        print("s2:"..s2)
        print("s3:"..s3)
    end
    
    
    r=CryptCore.NewBigInteger(true,r)
    s2=CryptCore.NewBigInteger(true,s2)
    s3=CryptCore.NewBigInteger(true,s3)
    local s=(d1*k1*s2+d1*s3-r)%n
    if verbose then
        print("s:"..s:Encode(32))
    end
    
    if s:Sign()==0 then
        if verbose then
            print(ToANSIString("s为0需要重试"))
        end
        return false
    end
    local n_r_s=n-r-s
    if n_r_s:Sign()==0 then
        if verbose then
            print(ToANSIString("s为n-r需要重试"))
        end
        return false
    end
    return r,s
end

function sign(url,d1,e)
    local index=1
    local r,s
    while(true) do
        r,s=trySign(index,url,d1,e)
        index=index+1
        if r==nil then
            return nil
        elseif r~=false then
            return r,s
        end
    end
end
function signHash(algo,param,hashValue)
    local r,s=sign(url,d1,hashValue)
    return assert(CryptCore.ECCSignatureEncode(
        CryptCore.HexDecode(r:Encode(32)),
        CryptCore.HexDecode(s:Encode(32))))
end

local certReqObj=assert(CryptCore.NewCertReq())

if not certReqObj:SetAttribute(CryptCore.Const.CERTREQ_SUBJECT,subject) then
    certReqObj:Free()
    print(ToANSIString("设置主体失败"))
    os.exit(-1)
end

local signAlgo=CryptCore.Const.SM3WITHSM2
local p10=certReqObj:Sign(spki,signAlgo,signHash)
certReqObj:Free()
if p10==nil then
    print(ToANSIString("产生证书请求失败"))
    os.exit(-1)
end

if Save(p10FileName,p10)==false then
    print(ToANSIString("保存P10文件失败"))
    os.exit(-1)
end

local t={["id"]=id,["d1"]=d1:Encode(32)}
local jsonData=CryptCore.Json.Encode(t)
if Save(publicKeyFileName,jsonData)==false then
    print(ToANSIString("保存公钥文件失败"))
    os.exit(-1)
end
print(ToANSIString("产生证书请求成功"))




