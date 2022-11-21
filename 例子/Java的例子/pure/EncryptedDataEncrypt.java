import net.netca.pki.encoding.asn1.pki.cms.EncryptedData;
import net.netca.pki.encoding.asn1.pki.cms.EncryptedDataBuilder;
import net.netca.pki.encoding.asn1.pki.Pkcs5PBKDF2;
import net.netca.pki.encoding.asn1.pki.NetcaSecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.NetcaSymEncrypter;
import net.netca.pki.encoding.asn1.pki.NetcaHasher;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;


public class EncryptedDataEncrypt {

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
		
		Pkcs5PBKDF2 kdf=new Pkcs5PBKDF2(new NetcaHasher());
		EncryptedData encryptedData=EncryptedDataBuilder.getInstance()
			.setEncryptAlgorithm(encAlgo)
			.setPkcs5KDFImplement(kdf, hashAlgo, 64, 8192)
			.setPwd(pwd)
			.setSymEncrypter(new NetcaSymEncrypter())
			.setSecureRandomGenerator(new NetcaSecureRandomGenerator())
			.encypt(clear);
		byte[] cipher=encryptedData.encode(true);
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
			return EncryptedDataBuilder.AES_128;
		} else if(upperName.equals("AES-192")
				|| upperName.equals("AES192")) {
			return EncryptedDataBuilder.AES_192;
		} else if(upperName.equals("AES-256")
				|| upperName.equals("AES256")) {
			return EncryptedDataBuilder.AES_256;
		} /*else if(upperName.equals("SM1")) {
			return EncryptedDataBuilder.SM1;
		} else if(upperName.equals("SSF33")) {
			return EncryptedDataBuilder.SSF33;
		}*/ else if(upperName.equals("SM4")) {
			return EncryptedDataBuilder.SM4;
		} else {
			throw new Exception("不支持的加密算法:"+name);
		}
	}
	private static int getHashAlgo(String name) throws Exception{
		String upperName=name.toUpperCase();
		if(upperName.equals("SHA-1")
				|| upperName.equals("SHA1")) {
			return EncryptedDataBuilder.SHA1;
		} else if(upperName.equals("SHA-224")
				|| upperName.equals("SHA224")) {
			return EncryptedDataBuilder.SHA224;
		} else if(upperName.equals("SHA-256")
				|| upperName.equals("SHA256")) {
			return EncryptedDataBuilder.SHA256;
		} else if(upperName.equals("SHA-384")
				|| upperName.equals("SHA384")) {
			return EncryptedDataBuilder.SHA384;
		} else if(upperName.equals("SHA-512")
				|| upperName.equals("SHA512")) {
			return EncryptedDataBuilder.SHA512;
		} else if(upperName.equals("SHA-512/224")
				|| upperName.equals("SHA512/224")) {
			return EncryptedDataBuilder.SHA512_224;
		} else if(upperName.equals("SHA-512/256")
				|| upperName.equals("SHA512/256")) {
			return EncryptedDataBuilder.SHA512_256;
		} else if(upperName.equals("SHA3-224")) {
			return EncryptedDataBuilder.SHA3_224;
		} else if(upperName.equals("SHA3-256")) {
			return EncryptedDataBuilder.SHA3_256;
		} else if(upperName.equals("SHA3-384")) {
			return EncryptedDataBuilder.SHA3_384;
		} else if(upperName.equals("SHA3-512")) {
			return EncryptedDataBuilder.SHA3_512;
		} else if(upperName.equals("SM3")) {
			return EncryptedDataBuilder.SM3;
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
