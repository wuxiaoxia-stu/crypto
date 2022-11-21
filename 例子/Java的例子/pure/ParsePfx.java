import java.io.File;
import java.io.FileInputStream;
import java.util.Iterator;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.X509CertificateAndPrivateKey;
import net.netca.pki.encoding.asn1.pki.pkcs12.PFX;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.PrivateKeyDecrypter;
import net.netca.pki.encoding.asn1.pki.Signable;
import net.netca.pki.encoding.asn1.pki.SubjectPublicKeyInfo;
import net.netca.pki.encoding.asn1.pki.JCEPublicKeyEncrypter;

public class ParsePfx {

		
	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=2) {
            System.out.println("Usage: java ParsePfx pfxFileName pwd");
            return;
        }
		String fileName=args[0];
		String pwd=args[1];
		PFX pfx=PFX.decode(readFile(fileName));
		pfx.decrypt(pwd);
		
		Iterator<X509CertificateAndPrivateKey> it=pfx.getCertAndPrivateKeyIterator();
		while(it.hasNext()){
			
			X509CertificateAndPrivateKey certAndKey=it.next();
			System.out.println(certAndKey.getCert().getSubject().getLdapName());
			if(check(certAndKey)==false){
				System.out.println("Check private key fail");
			}
						
		}

		
	}

	private static boolean check(X509CertificateAndPrivateKey certAndKey)throws Exception{
		X509Certificate cert=certAndKey.getCert();
		Signable signer=certAndKey.getSigner();
		PrivateKeyDecrypter privateKeyDecrypter=certAndKey.getPrivateKeyDecrypter();
		if(signer!=null){
			if(checkSign(cert,signer)==false){
				return false;
			}
		}
		if(privateKeyDecrypter!=null){
			if(checkDecrypt(cert,privateKeyDecrypter)==false){
				return false;
			}
		}
		return true;
	}
	private static boolean checkDecrypt(X509Certificate cert,PrivateKeyDecrypter privateKeyDecrypter)throws Exception{
		SubjectPublicKeyInfo spki=cert.getSubjectPublicKeyInfo();
		AlgorithmIdentifier encAlgo=getEncryptAlgo(spki);
		byte[] clear=new byte[2];
		clear[0]=1;
		clear[1]=2;
		JCEPublicKeyEncrypter publicKeyEncrypter=new JCEPublicKeyEncrypter();
		
		byte[] cipher=publicKeyEncrypter.encrypt(spki.getPublicKey(), encAlgo, clear,0, clear.length);
		
		byte[] clear2=privateKeyDecrypter.decrypt(encAlgo, cipher, 0,cipher.length);
		
		if(clear.length!=clear2.length){
			return false;
		}
		for(int i=0;i<clear.length;i++){
			if(clear[i]!=clear2[i]){
				return false;
			}
		}
		return true;
	}
	private static AlgorithmIdentifier getEncryptAlgo(SubjectPublicKeyInfo spki)throws Exception{
		if(spki.isSM2()){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM2ENC_OID);
		} 
		
		String oid=spki.getAlgorithm().getOid();
		if(oid.equals(AlgorithmIdentifier.RSAEncrypt_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.RSAEncrypt_OID);
		} else {
			throw new Exception("unknown public key for encrypt");
		}
		
	}
	
	private static boolean checkSign(X509Certificate cert,Signable signer)throws Exception{
		SubjectPublicKeyInfo spki=cert.getSubjectPublicKeyInfo();
		AlgorithmIdentifier signAlgo=getSignAlgo(spki);
		byte[] tbs=new byte[2];
		tbs[0]=1;
		tbs[1]=2;
		byte[] sign=signer.sign(signAlgo, tbs, 0, tbs.length);
		JCEVerifier verifier=new JCEVerifier();
		return verifier.verify(spki.getPublicKey(),signAlgo, tbs, 0,tbs.length, sign);
	}
	
	private static AlgorithmIdentifier getSignAlgo(SubjectPublicKeyInfo spki)throws Exception{
		if(spki.isSM2()){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
		} 
		
		String oid=spki.getAlgorithm().getOid();
		if(oid.equals(AlgorithmIdentifier.RSAEncrypt_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
		} else if(oid.equals(AlgorithmIdentifier.ECPubKey_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
		} else {
			throw new Exception("unknown public key for sign");
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
}
