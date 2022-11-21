local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end



function Usage(filename)
    print(string.format("Usage: lua %s -cert certFileName -rootCert rootCertFileName [-caCert caCertFileName -option option -param -param param -verifyTime verifyTime -ignoreExt extOid -crl crlFileName -ocsp ocspFileName -vaCert ocspCertFileName]",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcertFileName：要验证的证书文件名"))
    print(ToANSIString("\trootCertFileName：根证书文件名，可以多个，比如：-rootCert rootCertFileName1 -rootCert rootCertFileName2"))
    print(ToANSIString("\tcaCertFileName：CA证书文件名，可以多个，比如：-caCert caCertFileName1 -caCert caCertFileName2"))
    print(ToANSIString("\toption：验证选项，整数"))
    print(ToANSIString("\tparam：验证参数"))
    print(ToANSIString("\tverifyTime：验证的时间，格式为YYYYMMDDhhmmssZ"))
    print(ToANSIString("\textOid：验证时不验证的扩展OID，可以多个"))
    print(ToANSIString("\tcrlFileName：CRL文件名，可以多个"))
    print(ToANSIString("\tocspFileName：OCSP响应文件名，可以多个"))
    print(ToANSIString("\tocspCertFileName：OCSP证书文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证证书"))
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

function GetReasonString(reason)
    if reason==CryptCore.Const.CRL_REASON_UNSPECIFIED then
        return "未指定"
    elseif reason==CryptCore.Const.CRL_REASON_KEYCOMPROMISE then
        return "密钥泄露"
    elseif reason==CryptCore.Const.CRL_REASON_CACOMPROMISE then
        return "证书是CA证书，其密钥泄露"
    elseif reason==CryptCore.Const.CRL_REASON_AFFILIATIONCHANGED then
        return "附属关系改变"
    elseif reason==CryptCore.Const.CRL_REASON_SUPERSEDED then
        return "被取代"
    elseif reason==CryptCore.Const.CRL_REASON_CESSATIONOFOPERATION then
        return "停止操作"
    elseif reason==CryptCore.Const.CRL_REASON_CERTIFATEHOLD then
        return "挂失"
    else
        return string.format("未知的作废原因(%d)",reason)
    end
end

function FreeCerts(certs)
    for _,cert in ipairs(certs) do
        cert:Free()
    end
end

function FreeOcsps(ocsps)
    for _,ocsp in ipairs(ocsps) do
        if ocsp[2]~=nil then
            ocsp[2]:Free() 
        end
    end
end


local argCount=#arg
if argCount<4 or argCount%2~=0 then
    Usage(arg[0])
    os.exit(-1)
end

local cert=nil
local rootCerts={}
local caCerts={}
local crls={}
local option=0
local param=nil
local verifyTime=nil 
local ignoreExts={}
local ocsps={}

local data
local certObj
local i=1
while i<argCount do
    if arg[i]=="-cert" then
        data=GetFileConetent(arg[i+1])
        if data==nil then
            print(ToANSIString(string.format("读证书文件(%s)失败",arg[i+1])))
            os.exit(-1)
        end
        certObj=CryptCore.NewCert(data)
        if certObj==nil then
            print(ToANSIString(string.format("%s不是证书文件",arg[i+1])))
            os.exit(-1)
        end
        cert=certObj
        i=i+2
    elseif arg[i]=="-rootCert" then
        data=GetFileConetent(arg[i+1])
        if data==nil then
            print(ToANSIString(string.format("读根证书文件(%s)失败",arg[i+1])))
            os.exit(-1)
        end
        certObj=CryptCore.NewCert(data)
        if certObj==nil then
            print(ToANSIString(string.format("%s不是证书文件",arg[i+1])))
            os.exit(-1)
        end
        rootCerts[#rootCerts+1]=certObj
        i=i+2
    elseif arg[i]=="-caCert" then
        data=GetFileConetent(arg[i+1])
        if data==nil then
            print(ToANSIString(string.format("读CA证书文件(%s)失败",arg[i+1])))
            os.exit(-1)
        end
        certObj=CryptCore.NewCert(data)
        if certObj==nil then
            print(ToANSIString(string.format("%s不是证书文件",arg[i+1])))
            os.exit(-1)
        end
        caCerts[#caCerts+1]=certObj
        i=i+2
    elseif arg[i]=="-option" then
        option=tonumber(arg[i+1])
        i=i+2
    elseif arg[i]=="-param" then
        param=arg[i+1]
        i=i+2
    elseif arg[i]=="-verifyTime" then
        verifyTime=arg[i+1]
        i=i+2
    elseif arg[i]=="-ignoreExt" then
        ignoreExts[#ignoreExts+1]=arg[i+1]
        i=i+2
    elseif arg[i]=="-crl" then
        data=GetFileConetent(arg[i+1])
        if data==nil then
            print(ToANSIString(string.format("读CRL文件(%s)失败",arg[i+1])))
            os.exit(-1)
        end
        crls[#crls+1]=data
        i=i+2
    elseif arg[i]=="-ocsp" then
        local ocspResp=GetFileConetent(arg[i+1])
        if ocspResp==nil then
            print(ToANSIString(string.format("读OCSP文件(%s)失败",arg[i+1])))
            os.exit(-1)
        end
        if i+2< argCount and arg[i]=="-vaCert" then
            data=GetFileConetent(arg[i+3])
            if data==nil then
                print(ToANSIString(string.format("读OCSP证书文件(%s)失败",arg[i+3])))
                os.exit(-1)
            end
            certObj=CryptCore.NewCert(data)
            if certObj==nil then
                print(ToANSIString(string.format("%s不是证书文件",arg[i+3])))
                os.exit(-1)
            end
            ocsps[#ocsps+1]={ocspResp,certObj}
            i=i+4
        else
            ocsps[#ocsps+1]={ocspResp}
            i=i+2
        end
    else
        Usage(arg[0])
        os.exit(-1)
    end
end


if cert==nil then
    print(ToANSIString("没有要验证的证书文件"));
    os.exit(-1)
end

if #rootCerts==nil then
    print(ToANSIString("没有根证书文件"));
    os.exit(-1)
end

local certVerifyObj=assert(CryptCore.NewCertVerify())
for _,certObj in ipairs(rootCerts) do
    if not certVerifyObj:AddRootCert(certObj) then
        certVerifyObj:Free()
        FreeCerts(rootCerts)
        FreeCerts(caCerts)
        FreeOcsps(ocsps)
        cert:Free()
        print(ToANSIString("添加根证书失败"));
        os.exit(-1)
    end
end
FreeCerts(rootCerts)

for _,certObj in ipairs(caCerts) do
    if not certVerifyObj:AddCACert(certObj) then
        certVerifyObj:Free()
        FreeCerts(caCerts)
        cert:Free()
        FreeOcsps(ocsps)
        print(ToANSIString("添加CA证书失败"));
        os.exit(-1)
    end
end
FreeCerts(caCerts)

if not certVerifyObj:SetOption(option) then
    certVerifyObj:Free()
    cert:Free()
    FreeOcsps(ocsps)
    print(ToANSIString("设置证书选项失败"));
    os.exit(-1)
end

for _,crl in ipairs(crls) do
    if not certVerifyObj:AddCRL(crl) then
        certVerifyObj:Free()
        cert:Free()
        FreeOcsps(ocsps)
        print(ToANSIString("添加CRL失败"));
        os.exit(-1)
    end
end

for _,ocsp in ipairs(ocsps) do
    local ocspResp=ocsp[1]
    local b
    
    if #ocsp==1 then
        b=certVerifyObj:AddOCSP(ocspResp)
    else
        local ocspCert=ocsp[2]
        b=certVerifyObj:AddOCSP(ocspResp,ocspCert)
    end
    if not  b then
        certVerifyObj:Free()
        cert:Free()
        FreeOcsps(ocsps)
        print(ToANSIString("添加OCSP失败"));
        os.exit(-1)
    end
end
FreeOcsps(ocsps)

for _,ext in ipairs(ignoreExts) do
    if not certVerifyObj:AddIgnoreExtension(ext) then
        certVerifyObj:Free()
        cert:Free()
        print(ToANSIString("添加忽略的扩展失败"));
        os.exit(-1)
    end
end

if verifyTime~=nil then
    if not certVerifyObj:SetVerifyTime(verifyTime) then
        certVerifyObj:Free()
        cert:Free()
        print(ToANSIString("设置验证时间失败"));
        os.exit(-1)
    end
end

if param~=nil then
    if not certVerifyObj:SetParam(param) then
        certVerifyObj:Free()
        cert:Free()
        print(ToANSIString("设置验证参数失败"));
        os.exit(-1)
    end
end

local rv,status,revokeInfo=certVerifyObj:Verify(cert)
certVerifyObj:Free()
cert:Free()
if rv~=1 then
    print(ToANSIString(string.format("验证证书失败，错误号为%d",rv)))
elseif status==CryptCore.Const.CERT_STATUS_UNREVOKED then
    print(ToANSIString("证书未作废"))
elseif status==CryptCore.Const.CERT_STATUS_UNDETERMINED then 
    print(ToANSIString("证书状态不确定"))
else
    if status==CryptCore.Const.CERT_STATUS_REVOKED then 
        print(ToANSIString("证书已经作废"))
    else
        print(ToANSIString("证书的某个CA证书已经作废"))
    end
    print(ToANSIString(string.format("作废原因：%s，作废时间:%s",
        GetReasonString(revokeInfo:RevokedReason()),revokeInfo:RevokedTime())))
    revokeInfo:Free()
end

