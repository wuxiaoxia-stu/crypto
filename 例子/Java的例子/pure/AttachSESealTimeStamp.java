import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.seseal.Seal;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;

public class AttachSESealTimeStamp {

	public static void main(String[] args) throws Exception{
		if(args.length!=4) {
            System.out.println("Usage: java AttachSESealTimeStamp oldSealFileName tsaUrl hashAlgo newSealFileName");
            return;
        }
		String oldSealFileName=args[0];
		String url=args[1];
		AlgorithmIdentifier hashAlgo =getHashAlgo(args[2]);
		String newSealFileName=args[3];
		
		byte[] sealData=readFile(oldSealFileName);
		Seal seal=Seal.decode(sealData);
		
		if(seal.getSealType()!=Seal.GBT_38540){
			System.out.println("不是GB/T 38540的电子签章，不支持时间戳");
			return;
		}
		byte[] newSealData=seal.attachTimeStamp(url, hashAlgo);
		writeFile(newSealFileName,newSealData);
		System.out.println("时间戳时间:"+seal.getTimeStampTime());
	}
	
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
			throw new Exception("file too big:"+ fileName);
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail:" + fileName);
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}

	private static AlgorithmIdentifier getHashAlgo(String algo) throws PkiException{
		String upperAlgo=algo.toUpperCase();
		if(upperAlgo.equals("SM3")
				|| upperAlgo.equals(AlgorithmIdentifier.SM3_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3_OID);
		} else if(upperAlgo.equals("SHA-1")
				|| upperAlgo.equals("SHA1")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA1_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
		} else if(upperAlgo.equals("SHA-224")
				|| upperAlgo.equals("SHA224")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA224_OID);
		} else if(upperAlgo.equals("SHA-256")
				|| upperAlgo.equals("SHA256")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
		} else if(upperAlgo.equals("SHA-384")
				|| upperAlgo.equals("SHA384")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA384_OID);
		} else if(upperAlgo.equals("SHA-512")
				|| upperAlgo.equals("SHA512")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA512_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_OID);
		} else if(upperAlgo.equals("MD5")
				|| upperAlgo.equals(AlgorithmIdentifier.MD5_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.MD5_OID);
		} else if(upperAlgo.equals("SHA-512/224")
				|| upperAlgo.equals("SHA512/224")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA512_224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_224_OID);
		} else if(upperAlgo.equals("SHA-512/256")
				|| upperAlgo.equals("SHA512/256")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA512_256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_256_OID);
		} else if(upperAlgo.equals("SHA3-224")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA3_224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_224_OID);
		} else if(upperAlgo.equals("SHA3-256")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA3_256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_256_OID);
		} else if(upperAlgo.equals("SHA3-384")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA3_384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_384_OID);
		} else if(upperAlgo.equals("SHA3-512")
				|| upperAlgo.equals(AlgorithmIdentifier.SHA3_512_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_512_OID);
		} else {
			throw new PkiException("unkown algo:"+algo);
		}
	}
}
