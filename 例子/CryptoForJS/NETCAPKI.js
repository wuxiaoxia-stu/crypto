<!--  
/**
 * �ļ��޸ļ�¼: ���ڵ�˰��Ŀ
 * �汾��V1.0.0.1
 * ʱ��:2012-03-20 
 * 
 */
/* �����ʽ */ 
var NETCAPKI_CP_ACP =	0;//	ϵͳ�Ĵ���ҳ
var NETCAPKI_CP_UTF8 = 65001;
var NETCAPKI_CP_GBK = 936;
var NETCAPKI_CP_BIG5 = 950;
var NETCAPKI_CP_GB18030 = 54936;

//������Կ�ķ�ʽ-ֵ-˵��
var NETCAPKI_SEARCH_KEYPAIR_FLAG_CURRENT_USER	= 1073741824;  //	�ӵ�ǰ�û�֤���������
var NETCAPKI_SEARCH_KEYPAIR_FLAG_LOCAL_MACHINE	= 536870912;   //	�ӱ���֤���������
var NETCAPKI_SEARCH_KEYPAIR_FLAG_DEVICE	= 268435456;           //	�ӵ�ǰ���ӵ��豸������

    
/* ֤��洢���洢���ͳ���
 * �ر�ע�⣺SecuInter����Ϊ 0����ǰ�û�Ϊ1�� Ϊ�˼���SecuInter���˴��������������ֵ��ʵ������
 * �պ��෴��
 */
var NETCAPKI_CERT_STORE_TYPE_CONVERTO_0	 = 1; 
var NETCAPKI_CERT_STORE_TYPE_CONVERTO_1   = 0; 
var NETCAPKI_CERT_STORE_TYPE = new Array("1","0");

/* ֤��洢�����ͳ��� */
var NETCAPKI_CERT_STORE_NAME_MY = 0;
var NETCAPKI_CERT_STORE_NAME_OTHERS = 1;
var NETCAPKI_CERT_STORE_NAME_CA = 2;
var NETCAPKI_CERT_STORE_NAME_ROOT = 3;
var NETCAPKI_CERT_STORE_NAME=new Array("my","others","ca","root"); // ����SecuInter

/* ֤������� */
var NETCAPKI_CERTTYPE_ALL = 0;
var NETCAPKI_CERTTYPE_SIGN = 1;
var NETCAPKI_CERTTYPE_ENV = 2;

/* ֤���÷� */
var NETCAPKI_KEYUSAGE_NO = -1;
var NETCAPKI_KEYUSAGE_DIGITALSIGNATURE = 1;
var NETCAPKI_KEYUSAGE_NONREPUDIATION = 2;
var NETCAPKI_KEYUSAGE_CONTENTCOMMITMENT = 2;
var NETCAPKI_KEYUSAGE_KEYENCIPHERMENT = 4;
var NETCAPKI_KEYUSAGE_DATAENCIPHERMENT = 8;
var NETCAPKI_KEYUSAGE_KEYAGRESSMENT = 16;
var NETCAPKI_KEYUSAGE_KEYCERTSIGN = 32;
var NETCAPKI_KEYUSAGE_CRLSIGN = 64;

/* ֤�����ͳ��� */
var NETCAPKI_NETCA_ALL= 0;
var NETCAPKI_NETCA_YES= 1;
var NETCAPKI_NETCA_NO= 2;
var NETCAPKI_NETCA_OTHER= 3; //NETCA������CA

//ǩ���㷨-ֵ-˵��
var NETCAPKI_ALGORITHM_MD5WITHRSA = 1;    //	MD5WithRSA
var NETCAPKI_ALGORITHM_SHA1WITHRSA	= 2;  //	SHA1WithRSA
var NETCAPKI_ALGORITHM_SHA224WITHRSA = 3; //	SHA224WithRSA
var NETCAPKI_ALGORITHM_SHA256WITHRSA = 4; //	SHA256WithRSA
var NETCAPKI_ALGORITHM_SHA384WITHRSA = 5; //	SHA384WithRSA
var NETCAPKI_ALGORITHM_SHA512WITHRSA = 6; //	SHA512WithRSA
var NETCAPKI_ALGORITHM_SM3WITHSM2 = 25;   //	SM3WithSM2
var NETCAPKI_ALGORITHM_SM3WITHRSA =	31;   //	SM3WithRSA

//֤����;-ֵ-˵��
var NETCAPKI_CERT_PURPOSE_ENCRYPT =	1; //	����
var NETCAPKI_CERT_PURPOSE_SIGN =	2; //	ǩ��

// ֤��״̬
var NETCAPKI_CERT_STATUS_REVOKED        = 0;

var NETCAPKI_CERT_STATUS_UNDETERMINED   = -1;

var NETCAPKI_CERT_STATUS_UNREVOKED      = 1;

var NETCAPKI_CERT_STATUS_ERROR	=3;//	֤���ʽ����
var NETCAPKI_CERT_STATUS_NO_VALID=	4;//	֤���ѹ���Ч��
var NETCAPKI_CERT_STATUS_NOT_NETCA	=5;//	����NETCA�䷢��֤��
var NETCAPKI_CERT_STATUS_OTHER_ERROR=	8	;//��������

// ֤������ԭ��
var NETCAPKI_CRL_REASON_UNSPECIFIED = 0;
var NETCAPKI_CRL_REASON_KEYCOMPROMISE = 1;
var NETCAPKI_CRL_REASON_CACOMPROMISE = 2;
var NETCAPKI_CRL_REASON_AFFILIATION_CHANGED = 3;
var NETCAPKI_CRL_REASON_SUPERSEDED = 4;
var NETCAPKI_CRL_REASON_CESSATION_OF_OPERATION = 5;
var NETCAPKI_CRL_REASON_CERTIFATE_HOLD = 6;
var NETCAPKI_CRL_REASON_REMOVE_FROM_CRL = 8;
var NETCAPKI_CRL_REASON_PRIVILEGE_WITHDRAWN = 9;
var NETCAPKI_CRL_REASON_AACOMPROMISE = 10;

