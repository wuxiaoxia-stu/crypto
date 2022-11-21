import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.*;
public class EnvelopedDataDecryptFile {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java EnvelopedDataDecryptFile cipherTextFileName clearTextFileName");
            return;
        }
		String clearFileName=args[1];
		String cipherName=args[0];
		
		Pki pki=Pki.getInstance("netca");
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        
        IEnvelopedDataMultiStepDecrypt decryptObj=null;
        try{
        	
        	decryptObj=pki.getEnvelopedDataMultiStepDecryptObject();
        	
        	decrypt(decryptObj,cipherName,clearFileName);
        	System.out.println("Success");
        } finally {
        	if (decryptObj instanceof Freeable) {
        		((Freeable)decryptObj).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
        	}
        }
	}
	
	private static void decrypt(IEnvelopedDataMultiStepDecrypt decryptObj,String inFileName,String outFileName) throws Exception{
		FileInputStream fIn=null;
		FileOutputStream fout=null;
		byte[] data=new byte[8192];
		int len;
		byte[] outData;
		try {
			fIn=new FileInputStream(inFileName);
			fout=new FileOutputStream(outFileName);
			
			for(;;){
				len=fIn.read(data);
				if(len==-1) {
					break;
				}
				outData=decryptObj.decryptUpdate(data, 0, len);
				fout.write(outData);
			}
			decryptObj.decryptFinal();
			
		} finally {
			if(fIn!=null) {
				fIn.close();
			}
			if(fout!=null) {
				fout.close();
			}
		}
	}

}
