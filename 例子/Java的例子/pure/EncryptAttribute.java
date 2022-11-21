import java.io.*;
import java.util.ArrayList;

import net.netca.pki.encoding.asn1.pmi.EncryptAttributeBuilder;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntax;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntaxValue;
import net.netca.pki.encoding.asn1.pmi.RFC3281Clearance;
import net.netca.pki.encoding.asn1.pmi.RoleSyntax;
import net.netca.pki.encoding.asn1.pmi.SecurityCategory;
import net.netca.pki.encoding.asn1.pmi.SvceAuthInfo;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONBoolean;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
import net.netca.pki.encoding.asn1.pmi.AttributeCertificateBuilder;
import net.netca.pki.encoding.asn1.pmi.Clearance;
import net.netca.pki.encoding.asn1.pki.JCESecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.JCESymEncrypter;
import net.netca.pki.encoding.asn1.pki.OtherName;
import net.netca.pki.encoding.asn1.pki.RelativeDistinguishedName;
import net.netca.pki.encoding.asn1.pki.X500Name;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.EnvelopedDataBuilder;
import net.netca.pki.encoding.asn1.pki.cms.RecipientIdentifier;
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
import net.netca.pki.encoding.asn1.pki.Attribute;
import net.netca.pki.encoding.asn1.pki.AttributeTypeAndValue;
import net.netca.pki.encoding.asn1.pki.GeneralName;
import net.netca.pki.encoding.asn1.pki.GeneralNames;
import net.netca.pki.encoding.asn1.pki.JCEPublicKeyEncrypter;

