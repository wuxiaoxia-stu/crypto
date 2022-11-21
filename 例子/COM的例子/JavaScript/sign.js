var NETCAPKI_ALGORITHM_SHA1WITHRSA	    =2;
var NETCAPKI_ALGORITHM_SHA256WITHRSA    =4;
var NETCAPKI_ALGORITHM_SHA512WITHRSA    =6;
var NETCAPKI_ALGORITHM_MD5WITHRSA       =1;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var utilobj;
var certobj;
var data;
var sign;
var argobj;
var fs;
var cert;

argobj= WScript.Arguments;

if(argobj.length!=1)
{
	WScript.Echo("Usage: sign.js cert");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(0));
fs=null;

utilobj=new ActiveXObject("NetcaPki.Utilities");
data=utilobj.Encode("你好,NETCA",NETCAPKI_CP_UTF8);

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

sign=certobj.Sign(NETCAPKI_ALGORITHM_SHA1WITHRSA,data);

WScript.Echo("签名成功");

if (certobj.Verify(NETCAPKI_ALGORITHM_SHA1WITHRSA, data, sign))
{
   WScript.Echo("验证签名成功");
}
else
{
   WScript.Echo("验证签名失败");
}


