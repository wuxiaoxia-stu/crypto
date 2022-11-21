
/*设备类型*/
var NETCAPKI_DEVICETYPE_ANY = -1;

//-------设备标识-------//
var NETCAPKI_DEVICEFLAG_SILENT					= 1;	//如果这一位设置，则不会显示UI
var NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS	= 0;	//在进程中缓存PIN码
var NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_HANDLE		= 2;	//在句柄中缓存PIN码
var NETCAPKI_DEVICEFLAG_NOT_CACHE_PIN			= 4;	//不缓存PIN码

/*签名算法*/
var NETCAPKI_ALGORITHM_SHA1WITHRSA = 2;
var NETCAPKI_ALGORITHM_SM3WITHSM2 = 25;


/* 编码格式 */
var NETCAPKI_CP_ACP = 0; //	系统的代码页
var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;
var NETCAPKI_CP_UTF16LE = 1200;

/*CMS编码方式*/
var NETCAPKI_CMS_ENCODE_DER = 1;
var NETCAPKI_CMS_ENCODE_BASE64 = 2;
var NETCAPKI_CMS_ENCODE_BASE64_MULTILINE = 3;


/* BASE64的选项	值	说明 */
var NETCAPKI_BASE64_ENCODE_NO_NL = 1;        //	编码选项，如果设置了该位，则编码时不换行
var NETCAPKI_BASE64_DECODE_STRICT = 2;        // 解码选项，如果设置了该位，则解码时不允许包含换行


/* 证书存储区存储类型常量 */
var NETCAPKI_CERT_STORE_TYPE = new Array("1", "0");

/* 证书存储区类型常量 */
var NETCAPKI_CERT_STORE_NAME = new Array("my", "others", "ca", "root"); // 兼容SecuInter
/* 抛出错误说明 */
var NETCAPKI_ERROR_PREFIX_INFO='操作失败，可能发生以下情况：\n';
var NETCAPKI_ERROR_1_NOCERT = '没有符合条件的证书。';
var NETCAPKI_ERROR_2_ACTIVEXFAIL = 'NETCA控件安装失败。';
var NETCAPKI_ERROR_3_SIGNFAIL = '签名过程中发生错误。';
var NETCAPKI_ERROR_4_ARG_CONTENTEMPTY = '签名时签名原文不能为空。';
var NETCAPKI_ERROR_5_ARG_CERTEMPTY = '签名时签名证书不能为空。';
var NETCAPKI_ERROR_6_ARG_SIGNEMPTY = '验签时签名值不为空。';
var NETCAPKI_ERROR_7_ARG_SIGNCONTENTEMPTY = '不带源文的验签时源文不能为空。';
var NETCAPKI_ERROR_8_ARG_NODEVICES = '请检查是否已插入USBKEY。';
var NETCAPKI_ERROR_9_ARG_DECRYPTDATAEMPTY = '解密数据为空。';
var NETCAPKI_ERROR_10_ARG_PINEMPTY = '用户PIN码为空。';
var NETCAPKI_ERROR_11_ARG_FILEPATHEMPTY = '文件路径为空。';
var NETCAPKI_ERROR_12_ARG_CERTDIFF = '签名时候的证书与验证时候的证书不一致。';
var NETCAPKI_ERROR_13_ARG_VERIFY = '签名验证失败，数据可能被篡改。';
var NETCAPKI_ERROR_14_ARG_SELETECERTFAIL = '证书选择失败。';
var NETCAPKI_ERROR_15_ARG_ADDENCCERTFAIL = '添加加密证书失败。';
var NETCAPKI_ERROR_16_ARG_DECRYFAIL = '解密失败,找不到解密证书或者密文被修改。';

var NETCAPKI_ERROR_17_ARG_CONTENTEMPTYEX = '加密时原文不能为空。';
var NETCAPKI_ERROR_18_ARG_CIPHERMPTY = '解密时密文不能为空。';
var NETCAPKI_ERROR_19_ARG_CERTEMPTY = '加密证书不能为空。';

var NETCAPKI_RSA_PKCS_V1_5 =16;
var NETCAPKI_SM2_ENCRYPT=64;
var NETCAPKI_ALGORITHM_SM2 =4;
var NETCAPKI_ALGORITHM_RSA =1;