public class EncryptAttribute {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java EncryptAttribute attrFileName outFileName");
            return;
        }
		
		JSON templateJson=getJsonFromFile(args[0]);
		if (templateJson instanceof JSONObject==false) {
			System.out.println("模板文件不是JSON对象");
            return;
		}
		X509Certificate x509IssuerCert=getIssuerCert((JSONObject)templateJson);
		AttributeCertificateBuilder attrCertBuilder=AttributeCertificateBuilder.create(x509IssuerCert);
		byte[] sn=getSerialNumber((JSONObject)templateJson);
		attrCertBuilder.setSerialNumber(sn);
		
		EncryptAttributeBuilder encAttrBuilder=new EncryptAttributeBuilder(attrCertBuilder);
		EnvelopedDataBuilder envBuilder=encAttrBuilder.getEnvelopedDataBuilder();
        
        JCESecureRandomGenerator randomGenerator=JCESecureRandomGenerator.getInstance();
        envBuilder.setSecureRandomGenerator(randomGenerator);
        
        JCESymEncrypter symEncrypter=new JCESymEncrypter();
        envBuilder.setSymEncrypter(symEncrypter);
        
        JCEPublicKeyEncrypter publicKeyEncrypter=new JCEPublicKeyEncrypter();
        envBuilder.setPublicKeyEncrypter(publicKeyEncrypter);
        
        int algo=getCekAlgorithm((JSONObject)templateJson);
        envBuilder.setEncryptAlgorithm(algo);
        
        addRecipientInfos(envBuilder,(JSONObject)templateJson);
        
        addAttributes(encAttrBuilder,(JSONObject)templateJson);
        
        byte[] data=encAttrBuilder.encrypt().encode();
        
        String outFileName=args[1];
        writeFile(outFileName,data);
        System.out.println("Success");
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
	
	private static X509Certificate getCert(String certFileName) throws Exception{
		byte[] certData=readFile(certFileName);
		return new X509Certificate(certData);
	}
	
	private static byte[] getSerialNumber(JSONObject templete)throws Exception {
		JSON item=templete.getValue("serialNumber");
		if(item==null) {
			throw new Exception("序列号项不存在");
		}
		
		if(item instanceof JSONString==false) {
			throw new Exception("序列号项不是JSON字符串");
		}
		String hexValue=((JSONString)item).getString();
		
		byte[] value=Hex.decode(hexValue);
		return value;
	}
	
	private static X509Certificate getIssuerCert(JSONObject templete)throws Exception {
		JSON item=templete.getValue("issuerCert");
		if(item==null) {
			throw new Exception("颁发者证书项不存在");
		}
		if(item instanceof JSONString==false) {
			throw new Exception("颁发者证书项不是JSON字符串");
		}
		return getCert(((JSONString)item).getString());
	}
	
	private static int getCekAlgorithm(JSONObject templete)throws Exception {
		JSON item=templete.getValue("cekAlgo");
		if(item==null) {
			throw new Exception("cekAlgo项不存在");
		}
		if(item instanceof JSONString==false) {
			throw new Exception("cekAlgo项不是JSON字符串");
		}
		String str=((JSONString)item).getString();
		return getCekAlgorithm(str);
	}
	
	private static int getCekAlgorithm(String name)throws Exception {
		if(name.equalsIgnoreCase("AES 128 CBC")){
			return EnvelopedDataBuilder.AES_128;
		} else if(name.equalsIgnoreCase("AES 192 CBC")){
			return EnvelopedDataBuilder.AES_192;
		} else if(name.equalsIgnoreCase("AES 256 CBC")){
			return EnvelopedDataBuilder.AES_256;
		} else if(name.equalsIgnoreCase("3DES CBC")
				|| name.equalsIgnoreCase("TDES CBC")){
			return EnvelopedDataBuilder.TDES;
		} else if(name.equalsIgnoreCase("SM1 CBC")){
			return EnvelopedDataBuilder.SM1;
		} else if(name.equalsIgnoreCase("SSF33 CBC")){
			return EnvelopedDataBuilder.SSF33;
		} else if(name.equalsIgnoreCase("SM4 CBC")){
			return EnvelopedDataBuilder.SM4;
		} 
		
		throw new Exception("unknown cek algo "+name);
	}
	
	
	private static void addRecipientInfos(EnvelopedDataBuilder envBuilder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("recipientInfos");
		if(item==null) {
			throw new Exception("recipientInfos项不存在");
		}
		if(item instanceof JSONArray==false) {
			throw new Exception("recipientInfos项不是JSON数组");
		}
		JSONArray recipientInfos=(JSONArray)item;
		int size=recipientInfos.size();
		if(size==0){
			throw new Exception("recipientInfos项为空JSON数组");
		}
		for(int i=0;i<size;i++){
			item=recipientInfos.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("recipientInfos的元素不是JSON对象");
			}
			addRecipientInfo(envBuilder,(JSONObject)item);
		}
	}
	
	private static void addRecipientInfo(EnvelopedDataBuilder envBuilder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("type");
		if(item instanceof JSONString==false) {
			throw new Exception("recipientInfos项出错");
		}
		String type=((JSONString)item).getString();
		if(type.equalsIgnoreCase("ktri")){
			item=templete.getValue("value");
			if(item instanceof JSONObject==false) {
				throw new Exception("recipientInfos项出错");
			}
			addKeyTransRecipientInfo(envBuilder,(JSONObject)item);
			return;
		}
		
		throw new Exception("不支持其他类型的接收者");
	}
	
	private static void addKeyTransRecipientInfo(EnvelopedDataBuilder envBuilder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("cert");
		if(item instanceof JSONString==false) {
			throw new Exception("recipientInfos项出错");
		}
		X509Certificate cert= getCert(((JSONString)item).getString());
		item=templete.getValue("useSubjectKeyIdentifier");
		boolean useSubjectKeyIdentifier=false;
		if(item!=null){
			if(item instanceof JSONBoolean==false) {
				throw new Exception("recipientInfos项出错");
			}
			useSubjectKeyIdentifier=((JSONBoolean)item).isTrue();
		}
		envBuilder.addCert(cert, useSubjectKeyIdentifier?RecipientIdentifier.SUBJECT_KEYID_TYPE:RecipientIdentifier.ISSUER_SN_TYPE);
	}
	
	private static void addAttributes(EncryptAttributeBuilder encAttrBuilder,JSONObject templete)throws Exception {
		JSON item=templete.getValue("attributes");
		if(item==null) {
			throw new Exception("attributes项不存在");
		}
		if(item instanceof JSONArray==false) {
			throw new Exception("attributes项不是JSON数组");
		}
		JSONArray recipientInfos=(JSONArray)item;
		int size=recipientInfos.size();
		if(size==0){
			throw new Exception("attributes项为空JSON数组");
		}
		for(int i=0;i<size;i++){
			item=recipientInfos.get(i);
			if(item instanceof JSONObject==false) {
				throw new Exception("attributes的元素不是JSON对象");
			}
			addAttribute(encAttrBuilder,(JSONObject)item);
		}
	}
	
	private static void addAttribute(EncryptAttributeBuilder encAttrBuilder,JSONObject templete)throws Exception {
		Attribute attr=createAttribute(templete);
		encAttrBuilder.addAttribute(attr);
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
	
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
}
