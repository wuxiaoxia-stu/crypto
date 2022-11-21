import java.io.Console;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.globalplatform.Certificate;
import net.netca.pki.encoding.globalplatform.ECCPublicKey;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONBoolean;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
import net.netca.pki.encoding.asn1.pki.CertificationRequest;
import net.netca.pki.encoding.asn1.pki.Extension;
import net.netca.pki.encoding.asn1.pki.Extensions;
import net.netca.pki.encoding.asn1.pki.NetcaSigner;
import net.netca.pki.encoding.asn1.pki.OctetStringExtension;
import net.netca.pki.KeyPair;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.ObjectIdentifier;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.JCESecureRandomGenerator;

public class SignGPCert {

	public static void main(String[] args) throws Exception{
		
		if(args.length!=3) {
            System.out.println("Usage: java SignGPCert jsonFileName pwd outputFileName");
            return;
        }
		
		String x509CertFileName;
		String p10FileName;
		String gpCertFileName=args[2];
		String pwd=args[1];
		String jsonFileName=args[0];
		
		//JSON文件必需是UTF-8编码的，可以带BOM头，是JSON对象
		JSONObject json=getJsonFromFile(jsonFileName);
		// "CACertFileName":"CA证书文件名"
		x509CertFileName=getCACertFileName(json);
		X509Certificate x509=getCert(x509CertFileName);
		
		//"P10FileName":"证书请求文件名"
		p10FileName=getP10FileName(json);
		CertificationRequest p10=getCertReq(p10FileName);
		ECCPublicKey publicKey=new ECCPublicKey(p10.getSubjectPublicKeyInfo());
		
		
		boolean checkLength=getCheckLength(json);
		
		Certificate cert=new Certificate();
		
		/*
		 * "CertType":"证书类型"
		 * eUICC：eUICC client
		 * SM-DP：SM-DP
		 * SM-SR：SM-DP
		 * 不存在为eUICC
		 */
		int certType=getCertType(json);
		if(certType==-1){
			cert.setKeyUsage(Certificate.KEYAGREEMENT);
		} else {
			cert.setKeyUsage(Certificate.DIGITAL_SIGNATURE|Certificate.VERIFICATION_ENCIPHERMENT);
		}
		
		/*
		 * "CAIdentifier":"Hex编码的CAIdentifier"
		 * 或者
		 * "CAIdentifier":{
		 * 		"Value":"CAIdentifier值"
		 * 		"Encode":"编码类型"
		 * }
		 * 如果Encode不存在，则CAIdentifier值为Hex编码的CAIdentifier
		 * 如果Encode为Hex，则CAIdentifier值为Hex编码的CAIdentifier
		 * 如果Encode为OID Content Encode，则CAIdentifier值为OID的字符串表示，例如:1.2.3.4，最终得到的是OID的DER编码的Content部分
		 */
		byte[] caId=getCAIdentifier(json);
		checkCAIdentifier(checkLength,caId);
		cert.setCAIdentifier(caId);
		
		/*
		 * "SerialNumber":"序列号的值"
		 * 如果SerialNumber项不存在则是16个字节的随机数
		 * 序列号的值如果是random，则是16个字节的随机数
		 * 序列号的值如果是random:length，则是length个字节的随机数
		 * 序列号的值是Hex编码的序列号
		 */
		byte[] sn=getSerialNumber(json);
		checkSerialNumber(checkLength,sn);
		cert.setSerialNumber(sn);
		
		/*
		 * "KeyUsage":["KeyUsage值1","KeyUsage值2",...]
		 * KeyUsage值为Verification、Encipherment、Computation、Decipherment、
		 * Secure messaging in response data fields、Secure messaging in command data fields、
		 * Confidentiality、Cryptographic Checksum、Digital Signature、Cryptographic Authorization、Key Agreement
		 */
		int ku=getKeyUsage(json);
		if(ku!=-1){
			cert.setKeyUsage(ku);
		}
		
		/*
		 *	 "SubjectIdentifier"格式同"CAIdentifier"
		 */
		byte[] subjectId=getSubjectIdentifier(json);
		checkSubjectIdentifier(checkLength,subjectId);
		cert.setSubjectIdentifier(subjectId);
		
		cert.setPublicKey(publicKey);
		
		/*
		 *	"EffectiveDate":"YYYYMMDD"
		 *	可选
		 */
		String effectiveDate=getEffectiveDate(json);
		if(effectiveDate!=null){
			cert.setEffectiveDate(effectiveDate);
		}
		
		/*
		 *	"ExpirationDate":"YYYYMMDD"
		 */
		String expirationDate=getExpirationDate(json);
		cert.setExpirationDate(expirationDate);
		
		/*
		 * "IssuerKeyId":"Hex编码的IssuerKeyId"
		 * 或者
		 * "IssuerKeyId":"From Cert"
		 * 把颁发者证书的主体密钥标识符设置为IssuerKeyId
		 */
		byte[] issuerKeyId=getIssuerKeyId(json,x509);
		
		if(certType==-1){
			/*
			 *	 "ECASDImageNumber"格式同"CAIdentifier"
			 */
			byte[] ECASDImageNumber=getECASDImageNumber(json);
			checkECASDImageNumber(checkLength,ECASDImageNumber);
			cert.setECASDImageNumber(ECASDImageNumber);
			
			/*
			 *	 "eUICCSupplierIdentifier"格式同"CAIdentifier"
			 */
			byte[]eUICCSupplierIdentifier=geteUICCSupplierIdentifier(json);
			
			/*
			 *	 "eUICCProductLineIdentifier"格式同"CAIdentifier"
			 */
			byte[]eUICCProductLineIdentifier=geteUICCProductLineIdentifier(json);
			
			/*
			 * "eUICCExtendedGSMASASAccreditationSerialNumber"格式同"CAIdentifier"
			 */
			byte[] eUICCExtendedGSMASASAccreditationSerialNumber=geteUICCExtendedGSMASASAccreditationSerialNumber(json);
			
			cert.setDiscretionaryData(
					eUICCSupplierIdentifier,
					eUICCProductLineIdentifier,
					eUICCExtendedGSMASASAccreditationSerialNumber,
					issuerKeyId);
			
		} else {
			cert.setDiscretionaryData(issuerKeyId,certType);
		}
		
		net.netca.pki.Certificate issuerCert=new net.netca.pki.Certificate(x509.derEncode());
		KeyPair keypair=null;
		NetcaSigner signer=null;
		try{
			//pwd=getPwd();
			keypair=issuerCert.getKeyPair(net.netca.pki.Certificate.SEARCH_KEYPAIR_FLAG_DEVICE,
					net.netca.pki.Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取颁发者证书的私钥失败");
		        return;
			}
			signer=new NetcaSigner(keypair);
			AlgorithmIdentifier signAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
			byte[] data=cert.sign(signer, signAlgo);
			SaveFile(gpCertFileName,data);
		} finally{
			if(keypair!=null){
				keypair.free();
			}
			if(signer!=null){
				signer.free();
			}
			issuerCert.free();
		}
		
		
		System.out.println("签证书成功");
	}
	/*
	private static String getPwd() throws Exception
	{
		Console cons= System.console();
		if(cons==null)
		{
			throw new Exception("System.console fail");
		}
		char[] passwd;
		
		passwd=cons.readPassword("请输入密码\n");
		if(passwd==null) 
		{
			throw new Exception("readPassword fail");
		}
		
		return new String(passwd);
	}
	*/
	private static byte[] getSubjectKeyId(X509Certificate issuerCert) throws Exception{
		
		Extensions exts=issuerCert.getExtensions();
		if(exts==null) {
			throw new Exception("颁发者证书没有扩展");
		}
		Extension ext=exts.get(Extension.SUBJECT_KEYIDENTIFIER_OID);
		if(ext==null) {
			throw new Exception("颁发者证书没有主体密钥标识符扩展");
		}

		return ((OctetStringExtension)(ext.getExtensionObject())).getValue();
	}
	private static byte[] getIssuerKeyId(JSONObject jsonObj,X509Certificate issuerCert) throws Exception{
		JSON json=jsonObj.getValue("IssuerKeyId");
		if(json==null){
			return null;
		}
		if(json instanceof JSONString==false){
			throw new Exception("bad IssuerKeyId,not json string");
		} 
		
		String str=((JSONString)json).getString();
		if(str.equals("From Cert")){
			return getSubjectKeyId(issuerCert);
		} else {
			return Hex.decode(str);
		}
	}
	
