local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s cert  [ocspUrl [vaCert]]",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\tocspUrl：OCSP服务器的URL"))
    print(ToANSIString("\tvaCert：OCSP证书的文件名,可选"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t使用OCSP验证证书是否作废"))
	os.exit(-1)
end

function GetCert(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return CryptCore.NewCert(inData)
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

local argCount=#arg
if argCount~=1 and argCount~=2 and argCount~=3 then
	Usage(arg[0])
    os.exit(-1)
end

local url=nil
local vaCert=nil

local cert=GetCert(arg[1])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

local status
local revokeInfo
if argCount==1 then
    status,revokeInfo=cert:VerifyByOCSP()
elseif argCount==2 then
    url=arg[2]
    status,revokeInfo=cert:VerifyByOCSP(url)
else
    url=arg[2]
    vaCert=GetCert(arg[3])
    if vaCert==nil then
        cert:Free()
        print(ToANSIString("读OCSP证书文件失败"));
        os.exit(-1)
    end
end

if status==nil then
    print(ToANSIString(string.format("验证出错，错误代码为%d",CryptCore.GetLastError())))
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
cert:Free()
if vaCert~=nil then
    vaCert:Free()
end
