var NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC	    =16;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var utilobj;
var certobj;
var data;
var cipher;
var argobj;
var fs;
var cert;

argobj= WScript.Arguments;

if(argobj.length!=1)
{
	WScript.Echo("Usage: certencrypt.js cert");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(0));
fs=null;

utilobj=new ActiveXObject("NetcaPki.Utilities");
data=utilobj.Encode("ÄãºÃ,NETCA",NETCAPKI_CP_UTF8);

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

cipher=certobj.Encrypt(NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC,data);

WScript.Echo(utilobj.BinaryToHex(cipher));

