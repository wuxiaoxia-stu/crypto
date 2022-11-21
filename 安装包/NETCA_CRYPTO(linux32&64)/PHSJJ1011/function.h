#ifndef _FUNCTION_INLCUDE_H_
#define _FUNCTION_INLCUDE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SDR_OK					0x0							/*操作成功*/
#define SDR_BASE				0x01000000					/*错误码基础值*/
#define SDR_UNKNOWERR			(SDR_BASE + 0x00000001)		/*未知错误*/
#define SDR_NOTSUPPORT			(SDR_BASE + 0x00000002)		/*不支持的接口调用*/
#define SDR_COMMFAIL			(SDR_BASE + 0x00000003)		/*与设备通信失败*/
#define SDR_HARDFAIL			(SDR_BASE + 0x00000004)		/*运算模块无响应*/
#define SDR_OPENDEVICE			(SDR_BASE + 0x00000005)		/*打开设备失败*/
#define SDR_OPENSESSION			(SDR_BASE + 0x00000006)		/*创建会话失败*/
#define SDR_PARDENY				(SDR_BASE + 0x00000007)		/*无私钥使用权限*/
#define SDR_KEYNOTEXIST			(SDR_BASE + 0x00000008)		/*不存在的密钥调用*/
#define SDR_ALGNOTSUPPORT		(SDR_BASE + 0x00000009)		/*不支持的算法调用*/
#define SDR_ALGMODNOTSUPPORT	(SDR_BASE + 0x0000000A)		/*不支持的算法模式调用*/
#define SDR_PKOPERR				(SDR_BASE + 0x0000000B)		/*公钥运算失败*/
#define SDR_SKOPERR				(SDR_BASE + 0x0000000C)		/*私钥运算失败*/
#define SDR_SIGNERR				(SDR_BASE + 0x0000000D)		/*签名运算失败*/
#define SDR_VERIFYERR			(SDR_BASE + 0x0000000E)		/*验证签名失败*/
#define SDR_SYMOPERR			(SDR_BASE + 0x0000000F)		/*对称算法运算失败*/
#define SDR_STEPERR				(SDR_BASE + 0x00000010)		/*多步运算步骤错误*/
#define SDR_FILESIZEERR			(SDR_BASE + 0x00000011)		/*文件长度超出限制*/
#define SDR_FILENOEXIST			(SDR_BASE + 0x00000012)		/*指定的文件不存在*/
#define SDR_FILEOFSERR			(SDR_BASE + 0x00000013)		/*文件起始位置错误*/
#define SDR_KEYTYPEERR			(SDR_BASE + 0x00000014)		/*密钥类型错误*/
#define SDR_KEYERR				(SDR_BASE + 0x00000015)		/*密钥错误*/
#define SDR_ENCDATAERR			(SDR_BASE + 0x00000016)		/*ECC加密数据错误*/


