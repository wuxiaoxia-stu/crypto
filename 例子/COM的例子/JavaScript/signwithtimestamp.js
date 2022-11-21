var NETCAPKI_ALGORITHM_SHA1WITHRSA	    =2;
var NETCAPKI_ALGORITHM_SHA256WITHRSA    =4;
var NETCAPKI_ALGORITHM_SHA512WITHRSA    =6;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var NETCAPKI_CMS_ENCODE_BASE64 = 2;
var NETCAPKI_CMS_ENCODE_BASE64_MULTILINE = 3;
var NETCAPKI_CMS_ENCODE_DER = 1;

var utilobj;
var certobj;
var sign1obj;
var sign2obj;
var tbs;
var signature;





utilobj=new ActiveXObject("NetcaPki.Utilities");
tbs=utilobj.Encode("123",NETCAPKI_CP_UTF8);

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Select("Signature");

sign1obj=new ActiveXObject("NetcaPki.SignedData");
if (sign1obj.SetSignCertificate(certobj, "", false) == false)
{
    WScript.Echo("设置签名证书失败");
    WScript.Quit (-1);
}
sign1obj.SetSignAlgorithm(-1, NETCAPKI_ALGORITHM_SHA1WITHRSA);

sign1obj.Detached = true;

signature = sign1obj.SignWithTSATimeStamp("https://classatsa.cnca.net/tsa.asp",tbs);
WScript.Echo("签名成功");

sign2obj=new ActiveXObject("NetcaPki.SignedData");
if (sign2obj.DetachedVerify(tbs, signature))
{
    WScript.Echo("验证签名成功");
    WScript.Echo(sign2obj.GetTSATimeStamp(-1));
}
else
{
   WScript.Echo("验证签名失败");
}
