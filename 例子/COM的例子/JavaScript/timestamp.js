var NETCAPKI_ALGORITHM_SHA1	=8192;
var NETCAPKI_ALGORITHM_SHA256	=16384;
var NETCAPKI_ALGORITHM_SHA512	=24576;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var NETCAPKI_TIMESTAMP_RESP_STATUS_BADTSACERT   = -2;
var NETCAPKI_TIMESTAMP_RESP_STATUS_BADRESP      = -1;
var NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTED      = 0;
var NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS = 1;
var NETCAPKI_TIMESTAMP_RESP_STATUS_REJECTION = 2;
var NETCAPKI_TIMESTAMP_RESP_STATUS_WAITING = 3;
var NETCAPKI_TIMESTAMP_RESP_STATUS_REVOCATIONWARNING = 4;
var NETCAPKI_TIMESTAMP_RESP_STATUS_REVOCATIONNOTIFICATION = 5;


var tsobj;
var data;
var hash;
var utilobj;
var algo;
var deviceobj;


utilobj=new ActiveXObject("NetcaPki.Utilities");
data=utilobj.Encode("123",NETCAPKI_CP_UTF8);

algo=NETCAPKI_ALGORITHM_SHA1;
deviceobj=new ActiveXObject("NetcaPki.Device");
hash=deviceobj.Hash(algo,data);

tsobj=new ActiveXObject("NetcaPki.TimeStamp");
tsobj.TsaUrl="https://classatsa.cnca.net/tsa.asp";
tsobj.HashAlgorithm=algo;
tsobj.MessageImprint=hash;

var resp;
resp=tsobj.GetTSPResponse();

if(resp==NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTED|| resp==NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS)
{
    WScript.Echo(tsobj.GetTime());
}
else
{
   WScript.Echo("获取时间戳失败");
}

