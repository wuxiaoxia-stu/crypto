import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.encoding.asn1.pki.EncryptedPrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.PrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.JCESymEncrypter;
import net.netca.pki.encoding.asn1.pki.Pkcs5PBKDF2;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.pkcs12.PFX;
import net.netca.pki.encoding.asn1.pki.pkcs12.PFXBuilder;


public class GenPfx {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount<5) {
            System.out.println("Usage: java GenPfx [-v1.1] pfxFileName privKeyFileName privKeyPwd pfxPwd certFileName [caCertFile1 ... caCertFileN]");
            return;
        }
		int pos=0;
		boolean usePkcs5=false;
		if(args[0].equals("-v1.1")){
			if(argCount<6){
				System.out.println("Usage: java GenPfx [-v1.1] pfxFileName privKeyFileName privKeyPwd pfxPwd certFileName [caCertFile1 ... caCertFileN]");
	            return;
			}
			pos++;
			usePkcs5=true;
		}
		String pfxFileName=args[pos];
		pos++;
		String privKeyFileName=args[pos];
		pos++;
		String privKeyPwd=args[pos];
		pos++;
		String pfxPwd=args[pos];
		pos++;
		String certFileName=args[pos];
		pos++;
		
		int caCertCount=args.length-pos;
		String []caCerts=new String[caCertCount];
		for(int i=pos;i<args.length;i++){
			caCerts[i-pos]=args[i];
		}
		PrivateKeyInfo privKey=decryptPrivateKey(privKeyFileName,privKeyPwd);
		byte[] keyId=new byte[4];
		keyId[3]=1;
		X509Certificate cert=readCert(certFileName);
		
		
		PFXBuilder builder=new PFXBuilder();
		
		if(usePkcs5){
			builder.setPkcs5KDF(new Pkcs5PBKDF2());
		}
		builder.setPwd(pfxPwd);
		builder.addPrivateKey(privKey, null, cert, keyId, null);
		
		
		for(int i=0;i<caCerts.length;i++){
			builder.addCert(readCert(caCerts[i]));
		}
		
		PFX pfx=builder.build();
		save(pfxFileName,pfx.getASN1Object().encode());
		System.out.println("success");
	}
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
	}
	
	private static X509Certificate readCert(String fileName) throws Exception{
		return new X509Certificate(readFile(fileName));
	}
	
	
	private static PrivateKeyInfo decryptPrivateKey(String fileName,String pwd)throws Exception{
		EncryptedPrivateKeyInfo encPrivKeyInfo=readEncryptedPrivateKeyInfo(fileName);
		AlgorithmIdentifier algo=encPrivKeyInfo.getEncryptionAlgorithm();
		String oid=algo.getOid();
		if(oid.equals(AlgorithmIdentifier.PBES2)==false){
			throw new Exception("不支持的加密算法");
		}
		return encPrivKeyInfo.pkcs5Decrypt(pwd.getBytes("UTF-8"), new JCESymEncrypter(), new Pkcs5PBKDF2());
	}
	
	private static EncryptedPrivateKeyInfo readEncryptedPrivateKeyInfo(String fileName) throws Exception{
		return EncryptedPrivateKeyInfo.decode(readFile(fileName));
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
