import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

import net.netca.pki.Certificate;
import net.netca.pki.Device;
import net.netca.pki.Freeable;
import net.netca.pki.KeyPair;
import net.netca.pki.Util;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.ASN1TypeManager;
import net.netca.pki.encoding.asn1.AnyType;
import net.netca.pki.encoding.asn1.BMPString;
import net.netca.pki.encoding.asn1.BitString;
import net.netca.pki.encoding.asn1.IA5String;
import net.netca.pki.encoding.asn1.PrintableString;
import net.netca.pki.encoding.asn1.SetOf;
import net.netca.pki.encoding.asn1.SetOfType;
import net.netca.pki.encoding.asn1.UTF8String;
import net.netca.pki.encoding.asn1.VisibleString;
import net.netca.pki.encoding.asn1.pki.AccessDescription;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Attribute;
import net.netca.pki.encoding.asn1.pki.AttributeTypeAndValue;
import net.netca.pki.encoding.asn1.pki.AuthorityKeyIdentifierExtension;
import net.netca.pki.encoding.asn1.pki.CRLDistributionPointsExtension;
import net.netca.pki.encoding.asn1.pki.DistributionPoint;
import net.netca.pki.encoding.asn1.pki.DistributionPointName;
import net.netca.pki.encoding.asn1.pki.Extension;
import net.netca.pki.encoding.asn1.pki.Extensions;
import net.netca.pki.encoding.asn1.pki.GeneralName;
import net.netca.pki.encoding.asn1.pki.GeneralNames;
import net.netca.pki.encoding.asn1.pki.InfoAccessExtension;
import net.netca.pki.encoding.asn1.pki.NetcaSigner;
import net.netca.pki.encoding.asn1.pki.NullExtension;
import net.netca.pki.encoding.asn1.pki.OctetStringExtension;
import net.netca.pki.encoding.asn1.pki.OtherName;
import net.netca.pki.encoding.asn1.pki.RelativeDistinguishedName;
import net.netca.pki.encoding.asn1.pki.Signable;
import net.netca.pki.encoding.asn1.pki.X500Name;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pmi.AttributeCertificate;
import net.netca.pki.encoding.asn1.pmi.AttributeCertificateBuilder;
import net.netca.pki.encoding.asn1.pmi.Clearance;
import net.netca.pki.encoding.asn1.pmi.Holder;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntax;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntaxValue;
import net.netca.pki.encoding.asn1.pmi.IssuerSerial;
import net.netca.pki.encoding.asn1.pmi.ObjectDigestInfo;
import net.netca.pki.encoding.asn1.pmi.RFC3281Clearance;
import net.netca.pki.encoding.asn1.pmi.RoleSyntax;
import net.netca.pki.encoding.asn1.pmi.SecurityCategory;
import net.netca.pki.encoding.asn1.pmi.SvceAuthInfo;
import net.netca.pki.encoding.asn1.pmi.Target;
import net.netca.pki.encoding.asn1.pmi.TargetCert;
import net.netca.pki.encoding.asn1.pmi.TargetInformationExtension;
import net.netca.pki.encoding.asn1.pmi.Targets;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONBoolean;
import net.netca.pki.encoding.json.JSONNull;
import net.netca.pki.encoding.json.JSONNumber;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;

public class SignAC {