// ֤�������Ϣ��
var NETCAPKI_CERT_THUMBPRINT = 1;    //	NETCAΪ֤��ķӡ
var NETCAPKI_CERT_SERIALNUMBER = 2;  //	֤�����к�
var NETCAPKI_CERT_SUBJECT = 3;       //	֤��Subject
var NETCAPKI_CERT_ISSUER = 4;        //	֤��䷢��
var NETCAPKI_CERT_VALIDFROMDATE = 5; //	֤����Ч����
var NETCAPKI_CERT_VALIDTODATE = 6;   //	֤����Ч��ֹ
var NETCAPKI_CERT_KEYUSAGE = 7;      //	��Կ�÷� KeyUsage
var NETCAPKI_CERT_USRCERTNO = 9;     //	UsrCertNO��֤��󶨺ţ�//NETCA��ķӡ�����Ϊ1��GDCA��ΪTrustID�����Ϊ51��
var NETCAPKI_CERT_OLDUSRCERTNO = 10; // OldUsrCertNo���ɵ��û�֤���ֵ��NETCA���󶨾�ķӡ�����Ϊ31��GDCA����ΪTrustID�����Ϊ51��
// ֤�������Ϣϸ��������
var NETCAPKI_CERT_SUBJECT_NAME = 11; //	֤���������ƣ���CN��ȡCN��ֵ����CN�ȡO��ֵ
var NETCAPKI_CERT_SUBJECT_CN = 12;   //	Subject�е�CN�������
var NETCAPKI_CERT_SUBJECT_O =	13;    //	Subject�е�O���λ��
var NETCAPKI_CERT_SUBJECT_L =	14;    //	Subject�е�L���ַ��
var NETCAPKI_CERT_SUBJECT_EMAIL =	15;//	Subject�е�Email
var NETCAPKI_CERT_SUBJECT_DEPARTMENT = 16;//	Subject�еĲ�����
var NETCAPKI_CERT_SUBJECT_COUNTRY = 17;   //	�û�������
var NETCAPKI_CERT_SUBJECT_CITY = 18;      //	�û�ʡ����
// �ض�֤����Ϣ��
var NETCAPKI_CERT_CAID = 21;               //	CA ID�� CA��ID:1��NETCA��2��GDCA��3��SZCA��0��δ֪CA
var NETCAPKI_CERT_CERTCLASSIFY = 22;      //	CertClassify��֤�����ͣ�1��������֤�飻2������֤�� 3: ����֤�飻4������Ա��֤�飻5������ҵ��֤�飻ע�������͹��ܱ�׼����0������֤��var NETCAPKI_CERT_CERTID = 23;            //	CertID��֤��Ψһ��ʶ�� GDCAΪ���κţ������51 NETCA��Ŀǰ�ޣ��Ժ�����У������Ժ�
// NETCA��չ��		
var NETCAPKI_CERT__PREVCERT_THUMBPRINT = 31;//	��ķӡ��Ϣ���籣��������ȡ��������Ϊ������
var NETCAPKI_CERT_TAXPAYERNUM	= 32;         //	��˰�˱��루�籣��������ȡ��������Ϊ������
var NETCAPKI_CERT_ENTERPRISENUM = 33;       //	��ҵ���˴��루�籣��������ȡ��������Ϊ������
var NETCAPKI_CERT_TAXREGISTERNUM =	34;       //	˰��ǼǺţ��籣��������ȡ��������Ϊ������
var NETCAPKI_CERT_CERTFROM	= 35;             //	֤����Դ�أ��籣��������ȡ��������Ϊ������
// GDCA��չ��		
var NETCAPKI_CERT_TRUSTID = 51;              //	GDCA�����κ�TrustID


//֤������	ֵ	˵��
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_DISPLAY_NAME   =	9; //	�䷢����ʾ��
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_C              =	10;//	�䷢�ߵ�C
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_O              =	11;//	�䷢�ߵ�O
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_OU             =	12;//	�䷢�ߵ�OU
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_CN             =	13;//	�䷢�ߵ�CN
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_EMAIL          =	14;//	�䷢�ߵ�Email
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_DISPLAY_NAME  =	16;//	������ʾ��
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_C             =	17;//	�����C
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_O	          = 18;//	�����O
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_OU            =	19;//	�����OU
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_CN	          = 20;//	�����CN
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_EMAIL         =	21;//	�����Email
var NETCAPKI_CERT_ATTRIBUTE_EX_FRIENDLY_NAME	  = 22;//	�üǵ�����
var NETCAPKI_CERT_ATTRIBUTE_EX_NAME	              = 23;//	֤��ӵ��������
var NETCAPKI_CERT_ATTRIBUTE_EX_ORGANIZATION	      = 24;//   ֤��ӵ�������ڵĵ�λ
var NETCAPKI_CERT_ATTRIBUTE_EX_DEPARTMENT	      = 25;//   ֤��ӵ�������ڵĲ���
var NETCAPKI_CERT_ATTRIBUTE_EX_EMAIL	          = 26;//	֤��ӵ���ߵ�EMail
var NETCAPKI_CERT_ATTRIBUTE_PREVCERT_THUMBPRINT   = 29;//	����ǰ��֤���ķӡ
var NETCAPKI_CERT_ATTRIBUTE_UPN	                  = 36;//   UPN
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_ST             =	37;//	�䷢�ߵ�ST
var NETCAPKI_CERT_ATTRIBUTE_ISSUER_L	          = 38;//   �䷢�ߵ�L
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_ST            =	39;//   �����ST
var NETCAPKI_CERT_ATTRIBUTE_SUBJECT_L             =	40;//   �����L

// ֤����֤��־	ֵ	˵��
var NETCAPKI_CERT_VERIFY_FLAG_VERIFY_REVOKE = 1;          //	��֤������Ϣ
var NETCAPKI_CERT_VERIFY_FLAG_ONLINE = 2;                 //	������֤
var NETCAPKI_CERT_VERIFY_FLAG_VERIFY_CACERT_REVOKE = 4;   //	��֤CA��������Ϣ
var NETCAPKI_CERT_VERIFY_FLAG_VERIFY_OCSP = 16;           //	ʹ��OCSP����֤
var NETCAPKI_CERT_VERIFY_FLAG_VERIFY_CRL = 32;            //	ʹ��CRL����֤


//Hash�㷨	ֵ	˵��
var NETCAPKI_ALGORITHM_MD5 = 4096;            //	MD5�㷨
var NETCAPKI_ALGORITHM_SHA1	= 8192;           //    SHA1�㷨
var NETCAPKI_ALGORITHM_SHA224 = 12288;        //	SHA224�㷨
var NETCAPKI_ALGORITHM_SHA256 =	16384;        //	SHA256�㷨
var NETCAPKI_ALGORITHM_SHA384 =	20480;        //	SHA384�㷨
var NETCAPKI_ALGORITHM_SHA512 =	24576;        //	SHA512�㷨
var NETCAPKI_ALGORITHM_SM3 = 28672;           //	SM3�㷨