#ifdef PUHUA
/*以下为密码机服务层返回的错误*/
#define PHCDS_SDR_BSAE	                        0x00090000
#define PHCDS_SESSIONHANDLE_CLOSED            	(PHCDS_SDR_BSAE+0x00000100)  /*含义：函数执行过程中，该会话已经关闭。*/
#define PHCDS_SESSIONHANDLE_COUNT             	(PHCDS_SDR_BSAE+0x00000101)  /*含义：打开的会话太多。*/
#define PHCDS_SESSIONHANDLE_INVALID           	(PHCDS_SDR_BSAE+0x00000102)  /*含义：指定的会话句柄无效。*/
#define PHCDS_LOGIN_FAILED  		      		(PHCDS_SDR_BSAE+0x00000103)  /*含义：获取私钥使用权限失败。*/
#define PHCDS_LOGIN_REPEAT      	      		(PHCDS_SDR_BSAE+0x00000104)  /*含义：获取私钥使用权限重复。*/
#define PHCDS_NOT_LOGIN       	    	      	(PHCDS_SDR_BSAE+0x00000105)  /*含义：私钥使用权限未获取。*/
#define PHCDS_INPUT_LEN_ERROR                 	(PHCDS_SDR_BSAE+0x00000106)  /*含义：输入参数长度指示错误。*/
#define PHCDS_KEYID_INVALID           	      	(PHCDS_SDR_BSAE+0x00000107)  /*含义：指定的密钥号非法。*/
#define PHCDS_ALGID_INVALID                   	(PHCDS_SDR_BSAE+0x00000108)  /*含义：算法标识无效。*/
#define PHCDS_NOT_INITIALIZED         	      	(PHCDS_SDR_BSAE+0x00000109)  /*含义：未调用初始化。*/
#define PHCDS_ALREADY_INITIALIZED      	   		(PHCDS_SDR_BSAE+0x00000110)  /*含义：初始化已调用。*/
#define PHCDS_DEVICEHANDLE_INVALID           	(PHCDS_SDR_BSAE+0x00000111)  /*设备句柄无效*/
#define PHCDS_OPENDEVICE_ERROR          		(PHCDS_SDR_BSAE+0x00000112)	/*打开设备错误*/
#define PHCDS_CLOSEDEVICE_ERROR           		(PHCDS_SDR_BSAE+0x00000113)	/*关闭设备错误*/
#define PHCDS_OPENSESSION_ERROR           		(PHCDS_SDR_BSAE+0x00000114)	/*打开会话错误*/
#define PHCDS_CLOSESESSION_ERROR           		(PHCDS_SDR_BSAE+0x00000115)	/*关闭会话错误*/
#define PHCDS_GenerateRandom_ERROR           	(PHCDS_SDR_BSAE+0x00000116)	/*产生随机数错误*/
#define PHCDS_GenerateKeyPair_RSA_ERROR       	(PHCDS_SDR_BSAE+0x00000117)  /*产生RSA密钥对错误*/
#define PHCDS_ExternalPublicKeyOperation_ERROR  (PHCDS_SDR_BSAE+0x00000118) /*外部公钥加密错误*/
#define PHCDS_ExternalPrivateKeyOperation_ERROR (PHCDS_SDR_BSAE+0x00000119) /*外部私钥解密错误*/
#define PHCDS_ImportKey_ERROR 					(PHCDS_SDR_BSAE+0x00000120) /*外部导入对称密钥错误*/
#define PHCDS_Encrypt_ERROR						(PHCDS_SDR_BSAE+0x00000121)  /*对称加密错误*/
#define PHCDS_Decrypt_ERROR						(PHCDS_SDR_BSAE+0x00000122) /*对称解密错误*/
#define PHCDS_CalculateMAC_ERROR				(PHCDS_SDR_BSAE+0x00000123) /*MAC计算错误*/
#define PHCDS_DestoryKey_ERROR					(PHCDS_SDR_BSAE+0x00000124) /*销毁密码卡上的会话密钥错误*/
#define PHCDS_HashInit_ERROR					(PHCDS_SDR_BSAE+0x00000125) /*HASH初始化错误*/
#define PHCDS_HashUpdate_ERROR					(PHCDS_SDR_BSAE+0x00000126) /*HASH运算错误*/
#define PHCDS_HashFinal_ERROR					(PHCDS_SDR_BSAE+0x00000127) /*HASH运算结束错误*/
#define PHCDS_PARAMETER_INVALID     			(PHCDS_SDR_BSAE+0x00000128)    /*含义：输入参数无效。*/
#define PHCDS_SESSIONLIST_INVALID     			(PHCDS_SDR_BSAE+0x00000129) /*含义：SESSION链表为空。*/
#define PHCDS_SESSIONID_INVALID     			(PHCDS_SDR_BSAE+0x00000130)  /*含义：SESSION链表中没有SESSIONID指示的会话。*/
#define PHCDS_SESSIONSTAT_INVALID    			(PHCDS_SDR_BSAE+0x00000131) /*含义：SESSIONSTAT状态异常（非0和1）。*/
#define PHCDS_KEYCONTAINER_INVALID   			(PHCDS_SDR_BSAE+0x00000132) /*含义：密钥容器链表为空。*/
#define PHCDS_KEYRECORD_INVALID     			(PHCDS_SDR_BSAE+0x00000133) /*含义：密钥容器链表中没有指定的密钥。*/
#define PHCDS_KEYRECORDVALUETYPE_INVALID     	(PHCDS_SDR_BSAE+0x00000134) /*含义：密钥内容的类型值无效。*/
#define PHCDS_USERKEYLIST_INVALID     			(PHCDS_SDR_BSAE+0x00000135)  /*含义：密钥加密密钥链表为空。*/
#define PHCDS_USERKEY_INVALID     				(PHCDS_SDR_BSAE+0x00000136) /*含义：密钥加密密钥链表中没有指定的密钥。*/
#define PHCDS_USERKEYVALUETYPE_INVALID     		(PHCDS_SDR_BSAE+0x00000137) /*含义：密钥内容的类型值无效。*/
#define PHCDS_FILETYPE_INVALID      			(PHCDS_SDR_BSAE+0x00000138)  /*无效文件类型*/
#define PHCDS_PARAMNAME_INVALID      			(PHCDS_SDR_BSAE+0x00000139) /*无效参数名称*/
#define PHCDS_PARAMNAMELEN_INVALID      		(PHCDS_SDR_BSAE+0x00000140) /*无效参数名称长度*/
#define PHCDS_OPENFILE_ERROR      				(PHCDS_SDR_BSAE+0x00000141) /*打开文件失败*/
#define PHCDS_CREATFILE_ERROR      				(PHCDS_SDR_BSAE+0x00000142) /*创建文件失败*/
#define PHCDS_WRITEFILE_ERROR	  				(PHCDS_SDR_BSAE+0x00000143)/*写文件失败*/
#define PHCDS_CLOSEFILE_ERROR	   				(PHCDS_SDR_BSAE+0x00000144) /*关闭文件失败*/
#define PHCDS_FSEEK_ERROR          				(PHCDS_SDR_BSAE+0x00000145) /*改变文件指针失败*/
#define PHCDS_PAD_ERROR		   					(PHCDS_SDR_BSAE+0x00000146) /*对称加解密补位错误*/
#define PHCDS_USEPIN_ERROR						(PHCDS_SDR_BSAE+0x00000147)  /*用户PIN错误*/
#define PHCDS_KEYTYPE_INVALID   				(PHCDS_SDR_BSAE+0x00000148)  /*含义：密钥类型无效。*/
#define PHCDS_PRIVATEKEY_DECRYPT_ERROR    		(PHCDS_SDR_BSAE+0x00000149)  /*含义：私钥解密失败。*/
#define PHCDS_ERROR_DLL_LOAD_ERROR   			(PHCDS_SDR_BSAE+0x00000150)    /*加载加密卡库失败*/
#define PHCDS_MEMALLOC_ERROR  	    			(PHCDS_SDR_BSAE+0x00000151)     /*内存分配出错*/
#define PHCDS_DELETE_DIR_ERROR	   				(PHCDS_SDR_BSAE+0x00000152) /*删除文件失败*/
#define PHCDS_EXPORT_KEY_LENGTH_ERROR	   		(PHCDS_SDR_BSAE+0x00000153) /*备份密钥的长度有误*/
#define PHCDS_NO_KEY							(PHCDS_SDR_BSAE+0x00000154) /*无此密钥*/
#define PHCDS_CARD_FLAG_ERROR				   	(PHCDS_SDR_BSAE+0x00000155) /*加密卡标识配置有误*/
#define PHCDS_NO_CARD_SESSION_ERROR				(PHCDS_SDR_BSAE+0x00000156) /*没有加密卡会话*/
#define PHCDS_SOCKET_SERVER_RECV_ERROR			(PHCDS_SDR_BSAE+0x00000157) /*密码机接收数据错误*/
#define PHCDS_SOCKET_SERVER_PACKET_ERROR		(PHCDS_SDR_BSAE+0x00000158) /*密码机解析数据错误*/
#define PHCDS_SESSIONKEY_INVALID				(PHCDS_SDR_BSAE+0x00000159) /*会话密钥有误*/
#define PHCDS_CONFIGFILE_INVALID				(PHCDS_SDR_BSAE+0x00000160) /*配置文件有误*/
#define PHCDS_INDATA_MAXDATA					(PHCDS_SDR_BSAE+0x00000161) /*参数超过最大值*/
#define PHCDS_SESSIONKEYHANDLE_MAX              (PHCDS_SDR_BSAE+0x00000162) /*会话密钥句柄超过最大值*/
#define PHCDS_NOSUPPORT_ALGID					(PHCDS_SDR_BSAE+0x00000163) /*不支持的算法*/
#define PHCDS_HASH_MAXCOUNT						(PHCDS_SDR_BSAE+0x00000164) /*最大的hash数*/
#define PHCDS_AGREEMENTHANDLE_MAX               (PHCDS_SDR_BSAE+0x00000165) /*协商参数句柄超过最大值*/
#define PHCDS_KEY_ERROR							(PHCDS_SDR_BSAE+0x00000166) /*密钥格式错误*/
#define PHCDS_KEYLENGTH_ERROR					(PHCDS_SDR_BSAE+0x00000167) /*密钥长度错误*/