var NETCAPKI_ENVELOP_ALGORITHM_3DES =3;
var NETCAPKI_ENVELOP_ALGORITHM_AES128 =4;
var NETCAPKI_ENVELOP_ALGORITHM_AES192 =5;
var NETCAPKI_ENVELOP_ALGORITHM_AES256 =6;
var NETCAPKI_ENVELOP_ALGORITHM_SSF33 =7;
var NETCAPKI_ENVELOP_ALGORITHM_SM1 =8;
var NETCAPKI_ENVELOP_ALGORITHM_SM4 =9;

function VerifyCert(b64cert)
{
	
	try{
		 var pki = document.getElementById("pki");		
		var certObj=pki.CreateCertificateObject(b64cert);
		if(certObj==null)
		{			
			return -3;
		}
		var invility=certObj.GetIntInfo(34);
		if(invility ==0)
		{
			return 0;			
		}
		var certpath;
		certpath=certObj.BuildCertPath();
		if(certpath==null)
		{			
			return -3;
		}		
		var certverifyobj;		
		certverifyobj=pki.CreateCertVerifyObject();
		if(certverifyobj==null)
		{			
			return -3;
		}	
		certverifyobj.Option=0x23;
		
		certverifyobj.AddRootCert(certpath.GetCertificate(1));
		var count=certpath.GetCertificateCount();
		for(i=2;i<=count-1;i++)
		{
			certverifyobj.AddCACert(certpath.GetCertificate(i));				
		}
		var result;	
		result=certverifyobj.Verify(certObj); 
		return result;
	}
	catch(e) 
	{
		throw (e.description);
		return -3;
	}	
	
	
}


function GetCertTHUMBPRINT(cert)
{
	try{
		 var pki = document.getElementById("pki");
		 var thumbprint =cert.ThumbPrint(8192);
		 return pki.BinaryToHex(thumbprint,true);		
	}
	catch(e) 
	{
		throw (e.description);
		return null;
	}	
	
}
function envelopedDataDecrypt(cipherText)
{
	if (cipherText == null || cipherText == "")
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_18_ARG_CIPHERMPTY);
		return null;
	}	
	
	var pki = document.getElementById("pki");
	try{
		
			var envelopedDadaObj =pki.CreateEnvelopedDataObject(false);			
			var clear=envelopedDadaObj.Decrypt(cipherText); 
			return clear;
	}
	catch(e) 
	{
		throw (e.description);
		return null;
	}
	
	
	
}

function envelopedDataEncrypt(cert,clearText)
{	
	if (clearText == null || clearText == "")
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_17_ARG_CONTENTEMPTYEX);
		return null;
	}
	if (cert == null)
    {
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_19_ARG_CERTEMPTY);
		return null;
	}
	
	var pki = document.getElementById("pki");
	try{
		
			var envelopedDadaObj =pki.CreateEnvelopedDataObject(true);
			envelopedDadaObj.EncryptAlgorithm=6;
			envelopedDadaObj.AddCert(cert);
			var cipher=envelopedDadaObj.Encrypt(clearText,NETCAPKI_CMS_ENCODE_BASE64); 
			return cipher;
	}
	catch(e) 
	{
		throw (e.description);
		return null;
	}
	
}


function certDecrypt(cert,cipherText)
{
	if (cipherText == null || cipherText == "")
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_18_ARG_CIPHERMPTY);
		return null;
	}
	if (cert == null)
    {
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_19_ARG_CERTEMPTY);
		return null;
	}	
		
		try{
			var algo = cert.PublicKeyAlgorithm;
			var encrypAlgo;
			if(algo==NETCAPKI_ALGORITHM_RSA)
			{
				encrypAlgo=NETCAPKI_RSA_PKCS_V1_5;			
			}
			else{
			
				encrypAlgo=NETCAPKI_SM2_ENCRYPT;			
			}
			var clear = cert.Decrypt(encrypAlgo,cipherText);
			return clear;
	}
	catch(e) 
	{
		throw (e.description);
		return null;
	}
	
}

