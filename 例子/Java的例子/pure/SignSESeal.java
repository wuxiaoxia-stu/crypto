import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Date;

import net.netca.pki.encoding.asn1.pki.seseal.Stamp;
import net.netca.pki.encoding.asn1.pki.seseal.Seal;
import net.netca.pki.encoding.asn1.pki.seseal.SealBuilder;
import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.NetcaSigner;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Hashable;
import net.netca.pki.encoding.asn1.pki.JCEHasher;

public class SignSESeal {

	public static void main(String[] args) throws Exception{
		if(args.length!=5) {
            System.out.println("Usage: java SignSESeal signCertFileName pwd tbsFileName stampFileName sealFileName");
            return;
        }
		String signCertFileName=args[0];
		String pwd=args[1];
		String tbsFileName=args[2];
		String stampFileName=args[3];
		String sealFileName=args[4];
			
		
		int version=7; //随便写一个
		Date now=new Date();
		String propertyInfo="sign file";
		
		Stamp stamp=Stamp.decode(readFile(stampFileName));
		if(stamp.verify(now, new JCEVerifier())==false) {
			System.out.println("verify stamp fail");
			return;
		}
		
		byte[] certData=readFile(signCertFileName);
		X509Certificate signCert=new X509Certificate(certData);
		if(stamp.hasCert(signCert, new JCEHasher())==false) {
			System.out.println("签名证书不在印章中");
			return;
		}
		
		
		String signAlgo=getSignAlgorithm(signCert);
		AlgorithmIdentifier hashAlgo=getHashAlgorithm(signCert);
		byte[] hashValue=hashFile(hashAlgo,new JCEHasher(),tbsFileName);
		Certificate cryptoSignCert=new Certificate(certData);
		KeyPair keypair=null;
		NetcaSigner signer=null;
		try {
			keypair=cryptoSignCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN,pwd);
			if(keypair==null) {
				System.out.println("获取签名证书的私钥失败");
	            return;
			}
			signer=new NetcaSigner(keypair);
			int format;
			if(stamp.getStampType()==Stamp.GBT_38540){
				format=Seal.GBT_38540;
			} else{
				format=Seal.GMT_0031;
			}
			SealBuilder builder=SealBuilder.getInstance(format)
					.setStamp(stamp)
					.setTime(now)
					.setPropertyInfo(propertyInfo);
			if(format==Seal.GMT_0031){
				builder.setVersion(version);
			} /*else {
				net.netca.pki.encoding.asn1.pki.seseal.ExtData ext=new net.netca.pki.encoding.asn1.pki.seseal.ExtData("1.2.3.4.100",false,new byte[]{4 ,1 ,3});
				builder.addExtension(ext);
				ext=new net.netca.pki.encoding.asn1.pki.seseal.ExtData("2.3.200.100",true,new byte[]{5 ,0});
				builder.addExtension(ext);
			}*/
			Seal seal=builder
				.signHash(hashValue,signCert,signer,signAlgo,new JCEHasher());
			byte[] sealEncode=seal.getASN1Object().encode();
			writeFile(sealFileName,sealEncode);
	        System.out.println("Success");
		} finally {
			cryptoSignCert.free();
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
	
	private static byte[] hashFile(AlgorithmIdentifier hashAlgo,Hashable hasher,String fileName) throws Exception{
		FileInputStream fIn=new FileInputStream(fileName);
		byte[] data=new byte[8192];
		int length;
		hasher.init(hashAlgo);
		try {
			for(;;) {
				length=fIn.read(data);
				if(length==-1) {
					break;
				}
				hasher.update(data, 0, length);
			}
			return hasher.digest();
		}finally {
			fIn.close();
		}
	}
	
	private static AlgorithmIdentifier getHashAlgorithm(X509Certificate signCert)throws Exception{
		if(signCert.isSM2()) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3_OID);
		} else if(signCert.isRSA()) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256_OID);
		} else {
			throw new Exception("不支持该证书");
		}
	}
	
	private static String getSignAlgorithm(X509Certificate signCert)throws Exception{
		if(signCert.isSM2()) {
			return AlgorithmIdentifier.SM3WithSM2_OID;
		} else if(signCert.isRSA()) {
			return AlgorithmIdentifier.SHA256WithRSA_OID;
		} else {
			throw new Exception("不支持该证书");
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
}
