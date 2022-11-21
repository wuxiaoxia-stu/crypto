import java.io.FileOutputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.ISignedDataSign;
import net.netca.pki.global.Pki;
import net.netca.pki.global.X509Certificate;
import net.netca.pki.global.ISignedDataDetachedSign;

public class SignedDataSign {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if (argCount!=2 && argCount!=3) {
			System.out.println("Usage: java SignedDataSign [-detached] tbsData signedDataFileName");
            return;
		}
		boolean isDetached;
		int pos;
		if(argCount==3)	{
			if(args[0].equals("-detached") ||
				args[0].equals("/detached")) {
				isDetached=true;
			} else {
				System.out.println("Usage: java SignedDataSign [-detached] tbsData signedDataFileName");
	            return;
			}
			pos=1;
		} else 	{
			pos=0;
			isDetached=false;
		}
		
		byte[] tbs=args[pos].getBytes("UTF-8");
		pos++;
		String signedDataFileName=args[pos];
		
		if(isDetached) {
			detachedSign(tbs,signedDataFileName);
		} else {
			sign(tbs,signedDataFileName);
		}
		
	}
	
	private static void sign(byte[] tbs,String signFileName) throws Exception{
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        X509Certificate cert=null;
        ISignedDataSign signObj=null;
        try {
	        cert=pki.getUserCert(Pki.USERCERT_TYPE_SIGN, null,null);
	        signObj=pki.getSignedDataSignObject(cert);
	        byte[] sign=signObj.sign(tbs,0, tbs.length);
	        save(signFileName,sign);    
	        System.out.println("Success");
        }	finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (signObj instanceof Freeable) {
        		((Freeable)signObj).free();
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
	
	private static void detachedSign(byte[] tbs,String signFileName) throws Exception{
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        X509Certificate cert=null;
        ISignedDataDetachedSign signObj=null;
        try {
	        cert=pki.getUserCert(Pki.USERCERT_TYPE_SIGN, null,null);
	        signObj=pki.getSignedDataDetachedSignObject(cert);
	        signObj.detachedSignUpdate(tbs,0, tbs.length);
	        byte[] sign=signObj.detachedSignFinal();
	        save(signFileName,sign);    
	        System.out.println("Success");
        }	finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (signObj instanceof Freeable) {
        		((Freeable)signObj).free();
        	}
        	
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
