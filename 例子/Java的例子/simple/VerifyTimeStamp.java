import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.*;
import java.util.Date;

public class VerifyTimeStamp {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java VerifyTimeStamp data tokenFileName");
            return;
        }
		byte[] data=args[0].getBytes("UTF-8");
		String fileName=args[1];
		byte[] token=readFile(fileName);
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        try{
	        Date time=pki.verifyTimeStamp(data, token);
	        System.out.println(time);
	        
        } finally {
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
