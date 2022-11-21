#ifndef _FUNCTION_INLCUDE_H_
#define _FUNCTION_INLCUDE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SDR_OK					0x0							/*�����ɹ�*/
#define SDR_BASE				0x01000000					/*���������ֵ*/
#define SDR_UNKNOWERR			(SDR_BASE + 0x00000001)		/*δ֪����*/
#define SDR_NOTSUPPORT			(SDR_BASE + 0x00000002)		/*��֧�ֵĽӿڵ���*/
#define SDR_COMMFAIL			(SDR_BASE + 0x00000003)		/*���豸ͨ��ʧ��*/
#define SDR_HARDFAIL			(SDR_BASE + 0x00000004)		/*����ģ������Ӧ*/
#define SDR_OPENDEVICE			(SDR_BASE + 0x00000005)		/*���豸ʧ��*/
#define SDR_OPENSESSION			(SDR_BASE + 0x00000006)		/*�����Ựʧ��*/
#define SDR_PARDENY				(SDR_BASE + 0x00000007)		/*��˽Կʹ��Ȩ��*/
#define SDR_KEYNOTEXIST			(SDR_BASE + 0x00000008)		/*�����ڵ���Կ����*/
#define SDR_ALGNOTSUPPORT		(SDR_BASE + 0x00000009)		/*��֧�ֵ��㷨����*/
#define SDR_ALGMODNOTSUPPORT	(SDR_BASE + 0x0000000A)		/*��֧�ֵ��㷨ģʽ����*/
#define SDR_PKOPERR				(SDR_BASE + 0x0000000B)		/*��Կ����ʧ��*/
#define SDR_SKOPERR				(SDR_BASE + 0x0000000C)		/*˽Կ����ʧ��*/
#define SDR_SIGNERR				(SDR_BASE + 0x0000000D)		/*ǩ������ʧ��*/
#define SDR_VERIFYERR			(SDR_BASE + 0x0000000E)		/*��֤ǩ��ʧ��*/
#define SDR_SYMOPERR			(SDR_BASE + 0x0000000F)		/*�Գ��㷨����ʧ��*/
#define SDR_STEPERR				(SDR_BASE + 0x00000010)		/*�ಽ���㲽�����*/
#define SDR_FILESIZEERR			(SDR_BASE + 0x00000011)		/*�ļ����ȳ�������*/
#define SDR_FILENOEXIST			(SDR_BASE + 0x00000012)		/*ָ�����ļ�������*/
#define SDR_FILEOFSERR			(SDR_BASE + 0x00000013)		/*�ļ���ʼλ�ô���*/
#define SDR_KEYTYPEERR			(SDR_BASE + 0x00000014)		/*��Կ���ʹ���*/
#define SDR_KEYERR				(SDR_BASE + 0x00000015)		/*��Կ����*/
#define SDR_ENCDATAERR			(SDR_BASE + 0x00000016)		/*ECC�������ݴ���*/