function certEncrypt(cert,clearText)
{
	try{
		var algo = cert.PublicKeyAlgorithm;
		var encrypAlgo;
		if(algo==NETCAPKI_ALGORITHM_RSA)
		{
			encrypAlgo=NETCAPKI_RSA_PKCS_V1_5;			
		}
		else{
			
			encrypAlgo=NETCAPKI_SM2_ENCRYPT;	
			
		}
		var cipher = cert.Encrypt(encrypAlgo,clearText);
		return cipher;
	}
	catch(e) 
	{
		throw (e.description);
		return null;
	}	
	
	
}


function isPKIInstalled()
{	
	var pki = document.getElementById("pki");
	try
	{		
		utilObj = pki.CreateDeviceObject();
		if(typeof(utilObj).toString().indexOf("object") != -1) 
		{	
			return true; 
		}
		else 
		{	
			return false;
		}	
	}
	catch (e)
	{   
		alert(e);
		return false;
	}
}



/*-------------------数据编码--------------------------------(UTF-16BE的编码，暂时不支持)
 * 参数   encodetype  编码方式，可以是"Base64","UTF-8"
 * 参数   data        被编码的字节数据
 * 返回值             编码后的字符串
 */
function StrEncode(encodetype, data){
	var pki = document.getElementById("pki");
	var ecode;
	switch(encodetype){
		case "HEX":
			ecode = pki.BinaryToHex(data, true);
			break;
		case "hex":
			ecode = pki.BinaryToHex(data, false);
			break;
		case "Base64":
			ecode = pki.Base64Encode(data, NETCAPKI_BASE64_ENCODE_NO_NL);
			break;
		case "UTF-8":
			ecode = pki.Decode(encodetype, data);
			break;
		case "GBK":
			ecode = pki.Decode(encodetype, data);
			break;
		case "UTF-16LE":
			ecode = pki.Decode(encodetype, data);
			break;
	}
	
	return ecode;
	
}





/*------------------数据解码--------------------(UTF-16BE的编码，暂时不支持)
 *参数  encodetype   编码方式,可以是"Base64","UTF-8"
 *参数  str          编码字符串
 *返回值             解码后的字节数据
 */
function StrDecode(encodetype, str){
	var pki = document.getElementById("pki");
	var dcode;
	switch(encodetype){
		case "HEX":
			dcode = pki.HexToBinary(str, true);
			break;
		case "hex":
			dcode = pki.HexToBinary(str, false);
			break;
		case "Base64":
			dcode = pki.Base64Decode(str, NETCAPKI_BASE64_ENCODE_NO_NL);
			break;
		case "UTF-8":
			dcode = pki.Encode(encodetype, str);
			break;
		case "GBK":
			dcode = pki.Encode(encodetype, str);
			break;
		case "UTF-16LE":
			dcode = pki.Encode(encodetype, str);
			break;
	}
	
	return dcode;
}



/*--------------从多个证书里面选择一个证书（带私钥）-----------------------
 *参数  type       证书类型，1 签名证书， 2 加密证书
 *参数  filter     证书过滤条件，比如"IssuerCN~'NETCA'"。如果传空值，则不过滤
 *参数  guioption  证书选择框图形界面选项 1：只有一张证书时不弹提示框，否则弹框；
                                          2：只能有一张符合条件的证书；
                                          3：无论有无证书都要UI提示；
*参数  from        证书来源，0：从设备读证书，1：从windows证书库读证书
*返回值            成功返回证书对象
*/
function SelectMyCert(type, filter, guioption, from)
{
	var oCert;	
	if (type == 1)
	{
		filter += "&&CertType='Signature'";
	}
	else if (type == 2)
	{
		filter += "&&CertType='Encrypt'";
	}		
	try
	{
		if (from == 0)
		{
			oCert = getX509CertificateFromKey(filter, guioption);
		}
		else if (from == 1)
		{
			oCert = getX509Certificate(filter, guioption);
		}
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + e);
	}
	return oCert;
}

