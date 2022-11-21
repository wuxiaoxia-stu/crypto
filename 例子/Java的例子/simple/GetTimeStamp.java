import java.io.FileOutputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.*;

public class GetTimeStamp {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java GetTimeStamp data fileName");
            return;
        }
		byte[] data=args[0].getBytes("UTF-8");
		String fileName=args[1];
		
		IGetTimeStamp getTimeStampObj=null;
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        try{
	        getTimeStampObj=pki.getGetTimeStampObject();
	        byte[] token=getTimeStampObj.getToken(data, 0, data.length);
	        System.out.println(getTimeStampObj.getTime());
	        save(fileName,token);
        } finally {
        	if (getTimeStampObj instanceof Freeable) {
        		((Freeable)getTimeStampObj).free();
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
