
var NETCAPKI_DEVICETYPE_ANY=-1;
var NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS=0;
var NETCAPKI_ENVELOPEDDATA_ALGORITHM_TDESCBC=3;
var NETCAPKI_KEYPAIR_ENCRYPT=1;
var NETCAPKI_CMS_ENCODE_DER=1;
var NETCAPKI_CMS_ENCODE_BASE64=2;
var NETCAPKI_BASE64_ENCODE_NO_NL=1;
var NETCAPKI_CP_UTF8 = 65001;
var algo;
var plaintext="1234567812345678";



function GetEncryptCert()
{
	var devicecount;
	var keypaircount;
	var certcount;
	var deviceobj;
	var devicesetobj;
	var keypairobj;
	var certobj;
	
	try
	{
		devicesetobj=new ActiveXObject("NetcaPki.DeviceSet");
		devicesetobj.GetAllDevice(NETCAPKI_DEVICETYPE_ANY,NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS);//��ȡ�����豸
		devicecount=devicesetobj.Count; 
		if (devicecount == 0)
		{
			WScript.Echo("������豸��");
			return null;
		}
		else if (devicecount > 1)
		{
			WScript.Echo("ֻ�ܲ���һ���豸��");
			return null;
		}
		
		deviceobj=devicesetobj.Item(1);
		devicesetobj=null;
		keypaircount=deviceobj.GetKeyPairCount();
		if(keypaircount<=0)
		{
			return null;
		}
		
		for(var i=1; i<=keypaircount; ++i)
		{
			keypairobj=deviceobj.GetKeyPair(i);
			if (keypairobj.Type==NETCAPKI_KEYPAIR_ENCRYPT)
			{
				certcount=keypairobj.GetCertificateCount();
				if(certcount<=0)
				{
					keypairobj=null;
					continue;
				}
				
				certobj=keypairobj.GetCertifcate(1);
				keypairobj=null;
				deviceobj=null;
				return certobj;
			}
			
			keypairobj=null;
		}
		
		deviceobj=null;
		return null;
	}
	catch(e)
	{
		WScript.Echo(e.message+"  ������ : "+e.number);
		return null;
	}
}


function EnvEncrypt()
{
	var cipher;
	var encryptcert;
	var utilobj;
	var envelopeddataobj;
	var plaintextarray;
	try
	{
		envelopeddataobj=new ActiveXObject("NetcaPki.EnvelopedData");
		envelopeddataobj.EncryptAlgorithm=NETCAPKI_ENVELOPEDDATA_ALGORITHM_TDESCBC;
		encryptcert=GetEncryptCert();
		if(encryptcert==null)
		{
			WScript.Echo("�豸û�м���֤�飡");
			return null;
		}
		if(envelopeddataobj.AddCert(encryptcert,true)==false)
		{
			WScript.Echo("��ӽ��ܼ���֤��ʧ�ܣ�");
			return null;
		}
		
		utilobj=new ActiveXObject("NetcaPki.Utilities");
		plaintextarray=utilobj.Encode(plaintext,NETCAPKI_CP_UTF8);
		cipher=envelopeddataobj.Encrypt(plaintextarray,NETCAPKI_CMS_ENCODE_BASE64);
		WScript.Echo("���ܳɹ���");
		
		encryptcert=null;
		utilobj=null;
		envelopeddataobj=null;
		return cipher;
	}
	catch(e)
	{
		encryptcert=null;
		utilobj=null;
		envelopeddataobj=null
		WScript.Echo(e.message+"  ������ : "+e.number);
		return null;
	}
}


try
{
	var envelopeddataobj;
	var utilobj=new ActiveXObject("NetcaPki.Utilities");
	envelopeddataobj=new ActiveXObject("NetcaPki.EnvelopedData");

	var cipher=EnvEncrypt();
	var cleararray=envelopeddataobj.Decrypt(cipher);
	var clear=utilobj.Decode(cleararray,NETCAPKI_CP_UTF8);
	WScript.Echo("���ܳɹ���");
}
catch(e)
{
	WScript.Echo(e.message+"  ������ : "+e.number);
}