	public static void main(String[] args) throws Exception{
		if(args.length!=4) {
            System.out.println("Usage: java SignAC issuerCertFileName pwd templateFileName acFileName");
            return;
        }
		
		JSON templateJson=getJsonFromFile(args[2]);
		if (templateJson instanceof JSONObject==false) {
			System.out.println("模板文件不是JSON对象");
            return;
		}
				
		String pwd=args[1];
		String acFileName=args[3];
		String issuerCertFileName=args[0];
	
		
		Signable signer=null;
		
		try {
			X509Certificate x509IssuerCert=getCert(issuerCertFileName);			
			AttributeCertificateBuilder builder=AttributeCertificateBuilder.create(x509IssuerCert);
			
			
			int version=getVerison((JSONObject)templateJson);
			builder.setVersion(version);
			
			Holder holder=createHolder((JSONObject)templateJson);
			builder.setHolder(holder);
			
			AlgorithmIdentifier signAlgo=getSignAlgo((JSONObject)templateJson,x509IssuerCert);
			
			setValidity(builder,(JSONObject)templateJson);
			
			byte[] sn=getSerialNumber((JSONObject)templateJson);
			builder.setSerialNumber(sn);
			
			ArrayList<Attribute> attrs=createAttributes((JSONObject)templateJson);
			builder.setAttributes(attrs);
			
			Extensions exts=createExtensions((JSONObject)templateJson,x509IssuerCert);
			if(exts!=null) {
				builder.setExtensions(exts);
			}
			
			
			signer=getSigner(x509IssuerCert,pwd);
			AttributeCertificate ac=builder.sign(signer,signAlgo);
			
			writeFile(acFileName,ac.derEncode());
	        System.out.println("Success");
		} finally {
			
			if(signer instanceof Freeable){
				((Freeable)signer).free();
			}
		}

	}

	
	private static Signable getSigner(X509Certificate x509,String pwd) throws Exception{
		Certificate cert=new Certificate(x509.derEncode());
		KeyPair keypair=cert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
		cert.free();
		if(keypair==null) {
			throw new Exception("获取颁发者证书的密钥失败");
        }
		try {
			return new NetcaSigner(keypair);
		} finally{
			keypair.free();
		}
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
	
	private static X509Certificate getCert(String certFileName) throws Exception{
		byte[] certData=readFile(certFileName);
		return new X509Certificate(certData);
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
	
	private static int getVerison(JSONObject templete)throws Exception {
		JSON item=templete.getValue("verison");
		if(item==null) {
			return AttributeCertificate.V2;
		}
		if(item instanceof JSONString==false) {
			throw new Exception("版本号项不是JSON字符串");
		}
		String version=((JSONString)item).getString();
		if(version.equalsIgnoreCase("V2")) {
			return AttributeCertificate.V2;
		} else {
			throw new Exception("不支持的属性版本号");
		}
	}
	
	private static AlgorithmIdentifier getSignAlgo(JSONObject templete,X509Certificate issuerCert)throws Exception {
		JSON item=templete.getValue("signatureAlgorithm");
		if(item==null) {
			return getDefaultSignAlgo(issuerCert);
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
		} else if(item instanceof JSONString==false) {
			throw new Exception("签名算法参数项不是JSON字符串");
		}
		String hexValue=((JSONString)item).getString();
		byte[] value=Hex.decode(hexValue);
		ASN1Object paramValue=ASN1Object.decode(value, AnyType.getInstance());
		return new AlgorithmIdentifier(algo,paramValue);
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
		} else {
			return value;
		}
	}
	
	private static AlgorithmIdentifier getDefaultSignAlgo(X509Certificate issuerCert)throws Exception {
		
		if(issuerCert.isRSA()) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
		} else if(issuerCert.isSM2()) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
		}
		