//BASE64��ѡ��	ֵ	˵��
var NETCAPKI_BASE64_ENCODE_NO_NL  = 1;        //	����ѡ���������˸�λ�������ʱ������
var NETCAPKI_BASE64_DECODE_STRICT = 2;        //	����ѡ���������˸�λ�������ʱ�������������

//CMS���뷽ʽ	ֵ	˵��
var NETCAPKI_CMS_ENCODE_DER	= 1;              //	DER����
var NETCAPKI_CMS_ENCODE_BASE64 = 2;           //	DER������پ��������е�BASE64����
var NETCAPKI_CMS_ENCODE_BASE64_MULTILINE= 3;  //	DER������پ������е�BASE64����


/* �㷨���� */
var NETCAPKI_SHA1_ALGORITHM= 1;
var NETCAPKI_ALGORITHM_RC2=0;
var NETCAPKI_ALGORITHM_DES = 6;
var NETCAPKI_ALGORITHM_SHA1WITHRSA=2;

//UI��־	ֵ	˵��
var NETCAPKI_UIFLAG_DEFAULT_UI = 1;  //	ȱʡֵ����ֻ��һ����û��֤�������£��������Ի������û�ѡ��
var NETCAPKI_UIFLAG_NO_UI =	2;       //	�Ӳ������Ի������û�ѡ��
var NETCAPKI_UIFLAG_ALWAYS_UI =	3;   //	���ǵ����Ի������û�ѡ��

//ASN.1���ַ�������	ֵ	˵��
var NETCAPKI_UTF8STRING	=1;  //UTF8String
var NETCAPKI_PRINTABLESTRING	=2;  //PrintableString
var NETCAPKI_IA5STRING	=3;  //	IA5String
var NETCAPKI_VISIBLESTRING	=4;  //	VisibleString
var NETCAPKI_BMPSTRING	=5;  //	BMPString
var NETCAPKI_OID	=6;  //	OID

/* CA֤���CN,CA��ʶ */
var CASTR=new Array("CN=NETCA","CN=GDCA","CN=SZCA");

/* ��������WIN7������JSʱ����ʾ���ؿؼ� */
var initialObj=new ActiveXObject("NetcaPki.Utilities");


/***************************************************/
/***********  1.  ����� 2012.3.24       ***********/
/***************************************************/

/***************5.2.1 �жϿؼ��Ƿ�װ�ɹ� ***************/
function isPKIInstalled()
{
	try
	{ 
		var utilObj = new ActiveXObject("NetcaPki.Utilities");
		if(typeof(utilObj) == "object")
	    {
	         utilObj =null;
		     return true;
	    }
	    utilObj =null;
		return false;
	}
	catch (e)
	{   
 		return false;
	}
}

/*************** 5.2.2 �ж��Ƿ���֤��  ***************/
function isHasCert(caType)
{
	var storeObj;
	var count;
   	var isHas=false;

    try
    {
        storeObj = new ActiveXObject("NetcaPki.Store");
    }
    catch(e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }
    
    storeObj.Open(0, NETCAPKI_CERT_STORE_NAME[0]); 
     
    count = storeObj.GetCertificateCount();
    if(count <= 0)
    {  
        storeObj.Close();
        storeObj = null;
   	    return false;
   	}
    for(i=1; i<count+1; i++)
	{
		var cert = storeObj.GetCertificate(i);
		var issuer = cert.Issuer;
		switch(caType)
		{
			case NETCAPKI_NETCA_YES:
				if(issuer.indexOf("CN=NETCA") >= 0)
				{
					isHas= true;
				}
				break;
			case NETCAPKI_NETCA_NO:
				 if(issuer.indexOf("CN=GDCA") >= 0)
				{
					isHas= true;
				}
				break;
			case NETCAPKI_NETCA_OTHER:
				 // NETCA �� GDCA
				if( (issuer.indexOf("CN=NETCA") >= 0) || (issuer.indexOf("CN=GDCA") >= 0) )
				{
					isHas= true;
				}
				break;
			case NETCAPKI_NETCA_ALL:
				isHas= true;
			default:
				// ���У� ����ѭ��ǰ���Ѿ��жϳ���֤��
				isHas= false;
		}
		if(isHas==true){
			break;
		}
    }
    storeObj.Close();
    storeObj = null;

	return isHas;  
}

/**********  5.2.3 �ж��Ƿ�����֤֤ͨ���� ************/
function isHasChain(caType)
{
	var certs = getX509Certificates(1, NETCAPKI_CERT_STORE_NAME_ROOT, NETCAPKI_CERTTYPE_ALL, caType);
	if (certs==null || certs.Count<=0)
	{
   		alert("δ��װ��֤֤ͨ����,�뵽www.cnca.net����֤����,����װ!");
   		return false;
	}
	return true;  
}

/***************************************************/
/***********   2. ֤���� 2012.3.23       ***********/
/***************************************************/

/*********** 5.3.1 ѡ��֤�鼯 ***********   
 * storeLocation:NETCAPKI_LOCAL_MACHINE_STORE = 0;NETCAPKI_CURRENT_USER_STORE= 1;
 * storeName:NETCAPKI_MY_STORE=0(����);NETCAPKI_OTHER_STORE:1(������);NETCAPKI_CA_STORE= 2;NETCAPKI_ROOT_STORE= 3;
 * certType: NETCAPKI_CERTTYPE_ALL= 0;NETCAPKI_CERTTYPE_SIGN= 1;NETCAPKI_CERTTYPE_ENV= 2;
 * netcaType:NETCAPKI_NETCA_ALL= 0;NETCAPKI_NETCA_YES= 1;NETCAPKI_NETCA_NO= 2;
 */
