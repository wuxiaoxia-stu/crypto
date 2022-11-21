import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.encoding.asn1.pki.NetcaMyStore;
import net.netca.pki.encoding.asn1.pki.NetcaVerifier;
import net.netca.pki.encoding.asn1.pki.NetcaSymEncrypter;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.SignedAndEnvelopedData;

public class VerifySignedAndEnvelopedData {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java VerifySignedAndEnvelopedData infile outfile");
            return;
        }
		
		String inFileName=args[0];
		String outFileName=args[1];
		NetcaMyStore store=null;
		
		try{
			
			byte[] data;
			
			store=new NetcaMyStore();
			
	        data=readFile(inFileName);
	        SignedAndEnvelopedData signedAndEnv=new SignedAndEnvelopedData(data);
	        
	        signedAndEnv.setCertAndPrivKeys(store.iterator());
	        signedAndEnv.setSymEncrypter(new NetcaSymEncrypter());
	        signedAndEnv.setVerifyImplement(new NetcaVerifier());
	        byte[] content=signedAndEnv.decryptAndVerify();
			
			save(outFileName,content);
			
			X509Certificate signCert=signedAndEnv.getSignCert(0);
			X509Certificate encCert=signedAndEnv.getDecryptCert();
			
			System.out.println("Decrypt Cert:"+encCert.getSubject().getLdapName());
			System.out.println("Sign Cert:"+signCert.getSubject().getLdapName());
		}finally{
			if(store!=null){
				store.free();
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
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
	}
}
