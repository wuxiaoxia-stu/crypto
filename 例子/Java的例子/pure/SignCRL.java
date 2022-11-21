import net.netca.pki.encoding.json.*;
import java.io.*;
import net.netca.pki.KeyPair;
import net.netca.pki.Device;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.*;
import net.netca.pki.encoding.Hex;
import java.util.*;
import net.netca.pki.Util;
import net.netca.pki.Certificate;
import java.math.*;

public class SignCRL {

	public static void main(String[] args) throws Exception{
		if(args.length!=4) {
            System.out.println("Usage: java SignCRL issuerCertFileName pwd templateFileName crlFileName");
            return;
        }
		
		JSON templateJson=getJsonFromFile(args[2]);
		if (templateJson instanceof JSONObject==false) {
			System.out.println("模板文件不是JSON对象");
            return;
		}
				
		String pwd=args[1];
		String crlFileName=args[3];
		String issuerCertFileName=args[0];
	
		Certificate issuerCert=getCert(issuerCertFileName);
		KeyPair keypair=null;
		NetcaSigner signer=null;
		
		try {
			keypair=issuerCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取颁发者证书的密钥失败");
	            return;
			}
			
			X509Certificate x509IssuerCert=new X509Certificate(issuerCert.derEncode());
						
			X509CRLBuilder builder=new X509CRLBuilder(x509IssuerCert);
			
			
			int version=getVerison((JSONObject)templateJson);
			builder.setVersion(version);
			
			AlgorithmIdentifier signAlgo=getSignAlgo((JSONObject)templateJson,keypair);
			
			setValidity(builder,(JSONObject)templateJson);
			
			CRLEntries entries=createCRLEntries((JSONObject)templateJson);
			if(entries!=null) {
				builder.setCRLEntries(entries);
			}
		
			Extensions exts=createExtensions((JSONObject)templateJson,x509IssuerCert);
			if(exts!=null) {
				builder.setExtensions(exts);
			}
			
			signer=new NetcaSigner(keypair);
			X509CRL crl=builder.sign(signer,signAlgo);
			
			writeFile(crlFileName,crl.derEncode());
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
			setOf.add(createAttributeTypeAndValue(rdnArray.get(i)).getValue());
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
	
	private static int getVerison(JSONObject templete)throws Exception {
		JSON item=templete.getValue("verison");
		if(item==null) {
			return X509CRL.V2;
		}
		if(item instanceof JSONString==false) {
			throw new Exception("版本号项不是JSON字符串");
		}
		String version=((JSONString)item).getString();
		if(version.equalsIgnoreCase("V1")) {
			return X509CRL.V1;
		} else if(version.equalsIgnoreCase("V2")) {
			return X509CRL.V2;
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
		algo=getsignatureAlgorithmOid(algo);
		
		item=algoObject.getValue("parameters");
		if(item==null) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(algo);
		}
		if (item instanceof JSONNull) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(algo);
		} else if(item instanceof JSONString==false) {
			throw new Exception("签名算法参数项不是JSON字符串");
		}
		String hexValue=((JSONString)item).getString();
		byte[] value=Hex.decode(hexValue);
		ASN1Object paramValue=ASN1Object.decode(value, AnyType.getInstance());
		return new AlgorithmIdentifier(algo,paramValue);
	}
	
