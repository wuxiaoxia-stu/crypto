import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.*;
public class JWTEncryptByCert {

	public static void main(String[] args) throws Exception{
		if(args.length<2 || args.length%2!=1) {
            System.out.println("Usage: java JWTEncryptByCert certFileName claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }
		String fileName;
		fileName=args[0];
		JWT jwtObj=new JWT(JWT.JWE_TYPE);
		Certificate cert=null;
		
		try {
			for(int i=1;i<args.length;i+=2){
				jwtObj.setClaim(args[i],args[i+1]);
			}
			
			cert=getCert(fileName);
			int cekAlgo=getCEKAlgo(cert);
			if(cekAlgo==-1){
				System.out.println("不支持的证书类型");
				return;
			}
			int kekAlgo=geKEKAlgo(cert);
			if(kekAlgo==-1){
				System.out.println("不支持的证书类型");
				return;
			}
			
			String jwt=jwtObj.encryptByCert(cekAlgo, cert, kekAlgo, JWT.CERTID_TYPE_X5T_S256);
			System.out.println(jwt);
		}finally {
			jwtObj.free();
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
