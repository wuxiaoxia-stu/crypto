import net.netca.pki.global.*;
import net.netca.pki.Freeable;
import java.io.*;

public class CertEncrypt {

	public static void main(String[] args)throws Exception {
		if(args.length!=3) {
            System.out.println("Usage: java CertEncrypt certfilName clearText cipherTextFileName");
            return;
        }
		String certFileName=args[0];
	    byte[] clear=args[1].getBytes("UTF-8");
	    String cipherFileName=args[2];
	    
	    Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try {
	        cert=getCert(pki,certFileName);
	        byte[] cipher=cert.encrypt(clear);
	        save(cipherFileName,cipher);
	        
	        System.out.println("encrypt success");
	        
        }	finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
        	}
        }
        
	}

	private static X509Certificate getCert(Pki pki,String fileName) throws Exception{
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
			return pki.decodeCert(data);
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
