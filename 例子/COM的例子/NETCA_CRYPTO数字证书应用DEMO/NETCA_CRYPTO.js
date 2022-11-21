<!--

var NETCAPKI_CERT_STORE_NAME_MY = "my";
var NETCAPKI_CERT_STORE_NAME_OTHERS = "others";
var NETCAPKI_CERT_STORE_NAME_CA = "ca";
var NETCAPKI_CERT_STORE_NAME_ROOT = "root";

var NETCAPKI_ALGORITHM_SHA1WITHRSA	    =2;
var NETCAPKI_ALGORITHM_SHA256WITHRSA    =4;
var NETCAPKI_ALGORITHM_SHA512WITHRSA    =6;
var NETCAPKI_ALGORITHM_MD5WITHRSA       =1;
var NETCAPKI_ALGORITHM_SM3WITHSM2=25;
var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;


var NETCAPKI_ALGORITHM_SHA1	=8192;
var NETCAPKI_ALGORITHM_SHA256	=16384;
var NETCAPKI_ALGORITHM_SHA512	=24576;


var NETCAPKI_TIMESTAMP_RESP_STATUS_BADTSACERT   = -2;
var NETCAPKI_TIMESTAMP_RESP_STATUS_BADRESP      = -1;
var NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTED      = 0;
var NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS = 1;
var NETCAPKI_TIMESTAMP_RESP_STATUS_REJECTION = 2;
var NETCAPKI_TIMESTAMP_RESP_STATUS_WAITING = 3;
var NETCAPKI_TIMESTAMP_RESP_STATUS_REVOCATIONWARNING = 4;
var NETCAPKI_TIMESTAMP_RESP_STATUS_REVOCATIONNOTIFICATION = 5;

var NETCAPKI_CERT_STORE_TYPE_CURRENT_USER	  =0;
var NETCAPKI_CERT_STORE_TYPE_LOCAL_MACHINE    =1;



var NETCAPKI_KEYUSAGE_DIGITALSIGNATURE      = 1;
var NETCAPKI_KEYUSAGE_CONTENTCOMMITMENT     = 2;
var NETCAPKI_KEYUSAGE_KEYENCIPHERMENT       = 4;
var NETCAPKI_KEYUSAGE_DATAENCIPHERMENT      = 8;
var NETCAPKI_KEYUSAGE_KEYAGRESSMENT         = 16;
var NETCAPKI_KEYUSAGE_KEYCERTSIGN           = 32;
var NETCAPKI_KEYUSAGE_CRLSIGN               = 64;
var NETCAPKI_KEYUSAGE_ENCIPHERONLY          = 128;
var NETCAPKI_KEYUSAGE_DECIPHERONLY          = 256;



var NETCAPKI_CMS_ENCODE_BASE64 = 2;
var NETCAPKI_CMS_ENCODE_BASE64_MULTILINE = 3;
var NETCAPKI_CMS_ENCODE_DER = 1;

var NETCAPKI_UIFLAG_DEFAULT_UI	=1;
var NETCAPKI_UIFLAG_NO_UI	=2;
var NETCAPKI_UIFLAG_ALWAYS_UI	=3;

var NETCAPKI_BASE64_ENCODE_NO_NL =1;
var NETCAPKI_BASE64_DECODE_STRICT =2;

var NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC  =16;
/* SM2�����㷨 */
var NETCAPKI_ALGORITHM_SM2_ENC=64;

var NETCAPKI_ENVELOPEDDATA_ALGORITHM_TDESCBC    =0;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES128CBC  =1;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES192CBC  =2;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC  =3;

var oUtil;

/********************* netca_crytocom test demo wur add  2011-03-04******************/
/*�жϿؼ��Ƿ�װ�ɹ�*/
function IsObjInstalled()
{
	try
	{ 
		oUtil = new ActiveXObject("NetcaPki.Utilities");
		if(typeof(oUtil) == "object")
	        {
                    return true; 
	         }
	}
	catch (e)
	{   
		return false;
	}

	return false;
}

