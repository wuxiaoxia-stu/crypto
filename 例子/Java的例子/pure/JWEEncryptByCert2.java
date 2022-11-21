import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.json.jose.impl.jce.*;

public class JWEEncryptByCert2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=2) {
            System.out.println("Usage: java JWEEncryptByCert2 [-compact] certFileName clear");
            return;
        }
		
		int type;
		String fileName;
		String clear;
		if(args.length==2){
			type=JWE.JSON_SERIALIZATION;
			fileName=args[0];
			clear=args[1];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWEEncryptByCert2 [-compact] certFileName clear");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			fileName=args[1];
			clear=args[2];
		}

		X509Certificate encCert=getCert(fileName);
		String encAlgo=getEncAlgo(encCert);
		String algo=getAlgo(encCert);
		JWERecipienter recipienter=JWERecipienter.getInstance()
			.setCert(JWE.CERTID_TYPE_X5T_S256,algo,encCert);
		
		JWE jwe=JWEBuilder.getInstance(type)
				.setContentEncAlgo(encAlgo)
				.setPublicKeyEncrypter(new JCEJWEPublicKeyEncrypter())
				.setSymEncrypter(new JCEJWECipher())
				.setSecureRandomGenerator(new JCEGenerateRandom())
				.addRecipienter(recipienter)
				.encrypt(clear.getBytes("UTF-8"));
		System.out.println(jwe.encode());
	}
	private static String getAlgo(X509Certificate encCert)throws Exception{
		if(encCert.isSM2()){
			return JWE.ENCRYPT_CEK_ALGO_SM2_ENCRYPT;
		} else if(encCert.isRSA()){
			return JWE.ENCRYPT_CEK_ALGO_RSA1_5;
		} else {
			throw new Exception("unsupport cert");
		}
	}
	
	
	private static String getEncAlgo(X509Certificate encCert)throws Exception{
		if(encCert.isSM2()){
			return JWE.CONTENT_ENC_ALGO_SM4_CBC_HMAC_SM3;
		} else {
			return JWE.CONTENT_ENC_ALGO_AES_128_CBC_HMAC_SHA_256;
		}
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

}