#ifdef PUHUA
/*����Ϊ���������㷵�صĴ���*/
#define PHCDS_SDR_BSAE	                        0x00090000
#define PHCDS_SESSIONHANDLE_CLOSED            	(PHCDS_SDR_BSAE+0x00000100)  /*���壺����ִ�й����У��ûỰ�Ѿ��رա�*/
#define PHCDS_SESSIONHANDLE_COUNT             	(PHCDS_SDR_BSAE+0x00000101)  /*���壺�򿪵ĻỰ̫�ࡣ*/
#define PHCDS_SESSIONHANDLE_INVALID           	(PHCDS_SDR_BSAE+0x00000102)  /*���壺ָ���ĻỰ�����Ч��*/
#define PHCDS_LOGIN_FAILED  		      		(PHCDS_SDR_BSAE+0x00000103)  /*���壺��ȡ˽Կʹ��Ȩ��ʧ�ܡ�*/
#define PHCDS_LOGIN_REPEAT      	      		(PHCDS_SDR_BSAE+0x00000104)  /*���壺��ȡ˽Կʹ��Ȩ���ظ���*/
#define PHCDS_NOT_LOGIN       	    	      	(PHCDS_SDR_BSAE+0x00000105)  /*���壺˽Կʹ��Ȩ��δ��ȡ��*/
#define PHCDS_INPUT_LEN_ERROR                 	(PHCDS_SDR_BSAE+0x00000106)  /*���壺�����������ָʾ����*/
#define PHCDS_KEYID_INVALID           	      	(PHCDS_SDR_BSAE+0x00000107)  /*���壺ָ������Կ�ŷǷ���*/
#define PHCDS_ALGID_INVALID                   	(PHCDS_SDR_BSAE+0x00000108)  /*���壺�㷨��ʶ��Ч��*/
#define PHCDS_NOT_INITIALIZED         	      	(PHCDS_SDR_BSAE+0x00000109)  /*���壺δ���ó�ʼ����*/
#define PHCDS_ALREADY_INITIALIZED      	   		(PHCDS_SDR_BSAE+0x00000110)  /*���壺��ʼ���ѵ��á�*/
#define PHCDS_DEVICEHANDLE_INVALID           	(PHCDS_SDR_BSAE+0x00000111)  /*�豸�����Ч*/
#define PHCDS_OPENDEVICE_ERROR          		(PHCDS_SDR_BSAE+0x00000112)	/*���豸����*/
#define PHCDS_CLOSEDEVICE_ERROR           		(PHCDS_SDR_BSAE+0x00000113)	/*�ر��豸����*/
#define PHCDS_OPENSESSION_ERROR           		(PHCDS_SDR_BSAE+0x00000114)	/*�򿪻Ự����*/
#define PHCDS_CLOSESESSION_ERROR           		(PHCDS_SDR_BSAE+0x00000115)	/*�رջỰ����*/
#define PHCDS_GenerateRandom_ERROR           	(PHCDS_SDR_BSAE+0x00000116)	/*�������������*/
#define PHCDS_GenerateKeyPair_RSA_ERROR       	(PHCDS_SDR_BSAE+0x00000117)  /*����RSA��Կ�Դ���*/
#define PHCDS_ExternalPublicKeyOperation_ERROR  (PHCDS_SDR_BSAE+0x00000118) /*�ⲿ��Կ���ܴ���*/
#define PHCDS_ExternalPrivateKeyOperation_ERROR (PHCDS_SDR_BSAE+0x00000119) /*�ⲿ˽Կ���ܴ���*/
#define PHCDS_ImportKey_ERROR 					(PHCDS_SDR_BSAE+0x00000120) /*�ⲿ����Գ���Կ����*/
#define PHCDS_Encrypt_ERROR						(PHCDS_SDR_BSAE+0x00000121)  /*�ԳƼ��ܴ���*/
#define PHCDS_Decrypt_ERROR						(PHCDS_SDR_BSAE+0x00000122) /*�Գƽ��ܴ���*/
#define PHCDS_CalculateMAC_ERROR				(PHCDS_SDR_BSAE+0x00000123) /*MAC�������*/
#define PHCDS_DestoryKey_ERROR					(PHCDS_SDR_BSAE+0x00000124) /*�������뿨�ϵĻỰ��Կ����*/
#define PHCDS_HashInit_ERROR					(PHCDS_SDR_BSAE+0x00000125) /*HASH��ʼ������*/
#define PHCDS_HashUpdate_ERROR					(PHCDS_SDR_BSAE+0x00000126) /*HASH�������*/
#define PHCDS_HashFinal_ERROR					(PHCDS_SDR_BSAE+0x00000127) /*HASH�����������*/
#define PHCDS_PARAMETER_INVALID     			(PHCDS_SDR_BSAE+0x00000128)    /*���壺���������Ч��*/
#define PHCDS_SESSIONLIST_INVALID     			(PHCDS_SDR_BSAE+0x00000129) /*���壺SESSION����Ϊ�ա�*/
#define PHCDS_SESSIONID_INVALID     			(PHCDS_SDR_BSAE+0x00000130)  /*���壺SESSION������û��SESSIONIDָʾ�ĻỰ��*/
#define PHCDS_SESSIONSTAT_INVALID    			(PHCDS_SDR_BSAE+0x00000131) /*���壺SESSIONSTAT״̬�쳣����0��1����*/
#define PHCDS_KEYCONTAINER_INVALID   			(PHCDS_SDR_BSAE+0x00000132) /*���壺��Կ��������Ϊ�ա�*/
#define PHCDS_KEYRECORD_INVALID     			(PHCDS_SDR_BSAE+0x00000133) /*���壺��Կ����������û��ָ������Կ��*/
#define PHCDS_KEYRECORDVALUETYPE_INVALID     	(PHCDS_SDR_BSAE+0x00000134) /*���壺��Կ���ݵ�����ֵ��Ч��*/
#define PHCDS_USERKEYLIST_INVALID     			(PHCDS_SDR_BSAE+0x00000135)  /*���壺��Կ������Կ����Ϊ�ա�*/
#define PHCDS_USERKEY_INVALID     				(PHCDS_SDR_BSAE+0x00000136) /*���壺��Կ������Կ������û��ָ������Կ��*/
#define PHCDS_USERKEYVALUETYPE_INVALID     		(PHCDS_SDR_BSAE+0x00000137) /*���壺��Կ���ݵ�����ֵ��Ч��*/
#define PHCDS_FILETYPE_INVALID      			(PHCDS_SDR_BSAE+0x00000138)  /*��Ч�ļ�����*/
#define PHCDS_PARAMNAME_INVALID      			(PHCDS_SDR_BSAE+0x00000139) /*��Ч��������*/
#define PHCDS_PARAMNAMELEN_INVALID      		(PHCDS_SDR_BSAE+0x00000140) /*��Ч�������Ƴ���*/
#define PHCDS_OPENFILE_ERROR      				(PHCDS_SDR_BSAE+0x00000141) /*���ļ�ʧ��*/
#define PHCDS_CREATFILE_ERROR      				(PHCDS_SDR_BSAE+0x00000142) /*�����ļ�ʧ��*/
#define PHCDS_WRITEFILE_ERROR	  				(PHCDS_SDR_BSAE+0x00000143)/*д�ļ�ʧ��*/
#define PHCDS_CLOSEFILE_ERROR	   				(PHCDS_SDR_BSAE+0x00000144) /*�ر��ļ�ʧ��*/
#define PHCDS_FSEEK_ERROR          				(PHCDS_SDR_BSAE+0x00000145) /*�ı��ļ�ָ��ʧ��*/
#define PHCDS_PAD_ERROR		   					(PHCDS_SDR_BSAE+0x00000146) /*�ԳƼӽ��ܲ�λ����*/
#define PHCDS_USEPIN_ERROR						(PHCDS_SDR_BSAE+0x00000147)  /*�û�PIN����*/
#define PHCDS_KEYTYPE_INVALID   				(PHCDS_SDR_BSAE+0x00000148)  /*���壺��Կ������Ч��*/
#define PHCDS_PRIVATEKEY_DECRYPT_ERROR    		(PHCDS_SDR_BSAE+0x00000149)  /*���壺˽Կ����ʧ�ܡ�*/
#define PHCDS_ERROR_DLL_LOAD_ERROR   			(PHCDS_SDR_BSAE+0x00000150)    /*���ؼ��ܿ���ʧ��*/
#define PHCDS_MEMALLOC_ERROR  	    			(PHCDS_SDR_BSAE+0x00000151)     /*�ڴ�������*/
#define PHCDS_DELETE_DIR_ERROR	   				(PHCDS_SDR_BSAE+0x00000152) /*ɾ���ļ�ʧ��*/
#define PHCDS_EXPORT_KEY_LENGTH_ERROR	   		(PHCDS_SDR_BSAE+0x00000153) /*������Կ�ĳ�������*/
#define PHCDS_NO_KEY							(PHCDS_SDR_BSAE+0x00000154) /*�޴���Կ*/
#define PHCDS_CARD_FLAG_ERROR				   	(PHCDS_SDR_BSAE+0x00000155) /*���ܿ���ʶ��������*/
#define PHCDS_NO_CARD_SESSION_ERROR				(PHCDS_SDR_BSAE+0x00000156) /*û�м��ܿ��Ự*/
#define PHCDS_SOCKET_SERVER_RECV_ERROR			(PHCDS_SDR_BSAE+0x00000157) /*������������ݴ���*/
#define PHCDS_SOCKET_SERVER_PACKET_ERROR		(PHCDS_SDR_BSAE+0x00000158) /*������������ݴ���*/
#define PHCDS_SESSIONKEY_INVALID				(PHCDS_SDR_BSAE+0x00000159) /*�Ự��Կ����*/
#define PHCDS_CONFIGFILE_INVALID				(PHCDS_SDR_BSAE+0x00000160) /*�����ļ�����*/
#define PHCDS_INDATA_MAXDATA					(PHCDS_SDR_BSAE+0x00000161) /*�����������ֵ*/
#define PHCDS_SESSIONKEYHANDLE_MAX              (PHCDS_SDR_BSAE+0x00000162) /*�Ự��Կ����������ֵ*/
#define PHCDS_NOSUPPORT_ALGID					(PHCDS_SDR_BSAE+0x00000163) /*��֧�ֵ��㷨*/
#define PHCDS_HASH_MAXCOUNT						(PHCDS_SDR_BSAE+0x00000164) /*����hash��*/
#define PHCDS_AGREEMENTHANDLE_MAX               (PHCDS_SDR_BSAE+0x00000165) /*Э�̲�������������ֵ*/
#define PHCDS_KEY_ERROR							(PHCDS_SDR_BSAE+0x00000166) /*��Կ��ʽ����*/
#define PHCDS_KEYLENGTH_ERROR					(PHCDS_SDR_BSAE+0x00000167) /*��Կ���ȴ���*/