function getX509Certificates(storeLocation, storeName, certType, netcaType)
{	
	var storeObj;
	var certArray = new Array();
	var count;

    try
    {
        storeObj = new ActiveXObject("NetcaPki.Store");
    }
    catch (e)
    {
        storeObj = null;
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }
 
   // alert(" storeLocation:"+storeLocation+" storeName:"+storeName+" TYPE:"+NETCAPKI_CERT_STORE_TYPE[storeLocation]+" Name:"+NETCAPKI_CERT_STORE_NAME[storeName]);
    storeObj.Open(NETCAPKI_CERT_STORE_TYPE[storeLocation], NETCAPKI_CERT_STORE_NAME[storeName]);  
    count = storeObj.GetCertificateCount(); 
     
    if(count <= 0)
    {
        storeObj.Close();
        storeObj = null;
        alert("û��֤��!");
		return null;
    }

  	for(i=1; i<count+1 ;i++)
	{
		var cert;
		var issuer;
		cert = storeObj.GetCertificate(i);
		issuer = cert.Issuer;
		
		if(certType == NETCAPKI_CERTTYPE_ALL)
		{
		    if((netcaType == NETCAPKI_NETCA_ALL)
				|| ((netcaType == NETCAPKI_NETCA_YES) && (issuer.indexOf("CN=NETCA") >= 0))
				|| ((netcaType == NETCAPKI_NETCA_NO)  &&  (issuer.indexOf("CN=NETCA") < 0)))  //////
		    {
				certArray.push(cert);
		    }
		    else if(netcaType == NETCAPKI_NETCA_OTHER)
		    {
		        for(var j=0; j<CASTR.length; j++)
				{
					if(issuer.indexOf(CASTR[j]) >= 0)
					{
						certArray.push(cert);
						break;
				    }
				}
		    }
		}// ��һ��certType�жϽ��� 
		else if(certType == NETCAPKI_CERTTYPE_SIGN)
	    {
		    if((netcaType == NETCAPKI_NETCA_ALL)
				|| ((netcaType == NETCAPKI_NETCA_YES) && (issuer.indexOf("CN=NETCA") >= 0))
				|| ((netcaType == NETCAPKI_NETCA_NO) && (issuer.indexOf("CN=NETCA") < 0)))///////////
		    {
		        if((cert.KeyUsage == (NETCAPKI_KEYUSAGE_DIGITALSIGNATURE | NETCAPKI_KEYUSAGE_NONREPUDIATION)) 
					|| (cert.KeyUsage == NETCAPKI_KEYUSAGE_NO) || (cert.KeyUsage ==NETCAPKI_KEYUSAGE_DIGITALSIGNATURE) )
				{
	        		certArray.push(cert);
	        	}
		    }
		    else if(netcaType==NETCAPKI_NETCA_OTHER)
		    {
		        for(var j=0; j<CASTR.length; j++)
				{
					if(issuer.indexOf(CASTR[j])>=0)
					{
						if( (cert.KeyUsage == (NETCAPKI_KEYUSAGE_DIGITALSIGNATURE | NETCAPKI_KEYUSAGE_NONREPUDIATION)) 
							|| (cert.KeyUsage == NETCAPKI_KEYUSAGE_NO) || (cert.KeyUsage ==NETCAPKI_KEYUSAGE_DIGITALSIGNATURE) )
				        {
	        	        	certArray.push(cert);
	        	        }
						break;
				    }
				}
		    }	    
	    }//�ڶ���certType�жϽ���
	    else if(certType == NETCAPKI_CERTTYPE_ENV)
	    {
	        if((netcaType == NETCAPKI_NETCA_ALL)
				|| ( (netcaType == NETCAPKI_NETCA_YES) && (issuer.indexOf("CN=NETCA") >= 0) )
				|| ( (netcaType == NETCAPKI_NETCA_NO) && (issuer.indexOf("CN=NETCA") < 0) ) )
		    {
		        if((cert.KeyUsage == (NETCAPKI_KEYUSAGE_KEYENCIPHERMENT | NETCAPKI_KEYUSAGE_DATAENCIPHERMENT)) 
					|| (cert.KeyUsage == NETCAPKI_KEYUSAGE_NO) 
					|| (cert.KeyUsage ==NETCAPKI_KEYUSAGE_KEYENCIPHERMENT) )
				{
	        		certArray.push(cert);
	        	}
  		    }
  		    else if (netcaType == NETCAPKI_NETCA_OTHER)
		    {
		        for(var j=0; j<CASTR.length; j++)
		    	{
				    if(issuer.indexOf(CASTR[j]) >= 0)
				    {
				        if((cert.KeyUsage == (NETCAPKI_KEYUSAGE_KEYENCIPHERMENT | NETCAPKI_KEYUSAGE_DATAENCIPHERMENT)) 
							|| (cert.KeyUsage == NETCAPKI_KEYUSAGE_NO) 
							|| (cert.KeyUsage ==NETCAPKI_KEYUSAGE_KEYENCIPHERMENT))
		        		{
	                 		certArray.push(cert);
	                 	}
						break;
				    }
		        }
		    }
	    }// ������certType�жϽ���
	}// End for
	
	storeObj.Close();
	storeObj = null;
	return certArray;
}

/***********  5.3.2	��ȡ֤�� ***********             
 * storeLocation:NETCAPKI_LOCAL_MACHINE_STORE = 0(���ؼ����);NETCAPKI_CURRENT_USER_STORE= 1(��ǰ�û�);
 * storeName:NETCAPKI_MY_STORE=0(����);NETCAPKI_OTHER_STORE:1(������);NETCAPKI_CA_STORE= 2;NETCAPKI_ROOT_STORE= 3;
 * certType: NETCAPKI_CERTTYPE_ALL= 0(����);NETCAPKI_CERTTYPE_SIGN= 1(ǩ��);NETCAPKI_CERTTYPE_ENV= 2(����);
 * netcaType:NETCAPKI_NETCA_ALL= 0(����);NETCAPKI_NETCA_YES= 1(��֤ͨ);NETCAPKI_NETCA_NO= 2(����֤ͨ);
 */
