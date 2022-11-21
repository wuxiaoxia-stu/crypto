import net.netca.pki.global.*;
import net.netca.pki.Freeable;
import net.netca.pki.encoding.*;

public class Hash {
	public static void main(String[] args) throws Exception {
        if(args.length!=2) {
            System.out.println("Usage: java Hash hashAlgo data");
            return;
        }
        
        String hashAlgo=args[0];
        byte[] data=args[1].getBytes("UTF-8");
        
        Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        try {
	        byte[] hashValue=pki.hash(hashAlgo,data);
	        System.out.println(Hex.encode(true, hashValue));
        } finally {
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
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
