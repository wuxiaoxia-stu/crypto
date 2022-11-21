import net.netca.pki.encoding.json.*;
import java.io.*;
import net.netca.pki.KeyPair;
import net.netca.pki.Device;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.*;
import net.netca.pki.encoding.Hex;
import net.netca.pki.PublicKey;
import java.util.*;
import net.netca.pki.Util;
import net.netca.pki.Hash;
import net.netca.pki.Certificate;
import net.netca.pki.CertReq;
import net.netca.pki.encoding.Base64;

public class SignCert {

	public static void main(String[] args) throws Exception{
		if(args.length!=5) {
            System.out.println("Usage: java SignCert issuerCertFileName pwd templateFileName dataFileName certFileName");
            return;
        }

		JSON templateJson=getJsonFromFile(args[2]);
		if (templateJson instanceof JSONObject==false) {
			System.out.println("模板文件不是JSON对象");
            return;
		}
		JSON dataJson=getJsonFromFile(args[3]);
		if (dataJson instanceof JSONObject==false) {
			System.out.println("数据文件不是JSON对象");
            return;
		}
		
		String pwd=args[1];
		String certFileName=args[4];
		String issuerCertFileName=args[0];
	
		Certificate issuerCert=getCert(issuerCertFileName);
		KeyPair keypair=null;
		NetcaSigner signer=null;
		
		try {
			keypair=issuerCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取颁发者证书的私钥失败");
	            return;
			}
			X500Name subject=createDN(((JSONObject)dataJson).getValue("subject"));
			X509Certificate x509IssuerCert=new X509Certificate(issuerCert.derEncode());
			X509CertificateBuilder builder=new X509CertificateBuilder(x509IssuerCert);
			
			builder.setSubject(subject);
			
			SubjectPublicKeyInfo publicKey=getPublicKey((JSONObject)dataJson);
			builder.setSubjectPublicKeyInfo(publicKey);
			
			int version=getVerison((JSONObject)templateJson);
			builder.setVersion(version);
			
			AlgorithmIdentifier signAlgo=getSignAlgo((JSONObject)templateJson,keypair);
			
			byte[] sn=getSerialNumber((JSONObject)templateJson);
			builder.setSerialNumber(sn);
			
			
			setValidity(builder,(JSONObject)templateJson);
			
			setIssuerUniqueID(builder,(JSONObject)templateJson);
			
			setSubjectUniqueID(builder,(JSONObject)templateJson);
			
			Extensions exts=createExtensions((JSONObject)templateJson,publicKey,x509IssuerCert);
			if(exts!=null) {
				builder.setExtensions(exts);
			}
			
			signer=new NetcaSigner(keypair);
			X509Certificate cert=builder.sign(signer,signAlgo);
			
			writeFile(certFileName,cert.derEncode());
	        System.out.println("Success");
		} finally {
			issuerCert.free();
			if(keypair!=null) {
				keypair.free();
			}
			
			if(signer!=null){
				signer.free();
			}
		}
	}
	
	private static JSON getJsonFromFile(String fileName) throws Exception{
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
		return json;
	}
	
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
			throw new Exception("file too big:"+ fileName);
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail:" + fileName);
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private static Certificate getCert(String certFileName) throws Exception{
		byte[] certData=readFile(certFileName);
		return new Certificate(certData);
	}
	
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
	
	private static X500Name createDN(JSON subjectItem) throws Exception {
		if(subjectItem==null) {
			throw new Exception("没有subject项");
		}
		
		if(subjectItem instanceof JSONArray==false) {
			throw new Exception("DN项不是JSON数组");
		}
		
		X500Name subject=new X500Name();
		JSONArray sujectArray=(JSONArray)subjectItem;
		int count=sujectArray.size();
		RelativeDistinguishedName rdn;
		for(int i=0;i<count;i++) {
			rdn=createRDN(sujectArray.get(i));
			subject.add(rdn);
		}
		return subject;
	}
	
	private static RelativeDistinguishedName createRDN(JSON rdnItem) throws Exception {
		if(rdnItem instanceof JSONArray==false) {
			throw new Exception("RDN项不是JSON数组");
		}
		JSONArray rdnArray=(JSONArray)rdnItem;
		int count=rdnArray.size();
		SetOf setOf;
		
		setOf=new SetOf((SetOfType)ASN1TypeManager.getInstance().get("RelativeDistinguishedName"));
		for(int i=0;i<count;i++){
			setOf.add(createAttributeTypeAndValue(rdnArray.get(i)).getASN1Object());
		}
		
		return new RelativeDistinguishedName(setOf);
	}
	
	private static AttributeTypeAndValue createAttributeTypeAndValue(JSON attrItem) throws Exception {
		if(attrItem instanceof JSONObject==false) {
			throw new Exception("AttributeTypeAndValue项不是JSON对象");
		}
		JSONObject attrObj=(JSONObject)attrItem;
		
		JSON item=attrObj.getValue("attributeType");
		if(item instanceof JSONString==false) {
			throw new Exception("属性类型项不是JSON字符串");
		}
		String attrType=((JSONString)item).getString();
		attrType=getAttributeTypeOid(attrType);
		
		ASN1Object attrValue;
		item=attrObj.getValue("attributeValueEncodeValue");
		if(item!=null) {
			if(item instanceof JSONString==false) {
				throw new Exception("属性值的编码值项不是JSON字符串");
			}
			String attrValueHex=((JSONString)item).getString();
			
			byte[] value=Hex.decode(attrValueHex);
			attrValue=ASN1Object.decode(value, AnyType.getInstance());
			return new AttributeTypeAndValue(attrType,attrValue);
		}
		
		item=attrObj.getValue("attributeValueEncodeType");
		if(item instanceof JSONString==false) {
			throw new Exception("属性值的编码类型项不是JSON字符串");
		}
		String attrValueType=((JSONString)item).getString();
		
		item=attrObj.getValue("attributeValue");
		if(item instanceof JSONString==false) {
			throw new Exception("属性值项不是JSON字符串");
		}
		String attrValueString=((JSONString)item).getString();
		attrValue=createAttributeValue(attrValueType,attrValueString);
		return new AttributeTypeAndValue(attrType,attrValue);
	}
	
	private static String getAttributeTypeOid(String value) {
		if (value.equalsIgnoreCase("C")) {
			return X500Name.COUNTRYNAME_OID;
		} else if (value.equalsIgnoreCase("S") || value.equalsIgnoreCase("ST")) {
			return X500Name.STATEORPROVINCENAME_OID;
		} else if (value.equalsIgnoreCase("L")) {
			return X500Name.LOCALITYNAME_OID;
		} else if (value.equalsIgnoreCase("O")) {
			return X500Name.ORGANIZATIONNAME_OID;
		} else if (value.equalsIgnoreCase("OU")) {
			return X500Name.ORGANIZATIONUNITNAME_OID;
		} else if (value.equalsIgnoreCase("CN")) {
			return X500Name.COMMONNAME_OID;
		} else if (value.equalsIgnoreCase("Email") || value.equalsIgnoreCase("E")) {
			return X500Name.EMAILADDRESS_OID;
		} else if (value.equalsIgnoreCase("DC")) {
			return X500Name.DOMAIN_COMPONENT_OID;
		} else if (value.equalsIgnoreCase("Title")) {
			return X500Name.TITLE_OID;
		} else if (value.equalsIgnoreCase("UID")) {
			return X500Name.USERID_OID;
		} else if (value.equalsIgnoreCase("SerialNumber")) {
			return X500Name.SERIALNUMBER_OID;
		} else {
			return value;
		}
	}
	
	private static ASN1Object createAttributeValue(String type,String value) throws Exception {
		if(type.equalsIgnoreCase("BMPString")) {
			return new BMPString(value);
		} else if(type.equalsIgnoreCase("IA5String")) {
			return new IA5String(value);
		} else if(type.equalsIgnoreCase("PrintableString")) {
			return new PrintableString(value);
		} else if(type.equalsIgnoreCase("UTF8String")) {
			return new UTF8String(value);
		} else if(type.equalsIgnoreCase("VisibleString")) {
			return new VisibleString(value);
		} else {
			throw new Exception("不支持的属性类型");
		}
	}
	
	private static SubjectPublicKeyInfo getPublicKey(JSONObject obj) throws Exception {
		JSON item=obj.getValue("p10FileName");
		byte[] p10Data;
		if(item!=null) {
			if(item instanceof JSONString==false) {
				throw new Exception("数据文件错误");
			}
			p10Data=readFile(((JSONString)item).getString());
		} else {
			item=obj.getValue("p10");
			if(item==null) {
				throw new Exception("数据文件错误，没有证书请求");
			}
			if(item instanceof JSONString==false) {
				throw new Exception("数据文件错误");
			}
			p10Data=Base64.decode(true, ((JSONString)item).getString());
		}
		CertReq p10=new CertReq(p10Data);
		PublicKey publicKey=null;
		try {
			if(p10.verify()==false) {
				throw new Exception("验证证书请求失败");
			}
			publicKey=p10.getPublicKey();
			if(publicKey==null) {
				throw new Exception("get public key fail");
			}
		
			SubjectPublicKeyInfo spki= new SubjectPublicKeyInfo(publicKey.encode());
			item=obj.getValue("subjectPublicKeyInfoAlgorithm");
			if(item==null) {
				return spki;
			}
			AlgorithmIdentifier algo=getPublicKeyAlgorithmIdentifier((JSONObject)item);
			if(algo==null) {
				throw new Exception("bad public key algorithm");
			}
			return new SubjectPublicKeyInfo(algo,spki.getSubjectPublicKey());
		} finally{
			p10.free();
			if(publicKey!=null){
				publicKey.free();
			}
		}
		
	}
	
	private static AlgorithmIdentifier getPublicKeyAlgorithmIdentifier(JSONObject obj) throws Exception {
		JSON item=obj.getValue("algorithm");
		if(item instanceof JSONString==false){
			return null;
		}
		JSONString str=(JSONString)item;
		String oid=getPublicKeyAlgoOid(str.getString());
		
		ASN1Object asn1Obj;
		item=obj.getValue("paramEncode");
		if(item!=null) {
			if(item instanceof JSONString==false){
				return null;
			}
			str=(JSONString)item;
			asn1Obj=ASN1Object.decode(Hex.decode(str.getString()), AnyType.getInstance());
			return new AlgorithmIdentifier(oid,asn1Obj);
		}
		item=obj.getValue("param");
		if(item==null) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(oid);
		}
		
		if(item instanceof JSONNull){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(oid);
		}
		
		if(oid.equals(AlgorithmIdentifier.ECPubKey_OID)
				|| oid.equals(AlgorithmIdentifier.ECDH_OID)
				|| oid.equals(AlgorithmIdentifier.ECMQV_OID)) {
			if(item instanceof JSONString==false){
				return null;
			}
			str=(JSONString)item;
			return new AlgorithmIdentifier(oid,new ObjectIdentifier(str.getString()));
		}
		
		
		if(oid.equals(AlgorithmIdentifier.RSAES_OAEP_OID)) {
			if(item instanceof JSONObject==false){
				return null;
			}
			RSAESOAEPParams oaepParam=getOaepParam((JSONObject)item);
			if(oaepParam==null) {
				return null;
			}
			return new AlgorithmIdentifier(oid,oaepParam.getASN1Object());
		}
		
		if(oid.equals(AlgorithmIdentifier.RSASSA_PSS_OID)) {
			RSASSAPSSParams pssParam=getPssParam((JSONObject)item);
			if(pssParam==null) {
				return null;
			}
			return new AlgorithmIdentifier(oid,pssParam.getASN1Object());
		}
		
		return null;
	}
	
	private static RSAESOAEPParams getOaepParam(JSONObject obj) throws Exception {
		JSON item=obj.getValue("hashAlgorithm");
		String oid;
		if(item instanceof JSONString==false){
			return null;
		}
		oid=((JSONString)item).getString();
		AlgorithmIdentifier hashAlgo=createHashAlgorithm(oid);
		
		item=obj.getValue("mgf1HashAlgorithm");
		if(item instanceof JSONString==false){
			return null;
		}
		oid=((JSONString)item).getString();
		AlgorithmIdentifier mgf1HashAlgo=createHashAlgorithm(oid);
		
		item=obj.getValue("label");
		if(item instanceof JSONString==false){
			return null;
		}
		byte[] label=Hex.decode(((JSONString)item).getString());
		
		return new RSAESOAEPParams(hashAlgo.getOid(),mgf1HashAlgo.getOid(),label);
		
	}
	
	private static RSASSAPSSParams getPssParam(JSONObject obj) throws Exception {
		JSON item=obj.getValue("hashAlgorithm");
		String oid;
		if(item instanceof JSONString==false){
			return null;
		}
		oid=((JSONString)item).getString();
		AlgorithmIdentifier hashAlgo=createHashAlgorithm(oid);
		
		item=obj.getValue("mgf1HashAlgorithm");
		if(item instanceof JSONString==false){
			return null;
		}
		oid=((JSONString)item).getString();
		AlgorithmIdentifier mgf1HashAlgo=createHashAlgorithm(oid);
		
		item=obj.getValue("saltLength");
		if(item instanceof JSONNumber==false){
			return null;
		}
		int saltLen=((JSONNumber)item).getNumber().intValue();
		
		return new RSASSAPSSParams(hashAlgo.getOid(),mgf1HashAlgo.getOid(),saltLen);
		
	}
	
	private static String getPublicKeyAlgoOid(String name) {
		if(name.equalsIgnoreCase("RSA")) {
			return AlgorithmIdentifier.RSAEncrypt_OID;
		} else if(name.equalsIgnoreCase("DSA")) {
			return AlgorithmIdentifier.DSA_OID;
		} else if(name.equalsIgnoreCase("EC") || name.equalsIgnoreCase("ECC")) {
			return AlgorithmIdentifier.ECPubKey_OID;
		} else if(name.equalsIgnoreCase("RSA OAEP") || name.equalsIgnoreCase("OAEP")) {
			return AlgorithmIdentifier.RSAES_OAEP_OID;
		} else if(name.equalsIgnoreCase("RSA PSS") || name.equalsIgnoreCase("PSS")) {
			return AlgorithmIdentifier.RSASSA_PSS_OID;
		} else if(name.equalsIgnoreCase("ECDH")) {
			return AlgorithmIdentifier.ECDH_OID;
		} else if(name.equalsIgnoreCase("ECMQV")) {
			return AlgorithmIdentifier.ECMQV_OID;
		} else {
			return name;
		}
	}
	
	private static int getVerison(JSONObject templete)throws Exception {
		JSON item=templete.getValue("verison");
		if(item==null) {
			return X509Certificate.V3;
		}
		if(item instanceof JSONString==false) {
			throw new Exception("证书版本号项不是JSON字符串");
		}
		String version=((JSONString)item).getString();
		if(version.equalsIgnoreCase("V1")) {
			return X509Certificate.V1;
		} else if(version.equalsIgnoreCase("V2")) {
			return X509Certificate.V2;
		} else if(version.equalsIgnoreCase("V3")) {
			return X509Certificate.V3;
		} else {
			throw new Exception("不支持的证书版本号");
		}
	}
	
	private static AlgorithmIdentifier getSignAlgo(JSONObject templete,KeyPair keypair)throws Exception {
		JSON item=templete.getValue("signatureAlgorithm");
		if(item==null) {
			return getDefaultSignAlgo(keypair);
		}
		
		if(item instanceof JSONObject==false) {
			throw new Exception("签名算法项模板错误");
		}
		
		JSONObject algoObject=(JSONObject)item;
		
		item=algoObject.getValue("algorithm");
		if(item instanceof JSONString==false) {
			throw new Exception("签名算法OID项不是JSON字符串");
		}
		String algo=((JSONString)item).getString();
		algo=getSignatureAlgorithmOid(algo);
		
		item=algoObject.getValue("parameters");
		if(item==null) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(algo);
		}
		if (item instanceof JSONNull) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(algo);
		} else if(item instanceof JSONString) {
			String hexValue=((JSONString)item).getString();
			byte[] value=Hex.decode(hexValue);
			ASN1Object paramValue=ASN1Object.decode(value, AnyType.getInstance());
			return new AlgorithmIdentifier(algo,paramValue);
		}
		
		if(algo.equals(AlgorithmIdentifier.RSASSA_PSS_OID)) {
			if(item instanceof JSONObject==false){
				throw new Exception("RSA PSS签名算法参数类型错误");
			}
			RSASSAPSSParams pss=getPssParam((JSONObject)item);
			if(pss==null) {
				throw new Exception("RSA PSS签名算法参数错误");
			}
			return new AlgorithmIdentifier(algo,pss.getASN1Object());
		}
		
		throw new Exception("未知签名算法参数");
	}
	
	private static String getSignatureAlgorithmOid(String value) {
		if (value.equalsIgnoreCase("SHA1WithRSA") || value.equalsIgnoreCase("SHA-1WithRSA")) {
			return AlgorithmIdentifier.SHA1WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA224WithRSA")) {
			return AlgorithmIdentifier.SHA224WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA256WithRSA")) {
			return AlgorithmIdentifier.SHA256WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA384WithRSA")) {
			return AlgorithmIdentifier.SHA384WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA512WithRSA")) {
			return AlgorithmIdentifier.SHA512WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA512/224WithRSA")) {
			return AlgorithmIdentifier.SHA512_224WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA512/256WithRSA")) {
			return AlgorithmIdentifier.SHA512_256WithRSA_OID;
		} else if (value.equalsIgnoreCase("DSAWithSHA1")) {
			return AlgorithmIdentifier.DSAWithSHA1_OID;
		} else if (value.equalsIgnoreCase("DSAWithSHA224")) {
			return AlgorithmIdentifier.DSAWithSHA224_OID;
		} else if (value.equalsIgnoreCase("DSAWithSHA256")) {
			return AlgorithmIdentifier.DSAWithSHA256_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA1")) {
			return AlgorithmIdentifier.ECDSAWithSHA1_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA224")) {
			return AlgorithmIdentifier.ECDSAWithSHA224_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA256")) {
			return AlgorithmIdentifier.ECDSAWithSHA256_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA384")) {
			return AlgorithmIdentifier.ECDSAWithSHA384_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA512")) {
			return AlgorithmIdentifier.ECDSAWithSHA512_OID;
		} else if (value.equalsIgnoreCase("SM3WithSM2")) {
			return AlgorithmIdentifier.SM3WithSM2_OID;
		} else if (value.equalsIgnoreCase("PSS") || value.equalsIgnoreCase("RSA PSS")) {
			return AlgorithmIdentifier.RSASSA_PSS_OID;
		} else {
			return value;
		}
	}
	
	private static AlgorithmIdentifier getDefaultSignAlgo(KeyPair keypair)throws Exception {
		int algo=keypair.getAlgorithm();
		if(algo==KeyPair.RSA) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
		} else if(algo==KeyPair.DSA) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.DSAWithSHA1_OID);
		} else if(algo==KeyPair.ECC) {
			int curve=keypair.getECCCurve();
			if(curve==Device.ECC_CURVE_P256) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
			} else if(curve==Device.ECC_CURVE_P384) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA384_OID);
			} else if(curve==Device.ECC_CURVE_P521) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA512_OID);
			} else if(curve==Device.ECC_CURVE_SM2) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
			} 
		}
		
		throw new Exception("get default sign algo fail");
	}
	
	
	private static byte[] getSerialNumber(JSONObject templete)throws Exception {
		JSON item=templete.getValue("serialNumber");
		if(item==null) {
			return getDefaultSerialNumber();
		}
		
		if(item instanceof JSONString==false) {
			throw new Exception("序列号项不是JSON字符串");
		}
		String hexValue=((JSONString)item).getString();
		if(hexValue.equalsIgnoreCase("random")) {
			return getDefaultSerialNumber();
		}
		byte[] value=Hex.decode(hexValue);
		return value;
	}
	
	private static byte[] getDefaultSerialNumber()throws Exception {
		Device device=Device.getPseudoDevice();
		if(device==null) {
			throw new Exception("获取内置软件设备失败");
		}
		byte[] rand=device.generateRandom(20);
		try {
			rand[0]&=0x7F;
			return rand;
		}finally {
			device.free();
		}
	}
	
	private static void setValidity(X509CertificateBuilder builder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("validity");
		if(item==null) {
			setValidity(builder,1);
			return ;
		}
		if (item instanceof JSONNumber) {
			int year=((JSONNumber)item).getNumber().intValue();
			setValidity(builder,year);
			return;
		}
		if(item instanceof JSONArray==false) {
			throw new Exception("有效期不是JSON数组");
		}
		JSONArray validity=(JSONArray)item;
		if(validity.size()!=2) {
			throw new Exception("有效期的项数不对");
		}
		item=validity.get(0);
		if(item instanceof JSONString==false) {
			throw new Exception("有效期开始时间项不是JSON字符串");
		}
		String notBefore=((JSONString)item).getString();
		builder.setNotBefore(Util.UTCTimeDecode(notBefore.getBytes("UTF-8")));
		
		item=validity.get(1);
		if(item instanceof JSONString==false) {
			throw new Exception("有效期结束时间项不是JSON字符串");
		}
		String notAfter=((JSONString)item).getString();
		builder.setNotAfter(Util.UTCTimeDecode(notAfter.getBytes("UTF-8")));
	}
	
	private static void setValidity(X509CertificateBuilder builder,int year)throws Exception {
		Date notBefore=new Date();
		Calendar cal = Calendar.getInstance();
		cal.setTime(notBefore);
		builder.setNotBefore(notBefore);
		cal.add(Calendar.YEAR, year);
		builder.setNotAfter(cal.getTime());
	}
	
	private static void setIssuerUniqueID(X509CertificateBuilder builder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("issuerUniqueID");
		if(item==null) {
			return ;
		}
		
		if(item instanceof JSONArray==false) {
			throw new Exception("颁发者唯一ID项不是JSON数组");
		}
		JSONArray id=(JSONArray)item;
		if(id.size()!=2) {
			throw new Exception("颁发者唯一ID的项数不对");
		}
		
		item=id.get(0);
		if(item instanceof JSONNumber==false) {
			throw new Exception("颁发者唯一ID格式错误");
		}
		int unusedBits=((JSONNumber)item).getNumber().intValue();
		
		item=id.get(1);
		if(item instanceof JSONString==false) {
			throw new Exception("颁发者唯一ID格式错误");
		}
		String hexValue=((JSONString)item).getString();
		byte[] value=Hex.decode(hexValue);
		BitString issuerId=new BitString(unusedBits,value);
		builder.setIssuerUniqueID(issuerId);
	}
	
	private static void setSubjectUniqueID(X509CertificateBuilder builder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("subjectUniqueID");
		if(item==null) {
			return ;
		}
		
		if(item instanceof JSONArray==false) {
			throw new Exception("主体唯一ID项不是JSON数组");
		}
		JSONArray id=(JSONArray)item;
		if(id.size()!=2) {
			throw new Exception("主体唯一ID的项数不对");
		}
		
		item=id.get(0);
		if(item instanceof JSONNumber==false) {
			throw new Exception("主体唯一ID格式错误");
		}
		int unusedBits=((JSONNumber)item).getNumber().intValue();
		
		item=id.get(1);
		if(item instanceof JSONString==false) {
			throw new Exception("主体唯一ID格式错误");
		}
		String hexValue=((JSONString)item).getString();
		byte[] value=Hex.decode(hexValue);
		BitString subjectId=new BitString(unusedBits,value);
		builder.setSubjectUniqueID(subjectId);
	}
	
	private static Extensions createExtensions(JSONObject templete,SubjectPublicKeyInfo publicKey,X509Certificate issuerCert)throws Exception {
		JSON item=templete.getValue("extensions");
		if(item==null) {
			return null;
		}
		if(item instanceof JSONArray==false) {
			throw new Exception("扩展项不是JSON数组");
		}
		JSONArray extsArray=(JSONArray)item;
		int count=extsArray.size();
		Extension ext;
		Extensions exts=new Extensions();		
		for(int i=0;i<count;i++) {
			item=extsArray.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("扩展项不是JSON对象");
			}
			ext=createExtension((JSONObject)item,publicKey,issuerCert);
			exts.add(ext);
		}
				
		return exts;
	}
	
	private static Extension createExtension(JSONObject extObj,SubjectPublicKeyInfo publicKey,X509Certificate issuerCert)throws Exception {
		JSON item=extObj.getValue("extnID");
		if(item instanceof JSONString==false) {
			throw new Exception("扩展OID项不是JSON字符串");
		}
		String extOid=((JSONString)item).getString();
		extOid=getExtensionOid(extOid);
		
		boolean critical;
		item=extObj.getValue("critical");
		if(item==null) {
			critical=false;
		} else if(item instanceof JSONBoolean==false) {
			throw new Exception("扩展关键性项不是JSON布尔值");
		} else {
			critical=((JSONBoolean)item).isTrue();
		}
		item=extObj.getValue("extnValue");
		
		if(extOid.equals(Extension.AUTHORITY_KEYIDENTIFIER_OID)) {
			return createAuthorityKeyIdentifier(critical,item,issuerCert);
		} else if(extOid.equals(Extension.SUBJECT_KEYIDENTIFIER_OID)) {
			return createSubjectKeyIdentifier(critical,item,publicKey);
		} else if(extOid.equals(Extension.KEYUSAGE_OID)) {
			return createKeyUsage(critical,item);
		} else if(extOid.equals(Extension.POLICYMAPPINGS_OID)) {
			return createPolicyMappings(critical,item);
		} else if(extOid.equals(Extension.BASIC_CONSTRAINTS_OID)) {
			return createBasicConstraints(critical,item);
		} else if(extOid.equals(Extension.CERTPOLICIES_OID)) {
			return createCertificatePolicies(critical,item);
		} else if(extOid.equals(Extension.SUBJECT_ALTNAME_OID)) {
			return createSubjectAlternativeName(critical,item);
		} else if(extOid.equals(Extension.ISSUER_ALTNAME_OID)) {
			return createIssuerAlternativeName(critical,item);
		} else if(extOid.equals(Extension.NAME_CONSTRAINTS_OID)) {
			return createNameConstraints(critical,item);
		} else if(extOid.equals(Extension.POLICY_CONSTRAINTS_OID)) {
			return createPolicyConstraints(critical,item);
		} else if(extOid.equals(Extension.EXTKEYUSAGE_OID)) {
			return createExtendedKeyUsage(critical,item);
		} else if(extOid.equals(Extension.CRLDISTRIBUTIONPOINTS_OID)) {
			return createCRLDistributionPoints(critical,item);
		} else if(extOid.equals(Extension.FRESHESTCRL_OID)) {
			return createFreshestCRL(critical,item);
		} else if(extOid.equals(Extension.INHIBIT_ANYPOLICY_OID)) {
			return createInhibitanyPolicy(critical,item);
		} else if(extOid.equals(Extension.AUTHORITYINFOACCESS_OID)) {
			return createAuthorityInfoAccess(critical,item);
		} else if(extOid.equals(Extension.SUBJECTINFOACCESS_OID)) {
			return createSubjectInfoAccess(critical,item);
		} else if(extOid.equals(Extension.OCSP_NOCHECK_OID)) {
			return createOCSPNoCheck(critical,item);
		} else if(extOid.equals(Extension.NETCA_USERCERTSERVICEID_OID)) {
			return createNetcaUserCertServiceId(critical,item);
		} else if(extOid.equals(Extension.NETCA_ENTERPRISEID_ITEMS_OID)) {
			return createNetcaEnterpriseIdItems(critical,item);
		} else if(extOid.equals(Extension.NETCA_IDENTIFY_ITEMS_OID)) {
			return createNetcaIdentifyItems(critical,item);
		} else if(extOid.equals(Extension.NETCA_PREV_CERT_THUMBPRINT_OID)) {
			return createNetcaNetcaCertThumbs(critical,item);
		} else {
			if(item instanceof JSONString) {
				return createDefaultExtension(extOid,critical,(JSONString)item);
			} else {
				throw new Exception("扩展项模板错误");
			}
			
		}
	}
	
	private static Extension createAuthorityKeyIdentifier(boolean critical,JSON akidValue,X509Certificate issuerCert)throws Exception {
		if(akidValue instanceof JSONString) {
			return createDefaultExtension(Extension.AUTHORITY_KEYIDENTIFIER_OID,critical,(JSONString)akidValue);
		} else if(akidValue instanceof JSONArray==false) {
			throw new Exception("颁发者密钥标识符模板错误");
		}
		
		JSONArray akidArray=(JSONArray)akidValue;
		int count=akidArray.size();
		if(count!=1 && count!=2) {
			throw new Exception("颁发者密钥标识符模板错误");
		}
				
		JSON item;
		boolean hasKeyIdentifier=false;
		boolean hasIssuer=false;
		item=akidArray.get(0);
		if(item instanceof JSONString==false) {
			throw new Exception("颁发者密钥标识符模板错误");
		}
		String value=((JSONString)item).getString();
		
		if(value.equalsIgnoreCase("keyIdentifier")) {
			hasKeyIdentifier=true;
		} else if(value.equalsIgnoreCase("authorityCertIssuer and authorityCertSerialNumber")) {
			hasIssuer=true;
		} else {
			throw new Exception("颁发者密钥标识符模板错误");
		}
		
		if(count==2){
			item=akidArray.get(1);
			if(item instanceof JSONString==false) {
				throw new Exception("颁发者密钥标识符模板错误");
			}
			value=((JSONString)item).getString();
			
			if(value.equalsIgnoreCase("keyIdentifier")) {
				hasKeyIdentifier=true;
			} else if(value.equalsIgnoreCase("authorityCertIssuer and authorityCertSerialNumber")) {
				hasIssuer=true;
			} else {
				throw new Exception("颁发者密钥标识符模板错误");
			}
			
			if(hasKeyIdentifier==false || hasIssuer==false) {
				throw new Exception("颁发者密钥标识符模板错误");
			}
		}
		
		byte[] keyIdentifier;
		if(hasKeyIdentifier) {
			Extensions exts=issuerCert.getExtensions();
			if(exts==null) {
				throw new Exception("颁发者证书没有扩展");
			}
			Extension ext=exts.get(Extension.SUBJECT_KEYIDENTIFIER_OID);
			if(ext==null) {
				throw new Exception("颁发者证书没有主体密钥标识符扩展");
			}

			keyIdentifier= ((OctetStringExtension)(ext.getExtensionObject())).getValue();
		} else {
			keyIdentifier=null;
		}
		
		GeneralNames authorityCertIssuer;
		byte[] authorityCertSerialNumber;
		
		if(hasIssuer) {
			GeneralName gn=GeneralName.NewDirectoryName(issuerCert.getIssuer());
			authorityCertIssuer=new GeneralNames();
			authorityCertIssuer.add(gn);
			authorityCertSerialNumber=issuerCert.getSerialNumber();
			
		} else {
			authorityCertIssuer=null;
			authorityCertSerialNumber=null;
		}
		
		AuthorityKeyIdentifierExtension akidExt=new AuthorityKeyIdentifierExtension(keyIdentifier,
				authorityCertIssuer,authorityCertSerialNumber);
		
		return new Extension(Extension.AUTHORITY_KEYIDENTIFIER_OID,critical,akidExt);
	}
	
	private static Extension createDefaultExtension(String extOid,boolean critical,JSONString extValue) throws Exception {
		Extension ext;
		String hexValue=((JSONString)extValue).getString();
		byte[] value=Hex.decode(hexValue);
		
		ext=new Extension(extOid,critical,value);
		return ext;
	}
	
	private static byte[] calcKeyId(int hashAlgo,SubjectPublicKeyInfo pubkey,int type) throws Exception {
		byte[] blob=pubkey.getSubjectPublicKey().getValue();
		byte[] hashValue=Hash.computeHash(hashAlgo, blob);
		
		if(type==2) {
			byte[] id=new byte[8];
			System.arraycopy(hashValue, hashValue.length-8, id,0, 8);
			id[0]&=0xF;
			id[0]|=0x40;
			return id;
		} else {
			return hashValue;
		}
	}
	
	private static Extension createSubjectKeyIdentifier(boolean critical,JSON skidValue,SubjectPublicKeyInfo publicKey)throws Exception {
		byte[] keyIdentifier;
		if(skidValue instanceof JSONString) {
			String value=((JSONString)skidValue).getString();
			if(value.equals("1")) {
				keyIdentifier=calcKeyId(Hash.SHA1,publicKey,1);
			} else if(value.equals("2")) {
				keyIdentifier=calcKeyId(Hash.SHA1,publicKey,2);
			} else {
				return createDefaultExtension(Extension.SUBJECT_KEYIDENTIFIER_OID,critical,(JSONString)skidValue);
			}
			
		} else {
			throw new Exception("主体密钥标识符模板错误");
		}
		
		OctetStringExtension subjKeyId=new OctetStringExtension(keyIdentifier);
		
		return new Extension(Extension.SUBJECT_KEYIDENTIFIER_OID,critical,subjKeyId);
	}
	
	private static Extension createKeyUsage(boolean critical,JSON kuValue)throws Exception {
		if(kuValue instanceof JSONString) {
			return createDefaultExtension(Extension.KEYUSAGE_OID,critical,(JSONString)kuValue);
		} else if(kuValue instanceof JSONArray==false) {
			throw new Exception("密钥用法模板错误");
		}
		
		JSONArray kuArray=(JSONArray)kuValue;
		int count=kuArray.size();
		
		JSON item;
		boolean[] bits=new boolean[count];
		for(int i=0;i<count;i++) {
			item=kuArray.get(i);
			if (item instanceof JSONBoolean==false) {
				throw new Exception("密钥用法模板错误");
			} 
			bits[i]=((JSONBoolean)item).isTrue();
		}
		
		NamedBitStringExtension ku=new NamedBitStringExtension(bits);
		return new Extension(Extension.KEYUSAGE_OID,critical,ku);
	}
	
	private static Extension createPolicyMappings(boolean critical,JSON policyMappingsValue)throws Exception {
		if(policyMappingsValue instanceof JSONString) {
			return createDefaultExtension(Extension.POLICYMAPPINGS_OID,critical,(JSONString)policyMappingsValue);
		} else if(policyMappingsValue instanceof JSONArray==false) {
			throw new Exception("策略映射模板错误");
		}
		
		JSONArray policyMappingsArray=(JSONArray)policyMappingsValue;
		int count=policyMappingsArray.size();
		PolicyMappingsExtension policyMappingsExt=new PolicyMappingsExtension();
		JSON item;
		PolicyMapping policyMapping;
		for(int i=0;i<count;i++) {
			item=policyMappingsArray.get(i);
			if (item instanceof JSONArray==false) {
				throw new Exception("策略映射模板错误");
			} 
			policyMapping=createPolicyMapping((JSONArray)item);
			policyMappingsExt.add(policyMapping);
		}
		
		return new Extension(Extension.POLICYMAPPINGS_OID,critical,policyMappingsExt);
	}
	
	private static PolicyMapping createPolicyMapping(JSONArray policyMappingArray)throws Exception {
		int count=policyMappingArray.size();
		if(count!=2) {
			throw new Exception("策略映射模板错误");
		}
		
		JSON item;
		item=policyMappingArray.get(0);
		if (item instanceof JSONString==false) {
			throw new Exception("策略映射模板错误");
		} 
		String issuerDomainPolicy=((JSONString)item).getString();
		
		item=policyMappingArray.get(1);
		if (item instanceof JSONString==false) {
			throw new Exception("策略映射模板错误");
		} 
		String subjectDomainPolicy=((JSONString)item).getString();
		
		return new PolicyMapping(issuerDomainPolicy,subjectDomainPolicy);
	}
	
	private static Extension createBasicConstraints(boolean critical,JSON bcValue)throws Exception {
		if(bcValue instanceof JSONString) {
			return createDefaultExtension(Extension.AUTHORITY_KEYIDENTIFIER_OID,critical,(JSONString)bcValue);
		} else if(bcValue instanceof JSONObject==false) {
			throw new Exception("基本限制模板错误");
		}
		
		JSONObject bcObject=(JSONObject)bcValue;
		JSON item=bcObject.getValue("cA");
		if (item instanceof JSONBoolean==false) {
			throw new Exception("基本限制模板错误");
		} 
		boolean isCa=((JSONBoolean)item).isTrue();
		BasicConstraintsExtension bc;
		
		if(isCa==false) {
			bc=new BasicConstraintsExtension(isCa,-1);
		} else {
			item=bcObject.getValue("pathLenConstraint");
			if(item==null) {
				bc=new BasicConstraintsExtension(isCa,-1);
			} else if (item instanceof JSONNumber==false) {
				throw new Exception("基本限制模板错误");
			} else {
				int path=((JSONNumber)item).getNumber().intValue();
				bc=new BasicConstraintsExtension(isCa,path);
			}
		}
	
		return new Extension(Extension.BASIC_CONSTRAINTS_OID,critical,bc);
	}
	
	private static Extension createCertificatePolicies(boolean critical,JSON cpsValue)throws Exception {
		if(cpsValue instanceof JSONString) {
			return createDefaultExtension(Extension.CERTPOLICIES_OID,critical,(JSONString)cpsValue);
		} else if(cpsValue instanceof JSONArray==false) {
			throw new Exception("证书策略模板错误");
		}
		
		JSONArray cpsArray=(JSONArray)cpsValue;
		int count=cpsArray.size();
		CertificatePolicies cps=new CertificatePolicies();
		JSON item;
		PolicyInformation policyInfo;
		for(int i=0;i<count;i++) {
			item=cpsArray.get(i);
			if (item instanceof JSONArray==false) {
				throw new Exception("证书策略模板错误");
			} 
			policyInfo=createPolicyInformation((JSONArray)item);
			cps.add(policyInfo);
		}
		return new Extension(Extension.CERTPOLICIES_OID,critical,cps.getASN1Object().encode());
	}
	
	private static PolicyInformation createPolicyInformation(JSONArray policyInfoArray)throws Exception {
		int count=policyInfoArray.size();
		if(count!=1 && count!=2) {
			throw new Exception("证书策略模板错误");
		}
		
		JSON item;
		item=policyInfoArray.get(0);
		if (item instanceof JSONString==false) {
			throw new Exception("证书策略模板错误");
		} 
		String policyIdentifier=((JSONString)item).getString();
		
		if(count==1) {
			return new PolicyInformation(policyIdentifier,null);
		}
		item=policyInfoArray.get(1);
		if (item instanceof JSONArray==false) {
			throw new Exception("证书策略模板错误");
		} 
		PolicyQualifiers policyQualifiers=new PolicyQualifiers();
		JSONArray policyQualifiersArray=(JSONArray) item;
		count=policyQualifiersArray.size();
		PolicyQualifierInfo pqInfo;
		for(int i=0;i<count;i++) {
			item=policyQualifiersArray.get(i);
			if (item instanceof JSONArray==false) {
				throw new Exception("证书策略模板错误");
			}
			pqInfo=createPolicyQualifierInfo((JSONArray)item);
			policyQualifiers.add(pqInfo);
		}
				
		
		return new PolicyInformation(policyIdentifier,policyQualifiers);
	}
	
	private static PolicyQualifierInfo createPolicyQualifierInfo(JSONArray policyQualifierInfoArray)throws Exception {
		int count=policyQualifierInfoArray.size();
		if(count!=2) {
			throw new Exception("证书策略模板错误");
		}
		
		JSON item;
		item=policyQualifierInfoArray.get(0);
		if (item instanceof JSONString==false) {
			throw new Exception("证书策略模板错误");
		} 
		String policyQualifierId=((JSONString)item).getString();
		policyQualifierId=getPolicyQualifierOid(policyQualifierId);
		
		item=policyQualifierInfoArray.get(1);
		
		if(policyQualifierId.equals(PolicyQualifierInfo.CPS_OID)) {
			if (item instanceof JSONString==false) {
				throw new Exception("证书策略模板错误");
			} 
			return PolicyQualifierInfo.CreateCPS(((JSONString)item).getString());
		} else if (policyQualifierId.equals(PolicyQualifierInfo.UNOTICE_OID)) {
			if (item instanceof JSONObject==false) {
				throw new Exception("证书策略模板错误");
			} 
			UserNotice userNotice=createUserNotice((JSONObject)item);
			return PolicyQualifierInfo.CreateUserNotice(userNotice);
		} else {
			if (item instanceof JSONString==false) {
				throw new Exception("证书策略模板错误");
			} 
			String hexValue=((JSONString)item).getString();
			byte[] value=Hex.decode(hexValue);
			return new PolicyQualifierInfo(policyQualifierId,ASN1Object.decode(value, AnyType.getInstance()));
		}
	}
	
	private static String getPolicyQualifierOid(String name) {
		if(name.equalsIgnoreCase("cps")) {
			return PolicyQualifierInfo.CPS_OID;
		} else if(name.equalsIgnoreCase("userNotice")) {
			return PolicyQualifierInfo.UNOTICE_OID;
		} else {
			return name;
		}
	}
	
	private static UserNotice createUserNotice(JSONObject userNoticeObject)throws Exception {
		JSON item;
		item=userNoticeObject.getValue("noticeRef");
		
		NoticeReference noticeRef;
		DisplayText explicitText;
		if (item==null) {
			noticeRef=null;
		} else if (item instanceof JSONObject) {
			noticeRef=createNoticeReference((JSONArray)item);
		} else {
			throw new Exception("证书策略模板错误");
		}
		
		item=userNoticeObject.getValue("explicitText");
		if (item ==null) {
			explicitText=null;
		} else if (item instanceof JSONObject) {
			explicitText=createDisplayText((JSONObject)item);
		} else {
			throw new Exception("证书策略模板错误");
		}
		
		return new UserNotice(noticeRef,explicitText);
	}
	
	private static NoticeReference createNoticeReference(JSONArray noticeReferenceArray)throws Exception {
		int count=noticeReferenceArray.size();
		if(count!=2){
			throw new Exception("证书策略模板错误");
		}
		JSON item;
		item=noticeReferenceArray.get(0);
		if (item instanceof JSONObject==false) {
			throw new Exception("证书策略模板错误");
		}
		DisplayText organization=createDisplayText((JSONObject)item);
		item=noticeReferenceArray.get(1);
		if (item instanceof JSONArray==false) {
			throw new Exception("证书策略模板错误");
		}
		JSONArray noticeNumbersArray=(JSONArray)item;
		count=noticeNumbersArray.size();
		int []noticeNumbers=new int[count];
		for(int i=0;i<count;i++){
			item=noticeNumbersArray.get(i);
			if (item instanceof JSONNumber==false) {
				throw new Exception("证书策略模板错误");
			}
			noticeNumbers[i]=((JSONNumber)item).getNumber().intValue();
		}
		return new NoticeReference(organization,noticeNumbers);
	}
	
	private static DisplayText createDisplayText(JSONObject displayTextObject)throws Exception {
		JSON item;
		item=displayTextObject.getValue("type");
		if (item instanceof JSONString==false) {
			throw new Exception("DisplayText模板错误");
		}
		String type=((JSONString)item).getString();
		item=displayTextObject.getValue("value");
		if (item instanceof JSONString==false) {
			throw new Exception("DisplayText模板错误");
		}
		String value=((JSONString)item).getString();
		if(type.equalsIgnoreCase("BMPString")) {
			return DisplayText.NewBMPString(value);
		} else if(type.equalsIgnoreCase("IA5String")) {
			return DisplayText.NewIA5String(value);
		} else if(type.equalsIgnoreCase("UTF8String")) {
			return DisplayText.NewUTF8String(value);
		} else if(type.equalsIgnoreCase("VisibleString")) {
			return DisplayText.NewVisibleString(value);
		} else {
			throw new Exception("DisplayText模板错误");
		}
		
		
	}
	private static Extension createSubjectAlternativeName(boolean critical,JSON gnsValue)throws Exception {
		return createGeneralNames(critical,gnsValue,Extension.SUBJECT_ALTNAME_OID,"主体备用名扩展模板");		
	}
	
	private static Extension createIssuerAlternativeName(boolean critical,JSON gnsValue)throws Exception {
		return createGeneralNames(critical,gnsValue,Extension.ISSUER_ALTNAME_OID,"颁发者备用名扩展模板");		
	}
	
	private static Extension createGeneralNames(boolean critical,JSON gnsValue,String extOid,String extName)throws Exception {
		if(gnsValue instanceof JSONString) {
			return createDefaultExtension(extOid,critical,(JSONString)gnsValue);
		} else if(gnsValue instanceof JSONArray==false) {
			throw new Exception(extName + "错误");
		}
		
		JSONArray gnsArray=(JSONArray)gnsValue;
		
		GeneralNames gns=createGeneralNames(gnsArray,extName);
		return new Extension(extOid,critical,gns.getASN1Object().encode());
	}
	private static GeneralNames createGeneralNames(JSONArray gnsArray,String extName)throws Exception {
		int count=gnsArray.size();
		GeneralNames gns=new GeneralNames();
		JSON item;
		GeneralName gn;
		for(int i=0;i<count;i++) {
			item=gnsArray.get(i);
			if (item instanceof JSONObject==false) {
				throw new Exception(extName + "错误");
			} 
			gn=createGeneralName((JSONObject)item,extName);
			gns.add(gn);
		}
		return gns;
	}
	private static GeneralName createGeneralName(JSONObject gnObject,String extName)throws Exception {
		JSON item;
		item=gnObject.getValue("type");
		if (item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		}
		String type=((JSONString)item).getString();
		item=gnObject.getValue("value");
		
		if(type.equalsIgnoreCase("otherName")) {
			if (item instanceof JSONObject==false) {
				throw new Exception(extName + "错误");
			}
			OtherName otherName=createOtherName((JSONObject)item,extName);
			return GeneralName.NewOtherName(otherName);
		} else if (type.equalsIgnoreCase("rfc822Name")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewRFC822Name(value);
		} else if (type.equalsIgnoreCase("dNSName")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewDNSName(value);
		} else if (type.equalsIgnoreCase("directoryName")) {
			X500Name x500Name=createDN(item);
			return GeneralName.NewDirectoryName(x500Name);
		}else if (type.equalsIgnoreCase("uniformResourceIdentifier")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewURI(value);
		} else if (type.equalsIgnoreCase("iPAddress")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String hexValue=((JSONString)item).getString();
			byte[] value=Hex.decode(hexValue);
			return GeneralName.NewIPAddress(value);
			
		} else if (type.equalsIgnoreCase("registeredID")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewRegisteredID(value);
		} else {
			throw new Exception(extName + "错误");
		}
	}
	
	private static OtherName createOtherName(JSONObject otherNameObject,String extName)throws Exception {
		JSON item;
		item=otherNameObject.getValue("type-id");
		if (item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		}
		String type=((JSONString)item).getString();
		type=getOtherNameTypeOid(type);
		item=otherNameObject.getValue("value");;
		
		if(type.equals(OtherName.UPN_OID)) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return new OtherName(type,new UTF8String(value)); 
		} else {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String hexValue=((JSONString)item).getString();
			byte[] value=Hex.decode(hexValue);
			return new OtherName(type,ASN1Object.decode(value,AnyType.getInstance())); 
		}
	}
	
	private static String getOtherNameTypeOid(String name) {
		if(name.equalsIgnoreCase("upn")) {
			return OtherName.UPN_OID;
		} else {
			return name;
		}
	}
	
	private static Extension createNameConstraints(boolean critical,JSON ncsValue)throws Exception {
		if(ncsValue instanceof JSONString) {
			return createDefaultExtension(Extension.NAME_CONSTRAINTS_OID,critical,(JSONString)ncsValue);
		} else if(ncsValue instanceof JSONObject==false) {
			throw new Exception("名字约束扩展模板错误");
		}
		
		JSONObject ncsObject=(JSONObject)ncsValue;
		GeneralSubtrees permittedSubtrees;
		GeneralSubtrees excludedSubtrees;
		JSON item;
		item=ncsObject.getValue("permittedSubtrees");
		permittedSubtrees=createGeneralSubtrees(item);
		item=ncsObject.getValue("excludedSubtrees");
		excludedSubtrees=createGeneralSubtrees(item);
		return new Extension(Extension.NAME_CONSTRAINTS_OID,critical,new NameConstraintsExtension(permittedSubtrees,excludedSubtrees));
	}
	private static GeneralSubtrees createGeneralSubtrees(JSON gsValue)throws Exception {
		if(gsValue==null) {
			return null;
		} else if(gsValue instanceof JSONArray==false) {
			throw new Exception("名字约束扩展模板错误");
		}
		
		JSONArray gsArray=(JSONArray)gsValue;
		int count=gsArray.size();
		
		GeneralSubtree subtree;
		GeneralSubtrees subtrees=new GeneralSubtrees();
		JSON item;
		for(int i=0;i<count;i++) {
			item=gsArray.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("名字约束扩展模板错误");
			}
			subtree=createGeneralSubtree((JSONObject)item);
			subtrees.add(subtree);
		}
		
		return subtrees;
	}
	private static GeneralSubtree createGeneralSubtree(JSONObject subtreeObject)throws Exception {
		
		JSON item=subtreeObject.getValue("base");
		if(item instanceof JSONObject==false) {
			throw new Exception("名字约束扩展模板错误");
		}
		GeneralName base=createGeneralName((JSONObject)item,"名字约束扩展模板");
		
		item=subtreeObject.getValue("minimum");
		int min;
		if(item==null) {
			min=0;
		} else if(item instanceof JSONNumber==false) {
			throw new Exception("名字约束扩展模板错误");
		} else {
			min=((JSONNumber)item).getNumber().intValue();
		}
		
		item=subtreeObject.getValue("maximum");
		int max;
		if(item==null) {
			max=0;
		} else if(item instanceof JSONNumber==false) {
			throw new Exception("名字约束扩展模板错误");
		} else {
			max=((JSONNumber)item).getNumber().intValue();
		}
		return new GeneralSubtree(base,min,max);
	}
	
	private static Extension createPolicyConstraints(boolean critical,JSON pcValue)throws Exception {
		if(pcValue instanceof JSONString) {
			return createDefaultExtension(Extension.POLICY_CONSTRAINTS_OID,critical,(JSONString)pcValue);
		} else if(pcValue instanceof JSONObject==false) {
			throw new Exception("策略约束扩展错误");
		}
		
		JSONObject pcObject=(JSONObject)pcValue;
		int requireExplicitPolicy;
		int inhibitPolicyMapping;
		JSON item=pcObject.getValue("requireExplicitPolicy");
		if(item==null){
			requireExplicitPolicy=-1;
		} else if(item instanceof JSONNumber==false) {
			throw new Exception("策略约束扩展错误");
		} else {
			requireExplicitPolicy=((JSONNumber)item).getNumber().intValue();
		}
		
		item=pcObject.getValue("inhibitPolicyMapping");
		if(item==null){
			inhibitPolicyMapping=-1;
		} else if(item instanceof JSONNumber==false) {
			throw new Exception("策略约束扩展错误");
		} else {
			inhibitPolicyMapping=((JSONNumber)item).getNumber().intValue();
		}
		PolicyConstraintsExtension pcExt=new PolicyConstraintsExtension(requireExplicitPolicy,inhibitPolicyMapping);
		
		return new Extension(Extension.POLICY_CONSTRAINTS_OID,critical,pcExt);
	}
	
	private static Extension createExtendedKeyUsage(boolean critical,JSON extKuValue)throws Exception {
		if(extKuValue instanceof JSONString) {
			return createDefaultExtension(Extension.EXTKEYUSAGE_OID,critical,(JSONString)extKuValue);
		} else if(extKuValue instanceof JSONArray==false) {
			throw new Exception("扩展密钥用法模板错误");
		}
		
		JSONArray extKuArray=(JSONArray)extKuValue;
		int count=extKuArray.size();
		ExtKeyUsageExtension extKuExt=new ExtKeyUsageExtension();
		JSON item;
		String oid;
		for(int i=0;i<count;i++) {
			item=extKuArray.get(i);
			if(item instanceof JSONString==false) {
				throw new Exception("扩展密钥用法模板错误");
			}
			oid=((JSONString)item).getString();
			extKuExt.add(oid);
		}
		
		return new Extension(Extension.EXTKEYUSAGE_OID,critical,extKuExt);
	}
	
	private static Extension createCRLDistributionPoints(boolean critical,JSON crldpsValue)throws Exception {
		return  createCRLDistributionPoints(critical,crldpsValue,Extension.CRLDISTRIBUTIONPOINTS_OID,"CRL发布点扩展模板");
	}
	
	private static Extension createFreshestCRL(boolean critical,JSON crldpsValue)throws Exception {
		return  createCRLDistributionPoints(critical,crldpsValue,Extension.FRESHESTCRL_OID,"Freshest CRL扩展模板");
	}
	
	private static Extension createCRLDistributionPoints(boolean critical,JSON crldpsValue,String extOid,String extName)throws Exception {
		if(crldpsValue instanceof JSONString) {
			return createDefaultExtension(extOid,critical,(JSONString)crldpsValue);
		} else if(crldpsValue instanceof JSONArray==false) {
			throw new Exception(extName + "错误");
		}
		
		JSONArray crldpsArray=(JSONArray)crldpsValue;
		int count=crldpsArray.size();
		CRLDistributionPointsExtension crldps=new CRLDistributionPointsExtension();
		JSON item;
		DistributionPoint dp;
		for(int i=0;i<count;i++) {
			item=crldpsArray.get(i);
			if (item instanceof JSONObject==false) {
				throw new Exception(extName + "错误");
			} 
			dp=createDistributionPoint((JSONObject)item,extName);
			crldps.add(dp);
		}
		return new Extension(extOid,critical,crldps);
	}
	
	private static DistributionPoint createDistributionPoint(JSONObject dpObject,String extName)throws Exception {
		DistributionPointName distributionPoint;
		BitString reasons;
		GeneralNames cRLIssuer;
		
		JSON item=dpObject.getValue("distributionPoint");
		if(item==null) {
			distributionPoint=null;
		} else if (item instanceof JSONObject==false) {
			throw new Exception(extName + "错误");
		} else {
			distributionPoint=createDistributionPointName((JSONObject)item,extName);
		}
		
		item=dpObject.getValue("reasons");
		if(item==null) {
			reasons=null;
		} else if (item instanceof JSONArray==false) {
			throw new Exception(extName + "错误");
		} else {
			JSONArray reasonsArray=(JSONArray)item;
			int count=reasonsArray.size();
			boolean[] bits=new boolean[count];
			for(int i=0;i<count;i++) {
				item=reasonsArray.get(i);
				if(item instanceof JSONBoolean==false) {
					throw new Exception(extName + "错误");
				}
				bits[i]=((JSONBoolean)item).isTrue();
			}
			reasons=new BitString(bits);
		}
		
		item=dpObject.getValue("cRLIssuer");
		if(item==null) {
			cRLIssuer=null;
		} else if (item instanceof JSONArray==false) {
			throw new Exception(extName + "错误");
		} else {
			cRLIssuer=createGeneralNames((JSONArray)item,extName);
		}
		
		return new DistributionPoint(distributionPoint,reasons,cRLIssuer);
	}
	
	private static DistributionPointName createDistributionPointName(JSONObject dpNameObject,String extName)throws Exception {
		JSON item=dpNameObject.getValue("type");
		
		if(item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		}
		String type=((JSONString)item).getString();
		
		if(type.equalsIgnoreCase("fullName")) {
			item=dpNameObject.getValue("value");
			if (item instanceof JSONArray==false) {
				throw new Exception(extName + "错误");
			}
			GeneralNames fullName=createGeneralNames((JSONArray)item,extName);
			return DistributionPointName.NewFullName(fullName);
		} else if(type.equalsIgnoreCase("nameRelativeToCRLIssuer")) {
			item=dpNameObject.getValue("value");
			if (item instanceof JSONArray==false) {
				throw new Exception(extName + "错误");
			}
			RelativeDistinguishedName  nameRelativeToCRLIssuer=createRDN((JSONArray)item);
			return DistributionPointName.NewNameRelativeToCRLIssuer(nameRelativeToCRLIssuer);
		} else {
			throw new Exception(extName + "错误");
		}
	}
	
	private static Extension createInhibitanyPolicy(boolean critical,JSON value)throws Exception {
		if(value instanceof JSONNumber==false) {
			throw new Exception("禁止anypolicy扩展模板错误");
		}
		
		IntegerExtension ext=new IntegerExtension(((JSONNumber)value).getNumber().toBigInteger());
		
		return new Extension(Extension.INHIBIT_ANYPOLICY_OID,critical,ext);
	}
	private static Extension createAuthorityInfoAccess(boolean critical,JSON aiaValue)throws Exception {
		return createAuthorityInfoAccess(critical,aiaValue,Extension.AUTHORITYINFOACCESS_OID,"颁发者信息访问扩展模板");
	}
	
	private static Extension createSubjectInfoAccess(boolean critical,JSON aiaValue)throws Exception {
		return createAuthorityInfoAccess(critical,aiaValue,Extension.SUBJECTINFOACCESS_OID,"主体信息访问扩展模板");
	}
	
	private static Extension createAuthorityInfoAccess(boolean critical,JSON aiaValue,String extOid,String extName)throws Exception {
		if(aiaValue instanceof JSONString) {
			return createDefaultExtension(extOid,critical,(JSONString)aiaValue);
		} else if(aiaValue instanceof JSONArray==false) {
			throw new Exception(extName + "错误");
		}
		
		JSONArray aiaArray=(JSONArray)aiaValue;
		int count=aiaArray.size();
		InfoAccessExtension aia=new InfoAccessExtension();
		JSON item;
		AccessDescription ad;
		for(int i=0;i<count;i++) {
			item=aiaArray.get(i);
			if (item instanceof JSONObject==false) {
				throw new Exception(extName + "错误");
			} 
			ad=createAccessDescription((JSONObject)item,extName);
			aia.add(ad);
		}
		return new Extension(extOid,critical,aia);
	}
	
	private static AccessDescription createAccessDescription(JSONObject adObject,String extName)throws Exception {
		String accessMethod;
		GeneralName accessLocation;
		
		JSON item=adObject.getValue("accessMethod");
		if (item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		} else {
			accessMethod=((JSONString)item).getString();
			accessMethod=getAccessMethodOid(accessMethod);
		}
		
		item=adObject.getValue("accessLocation");
		if (item instanceof JSONObject==false) {
			throw new Exception(extName + "错误");
		} else {
			accessLocation=createGeneralName((JSONObject)item,extName);
		}
		
		return new AccessDescription(accessMethod,accessLocation);
	}
	
	private static String getAccessMethodOid(String name) {
		if(name.equalsIgnoreCase("caIssuers")) {
			return AccessDescription.CAISSUERS_OID;
		} else if(name.equalsIgnoreCase("ocsp")) {
			return AccessDescription.OCSP_OID;
		} else if(name.equalsIgnoreCase("caRepository")) {
			return AccessDescription.CAREPOSITORY_OID;
		} else if(name.equalsIgnoreCase("timeStamping")) {
			return AccessDescription.TIMESTAPING_OID;
		} else {
			return name;
		}
	}
	
	private static Extension createOCSPNoCheck(boolean critical,JSON value)throws Exception {
		if(value instanceof JSONString) {
			return createDefaultExtension(Extension.OCSP_NOCHECK_OID,critical,(JSONString)value);
		} else if(value==null || value instanceof JSONNull) {
			return new Extension(Extension.OCSP_NOCHECK_OID,critical,new NullExtension());
		} else {
			throw new Exception("ocsp no check扩展错误");
		}
		
	}
	
	private static Extension createNetcaUserCertServiceId(boolean critical,JSON value)throws Exception {
		if(value instanceof JSONString==false) {
			throw new Exception("用户证书服务号扩展模板错误");
		}
		
		String str=((JSONString)value).getString();
		return new Extension(Extension.NETCA_USERCERTSERVICEID_OID,critical,new UTF8StringExtension(str));
	}
	
	private static Extension createNetcaEnterpriseIdItems(boolean critical,JSON itemsValue)throws Exception {
		return createNetcaIdentificationItems(critical,itemsValue,Extension.NETCA_ENTERPRISEID_ITEMS_OID,"企业机构身份标识扩展模板");
	}
	
	private static Extension createNetcaIdentifyItems(boolean critical,JSON itemsValue)throws Exception {
		return createNetcaIdentificationItems(critical,itemsValue,Extension.NETCA_IDENTIFY_ITEMS_OID,"个人身份标识扩展模板");
	}
	
	private static Extension createNetcaIdentificationItems(boolean critical,JSON itemsValue,String extOid,String extName)throws Exception {
		if(itemsValue instanceof JSONString) {
			return createDefaultExtension(extOid,critical,(JSONString)itemsValue);
		} else if(itemsValue instanceof JSONArray==false) {
			throw new Exception(extName + "错误");
		}
		
		JSONArray itemsArray=(JSONArray)itemsValue;
		int count=itemsArray.size();
		if(count==0){
			throw new Exception(extName + "错误");
		}
		NetcaIdentificationItemsExtension idItems;
		JSON item;
		NetcaIdentificationItem idItem=null;
		item=itemsArray.get(0);
		if (item instanceof JSONObject==false) {
			throw new Exception(extName + "错误");
		} 
		idItem=createNetcaIdentificationItem((JSONObject)item,extName);
		idItems=new NetcaIdentificationItemsExtension(idItem);
		
		for(int i=1;i<count;i++) {
			item=itemsArray.get(i);
			if (item instanceof JSONObject==false) {
				throw new Exception(extName + "错误");
			} 
			
			idItem=createNetcaIdentificationItem((JSONObject)item,extName);
			idItems.add(idItem);
		}
		return new Extension(extOid,critical,idItems);
	}
	
	private static NetcaIdentificationItem createNetcaIdentificationItem(JSONObject itemObject,String extName)throws Exception {
		int type;
		int encode;
		String value;
		
		JSON item=itemObject.getValue("type");
		if (item instanceof JSONNumber==false) {
			throw new Exception(extName + "错误");
		} else {
			type=((JSONNumber)item).getNumber().intValue();
		}
		
		item=itemObject.getValue("encode");
		if (item instanceof JSONNumber==false) {
			throw new Exception(extName + "错误");
		} else {
			encode=((JSONNumber)item).getNumber().intValue();
		}
		
		item=itemObject.getValue("value");
		if (item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		} else {
			value=((JSONString)item).getString();
		}
		
		if(encode==1 || encode==2) {
			return new NetcaIdentificationItem(type,encode,value.getBytes("UTF-8"));
		} else {
			return new NetcaIdentificationItem(type,encode,Hex.decode(value));
		}
	}
	
	private static Extension createNetcaNetcaCertThumbs(boolean critical,JSON certThumbsValue)throws Exception {
		if(certThumbsValue instanceof JSONString) {
			return createDefaultExtension(Extension.NETCA_PREV_CERT_THUMBPRINT_OID,critical,(JSONString)certThumbsValue);
		} else if(certThumbsValue instanceof JSONArray==false) {
			throw new Exception("前证书微缩图扩展模板错误");
		}
		
		JSONArray thumbsArray=(JSONArray)certThumbsValue;
		int count=thumbsArray.size();
		if(count==0){
			throw new Exception("前证书微缩图扩展模板错误");
		}
		NetcaPrevCertThumbPrintExtension prevCertThumbprint=new NetcaPrevCertThumbPrintExtension();
		JSON item;
		DigestInfo digestInfo;
		for(int i=0;i<count;i++) {
			item=thumbsArray.get(i);
			if (item instanceof JSONObject==false) {
				throw new Exception("前证书微缩图扩展模板错误");
			} 
			
			digestInfo=createDigestInfo((JSONObject)item,"前证书微缩图扩展模板");
			prevCertThumbprint.add(digestInfo);
		}
		return new Extension(Extension.NETCA_PREV_CERT_THUMBPRINT_OID,critical,prevCertThumbprint);
	}
	
	private static DigestInfo createDigestInfo(JSONObject itemObject,String extName)throws Exception {
		String hashAlgo;
		String value;
		
		JSON item=itemObject.getValue("algo");
		if (item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		} else {
			hashAlgo=((JSONString)item).getString();
		}
		
		item=itemObject.getValue("value");
		if (item instanceof JSONString==false) {
			throw new Exception(extName + "错误");
		} else {
			value=((JSONString)item).getString();
		}
		
		AlgorithmIdentifier algo=createHashAlgorithm(hashAlgo);
		return new DigestInfo(algo,Hex.decode(value));
	}
	private static AlgorithmIdentifier createHashAlgorithm(String name) throws Exception{
		if(name.equalsIgnoreCase("MD5")
				|| name.equals(AlgorithmIdentifier.MD5_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.MD5_OID);
		} else if(name.equalsIgnoreCase("SHA1")
				|| name.equalsIgnoreCase("SHA-1")
				|| name.equals(AlgorithmIdentifier.SHA1_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
		} else if(name.equalsIgnoreCase("SM3")
				|| name.equals(AlgorithmIdentifier.SM3_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3_OID);
		} else if(name.equalsIgnoreCase("SHA224")
				|| name.equalsIgnoreCase("SHA-224")
				|| name.equals(AlgorithmIdentifier.SHA224_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA224_OID);
		} else if(name.equalsIgnoreCase("SHA256")
				|| name.equalsIgnoreCase("SHA-256")
				|| name.equals(AlgorithmIdentifier.SHA256_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
		} else if(name.equalsIgnoreCase("SHA384")
				|| name.equalsIgnoreCase("SHA-384")
				|| name.equals(AlgorithmIdentifier.SHA384_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA384_OID);
		} else if(name.equalsIgnoreCase("SHA512")
				|| name.equalsIgnoreCase("SHA-512")
				|| name.equals(AlgorithmIdentifier.SHA512_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_OID);
		} else if(name.equalsIgnoreCase("SHA-512/224")
				|| name.equals(AlgorithmIdentifier.SHA512_224_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_224_OID);
		} else if(name.equalsIgnoreCase("SHA-512/256")
				|| name.equals(AlgorithmIdentifier.SHA512_256_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_256_OID);
		} else if(name.equalsIgnoreCase("SHA3-224")
				|| name.equals(AlgorithmIdentifier.SHA3_224_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_224_OID);
		} else if(name.equalsIgnoreCase("SHA3-256")
				|| name.equals(AlgorithmIdentifier.SHA3_256_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_256_OID);
		} else if(name.equalsIgnoreCase("SHA3-384")
				|| name.equals(AlgorithmIdentifier.SHA3_384_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_384_OID);
		} else if(name.equalsIgnoreCase("SHA3-512")
				|| name.equals(AlgorithmIdentifier.SHA3_512_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_512_OID);
		} else {
			throw new Exception("未知Hash算法");
		}
	}
	private static String getExtensionOid(String name) {
		if(name.equalsIgnoreCase("Authority Key Identifier")) {
			return Extension.AUTHORITY_KEYIDENTIFIER_OID;
		} else if(name.equalsIgnoreCase("Subject Key Identifier")) {
			return Extension.SUBJECT_KEYIDENTIFIER_OID;
		} else if(name.equalsIgnoreCase("Key Usage")) {
			return Extension.KEYUSAGE_OID;
		} else if(name.equalsIgnoreCase("Certificate Policies")) {
			return Extension.CERTPOLICIES_OID;
		} else if(name.equalsIgnoreCase("Policy Mappings")) {
			return Extension.POLICYMAPPINGS_OID;
		} else if(name.equalsIgnoreCase("Subject Alternative Name")) {
			return Extension.SUBJECT_ALTNAME_OID;
		} else if(name.equalsIgnoreCase("Issuer Alternative Name")) {
			return Extension.ISSUER_ALTNAME_OID;
		} else if(name.equalsIgnoreCase("Subject Directory Attributes")) {
			return Extension.SUBJECT_DIRECTORY_ATTRIBUTES_OID;
		} else if(name.equalsIgnoreCase("Basic Constraints")) {
			return Extension.BASIC_CONSTRAINTS_OID;
		} else if(name.equalsIgnoreCase("Name Constraints")) {
			return Extension.NAME_CONSTRAINTS_OID;
		} else if(name.equalsIgnoreCase("Policy Constraints")) {
			return Extension.POLICY_CONSTRAINTS_OID;
		} else if(name.equalsIgnoreCase("Extended Key Usage")) {
			return Extension.EXTKEYUSAGE_OID;
		} else if(name.equalsIgnoreCase("CRL Distribution Points")) {
			return Extension.CRLDISTRIBUTIONPOINTS_OID;
		} else if(name.equalsIgnoreCase("Inhibit anyPolicy")) {
			return Extension.INHIBIT_ANYPOLICY_OID;
		} else if(name.equalsIgnoreCase("Freshest CRL")) {
			return Extension.FRESHESTCRL_OID;
		} else if(name.equalsIgnoreCase("Authority Information Access")) {
			return Extension.AUTHORITYINFOACCESS_OID;
		} else if(name.equalsIgnoreCase("Subject Information Access")) {
			return Extension.SUBJECTINFOACCESS_OID;
		} else if(name.equalsIgnoreCase("CRL Number")) {
			return Extension.CRLNUMBER_OID;
		} else if(name.equalsIgnoreCase("Delta CRL Indicator")) {
			return Extension.DELTACRLINDICATOR_OID;
		} else if(name.equalsIgnoreCase("Issuing Distribution Point")) {
			return Extension.ISSUINGDISTRIBUTIONPOINT_OID;
		} else if(name.equalsIgnoreCase("Reason Code")) {
			return Extension.CRLREASONS_OID;
		} else if(name.equalsIgnoreCase("Invalidity Date")) {
			return Extension.INVALID_DATE_OID;
		} else if(name.equalsIgnoreCase("Certificate Issuer")) {
			return Extension.CERTIFICATEISSUER_OID;
		} else if(name.equalsIgnoreCase("ocsp nocheck")) {
			return Extension.OCSP_NOCHECK_OID;
		} else if(name.equals("用户证书服务号")) {
			return Extension.NETCA_USERCERTSERVICEID_OID;
		} else if(name.equals("个人身份标识")) {
			return Extension.NETCA_IDENTIFY_ITEMS_OID;
		} else if(name.equals("企业机构身份标识")) {
			return Extension.NETCA_ENTERPRISEID_ITEMS_OID;
		} else if(name.equals("前证书微缩图")) {
			return Extension.NETCA_PREV_CERT_THUMBPRINT_OID;
		} else {
			return name;
		}	
	}
}
