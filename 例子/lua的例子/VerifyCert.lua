local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
	print(ToANSIString(string.format("Usage: lua %s cert [flag]",filename)))
    print(ToANSIString("参数"))
    print(ToANSIString("\tcert：证书文件名"))
    print(ToANSIString("\tflag：验证的标识"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t验证证书"))
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

if #arg~=2 and #arg~=1 then
	Usage(arg[0])
    os.exit(-1)
end


local cert=GetCert(arg[1])
if cert==nil then
    print(ToANSIString("读证书文件失败"));
    os.exit(-1)
end

local flag
if #arg==1 then
    flag=CryptCore.BitOr(CryptCore.Const.CERT_VERIFYFLAG_VERIFY_REVOKE,
        CryptCore.Const.CERT_VERIFYFLAG_VERIFY_ONLINE,
        CryptCore.Const.CERT_VERIFYFLAG_VERIFY_OCSP,
        CryptCore.Const.CERT_VERIFYFLAG_VERIFY_CRL)
else
    flag=tonumber(arg[2])
end

local status,revokeInfo=cert:Verify(flag)
if status==nil then
    print(ToANSIString(string.format("证书验证出错，错误代码为%d",CryptCore.GetLastError())))
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
    print(ToANSIString(string.format("作废原因：%s，作废时间：%s",
        GetReasonString(revokeInfo:RevokedReason()),revokeInfo:RevokedTime())))
    revokeInfo:Free()
end
cert:Free()

