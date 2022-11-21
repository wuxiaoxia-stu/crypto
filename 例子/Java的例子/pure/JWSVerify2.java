import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWSVerifier;

public class JWSVerify2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=4) {
            System.out.println("Usage: java JWSVerify2 [-compact] certFileName payLoad jws");
            return;
        }

		int type;
		String fileName;
		String payLoad;
		String jwsData;
		if(args.length==3){
			type=JWS.JSON_SERIALIZATION;
			fileName=args[0];
			payLoad=args[1];
			jwsData=args[2];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSVerify2 [-compact] payLoad jws");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			fileName=args[1];
			payLoad=args[2];
			jwsData=args[3];
		}
		
		JWS jwsObj=JWS.decode(type, jwsData);
		
		if(jwsObj.getSignerCount()!=1){
			System.out.println("too much signer");
			return;
		}
		if(jwsObj.getSignerInfo(0).isSignature()==false){
			System.out.println("not sign");
			return;
		}
		
		jwsObj.setVerifyImplement(new JCEJWSVerifier());
		jwsObj.setHashImplement(new net.netca.pki.encoding.json.jose.impl.jce.JCEHash());
		
		X509Certificate signCert=getCert(fileName);
		if(jwsObj.verifySignature(0, signCert)==false){
			System.out.println("verify fail");
			return;
		}
		
		byte[] data=jwsObj.getPayload();
		if(Arrays.equals(data, payLoad.getBytes("UTF-8"))==false){
			System.out.println("payLoad mismatch");
			return;
		}
		System.out.println("Sign Algo:"+jwsObj.getSignerInfo(0).getAlgo());
				
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
	
	private static X509Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509Certificate(data);
	}

}
