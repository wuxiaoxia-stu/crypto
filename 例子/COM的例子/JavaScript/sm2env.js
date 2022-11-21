var NETCAPKI_ENVELOPEDDATA_ALGORITHM_TDESCBC = 3;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES128CBC = 4;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES192CBC = 5;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC = 6;

var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

var NETCAPKI_CMS_ENCODE_BASE64 = 2;
var NETCAPKI_CMS_ENCODE_BASE64_MULTILINE = 3;
var NETCAPKI_CMS_ENCODE_DER = 1;

var NETCAPKI_ENVELOPEDDATA_ATTRIBUTE_USE_SM2_Q7=3

var utilobj;
var certobj;
var envobj;
var data;
var argobj;
var fs;
var cert;
var cipher;

argobj= WScript.Arguments;

if(argobj.length!=1)
{
	WScript.Echo("Usage: sm2env.js cert");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(0));
fs=null;

utilobj=new ActiveXObject("NetcaPki.Utilities");
data=utilobj.Encode("123",NETCAPKI_CP_UTF8);

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

envobj=new ActiveXObject("NetcaPki.EnvelopedData");

envobj.SetIntegerAttribute(NETCAPKI_ENVELOPEDDATA_ATTRIBUTE_USE_SM2_Q7,1)

envobj.EncryptAlgorithm = NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC;
if (envobj.AddCert(certobj) == false)
{
   WScript.Echo("��Ӽ���֤��ʧ��");
   WScript.Quit (-1);
}

cipher=envobj.Encrypt(data,NETCAPKI_CMS_ENCODE_BASE64_MULTILINE);

WScript.Echo("���ܳɹ�");
WScript.Echo(cipher);