/*以下为密码机客户端的错误信息*/
#define SDF_SDR_BASE				0x04000000					/*错误码基础值*/
#define SDF_SDR_UNKNOWERR			(SDF_SDR_BSAE + 0x00000001)	/*未知错误*/
#define SDF_SDR_NOTSUPPORT			(SDF_SDR_BSAE + 0x00000002)	/*不支持的接口调用*/
#define SDF_SDR_COMMFAIL			(SDF_SDR_BSAE + 0x00000003)	/*与设备通信失败*/
#define SDF_SDR_HARDFAIL			(SDF_SDR_BSAE + 0x00000004)	/*运算模块无响应*/
#define SDF_SDR_OPENDEVICE			(SDF_SDR_BSAE + 0x00000005)	/*打开设备失败*/
#define SDF_SDR_OPENSESSION			(SDF_SDR_BSAE + 0x00000006)	/*创建会话失败*/
#define SDF_SDR_PARDENY				(SDF_SDR_BSAE + 0x00000007)	/*无私钥使用权限*/
#define SDF_SDR_KEYNOTEXIST			(SDF_SDR_BSAE + 0x00000008)	/*不存在的密钥调用*/
#define SDF_SDR_ALGNOTSUPPORT		(SDF_SDR_BSAE + 0x00000009)	/*不支持的算法调用*/
#define SDF_SDR_ALGMODNOTSUPPORT	(SDF_SDR_BSAE + 0x0000000A)	/*不支持的算法模式调用*/
#define SDF_SDR_PKOPERR				(SDF_SDR_BSAE + 0x0000000B)	/*公钥运算失败*/
#define SDF_SDR_SKOPERR				(SDF_SDR_BSAE + 0x0000000C)	/*私钥运算失败*/
#define SDF_SDR_SIGNERR				(SDF_SDR_BSAE + 0x0000000D)	/*签名运算失败*/
#define SDF_SDR_VERIFYERR			(SDF_SDR_BSAE + 0x0000000E)	/*验证签名失败*/
#define SDF_SDR_SYMOPERR			(SDF_SDR_BSAE + 0x0000000F)	/*对称算法运算失败*/
#define SDF_SDR_STEPERR				(SDF_SDR_BSAE + 0x00000010)	/*多步运算步骤错误*/
#define SDF_SDR_FILESIZEERR			(SDF_SDR_BSAE + 0x00000011)	/*文件长度超出限制*/
#define SDF_SDR_FILENOEXIST			(SDF_SDR_BSAE + 0x00000012)	/*指定的文件不存在*/
#define SDF_SDR_FILEOFSERR			(SDF_SDR_BSAE + 0x00000013)	/*文件起始位置错误*/
#define SDF_SDR_KEYTYPEERR			(SDF_SDR_BSAE + 0x00000014)	/*密钥类型错误*/
#define SDF_SDR_KEYERR				(SDF_SDR_BSAE + 0x00000015)	/*密钥错误*/
/* 非标准错误 */
#define SDF_SDR_PARAMETER_INVALID   (SDF_SDR_BSAE + 0x00000016)	/*参数错误*/

