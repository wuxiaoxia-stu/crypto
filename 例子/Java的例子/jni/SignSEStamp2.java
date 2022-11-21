import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONBoolean;
import net.netca.pki.encoding.json.JSONNumber;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
import net.netca.pki.SEStamp;
import net.netca.pki.Signature;
import net.netca.pki.Util;
import net.netca.pki.Hash;
import net.netca.pki.KeyPair;
import net.netca.pki.Base64;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Date;

import net.netca.pki.Certificate;

public class SignSEStamp2 {

	public static void main(String[] args) throws Exception {
		if(args.length!=4) {
            System.out.println("Usage: java SignSEStamp2 issuerCertFileName pwd templateFileName stampFileName");
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
		
		SEStamp stamp=null;
		Certificate signCert=null;
		KeyPair keypair=null;
		try {
			int format=getFormat(jsonObject);
			stamp=new SEStamp(format);
			if(format==SEStamp.GMT_0031){
				int version=getVersion(jsonObject);
				stamp.setVersion(version);
			}
			String vid=getVid(jsonObject);
			stamp.setVid(vid);
			String id=getId(jsonObject);
			stamp.setId(id);
			int type=getType(jsonObject);
			stamp.setType(type);
			String name=getName(jsonObject);
			stamp.setName(name);
			addCerts(stamp,jsonObject);
			
			Date now=new Date();
			Date createDate=getCreateDate(jsonObject);
			if(createDate==null) {
				createDate=now;
			}
			stamp.setCreateDate(createDate);
			
			Date validStart=getValidStart(jsonObject);
			if(validStart==null) {
				validStart=now;
			}
			stamp.setValidStart(validStart);
			
			
			Date validEnd=getValidEnd(jsonObject);
			stamp.setValidEnd(validEnd);
			
			String pictureType=getPictureType(jsonObject);
			byte[] pictureData=getPictureData(jsonObject);
			int pictureWidth=getPictureWidth(jsonObject);
			int pictureHeigth=getPictureHeigth(jsonObject);
			stamp.setPicture(pictureType, pictureData, pictureWidth, pictureHeigth);
			
			addExtDatas(stamp,jsonObject);
			int signAlgo=getSignatureAlgorithm(jsonObject);
			
			signCert=getCert(issuerCertFileName);
						
			keypair=signCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取制章人证书的私钥失败");
	            return;
			}
			byte[] stampEncode=stamp.sign(signAlgo, signCert);
			writeFile(stampFileName,stampEncode);
	        System.out.println("Success");
		} finally {
			if(signCert!=null){
				signCert.free();
			}
			if(keypair!=null) {
				keypair.free();
			}
			if(stamp!=null) {
				stamp.free();
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
	
	private static void addExtData(SEStamp stamp,JSONObject jsonObject)throws Exception{
		JSON item=jsonObject.getValue("extnID");
		if(item instanceof JSONString==false) {
			throw new Exception("扩展OID项不是JSON字符串");
		}
		String extOid=((JSONString)item).getString();
				
		boolean critical=false;
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
		stamp.addExtension(extOid, critical, value);
	}
	private static void addExtDatas(SEStamp stamp,JSONObject jsonObject)throws Exception{
		
		JSON json=jsonObject.getValue("exts");
		if(json==null) {
			return ;
		}
		if(json instanceof JSONArray==false) {
			throw new Exception("bad exts");
		}
		JSONArray jsonArray=(JSONArray)json;
		JSONObject jsonExt;
		
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
			addExtData(stamp,jsonExt);
			
		}
		
	}
	
	private static int getSignatureAlgorithm(String name) throws Exception {
		String upperName=name.toUpperCase();
		if(upperName.equals("SHA1WITHRSA") || upperName.equals("SHA-1WITHRSA") || upperName.equals("SHA1WITHRSAENCRYPTION")|| upperName.equals("1.2.840.113549.1.1.5")) {
			return Signature.SHA1WITHRSA;
		} else if(upperName.equals("SHA224WITHRSA") || upperName.equals("SHA224WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.14")) {
			return Signature.SHA224WITHRSA;
		} else if(upperName.equals("SHA256WITHRSA") || upperName.equals("SHA256WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.11")) {
			return Signature.SHA256WITHRSA;
		} else if(upperName.equals("SHA384WITHRSA") || upperName.equals("SHA384WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.12")) {
			return Signature.SHA384WITHRSA;
		} else if(upperName.equals("SHA512WITHRSA") || upperName.equals("SHA512WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.13")) {
			return Signature.SHA512WITHRSA;
		} else if(upperName.equals("MD5WITHRSA") || upperName.equals("MD5WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.4")) {
			return Signature.MD5WITHRSA;
		} else if(upperName.equals("SHA512/224WITHRSA") || upperName.equals("SHA512/224WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.15")) {
			return Signature.SHA512_224WITHRSA;
		} else if(upperName.equals("SHA512/256WITHRSA") || upperName.equals("SHA512/256WITHRSAENCRYPTION") || upperName.equals("1.2.840.113549.1.1.16")) {
			return Signature.SHA512_256WITHRSA;
		} else if(upperName.equals("SHA3-224WITHRSA") || upperName.equals("SHA3-224WITHRSAENCRYPTION") || upperName.equals("2.16.840.1.101.3.4.3.13")) {
			return Signature.SHA3_224WITHRSA;
		} else if(upperName.equals("SHA3-256WITHRSA") || upperName.equals("SHA3-256WITHRSAENCRYPTION") || upperName.equals("2.16.840.1.101.3.4.3.14")) {
			return Signature.SHA3_256WITHRSA;
		} else if(upperName.equals("SHA3-384WITHRSA") || upperName.equals("SHA3-384WITHRSAENCRYPTION") || upperName.equals("2.16.840.1.101.3.4.3.15")) {
			return Signature.SHA3_384WITHRSA;
		} else if(upperName.equals("SHA3-512WITHRSA") || upperName.equals("SHA3-512WITHRSAENCRYPTION") || upperName.equals("2.16.840.1.101.3.4.3.16")) {
			return Signature.SHA3_512WITHRSA;
		} else if(upperName.equals("SM3WITHSM2") ||  upperName.equals("1.2.156.10197.1.501")) {
			return Signature.SM3WITHSM2;
		} else if(upperName.equals("ECDSAWITHSHA1") ||  upperName.equals("1.2.840.10045.4.1")) {
			return Signature.ECDSAWITHSHA1;
		} else if(upperName.equals("ECDSAWITHSHA224") ||  upperName.equals("1.2.840.10045.4.3.1")) {
			return Signature.ECDSAWITHSHA224;
		} else if(upperName.equals("ECDSAWITHSHA256") ||  upperName.equals("1.2.840.10045.4.3.2")) {
			return Signature.ECDSAWITHSHA256;
		} else if(upperName.equals("ECDSAWITHSHA384") ||  upperName.equals("1.2.840.10045.4.3.3")) {
			return Signature.ECDSAWITHSHA384;
		} else if(upperName.equals("ECDSAWITHSHA512") ||  upperName.equals("1.2.840.10045.4.3.4")) {
			return Signature.ECDSAWITHSHA512;
		} else if(upperName.equals("ECDSAWITHSHA3-224") ||  upperName.equals("2.16.840.1.101.3.4.3.9")) {
			return Signature.ECDSAWITHSHA3_224;
		} else if(upperName.equals("ECDSAWITHSHA3-256") ||  upperName.equals("2.16.840.1.101.3.4.3.10")) {
			return Signature.ECDSAWITHSHA3_256;
		} else if(upperName.equals("ECDSAWITHSHA3-384") ||  upperName.equals("2.16.840.1.101.3.4.3.11")) {
			return Signature.ECDSAWITHSHA3_384;
		} else if(upperName.equals("ECDSAWITHSHA3-512") ||  upperName.equals("2.16.840.1.101.3.4.3.12")) {
			return Signature.ECDSAWITHSHA3_384;
		} 
		throw new Exception("bad sign algo");
	}
	private static int getSignatureAlgorithm(JSONObject jsonObject)throws Exception{
		JSON json=jsonObject.getValue("signAlgo");
		if(json instanceof JSONString==false) {
			throw new Exception("bad signAlgo");
		}
		JSONString jsonString=(JSONString)json;
		return getSignatureAlgorithm(jsonString.getString()); 
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
		return Base64.decode(0,jsonString.getString());
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
	
	
	private static int getHashAlgo(String algo)throws Exception{
		algo=algo.toUpperCase();
		if(algo.equals("SHA1")|| algo.equals("SHA-1")|| algo.equals("1.3.14.3.2.26")){
			return Hash.SHA1;
		} else if(algo.equals("SHA224")|| algo.equals("SHA-224")|| algo.equals("2.16.840.1.101.3.4.2.4")){
			return Hash.SHA224;
		} else if(algo.equals("SHA256")|| algo.equals("SHA-256")|| algo.equals("2.16.840.1.101.3.4.2.1")){
			return Hash.SHA256;
		} else if(algo.equals("SHA384")|| algo.equals("SHA-384")|| algo.equals("2.16.840.1.101.3.4.2.2")){
			return Hash.SHA384;
		} else if(algo.equals("SHA512")|| algo.equals("SHA-512")|| algo.equals("2.16.840.1.101.3.4.2.3")){
			return Hash.SHA512;
		} else if(algo.equals("MD5")|| algo.equals("1.2.840.113549.2.5")){
			return Hash.MD5;
		} else if(algo.equals("SHA512/224")|| algo.equals("SHA-512/224") || algo.equals("2.16.840.1.101.3.4.2.5")){
			return Hash.SHA512_224;
		} else if(algo.equals("SHA512/256")|| algo.equals("SHA-512/256") || algo.equals("2.16.840.1.101.3.4.2.6")){
			return Hash.SHA512_256;
		} else if(algo.equals("SHA3-224")|| algo.equals("2.16.840.1.101.3.4.2.7")){
			return Hash.SHA3_224;
		} else if(algo.equals("SHA3-256")|| algo.equals("2.16.840.1.101.3.4.2.8")){
			return Hash.SHA3_256;
		} else if(algo.equals("SHA3-384")|| algo.equals("2.16.840.1.101.3.4.2.9")){
			return Hash.SHA3_384;
		} else if(algo.equals("SHA3-512")|| algo.equals("2.16.840.1.101.3.4.2.10")){
			return Hash.SHA3_512;
		} else if(algo.equals("SM3")|| algo.equals("1.2.156.10197.1.401")){
			return Hash.SM3;
		} else {
			throw new Exception("bad hash algo");
		}
	}
	
	private static void addCerts(SEStamp stamp,JSONObject jsonObject)throws Exception{
		
		JSON json=jsonObject.getValue("useCertDigest");
		boolean useCertDigest=false;
		int hashAlgo=-1;
		if(json!=null){
			if(json instanceof JSONBoolean){
				useCertDigest=((JSONBoolean)json).isTrue();
			} else {
				throw new Exception("bad useCertDigest");
			}
		}
		if(useCertDigest){
			json=jsonObject.getValue("certDigestAlgo");
			if(json instanceof JSONString==false) {
				throw new Exception("bad certDigestAlgo");
			}
			hashAlgo=getHashAlgo(((JSONString)json).getString());
		}
		
		json=jsonObject.getValue("certs");
		if(json instanceof JSONArray==false) {
			throw new Exception("bad certs");
		}
		JSONArray jsonArray=(JSONArray)json;
		JSONString jsonString;
		Certificate cert;
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
			cert=null;
			try{
				cert=new Certificate(jsonString.getString());
				if(useCertDigest){
					stamp.addCertDigest(hashAlgo, cert);
				} else {
					stamp.addCert(cert);
				}
			}finally{
				if(cert!=null){
					cert.free();
				}
			}
			
		}

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
