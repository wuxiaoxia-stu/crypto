import net.netca.pki.global.*;
import net.netca.pki.Freeable;
import java.io.*;

public class Sign {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java Sign tbsData signFileName");
            return;
        }
		byte[] tbs=args[0].getBytes("UTF-8");
		String signFileName=args[1];
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try {
	        cert=pki.getUserCert(Pki.USERCERT_TYPE_SIGN, null,null);
	        byte[] signature=cert.sign(tbs);
	        save(signFileName,signature);        
	        System.out.println("sign success");
	        
        }	finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
        	}
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