/*����ķӡ�õ�֤��Certificate*/
function getCertByThumbprint(szThumbprint)
{	
	
	if (szThumbprint.length < 32)
	{
		alert("֤���ķӡ̫��!");
		return null;
	}
	//if(!IsObjInstalled()){
	//	alert("NetcaPki��װ���ɹ�!");
	//	return null;
        //}
	
	var MyStore;
	try
	{
		MyStore = new ActiveXObject("NetcaPki.Store");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}

	try
	{
		MyStore.Open(NETCAPKI_CERT_STORE_TYPE_CURRENT_USER,NETCAPKI_CERT_STORE_NAME_MY);
	}
	catch (e)
	{
		alert("��֤���ʧ��");
		return null;
	}

	var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}	
	
	var certobj;
	var now;
	var count;
	var i;	
	now=new Date();
	count=MyStore.GetCertificateCount();
	

	for(i=1;i<=count;i++)
	{
	    certobj=MyStore.GetCertificate(i);
	    if( oUtilmy.BinaryToHex(certobj.Thumbprint,false).toLowerCase() == szThumbprint.toLowerCase() )
	    {
		MyStore.Close();	
		MyStore = null;
		
		oUtilmy = null;	    	
	    	 return certobj;
	    }
	}
	MyStore.Close();	
	MyStore = null;	

	window.status="";
	return null;

}


/*ѡ��֤��,���� X509Certificate*/
function getX509CertificateBySelect()
{	
	
	var MyStore;
	try
	{
		MyStore = new ActiveXObject("NetcaPki.Store");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}
	alert(1)
	try
	{
		MyStore.Open(NETCAPKI_CERT_STORE_TYPE_CURRENT_USER,NETCAPKI_CERT_STORE_NAME_MY);
	}
	catch (e)
	{
		alert("��֤���ʧ��");
		return null;
	}
	alert(2)
	var certobj;
	var count;
	var i;	
	var now;
	now=new Date();	
  	//count=MyStore.GetCertificateCount();

	//certobj=MyStore.FindCertificate("HasPrivKey='True'&&InValidity='True'&&CertType='Signature'",NETCAPKI_UIFLAG_ALWAYS_UI);
	alert(11)
	try {
	certobj=MyStore.FindCertificate("CertType='Signature'",NETCAPKI_UIFLAG_ALWAYS_UI);//aoyi20130624 
	}
	catch (e)
	{
		alert("��֤���ʧ��" + e.description);
		return null;
	}                              
	alert(3)
	if(certobj!=null)
	{
	        return certobj;
	}
	MyStore.Close();
	alert(4)
	window.status="";
	return null;

}

/*ѡ��֤��,���� X509Certificate*/


//storeType:NETCAPKI_CERT_STORE_NAME_MY = "my" (����);NETCAPKI_CERT_STORE_NAME_OTHERS = "others"(������)
//isSignCert:true(sign cert);false(env cert)

//===����ע��======
//IssuerO='NETCA Certificate Authority'  ��NETCA�ĸ���֤��/��λ֤��/��λԱ��֤��/������֤��
//IssuerCN='NETCA Organization ClassA CA'  �ǵ�λ�͵�λԱ��֤��
//IssuerCN='NETCA Server ClassA CA' �Ƿ�����֤��
//IssuerCN='NETCA Individual ClassA CA' �Ǹ���֤��

