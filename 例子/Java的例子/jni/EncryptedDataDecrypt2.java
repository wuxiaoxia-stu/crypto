import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import net.netca.pki.Util;

public class EncryptedDataDecrypt2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
			usage();
            return;
        }
		
		String pwd=args[0];
		String inFileName=args[1];
		String outFileName=args[2];
		
		byte[] cipher=readFile(inFileName);
		byte[] clear=Util.encryptedDataDecryptByPwd(
				pwd.getBytes("UTF-8"),cipher);
		writeFile(outFileName,clear);
		System.out.println("Success");

	}

	private static void usage() {
		System.out.println("Usage: java EncryptedDataDecrypt pwd cipherFile clearFile");
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