function getX509Certificate(storeLocation, storeName, certType, netcaType)
{	
 	var storeObj;
 	var cert;
	var count;
	var filter="InValidity='True'";
	//alert("cert:"+storeLocation+storeName+certType+netcaType);
 	try
    {
 	     storeObj = new ActiveXObject("NetcaPki.Store");
	     //cert =  new ActiveXObject("NetcaPki.Certificate");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }
    storeObj.Open(NETCAPKI_CERT_STORE_TYPE[storeLocation], NETCAPKI_CERT_STORE_NAME[storeName]); 
    count = storeObj.GetCertificateCount();
    if(count<=0)
    {  
        storeObj.Close();
        storeObj = null;
   	    alert("֤���û��֤��");
   	    return null;
   	}

    if(certType == NETCAPKI_CERTTYPE_ALL)
    {
        if (netcaType==NETCAPKI_NETCA_YES)
        {
            filter+="&&(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA')";
        }
        else  if (netcaType==NETCAPKI_NETCA_NO)
        {
            filter+="&&!(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA')";
        }
        else  if (netcaType==NETCAPKI_NETCA_OTHER)
        {
    	    filter+="&&(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA'||IssuerO='GDCA Certificate Authority'||IssuerO='GDCA'||IssuerO='SZCA Certificate Authority')";
        }
        else
        {
        
        }
    }
    else if (certType == NETCAPKI_CERTTYPE_SIGN)
    {
        if (netcaType==NETCAPKI_NETCA_YES)
        {
            filter+="&&(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA')&&CertType='Signature'";	
        }
        else  if (netcaType==NETCAPKI_NETCA_NO)
        {
            filter+="&&!(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA')&&CertType='Signature'";
        }
        else  if (netcaType==NETCAPKI_NETCA_OTHER)
        {
            filter+="&&(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA'||IssuerO='GDCA Certificate Authority'||IssuerO='GDCA'||IssuerO='SZCA Certificate Authority')&&CertType='Signature'";
        }
        else
        {
            filter+="&&CertType='Signature'";
        }
    }
    else if (certType == NETCAPKI_CERTTYPE_ENV)
    {
        if (netcaType==NETCAPKI_NETCA_YES)
        {
            filter+="&&(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA')&&CertType='Encrypt'";
        }
        else  if (netcaType==NETCAPKI_NETCA_NO)
        {
            filter+="&&!(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA')&&CertType='Encrypt'";
        }
        else  if (netcaType==NETCAPKI_NETCA_OTHER)
        {
            filter+="&&(IssuerO='NETCA Certificate Authority'||IssuerO='NETCA'||IssuerO='GDCA Certificate Authority'||IssuerO='GDCA')&&CertType='Encrypt'";
        }
        else
        {
            filter+="&&CertType='Signature'";
        }
    }
    else
    {
        storeObj.Close();
        storeObj = null;
        return null;
    }

    cert = storeObj.FindCertificate(filter);
    storeObj.Close();
    storeObj = null;
    return cert;
}

/** 5.3.3	��ȡ֤�����
 * 
 */
function getX509CertificateByString(certContent)
{
    var certObj;
    if(certContent==null)
	{
		return null;
	}
	
 	try
    {
 	     certObj = new ActiveXObject("NetcaPki.Certificate");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }
    
    return certObj.Decode(certContent);
}

/***********  5.3.4	��ȡ֤�飺�����ض����ֵ��ȡ֤�� **********����##��û�в��ԣ��ú�������û��д��
 * storeLocation:NETCAPKI_LOCAL_MACHINE_STORE = 0(���ؼ����);NETCAPKI_CURRENT_USER_STORE= 1(��ǰ�û�);
 * storeName:NETCAPKI_MY_STORE=0(����);NETCAPKI_OTHER_STORE:1(������);NETCAPKI_CA_STORE= 2;NETCAPKI_ROOT_STORE= 3;
 * certType: NETCAPKI_CERTTYPE_ALL= 0(����);NETCAPKI_CERTTYPE_SIGN= 1(ǩ��);NETCAPKI_CERTTYPE_ENV= 2(����);
 * netcaType:NETCAPKI_NETCA_ALL= 0(����);NETCAPKI_NETCA_YES= 1(��֤ͨ);NETCAPKI_NETCA_NO= 2(����֤ͨ);
 * iValueType:   ֤����Ϣ�ض������
 * value:        ֤����Ϣ�ض���ֵ
 */ 
function getX509CertificateByValue(storeLocation, storeName, certType, netcaType, iValueType, value)
{
    var myCerts = getX509Certificates(storeLocation, storeName, certType, netcaType);
    var certCount = myCerts.length;
    var utilObj;
    
    try
    {
 	     utilObj = new ActiveXObject("NetcaPki.Utilities");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }

    if(certCount<=0)
    {
        utilObj= null;
        alter("û�л�ȡ��֤��");
        return null;
    }
    
    // ��������ʱֻ���� ֤��ķӡ
   	for(var i=0; i<certCount; i++)
	{
	    switch (iValueType)
        {
            case NETCAPKI_CERT_THUMBPRINT: //֤��ķӡ 
                rvStr = utilObj.BinaryToHex(myCerts[i].ThumbPrint(NETCAPKI_ALGORITHM_SHA1), true);
               // value = value.tolocaleUpperCase();
                break;
            default:
                rvStr = null;
        }
        
        if(rvStr == value) 
        {
            utilObj= null;
            return myCerts[i];
        }
	}
	
    return null;
}

/***********5.3.5 ��ȡ֤����Ϣ: ����֤�� ��  ֤����Ϣ�ض������ ��ȡ֤����Ϣ
 // ֤�������Ϣ��
    1	֤��ķӡ
    2	֤�����к�
    3	֤��Subject
    4	֤��䷢��
    5	֤����Ч����
    6	֤����Ч��ֹ
    7	��Կ�÷� KeyUsage
// ֤�������Ϣϸ��������
    11	֤���������ƣ���CN��ȡCN��ֵ����CN�ȡO��ֵ
    12	Subject�е�CN�������
    13	Subject�е�O���λ��
    14	Subject�е�L���ַ��
    15	Subject�е�Email
    16	Subject�еĲ�����
    17	�û�������
    18	�û�ʡ����

// �ض�֤����Ϣ��
    21	CAID֤������:1��NETCA��2��GDCA��3��SZCA��0��δ֪CA
    22	CertID��֤�����ͣ�1��������֤�飻2������֤�飻3: ����֤�飻4������Ա��֤�飻5������ҵ��֤�飻ע�������͹��ܱ�׼���� 0������֤��    23	CertID��֤��Ψһ��ʶ��GDCAΪ���κţ������51;NETCA��Ŀǰ�ޣ��Ժ�����У������Ժ�
    
// NETCA��չ��		
	31	��ķӡ��Ϣ���籣��������ȡ��������Ϊ������
	32	��˰�˱��루�籣��������ȡ��������Ϊ������
	33	��ҵ���˴��루�籣��������ȡ��������Ϊ������
	34	˰��ǼǺţ��籣��������ȡ��������Ϊ������
	35	֤����Դ�أ��籣��������ȡ��������Ϊ������
// GDCA��չ��		
	51	GDCA�����κ�TrustID

 * ��������ַ���������֤����Ϣ
 */
function getX509CertificateInfo(oCert, iValueType)
{  	
    var rvStr;
    var temp;
    var utilObj;

	if (oCert==null)
	{
		return null;
	}
	if(iValueType==null)
	{
	    return null;
	}
	
	try
    {
 	     utilObj = new ActiveXObject("NetcaPki.Utilities");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }
    switch (iValueType)
    {
        case NETCAPKI_CERT_THUMBPRINT: //֤��ķӡ
            try
            {
                rvStr = utilObj.BinaryToHex(oCert.ThumbPrint(NETCAPKI_ALGORITHM_SHA1),true);
            }
            catch(e)
            {
                 rvStr = "";
            }
            break;
        case NETCAPKI_CERT_SERIALNUMBER: //֤�����к�
            rvStr = oCert.SerialNumber;
           break;
        case NETCAPKI_CERT_SUBJECT: //֤��Subject
            rvStr = oCert.Subject;
            break;
        case NETCAPKI_CERT_ISSUER: // ֤��䷢��
            rvStr = oCert.Issuer;
            break;
        case NETCAPKI_CERT_VALIDFROMDATE://֤����Ч����
            var fromDate =  new Date(oCert.ValidFromDate);
            rvStr = fromDate.toDateString();
            break;
        case NETCAPKI_CERT_VALIDTODATE://֤����Ч��ֹ
            var toDate =  new Date(oCert.ValidToDate );
            rvStr = toDate.toDateString();
            break;     
        case NETCAPKI_CERT_KEYUSAGE: //��Կ�÷� KeyUsage
            rvStr = ""+ oCert.KeyUsage;
            break;
        case NETCAPKI_CERT_USRCERTNO: // UsrCertNO��֤��󶨺ţ�NETCA��ķӡ�����Ϊ1��GDCA��ΪTrustID�����Ϊ51��
            var issuer_o;
            issuer_o = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_ISSUER_O);
            if(issuer_o.indexOf("NETCA")>=0)
            {
                 rvStr = utilObj.BinaryToHex(oCert.ThumbPrint(NETCAPKI_ALGORITHM_SHA1),true);
            }
            else if(issuer_o.indexOf("GDCA")>=0)
            {
                 rvStr = getX509CertificateInfo(oCert, 51);
            }
            else
            {
                 rvStr = "δ֪CA";
            }
            break;
        case NETCAPKI_CERT_OLDUSRCERTNO:
            if (getX509CertificateInfo(oCert, 21)=="1") 
            {
                return getX509CertificateInfo(oCert, 31);
  		    }
		    else if (getX509CertificateInfo(oCert, 21)=="2") 
		    {
                return getX509CertificateInfo(oCert, 51);
            }
        case NETCAPKI_CERT_SUBJECT_NAME: // ֤���������ƣ���CN��ȡCN��ֵ����CN�ȡO��ֵ�� 
            try
            {
                  rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_CN);
            }
            catch(e)
            {
                 rvStr = "";
            } 
          
            if(rvStr =="")
            {
                try
                {
                     rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_O);
                }
                catch(e)
                {
                     rvStr = "";
                } 
            }
            break;
        case NETCAPKI_CERT_SUBJECT_CN: //Subject�е�CN�������
            try
            {
                 rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_CN);
            }
            catch(e)
            {
                 rvStr = "";
            } 
            break;
        case NETCAPKI_CERT_SUBJECT_O: //Subject�е�O���λ)
            try
            {
                 rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_O);
            }
            catch(e)
            {
                 rvStr = "";
            } 
            break;
        case NETCAPKI_CERT_SUBJECT_L: //Subject�е�L���ַ��
            try
            {
                rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_L);
            }
            catch(e)
            {
                 rvStr = "";
            } 
            break;
        case NETCAPKI_CERT_SUBJECT_EMAIL: //Subject�е�Email
            var temp = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_ISSUER_O);
            if(temp.indexOf("NETCA")>=0)
            {
                try
                {
                    rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_EMAIL);
                }
                catch(e)
                {
                     rvStr = "";
                }
            }
            break;
       case NETCAPKI_CERT_SUBJECT_DEPARTMENT:  //Subject�еĲ�����
            try
            {
                rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_EX_DEPARTMENT);
            }
            catch(e)
            {
                 rvStr = "";
            }
            break; 
        case NETCAPKI_CERT_SUBJECT_COUNTRY:   //�û�������         
            try
            {
                 rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_C);
            }
            catch(e)
            {
                 rvStr = "";
            }
            break;
        case NETCAPKI_CERT_SUBJECT_CITY: //  �û�ʡ���� 
            try
            {
                 rvStr = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_SUBJECT_ST);

            }
            catch(e)
            {
                 rvStr = "";
            }
            break;
        case NETCAPKI_CERT_CAID: // CAID  1��NETCA��2��GDCA��3��SZCA��0��δ֪CA
            var issuer_o;
            issuer_o = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_ISSUER_O);
            if(issuer_o.indexOf("NETCA")>=0)
            {
                 rvStr = "1";
            }
            else if(issuer_o.indexOf("GDCA")>=0)
            {
                 rvStr = "2";
            }
            else if(issuer_o.indexOf("SZCA")>=0)
            {
                 rvStr = "3";
            }
            else
            {
                 rvStr = "0";
            }
            break;
       
       case NETCAPKI_CERT_CERTCLASSIFY: //CertID��֤������
           rvStr = "3";
           break;
        case NETCAPKI_CERT_CERTID: // ֤��Ψһ��ʶ
            var issuer_o = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_ISSUER_O);
            if(issuer_o.indexOf("NETCA")>=0)
            {
                 rvStr = "����";
            }
            else if(issuer_o.indexOf("GDCA")>=0)
            {
                 rvStr = getX509CertificateInfo(oCert, 51);
            }
            else
            {
                 rvStr = "δ֪CA";
            }
           break;
        case NETCAPKI_CERT__PREVCERT_THUMBPRINT:  // ��ķӡ��Ϣ 
            var issuer_o;
            issuer_o = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_ISSUER_O);
            if(issuer_o.indexOf("NETCA")>=0)
            {
                try
                {
                     rvStr = utilObj.BinaryToHex(oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_PREVCERT_THUMBPRINT),true);
                }
                catch(e)
                {
                     rvStr = "";
                }
            }
            else if(issuer_o.indexOf("GDCA")>=0)
            {
                 rvStr = "";
            }
            else
            {
                 rvStr = "δ֪CA";
            }
          
           break;
     /* ����û���ṩ OID��Ϣ���޷���ȡ����δʵ��
        case NETCAPKI_CERT_TAXPAYERNUM: //��˰�˱��루�籣��������ȡ��������Ϊ������
           break;
        case NETCAPKI_CERT_ENTERPRISENUM:    //��ҵ���˴��루�籣��������ȡ��������Ϊ������
            break;

	    case NETCAPKI_CERT_TAXREGISTERNUM:    //˰��ǼǺţ��籣��������ȡ��������Ϊ������	
	        break;

	    case NETCAPKI_CERT_CERTFROM:    //֤����Դ��	
	        break;
     */
	    case  NETCAPKI_CERT_TRUSTID:    //GDCA�����κ�TrustID	
	        var issuer_o;
	        var oid = "1.2.86.21.1.3";
	        try
	        {
                issuer_o = oCert.GetStringInfo(NETCAPKI_CERT_ATTRIBUTE_ISSUER_O);
                if(issuer_o.indexOf("GDCA")>=0)
                {
                  //var utilObj =  new ActiveXObject("NetcaPki.Utilities");
                    temp = utilObj.Decode(oCert.GetExtension(oid), NETCAPKI_CP_UTF8);
                   
                    rvStr = temp.substr(2,temp.length-2);
                   // rvStr = utilObj.Decode(temp.slice(2) , NETCAPKI_CP_UTF8);
                }
                else
                {
                     rvStr = "";
                }
            }
            catch(e)
            {
                rvStr = "";
            }
            
	        break;
        default:
            rvStr = null;
            break;
    }
    return rvStr;
}

