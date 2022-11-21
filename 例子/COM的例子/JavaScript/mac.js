var NETCAPKI_ALGORITHM_HMAC_MD5	    =131072;
var NETCAPKI_ALGORITHM_HMAC_SHA1	=262144;
var NETCAPKI_ALGORITHM_HMAC_SHA256	=524288;
var NETCAPKI_ALGORITHM_HMAC_SHA512	=786432;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var utilobj;
var deviceobj;
var data;
var mac;
var key;

utilobj=new ActiveXObject("NetcaPki.Utilities");
key=utilobj.Encode("Jefe",NETCAPKI_CP_UTF8);
data =utilobj.Encode("what do ya want for nothing?",NETCAPKI_CP_UTF8);

deviceobj=new ActiveXObject("NetcaPki.Device");
mac=deviceobj.Mac(NETCAPKI_ALGORITHM_HMAC_SHA256,key,data);

WScript.Echo(utilobj.BinaryToHex(mac));