	private static byte[] geteUICCExtendedGSMASASAccreditationSerialNumber(JSONObject jsonObj) throws Exception{
		return getByteStringValue(jsonObj,"eUICCExtendedGSMASASAccreditationSerialNumber",true);
	}
	
	private static byte[] geteUICCProductLineIdentifier(JSONObject jsonObj) throws Exception{
		return getByteStringValue(jsonObj,"eUICCProductLineIdentifier",true);
	}
	
	private static byte[] geteUICCSupplierIdentifier(JSONObject jsonObj) throws Exception{
		return getByteStringValue(jsonObj,"eUICCSupplierIdentifier",true);
	}
	
	private static void checkECASDImageNumber(boolean checkLength,byte[] number) throws Exception{
		if(checkLength==false){
			return;
		}
		int length=number.length;
		if(length<1 || length>16){
			throw new Exception("the length of ECASD Image Number must be [1,16]");
		}
		
	}
	
	private static byte[] getECASDImageNumber(JSONObject jsonObj) throws Exception{
		return getByteStringValue(jsonObj,"ECASDImageNumber");
	}
	
	private static String getExpirationDate(JSONObject jsonObj) throws Exception{
		return getJsonStringValue(jsonObj,"ExpirationDate");
	}
	
	private static String getEffectiveDate(JSONObject jsonObj) throws Exception{
		return getJsonStringValue(jsonObj,"EffectiveDate",null);
	}
	