		String oid=issuerCert.getSubjectPublicKeyInfo().getAlgorithm().getOid();
		if(oid.equals(AlgorithmIdentifier.DSA_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.DSAWithSHA1_OID);
		} else if(oid.equals(AlgorithmIdentifier.ECPubKey_OID)) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
		}
		
		throw new Exception("get default sign algo fail");
	}
	private static void setValidity(AttributeCertificateBuilder builder,JSONObject templete)throws Exception {
		
		Date notBefore;
		String value;
		JSON item=templete.getValue("notBefore");
		if(item==null) {
			notBefore=getDefaultThisUpdate();
		} else if(item instanceof JSONString==false) {
			throw new Exception("notBefore模板出错");
		} else {
			value=((JSONString)item).getString();
			notBefore=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		}
		builder.setNotBefore(notBefore);
		
		Date notAfter;
		
		item=templete.getValue("notAfter");
		if(item==null) {
			Calendar cal = Calendar.getInstance();
			cal.setTime(notBefore);
			cal.add(Calendar.MONTH, 1);
			notAfter=cal.getTime();
		} else if(item instanceof JSONNumber) {
			int days=((JSONNumber)item).getNumber().intValue();
			Calendar cal = Calendar.getInstance();
			cal.setTime(notBefore);
			cal.add(Calendar.DAY_OF_MONTH, days);
			notAfter=cal.getTime();
		} else if(item instanceof JSONObject) {
			notAfter=getNotAfter(notBefore,(JSONObject)item);
		} else if(item instanceof JSONString==false) {
			throw new Exception("notAfter模板出错");
		} else {
			value=((JSONString)item).getString();
			notAfter=Util.UTCTimeDecode(value.getBytes("UTF-8"));
		}
		builder.setNotAfter(notAfter);
		
		
	}
	private static Date getNotAfter(Date notBefore,JSONObject templete)throws Exception {
		Calendar cal = Calendar.getInstance();
		cal.setTime(notBefore);
		int value;
		JSON item=templete.getValue("year");
		if(item!= null){
			if(item instanceof JSONNumber) {
				value=((JSONNumber)item).getNumber().intValue();
				cal.add(Calendar.YEAR, value);
			} else {
				throw new Exception("notAfter模板出错");
			}
		} 
		
		item=templete.getValue("month");
		if(item!= null){
			if(item instanceof JSONNumber) {
				value=((JSONNumber)item).getNumber().intValue();
				cal.add(Calendar.MONTH, value);
			} else {
				throw new Exception("notAfter模板出错");
			}
		} 
		
		item=templete.getValue("day");
		if(item!= null){
			if(item instanceof JSONNumber) {
				value=((JSONNumber)item).getNumber().intValue();
				cal.add(Calendar.DAY_OF_MONTH, value);
			} else {
				throw new Exception("notAfter模板出错");
			}
		} 
		
		item=templete.getValue("hour");
		if(item!= null){
			if(item instanceof JSONNumber) {
				value=((JSONNumber)item).getNumber().intValue();
				cal.add(Calendar.HOUR_OF_DAY, value);
			} else {
				throw new Exception("notAfter模板出错");
			}
		} 
		
		item=templete.getValue("minute");
		if(item!= null){
			if(item instanceof JSONNumber) {
				value=((JSONNumber)item).getNumber().intValue();
				cal.add(Calendar.MINUTE, value);
			} else {
				throw new Exception("notAfter模板出错");
			}
		}
		
		item=templete.getValue("second");
		if(item!= null){
			if(item instanceof JSONNumber) {
				value=((JSONNumber)item).getNumber().intValue();
				cal.add(Calendar.SECOND, value);
			} else {
				throw new Exception("notAfter模板出错");
			}
		}
		Date notAfter=cal.getTime();
		if(notBefore==notAfter){
			throw new Exception("notAfter模板出错");
		}
		return notAfter;
	}
	private static Date getDefaultThisUpdate() {
		return new Date();
	}
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
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
		} else if(hexValue.toLowerCase().startsWith("random:")) {
			String lenStr=hexValue.substring(7);
			int len=java.lang.Integer.parseInt(lenStr);
			return getRandSerialNumber(len);
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
	
	private static byte[] getRandSerialNumber(int length)throws Exception {
		Device device=Device.getPseudoDevice();
		if(device==null) {
			throw new Exception("获取内置软件设备失败");
		}
		byte[] rand=device.generateRandom(length);
		try {
			for(;;) {
				rand[0]&=0x7F;
				if(rand[0]!=0){
					break;
				}
				
			}
			
			return rand;
		}finally {
			device.free();
		}
	}
	
	
	private static Holder createHolder(JSONObject templete)throws Exception {
		
		JSON item=templete.getValue("holder");
		if(item instanceof JSONObject==false) {
			throw new Exception("holder模板出错");
		} 
		JSONObject holderObj=(JSONObject)item;
		IssuerSerial baseCertificateID=null;
		item=holderObj.getValue("baseCertificate");
		if(item!=null){
			if(item instanceof JSONString==false) {
				throw new Exception("holder模板出错");
			}
			String certFileName=((JSONString)item).getString();
			X509Certificate cert=new X509Certificate(readFile(certFileName));
			baseCertificateID=new IssuerSerial(cert);
			
		}
		GeneralNames entityName=null;
		item=holderObj.getValue("entityName");
		if(item!=null){
			if(item instanceof JSONArray==false) {
				throw new Exception("holder模板出错");
			}
			entityName=createGeneralNames((JSONArray)item,"holder模板");
		}
		
		ObjectDigestInfo objectDigestInfo=null;
		item=holderObj.getValue("objectDigestInfo");
		if(item!=null){
			if(item instanceof JSONObject==false) {
				throw new Exception("holder模板出错");
			}
			objectDigestInfo=createObjectDigestInfo((JSONObject)item,"holder模板出错");
		}
		
		return new Holder(baseCertificateID,entityName,objectDigestInfo);
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
	
	private static X500Name createDN(JSON subjectItem) throws Exception {
		if(subjectItem==null) {
			throw new Exception("没有DN项");
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

	private static ObjectDigestInfo createObjectDigestInfo(JSONObject templete,String msg)throws Exception {
			
		JSON item=templete.getValue("type");
		if(item instanceof JSONString==false) {
			throw new Exception(msg + "错误");
		} 
		int type;
		String typeStr=((JSONString)item).getString();
		if(typeStr.equalsIgnoreCase("publicKey")){
			type=ObjectDigestInfo.PUBLICKEY;
		} else if(typeStr.equalsIgnoreCase("publicKeyCert")){
			type=ObjectDigestInfo.PUBLICKEYCERT;
		} else if(typeStr.equalsIgnoreCase("other")){
			type=ObjectDigestInfo.OTHEROBJECTTYPES;
		} else {
			throw new Exception(msg + "错误");
		}
		String otherObjectTypeID=null;
		item=templete.getValue("otherObjectTypeID");
		if(item!=null){
			if(item instanceof JSONString==false) {
				throw new Exception(msg + "错误");
			}
			otherObjectTypeID=((JSONString)item).getString();
		}
		String digestAlgorithm;
		item=templete.getValue("digestAlgorithm");
		if(item instanceof JSONString==false) {
			throw new Exception(msg + "错误");
		}
		digestAlgorithm=((JSONString)item).getString();
		
		String objectDigest;
		item=templete.getValue("objectDigest");
		if(item instanceof JSONString==false) {
			throw new Exception(msg + "错误");
		}
		objectDigest=((JSONString)item).getString();
		
		return new ObjectDigestInfo(type,otherObjectTypeID,getHashAlgo(digestAlgorithm),
				Util.HexDecode(objectDigest));
	}
	
	private static AlgorithmIdentifier getHashAlgo(String oid) throws Exception{
		if(oid.equalsIgnoreCase("MD2") ||
				oid.equals(AlgorithmIdentifier.MD2_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.MD2_OID);
		} else if(oid.equalsIgnoreCase("MD5") ||
				oid.equals(AlgorithmIdentifier.MD5_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.MD5_OID);
		} else if(oid.equalsIgnoreCase("SHA-1") ||
				oid.equalsIgnoreCase("SHA1") ||
				oid.equals(AlgorithmIdentifier.SHA1_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
		} else if(oid.equalsIgnoreCase("SHA-224") ||
				oid.equalsIgnoreCase("SHA224") ||
				oid.equals(AlgorithmIdentifier.SHA224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA224_OID);
		} else if(oid.equalsIgnoreCase("SHA-256") ||
				oid.equalsIgnoreCase("SHA256") ||
				oid.equals(AlgorithmIdentifier.SHA256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
		} else if(oid.equalsIgnoreCase("SHA-384") ||
				oid.equalsIgnoreCase("SHA384") ||
				oid.equals(AlgorithmIdentifier.SHA384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA384_OID);
		} else if(oid.equalsIgnoreCase("SHA-512") ||
				oid.equalsIgnoreCase("SHA512") ||
				oid.equals(AlgorithmIdentifier.SHA512_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_OID);
		} else if(oid.equalsIgnoreCase("SHA-512/224") ||
				oid.equalsIgnoreCase("SHA512/224") ||
				oid.equals(AlgorithmIdentifier.SHA512_224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_224_OID);
		} else if(oid.equalsIgnoreCase("SHA-512/256") ||
				oid.equalsIgnoreCase("SHA512/256") ||
				oid.equals(AlgorithmIdentifier.SHA512_256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_256_OID);
		} else if(oid.equalsIgnoreCase("SHA3-224") || 
				oid.equals(AlgorithmIdentifier.SHA3_224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_224_OID);
		} else if(oid.equalsIgnoreCase("SHA3-256") || 
				oid.equals(AlgorithmIdentifier.SHA3_256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_256_OID);
		} else if(oid.equalsIgnoreCase("SHA3-384") || 
				oid.equals(AlgorithmIdentifier.SHA3_384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_384_OID);
		} else if(oid.equalsIgnoreCase("SHA3-512") || 
				oid.equals(AlgorithmIdentifier.SHA3_512_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_512_OID);
		} else if(oid.equalsIgnoreCase("SM3") || 
				oid.equals(AlgorithmIdentifier.SM3_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SM3_OID);
		} else {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(oid);
		}
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
		} else if(extOid.equals(Extension.CRLDISTRIBUTIONPOINTS_OID)) {
			return createCRLDistributionPoints(critical,item);
		} else if(extOid.equals(Extension.AC_AUDITIDENTITY_OID)) {
			return createAuditIdentity(critical,item);
		} else if(extOid.equals(Extension.AUTHORITYINFOACCESS_OID)) {
			return createAuthorityInfoAccess(critical,item);
		} else if(extOid.equals(Extension.NOREVAVAIL_OID)) {
			return createNoRevAvail(critical,item);
		} else if(extOid.equals(Extension.TARGETINFOMATION_OID)) {
			return createACTargeting(critical,item);
		} else if(extOid.equals(Extension.AC_PROXYING_OID)) {
			return createProxying(critical,item);
		} else{
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

	private static String getExtensionOid(String name) {
		if(name.equalsIgnoreCase("Authority Key Identifier")) {
			return Extension.AUTHORITY_KEYIDENTIFIER_OID;
		} else if(name.equalsIgnoreCase("CRL Distribution Points")) {
			return Extension.CRLDISTRIBUTIONPOINTS_OID;
		} else if(name.equalsIgnoreCase("Freshest CRL")) {
			return Extension.FRESHESTCRL_OID;
		} else if(name.equalsIgnoreCase("Authority Information Access")) {
			return Extension.AUTHORITYINFOACCESS_OID;
		} else if(name.equalsIgnoreCase("Audit Identity")) {
			return Extension.AC_AUDITIDENTITY_OID;
		} else if(name.equalsIgnoreCase("AC Targeting") ||
				 name.equalsIgnoreCase("target information")) {
			return Extension.TARGETINFOMATION_OID;
		} else if(name.equalsIgnoreCase("No Revocation Available") || 
				name.equalsIgnoreCase("noRevAvail")) {
			return Extension.NOREVAVAIL_OID;
		} else if(name.equalsIgnoreCase("Proxying") || 
				name.equalsIgnoreCase("ProxyInfo")) {
			return Extension.AC_PROXYING_OID;
		} else {
			return name;
		}
	}

	private static Extension createOctetStringExtension(boolean critical,JSON octValue,String extOid,String extName)throws Exception {
		if(octValue instanceof JSONString) {
			String hexValue=((JSONString)octValue).getString();
			byte[] value=Hex.decode(hexValue);
			return new Extension(extOid,critical,new OctetStringExtension(value));
		} else{
			throw new Exception(extName + "错误");
		} 
		
	}
	
	private static Extension createAuditIdentity(boolean critical,JSON octValue)throws Exception {
		return createOctetStringExtension(critical,octValue,Extension.AC_AUDITIDENTITY_OID,"Audit Identity");
	}
	private static Extension createCRLDistributionPoints(boolean critical,JSON crldpsValue)throws Exception {
		return  createCRLDistributionPoints(critical,crldpsValue,Extension.CRLDISTRIBUTIONPOINTS_OID,"CRL发布点扩展模板");
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
	
	private static Extension createNoRevAvail(boolean critical,JSON value)throws Exception {
		if(value instanceof JSONString) {
			return createDefaultExtension(Extension.NOREVAVAIL_OID,critical,(JSONString)value);
		} else if(value==null || value instanceof JSONNull) {
			return new Extension(Extension.NOREVAVAIL_OID,critical,new NullExtension());
		} else {
			throw new Exception("noRevAvail扩展错误");
		}
		
	}
	
	private static Extension createACTargeting(boolean critical,JSON value)throws Exception {
		return createTargetingInformation(critical,Extension.TARGETINFOMATION_OID,value,"AC Targeting模板");
	}
	
	private static Extension createProxying(boolean critical,JSON value)throws Exception {
		return createTargetingInformation(critical,Extension.AC_PROXYING_OID,value,"Proxying模板");
	}
	
	
	private static Extension createTargetingInformation(boolean critical,String extOid,JSON value,String errMsg)throws Exception {
		if(value instanceof JSONString) {
			return createDefaultExtension(extOid,critical,(JSONString)value);
		} else if(value instanceof JSONArray==false) {
			throw new Exception(errMsg +"错误");
		}
		
		JSONArray targetssArray=(JSONArray)value;
		int count=targetssArray.size();
		
		ArrayList<Targets> list=new ArrayList<Targets>();
		JSON item;
		for(int i=0;i<count;i++){
			item=targetssArray.get(i);
			if (item instanceof JSONArray==false) {
				throw new Exception(errMsg+"模板错误");
			}
			JSONArray targetsArray=(JSONArray)item;
			Targets targets=new Targets();
			Target taget;
			int targetCount=targetsArray.size();
			for(int j=0;j<targetCount;j++) {
				item=targetsArray.get(j);
				if (item instanceof JSONObject==false) {
					throw new Exception(errMsg+"模板错误");
				} 
				taget=createTarget((JSONObject)item,errMsg);
				targets.add(taget);
			}
			list.add(targets);
		}
		return new Extension(extOid,critical,new TargetInformationExtension(list));
	}
	
	
	
	private static Target createTarget(JSONObject value,String errMsg)throws Exception {
		JSON item=value.getValue("type");
		if(item instanceof JSONString==false){
			throw new Exception(errMsg+"错误");
		}
		String typeStr=((JSONString)item).getString();
		int type;
		if(typeStr.equalsIgnoreCase("targetName") || 
				typeStr.equalsIgnoreCase("Name")){
			type=Target.TARGETNAME_TYPE;
		} else if(typeStr.equalsIgnoreCase("targetGroup") || 
				typeStr.equalsIgnoreCase("Group")){
			type=Target.TARGETGROUP_TYPE;
		} else if(typeStr.equalsIgnoreCase("targetCert") || 
				typeStr.equalsIgnoreCase("Cert")){
			type=Target.TARGETCERT_TYPE;
		} else {
			throw new Exception(errMsg+"错误");
		}
		item=value.getValue("value");
		if(item==null){
			throw new Exception(errMsg+"错误");
		}
		
		if(type==Target.TARGETNAME_TYPE || type==Target.TARGETGROUP_TYPE) {
			if(item instanceof JSONObject==false){
				throw new Exception(errMsg+"错误");
			}
			GeneralName gn=createGeneralName((JSONObject)item,errMsg);
			if(type==Target.TARGETNAME_TYPE){
				return Target.NewTargetName(gn);
			} else {
				return Target.NewTargetGroup(gn);
			}
		}
		if(item instanceof JSONObject==false){
			throw new Exception(errMsg+"错误");
		}
		return 	Target.NewTargetCert(createTargetCert((JSONObject)item,errMsg));
	}
	private static TargetCert createTargetCert(JSONObject value,String errMsg)throws Exception {
		IssuerSerial targetCertificate=null;
		JSON item=value.getValue("targetCertificate");
		if(item instanceof JSONString==false) {
			throw new Exception(errMsg+"错误");
		}
		String certFileName=((JSONString)item).getString();
		X509Certificate cert=new X509Certificate(readFile(certFileName));
		targetCertificate=new IssuerSerial(cert);
		GeneralName targetName=null;
		item=value.getValue("targetName");
		if(item!=null){
			if(item instanceof JSONObject==false) {
				throw new Exception(errMsg+"错误");
			}
			targetName=createGeneralName((JSONObject)item,errMsg);
		}
		ObjectDigestInfo certDigestInfo=null;
		item=value.getValue("certDigestInfo");
		if(item!=null){
			if(item instanceof JSONObject==false) {
				throw new Exception(errMsg+"错误");
			}
			certDigestInfo=createObjectDigestInfo((JSONObject)item,errMsg);
		}
		
		return new TargetCert(targetCertificate,targetName,certDigestInfo);
	}
	
	private static ArrayList<Attribute> createAttributes(JSONObject templete)throws Exception {
		JSON item=templete.getValue("attributes");
		if(item==null) {
			return null;
		}
		if(item instanceof JSONArray==false) {
			throw new Exception("属性不是JSON数组");
		}
		JSONArray attrsArray=(JSONArray)item;
		int count=attrsArray.size();
		Attribute attr;
		ArrayList<Attribute> attrs=new ArrayList<Attribute>();		
		for(int i=0;i<count;i++) {
			item=attrsArray.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("属性项不是JSON对象");
			}
			attr=createAttribute((JSONObject)item);
			attrs.add(attr);
		}
				
		return attrs;
	}
	
	private static Attribute createAttribute(JSONObject templete)throws Exception {
		JSON item=templete.getValue("type");
		if(item instanceof JSONString==false){
			throw new Exception("属性项类型不是JSON字符串");
		}
		String typeStr=((JSONString)item).getString();
		String typeOid=getAttributeOid(typeStr);
		item=templete.getValue("values");
		if(item instanceof JSONArray==false){
			throw new Exception("属性项值不是JSON数组");
		}
		ArrayList<ASN1Object>values=new ArrayList<ASN1Object>();
		JSONArray valueArray=(JSONArray)item;
		int count=valueArray.size();
		ASN1Object obj;
		for(int i=0;i<count;i++){
			item=valueArray.get(i);
			obj=createAttributeValue(typeOid,item);
			values.add(obj);
		}
		
		return new Attribute(typeOid,values);
	}
	
	private static String getAttributeOid(String name) {
		if(name.equalsIgnoreCase("Service Authentication Information")){
			return Attribute.SERVICE_AUTH_INFO;
		} else if(name.equalsIgnoreCase("Access Identity")){
			return Attribute.ACCESS_IDENTITY;
		} else if(name.equalsIgnoreCase("Charging Identity")){
			return Attribute.CHARGING_IDENTITY;
		} else if(name.equalsIgnoreCase("Group")){
			return Attribute.GROUP;
		} else if(name.equalsIgnoreCase("Role")){
			return Attribute.ROLE;
		} else if(name.equalsIgnoreCase("Clearance")){
			return Attribute.CLEARANCE;
		} else if(name.equalsIgnoreCase("RFC3281 Clearance")){
			return Attribute.RFC3281_CLEARANCE;
		} else if(name.equalsIgnoreCase("Encrypt Attribute")){
			return Attribute.ENC_ATTRS;
		} else {
			return name;
		}
	}
	
	private static ASN1Object createAttributeValue(String oid,JSON templete)throws Exception {
		if(oid.equals(Attribute.SERVICE_AUTH_INFO)){
			return createServiceAuthenticationInformation(templete);
		} else if(oid.equals(Attribute.ACCESS_IDENTITY)){
			return createAccessIdentity(templete);
		} else if(oid.equals(Attribute.CHARGING_IDENTITY)){
			return createChargingIdentity(templete);
		} else if(oid.equals(Attribute.GROUP)){
			return createGroup(templete);
		} else if(oid.equals(Attribute.ROLE)){
			return createRoleSyntax(templete);
		} else if(oid.equals(Attribute.CLEARANCE)){
			return createClearance(templete);
		} else if(oid.equals(Attribute.RFC3281_CLEARANCE)){
			return createRFC3281Clearance(templete);
		} else {
			if(templete instanceof JSONString==false){
				throw new Exception("Atrribute "+oid+ " 出错");
			}
			return createDefaultAttribute((JSONString)templete);
		}
	}
	
	private static ASN1Object createSvceAuthInfo(JSON templete,String msgErr)throws Exception {
		if(templete instanceof JSONString){
			return createDefaultAttribute((JSONString)templete);
		}
		
		if(templete instanceof JSONObject==false){
			throw new Exception(msgErr+" 出错");
		}
		JSONObject obj=(JSONObject)templete;
		JSON item=obj.getValue("service");
		if(item instanceof JSONObject==false){
			throw new Exception(msgErr+" 出错");
		}
		GeneralName service=createGeneralName((JSONObject)item,msgErr);
		item=obj.getValue("ident");
		if(item instanceof JSONObject==false){
			throw new Exception(msgErr+" 出错");
		}
		GeneralName ident=createGeneralName((JSONObject)item,msgErr);
		byte[] authInfo=null;
		item=obj.getValue("authInfo");
		if(item!=null){
			if(item instanceof JSONString==false){
				throw new Exception(msgErr+" 出错");
			}
			String hexValue=((JSONString)item).getString();
			authInfo=Hex.decode(hexValue);
		}
		return (new SvceAuthInfo(service,ident,authInfo)).getASN1Object();
	}
	
	private static ASN1Object createDefaultAttribute(JSONString str) throws Exception {
		String hexValue=((JSONString)str).getString();
		byte[] value=Hex.decode(hexValue);
				
		return ASN1Object.decode(value, AnyType.getInstance());
	}

	private static ASN1Object createServiceAuthenticationInformation(JSON templete)throws Exception {
		return createSvceAuthInfo(templete,"Service Authentication Information");
	}
	
	private static ASN1Object createAccessIdentity(JSON templete)throws Exception {
		return createSvceAuthInfo(templete,"Access Identity");
	}
	
	private static ASN1Object createIetfAttrSyntax(JSON templete,String msgErr)throws Exception {
		if(templete instanceof JSONString){
			return createDefaultAttribute((JSONString)templete);
		}
		
		if(templete instanceof JSONObject==false){
			throw new Exception(msgErr+" 出错");
		}
		JSONObject obj=(JSONObject)templete;
		JSON item=obj.getValue("policyAuthority");
		GeneralNames policyAuthority=null;
		if(item!=null){
			if(item instanceof JSONArray==false){
				throw new Exception(msgErr+" 出错");
			}
			policyAuthority=createGeneralNames((JSONArray)item,msgErr);
		}
		item=obj.getValue("values");
		if(item instanceof JSONArray==false){
			throw new Exception(msgErr+" 出错");
		}
		JSONArray valueArray=(JSONArray)item;
		int count=valueArray.size();
		IetfAttrSyntaxValue ietfAttrSyntaxValue;
		ArrayList<IetfAttrSyntaxValue> ietfAttrSyntaxValues=new ArrayList<IetfAttrSyntaxValue>();
		for(int i=0;i<count;i++){
			item=valueArray.get(i);
			if(item instanceof JSONObject==false){
				throw new Exception(msgErr+" 出错");
			}
			obj=(JSONObject)item;
			item=obj.getValue("type");
			if(item instanceof JSONString==false){
				throw new Exception(msgErr+" 出错");
			}
			String typeStr=((JSONString)item).getString();
			item=obj.getValue("value");
			if(item instanceof JSONString==false){
				throw new Exception(msgErr+" 出错");
			}
			String valueStr=((JSONString)item).getString();
			if(typeStr.equalsIgnoreCase("octets")){
				ietfAttrSyntaxValue=IetfAttrSyntaxValue.NewOctets(Hex.decode(valueStr));
			} else if(typeStr.equalsIgnoreCase("oid")){
				ietfAttrSyntaxValue=IetfAttrSyntaxValue.NewOid(valueStr);
			} else if(typeStr.equalsIgnoreCase("string")){
				ietfAttrSyntaxValue=IetfAttrSyntaxValue.NewString(valueStr);
			} else {
				throw new Exception(msgErr+" 出错");
			}
			ietfAttrSyntaxValues.add(ietfAttrSyntaxValue);
		}
		
		return (new IetfAttrSyntax(policyAuthority,ietfAttrSyntaxValues)).getASN1Object();
	}

	private static ASN1Object createChargingIdentity(JSON templete)throws Exception {
		return createIetfAttrSyntax(templete,"Charging Identity");
	}
	
	private static ASN1Object createGroup(JSON templete)throws Exception {
		return createIetfAttrSyntax(templete,"Group");
	}
	
	private static ASN1Object createRoleSyntax(JSON templete)throws Exception {
		if(templete instanceof JSONString){
			return createDefaultAttribute((JSONString)templete);
		}
		
		if(templete instanceof JSONObject==false){
			throw new Exception("Role属性出错");
		}
		JSONObject obj=(JSONObject)templete;
		JSON item=obj.getValue("roleAuthority");
		GeneralNames roleAuthority=null;
		if(item!=null){
			if(item instanceof JSONArray==false){
				throw new Exception("Role属性出错");
			}
			roleAuthority=createGeneralNames((JSONArray)item,"Role属性");
		}
		item=obj.getValue("roleName");
		if(item instanceof JSONObject==false){
			throw new Exception("Role属性出错");
		}
		GeneralName roleName=createGeneralName((JSONObject)item,"Role属性");
		
		return (new RoleSyntax(roleAuthority,roleName)).getASN1Object();
	}
	
	private static ASN1Object createRFC3281Clearance(JSON templete)throws Exception {
		if(templete instanceof JSONString){
			return createDefaultAttribute((JSONString)templete);
		}
		
		if(templete instanceof JSONObject==false){
			throw new Exception("RFC3281 Clearance属性出错");
		}
		JSONObject obj=(JSONObject)templete;
		JSON item=obj.getValue("policyId");
		String policyId;
		if(item instanceof JSONString==false){
			throw new Exception("RFC3281 Clearance属性出错");
		}
		policyId=((JSONString)item).getString();
		BitString classList=new BitString(new boolean[]{false,true});
		item=obj.getValue("classList");
		if(item!=null){
			if(item instanceof JSONArray==false){
				throw new Exception("RFC3281 Clearance属性出错");
			}
			classList=createClassList((JSONArray)item);
		}
		item=obj.getValue("securityCategories");
		ArrayList<SecurityCategory> list=null;
		if(item!=null){
			if(item instanceof JSONArray==false){
				throw new Exception("RFC3281 Clearance属性出错");
			}
			list=createSecurityCategories((JSONArray)item);
		}
		return (new RFC3281Clearance(policyId,classList,list)).getASN1Object();
	}
	
	
	private static ASN1Object createClearance(JSON templete)throws Exception {
		if(templete instanceof JSONString){
			return createDefaultAttribute((JSONString)templete);
		}
		
		if(templete instanceof JSONObject==false){
			throw new Exception("Clearance属性出错");
		}
		JSONObject obj=(JSONObject)templete;
		JSON item=obj.getValue("policyId");
		String policyId;
		if(item instanceof JSONString==false){
			throw new Exception("Clearance属性出错");
		}
		policyId=((JSONString)item).getString();
		BitString classList=new BitString(new boolean[]{false,true});
		item=obj.getValue("classList");
		if(item!=null){
			if(item instanceof JSONArray==false){
				throw new Exception("Clearance属性出错");
			}
			classList=createClassList((JSONArray)item);
		}
		item=obj.getValue("securityCategories");
		ArrayList<SecurityCategory> list=null;
		if(item!=null){
			if(item instanceof JSONArray==false){
				throw new Exception("Clearance属性出错");
			}
			list=createSecurityCategories((JSONArray)item);
		}
		return (new Clearance(policyId,classList,list)).getASN1Object();
	}
	
	private static BitString createClassList(JSONArray classList)throws Exception {
		
		int count=classList.size();
		
		JSON item;
		int bitsCount=count>6?count:6;
		boolean[] bits=new boolean[bitsCount];
		for(int i=0;i<bitsCount;i++) {
			bits[i]=false;
		}
		String str;
		for(int i=0;i<count;i++) {
			item=classList.get(i);
			if (item instanceof JSONBoolean) {
				bits[i]=((JSONBoolean)item).isTrue();
				continue;
			} else if (item instanceof JSONString==false) {
				throw new Exception("ClassList模板出错");
			}
			str=((JSONString)item).getString();
			if(str.equalsIgnoreCase("unmarked")){
				bits[0]=true;
			} else if(str.equalsIgnoreCase("unclassified")){
				bits[1]=true;
			} else if(str.equalsIgnoreCase("restricted")){
				bits[2]=true;
			} else if(str.equalsIgnoreCase("confidential")){
				bits[3]=true;
			} else if(str.equalsIgnoreCase("secret")){
				bits[4]=true;
			} else if(str.equalsIgnoreCase("topSecret")){
				bits[5]=true;
			}
		}
		
		return new BitString(bits);
	}
	
	private static ArrayList<SecurityCategory> createSecurityCategories(JSONArray templete)throws Exception {
		ArrayList<SecurityCategory> list=new ArrayList<SecurityCategory>();
		int count=templete.size();
		JSON item;
		SecurityCategory securityCategory;
		for(int i=0;i<count;i++){
			item=templete.get(i);
			if(item instanceof JSONObject==false){
				throw new Exception("SecurityCategory出错");
			}
			securityCategory=createSecurityCategory((JSONObject)item);
			list.add(securityCategory);
		}
		return list;
	}
	
	private static SecurityCategory createSecurityCategory(JSONObject templete)throws Exception {
		JSON item;
		
		item=templete.getValue("type");
		if(item instanceof JSONString==false){
			throw new Exception("SecurityCategory出错");
		}
		String type=((JSONString)item).getString();
		item=templete.getValue("value");
		if(item instanceof JSONString==false){
			throw new Exception("SecurityCategory出错");
		}
		String value=((JSONString)item).getString();
		ASN1Object asn1Value=ASN1Object.decode(Util.HexDecode(value), AnyType.getInstance());
		return new SecurityCategory(type, asn1Value);
	}
	
}