function getX509Certificate(storeType,isSignCert)
{	
	
	var MyStore;
	try
	{
		MyStore = new ActiveXObject("NetcaPki.Store");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}

	try
	{
		MyStore.Open(NETCAPKI_CERT_STORE_TYPE_CURRENT_USER,storeType);
	}
	catch (e)
	{
		alert("��֤���ʧ��");
		return null;
	}
	var certobj;
	var count;
	var i;	
	var now;
	now=new Date();	
  	//count=MyStore.GetCertificateCount();
        if(isSignCert==true){
	     //certobj=MyStore.FindCertificate("HasPrivKey='True'&&InValidity='True'&&CertType='Signature'&&IssuerO='NETCA Certificate Authority'",NETCAPKI_UIFLAG_ALWAYS_UI);
		certobj=MyStore.FindCertificate("CertType='Signature'",NETCAPKI_UIFLAG_ALWAYS_UI);
	}
	else{
	     //certobj=MyStore.FindCertificate("HasPrivKey='True'&&InValidity='True'&&CertType='Encrypt'&&IssuerO='NETCA Certificate Authority'",NETCAPKI_UIFLAG_ALWAYS_UI);
		certobj=MyStore.FindCertificate("CertType='Encrypt'",NETCAPKI_UIFLAG_ALWAYS_UI);
	}
	
	if(certobj!=null)
	{
	        return certobj;
	}
	MyStore.Close();
	
	window.status="";
	return null;

}
/*֤�����*/
function getCertInfo()
{	
	var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}	

	var cert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,true);
	if(cert==null){
		return;
    	}

   	cert.Display();
   	var certtrump;
   	certtrump=oUtilmy.BinaryToHex(cert.Thumbprint);
   	alert("֤���΢��ͼ:   "+oUtilmy.BinaryToHex(cert.Thumbprint) );
   	alert("֤����Ч��::"+cert.ValidFromDate);
   	alert("֤��䷢��::"+cert.Issuer);
   	alert("֤�����к�::"+cert.SerialNumber);
   	alert("֤������::"+cert.Subject);
   	 
        return certtrump;
}
/*��ǩ��*/
function sign(bContent)
{	
	var oCert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,true);
	if(oCert==null){
		alert("δѡ��֤��!");
		return null;
   	
   	}
	var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	var data; 	
	data=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);
    var signAlgo=NETCAPKI_ALGORITHM_SHA256WITHRSA;
	if(oCert.PublicKeyType==2)
	{
		signAlgo=NETCAPKI_ALGORITHM_SM3WITHSM2;
	}

	var arrRT =oCert.Sign(signAlgo,data);
    	oCert = null;
        return oUtilmy.Base64Encode(arrRT,NETCAPKI_BASE64_ENCODE_NO_NL);
	

}
/*��ǩ�������֤*/
function verify(bContent,bSignData)
{
	var oCert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,true);
	if(oCert==null){
		return -1;
		return null;
   	
   	}	
	var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		return -1;
		return null;
	}  
	var signature; 	
	var data; 	
	data=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);	
	signature=oUtilmy.Base64Decode(bSignData,NETCAPKI_BASE64_ENCODE_NO_NL);	

	 var signAlgo=NETCAPKI_ALGORITHM_SHA256WITHRSA;
	if(oCert.PublicKeyType==2)
	{
		signAlgo=NETCAPKI_ALGORITHM_SM3WITHSM2;
	}

	if (oCert.Verify(signAlgo, data, signature))
	{
	   return 0;
	}
	else
	{
	   return -2;
	}		
}
/*���ǩ����֤*/
function signMuti(bContent,oCert,maxcount)
{	
	
	var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}
   	
    	var bSignData;
   	var icount;
   	var data; 
   	var num;
   	for(icount=0;icount<maxcount;icount++)
   	{
   		
                bSignData=null;
                data=null;
		data=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);

	 var signAlgo=NETCAPKI_ALGORITHM_SHA256WITHRSA;
	if(oCert.PublicKeyType==2)
	{
		signAlgo=NETCAPKI_ALGORITHM_SM3WITHSM2;
	}

		var arrRT =oCert.Sign(signAlgo,data);
	        bSignData=oUtilmy.Base64Encode(arrRT,NETCAPKI_BASE64_ENCODE_NO_NL);
	   	
		if (oCert.Verify(signAlgo, data, oUtilmy.Base64Decode(bSignData,NETCAPKI_BASE64_ENCODE_NO_NL)))
		{
	           num=icount+1;
		   alert("ǩ����֤��" + num + "�γɹ�" );
		}
		else
		{
		   return -2;
		}
	    	
	}
    	alert("��֤ͨ��");
    	return 0;
}


/*SignedDataǩ��/��֤*/
function signpkcs7(bContent)
{
        var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	var oCert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,true);
	if(oCert==null){
		alert("δѡ��֤��!");
		return null;
   	
   	}
	var sign1obj;
	var signature;
	var tbsdata; 	
	tbsdata=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);	
	try
	{
		var sign1obj = new ActiveXObject("NetcaPki.SignedData");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	if (sign1obj.SetSignCertificate(oCert, "", false) == false)
	{
	      alert("����ǩ��֤��ʧ��!");
	      return null;
	}	

	 var signAlgo=NETCAPKI_ALGORITHM_SHA256WITHRSA;
	if(oCert.PublicKeyType==2)
	{
		signAlgo=NETCAPKI_ALGORITHM_SM3WITHSM2;
	}

	sign1obj.SetSignAlgorithm(1, signAlgo);
	
	sign1obj.Detached = true;
        
        
        signature = sign1obj.Sign(tbsdata,NETCAPKI_CMS_ENCODE_BASE64);	
        //�õ�ǩ�����
        sign1obj=null;
        var sign2obj
	try
	{
		sign2obj = new ActiveXObject("NetcaPki.SignedData");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}         
	if (sign2obj.DetachedVerify(tbsdata, signature))
	{
            //��֤ǩ���ɹ�,����ǩ�����
	    return signature;
	}
	else
	{
	    alert("ǩ����֤ʧ��");
	    return -1;
	}        

	  		
}

