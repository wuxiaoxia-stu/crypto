import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.SignedAndEnvelopedData;
import net.netca.pki.CertStore;

public class SignedAndEnvelopedDataDecrypt {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=4 && argCount!=5) {
            System.out.println("Usage: java SignedAndEnvelopedDataDecrypt decCert signCert infile outfile [decPwd]");
            return;
        }

		String decCertFileName=args[0];
		String signCertFileName=args[1];
		String inFileName=args[2];
		String outFileName=args[3];
		String pwd=null;
		if(argCount==5){
			pwd=args[4];
		}
		
		Certificate decCert=null;
		Certificate signCert=null;
		SignedAndEnvelopedData signAndEnvObj=null;
		KeyPair keypair=null;
		CertStore store=null;
		try{
			decCert=getCert(decCertFileName);
			
			if(decCert.match("CertType='Encrypt'")==false){
				System.out.println("不是加密证书");
				return;
			}
			if(signCertFileName.length()>0){
				signCert=getCert(signCertFileName);
				if(signCert.isInValidity()==false){
					System.out.println("签名证书不在有效期内");
					return;
				}
				if(signCert.match("CertType='Signature'")==false){
					System.out.println("不是签名证书");
					return;
				}
			}
			byte[] inData=readFile(inFileName);
						
			keypair=decCert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE,
					Certificate.PURPOSE_ENCRYPT, pwd);
			if(keypair==null){
				System.out.println("解密证书没有私钥");
				return;
			}
			store=CertStore.createMemoryStore();
			store.addCertificate(decCert);
			signAndEnvObj=new SignedAndEnvelopedData(false);
			signAndEnvObj.addStore(store);
			if(signCert!=null){
				signAndEnvObj.addCert(signCert);
			}
						
			byte[] outData=signAndEnvObj.decryptAndVerify(true, inData);
			save(outFileName,outData);
			
			System.out.println("解密验证成功");
			
		} finally{
			if(decCert!=null){
				decCert.free();
			}
			if(signCert!=null){
				signCert.free();
			}
			if(keypair!=null){
				keypair.free();
			}
			if(store!=null){
				store.close();
			}
			if(signAndEnvObj!=null){
				signAndEnvObj.free();
			}
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
