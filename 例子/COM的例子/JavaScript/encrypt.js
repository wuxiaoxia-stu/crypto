var NETCAPKI_ALGORITHM_3DES_ECB	    =12582912;
var NETCAPKI_ALGORITHM_3DES_CBC	    =16777216;
var NETCAPKI_ALGORITHM_AES_ECB	    =37748736;
var NETCAPKI_ALGORITHM_AES_CBC	    =41943040;
var NETCAPKI_ALGORITHM_SSF33_ECB    =50331648;
var NETCAPKI_ALGORITHM_SSF33_CBC    =54525952;

var NETCAPKI_PADDING_NONE    =1;
var NETCAPKI_PADDING_PKCS5   =2;

var utilobj;
var deviceobj;
var data;
var cipher;
var key;

utilobj=new ActiveXObject("NetcaPki.Utilities");
key=utilobj.HexToBinary("000102030405060708090a0b0c0d0e0f");
data =utilobj.HexToBinary("00112233445566778899aabbccddeeff");

deviceobj=new ActiveXObject("NetcaPki.Device");
cipher=deviceobj.Encrypt(NETCAPKI_ALGORITHM_AES_ECB,key,null,NETCAPKI_PADDING_NONE,data);

WScript.Echo(utilobj.BinaryToHex(cipher));

