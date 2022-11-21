import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.*;
public class EnvelopedDataEncryptFile {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java EnvelopedDataEncryptFile certFileName clearTextFileName cipherTextFileName");
            return;
        }

		String certFileName=args[0];
		String clearFileName=args[1];
		String cipherName=args[2];
		
		byte[] certData=readFile(certFileName);
		Pki pki=Pki.getInstance("netca");
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        IEnvelopedDataMultiStepEncrypt encryptObj=null;
        try{
        	cert=pki.decodeCert(certData);
        	encryptObj=pki.getEnvelopedDataMultiStepEncryptObject();
        	encryptObj.addCert(cert);
        	encrypt(encryptObj,clearFileName,cipherName);
        	System.out.println("Success");
        } finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (encryptObj instanceof Freeable) {
        		((Freeable)encryptObj).free();
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
	
	
	private static void encrypt(IEnvelopedDataMultiStepEncrypt encryptObj,String inFileName,String outFileName) throws Exception{
		FileInputStream fIn=null;
		FileOutputStream fout=null;
		byte[] data=new byte[8192];
		int len;
		byte[] outData;
		try {
			fIn=new FileInputStream(inFileName);
			fout=new FileOutputStream(outFileName);
			outData=encryptObj.encryptInit();
			fout.write(outData);
			for(;;){
				len=fIn.read(data);
				if(len==-1) {
					break;
				}
				outData=encryptObj.encryptUpdate(data, 0, len);
				fout.write(outData);
			}
			outData=encryptObj.encryptFinal();
			fout.write(outData);
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
