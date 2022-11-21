import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.ISignedDataSign;
import net.netca.pki.global.Pki;
import net.netca.pki.global.X509Certificate;
import net.netca.pki.global.ISignedDataDetachedSign;

public class SignedDataSign2 {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if (argCount!=4 && argCount!=5) {
			System.out.println("Usage: java SignedDataSign2 [-detached] certFileName pwd tbsData signedDataFileName");
            return;
		}
		boolean isDetached;
		int pos;
		if(argCount==5) {
			if(args[0].equals("-detached") ||
				args[0].equals("/detached")) {
				isDetached=true;
			} else {
				System.out.println("Usage: java SignedDataSign2 [-detached] certFileName pwd tbsData signedDataFileName");
	            return;
			}
			pos=1;
		} else {
			pos=0;
			isDetached=false;
		}
		
		String certFileName=args[pos];
		pos++;
		String pwd=args[pos];
		pos++;
		byte[] tbs=args[pos].getBytes("UTF-8");
		pos++;
		String signedDataFileName=args[pos];
		
		byte[] certData=readFile(certFileName);
		if(isDetached) {
			detachedSign(certData,pwd,tbs,signedDataFileName);
		} else {
			sign(certData,pwd,tbs,signedDataFileName);
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
	
	private static void sign(byte[] certData,String pwd,byte[] tbs,String signFileName) throws Exception{
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        X509Certificate cert=null;
        ISignedDataSign signObj=null;
        try {
	        cert=pki.decodeCert(certData);
	        cert.getPrivateKey(pwd);
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
	
	private static void detachedSign(byte[] certData,String pwd,byte[] tbs,String signFileName) throws Exception{
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        X509Certificate cert=null;
        ISignedDataDetachedSign signObj=null;
        try {
        	cert=pki.decodeCert(certData);
 	        cert.getPrivateKey(pwd);
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