/*----------------从证书库或者USBKEY里面选择符合特定域值条件的一个证书（带私钥）-------------
 *参数  valuetype       证书特定域，1（证书姆印）2（证书序列号）
 *参数  value           证书特定域值
 *参数  from            证书来源，0 从设备读证书，1 从windows证书库读证书
 *返回值                成功返回符合条件的证书对象
 */
function FindMyCert(valuetype, value, from)
{
	var oCert = null;
	switch (from)
	{
		case 0:
			oCert = FindMyCertFromKey(valuetype, value);
			break;
		case 1:
		  oCert = FindMyCertFromStore(valuetype, value);
		  break;
		default:
	}
	return oCert;
	
}
/*------------------从USBKEY里面根据特定域选择符合条件的一个证书（带私钥）------------
 *参数  valuetype       证书特定域，1（证书姆印）2（证书序列号）
 *参数  value           证书特定域值
 *返回值                成功返回符合条件的证书对象象
 */
function FindMyCertFromKey(valuetype, value)
{
	var deviceSet;
	var dev;
	var oCert;
	try
	{
		var pki = document.getElementById("pki");
		deviceSet = pki.GetAllDevices(NETCAPKI_DEVICETYPE_ANY, NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS); 
	}
	catch(e)
	{
		throw NETCAPKI_ERROR_2_ACTIVEXFAIL;
		return null;
	}
	deviceCount = deviceSet.Count;
	if (deviceCount <= 0){
		throw NETCAPKI_ERROR_8_ARG_NODEVICES;
		return null;
	}
	for (var i=1; i<=deviceCount; i++)
	{
		dev = deviceSet.GetDevice(i);		
		var keyPairCount = dev.GetKeyPairCount();
		for(var j=1; j<=keyPairCount; j++)
		{
			var keyPair = dev.GetKeyPair(j);
			oCert = keyPair.GetCertifcate(1);				
			if (valuetype == 1)
			{
				var ThumbPrint = oCert.ThumbPrint;
				var hexThumbPrint = pki.BinaryToHex(ThumbPrint, false);
				if(hexThumbPrint == value.toLowerCase())
				{
					
					return oCert;
				}
			}
			if(valuetype ==2)
			{
				var sn = oCert.SerialNumber;
				if(sn.toLowerCase() == value.toLowerCase())
				{
					return oCert;
				}
			}
		}
	}
	throw NETCAPKI_ERROR_1_NOCERT;
	return null;

}
/*--------------------从证书库里面根据特定域选择符合条件的一个证书（带私钥）---------------------
 *参数  valuetype       证书特定域，1（证书姆印）2（证书序列号）
 *参数  value           证书特定域值
 *返回值                成功返回符合条件的证书对象象
 */
function FindMyCertFromStore(valuetype, value)
{
	var oCert;
	var store;
	var storeLocation = 1;
	var storeName = 0;
	
	var pki = document.getElementById("pki");
	store = pki.OpenStore(0, "my");
	if(store!=null)
	{
		count = store.GetCertificateCount(); 			
		for (var i=1; i<=certCount; i++)
		{
			oCert = store.GetCertificate(i);
			if(valuetype == 1)
			{
				var ThumbPrint = oCert.ThumbPrint;
				var hexThumbPrint = pki.BinaryToHex(ThumbPrint, false);
				if(hexThumbPrint == value.toLowerCase())
				{
						
					return oCert;
				}
			}
			if(valuetype == 2)
			{
				var sn = oCert.SerialNumber;
				if(sn.toLowerCase() == value.toLowerCase())
				{
					return oCert;
				}
			}
		}
	}
	throw NETCAPKI_ERROR_1_NOCERT;
	return null;
}



/*---------------数据电子签名----------------------
 * 参数 ocert       证书对象
 * 参数 content     被签名的内容，byte数组
 * 参数 isAttached  签名值是否带原文，0：不带原文，1：带原文
 * 参数 tsaurl      时间戳服务器URL
 * 参数 pin         密码
 * 返回值：P7签名
 */