	private static void checkSubjectIdentifier(boolean checkLength,byte[] subjectId) throws Exception{
		if(checkLength==false){
			return;
		}
		int length=subjectId.length;
		if(length<1 || length>16){
			throw new Exception("the length of SubjectIdentifier must be [1,16]");
		}
		
	}
	
	private static byte[] getSubjectIdentifier(JSONObject jsonObj) throws Exception{
		return getByteStringValue(jsonObj,"SubjectIdentifier");
	}
	
	
	private static int getKeyUsage(String str) throws Exception{
		if(str.equals("Verification")|| str.equals("Encipherment")){
			return Certificate.VERIFICATION_ENCIPHERMENT;
		} else if(str.equals("Computation")|| str.equals("Decipherment")){
			return Certificate.COMPUTATION_DECIPHERMENT;
		} else if(str.equals("Secure messaging in response data fields")){
			return Certificate.SECURE_MESSAGING_IN_RESPONSE;
		} else if(str.equals("Secure messaging in command data fields")){
			return Certificate.SECURE_MESSAGING_IN_COMMAND;
		} else if(str.equals("Confidentiality")){
			return Certificate.CONFIDENTIALITY;
		} else if(str.equals("Cryptographic Checksum")){
			return Certificate.CHECKSUM;
		} else if(str.equals("Digital Signature")){
			return Certificate.DIGITAL_SIGNATURE;
		} else if(str.equals("Cryptographic Authorization")){
			return Certificate.AUTHORIZATION;
		} else if(str.equals("Key Agreement")){
			return Certificate.KEYAGREEMENT;
		} else {
			throw new Exception("unknown KeyUsage:"+str);
		}
	}
	private static int getKeyUsage(JSONArray jsonArray) throws Exception{
		int count=jsonArray.size();
		int keyUsage=0;
		JSON item;
		
		for(int i=0;i<count;i++){
			item=jsonArray.get(i);
			if(item instanceof JSONString ==false){
				throw new Exception("bad KeyUsage item,not json string");
			}
			keyUsage|=getKeyUsage(((JSONString)item).getString());
			
		}
		return keyUsage;
	}
	private static int getKeyUsage(JSONObject jsonObj) throws Exception{
		JSON json=jsonObj.getValue("KeyUsage");
		if(json==null){
			return -1;
		}
		if(json instanceof JSONArray==false){
			throw new Exception("bad KeyUsage,not json array");
		}
		return getKeyUsage((JSONArray)json);
	}
	
	private static void checkSerialNumber(boolean checkLength,byte[] sn) throws Exception{
		if(checkLength==false){
			return;
		}
		int length=sn.length;
		if(length<1 || length>16){
			throw new Exception("the length of SerialNumber must be [1,16]");
		}
		
	}
	
	private static byte[] getDefaultSerialNumber(int length)throws Exception {
		byte[] rand=JCESecureRandomGenerator.getInstance().generate(length);
		rand[0]&=0x7F;
		return rand;
	}
	
	private static byte[] getSerialNumber(JSONObject jsonObj) throws Exception{
		String value=getJsonStringValue(jsonObj,"SerialNumber","random");
		if(value.equals("random")){
			return getDefaultSerialNumber(16);
		} else if(value.startsWith("random:")){
			String number=value.substring(7);
			return getDefaultSerialNumber(java.lang.Integer.parseInt(number));
		} else {
			return Hex.decode(value);
		}
	}
	
	private static boolean getCheckLength(JSONObject jsonObj) throws Exception{
		return getBooleanValue(jsonObj,"CheckLength",false);
	}
	private static boolean getBooleanValue(JSONObject jsonObj,String name,boolean defaultValue) throws Exception{
		JSON json=jsonObj.getValue(name);
		if(json==null){
			return defaultValue;
		}
		if(json instanceof JSONBoolean==false){
			throw new Exception("bad " + name+",not json boolean");
		}
		return ((JSONBoolean)json).isTrue();
	}
	
