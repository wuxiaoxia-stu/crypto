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


var certobj;
var signobj;
var tbs;
var argobj;
var fs;
var cert;
var signature;
var pwd;
var tbs;

argobj= WScript.Arguments;

if(argobj.length!=3)
{
	WScript.Echo("Usage: signeddata2.js signeddata cert pwd");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
signature=fs.Read(argobj(0));
fs=null;


fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(1));
fs=null;

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

pwd=argobj(2);

signobj=new ActiveXObject("NetcaPki.SignedData");

tbs = signobj.Verify(signature, true);

if (signobj.SetSignCertificate(certobj, pwd, false) == false)
{
    WScript.Echo("设置签名证书失败");
    WScript.Quit (-1);
}

signobj.SetSignAlgorithm(-1, NETCAPKI_ALGORITHM_SHA1WITHRSA);

signature = signobj.CoSign();
WScript.Echo("签名成功");