/*����Ϊ������ͻ��˵Ĵ�����Ϣ*/
#define SDF_SDR_BASE				0x04000000					/*���������ֵ*/
#define SDF_SDR_UNKNOWERR			(SDF_SDR_BSAE + 0x00000001)	/*δ֪����*/
#define SDF_SDR_NOTSUPPORT			(SDF_SDR_BSAE + 0x00000002)	/*��֧�ֵĽӿڵ���*/
#define SDF_SDR_COMMFAIL			(SDF_SDR_BSAE + 0x00000003)	/*���豸ͨ��ʧ��*/
#define SDF_SDR_HARDFAIL			(SDF_SDR_BSAE + 0x00000004)	/*����ģ������Ӧ*/
#define SDF_SDR_OPENDEVICE			(SDF_SDR_BSAE + 0x00000005)	/*���豸ʧ��*/
#define SDF_SDR_OPENSESSION			(SDF_SDR_BSAE + 0x00000006)	/*�����Ựʧ��*/
#define SDF_SDR_PARDENY				(SDF_SDR_BSAE + 0x00000007)	/*��˽Կʹ��Ȩ��*/
#define SDF_SDR_KEYNOTEXIST			(SDF_SDR_BSAE + 0x00000008)	/*�����ڵ���Կ����*/
#define SDF_SDR_ALGNOTSUPPORT		(SDF_SDR_BSAE + 0x00000009)	/*��֧�ֵ��㷨����*/
#define SDF_SDR_ALGMODNOTSUPPORT	(SDF_SDR_BSAE + 0x0000000A)	/*��֧�ֵ��㷨ģʽ����*/
#define SDF_SDR_PKOPERR				(SDF_SDR_BSAE + 0x0000000B)	/*��Կ����ʧ��*/
#define SDF_SDR_SKOPERR				(SDF_SDR_BSAE + 0x0000000C)	/*˽Կ����ʧ��*/
#define SDF_SDR_SIGNERR				(SDF_SDR_BSAE + 0x0000000D)	/*ǩ������ʧ��*/
#define SDF_SDR_VERIFYERR			(SDF_SDR_BSAE + 0x0000000E)	/*��֤ǩ��ʧ��*/
#define SDF_SDR_SYMOPERR			(SDF_SDR_BSAE + 0x0000000F)	/*�Գ��㷨����ʧ��*/
#define SDF_SDR_STEPERR				(SDF_SDR_BSAE + 0x00000010)	/*�ಽ���㲽�����*/
#define SDF_SDR_FILESIZEERR			(SDF_SDR_BSAE + 0x00000011)	/*�ļ����ȳ�������*/
#define SDF_SDR_FILENOEXIST			(SDF_SDR_BSAE + 0x00000012)	/*ָ�����ļ�������*/
#define SDF_SDR_FILEOFSERR			(SDF_SDR_BSAE + 0x00000013)	/*�ļ���ʼλ�ô���*/
#define SDF_SDR_KEYTYPEERR			(SDF_SDR_BSAE + 0x00000014)	/*��Կ���ʹ���*/
#define SDF_SDR_KEYERR				(SDF_SDR_BSAE + 0x00000015)	/*��Կ����*/
/* �Ǳ�׼���� */
#define SDF_SDR_PARAMETER_INVALID   (SDF_SDR_BSAE + 0x00000016)	/*��������*/