//֤�����->����֤��->����
function env(bContent)
{	

	var oUtilmy;
	try
	{
		oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	var oCert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,false);
	if(oCert==null){
		alert("δѡ��֤��!");
		return null;
   	
   	}	
	var tbsdata; 
	tbsdata=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);	

   	var oEnv;
   	var envbase64;	
   var envAlgo=NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC;
	if(oCert.PublicKeyType==2)
	{
		envAlgo=NETCAPKI_ALGORITHM_SM2_ENC;
	}

	oEnv=oCert.Encrypt(envAlgo,tbsdata);
	envbase64=oUtilmy.Base64Encode(oEnv,NETCAPKI_BASE64_ENCODE_NO_NL);
    	oEnv = null;
    	oUtilmy = null;
        return envbase64;
        
}
//֤�����->����֤����ܺ�Ľ���
function dev(bEnvData)
{	
	var oUtilmy;
	try
	{
		oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	var oCert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,false);
	if(oCert==null){
		alert("δѡ��֤��!");
		return null;
   	
   	}
   	
   	var envDER;	
   	var oDec;
   	var tbsdata;    		
   	envDER=oUtilmy.Base64Decode(bEnvData,NETCAPKI_BASE64_ENCODE_NO_NL);

	   var envAlgo=NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC;
	if(oCert.PublicKeyType==2)
	{
		envAlgo=NETCAPKI_ALGORITHM_SM2_ENC;
	}
   

   	oDec=oCert.Decrypt(envAlgo,envDER);	
        tbsdata=oUtilmy.Decode(oDec,NETCAPKI_CP_UTF8);	
   	

   	oCert= null;
   	oUtilmy = null;
    	oEnv = null;
    	
    	return tbsdata;
}



//�����ŷ�->����
function EnvelopEnc(bContent)
{	

	var oUtilmy;
	try
	{
		oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	var oCert=getX509Certificate(NETCAPKI_CERT_STORE_NAME_MY,false);
	if(oCert==null){
		alert("δѡ��֤��!");
		return null;
   	
   	}	
	var tbsdata; 
	tbsdata=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);	
	try
	{
		var envobj=new ActiveXObject("NetcaPki.EnvelopedData");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}
   	var oEnv;

	envobj.EncryptAlgorithm = NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC;
	if (envobj.AddCert(oCert) == false)
	{
	       alert("��Ӽ���֤��ʧ��!");
	       return null;
	
        }
        else{
           alert("��Ӽ���֤��ɹ�,��ʼ�����ŷ����");
        }
        
	oCert=null;
	oEnv=envobj.Encrypt(tbsdata,NETCAPKI_CMS_ENCODE_BASE64);
    	envobj = null;
    	oUtilmy = null;
        return oEnv;
        
}


//�����ŷ�->����
function EnvelopDec(bSignData)
{	

	var oUtilmy;
	try
	{
		oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}  
	try
	{
		var envobj=new ActiveXObject("NetcaPki.EnvelopedData");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}
   	var oEnv;
   	var tbsdata;	
	oEnv=envobj.Decrypt(bSignData);	

	
	alert("������Ϣ���ܺ��ȡ�ļ���֤��");
	
        envobj.GetDecryptCertificate().Display();
        tbsdata=oUtilmy.Decode(oEnv,NETCAPKI_CP_UTF8);
    	envobj = null;
    	oUtilmy = null;
        return tbsdata;
        
}

/*��μ��ܽ���*/
function devMuti(bContent,oCert,maxcount)
{	
	
	var oUtilmy;
	try
	{
		 oUtilmy = new ActiveXObject("NetcaPki.Utilities");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}
   	

   	var icount;
   	var num;
   	
	var tbsdata;   
   	var oEnv;
   	var oDec;
   	var tbsinfo;
	tbsdata=oUtilmy.Encode(bContent,NETCAPKI_CP_UTF8);		 	
   	for(icount=0;icount<maxcount;icount++)
   	{

	 var envAlgo=NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC;
		if(oCert.PublicKeyType==2)
		{
			envAlgo=NETCAPKI_ALGORITHM_SM2_ENC;
		}
	        oEnv=null;
	        oDec=null;
		oEnv=oCert.Encrypt(envAlgo,tbsdata);
	
	   	oDec=oCert.Decrypt(envAlgo,oEnv)
	        tbsinfo=oUtilmy.Decode(oDec,NETCAPKI_CP_UTF8);	
		if (tbsinfo==bContent)
		{
	           num=icount+1;
		   alert("���ܽ��ܵ�" + num + "�γɹ�" );
		}
		else
		{
		   return -2;
		}
	    	
	}
    	alert("��μ��ܽ���ͨ��");
    	return 0;
}
//-->