/****** ��ȡ֤����Ϣ: ����֤�� ��  OID ��ȡ֤����Ϣ �� ĿǰDecodeASN1String ����ʧ��*******
 * oCert: ֤��;
 * OID:	String���ͣ�OID��ֵ
 * �����OID��Ϣ��base64���� 
 */
function getX509CertificateInfoByOID(oCert, OID)
{
    var OIDStr;
    var utilObj;
    if (oCert==null)
	{
		return null;
	} 

    try
    {
        utilObj= new ActiveXObject("NetcaPki.Utilities");
    }
    catch(e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }

    OIDStr =oCert.GetExtension (OID);
    
   
   return utilObj.Base64Encode( OIDStr,1);
}

/***************************************************/
/***********  4.ǩ���� 2012.3.23         ***********/
/***************************************************/

/**5.4.1	PKCS#7ǩ�� **/
function signPKCS7(sSource, IsNotHasSource)
{
    return signPKCS7ByPwd(sSource,IsNotHasSource);
}

/**5.4.2	PKCS#7ǩ�� **/
function signPKCS7ByPwd(sSource, IsNotHasSource, pwd)
{
    var oCert;
    try
    {
        oCert= new ActiveXObject("NetcaPki.Certificate");
    }
    catch(e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }
    
    oCert = getX509Certificate(1, NETCAPKI_CERT_STORE_NAME_MY, NETCAPKI_CERTTYPE_SIGN, NETCAPKI_NETCA_OTHER);
	if(oCert==null)
	{
		alert("δѡ��֤��,�����Ƿ������Կ!");
		return null;
   	}

   	return signPKCS7ByCert(sSource,oCert,IsNotHasSource,pwd);
}  

