
import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.*;
public class EnvelopedDataDecrypt2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java EnvelopedDataDecrypt2 certFileName pwd cipherTextFileName");
            return;
        }
		String certFileName=args[0];
		String pwd=args[1];
		String fileName=args[2];
		
		byte[] certData=readFile(certFileName);
		byte[] data=readFile(fileName);
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try{
        	cert=pki.decodeCert(certData);
        	cert.getPrivateKey(pwd);
        	byte[] clear=pki.envelopedDataDecrypt(cert,data);
        	System.out.println(new String(clear,"UTF-8"));
 
        } finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
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
	
	private static Pki getPkiObject() throws Exception{
		String name=System.getProperty("pkiName");
		if(name==null) {
			name="netca";
		}
		String param=System.getProperty("pkiParam");
		if(param==null) {
			return Pki.getInstance(name);
		} else {
			return Pki.getInstance(name,param);
		}
	}
}
