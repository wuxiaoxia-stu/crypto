local CryptCore=require("CryptCore")

local function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

local function g(m,n,e,b)
    local q,r=m:Div(n)
    local t=(q+1)*n
    if t:Compare(b)>0 then
        return m,false
    else
        return q*n+r:ExpMod(e,n),true
    end
end

local function ginv(v,n,keypair,b)
    local q,rinv=v:Div(n)
    local t=(q+1)*n
    if t:Compare(b)>0 then
        return v,false
    else
        local nLen=(n:Bits()+7)/8
        local rinvData=CryptCore.HexDecode(rinv:Encode(nLen))
        local r=keypair:Decrypt{
            ["algo"]=0x30,
            ["cipher"]=rinvData
        }
        if r==nil then
            return nil
        end
        local rBN=CryptCore.NewBigInteger(CryptCore.HexEncode(r),16)
        return q*n+rBN,true
    end
end

local function hash(m)
    local hashObj=CryptCore.NewHash(0x4000)
    hashObj:Update(m)
    local hashValue=hashObj:Final()
    hashObj:Free()
    return hashValue
end

local function maxbits(certs)
    local max=0
    local bits
    for _,cert in ipairs(certs) do
        bits=cert:GetPublicKeyBits()
        if bits>max then
            max=bits
        end
    end
    return max
end

local function getb(certs)
    local max=maxbits(certs)
    if max<=1024 then
        return 160,CryptCore.NewBigInteger("01"..string.rep("00",160),16)
    elseif max<=2048 then
        return 288,CryptCore.NewBigInteger("01"..string.rep("00",288),16)
    elseif max<=4096 then
        return 544,CryptCore.NewBigInteger("01"..string.rep("00",544),16)
    elseif max<=8192 then
        return 1056,CryptCore.NewBigInteger("01"..string.rep("00",1056),16)
    else
        return nil
    end
end


local function encrypt(key,clear)
    local cipherObj=CryptCore.NewECBCipher(true,CryptCore.Const.AES_ECB,key,CryptCore.Const.PADDING_NONE)
    local data1=cipherObj:Update(clear)
    local data2=cipherObj:Final()
    cipherObj:Free()
    return data1 .. data2
end

local function decrypt(key,cipher)
    local cipherObj=CryptCore.NewECBCipher(false,CryptCore.Const.AES_ECB,key,CryptCore.Const.PADDING_NONE)
    local data1=cipherObj:Update(cipher)
    local data2=cipherObj:Final()
    cipherObj:Free()
    return data1 .. data2
end

local function yr(key,v,s,yArray,len)
    local count=#yArray
    local prev=v
    local clear
    for i=1,s-1 do
        y=CryptCore.HexDecode(yArray[i]:Encode(len))
        clear=CryptCore.Xor(prev,y)
        prev=encrypt(key,clear)
    end
    
    local post=v
    for i=count,s+1 do
        clear=decrypt(key,post)
        y=CryptCore.HexDecode(yArray[i]:Encode(len))
        post=CryptCore.Xor(clear,y)
    end
    
    clear=decrypt(key,post)
    return CryptCore.NewBigInteger(CryptCore.HexEncode(CryptCore.Xor(clear,prev)),16)
end



local function getne(cert)
    local publicKey=cert:PublicKey()
    local encode=publicKey:Encode()
    publicKey:Free()
    local n,e= CryptCore.RSAPublicKeyDecode(encode)
    if n==nil then
        return n
    end
    return CryptCore.NewBigInteger(CryptCore.HexEncode(n),16),CryptCore.NewBigInteger(CryptCore.HexEncode(e),16)
end

local function try_ringsign(deviceObj,key,v,s,keypair,nArray,eArray,len,b)
    local xArray={}
    local yArray={}
    local count=#nArray
    local x
    local number
    local y
    local success
    for i=1,count do
        if i~=s then
            x=deviceObj:GenerateRandom(len)
            xArray[i]=x
            number=CryptCore.NewBigInteger(CryptCore.HexEncode(x),16)
            y,success=g(number,nArray[i],eArray[i],b)
            if not success then
                return success
            end
            yArray[i]=y
        else
            yArray[i]=0
        end
    end
    
    y=yr(key,v,s,yArray,len)
    x,success=ginv(y,nArray[s],keypair,b)
    if not success then
        return success
    end
    if x==nil then
        return nil
    end
    xArray[s]=CryptCore.HexDecode(x:Encode(len))
    return xArray
end