/**5.4.3	PKCS#7ǩ����������ǰ��**/
function signNetCA(bContent,IsNotHasSource)
{
    return signPKCS7ByPwd(bContent,IsNotHasSource,"");
}  

/**5.4.4	ʹ��ָ��֤��,PKCS#7ǩ�� **/
function signPKCS7ByCert(bContent,oCert,IsNotHasSource,pwd)
{	
 	var signObj;
 	var certObj;
   	var utilObj;
	if(bContent=="")
	{   
	    alert("ԭ������Ϊ��!");
		return null;
    }

	try
	{
		utilObj = new ActiveXObject("NetcaPki.Utilities");
		signObj = new ActiveXObject("NetcaPki.SignedData");
	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null;
	}
	
    if (signObj.SetSignCertificate(oCert, pwd, false) == false)
    {
        alert("����ǩ��֤��ʧ��");
		return null;
    }
    signObj.SetSignAlgorithm(-1, NETCAPKI_ALGORITHM_SHA1WITHRSA);
    var tbs;
    var str; 
    
    if(typeof(bContent)=="string" || typeof(bContent)=="String")
    {
        // ԭ�����ַ���
        //alert("string");
        tbs = utilObj.Encode(bContent,NETCAPKI_CP_UTF8);
     }
    else 
    {
        // ԭ��������
         tbs = bContent;
    }

    // 1������ԭ�ģ�0����ԭ��
    if(IsNotHasSource==0||IsNotHasSource=="0" || IsNotHasSource==false)
    { 
        // ��ԭ��
          //      alert("��ԭ��");
         signObj.Detached = false;   
         str = signObj.Sign(tbs,NETCAPKI_CMS_ENCODE_BASE64);
    }
    else
    {
         signObj.Detached = true;
         str = signObj.Sign(tbs,NETCAPKI_CMS_ENCODE_BASE64);
    }
    signObj = null;
	utilObj = null;
    return str;
}

/**5.4.5	PKCS#7ǩ����֤**/
function verifyPKCS7(sSource, sSignature, IsNotHasSource)
{
    var signObj;
 	var certObj;
   	var utilObj;
	if(sSource=="")
	{   
	    alert("ԭ������Ϊ��!");
		return null;
    }
    if(sSignature=="")
    {
       alert("ǩ����ϢΪ��!");
       return null;
    }
    
	try
	{
		utilObj = new ActiveXObject("NetcaPki.Utilities");
		signObj = new ActiveXObject("NetcaPki.SignedData");

	}
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null ;
	}
	
    var sSourceS;
    var tbs;
    if(typeof(sSource)=="string" || typeof(sSource)=="String")
    {
        // ԭ�����ַ���
        sSourceS = utilObj.Encode(sSource,NETCAPKI_CP_UTF8);
     }
    else
    {
        // ԭ��������
        sSourceS = sSource;
    }
    
    // 1������ԭ�ģ�0����ԭ��
	if(IsNotHasSource==0||IsNotHasSource=="0" || IsNotHasSource==false)
    {	
         // ��ԭ��
        signObj.Detached = false;  
        tbs = signObj.Verify(sSignature);
        if(tbs=="")
        {
   		    alert("ԭʼǩ����Ϣ��֤ûͨ��!");
		    return null;
	    }
	    else
	    {
	        alert("ǩ����Ϣ��֤ͨ��!");
	    }  
    }
    else
    {
         // ����ԭ��
        signObj.Detached = true;
        tbs = signObj.DetachedVerify(sSourceS,sSignature, false);
        if(!tbs)
        {
   		    alert("ԭʼǩ����Ϣ��֤ûͨ��!");
		    return null;
	    }
	    else
	    {
	        alert("ǩ����Ϣ��֤ͨ��!");
	    }  
    }

    certObj=signObj.GetSignCertificate(-1);
	return certObj;
}