#define SDF_SDR_GETCONFIG     		(SDF_SDR_BSAE + 0x00000100)	/*获取配置文件出错*/
#define SDF_SDR_FUNCNUM       		(SDF_SDR_BSAE + 0x00000200) /*方法类型错误*/
#define SDF_SDR_LBLTYPE       		(SDF_SDR_BSAE + 0x00000201)	/*标签类型错误*/
#define SDF_SDR_MEMALLOC      		(SDF_SDR_BSAE + 0x00000202)	/*内存分配出错*/
#define SDF_SDR_INPUTEMPTY    		(SDF_SDR_BSAE + 0x00000203) /*入参为空*/
                    		
#define SDF_SDR_NOGOODIP      		(SDF_SDR_BSAE + 0x00000300)	/*没有可用的密码机*/
#define SDF_SDR_NULLHOSTNAME  		(SDF_SDR_BSAE + 0x00000301)	/*配置文件为空*/
#define SDF_SDR_GETHOSTNAME   		(SDF_SDR_BSAE + 0x00000302)	/*获取服务器失败*/
#define SDF_SDR_SOCKETCREAT   		(SDF_SDR_BSAE + 0x00000303)	/*创建socket连接失败*/
#define SDF_SDR_SOCKETCONN    		(SDF_SDR_BSAE + 0x00000304)	/*socket连接失败*/
#define SDF_SDR_SOCKETSEND    		(SDF_SDR_BSAE + 0x00000305)	/*socket发送数据失败*/
#define SDF_SDR_SOCKETRECV    		(SDF_SDR_BSAE + 0x00000306)	/*socket接收数据失败*/
#define SDF_SDR_SOCKETBIND    		(SDF_SDR_BSAE + 0x00000307)	/*socket端口绑定失败*/
                   		
