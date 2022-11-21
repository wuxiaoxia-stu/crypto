import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.*;

public class JWEEncryptByCert {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=2) {
            System.out.println("Usage: java JWEEncryptByCert [-compact] certFileName clear");
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
				 System.out.println("Usage: java JWEEncryptByCert [-compact] certFileName clear");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			fileName=args[1];
			clear=args[2];
		}
		JWE jweObj=new JWE(type);
		Certificate cert=null;
		
		try {
			cert=getCert(fileName);
			int cekAlgo=getCEKAlgo(cert);
			if(cekAlgo==-1){
				System.out.println("不支持的证书类型");
				return;
			}
			jweObj.setContentEncAlgo(cekAlgo);
			int kekAlgo=geKEKAlgo(cert);
			if(kekAlgo==-1){
				System.out.println("不支持的证书类型");
				return;
			}
			jweObj.addCert(kekAlgo, cert, JWE.CERTID_TYPE_X5T_S256);
			String jwe=jweObj.encrypt(clear.getBytes("UTF-8"));
			System.out.println(jwe);
		}finally {
			jweObj.free();
			if(cert!=null){
				cert.free();
			}
		}
		
		
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
	
	private static Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new Certificate(data);
	}
	
	private static int getCEKAlgo(Certificate cert)throws Exception{
		if(cert.match("Algorithm='RSA'")){
			return JWE.AES_256_GCM;
		} else if(cert.match("Algorithm='SM2'")){
			return JWE.SM4_CBC_HMAC_SM3;
		} else {
			return -1;
		}
	}
	
	private static int geKEKAlgo(Certificate cert)throws Exception{
		if(cert.match("Algorithm='RSA'")){
			return JWE.RSA1_5;
		} else if(cert.match("Algorithm='SM2'")){
			return JWE.SM2;
		} else {
			return -1;
		}
	}
}