#define SDF_SDR_GETCONFIG     		(SDF_SDR_BSAE + 0x00000100)	/*��ȡ�����ļ�����*/
#define SDF_SDR_FUNCNUM       		(SDF_SDR_BSAE + 0x00000200) /*�������ʹ���*/
#define SDF_SDR_LBLTYPE       		(SDF_SDR_BSAE + 0x00000201)	/*��ǩ���ʹ���*/
#define SDF_SDR_MEMALLOC      		(SDF_SDR_BSAE + 0x00000202)	/*�ڴ�������*/
#define SDF_SDR_INPUTEMPTY    		(SDF_SDR_BSAE + 0x00000203) /*���Ϊ��*/
                    		
#define SDF_SDR_NOGOODIP      		(SDF_SDR_BSAE + 0x00000300)	/*û�п��õ������*/
#define SDF_SDR_NULLHOSTNAME  		(SDF_SDR_BSAE + 0x00000301)	/*�����ļ�Ϊ��*/
#define SDF_SDR_GETHOSTNAME   		(SDF_SDR_BSAE + 0x00000302)	/*��ȡ������ʧ��*/
#define SDF_SDR_SOCKETCREAT   		(SDF_SDR_BSAE + 0x00000303)	/*����socket����ʧ��*/
#define SDF_SDR_SOCKETCONN    		(SDF_SDR_BSAE + 0x00000304)	/*socket����ʧ��*/
#define SDF_SDR_SOCKETSEND    		(SDF_SDR_BSAE + 0x00000305)	/*socket��������ʧ��*/
#define SDF_SDR_SOCKETRECV    		(SDF_SDR_BSAE + 0x00000306)	/*socket��������ʧ��*/
#define SDF_SDR_SOCKETBIND    		(SDF_SDR_BSAE + 0x00000307)	/*socket�˿ڰ�ʧ��*/
                   		
#define SDF_SDR_ARGVENCODE    		(SDF_SDR_BSAE + 0x00000400)	/*���ݱ���ʧ��*/
#define SDF_SDR_ARGVDECODE    		(SDF_SDR_BSAE + 0x00000401)	/*���ݽ���ʧ��*/
#define SDF_SDR_HEADENCODE    		(SDF_SDR_BSAE + 0x00000402)	/*����ͷ����ʧ��*/
#define SDF_SDR_HEADDECODE    		(SDF_SDR_BSAE + 0x00000403)	/*����ͷ����ʧ��*/
#define SDF_SDR_RETVENCODE    		(SDF_SDR_BSAE + 0x00000404)	/*�������ݱ���ʧ��*/
#define SDF_SDR_RETVDECODE    		(SDF_SDR_BSAE + 0x00000405)	/*�������ݽ���ʧ��*/
                      		
#define SDF_SDR_OPENFILE      		(SDF_SDR_BSAE + 0x00000500)	/*���ļ�ʧ��*/
#define SDF_SDR_GETFILESTAT   		(SDF_SDR_BSAE + 0x00000501)	/*��ȡ�ļ�״̬ʧ��*/
#define SDF_SDR_NULLFILE      		(SDF_SDR_BSAE + 0x00000502)	/*���ļ�����*/
#define SDF_SDR_READFILE      		(SDF_SDR_BSAE + 0x00000503)	/*���ļ�ʧ��*/
#define SDF_SDR_WRITEFILE     		(SDF_SDR_BSAE + 0x00000504)	/*д�ļ�ʧ��*/
#define SDF_SDR_DELETEFILE    		(SDF_SDR_BSAE + 0x00000505)	/*ɾ���ļ�ʧ��*/
#define SDF_SDR_OPENDIR       		(SDF_SDR_BSAE + 0x00000506)	/*��Ŀ¼ʧ��*/

#define SDF_SDR_NOPERMISSION  		(SDF_SDR_BSAE + 0x00000600)	/*�޴�Ȩ��*/

#endif




#define SGD_SM1_ECB			0x00000101		/*SM1�㷨ECB����ģʽ*/
#define SGD_SM1_CBC			0x00000102		/*SM1�㷨CBC����ģʽ*/
#define SGD_SM1_CFB			0x00000104		/*SM1�㷨CFB����ģʽ*/
#define SGD_SM1_OFB			0x00000108		/*SM1�㷨OFB����ģʽ*/
#define SGD_SM1_MAC			0x00000110		/*SM1�㷨MAC����*/
#define SGD_SSF33_ECB		0x00000201		/*SSF33�㷨ECB����ģʽ*/
#define SGD_SSF33_CBC		0x00000202		/*SSF33�㷨CBC����ģʽ*/
#define SGD_SSF33_CFB		0x00000204		/*SSF33�㷨CFB����ģʽ*/
#define SGD_SSF33_OFB		0x00000208		/*SSF33�㷨OFB����ģʽ*/
#define SGD_SSF33_MAC		0x00000210		/*SSF33�㷨MAC����*/
#define SGD_SMS4_ECB		0x00000401		/*SMS4�㷨ECB����ģʽ*/
#define SGD_SMS4_CBC		0x00000402		/*SMS4�㷨CBC����ģʽ*/
#define SGD_SMS4_CFB		0x00000404		/*SMS4�㷨CFB����ģʽ*/
#define SGD_SMS4_OFB		0x00000408		/*SMS4�㷨OFB����ģʽ*/
#define SGD_SMS4_MAC		0x00000410		/*SMS4�㷨MAC����*/

#define SGD_RSA				0x00010000		/*RSA�㷨*/
#define SGD_SM2_1			0x00020100		/*��Բ����ǩ���㷨*/
#define SGD_SM2_2			0x00020200		/*��Բ������Կ����Э��*/
#define SGD_SM2_3			0x00020400		/*��Բ���߼����㷨*/