function SignPKCS7(ocert, content, isAttached, tsaurl, pin)
{

	var signObj;
	var certObj;
	var signAlgo;
	var pwd = pin;
	if (content == null || content == "")
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_4_ARG_CONTENTEMPTY);
		return null;
	}
	if (ocert == null)
    {
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_5_ARG_CERTEMPTY);
		return null;
	}
	try{
		pki = document.getElementById("pki");
		signObj = pki.CreateSignedDataObject(true);
	}
	catch(e) 
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_2_ACTIVEXFAIL);
		return null;
	}

	if (signObj.SetSignCertificate(ocert, pwd, false) == false) 
	{
		throw ("设置签名证书失败");
		return null;
	}
	signAlgo = getAlgoFromCert(ocert);
	if (signAlgo == 2)
	{
		signObj.SetSignAlgorithm(-1,NETCAPKI_ALGORITHM_SHA1WITHRSA);
	}
	else if (signAlgo == 25)
	{
		signObj.SetSignAlgorithm(-1, NETCAPKI_ALGORITHM_SM3WITHSM2);
	}
	
	var str;
	
	    // 1：不带原文；0：带原文
    if (isAttached == 0 || isAttached == "0" || isAttached == false) 
	{
        // 带原文
        signObj.Detached = true;
    }
    else {
        signObj.Detached = false;
    }
	try
	{
		if (tsaurl == "") 
		{
			str = signObj.Sign(content, NETCAPKI_CMS_ENCODE_DER);
		}
		else 
		{
			str = signObj.SignWithTSATimeStamp(tsaurl, content, NETCAPKI_CMS_ENCODE_DER);
		}
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_3_SIGNFAIL);
	}
    signObj = null;
    return str;
}



/*----------------直接从USBKEY中获取证书-----------------------------
 * 参数 filter        证书筛选条件，例如"IssuerCN~'NETCA'"
 * 参数 guioption     证书选择框的形式，1：只有一个证书是不弹框，2：只能有一个符合条件的证书；3：始终有证书选择框
 */
function getX509CertificateFromKey(filter, guioption){
	var deviceSet;
	var deviceCount;
	var cert;
	
	try
	{
		var pki = document.getElementById("pki");
		deviceSet = pki.GetAllDevices(NETCAPKI_DEVICETYPE_ANY, NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS); 
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_2_ACTIVEXFAIL);
		return null;
	}


	deviceCount = deviceSet.Count;
	if (deviceCount <= 0)
	{
		throw (NETCAPKI_ERROR_8_ARG_NODEVICES);
		return null;
	}
	if (guioption == 1)
	{
		cert = deviceSet.FindCertificate(filter, 1); //在只有一个或没有证书的情况下，不弹出对话框让用户选择
	}
	else if (guioption == 2)
	{
		cert = deviceSet.FindCertificate(filter, 2); //从不弹出对话框让用户选择
	}
	else if (guioption == 3)
	{
		cert = deviceSet.FindCertificate(filter, 3); //总是弹出对话框让用户选择
	}
	if (cert == null)
	{
		throw (NETCAPKI_ERROR_1_NOCERT);
	}
	return cert;
}



/*-------------从证书库中获取证书--------------------------            
 * 参数 filter        证书筛选条件，例如"IssuerCN~'NETCA'"
 * 参数 guioption     证书选择框的形式，1：只有一个证书是不弹框，2：只能有一个符合条件的证书；3：始终有证书选择框
 */
function getX509Certificate(filter, guioption)
{
    var storeObj;
    var cert;
    var count = 0;
    var storeLocation = 1;
	var storeName = 0;
	
	try
	{
		var pki = document.getElementById("pki");
		storeObj = pki.OpenStore(0, "my");
		if(storeObj == null)
		{
			throw (NETCAPKI_ERROR_2_ACTIVEXFAIL);
		}
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_2_ACTIVEXFAIL);
		return null;
	}
	count = storeObj.GetCertificateCount(); 
	if(count <= 0)
	{
		storeObj.Close();
		storeObj = null;
		throw NETCAPKI_ERROR_1_NOCERT;
		return null;
	}
		
	
	if (guioption == 1)
	{
		cert = storeObj.FindCertificate(filter, 1); //在只有一个或没有证书的情况下，不弹出对话框让用户选择
	}
	else if (guioption == 2)
	{
		cert = storeObj.FindCertificate(filter, 2); //从不弹出对话框让用户选择
	}
	else if (guioption == 3)
	{
		cert = storeObj.FindCertificate(filter, 3); //总是弹出对话框让用户选择
	}
	storeObj.Close();
	storeObj = null;
	if (cert == null)
	{
		throw (NETCAPKI_ERROR_1_NOCERT);
	}
	return cert;	
}


