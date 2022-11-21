local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(ToANSIString(string.format("lua %s deviceType deviceSn pwd rsa|sm2 bits keypairLabel keypairType signAlgo subject p10FileName",scriptName)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tdeviceType：设备类型，是个整数"))
    print(ToANSIString("\tdeviceSn：设备序列号"))
    print(ToANSIString("\tpwd：设备的用户密码"))
    print(ToANSIString("\trsa：要产生RSA密钥对"))
    print(ToANSIString("\tsm2：要产生SM2密钥对"))
    print(ToANSIString("\tbits：要产生的密钥位数"))
    print(ToANSIString("\tkeypairLabel：密钥对标签"))
    print(ToANSIString("\tkeypairType：密钥对类型，enc为加密，sign为签名"))
    print(ToANSIString("\tsignAlgo：签名算法，比如:SHA1WithRSA、SM3WithSM2之类"))
    print(ToANSIString("\tsubject：主体名，正序"))
    print(ToANSIString("\tp10FileName：证书请求文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t先产生密钥对，接着产生证书请求"))
end

function GetKeypairType(name)
    name=name:upper()
    if name=="ENC" or name=="ENCRYPT" then
        return CryptCore.Const.KEYPAIRTYPE_ENCRYPT
    elseif name=="SIGN" or name=="SIGNATURE" then
        return CryptCore.Const.KEYPAIRTYPE_SIGNATURE
    elseif name=="KEYAGREEMENT" then
        return CryptCore.Const.KEYPAIRTYPE_KEYAGREEMENT
    else
        return tonumber(name)
    end
end

function GetGenKeyPairAlgo(name)
    name=name:upper()
    if name=="RSA" then
        return CryptCore.Const.GENKEYPAIR_RSA
    elseif name=="SM2" then
        return CryptCore.Const.GENKEYPAIR_ECC,256,CryptCore.Const.ECC_CURVE_SM2
    elseif name=="P192" then
        return CryptCore.Const.GENKEYPAIR_ECC,192,CryptCore.Const.ECC_CURVE_P192
    elseif name=="P224" then
        return CryptCore.Const.GENKEYPAIR_ECC,224,CryptCore.Const.ECC_CURVE_P224
    elseif name=="P256" then
        return CryptCore.Const.GENKEYPAIR_ECC,256,CryptCore.Const.ECC_CURVE_P256
    elseif name=="P384" then
        return CryptCore.Const.GENKEYPAIR_ECC,384,CryptCore.Const.ECC_CURVE_P384
    elseif name=="P521" then
        return CryptCore.Const.GENKEYPAIR_ECC,521,CryptCore.Const.ECC_CURVE_P521
    elseif name=="BRAINPOOL_P192" then
        return CryptCore.Const.GENKEYPAIR_ECC,192,8
    elseif name=="BRAINPOOL_P224" then
        return CryptCore.Const.GENKEYPAIR_ECC,224,9
    elseif name=="BRAINPOOL_P256" then
        return CryptCore.Const.GENKEYPAIR_ECC,256,10
    elseif name=="BRAINPOOL_P320" then
        return CryptCore.Const.GENKEYPAIR_ECC,320,11
    elseif name=="BRAINPOOL_P384" then
        return CryptCore.Const.GENKEYPAIR_ECC,384,12
    elseif name=="BRAINPOOL_P512" then
        return CryptCore.Const.GENKEYPAIR_ECC,512,13
    elseif name=="FRP256V1" then
        return CryptCore.Const.GENKEYPAIR_ECC,256,14
    else
        return nil
    end
end

function GetSignAlgo(signAlgo)
    signAlgo=signAlgo:upper()
    if signAlgo== "SHA1WITHRSA" or hashAlgo=="SHA-1WITHRSA" or signAlgo== "SHA1WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA1WITHRSA
    elseif  signAlgo== "SHA224WITHRSA" or signAlgo== "SHA224WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA224WITHRSA
    elseif  signAlgo== "SHA256WITHRSA" or signAlgo== "SHA256WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA256WITHRSA
    elseif  signAlgo== "SHA384WITHRSA" or signAlgo== "SHA384WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA384WITHRSA
    elseif  signAlgo== "SHA512WITHRSA" or signAlgo== "SHA512WITHRSAENCRYPTION" then
        return CryptCore.Const.SHA512WITHRSA
    elseif  signAlgo== "MD5WITHRSA" or signAlgo== "MD5WITHRSAENCRYPTION" then
        return CryptCore.Const.MD5WITHRSA
    elseif  signAlgo== "SHA512/224WITHRSA" or signAlgo== "SHA512/224WITHRSAENCRYPTION" then
        return 34
    elseif  signAlgo== "SHA512/256WITHRSA" or signAlgo== "SHA512/256WITHRSAENCRYPTION" then
        return 35
    elseif  signAlgo== "SHA3-224WITHRSA" or signAlgo== "SHA3-224WITHRSAENCRYPTION" then
        return 36
    elseif  signAlgo== "SHA3-256WITHRSA" or signAlgo== "SHA3-256WITHRSAENCRYPTION" then
        return 37
    elseif  signAlgo== "SHA3-384WITHRSA" or signAlgo== "SHA3-384WITHRSAENCRYPTION" then
        return 38
    elseif  signAlgo== "SHA3-512WITHRSA" or signAlgo== "SHA3-512WITHRSAENCRYPTION" then
        return 39
    elseif  signAlgo== "SM3WITHSM2" then
        return CryptCore.Const.SM3WITHSM2
    elseif  signAlgo== "ECDSAWITHSHA1" then
        return CryptCore.Const.ECDSAWITHSHA1
    elseif  signAlgo== "ECDSAWITHSHA224" then
        return CryptCore.Const.ECDSAWITHSHA224
    elseif  signAlgo== "ECDSAWITHSHA256" then
        return CryptCore.Const.ECDSAWITHSHA256
    elseif  signAlgo== "ECDSAWITHSHA384" then
        return CryptCore.Const.ECDSAWITHSHA384
    elseif  signAlgo== "ECDSAWITHSHA512" then
        return CryptCore.Const.ECDSAWITHSHA512
    elseif  signAlgo== "ECDSAWITHSHA3-224" then
        return 40
    elseif  signAlgo== "ECDSAWITHSHA3-256" then
        return 41
    elseif  signAlgo== "ECDSAWITHSHA3-384" then
        return 42
    elseif  signAlgo== "ECDSAWITHSHA3-512" then
        return 43
    else
        return nil;
    end
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

local argCount=#arg
if argCount~=10 then
    Usage(arg[0])
    os.exit(-1)
end


local deviceType=tonumber(arg[1])
local deviceSn=arg[2]
local pwd=arg[3]
local algo,bits,curve=GetGenKeyPairAlgo(arg[4])
if algo==nil then
    Usage(arg[0])
    os.exit(-1)
end

if bits==nil then
    bits=tonumber(arg[5])
end

local label=arg[6]
local keypairType=GetKeypairType(arg[7])

local signAlgo=GetSignAlgo(arg[8])
if signAlgo==nil then
    Usage(arg[0])
    os.exit(-1)
end
local subject=arg[9]
local p10FileName=arg[10]

local deviceObj=nil

deviceObj=CryptCore.GetDevice(deviceType,deviceSn)
if not deviceObj then
    print(ToANSIString("根据设备类型和设备序列号获取设备失败,没有该设备"))
    os.exit(-1)
end
    
local result,retryNumer= deviceObj:VerifyPwd(pwd)
if result==false then
    if retryNumer==0 then
        print(ToANSIString("验证密码失败，设备已经锁死"))
    else
        print(ToANSIString(string.format("验证密码失败，还剩%d次重试机会",retryNumer)))
    end
    deviceObj:Free()
    os.exit(-1)
elseif result==nil then
    deviceObj:Free()
    print(ToANSIString("验证密码出错"))
    os.exit(-1)
end
    
local keypair=deviceObj:GenerateKeyPair {
    ["algo"]=algo,
    ["bits"]=bits,
    ["type"]=keypairType,
    ["label"]=label,
    ["curve"]=curve
}
deviceObj:Free()

if keypair==nil then
    if CryptCore.GetLastError()== -6 then
        print(ToANSIString("密钥对已经存在"))
    else
        print(ToANSIString("产生密钥对失败"))
    end
    os.exit(-1)
end

local certReqObj=assert(CryptCore.NewCertReq())

if not certReqObj:SetAttribute(CryptCore.Const.CERTREQ_SUBJECT,subject) then
    keypair:Free()
    certReqObj:Free()
    print(ToANSIString("设置主体失败"))
    os.exit(-1)
end

local p10=certReqObj:Sign(keypair,signAlgo)
keypair:Free()
certReqObj:Free()
if p10==nil then
    print(ToANSIString("产生证书请求失败"))
    os.exit(-1)
end

if Save(p10FileName,p10)==false then
    print(ToANSIString("保存文件失败"));
    os.exit(-1)
end

print(ToANSIString("产生证书请求成功"));