function getSourceFromSignature(sSignature)
{
    var signObj;
 	var certObj;
   	var utilObj;
	
    if(sSignature=="")
    {
       alert("ǩ����ϢΪ��!");
       return null;
    }
    
    try
	{
		utilObj = new ActiveXObject("NetcaPki.Utilities");
		signObj = new ActiveXObject("NetcaPki.SignedData");
    }
	catch (e)
	{
		alert("��װ���ɹ�!");
		return null ;
	}
	
	return utilObj.Decode(signObj.Verify(sSignature, true),NETCAPKI_CP_UTF8);
}

/***************************************************/
/***********    ������ 2012.3.23         ***********/
/***************************************************/

/**	PKCS#7����  *******
 * ���룺sSource:	String��ԭ��;
 *        oCert	֤��
 * �����byte ����
 */
function encryptPKCS7(bContent,oCert)
{
    var NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC = 6;
    
    var utilObj;
    var certObj;
    var envObj;
    var data;
    var cipher;
    
    try
    {
        utilObj = new ActiveXObject("NetcaPki.Utilities");
        envObj=new ActiveXObject("NetcaPki.EnvelopedData");

    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }  
    
    data = utilObj.Encode(bContent, NETCAPKI_CP_UTF8);
    envObj.EncryptAlgorithm = NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC;
    if (envObj.AddCert(oCert) == false)
    {
       alert("��Ӽ���֤��ʧ��");
       return null;
    }

    cipher=envObj.Encrypt(data,NETCAPKI_CMS_ENCODE_DER);
    return cipher; 
}

/**	PKCS#7����  *******
 * ���룺bEnvData:	 	byte[]����������;
 * �����String 	PKCS#7���ܺ����Ϣ
 */
function decryptPKCS7(bEnvData)
{
    var utilObj;
    var envObj;
    var cipher;
    var clear;
 
    try
    {
        utilObj = new ActiveXObject("NetcaPki.Utilities");
        envObj=new ActiveXObject("NetcaPki.EnvelopedData");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }  
    
    return utilObj.Decode(envObj.Decrypt(bEnvData),NETCAPKI_CP_UTF8);
 }


/***************************************************/
/***********    ������ 2012.3.23         ***********/
/***************************************************/

/** Base64���� 
 * ���룺sSource	byte[]:ԭ��
 * �����String	BASE64��Ϣ; 
 */
function base64Encode(sSource)
{
    var utilObj;
   
    try
    {
        utilObj = new ActiveXObject("NetcaPki.Utilities");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    }  
    
   return  utilObj.Base64Encode(sSource,NETCAPKI_BASE64_ENCODE_NO_NL);
}

/** Base64���� 
 * ���룺string strBase64
 * �����Byte[]	ԭ��
 */
function base64Decode(strBase64)
{
    var utilObj;
   
    try
    {
        utilObj = new ActiveXObject("NetcaPki.Utilities");
    }
    catch (e)
    {
        alert("��ȡActiveXObjectʧ��!");
		return null;
    } 
   
    return  utilObj.Base64Decode(strBase64,NETCAPKI_BASE64_DECODE_STRICT);
}

/** 
 * Hash 
 * ���룺algo Hash�㷨
 *       sSource ԭ��
 * �����Hashֵ��Byte����
 */
function getHash(algo,sSource)
{
    var deviceObj;
   
    try
    {
       	deviceObj = new ActiveXObject("NetcaPki.Device");
    }
    catch (e)
    {
		alert("��װ���ɹ�!");
		return null;
    } 
    
    return deviceObj.Hash(sSource);
}

/** ��ȡ�����
 * ���룺length; 
 * �����Byte[]	�����
 */
function getRandom(length)
{
    var deviceObj;
    
    try
    {
       	deviceObj = new ActiveXObject("NetcaPki.Device");
    }
    catch (e)
    {
		alert("��װ���ɹ�!");
		return null;
    } 

    return deviceObj.GenerateRandom(length);
}

/**
 * �����ƶ��ļ�
 * ���룺sFilePath:String���ļ�������·����; 
 * �����Byte[]	�ļ�����
 */
function readFile(sFilePath)
{   
    if(sFilePath=="")
    {
        alert("�ļ�·��Ϊ��");
        return null;
    }
    
    var utilObj;
    var fileProcessObj;
    try
    {
       	utilObj =  new ActiveXObject("NetcaPki.Utilities");
        fileProcessObj = new ActiveXObject("LittleUtils.BinaryFile");
    }
    catch (e)
    {
		alert("��װ���ɹ�!");
		return null;
    } 
    return fileProcessObj.Read(sFilePath);
    //return utilObj.Base64Encode(fileProcessObj.Read(sFilePath),NETCAPKI_BASE64_ENCODE_NO_NL);
}


/**
 * ������д�ļ�
 * ���룺sFilePath:String���ļ�������·����; 
 *       bContent��Byte[]:����������  
 * �������
 */
function writeFile(sFilePath, bContent)
{
    if(sFilePath=="")
    {
        alert("�ļ�·��Ϊ��");
        return;
    } 
    
    var utilObj;
    var fileProcessObj;
    try
    {
       	utilObj =  new ActiveXObject("NetcaPki.Utilities");
        fileProcessObj = new ActiveXObject("LittleUtils.BinaryFile");
    }
    catch (e)
    {
		alert("��װ���ɹ�!");
		return;
    } 
    //var tbs = utilObj.Encode(bContent,NETCAPKI_CP_UTF8);
    fileProcessObj.Write(sFilePath, bContent);
    return ;
}

//-->