	private static String getsignatureAlgorithmOid(String value) {
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
	
	private static void setValidity(X509CRLBuilder builder,JSONObject templete)throws Exception {
		
		Date thisUpdate;
		String value;
		JSON item=templete.getValue("thisUpdate");
		if(item==null) {
			thisUpdate=getDefaultThisUpdate();
		} else if(item instanceof JSONString==false) {
			throw new Exception("thisUpdate模板出错");
		} else {
			value=((JSONString)item).getString();
			thisUpdate=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		}
		builder.setThisUpdate(thisUpdate);
		
		Date nextUpdate;
		
		item=templete.getValue("nextUpdate");
		if(item==null) {
			Calendar cal = Calendar.getInstance();
			cal.setTime(thisUpdate);
			cal.add(Calendar.MONTH, 1);
			nextUpdate=cal.getTime();
		} else if(item instanceof JSONNull){
			return;
		}  else if(item instanceof JSONNumber) {
			int days=((JSONNumber)item).getNumber().intValue();
			Calendar cal = Calendar.getInstance();
			cal.setTime(thisUpdate);
			cal.add(Calendar.DAY_OF_MONTH, days);
			nextUpdate=cal.getTime();
		} else if(item instanceof JSONString==false) {
			throw new Exception("nextUpdate模板出错");
		} else {
			value=((JSONString)item).getString();
			nextUpdate=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		}
		builder.setNextUpdate(nextUpdate);
		
		
	}
	private static Date getDefaultThisUpdate() {
		return new Date();
	}
	
	private static Extensions createExtensions(JSONObject templete,X509Certificate issuerCert)throws Exception {
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
			ext=createExtension((JSONObject)item,issuerCert);
			exts.add(ext);
		}
				
		return exts;
	}
	