#define SDF_SDR_ARGVENCODE    		(SDF_SDR_BSAE + 0x00000400)	/*数据编码失败*/
#define SDF_SDR_ARGVDECODE    		(SDF_SDR_BSAE + 0x00000401)	/*数据解码失败*/
#define SDF_SDR_HEADENCODE    		(SDF_SDR_BSAE + 0x00000402)	/*数据头编码失败*/
#define SDF_SDR_HEADDECODE    		(SDF_SDR_BSAE + 0x00000403)	/*数据头解码失败*/
#define SDF_SDR_RETVENCODE    		(SDF_SDR_BSAE + 0x00000404)	/*接收数据编码失败*/
#define SDF_SDR_RETVDECODE    		(SDF_SDR_BSAE + 0x00000405)	/*接收数据解码失败*/
                      		
#define SDF_SDR_OPENFILE      		(SDF_SDR_BSAE + 0x00000500)	/*打开文件失败*/
#define SDF_SDR_GETFILESTAT   		(SDF_SDR_BSAE + 0x00000501)	/*获取文件状态失败*/
#define SDF_SDR_NULLFILE      		(SDF_SDR_BSAE + 0x00000502)	/*空文件错误*/
#define SDF_SDR_READFILE      		(SDF_SDR_BSAE + 0x00000503)	/*读文件失败*/
#define SDF_SDR_WRITEFILE     		(SDF_SDR_BSAE + 0x00000504)	/*写文件失败*/
#define SDF_SDR_DELETEFILE    		(SDF_SDR_BSAE + 0x00000505)	/*删除文件失败*/
#define SDF_SDR_OPENDIR       		(SDF_SDR_BSAE + 0x00000506)	/*打开目录失败*/

#define SDF_SDR_NOPERMISSION  		(SDF_SDR_BSAE + 0x00000600)	/*无此权限*/

#endif




#define SGD_SM1_ECB			0x00000101		/*SM1算法ECB加密模式*/
#define SGD_SM1_CBC			0x00000102		/*SM1算法CBC加密模式*/
#define SGD_SM1_CFB			0x00000104		/*SM1算法CFB加密模式*/
#define SGD_SM1_OFB			0x00000108		/*SM1算法OFB加密模式*/
#define SGD_SM1_MAC			0x00000110		/*SM1算法MAC运算*/
#define SGD_SSF33_ECB		0x00000201		/*SSF33算法ECB加密模式*/
#define SGD_SSF33_CBC		0x00000202		/*SSF33算法CBC加密模式*/
#define SGD_SSF33_CFB		0x00000204		/*SSF33算法CFB加密模式*/
#define SGD_SSF33_OFB		0x00000208		/*SSF33算法OFB加密模式*/
#define SGD_SSF33_MAC		0x00000210		/*SSF33算法MAC运算*/
#define SGD_SMS4_ECB		0x00000401		/*SMS4算法ECB加密模式*/
#define SGD_SMS4_CBC		0x00000402		/*SMS4算法CBC加密模式*/
#define SGD_SMS4_CFB		0x00000404		/*SMS4算法CFB加密模式*/
#define SGD_SMS4_OFB		0x00000408		/*SMS4算法OFB加密模式*/
#define SGD_SMS4_MAC		0x00000410		/*SMS4算法MAC运算*/

#define SGD_RSA				0x00010000		/*RSA算法*/
#define SGD_SM2_1			0x00020100		/*椭圆曲线签名算法*/
#define SGD_SM2_2			0x00020200		/*椭圆曲线密钥交换协议*/
#define SGD_SM2_3			0x00020400		/*椭圆曲线加密算法*/

#define SGD_SM3				0x00000001		/*SM3杂凑算法*/
#define SGD_SHA1			0x00000002		/*SHA_1杂凑算法*/
#define SGD_SHA256			0x00000004		/*SHA_256杂凑算法*/

#define SGD_SM3_RSA			0x00001001		/*基于SM3算法和RSA算法的签名*/
#define SGD_SHA1_RSA		0x00001002		/*基于SHA_1算法和RSA算法的签名*/
#define SGD_SHA256_RSA		0x00001004		/*基于SHA_256算法和RSA算法的签名*/
#define SGD_SM3_SM2			0x00020101		/*基于SM2算法和SM3算法的签名*/


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

