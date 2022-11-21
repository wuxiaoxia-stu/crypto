import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.Pki;
import net.netca.pki.global.X509Certificate;

public class BuildCertPath {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java BuildCertPath certFileName");
            return;
        }
		
		String certFileName=args[0];
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        X509Certificate[] certs=null;
        try {
        	byte[] certData=readFile(certFileName);
	        cert=pki.decodeCert(certData);
	        certs=cert.buildCertPath();
	        for(int i=0;i<certs.length;i++) {
	        	System.out.println(certs[i].getSubject());
	        }
        } finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if(certs!=null) {
        		for(int i=0;i<certs.length;i++) {
        			if (certs[i] instanceof Freeable) {
                		((Freeable)certs[i]).free();
                	}
        		}
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
		String fileName=System.getProperty("pkiParamFileName");
		String param;
		if(fileName==null) {
			param=System.getProperty("pkiParam");
			if(param==null) {
				return Pki.getInstance(name);
			} else {
				return Pki.getInstance(name,param);
			}
		} else {
			byte[] data=readFile(fileName);
			if(data.length>=3 && data[0]==-17 && data[1]==-69 && data[2]==-65) {
				param=new String(data,3,data.length-3,"UTF-8");
			} else {
				param=new String(data,"UTF-8");
			}
			return Pki.getInstance(name,param);
		}
	}
	
}