	private static Extension createExtension(JSONObject extObj,X509Certificate issuerCert)throws Exception {
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
		} else if(extOid.equals(Extension.ISSUER_ALTNAME_OID)) {
			return createIssuerAlternativeName(critical,item);
		} else if(extOid.equals(Extension.FRESHESTCRL_OID)) {
			return createFreshestCRL(critical,item);
		} else if(extOid.equals(Extension.CRLNUMBER_OID)) {
			return createCRLNumber(critical,item);
		} else if(extOid.equals(Extension.DELTACRLINDICATOR_OID)) {
			return createDeltaCRLIndicator(critical,item);
		} else if(extOid.equals(Extension.AUTHORITYINFOACCESS_OID)) {
			return createAuthorityInfoAccess(critical,item);
		} else if(extOid.equals(Extension.ISSUINGDISTRIBUTIONPOINT_OID)) {
			return createIssuingDistributionPoint(critical,item);
		} else if(extOid.equals("2.23.146.1.2.0.2")) {
			return createTotalPartialCrlNumber(critical,item);
		} else if(extOid.equals("2.23.146.1.2.0.3")) {
			return createPartialCRLNumber(critical,item);
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
		
		if(type.equals("otherName")) {
			if (item instanceof JSONObject==false) {
				throw new Exception(extName + "错误");
			}
			OtherName otherName=createOtherName((JSONObject)item,extName);
			return GeneralName.NewOtherName(otherName);
		} else if (type.equals("rfc822Name")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewRFC822Name(value);
		} else if (type.equals("dNSName")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewDNSName(value);
		} else if (type.equals("directoryName")) {
			X500Name x500Name=createDN(item);
			return GeneralName.NewDirectoryName(x500Name);
		}else if (type.equals("uniformResourceIdentifier")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String value=((JSONString)item).getString();
			return GeneralName.NewURI(value);
		} else if (type.equals("iPAddress")) {
			if (item instanceof JSONString==false) {
				throw new Exception(extName + "错误");
			}
			String hexValue=((JSONString)item).getString();
			byte[] value=Hex.decode(hexValue);
			return GeneralName.NewIPAddress(value);
			
		} else if (type.equals("registeredID")) {
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
	
	private static Extension createCRLNumber(boolean critical,JSON crlNumberValue)throws Exception {
		return  createCRLNumber(critical,crlNumberValue,Extension.CRLNUMBER_OID,"CRL数字扩展模板");
	}
	
	private static Extension createDeltaCRLIndicator(boolean critical,JSON crlNumberValue)throws Exception {
		return  createCRLNumber(critical,crlNumberValue,Extension.DELTACRLINDICATOR_OID,"Delta CRL指示符扩展模板");
	}
	
	private static Extension createCRLNumber(boolean critical,JSON crlNumberValue,String extOid,String extName)throws Exception {
		net.netca.pki.encoding.asn1.Integer number; 
		if(crlNumberValue instanceof JSONString) {
			String hexValue=((JSONString)crlNumberValue).getString();
			byte[] value=Hex.decode(hexValue);
			number=new net.netca.pki.encoding.asn1.Integer(new BigInteger(1,value));
		} else if(crlNumberValue instanceof JSONNumber==false) {
			throw new Exception(extName + "错误");
		} else {
			BigInteger value=((JSONNumber)crlNumberValue).getNumber().toBigInteger();
			number=new net.netca.pki.encoding.asn1.Integer(value);
		}
		
		return new Extension(extOid,critical,number.encode());
	}
	
	private static Extension createAuthorityInfoAccess(boolean critical,JSON aiaValue)throws Exception {
		return createAuthorityInfoAccess(critical,aiaValue,Extension.AUTHORITYINFOACCESS_OID,"颁发者信息访问扩展模板");
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
		if (item instanceof JSON==false) {
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
	
	private static Extension createIssuingDistributionPoint(boolean critical,JSON idpValue)throws Exception {
		if(idpValue instanceof JSONString) {
			return createDefaultExtension(Extension.ISSUINGDISTRIBUTIONPOINT_OID,critical,(JSONString)idpValue);
		} else if(idpValue instanceof JSONObject==false) {
			throw new Exception("颁发分布点模板错误");
		}
		
		JSONObject idpObject=(JSONObject)idpValue;
		IssuingDistributionPointExtension ext;
		DistributionPointName distributionPoint=null;
		boolean onlyContainsUserCerts=false;
		boolean onlyContainsCACerts=false;
		net.netca.pki.encoding.asn1.BitString onlySomeReasons=null;
		boolean indirectCRL=false;
		boolean onlyContainsAttributeCerts=false;
		
		JSON item=idpObject.getValue("distributionPoint");
		if(item!=null) {
			if(item instanceof JSONObject==false) {
				throw new Exception("颁发分布点模板错误");
			}
			distributionPoint=createDistributionPointName((JSONObject)item,"颁发分布点模板");
		}
		
		item=idpObject.getValue("onlyContainsUserCerts");
		if(item!=null) {
			if(item instanceof JSONBoolean==false) {
				throw new Exception("颁发分布点模板错误");
			}
			onlyContainsUserCerts=((JSONBoolean)item).isTrue();
		}
		
		item=idpObject.getValue("onlyContainsCACerts");
		if(item!=null) {
			if(item instanceof JSONBoolean==false) {
				throw new Exception("颁发分布点模板错误");
			}
			onlyContainsCACerts=((JSONBoolean)item).isTrue();
		}
		
		item=idpObject.getValue("indirectCRL");
		if(item!=null) {
			if(item instanceof JSONBoolean==false) {
				throw new Exception("颁发分布点模板错误");
			}
			indirectCRL=((JSONBoolean)item).isTrue();
		}
		
		item=idpObject.getValue("onlyContainsAttributeCerts");
		if(item!=null) {
			if(item instanceof JSONBoolean==false) {
				throw new Exception("颁发分布点模板错误");
			}
			onlyContainsAttributeCerts=((JSONBoolean)item).isTrue();
		}
		
		item=idpObject.getValue("onlySomeReasons");
		if(item!=null) {
			if(item instanceof JSONArray==false) {
				throw new Exception("颁发分布点模板错误");
			}
			JSONArray reasonArray=(JSONArray)item;
			int count=reasonArray.size();
			boolean []bits=new boolean[count];
			for(int i=0;i<count;i++) {
				item=reasonArray.get(i);
				if(item instanceof JSONBoolean==false) {
					throw new Exception("颁发分布点模板错误");
				}
				bits[i]=((JSONBoolean)item).isTrue();
			}
			onlySomeReasons=new net.netca.pki.encoding.asn1.BitString(bits);
		}
		ext=new IssuingDistributionPointExtension(distributionPoint,onlyContainsUserCerts,
				onlyContainsCACerts,onlySomeReasons,indirectCRL,onlyContainsAttributeCerts);
		return new Extension(Extension.ISSUINGDISTRIBUTIONPOINT_OID,critical,ext);
	}
	
	private static CRLEntries createCRLEntries(JSONObject templateJson) throws Exception{
		JSON item=templateJson.getValue("revokedCertificates");
		if(item==null){
			return null;
		}
		
		if(item instanceof JSONArray==false) {
			throw new Exception("作废证书模板错误");
		}
		
		CRLEntries entries=new CRLEntries();
		JSONArray entryArray=(JSONArray)item;
		int count=entryArray.size();
		CRLEntry entry;
		for(int i=0;i<count;i++){
			item=entryArray.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("作废证书模板错误");
			}
			entry=createCRLEntry((JSONObject)item);
			entries.add(entry);
		}
		
		return entries;
	}
	
	private static CRLEntry createCRLEntry(JSONObject entryJson) throws Exception{
		JSON item=entryJson.getValue("serialNumber");
		if(item==null){
			throw new Exception("作废证书模板错误");
		}
		if(item instanceof JSONString==false) {
			throw new Exception("作废证书模板错误");
		}
		
		String value=((JSONString)item).getString();
		byte[] serialNumber=Hex.decode(value);
		
		item=entryJson.getValue("revocationDate");
		if(item==null){
			throw new Exception("作废证书模板错误");
		}
		if(item instanceof JSONString==false) {
			throw new Exception("作废证书模板错误");
		}
		value=((JSONString)item).getString();
		Date revocationDate=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		Extensions exts=createCRLEntryExtensions(entryJson);
		
		item=entryJson.getValue("extensions");
		if(item==null){
			exts=null;
		}
		return new CRLEntry(serialNumber,revocationDate,exts);
	}
	
	private static Extensions createCRLEntryExtensions(JSONObject templete)throws Exception {
		JSON item=templete.getValue("extensions");
		if(item==null) {
			return null;
		}
		if(item instanceof JSONArray==false) {
			throw new Exception("CRL条目扩展项不是JSON数组");
		}
		JSONArray extsArray=(JSONArray)item;
		int count=extsArray.size();
		Extension ext;
		Extensions exts=new Extensions();		
		for(int i=0;i<count;i++) {
			item=extsArray.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("CRL条目扩展项不是JSON对象");
			}
			ext=createCRLEntryExtension((JSONObject)item);
			exts.add(ext);
		}
				
		return exts;
	}
	
	private static Extension createCRLEntryExtension(JSONObject extObj)throws Exception {
		JSON item=extObj.getValue("extnID");
		if(item instanceof JSONString==false) {
			throw new Exception("CRL条目扩展OID项不是JSON字符串");
		}
		String extOid=((JSONString)item).getString();
		extOid=getExtensionOid(extOid);
		
		boolean critical;
		item=extObj.getValue("critical");
		if(item==null) {
			critical=false;
		} else if(item instanceof JSONBoolean==false) {
			throw new Exception("CRL条目扩展关键性项不是JSON布尔值");
		} else {
			critical=((JSONBoolean)item).isTrue();
		}
		item=extObj.getValue("extnValue");
		
		if(extOid.equals(Extension.CRLREASONS_OID)) {
			return createCRLReason(critical,item);
		} else if(extOid.equals(Extension.INVALID_DATE_OID)) {
			return createInvalidityDate(critical,item);
		} else if(extOid.equals(Extension.CERTIFICATEISSUER_OID)) {
			return createCertificateIssuer(critical,item);
		} else if(extOid.equals("2.23.146.1.2.0.1")) {
			return createCertificateExpirationDate(critical,item);
		} else {
			if(item instanceof JSONString) {
				return createDefaultExtension(extOid,critical,(JSONString)item);
			} else {
				throw new Exception("CRL条目扩展项模板错误");
			}
			
		}
	}
	
	private static Extension createCRLReason(boolean critical,JSON crlReasonValue)throws Exception {
		int reason;
		if(crlReasonValue instanceof JSONString) {
			String value=((JSONString)crlReasonValue).getString();
			if(value.equalsIgnoreCase("unspecified")) {
				reason=0;
			} else if(value.equalsIgnoreCase("keyCompromise")) {
				reason=1;
			} else if(value.equalsIgnoreCase("cACompromise")) {
				reason=2;
			} else if(value.equalsIgnoreCase("affiliationChanged")) {
				reason=3;
			} else if(value.equalsIgnoreCase("superseded")) {
				reason=4;
			} else if(value.equalsIgnoreCase("cessationOfOperation")) {
				reason=5;
			} else if(value.equalsIgnoreCase("certificateHold")) {
				reason=6;
			} else if(value.equalsIgnoreCase("removeFromCRL")) {
				reason=8;
			} else if(value.equalsIgnoreCase("privilegeWithdrawn")) {
				reason=9;
			} else if(value.equalsIgnoreCase("aACompromise")) {
				reason=10;
			} else {
				throw new Exception("CRL理由码扩展项模板错误");
			}
		} else if(crlReasonValue instanceof JSONNumber==false) {
			throw new Exception("CRL理由码扩展项模板错误");
		} else {
			reason=((JSONNumber)crlReasonValue).getNumber().intValue();
		}
		return new Extension(Extension.CRLREASONS_OID,critical,new EnumeratedExtension(reason));
	}
	
	private static Extension createInvalidityDate(boolean critical,JSON invalidityDateValue)throws Exception {
		Date invalidityDate;
		if(invalidityDateValue instanceof JSONString) {
			String value=((JSONString)invalidityDateValue).getString();
			invalidityDate=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		} else{
			throw new Exception("无效日期扩展项模板错误");
		} 
		return new Extension(Extension.INVALID_DATE_OID,critical,new GeneralizedTimeExtension(invalidityDate));
	}
	
	private static Extension createCertificateIssuer(boolean critical,JSON gnsValue)throws Exception {
		return createGeneralNames(critical,gnsValue,Extension.CERTIFICATEISSUER_OID,"证书颁发者扩展模板");		
	}
	
	private static Extension createTotalPartialCrlNumber(boolean critical,JSON crlNumberValue)throws Exception {
		return  createCRLNumber(critical,crlNumberValue,"2.23.146.1.2.0.2","Total Partial CRL Number扩展模板");
	}
	
	private static Extension createPartialCRLNumber(boolean critical,JSON crlNumberValue)throws Exception {
		return  createCRLNumber(critical,crlNumberValue,"2.23.146.1.2.0.3","Partial CRL Number扩展模板");
	}
	
	private static Extension createCertificateExpirationDate(boolean critical,JSON invalidityDateValue)throws Exception {
		Date invalidityDate;
		if(invalidityDateValue instanceof JSONString) {
			String value=((JSONString)invalidityDateValue).getString();
			invalidityDate=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		} else{
			throw new Exception("证书过期日期扩展项模板错误");
		} 
		Time t=new Time(invalidityDate);
		return new Extension("2.23.146.1.2.0.1",critical,t.getASN1Object().encode());
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
		} else if(name.equalsIgnoreCase("Certificate Expiration Date")) {
			return "2.23.146.1.2.0.1";
		} else if(name.equalsIgnoreCase("Total Partial CRL Number")) {
			return "2.23.146.1.2.0.2";
		} else if(name.equalsIgnoreCase("Partial CRL Number")) {
			return "2.23.146.1.2.0.3";
		} else {
			return name;
		}
	}
}