/* 打开密码设备 */
typedef int (DEVICEAPI *SDF_OpenDevice_Ptr)(void **phDeviceHandle);
/* 关闭密码设备，并释放相关资源 */
typedef int (DEVICEAPI *SDF_CloseDevice_Ptr)(void *hDeviceHandle);
/* 创建与密码设备的会话 */
typedef int (DEVICEAPI *SDF_OpenSession_Ptr)(void *hDeviceHandle, void **phSessionHandle);
/* 关闭与密码设备已建立的会话，并释放相关资源 */
typedef int (DEVICEAPI *SDF_CloseSession_Ptr)(void *hSessionHandle);
/* 获取密码设备能力描述 */
typedef int (DEVICEAPI *SDF_GetDeviceInfo_Ptr)(void *hSessionHandle,DEVICEINFO *pstDeviceInfo);
/* 获取指定长度的随机数 */
typedef int (DEVICEAPI *SDF_GenerateRandom_Ptr)(void *hSessionHandle, unsigned int  uiLength,unsigned char *pucRandom);
/* 获取密码设备内部存储的指定索引私钥的使用权 */
typedef int (DEVICEAPI *SDF_GetPrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex,unsigned char *pucPassword,unsigned int  uiPwdLength);
/* 释放密码设备存储的指定索引私钥的使用授权 */
typedef int (DEVICEAPI *SDF_ReleasePrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex);
/* 导出密码设备内部存储的指定索引位置的签名公钥 */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* 导出密码设备内部存储的指定索引位置的加密公钥 */
typedef int  (DEVICEAPI *SDF_ExportEncPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* 请求密码设备产生指定模长的RSA密钥对 */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyBits,RSArefPublicKey *pucPublicKey,RSArefPrivateKey *pucPrivateKey);
/* 生成会话密钥并用指定索引的内部加密公钥加密输出，同时返回密钥句柄 */
typedef int (DEVICEAPI *SDF_GenerateKeyWithIPK_RSA_Ptr)(void *hSessionHandle,unsigned int uiIPKIndex,unsigned int uiKeyBits,unsigned char *pucKey,unsigned int *puiKeyLength,void **phKeyHandle);
/* 生成会话密钥并用外部公钥加密输出，同时返回密钥句柄 */
typedef int (DEVICEAPI *SDF_GenerateKeyWithEPK_RSA_Ptr)(void *hSessionHandle, unsigned int uiKeyBits,RSArefPublicKey *pucPublicKey,unsigned char *pucKey,unsigned int *puiKeyLength,void **phKeyHandle);
/* 导入会话密钥并用内部私钥解密，同时返回密钥句柄 */
typedef int (DEVICEAPI *SDF_ImportKeyWithISK_RSA_Ptr)(void *hSessionHandle,unsigned int uiISKIndex,unsigned char *pucKey,unsigned int puiKeyLength,void **phKeyHandle);
/* 将由内部加密公钥加密的会话密钥转换为由外部指定的公钥加密，可用于数字信封转换。*/
typedef int (DEVICEAPI *SDF_ExchangeDigitEnvelopeBaseOnRSA_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey,unsigned char *pucDEInput,unsigned int  uiDELength,unsigned char *pucDEOutput,unsigned int  *puiDELength);
/* 导出密码设备内部存储的指定索引位置的签名公钥 */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* 导出密码设备内部存储的指定索引位置的加密公钥 */
typedef int (DEVICEAPI *SDF_ExportEncPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* 请求密码设备产生指定类型和模长的ECC密钥对 */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_ECC_Ptr)(void *hSessionHandle,unsigned int  uiAlgID,unsigned int  uiKeyBits,ECCrefPublicKey *pucPublicKey,ECCrefPrivateKey *pucPrivateKey);
/* 生成会话密钥并用指定索引的内部ECC加密公钥加密输出，同时返回密钥句柄*/
typedef int (DEVICEAPI *SDF_GenerateKeyWithIPK_ECC_Ptr)(void *hSessionHandle,unsigned int uiIPKIndex,unsigned int uiKeyBits,ECCCipher *pucKey,void **phKeyHandle);
/* 生成会话密钥并用外部ECC公钥加密输出，同时返回密钥句柄 */
typedef int (DEVICEAPI *SDF_GenerateKeyWithEPK_ECC_Ptr)(void *hSessionHandle,unsigned int uiKeyBits,unsigned int  uiAlgID,ECCrefPublicKey *pucPublicKey,ECCCipher *pucKey,void **phKeyHandle);
/* 导入会话密钥并用内部ECC加密私钥解密，同时返回密钥句柄 */
typedef int (DEVICEAPI *SDF_ImportKeyWithISK_ECC_Ptr)(void *hSessionHandle,unsigned int uiISKIndex,ECCCipher *pucKey,void **phKeyHandle);
/* 使用ECC密钥协商算法，为计算会话密钥而产生协商参数，同时返回指定索引位置的ECC公钥、临时ECC密钥对的公钥及协商句柄。*/
typedef int (DEVICEAPI *SDF_GenerateAgreementDataWithECC_Ptr)(void *hSessionHandle, unsigned int uiISKIndex,unsigned int uiKeyBits,unsigned char *pucSponsorID,unsigned int uiSponsorIDLength,ECCrefPublicKey  *pucSponsorPublicKey,ECCrefPublicKey  *pucSponsorTmpPublicKey,void **phAgreementHandle);
/* 使用ECC密钥协商算法，使用自身协商句柄和响应方的协商参数计算会话密钥，同时返回会话密钥句柄 */
typedef int (DEVICEAPI *SDF_GenerateKeyWithECC_Ptr)(void *hSessionHandle,unsigned char *pucResponseID,unsigned int uiResponseIDLength,ECCrefPublicKey *pucResponsePublicKey,ECCrefPublicKey *pucResponseTmpPublicKey,void *hAgreementHandle,void **phKeyHandle);
/* 使用ECC密钥协商算法，产生协商参数并计算会话密钥，同时返回产生的协商参数和和密钥句柄。*/
typedef int (DEVICEAPI *SDF_GenerateAgreementDataAndKeyWithECC_Ptr)(void *hSessionHandle,unsigned int uiISKIndex,unsigned int uiKeyBits,unsigned char *pucResponseID,unsigned int uiResponseIDLength,unsigned char *pucSponsorID,unsigned int uiSponsorIDLength,ECCrefPublicKey *pucSponsorPublicKey,ECCrefPublicKey *pucSponsorTmpPublicKey,ECCrefPublicKey  *pucResponsePublicKey,ECCrefPublicKey  *pucResponseTmpPublicKey,void **phKeyHandle);
/* 将由内部加密公钥加密的会话密钥转换为由外部指定的公钥加密，可用于数字信封转换。*/
typedef int (DEVICEAPI *SDF_ExchangeDigitEnvelopeBaseOnECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,unsigned int  uiAlgID,ECCrefPublicKey *pucPublicKey,ECCCipher *pucEncDataIn,ECCCipher *pucEncDataOut);
/* 生成会话密钥并用密钥加密密钥加密输出，同时返回密钥句柄。*/
typedef int (DEVICEAPI *SDF_GenerateKeyWithKEK_Ptr)(void *hSessionHandle,unsigned int uiKeyBits,unsigned int  uiAlgID,unsigned int uiKEKIndex, unsigned char *pucKey, unsigned int *puiKeyLength, void **phKeyHandle);
/* 导入会话密钥并用密钥加密密钥解密，同时返回会话密钥句柄。*/
typedef int (DEVICEAPI *SDF_ImportKeyWithKEK_Ptr)(void *hSessionHandle,unsigned int  uiAlgID,unsigned int uiKEKIndex,unsigned char *pucKey,unsigned int *puiKeyLength,void **phKeyHandle);
/* 导入明文会话密钥，同时返回密钥句柄*/
typedef int (DEVICEAPI *SDF_ImportKey_Ptr)(void *hSessionHandle,unsigned char *pucKey, unsigned int uiKeyLength,void **phKeyHandle);
/* 销毁会话密钥，并释放为密钥句柄分配的内存等资源。*/
typedef int (DEVICEAPI *SDF_DestoryKey_Ptr)(void *hSessionHandle,void *hKeyHandle);
/* 指定使用外部公钥对数据进行运算 */
typedef int (DEVICEAPI *SDF_ExternalPublicKeyOperation_RSA_Ptr)(void *hSessionHandle,RSArefPublicKey *pucPublicKey,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* 指定使用外部私钥对数据进行运算*/
typedef int (DEVICEAPI *SDF_ExternalPrivateKeyOperation_RSA_Ptr)(void *hSessionHandle,RSArefPrivateKey *pucPrivateKey,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* 使用内部指定索引的公钥对数据进行运算 */
typedef int (DEVICEAPI *SDF_InternalPublicKeyOperation_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* 使用内部指定索引的私钥对数据进行运算 */
typedef int (DEVICEAPI *SDF_InternalPrivateKeyOperation_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);
/* 使用外部ECC私钥对数据进行签名运算 */
typedef int (DEVICEAPI *SDF_ExternalSign_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPrivateKey *pucPrivateKey,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);
/* 使用外部ECC公钥对ECC签名值进行验证运算 */
typedef int (DEVICEAPI *SDF_ExternalVerify_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucDataInput,unsigned int  uiInputLength,ECCSignature *pucSignature);
/* 使用内部ECC私钥对数据进行签名运算 */
typedef int (DEVICEAPI *SDF_InternalSign_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);
/* 使用内部ECC公钥对ECC签名值进行验证运算 */
typedef int (DEVICEAPI *SDF_InternalVerify_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);
/* 使用外部ECC公钥对数据进行加密运算 */
typedef int (DEVICEAPI *SDF_ExternalEncrytp_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucData,unsigned int  uiDataLength,ECCCipher *pucEncData);
/* 使用外部ECC私钥进行解密运算 */
typedef int (DEVICEAPI *SDF_ExternalDecrypt_ECC_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPrivateKey *pucPrivateKey,ECCCipher *pucEncData,unsigned char *pucData,unsigned int  *puiDataLength);
/* 使用指定的密钥句柄和IV对数据进行对称加密运算 */
typedef int (DEVICEAPI *SDF_Encrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucData,unsigned int uiDataLength,unsigned char *pucEncData,unsigned int  *puiEncDataLength);
/* 使用指定的密钥句柄和IV对数据进行对称解密运算 */
typedef int (DEVICEAPI *SDF_Decrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucEncData,unsigned int  uiEncDataLength,unsigned char *pucData,unsigned int *puiDataLength);
/* 使用指定的密钥句柄和IV对数据进行MAC运算 */
typedef int (DEVICEAPI *SDF_CalculateMAC_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucData,unsigned int uiDataLength,unsigned char *pucMAC,unsigned int  *puiMACLength);
/* 三步式数据杂凑运算第一步。*/
typedef int (DEVICEAPI *SDF_HashInit_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucID,unsigned int uiIDLength);
/* 三步式数据杂凑运算第二步，对输入的明文进行杂凑运算 */
typedef int (DEVICEAPI *SDF_HashUpdate_Ptr)(void *hSessionHandle,unsigned char *pucData,unsigned int  uiDataLength);
/* 三步式数据杂凑运算第三步，杂凑运算结束返回杂凑数据并清除中间数据 */
typedef int (DEVICEAPI *SDF_HashFinal_Ptr)(void *hSessionHandle,unsigned char *pucHash,unsigned int  *puiHashLength);
/* 在密码设备内部创建用于存储用户数据的文件 */
typedef int (DEVICEAPI *SDF_CreateFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen,unsigned int uiFileSize);
/* 读取在密码设备内部存储用户数据的文件的内容 */
typedef int (DEVICEAPI *SDF_ReadFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen,unsigned int uiOffset,unsigned int *puiFileLength,unsigned char *pucBuffer);
/* 向密码设备内部存储用户数据的文件中写入内容 */
typedef int (DEVICEAPI *SDF_WriteFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen,unsigned int uiOffset,unsigned int uiFileLength,unsigned char *pucBuffer);
/* 删除指定文件名的密码设备内部存储用户数据的文件 */
typedef int (DEVICEAPI *SDF_DeleteFile_Ptr)(void *hSessionHandle,unsigned char *pucFileName,unsigned int uiNameLen);

#ifdef PUHUA
/*
hSessionHandle[IN] 会话句柄
uiKeyIndex[IN]	内部私钥索引号
signKeyType[IN]	密钥类型	1为签名密钥，否则为加密密钥
pucDataInput[IN]	输入数据
uiInputLength[IN]	输入数据长度
pucDataOutput[OUT]	运算结果
puiOutputLength[OUT] 运算结果长度
*/
typedef int (DEVICEAPI *SDF_InternalPrivateKeyOperation_RSA_EX_Ptr)( void *hSessionHandle,  unsigned int  uiKeyIndex,unsigned int  signKeyType,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLength);

/*
参数说明：
hSessionHandle[IN] 会话句柄
uiISKIndex[IN]	内部私钥索引号
signKeyType[IN]	密钥类型	1为签名密钥，否则为加密密钥
ECCCipher[IN]	输入密文数据
pucData[OUT]	运算结果
puiDataLength[OUT] 运算结果长度
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