local function ringsign(rsaCerts,m,s)
    local count=#rsaCerts
    if s<=0 or s>count then
        return nil,ToANSIString("索引号超出范围")
    end
    
    for i,cert in ipairs(rsaCerts) do
        if not cert:Match("Algorithm='RSA'") then
            return nil,ToANSIString("第"..i.."个证书不是RSA证书")
        end
    end
    
    local len,b=getb(rsaCerts)
    if len==nil then
        return nil,ToANSIString("证书公钥太长不支持")
    end
    
    local n
    local e
    local nArray={}
    local eArray={}
    
    for i,cert in ipairs(rsaCerts) do
        n,e=getne(cert)
        if n==nil or e==nil then
            return nil,ToANSIString("证书公钥的n，e失败")
        end
        nArray[i]=n
        eArray[i]=e
    end
    
    
    local keypair=rsaCerts[s]:GetPrivateKey(0x10000000,1)
    if keypair==nil then
        return nil,ToANSIString("第"..s.."个证书没有对应的私钥")
    end
    
    local deviceObj=keypair:Device()
    if not deviceObj:IsSupportedAlgorithm{["algo"]=0x30,["usage"]="decrypt",["keybits"]=rsaCerts[s]:GetPublicKeyBits()} then
        deviceObj:Free()
        keypair:Free()
        return nil,ToANSIString("不支持RSA不填充的解密")
    end
    deviceObj:Free()
    
    local key=hash(m)
    local xArray
    local deviceObj=CryptCore.NewDevice()
    local v
    while true do
        v=deviceObj:GenerateRandom(len)
        xArray=try_ringsign(deviceObj,key,v,s,keypair,nArray,eArray,len,b)
        if xArray then
            deviceObj:Free()
            keypair:Free()
            return v,xArray
        elseif xArray==nil then
            deviceObj:Free()
            keypair:Free()
            return nil,ToANSIString("产生环签名失败")
        end
    end
end




local function ckv(key,v,yArray,len)
    local count=#yArray
    local prev=v
    local clear
    for i=1,count do
        y=CryptCore.HexDecode(yArray[i]:Encode(len))
        clear=CryptCore.Xor(prev,y)
        prev=encrypt(key,clear)
    end
    return prev
end

local function ringverify(rsaCerts,m,v,xArray)
    local count=#rsaCerts
    if #xArray~=count then
        return nil,ToANSIString("证书个数和x的个数不一样")
    end
    
    for i,cert in ipairs(rsaCerts) do
        if not cert:Match("Algorithm='RSA'") then
            return nil,ToANSIString("第"..i.."个证书不是RSA证书")
        end
    end
    
    local len,b=getb(rsaCerts)
    if len==nil then
        return nil,ToANSIString("证书公钥太长不支持")
    end
    
    for i,x in ipairs(xArray) do
        if #x~=len then
            return nil,ToANSIString("第"..i.."个x的长度不符")
        end
        
    end
    
    local n
    local e
    local nArray={}
    local eArray={}
    
    for i,cert in ipairs(rsaCerts) do
        n,e=getne(cert)
        if n==nil or e==nil then
            return nil,ToANSIString("证书公钥的n，e失败")
        end
        nArray[i]=n
        eArray[i]=e
    end
    
    local yArray={}
    local y
    local number
    for i,x in ipairs(xArray) do
        number=CryptCore.NewBigInteger(CryptCore.HexEncode(x),16)
        y=g(number,nArray[i],eArray[i],b)
        yArray[i]=y
    end
    
    local key=hash(m)
    
    local z=ckv(key,v,yArray,len)
    if v==z then
        return true
    else
        return false
    end
end


local function GetFileConetent(fileName)
    local fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end
    local data=fIn:read("*a")
    fIn:close()
    
    return data
end

local function GetCert(fileName)
    local data=GetFileConetent(fileName)
    if data==nil then
        return nil
    end
    return CryptCore.NewCert(data)
end

local function test()
    local certFileNames={
        "..\\user.cer",
        "..\\zm_enc.cer",
        "..\\zm_sign.cer",
    }
    local certs={}
    
    for i,fileName in ipairs(certFileNames) do
        certs[i]=assert(GetCert(fileName))
    end
    
    local m="你好"
    local s=2
    local v,xArray=assert(ringsign(certs,m,s))
    print("v:"..CryptCore.HexEncode(v))
    print(#xArray)
    for i,x in ipairs(xArray) do
        print("x("..i.."):"..CryptCore.HexEncode(x))
    end
    
    print(ringverify(certs,m,v,xArray))
end

test()

