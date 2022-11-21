import net.netca.pki.global.*;
import net.netca.pki.Freeable;
import java.io.*;

public class Verify {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java Verify certFileName tbsData signFileName");
            return;
        }
		String certFileName=args[0];
	    byte[] tbs=args[1].getBytes("UTF-8");
	    String signFileName=args[2];
	    
	    Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try {
        	byte[] certData=readFile(certFileName);
	        cert=pki.decodeCert(certData);
	        byte[] signature=readFile(signFileName);
	        if(cert.verifySignature(tbs, signature)) {      
	        	System.out.println("verify success");
	        } else {
	        	System.out.println("verify fail");
	        }
	       
	        
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
