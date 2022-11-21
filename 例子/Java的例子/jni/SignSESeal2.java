import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.util.Date;
import net.netca.pki.SEStamp;
import net.netca.pki.Signature;
import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.SESeal;
import net.netca.pki.Hash;

public class SignSESeal2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=5) {
            System.out.println("Usage: java SignSESeal2 signCertFileName pwd tbsFileName stampFileName sealFileName");
            return;
        }
		String signCertFileName=args[0];
		String pwd=args[1];
		String tbsFileName=args[2];
		String stampFileName=args[3];
		String sealFileName=args[4];
		
		int version=17; //随便写一个
		Date now=new Date();
		String propertyInfo="sign file";
		
		SESeal seal=null;
		SEStamp stamp=new SEStamp(readFile(stampFileName));
		KeyPair keypair=null;
		Certificate signCert=null;
		try {
			if(stamp.verify()==false) {
				System.out.println("验证电子印章失败");
				return;
			}
			int format=stamp.getFormat();
			seal=new SESeal(format);
			byte[] certData=readFile(signCertFileName);
			signCert=new Certificate(certData);
			if(isCertInStamp(stamp,signCert)==false) {
				System.out.println("签名证书不在印章中");
				return;
			}
					
			int signAlgo=getSignAlgorithm(signCert);
			int hashAlgo=SESeal.getHashAlgorithmFromSignAlgorithm(signAlgo);
			byte[] hashValue=hashFile(hashAlgo,tbsFileName);
		
		
		
			keypair=signCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取签名证书的私钥失败");
	            return;
			}
			if(format==SESeal.GMT_0031){
				seal.setVersion(version);
			} else {
				seal.setVersion(stamp.getVersion());
			}
			seal.setStamp(stamp);
			seal.setTime(now);
			seal.setProperty(propertyInfo);
			seal.setDataHash(hashValue);
			byte[] sealEncode=seal.sign(signAlgo, signCert);
			writeFile(sealFileName,sealEncode);
	        System.out.println("Success");
		} finally {
			if(signCert!=null){
				signCert.free();
			}
			if(keypair!=null) {
				keypair.free();
			}
			if(seal!=null) {
				seal.free();
			}
			stamp.free();
		}

	}
	
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
	
	private static byte[] hashFile(int hashAlgo,String fileName) throws Exception{
		FileInputStream fIn=new FileInputStream(fileName);
		byte[] data=new byte[8192];
		int length;
		Hash hash=null;
		try {
			hash=new Hash(hashAlgo);
			for(;;) {
				length=fIn.read(data);
				if(length==-1) {
					break;
				}
				hash.update(data, 0, length);
			}
			return hash.doFinal();
		}finally {
			if(hash!=null){
				hash.free();
			}
			fIn.close();
		}
	}

	private static int getSignAlgorithm(Certificate signCert)throws Exception{
		if(signCert.match("Algorithm='SM2'")) {
			return Signature.SM3WITHSM2;
		} else if(signCert.match("Algorithm='RSA'")) {
			return Signature.SHA256WITHRSA;
		} else {
			throw new Exception("不支持该证书");
		}
	}
	
	private static boolean isCertInStamp(SEStamp stamp,Certificate signCert)throws Exception{
		byte[] derCert=signCert.derEncode();
		int certlistType=stamp.getCertListType();
		int count;
		if(certlistType==SEStamp.CERTLIST_TYPE_CERT){
			count=stamp.getCertCount();
			Certificate cert;
			for(int i=0;i<count;i++){
				cert=stamp.getCert(i);
				if(cert!=null){
					try{
						byte[] derCert2=cert.derEncode();
						if(Arrays.equals(derCert2, derCert)){
							return true;
						}
					} finally{
						cert.free();
					}
				}
			}
			return false;
		}else {
			count=stamp.getCertDigestCount();
			for(int i=0;i<count;i++){
				String type=stamp.getCertDigestType(i);
				byte[] hashValue=stamp.getCertDigestValue(i);
				byte[] hashValue2=hash(type,derCert);
				if(Arrays.equals(hashValue, hashValue2)){
					return true;
				}
			}
			return false;
		}
		
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
	private static byte[] hash(String type,byte[] data)throws Exception{
		int algo=getHashAlgo(type);
		return Hash.computeHash(algo, data);
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
