var NETCAPKI_ALGORITHM_SHA1WITHRSA	    =2;
var NETCAPKI_ALGORITHM_SHA256WITHRSA    =4;
var NETCAPKI_ALGORITHM_SHA512WITHRSA    =6;
var NETCAPKI_ALGORITHM_SM3WITHSM2    =25;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var NETCAPKI_CMS_ENCODE_BASE64 = 2;
var NETCAPKI_CMS_ENCODE_BASE64_MULTILINE = 3;
var NETCAPKI_CMS_ENCODE_DER = 1;

var NETCAPKI_SIGNEDDATA_ATTRIBUTE_USE_SM2_Q7=23;
var NETCAPKI_SIGNEDDATA_ATTRIBUTE_USE_SM2SIGN_OID=24;

var utilobj;
var certobj;
var sign1obj;
var sign2obj;
var tbs;
var tbs2;
var argobj;
var fs;
var cert;
var signature;

argobj= WScript.Arguments;

if(argobj.length!=1)
{
	WScript.Echo("Usage: sm2signeddata.js cert");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(0));
fs=null;

utilobj=new ActiveXObject("NetcaPki.Utilities");
tbs=utilobj.Encode("123",NETCAPKI_CP_UTF8);

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

sign1obj=new ActiveXObject("NetcaPki.SignedData");
if (sign1obj.SetSignCertificate(certobj, "", false) == false)
{
    WScript.Echo("设置签名证书失败");
    WScript.Quit (-1);
}
sign1obj.SetSignAlgorithm(-1, NETCAPKI_ALGORITHM_SM3WITHSM2);

sign1obj.SetIntegerAttribute(NETCAPKI_SIGNEDDATA_ATTRIBUTE_USE_SM2_Q7,-1,1);
sign1obj.SetIntegerAttribute(NETCAPKI_SIGNEDDATA_ATTRIBUTE_USE_SM2SIGN_OID,1,1);

signature = sign1obj.Sign(tbs,NETCAPKI_CMS_ENCODE_BASE64_MULTILINE);
WScript.Echo("签名成功");
WScript.Echo(signature);

sign2obj=new ActiveXObject("NetcaPki.SignedData");
tbs2=sign2obj.Verify(signature)
if (utilobj.ByteArrayCompare(tbs,tbs2))
{
    WScript.Echo("验证签名成功");
}
else
{
   WScript.Echo("验证签名失败");
}
