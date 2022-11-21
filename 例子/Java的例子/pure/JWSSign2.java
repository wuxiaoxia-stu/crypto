import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.json.jose.impl.netcajni.*;
import net.netca.pki.CertStore;
import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;

public class JWSSign2 {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=2 && argCount!=3) {
            System.out.println("Usage: java JWSSign2 [-compact] signCert payLoad");
            return;
        }
		int type;
		String signCertFileName;
		String payLoad;
		
		if(argCount==2){
			type=JWS.JSON_SERIALIZATION;
			signCertFileName=args[0];
			payLoad=args[1];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSSign2 [-compact] signCert payLoad");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			signCertFileName=args[1];
			payLoad=args[2];
		}
		
		X509Certificate signCert=getCert(signCertFileName);
		String algoName=getSignAlgo(signCert);
		NetcaJWSSigner signObj=null;
		CertStore store=new CertStore(CertStore.CURRENT_USER,CertStore.DEVICE);
		try{
			signObj=getSignObj(store,signCert);
					
			JWSSigner jwsSigner=JWSSigner.getInstance()
				.setSignCert(JWS.CERTID_TYPE_X5T_S256, algoName, signCert, signObj);
			
			JWS jws=JWSBuilder.getInstance(type)
					.addSigner(jwsSigner)
					.setHashImplement(new NetcaHash())
					.setPayload(payLoad.getBytes("UTF-8"))
					.sign();
			System.out.println(jws.encode());
		}finally{
			store.free();
			if(signObj!=null){
				signObj.free();
			}
		}

	}
	
	private static NetcaJWSSigner getSignObj(CertStore store,X509Certificate signCert)throws Exception{
		int count=store.getCertificateCount();
		for(int i=0;i<count;i++){
			Certificate cert=store.getCertificate(i);
			if(cert!=null){
				KeyPair keypair=null;
				try{
					if(Arrays.equals(cert.derEncode(),signCert.derEncode())){
						keypair=cert.getKeyPair(0, Certificate.PURPOSE_SIGN, null);
						if(keypair!=null){
							return new NetcaJWSSigner(keypair);
						}
					}
				}finally{
					cert.free();
					if(keypair!=null){
						keypair.free();
					}
				}
			}
		}
		return null;
	}
	
	private static String getSignAlgo(X509Certificate signCert)throws Exception{
		if(signCert.isSM2()){
			return JWS.SM2_SM3;
		} else if(signCert.isRSA()){
			return JWS.RSA_SHA256;
		} else {
			throw new Exception("unsupport cert");
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
