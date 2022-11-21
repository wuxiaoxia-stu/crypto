import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Date;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONBoolean;
import net.netca.pki.encoding.json.JSONNumber;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.PkiException;
import net.netca.pki.SEStamp;
import net.netca.pki.Util;
import net.netca.pki.encoding.Base64;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.pki.seseal.StampBuilder;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.NetcaSigner;
import net.netca.pki.encoding.asn1.pki.seseal.ExtData;
import net.netca.pki.encoding.asn1.pki.seseal.Stamp;

public class SignSEStamp {

	public static void main(String[] args) throws Exception{
		if(args.length!=4) {
            System.out.println("Usage: java SignSEStamp issuerCertFileName pwd templateFileName stampFileName");
            return;
        }
		String issuerCertFileName=args[0];
		String pwd=args[1];
		String templateFileName=args[2];
		String stampFileName=args[3];
		JSON templateJson=getJsonFromFile(templateFileName);
		if (templateJson instanceof JSONObject==false) {
			System.out.println("模板文件不是JSON对象");
            return;
		}
		JSONObject jsonObject=(JSONObject)templateJson;
		int format=getFormat(jsonObject);
		int version=4;
		if(format!=SEStamp.GBT_38540){
			version=getVersion(jsonObject);
		}
		String vid=getVid(jsonObject);
		String id=getId(jsonObject);
		int type=getType(jsonObject);
		String name=getName(jsonObject);
		
		int certListType=-1;
		if(format==SEStamp.GMT_0031){
			certListType=SEStamp.CERTLIST_TYPE_CERT;
		} else {
			if(getUseCertDigest(jsonObject)){
				certListType=SEStamp.CERTLIST_TYPE_CERTDIGEST;
			} else {
				certListType=SEStamp.CERTLIST_TYPE_CERT;
			}
		}
		AlgorithmIdentifier hashAlgo=null;
		if(certListType==SEStamp.CERTLIST_TYPE_CERTDIGEST){
			hashAlgo=getCertHashAlgorithm(jsonObject);
		}
		
		
		ArrayList<X509Certificate> certs=getCerts(jsonObject);
		Date now=new Date();
		Date createDate=getCreateDate(jsonObject);
		if(createDate==null) {
			createDate=now;
		}
		Date validStart=getValidStart(jsonObject);
		if(validStart==null) {
			validStart=now;
		}
		Date validEnd=getValidEnd(jsonObject);
		String pictureType=getPictureType(jsonObject);
		byte[] pictureData=getPictureData(jsonObject);
		int pictureWidth=getPictureWidth(jsonObject);
		int pictureHeigth=getPictureHeigth(jsonObject);
		ArrayList<ExtData> exts=getExtDatas(jsonObject);
		String signAlgo=getSignatureAlgorithm(jsonObject);
		
		StampBuilder builder=StampBuilder.getInstance(format)
			.setVid(vid)
			.setId(id)
			.setType(type)
			.setName(name)
			.setCreateDate(createDate)
			.setValidStart(validStart)
			.setValidEnd(validEnd)
			.setPicture(pictureType, pictureData, pictureWidth, pictureHeigth);
		if(format!=SEStamp.GBT_38540){
			builder.setVersion(version);
		}
		if(certListType==SEStamp.CERTLIST_TYPE_CERT){
			for(int i=0;i<certs.size();i++) {
				builder.addCert(certs.get(i));
			}
		} else {
			for(int i=0;i<certs.size();i++) {
				builder.addCertDigest(hashAlgo, new JCEHasher(), certs.get(i));
			}
		}
		if(exts!=null) {
			for(int i=0;i<exts.size();i++) {
				builder.addExtension(exts.get(i));
			}
		}
		
		Certificate signCert=getCert(issuerCertFileName);
		KeyPair keypair=null;
		NetcaSigner signer=null;
		try {
			keypair=signCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取制章人证书的私钥失败");
	            return;
			}
			signer=new NetcaSigner(keypair);
			Stamp stamp=builder.sign(new X509Certificate(signCert.derEncode()),
					signer, signAlgo);
			byte[] stampEncode=stamp.getASN1Object().encode();
			writeFile(stampFileName,stampEncode);
	        System.out.println("Success");
		} finally {
			signCert.free();
			if(keypair!=null) {
				keypair.free();
			}
			if(signer!=null) {
				signer.free();
			}
		}
	}
	
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
	
	private static Certificate getCert(String certFileName) throws Exception{
		byte[] certData=readFile(certFileName);
		return new Certificate(certData);
	}
	
	private static boolean getUseCertDigest(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("useCertDigest");
		if(json==null){
			return false;
		}
		if(json instanceof JSONBoolean==false) {
			throw new Exception("bad useCertDigest");
		}
		return ((JSONBoolean)json).isTrue();
		 
	}
	
	private static AlgorithmIdentifier getHashAlgorithmOid(String name) throws PkiException {
		name=name.toUpperCase();
		if(name.equals("SM3") || name.equals(AlgorithmIdentifier.SM3_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3_OID);
		} else if(name.equals("SHA1") || name.equals("SHA-1") || name.equals(AlgorithmIdentifier.SHA1_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
		} else if(name.equals("SHA224") || name.equals("SHA-224") || name.equals(AlgorithmIdentifier.SHA224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA224_OID);
		} else if(name.equals("SHA256") || name.equals("SHA-256") || name.equals(AlgorithmIdentifier.SHA256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
		} else if(name.equals("SHA384") || name.equals("SHA-384") || name.equals(AlgorithmIdentifier.SHA384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA384_OID);
		} else if(name.equals("SHA512") || name.equals("SHA-512") || name.equals(AlgorithmIdentifier.SHA512_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_OID);
		} else if(name.equals("MD5") || name.equals(AlgorithmIdentifier.MD5_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.MD5_OID);
		} else if(name.equals("SHA512/224") || name.equals("SHA-512/224") || name.equals(AlgorithmIdentifier.SHA512_224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_224_OID);
		} else if(name.equals("SHA512/256") || name.equals("SHA-512/256") || name.equals(AlgorithmIdentifier.SHA512_256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_256_OID);
		} else if(name.equals("SHA3-224") || name.equals(AlgorithmIdentifier.SHA3_224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_224_OID);
		} else if(name.equals("SHA3-256") || name.equals(AlgorithmIdentifier.SHA3_256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_256_OID);
		} else if(name.equals("SHA3-384") || name.equals(AlgorithmIdentifier.SHA3_384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_384_OID);
		} else if(name.equals("SHA3-512") || name.equals(AlgorithmIdentifier.SHA3_512_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_512_OID);
		} else {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(name);
		}
	}
	
	private static AlgorithmIdentifier getCertHashAlgorithm(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("certDigestAlgo");
		if(json instanceof JSONString==false) {
			throw new Exception("bad certDigestAlgo");
		}
		JSONString jsonString=(JSONString)json;
		return getHashAlgorithmOid(jsonString.getString()); 
	}
	
	private static ExtData getExtData(JSONObject jsonObject)throws Exception{
		JSON item=jsonObject.getValue("extnID");
		if(item instanceof JSONString==false) {
			throw new Exception("扩展OID项不是JSON字符串");
		}
		String extOid=((JSONString)item).getString();
				
		boolean critical;
		item=jsonObject.getValue("critical");
		if(item==null) {
			critical=false;
		} else if(item instanceof JSONBoolean==false) {
			throw new Exception("扩展关键性项不是JSON布尔值");
		} else {
			critical=((JSONBoolean)item).isTrue();
		}
		item=jsonObject.getValue("extnValue");
		if(item instanceof JSONString==false) {
			throw new Exception("扩展值不是JSON字符串");
		}
		byte[] value=Hex.decode(((JSONString)item).getString());
		return new ExtData(extOid,critical,value);
	}
	private static ArrayList<ExtData> getExtDatas(JSONObject jsonObject)throws Exception{
		ArrayList<ExtData> exts=new ArrayList<ExtData>();
		JSON json=jsonObject.getValue("exts");
		if(json==null) {
			return null;
		}
		if(json instanceof JSONArray==false) {
			throw new Exception("bad exts");
		}
		JSONArray jsonArray=(JSONArray)json;
		JSONObject jsonExt;
		
		ExtData ext;
		int count=jsonArray.size();
		if(count==0) {
			throw new Exception("no ext");
		}
		for(int i=0;i<count;i++) {
			json=jsonArray.get(i);
			if(json instanceof JSONObject==false) {
				throw new Exception("bad exts");
			}
			jsonExt=(JSONObject)json;
			ext=getExtData(jsonExt);
			exts.add(ext);
		}
		return exts;
	}
	
	private static String getSignatureAlgorithmOid(String name) {
		String upperName=name.toUpperCase();
		if(upperName.equals("SHA1WITHRSA")) {
			return AlgorithmIdentifier.SHA1WithRSA_OID;
		} else if(upperName.equals("SHA224WITHRSA")) {
			return AlgorithmIdentifier.SHA224WithRSA_OID;
		} else if(upperName.equals("SHA256WITHRSA")) {
			return AlgorithmIdentifier.SHA256WithRSA_OID;
		} else if(upperName.equals("SHA384WITHRSA")) {
			return AlgorithmIdentifier.SHA384WithRSA_OID;
		} else if(upperName.equals("SHA512WITHRSA")) {
			return AlgorithmIdentifier.SHA512WithRSA_OID;
		} else if(upperName.equals("SHA512/224WITHRSA")) {
			return AlgorithmIdentifier.SHA512_224WithRSA_OID;
		} else if(upperName.equals("SHA512/256WITHRSA")) {
			return AlgorithmIdentifier.SHA512_256WithRSA_OID;
		} else if(upperName.equals("SHA3-224WITHRSA")) {
			return AlgorithmIdentifier.SHA3_224WithRSA_OID;
		} else if(upperName.equals("SHA3-256WITHRSA")) {
			return AlgorithmIdentifier.SHA3_256WithRSA_OID;
		} else if(upperName.equals("SHA3-384WITHRSA")) {
			return AlgorithmIdentifier.SHA3_384WithRSA_OID;
		} else if(upperName.equals("SHA3-512WITHRSA")) {
			return AlgorithmIdentifier.SHA3_512WithRSA_OID;
		} else if(upperName.equals("SM3WITHRSA")) {
			return AlgorithmIdentifier.SM3WithRSA_OID;
		} else if(upperName.equals("SM3WITHSM2")) {
			return AlgorithmIdentifier.SM3WithSM2_OID;
		} else if(upperName.equals("DSAWITHSHA1")) {
			return AlgorithmIdentifier.DSAWithSHA1_OID;
		} else if(upperName.equals("DSAWITHSHA224")) {
			return AlgorithmIdentifier.DSAWithSHA224_OID;
		} else if(upperName.equals("DSAWITHSHA256")) {
			return AlgorithmIdentifier.DSAWithSHA256_OID;
		} else if(upperName.equals("ECDSAWITHSHA1")) {
			return AlgorithmIdentifier.ECDSAWithSHA1_OID;
		} else if(upperName.equals("ECDSAWITHSHA224")) {
			return AlgorithmIdentifier.ECDSAWithSHA224_OID;
		} else if(upperName.equals("ECDSAWITHSHA256")) {
			return AlgorithmIdentifier.ECDSAWithSHA256_OID;
		} else if(upperName.equals("ECDSAWITHSHA384")) {
			return AlgorithmIdentifier.ECDSAWithSHA384_OID;
		} else if(upperName.equals("ECDSAWITHSHA512")) {
			return AlgorithmIdentifier.ECDSAWithSHA512_OID;
		} else if(upperName.equals("ECDSAWITHSHA3-224")) {
			return AlgorithmIdentifier.ECDSAWithSHA3_224_OID;
		} else if(upperName.equals("ECDSAWITHSHA3-256")) {
			return AlgorithmIdentifier.ECDSAWithSHA3_256_OID;
		} else if(upperName.equals("ECDSAWITHSHA3-384")) {
			return AlgorithmIdentifier.ECDSAWithSHA3_384_OID;
		} else if(upperName.equals("ECDSAWITHSHA3-512")) {
			return AlgorithmIdentifier.ECDSAWithSHA3_512_OID;
		} 
		return name;
	}
	private static String getSignatureAlgorithm(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("signAlgo");
		if(json instanceof JSONString==false) {
			throw new Exception("bad signAlgo");
		}
		JSONString jsonString=(JSONString)json;
		return getSignatureAlgorithmOid(jsonString.getString()); 
	}
	private static int getPictureHeigth(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("picture");
		if(json instanceof JSONObject==false) {
			throw new Exception("bad picture");
		}
		JSONObject picture=(JSONObject)json;
		json=picture.getValue("heigth");
		if(json instanceof JSONNumber==false) {
			throw new Exception("bad picture heigth");
		}
		JSONNumber jsonNumber=(JSONNumber)json;
		return jsonNumber.getNumber().intValue();
	}
	
	private static int getPictureWidth(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("picture");
		if(json instanceof JSONObject==false) {
			throw new Exception("bad picture");
		}
		JSONObject picture=(JSONObject)json;
		json=picture.getValue("width");
		if(json instanceof JSONNumber==false) {
			throw new Exception("bad picture width");
		}
		JSONNumber jsonNumber=(JSONNumber)json;
		return jsonNumber.getNumber().intValue();
	}
	
	private static byte[] getPictureData(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("picture");
		if(json instanceof JSONObject==false) {
			throw new Exception("bad picture");
		}
		JSONObject picture=(JSONObject)json;
		json=picture.getValue("data");
		if(json instanceof JSONString==false) {
			throw new Exception("bad picture data");
		}
		JSONString jsonString=(JSONString)json;
		return Base64.decode(true,jsonString.getString());
	}
	
	private static String getPictureType(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("picture");
		if(json instanceof JSONObject==false) {
			throw new Exception("bad picture");
		}
		JSONObject picture=(JSONObject)json;
		json=picture.getValue("type");
		if(json instanceof JSONString==false) {
			throw new Exception("bad picture type");
		}
		JSONString jsonString=(JSONString)json;
		return jsonString.getString();
	}
	
	private static Date getValidEnd(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("validEnd");
		if(json instanceof JSONString==false) {
			throw new Exception("bad validEnd");
		}
		JSONString jsonString;
		jsonString=(JSONString)json;
		return Util.UTCTimeDecode(jsonString.getString().getBytes("UTF-8"));
	}
	
	private static Date getValidStart(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("validStart");
		if(json==null) {
			return null;
		}
		if(json instanceof JSONString==false) {
			throw new Exception("bad validStart");
		}
		JSONString jsonString;
		jsonString=(JSONString)json;
		return Util.UTCTimeDecode(jsonString.getString().getBytes("UTF-8"));
	}
	
	private static Date getCreateDate(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("createDate");
		if(json==null) {
			return null;
		}
		if(json instanceof JSONString==false) {
			throw new Exception("bad createDate");
		}
		JSONString jsonString;
		jsonString=(JSONString)json;
		return Util.UTCTimeDecode(jsonString.getString().getBytes("UTF-8"));
	}
	
	private static ArrayList<X509Certificate> getCerts(JSONObject jsonObject)throws Exception{
		ArrayList<X509Certificate> certs=new ArrayList<X509Certificate>();
		JSON json=jsonObject.getValue("certs");
		if(json instanceof JSONArray==false) {
			throw new Exception("bad certs");
		}
		JSONArray jsonArray=(JSONArray)json;
		JSONString jsonString;
		X509Certificate cert;
		int count=jsonArray.size();
		if(count==0) {
			throw new Exception("no cert");
		}
		for(int i=0;i<count;i++) {
			json=jsonArray.get(i);
			if(json instanceof JSONString==false) {
				throw new Exception("bad certs");
			}
			jsonString=(JSONString)json;
			cert=new X509Certificate(jsonString.getString());
			certs.add(cert);
		}
		return certs;
	}
	private static String getName(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("name");
		if(json instanceof JSONString==false) {
			throw new Exception("bad name");
		}
		return ((JSONString)json).getString();
	}
	
	private static int getType(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("type");
		if(json instanceof JSONNumber==false) {
			throw new Exception("bad type");
		}
		return ((JSONNumber)json).getNumber().intValue();
	}
	
	private static String getVid(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("vid");
		if(json instanceof JSONString==false) {
			throw new Exception("bad vid");
		}
		return ((JSONString)json).getString();
	}
	
	private static int getFormat(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("format");
		if(json==null){
			return SEStamp.GBT_38540;
		}
		if(json instanceof JSONString==false) {
			throw new Exception("bad format");
		}
		String str=((JSONString)json).getString();
		if(str.equals("GB/T 38540")){
			return SEStamp.GBT_38540;
		} else if(str.equals("GM/T 0031")){
			return SEStamp.GMT_0031;
		} else {
			throw new Exception("bad format");
		}
	}
	
	private static int getVersion(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("version");
		if(json instanceof JSONNumber==false) {
			throw new Exception("bad version");
		}
		return ((JSONNumber)json).getNumber().intValue();
	}
	
	private static String getId(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("id");
		if(json instanceof JSONString==false) {
			throw new Exception("bad id");
		}
		return ((JSONString)json).getString();
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
}
