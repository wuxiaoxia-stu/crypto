import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.Pki;
import net.netca.pki.global.ISignedDataVerify;
import net.netca.pki.global.ISignedDataDetachedVerify;

public class SignedDataAttachTimeStamp {

	public static void main(String[] args) throws Exception {
		if (args.length!=3) {
			System.out.println("Usage: java SignedDataAttachTimeStamp tbsData oldSignedDataFileName newSignedDataFileName");
            return;
		}

		byte[] tbs=args[0].getBytes("UTF-8");
		String oldSignedDataFileName=args[1];
		String newSignedDataFileName=args[2];
		byte[] sign=readFile(oldSignedDataFileName);
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        
        try {
        	
        	if(pki.isSignedData(sign)==false) {
        		System.out.println("not SignedData");
        		return;
        	}
        	
        	if(pki.isDetachedSignedData(sign)) {
        		attachDetachedTimeStamp(pki,tbs,sign,newSignedDataFileName);
        	} else {
        		attachTimeStamp(pki,tbs,sign,newSignedDataFileName);
        	}
        	
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
	
	private static void attachTimeStamp(Pki pki,byte[] tbs,byte[] signedData,String newSignedDataFileName) throws Exception{
		ISignedDataVerify verify=null;
		try {
			verify=pki.getSignedDataVerifyObject();
			byte[] tbs2=verify.verify(signedData, 0, signedData.length);
			if (isByteArrayEqual(tbs,tbs2)==false) {
				throw new Exception("tbs mismatch");
			}
			byte[] newSignedData=verify.attachSignatureTimeStamp();
			save(newSignedDataFileName,newSignedData);
			System.out.println(verify.getSignatureTimeStampTime());
		} finally {
			if (verify instanceof Freeable) {
				((Freeable)verify).free();
			}
		}
	}
	
	private static boolean isByteArrayEqual(byte[] b1,byte[] b2) {
		if(b1.length!= b2.length) {
			return false;
		}
		
		for(int i=0;i<b1.length;i++) {
			if(b1[i]!=b2[i]) {
				return false;
			}
		}
		return true;
	}
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
	}
	
	private static void attachDetachedTimeStamp(Pki pki,byte[] tbs,byte[] signedData,String newSignedDataFileName) throws Exception{
		ISignedDataDetachedVerify verify=null;
		try {
			verify=pki.getSignedDataDetachedVerifyObject();
			verify.detachedVerifyInit(signedData, 0, signedData.length);
			verify.detachedVerifyUpdate(tbs, 0, tbs.length);
			verify.detachedVerifyFinal();
			byte[] newSignedData=verify.attachSignatureTimeStamp();
			save(newSignedDataFileName,newSignedData);
			System.out.println(verify.getSignatureTimeStampTime());
		} finally {
			if (verify instanceof Freeable) {
				((Freeable)verify).free();
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
