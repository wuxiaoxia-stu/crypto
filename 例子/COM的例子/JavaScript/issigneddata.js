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

if(argobj.length!=1)
{
	WScript.Echo("Usage: issigneddata.js signeddata");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
signature=fs.Read(argobj(0));
fs=null;

signobj=new ActiveXObject("NetcaPki.SignedData");
if(signobj.IsSign(signature) )
{
	if (signobj.IsDetachedSign(signature) )
	{
		WScript.Echo("不带原文的SignedData");
	}
	else
	{
		WScript.Echo("带原文的SignedData");
	}
}
else
{
	WScript.Echo("不是SignedData");
}


