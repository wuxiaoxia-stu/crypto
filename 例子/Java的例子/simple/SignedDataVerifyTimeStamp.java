import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.ISignedDataDetachedVerify;
import net.netca.pki.global.ISignedDataVerify;
import net.netca.pki.global.Pki;
import java.util.Date;

public class SignedDataVerifyTimeStamp {

	public static void main(String[] args) throws Exception{
		if (args.length!=2) {
			System.out.println("Usage: java SignedDataVerifyTimeStamp tbsData signedDataFileName");
            return;
		}

		byte[] tbs=args[0].getBytes("UTF-8");
		String signedDataFileName=args[1];
		byte[] sign=readFile(signedDataFileName);
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
        		verifyDetached(pki,tbs,sign);
        	} else {
        		verify(pki,tbs,sign);
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
	
	private static void verify(Pki pki,byte[] tbs,byte[] signedData) throws Exception{
		ISignedDataVerify verifyObj=null;
		try {
			verifyObj=pki.getSignedDataVerifyObject();
			byte[] tbs2=verifyObj.verify(signedData, 0, signedData.length);
			if (isByteArrayEqual(tbs,tbs2)==false) {
				throw new Exception("tbs mismatch");
			}
			System.out.println("verify success");
			Date t=verifyObj.getSignatureTimeStampTime();
			if(t==null) {
				System.out.println("no signature timstamp");
			} else {
				System.out.println("signature timstamp:" + t);
			}
			
			
		} finally {
			if (verifyObj instanceof Freeable) {
				((Freeable)verifyObj).free();
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
	
	private static void verifyDetached(Pki pki,byte[] tbs,byte[] signedData) throws Exception{
		ISignedDataDetachedVerify verifyObj=null;
		try {
			verifyObj=pki.getSignedDataDetachedVerifyObject();
			verifyObj.detachedVerifyInit(signedData, 0, signedData.length);
			verifyObj.detachedVerifyUpdate(tbs, 0, tbs.length);
			verifyObj.detachedVerifyFinal();
			System.out.println("verify success");
			Date t=verifyObj.getSignatureTimeStampTime();
			if(t==null) {
				System.out.println("no signature timstamp");
			} else {
				System.out.println("signature timstamp:" + t);
			}
			
		} finally {
			if (verifyObj instanceof Freeable) {
				((Freeable)verifyObj).free();
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
