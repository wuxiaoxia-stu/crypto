import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.SignedAndEnvelopedData;
import net.netca.pki.Signature;
import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;

public class SignedAndEnvelopedDataEncrypt {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=4 && argCount!=5) {
            System.out.println("Usage: java SignedAndEnvelopedDataEncrypt encCert signCert infile outfile [signPwd]");
            return;
        }
		
		String encCertFileName=args[0];
		String signCertFileName=args[1];
		String inFileName=args[2];
		String outFileName=args[3];
		String pwd=null;
		if(argCount==5){
			pwd=args[4];
		}
		
		Certificate encCert=null;
		Certificate signCert=null;
		SignedAndEnvelopedData signAndEnvObj=null;
		KeyPair keypair=null;
		try{
			encCert=getCert(encCertFileName);
			if(encCert.isInValidity()==false){
				System.out.println("加密证书不在有效期内");
				return;
			}
			if(encCert.match("CertType='Encrypt'")==false){
				System.out.println("不是加密证书");
				return;
			}
			
			signCert=getCert(signCertFileName);
			if(signCert.isInValidity()==false){
				System.out.println("签名证书不在有效期内");
				return;
			}
			if(signCert.match("CertType='Signature'")==false){
				System.out.println("不是签名证书");
				return;
			}
			byte[] inData=readFile(inFileName);
			int encAlgo=getEncAlgo(encCert);
			int signAlgo=getSignAlgo(signCert);
			
			keypair=signCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE,
					Certificate.PURPOSE_SIGN, pwd);
			if(keypair==null){
				System.out.println("签名证书没有私钥");
				return;
			}
			
			
			signAndEnvObj=new SignedAndEnvelopedData(true);
			signAndEnvObj.setEncAlgorithm(encAlgo);
			signAndEnvObj.addEncCert(encCert);
			signAndEnvObj.setClearText(inData);
			
			byte[] outData=signAndEnvObj.signAndEncrypt(signAlgo, signCert);
			save(outFileName,outData);
			
			System.out.println("签名加密成功");
			
		} finally{
			if(encCert!=null){
				encCert.free();
			}
			if(signCert!=null){
				signCert.free();
			}
			if(keypair!=null){
				keypair.free();
			}
			if(signAndEnvObj!=null){
				signAndEnvObj.free();
			}
		}
	}
	
	private static int getEncAlgo(Certificate encCert)throws Exception{
		if(encCert.match("Algorithm='SM2'")){
			return SignedAndEnvelopedData.SM4CBC;
		} else {
			return SignedAndEnvelopedData.AES128CBC;
		}
	}
	
	private static int getSignAlgo(Certificate signCert)throws Exception{
		if(signCert.match("Algorithm='SM2'")){
			return Signature.SM3WITHSM2;
		}else if(signCert.match("Algorithm='RSA'")){
			return Signature.SHA256WITHRSA;
		}else if(signCert.match("Algorithm='ECC'")){
			return Signature.ECDSAWITHSHA256;
		} else {
			throw new Exception("不支持的签名证书");
		}
	}

	private static Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new Certificate(data);
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
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
	}
}