#define SGD_SM3				0x00000001		/*SM3�Ӵ��㷨*/
#define SGD_SHA1			0x00000002		/*SHA_1�Ӵ��㷨*/
#define SGD_SHA256			0x00000004		/*SHA_256�Ӵ��㷨*/

#define SGD_SM3_RSA			0x00001001		/*����SM3�㷨��RSA�㷨��ǩ��*/
#define SGD_SHA1_RSA		0x00001002		/*����SHA_1�㷨��RSA�㷨��ǩ��*/
#define SGD_SHA256_RSA		0x00001004		/*����SHA_256�㷨��RSA�㷨��ǩ��*/
#define SGD_SM3_SM2			0x00020101		/*����SM2�㷨��SM3�㷨��ǩ��*/


#ifdef _WIN32
	#ifdef PUHUA
		#define DEVICEAPI __stdcall
	#else
		#define DEVICEAPI
	#endif
#else
#define DEVICEAPI
#endif

typedef struct DeviceInfo_st{
	unsigned char IssuerName[40];
	unsigned char DeviceName[16];
	unsigned char DeviceSerial[16];
	unsigned int  DeviceVersion;
	unsigned int  StandardVersion;
	unsigned int  AsymAlgAbility[2];
	unsigned int  SymAlgAbility;
	unsigned int  HashAlgAbility;
	unsigned int  BufferSize;
}DEVICEINFO;

#define RSAref_MAX_BITS    2048
#define RSAref_MAX_LEN     ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS   ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN    ((RSAref_MAX_PBITS + 7)/ 8)
typedef struct RSArefPublicKey_st
{
	unsigned int  bits;
	unsigned char m[RSAref_MAX_LEN];
	unsigned char e[RSAref_MAX_LEN];
} RSArefPublicKey;

typedef struct RSArefPrivateKey_st
{
	unsigned int  bits;
	unsigned char m[RSAref_MAX_LEN];
	unsigned char e[RSAref_MAX_LEN];
	unsigned char d[RSAref_MAX_LEN];
	unsigned char prime[2][RSAref_MAX_PLEN];
	unsigned char pexp[2][RSAref_MAX_PLEN];
	unsigned char coef[RSAref_MAX_PLEN];
} RSArefPrivateKey;

#define ECCref_MAX_BITS			512 
#define ECCref_MAX_LEN			((ECCref_MAX_BITS+7) / 8)
typedef struct ECCrefPublicKey_st
{
	unsigned int  bits;
	unsigned char x[ECCref_MAX_LEN]; 
	unsigned char y[ECCref_MAX_LEN]; 
} ECCrefPublicKey;

typedef struct ECCrefPrivateKey_st
{
    unsigned int  bits;
    unsigned char K[ECCref_MAX_LEN];
} ECCrefPrivateKey;

typedef struct ECCCipher_st
{
	unsigned char x[ECCref_MAX_LEN]; 
	unsigned char y[ECCref_MAX_LEN]; 
	unsigned char M[32];
	unsigned int  L;
	unsigned char C[1];
} ECCCipher;

typedef struct ECCSignature_st
{
	unsigned char r[ECCref_MAX_LEN];	
	unsigned char s[ECCref_MAX_LEN];	
} ECCSignature;

