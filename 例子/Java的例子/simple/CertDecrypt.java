import net.netca.pki.global.*;
import net.netca.pki.Freeable;
import java.io.*;

public class CertDecrypt {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java CertDecrypt cipherTextFileName");
            return;
        }
		
		String cipherFileName=args[0];
		byte[] cipher=readFile(cipherFileName);
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try {
	        cert=pki.getUserCert(Pki.USERCERT_TYPE_ENCRYPT, null,null);
	        byte[] clear=cert.decrypt(cipher);
	        	        
	        System.out.println(new String(clear,"UTF-8"));
	        
        }	finally {
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