	private static int getCertType(JSONObject jsonObj) throws Exception{
		String certType=getJsonStringValue(jsonObj,"CertType","eUICC");
		if(certType.equals("eUICC")){
			return -1;
		} else if(certType.equals("SM-DP")){
			return Certificate.CERT_TYPE_SM_DP;
		} else if(certType.equals("SM-SR")){
			return Certificate.CERT_TYPE_SM_SR;
		} else {
			throw new Exception("bad CertType:"+certType);
		}
	}
	private static byte[] encodeOid(String oid)throws Exception{
		ObjectIdentifier oidObj=new ObjectIdentifier(oid);
		byte[] encode=oidObj.encode();
		if(encode[1]<0){
			throw new Exception("oid "+oid+" too long");
		}
		byte[] data=new byte[encode.length-2];
		System.arraycopy(encode, 2, data, 0, data.length);
		return data; 
	}
	
	private static void checkCAIdentifier(boolean checkLength,byte[] caId) throws Exception{
		if(checkLength==false){
			return;
		}
		int length=caId.length;
		if(length<1 || length>16){
			throw new Exception("the length of CAIdentifier must be [1,16]");
		}
		
	}
	
	private static byte[] getCAIdentifier(JSONObject jsonObj) throws Exception{
		return getByteStringValue(jsonObj,"CAIdentifier");
	}
	private static byte[] getByteStringValue(JSONObject jsonObj) throws Exception{
		String value=getJsonStringValue(jsonObj,"Value");
		String encode=getJsonStringValue(jsonObj,"Encode","Hex");
		if(encode.equals("Hex")){
			return Hex.decode(value);
		} else if(encode.equals("UTF-8") || encode.equals("UTF8") ){
			return value.getBytes("UTF-8");
		} else if(encode.equals("OID Content Encode")){
			return encodeOid(value);
		} else {
			return value.getBytes(encode);
		}
	}
	
	private static byte[] getByteStringValue(JSONObject jsonObj,String name,boolean optional) throws Exception{
		JSON json=jsonObj.getValue(name);
		if(json==null){
			if(optional){
				return null;
			}
			throw new Exception("no " + name);
		}
		if(json instanceof JSONString){
			return Hex.decode(((JSONString)json).getString());
		} 
		if(json instanceof JSONObject==false){
			throw new Exception("bad " + name+",not json string or json object");
		}
		
		JSONObject jsonValue=(JSONObject)json;
		
		return getByteStringValue(jsonValue);
	}
	private static byte[] getByteStringValue(JSONObject jsonObj,String name) throws Exception{
		return getByteStringValue(jsonObj,name,false);
	}
	
	private static String getP10FileName(JSONObject jsonObj) throws Exception{
		return getJsonStringValue(jsonObj,"P10FileName");
	}
	private static String getCACertFileName(JSONObject jsonObj) throws Exception{
		return getJsonStringValue(jsonObj,"CACertFileName");
	}
	
	private static String getJsonStringValue(JSONObject jsonObj,String name) throws Exception{
		JSON json=jsonObj.getValue(name);
		if(json==null){
			throw new Exception("no " + name);
		}
		if(json instanceof JSONString==false){
			throw new Exception("bad " + name+",not json string");
		}
		return ((JSONString)json).getString();
	}
	
	private static String getJsonStringValue(JSONObject jsonObj,String name,String defaultValue) throws Exception{
		JSON json=jsonObj.getValue(name);
		if(json==null){
			return defaultValue;
		}
		if(json instanceof JSONString==false){
			throw new Exception("bad " + name+",not json string");
		}
		return ((JSONString)json).getString();
	}
	
	private static JSONObject getJsonFromFile(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		String str;
		if(data.length>=3 && (data[0]&0xFF)==0xEF && (data[1]&0xFF)==0xBB && (data[2]&0xFF)==0xBF) {
			str=new String(data,3,data.length-3,"UTF-8");
		} else {
			str=new String(data,"UTF-8");
		}
		JSON json=JSON.decode(str);
		if(json==null) {
			throw new Exception("bad json file:" + fileName);
		}
		if(json instanceof JSONObject==false){
			throw new Exception("bad json file:" + fileName+",not json object");
		}
		return (JSONObject)json;
	}
	
	private static CertificationRequest getCertReq(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new CertificationRequest(data);
	}
	
	private static X509Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509Certificate(data);
	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=Integer.MAX_VALUE) {
			throw new Exception("file too big");
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail");
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private static void SaveFile(String fileName,byte[] data)throws Exception {
		FileOutputStream f=new FileOutputStream(fileName);
		f.write(data);
		f.close();
	}
}