/* �������豸 */
typedef int (DEVICEAPI *SDF_OpenDevice_Ptr)(void **phDeviceHandle);
/* �ر������豸�����ͷ������Դ */
typedef int (DEVICEAPI *SDF_CloseDevice_Ptr)(void *hDeviceHandle);
/* �����������豸�ĻỰ */
typedef int (DEVICEAPI *SDF_OpenSession_Ptr)(void *hDeviceHandle, void **phSessionHandle);
/* �ر��������豸�ѽ����ĻỰ�����ͷ������Դ */
typedef int (DEVICEAPI *SDF_CloseSession_Ptr)(void *hSessionHandle);
/* ��ȡ�����豸�������� */
typedef int (DEVICEAPI *SDF_GetDeviceInfo_Ptr)(void *hSessionHandle,DEVICEINFO *pstDeviceInfo);
/* ��ȡָ�����ȵ������ */
typedef int (DEVICEAPI *SDF_GenerateRandom_Ptr)(void *hSessionHandle, unsigned int  uiLength,unsigned char *pucRandom);
/* ��ȡ�����豸�ڲ��洢��ָ������˽Կ��ʹ��Ȩ */
typedef int (DEVICEAPI *SDF_GetPrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex,unsigned char *pucPassword,unsigned int  uiPwdLength);
/* �ͷ������豸�洢��ָ������˽Կ��ʹ����Ȩ */
typedef int (DEVICEAPI *SDF_ReleasePrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex);
/* ���������豸�ڲ��洢��ָ������λ�õ�ǩ����Կ */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* ���������豸�ڲ��洢��ָ������λ�õļ��ܹ�Կ */
typedef int  (DEVICEAPI *SDF_ExportEncPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* ���������豸����ָ��ģ����RSA��Կ�� */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyBits,RSArefPublicKey *pucPublicKey,RSArefPrivateKey *pucPrivateKey);
/* ���ɻỰ��Կ����ָ���������ڲ����ܹ�Կ���������ͬʱ������Կ��� */
typedef int (DEVICEAPI *SDF_GenerateKeyWithIPK_RSA_Ptr)(void *hSessionHandle,unsigned int uiIPKIndex,unsigned int uiKeyBits,unsigned char *pucKey,unsigned int *puiKeyLength,void **phKeyHandle);
/* ���ɻỰ��Կ�����ⲿ��Կ���������ͬʱ������Կ��� */
typedef int (DEVICEAPI *SDF_GenerateKeyWithEPK_RSA_Ptr)(void *hSessionHandle, unsigned int uiKeyBits,RSArefPublicKey *pucPublicKey,unsigned char *pucKey,unsigned int *puiKeyLength,void **phKeyHandle);
/* ����Ự��Կ�����ڲ�˽Կ���ܣ�ͬʱ������Կ��� */
typedef int (DEVICEAPI *SDF_ImportKeyWithISK_RSA_Ptr)(void *hSessionHandle,unsigned int uiISKIndex,unsigned char *pucKey,unsigned int puiKeyLength,void **phKeyHandle);
/* �����ڲ����ܹ�Կ���ܵĻỰ��Կת��Ϊ���ⲿָ���Ĺ�Կ���ܣ������������ŷ�ת����*/
typedef int (DEVICEAPI *SDF_ExchangeDigitEnvelopeBaseOnRSA_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey,unsigned char *pucDEInput,unsigned int  uiDELength,unsigned char *pucDEOutput,unsigned int  *puiDELength);
/* ���������豸�ڲ��洢��ָ������λ�õ�ǩ����Կ */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* ���������豸�ڲ��洢��ָ������λ�õļ��ܹ�Կ */
typedef int (DEVICEAPI *SDF_ExportEncPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* ���������豸����ָ�����ͺ�ģ����ECC��Կ�� */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_ECC_Ptr)(void *hSessionHandle,unsigned int  uiAlgID,unsigned int  uiKeyBits,ECCrefPublicKey *pucPublicKey,ECCrefPrivateKey *pucPrivateKey);
/* ���ɻỰ��Կ����ָ���������ڲ�ECC���ܹ�Կ���������ͬʱ������Կ���*/
typedef int (DEVICEAPI *SDF_GenerateKeyWithIPK_ECC_Ptr)(void *hSessionHandle,unsigned int uiIPKIndex,unsigned int uiKeyBits,ECCCipher *pucKey,void **phKeyHandle);
/* ���ɻỰ��Կ�����ⲿECC��Կ���������ͬʱ������Կ��� */
typedef int (DEVICEAPI *SDF_GenerateKeyWithEPK_ECC_Ptr)(void *hSessionHandle,unsigned int uiKeyBits,unsigned int  uiAlgID,ECCrefPublicKey *pucPublicKey,ECCCipher *pucKey,void **phKeyHandle);
/* ����Ự��Կ�����ڲ�ECC����˽Կ���ܣ�ͬʱ������Կ��� */
typedef int (DEVICEAPI *SDF_ImportKeyWithISK_ECC_Ptr)(void *hSessionHandle,unsigned int uiISKIndex,ECCCipher *pucKey,void **phKeyHandle);
/* ʹ��ECC��ԿЭ���㷨��Ϊ����Ự��Կ������Э�̲�����ͬʱ����ָ������λ�õ�ECC��Կ����ʱECC��Կ�ԵĹ�Կ��Э�̾����*/
typedef int (DEVICEAPI *SDF_GenerateAgreementDataWithECC_Ptr)(void *hSessionHandle, unsigned int uiISKIndex,unsigned int uiKeyBits,unsigned char *pucSponsorID,unsigned int uiSponsorIDLength,ECCrefPublicKey  *pucSponsorPublicKey,ECCrefPublicKey  *pucSponsorTmpPublicKey,void **phAgreementHandle);
/* ʹ��ECC��ԿЭ���㷨��ʹ������Э�̾������Ӧ����Э�̲�������Ự��Կ��ͬʱ���ػỰ��Կ��� */
typedef int (DEVICEAPI *SDF_GenerateKeyWithECC_Ptr)(void *hSessionHandle,unsigned char *pucResponseID,unsigned int uiResponseIDLength,ECCrefPublicKey *pucResponsePublicKey,ECCrefPublicKey *pucResponseTmpPublicKey,void *hAgreementHandle,void **phKeyHandle);
/* ʹ��ECC��ԿЭ���㷨������Э�̲���������Ự��Կ��ͬʱ���ز�����Э�̲����ͺ���Կ�����*/
typedef int (DEVICEAPI *SDF_GenerateAgreementDataAndKeyWithECC_Ptr)(void *hSessionHandle,unsigned int uiISKIndex,unsigned int uiKeyBits,unsigned char *pucResponseID,unsigned int uiResponseIDLength,unsigned char *pucSponsorID,unsigned int uiSponsorIDLength,ECCrefPublicKey *pucSponsorPublicKey,ECCrefPublicKey *pucSponsorTmpPublicKey,ECCrefPublicKey  *pucResponsePublicKey,ECCrefPublicKey  *pucResponseTmpPublicKey,void **phKeyHandle);
/* �����ڲ����ܹ�Կ���ܵĻỰ��Կת��Ϊ���ⲿָ���Ĺ�Կ���ܣ������������ŷ�ת����*/
typedef int (DEVICEAPI *SDF_ExchangeDigitEnvelopeBaseOnECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,unsigned int  uiAlgID,ECCrefPublicKey *pucPublicKey,ECCCipher *pucEncDataIn,ECCCipher *pucEncDataOut);
/* ���ɻỰ��Կ������Կ������Կ���������ͬʱ������Կ�����*/
typedef int (DEVICEAPI *SDF_GenerateKeyWithKEK_Ptr)(void *hSessionHandle,unsigned int uiKeyBits,unsigned int  uiAlgID,unsigned int uiKEKIndex, unsigned char *pucKey, unsigned int *puiKeyLength, void **phKeyHandle);
/* ����Ự��Կ������Կ������Կ���ܣ�ͬʱ���ػỰ��Կ�����*/
typedef int (DEVICEAPI *SDF_ImportKeyWithKEK_Ptr)(void *hSessionHandle,unsigned int  uiAlgID,unsigned int uiKEKIndex,unsigned char *pucKey,unsigned int *puiKeyLength,void **phKeyHandle);
/* �������ĻỰ��Կ��ͬʱ������Կ���*/
typedef int (DEVICEAPI *SDF_ImportKey_Ptr)(void *hSessionHandle,unsigned char *pucKey, unsigned int uiKeyLength,void **phKeyHandle);
/* ���ٻỰ��Կ�����ͷ�Ϊ��Կ���������ڴ����Դ��*/
typedef int (DEVICEAPI *SDF_DestoryKey_Ptr)(void *hSessionHandle,void *hKeyHandle);
/* ָ��ʹ���ⲿ��Կ�����ݽ������� */
typedef int (DEVICEAPI *SDF_ExternalPublicKeyOperation_RSA_Ptr)(void *hSessionHandle,RSArefPublicKey *pucPublicKey,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* ָ��ʹ���ⲿ˽Կ�����ݽ�������*/
typedef int (DEVICEAPI *SDF_ExternalPrivateKeyOperation_RSA_Ptr)(void *hSessionHandle,RSArefPrivateKey *pucPrivateKey,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* ʹ���ڲ�ָ�������Ĺ�Կ�����ݽ������� */
typedef int (DEVICEAPI *SDF_InternalPublicKeyOperation_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* ʹ���ڲ�ָ��������˽Կ�����ݽ������� */
typedef int (DEVICEAPI *SDF_InternalPrivateKeyOperation_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* ʹ���ⲿECC˽Կ�����ݽ���ǩ������ */
typedef int (DEVICEAPI *SDF_ExternalSign_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPrivateKey *pucPrivateKey,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);
/* ʹ���ⲿECC��Կ��ECCǩ��ֵ������֤���� */
typedef int (DEVICEAPI *SDF_ExternalVerify_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucDataInput,unsigned int  uiInputLength,ECCSignature *pucSignature);
/* ʹ���ڲ�ECC˽Կ�����ݽ���ǩ������ */
typedef int (DEVICEAPI *SDF_InternalSign_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);
/* ʹ���ڲ�ECC��Կ��ECCǩ��ֵ������֤���� */
typedef int (DEVICEAPI *SDF_InternalVerify_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);
/* ʹ���ⲿECC��Կ�����ݽ��м������� */
typedef int (DEVICEAPI *SDF_ExternalEncrytp_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucData,unsigned int  uiDataLength,ECCCipher *pucEncData);
/* ʹ���ⲿECC˽Կ���н������� */
typedef int (DEVICEAPI *SDF_ExternalDecrypt_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPrivateKey *pucPrivateKey,ECCCipher *pucEncData,unsigned char *pucData,unsigned int  *puiDataLength);
/* ʹ��ָ������Կ�����IV�����ݽ��жԳƼ������� */
typedef int (DEVICEAPI *SDF_Encrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucData,unsigned int uiDataLength,unsigned char *pucEncData,unsigned int  *puiEncDataLength);
/* ʹ��ָ������Կ�����IV�����ݽ��жԳƽ������� */
typedef int (DEVICEAPI *SDF_Decrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucEncData,unsigned int  uiEncDataLength,unsigned char *pucData,unsigned int *puiDataLength);
/* ʹ��ָ������Կ�����IV�����ݽ���MAC���� */
typedef int (DEVICEAPI *SDF_CalculateMAC_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucData,unsigned int uiDataLength,unsigned char *pucMAC,unsigned int  *puiMACLength);
/* ����ʽ�����Ӵ������һ����*/
typedef int (DEVICEAPI *SDF_HashInit_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucID,unsigned int uiIDLength);
/* ����ʽ�����Ӵ�����ڶ���������������Ľ����Ӵ����� */
typedef int (DEVICEAPI *SDF_HashUpdate_Ptr)(void *hSessionHandle,unsigned char *pucData,unsigned int  uiDataLength);
/* ����ʽ�����Ӵ�������������Ӵ�������������Ӵ����ݲ�����м����� */
typedef int (DEVICEAPI *SDF_HashFinal_Ptr)(void *hSessionHandle,unsigned char *pucHash,unsigned int  *puiHashLength);
/* �������豸�ڲ��������ڴ洢�û����ݵ��ļ� */
typedef int (DEVICEAPI *SDF_CreateFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen,unsigned int uiFileSize);
/* ��ȡ�������豸�ڲ��洢�û����ݵ��ļ������� */
typedef int (DEVICEAPI *SDF_ReadFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen,unsigned int uiOffset,unsigned int *puiFileLength,unsigned char *pucBuffer);
/* �������豸�ڲ��洢�û����ݵ��ļ���д������ */
typedef int (DEVICEAPI *SDF_WriteFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen,unsigned int uiOffset,unsigned int uiFileLength,unsigned char *pucBuffer);
/* ɾ��ָ���ļ����������豸�ڲ��洢�û����ݵ��ļ� */
typedef int (DEVICEAPI *SDF_DeleteFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen);

#ifdef PUHUA
/*
hSessionHandle[IN] �Ự���
uiKeyIndex[IN]	�ڲ�˽Կ������
signKeyType[IN]	��Կ����	1Ϊǩ����Կ������Ϊ������Կ
pucDataInput[IN]	��������
uiInputLength[IN]	�������ݳ���
pucDataOutput[OUT]	������
puiOutputLength[OUT] ����������
*/
typedef int (DEVICEAPI *SDF_InternalPrivateKeyOperation_RSA_EX_Ptr)( void *hSessionHandle,  unsigned int  uiKeyIndex,unsigned int  signKeyType,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);

/*
����˵����
hSessionHandle[IN] �Ự���
uiISKIndex[IN]	�ڲ�˽Կ������
signKeyType[IN]	��Կ����	1Ϊǩ����Կ������Ϊ������Կ
ECCCipher[IN]	������������
pucData[OUT]	������
puiDataLength[OUT] ����������
*/
typedef int (DEVICEAPI *SDF_InternalDecrypt_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned int signKeyType,ECCCipher *pucEncData,unsigned char *pucData,unsigned int  *puiDataLength);

#endif






extern SDF_OpenDevice_Ptr SDF_OpenDevice;
extern SDF_CloseDevice_Ptr SDF_CloseDevice;
extern SDF_OpenSession_Ptr SDF_OpenSession;
extern SDF_CloseSession_Ptr SDF_CloseSession;
extern SDF_GetDeviceInfo_Ptr SDF_GetDeviceInfo;
extern SDF_GenerateRandom_Ptr SDF_GenerateRandom;
extern SDF_GetPrivateKeyAccessRight_Ptr SDF_GetPrivateKeyAccessRight;
extern SDF_ReleasePrivateKeyAccessRight_Ptr SDF_ReleasePrivateKeyAccessRight;
extern SDF_ExportSignPublicKey_RSA_Ptr SDF_ExportSignPublicKey_RSA;
extern SDF_ExportEncPublicKey_RSA_Ptr SDF_ExportEncPublicKey_RSA;
extern SDF_GenerateKeyPair_RSA_Ptr SDF_GenerateKeyPair_RSA;
extern SDF_GenerateKeyWithIPK_RSA_Ptr SDF_GenerateKeyWithIPK_RSA;
extern SDF_GenerateKeyWithEPK_RSA_Ptr SDF_GenerateKeyWithEPK_RSA;
extern SDF_ImportKeyWithISK_RSA_Ptr SDF_ImportKeyWithISK_RSA;
extern SDF_ExchangeDigitEnvelopeBaseOnRSA_Ptr SDF_ExchangeDigitEnvelopeBaseOnRSA;
extern SDF_ExportSignPublicKey_ECC_Ptr SDF_ExportSignPublicKey_ECC;
extern SDF_ExportEncPublicKey_ECC_Ptr SDF_ExportEncPublicKey_ECC;
extern SDF_GenerateKeyPair_ECC_Ptr SDF_GenerateKeyPair_ECC;
extern SDF_GenerateKeyWithIPK_ECC_Ptr SDF_GenerateKeyWithIPK_ECC;
extern SDF_GenerateKeyWithEPK_ECC_Ptr SDF_GenerateKeyWithEPK_ECC;
extern SDF_ImportKeyWithISK_ECC_Ptr SDF_ImportKeyWithISK_ECC;
extern SDF_GenerateAgreementDataWithECC_Ptr SDF_GenerateAgreementDataWithECC;
extern SDF_GenerateKeyWithECC_Ptr SDF_GenerateKeyWithECC;
extern SDF_GenerateAgreementDataAndKeyWithECC_Ptr SDF_GenerateAgreementDataAndKeyWithECC;
extern SDF_ExchangeDigitEnvelopeBaseOnECC_Ptr SDF_ExchangeDigitEnvelopeBaseOnECC;
extern SDF_GenerateKeyWithKEK_Ptr SDF_GenerateKeyWithKEK;
extern SDF_ImportKeyWithKEK_Ptr SDF_ImportKeyWithKEK;
extern SDF_ImportKey_Ptr SDF_ImportKey;
extern SDF_DestoryKey_Ptr SDF_DestoryKey;
extern SDF_ExternalPublicKeyOperation_RSA_Ptr SDF_ExternalPublicKeyOperation_RSA;
extern SDF_ExternalPrivateKeyOperation_RSA_Ptr SDF_ExternalPrivateKeyOperation_RSA;
extern SDF_InternalPublicKeyOperation_RSA_Ptr SDF_InternalPublicKeyOperation_RSA;
extern SDF_InternalPrivateKeyOperation_RSA_Ptr SDF_InternalPrivateKeyOperation_RSA;
extern SDF_ExternalSign_ECC_Ptr SDF_ExternalSign_ECC;
extern SDF_ExternalVerify_ECC_Ptr SDF_ExternalVerify_ECC;
extern SDF_InternalSign_ECC_Ptr SDF_InternalSign_ECC;
extern SDF_InternalVerify_ECC_Ptr SDF_InternalVerify_ECC;
extern SDF_ExternalEncrytp_ECC_Ptr SDF_ExternalEncrytp_ECC;
extern SDF_ExternalDecrypt_ECC_Ptr SDF_ExternalDecrypt_ECC;
extern SDF_Encrypt_Ptr SDF_Encrypt;
extern SDF_Decrypt_Ptr SDF_Decrypt;
extern SDF_CalculateMAC_Ptr SDF_CalculateMAC;
extern SDF_HashInit_Ptr SDF_HashInit;
extern SDF_HashUpdate_Ptr SDF_HashUpdate;
extern SDF_HashFinal_Ptr SDF_HashFinal;
extern SDF_CreateFile_Ptr SDF_CreateFile;
extern SDF_ReadFile_Ptr SDF_ReadFile;
extern SDF_WriteFile_Ptr SDF_WriteFile;
extern SDF_DeleteFile_Ptr SDF_DeleteFile;


#ifdef PUHUA
extern SDF_InternalPrivateKeyOperation_RSA_EX_Ptr SDF_InternalPrivateKeyOperation_RSA_EX;
extern SDF_InternalDecrypt_ECC_Ptr SDF_InternalDecrypt_ECC;
#endif

#ifdef __cplusplus
}
#endif

#endif