/*----------------------从证书对象里面获取签名算法 -------------------
 * 参数 oCert     证书对象
 */
function getAlgoFromCert(oCert)
{
	var signAlgo = 0;
	var algo = oCert.PublicKeyAlgorithm;
	switch(algo)
	{
		case 1:
			signAlgo = 2;
			break;
		case 4:
			signAlgo = 25;
			break;
		default:
			signAlgo = 2;
			break;
	}	
	return signAlgo;	
}


/*---------------签名结果验证--------------------------------
 * 参数 bcms     调用SignPKCS7得到签名结果，byte数组形式
 * 参数 content  签名原文，byte数组形式
 */
function SimpleVerifyPKCS7(cms, content){
	var signObj;
	var pki;
	if(cms == ""){
		throw (NETCAPKI_ERROR_6_ARG_SIGNEMPTY);
		return null;
	}
	
	try{
		pki = document.getElementById("pki");
		signObj1 = pki.CreateSignedDataObject(false);
		signObj2 = pki.CreateSignedDataObject(false);
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_2_ACTIVEXFAIL);
		return null;
	}
	try
	{//带原文
		isOK = true//标志是否通过
		//signObj1.Detached = false;

		var tbs;
		if(content != "")
		{
			tbs = signObj1.Verify(cms);
			isOK = content.Equals(tbs);								
		}
		else if(content == "")
		{
			tbs = signObj1.verify(cms);
			if(tbs == "")
			{
				isOK = false;
			}
		}
		if(!isOK)
		{
			throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_13_ARG_VERIFY);
			return null;
		}
		else
		{
			certObj = signObj1.GetSignCertificate(-1);  //获取当前签名的证书
			return certObj;
		}
	}
	catch(e)
	{//不带原文
		if(content == ""){
			throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_7_ARG_SIGNCONTENTEMPTY);
			return null;
		}

		var tbs;
		//signObj2.Detached = true;
		try 
        {
			tbs = signObj2.DetachedVerify(content, cms, false);
			if (!tbs)
			{
				throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_13_ARG_VERIFY);
				return null;
			}
			else
			{
				certObj = signObj2.GetSignCertificate(-1);  //获取当前签名的证书
				return certObj;
			}
		}
		catch(e)
		{
		    throw (NETCAPKI_ERROR_PREFIX_INFO + NETCAPKI_ERROR_13_ARG_VERIFY);
		}
	}
}
/*-----------------获取证书绑定值--------------------------
 * 参数 cert     证书对象
 */
function GetCertExtensionStringValue(cert,oid,certOIDEncodeType) 
{
	var pki;
	try
	{
		pki = document.getElementById("pki");
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_2_ACTIVEXFAIL);
		return null;
	}
	var boidval = cert.GetExtension(oid); 
    var oidval = pki.DecodeASN1String(certOIDEncodeType, boidval);
    return oidval;
}

function getDeviceNumber() 
{
	var pki;
	try
	{
		pki = document.getElementById("pki");
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_2_ACTIVEXFAIL);
		return -1;
	}
	var oDeviceSet = null;
	var oUtilObj = null;
    try 
	{
        oDeviceSet = pki.GetAllDevices (-1, 0);
	}
	catch(e)
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + e.message);
	}
    var count = oDeviceSet.Count;
	if (count == 0)
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + "请插入证书介质！");
		return -1;
	} 
	else if (count > 1) 
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + "您插入的证书介质不唯一！");
		return -1;
	}
    var oDevice = null;
    try 
	{
        oDevice = oDeviceSet.GetDevice(1);
        oDeviceSet = null;
		var brv = oDevice.SerialNumber;
        oDevice = null;
        return brv;
    }
	catch (e) 
	{
		throw (NETCAPKI_ERROR_PREFIX_INFO + e.message);
        oDeviceSet = null;
        return -1;
    }
}
