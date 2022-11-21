import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import net.netca.pki.Hash;
import net.netca.pki.Util;

public class SM4EncryptedDataEncrypt2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
			usage();
            return;
        }
		
		String pwd=args[0];
		String inFileName=args[1];
		String outFileName=args[2];
		
		int encAlgo=Util.ENCRYPTED_DATA_ALGORITHM_SM4CBC;
		int hashAlgo=Hash.SM3;
		byte[] clear=readFile(inFileName);
		
		int flag=Util.ENCRYPTED_DATA_FLAG_USE_Q7;
		int saltLen=32;
		int iterCount=10000;
		
		byte[] cipher=Util.pkcs5EncryptedDataEncrypt(flag, encAlgo,
				hashAlgo, saltLen, iterCount,
				pwd.getBytes("UTF-8"), clear);
		writeFile(outFileName,cipher);
		System.out.println("Success");

	}
	private static void usage() {
		System.out.println("Usage: java SM4EncryptedDataEncrypt pwd clearFile cipherFile");
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
	
	private static void writeFile(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
		
	}
}
