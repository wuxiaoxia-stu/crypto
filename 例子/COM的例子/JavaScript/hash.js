var NETCAPKI_ALGORITHM_MD5	=4096;
var NETCAPKI_ALGORITHM_SHA1	=8192;
var NETCAPKI_ALGORITHM_SHA256	=16384;
var NETCAPKI_ALGORITHM_SHA512	=24576;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var utilobj;
var deviceobj;
var data;
var hash;

utilobj=new ActiveXObject("NetcaPki.Utilities");
data=utilobj.Encode("abc",NETCAPKI_CP_UTF8);
deviceobj=new ActiveXObject("NetcaPki.Device");
hash=deviceobj.Hash(NETCAPKI_ALGORITHM_SHA256,data);

WScript.Echo(utilobj.BinaryToHex(hash));

