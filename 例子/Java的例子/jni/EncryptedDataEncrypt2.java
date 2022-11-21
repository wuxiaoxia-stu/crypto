import net.netca.pki.Util;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import net.netca.pki.Hash;


public class EncryptedDataEncrypt2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=5) {
			usage();
            return;
        }
		
		String pwd=args[0];
		String encAlgoName=args[1];
		String hashAlgoName=args[2];
		String inFileName=args[3];
		String outFileName=args[4];
		
		int encAlgo=getEncAlgo(encAlgoName);
		int hashAlgo=getHashAlgo(hashAlgoName);
		byte[] clear=readFile(inFileName);
		int flag=0;
		int saltLen=32;
		int iterCount=8192;
		
		byte[] cipher=Util.pkcs5EncryptedDataEncrypt(flag, encAlgo,
				hashAlgo, saltLen, iterCount,
				pwd.getBytes("UTF-8"), clear);
		writeFile(outFileName,cipher);
		System.out.println("Success");

	}
	private static void usage() {
		System.out.println("Usage: java EncryptedDataEncrypt pwd aes-128|sm4 sha256|sm3 clearFile cipherFile");
	}
	private static int getEncAlgo(String name) throws Exception{
		String upperName=name.toUpperCase();
		if(upperName.equals("AES-128")
				|| upperName.equals("AES128")) {
			return Util.ENCRYPTED_DATA_ALGORITHM_AES128CBC;
		} else if(upperName.equals("AES-192")
				|| upperName.equals("AES192")) {
			return Util.ENCRYPTED_DATA_ALGORITHM_AES192CBC;
		} else if(upperName.equals("AES-256")
				|| upperName.equals("AES256")) {
			return Util.ENCRYPTED_DATA_ALGORITHM_AES256CBC;
		} else if(upperName.equals("SM1")) {
			return Util.ENCRYPTED_DATA_ALGORITHM_SM1CBC;
		} else if(upperName.equals("SSF33")) {
			return Util.ENCRYPTED_DATA_ALGORITHM_SSF33CBC;
		} else if(upperName.equals("SM4")) {
			return Util.ENCRYPTED_DATA_ALGORITHM_SM4CBC;
		} else {
			throw new Exception("不支持的加密算法:"+name);
		}
	}
	private static int getHashAlgo(String name) throws Exception{
		String upperName=name.toUpperCase();
		if(upperName.equals("SHA-1")
				|| upperName.equals("SHA1")) {
			return Hash.SHA1;
		} else if(upperName.equals("SHA-224")
				|| upperName.equals("SHA224")) {
			return Hash.SHA224;
		} else if(upperName.equals("SHA-256")
				|| upperName.equals("SHA256")) {
			return Hash.SHA256;
		} else if(upperName.equals("SHA-384")
				|| upperName.equals("SHA384")) {
			return Hash.SHA384;
		} else if(upperName.equals("SHA-512")
				|| upperName.equals("SHA512")) {
			return Hash.SHA512;
		} else if(upperName.equals("SHA-512/224")
				|| upperName.equals("SHA512/224")) {
			return Hash.SHA512_224;
		} else if(upperName.equals("SHA-512/256")
				|| upperName.equals("SHA512/256")) {
			return Hash.SHA512_256;
		} else if(upperName.equals("SHA3-224")) {
			return Hash.SHA3_224;
		} else if(upperName.equals("SHA3-256")) {
			return Hash.SHA3_256;
		} else if(upperName.equals("SHA3-384")) {
			return Hash.SHA3_384;
		} else if(upperName.equals("SHA3-512")) {
			return Hash.SHA3_512;
		} else if(upperName.equals("SM3")) {
			return Hash.SM3;
		} else {
			throw new Exception("不支持的Hash算法:"+name);
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
	
	private static void writeFile(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
		
	}
}
