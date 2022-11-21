import net.netca.pki.global.*;
import net.netca.pki.Freeable;
import net.netca.pki.encoding.*;
import java.io.*;

public class HashFile {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java HashFile hashAlgo fileName");
            return;
        }
		String hashAlgo=args[0];
		String fileName=args[1];
		
		
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        FileInputStream fIn=null;
        IHash hashObj=null;
        byte[] data=new byte[8192];
        int len;
        try {
        	hashObj=pki.getHashObject(hashAlgo);
        	fIn=new FileInputStream(fileName);
        	for(;;) {
        		len=fIn.read(data);
        		if(len==-1) {
        			break;
        		}
        		hashObj.update(data, 0, len);
        	}
        	byte[] hashValue=hashObj.doFinal();
        	System.out.println(Hex.encode(true, hashValue));
        } finally {
        	if (hashObj instanceof Freeable) {
        		((Freeable)hashObj).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
        	}
        	
        	if(fIn!=null) {
        		fIn.close();
        	}
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

