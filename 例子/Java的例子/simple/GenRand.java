import net.netca.pki.global.*;
import net.netca.pki.encoding.*;
import net.netca.pki.Freeable;

public class GenRand {
	public static void main(String[] args) throws Exception {
        if(args.length!=1) {
            System.out.println("Usage: java GenRand length");
            return;
        }
        
        int len=Integer.parseInt(args[0]);
        Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        try {
	        byte[] rand=pki.generateRandom(len);
	        System.out.println(Hex.encode(true, rand));
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
