import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Hash;
import net.netca.pki.SESeal;
import net.netca.pki.TimeStamp;

public class AttachSESealTimeStamp2 {

	public static void main(String[] args)throws Exception {
		if(args.length!=4) {
            System.out.println("Usage: java AttachSESealTimeStamp2 oldSealFileName tsaUrl hashAlgo newSealFileName");
            return;
        }
		String oldSealFileName=args[0];
		String url=args[1];
		int hashAlgo =getHashAlgo(args[2]);
		String newSealFileName=args[3];
		
		byte[] sealData=readFile(oldSealFileName);
		SESeal seal=new SESeal(sealData);
		TimeStamp timeStamp=null;
		try{
			if(seal.getFormat()!=SESeal.GBT_38540){
				System.out.println("不是GB/T 38540的电子签章，不支持时间戳");
				return;
			}
			sealData=seal.attachTimeStamp(hashAlgo, url);
			timeStamp=seal.getTimeStamp();
			writeFile(newSealFileName,sealData);
			System.out.println("时间戳时间:"+timeStamp.getTime());
		}finally{
			if(timeStamp!=null){
				timeStamp.free();
			}
			seal.free();
		}
	}
	private static int getHashAlgo(String algo)throws Exception{
		algo=algo.toUpperCase();
		if(algo.equals("SHA1")|| algo.equals("SHA-1")|| algo.equals("1.3.14.3.2.26")){
			return Hash.SHA1;
		} else if(algo.equals("SHA224")|| algo.equals("SHA-224")|| algo.equals("2.16.840.1.101.3.4.2.4")){
			return Hash.SHA224;
		} else if(algo.equals("SHA256")|| algo.equals("SHA-256")|| algo.equals("2.16.840.1.101.3.4.2.1")){
			return Hash.SHA256;
		} else if(algo.equals("SHA384")|| algo.equals("SHA-384")|| algo.equals("2.16.840.1.101.3.4.2.2")){
			return Hash.SHA384;
		} else if(algo.equals("SHA512")|| algo.equals("SHA-512")|| algo.equals("2.16.840.1.101.3.4.2.3")){
			return Hash.SHA512;
		} else if(algo.equals("MD5")|| algo.equals("1.2.840.113549.2.5")){
			return Hash.MD5;
		} else if(algo.equals("SHA512/224")|| algo.equals("SHA-512/224") || algo.equals("2.16.840.1.101.3.4.2.5")){
			return Hash.SHA512_224;
		} else if(algo.equals("SHA512/256")|| algo.equals("SHA-512/256") || algo.equals("2.16.840.1.101.3.4.2.6")){
			return Hash.SHA512_256;
		} else if(algo.equals("SHA3-224")|| algo.equals("2.16.840.1.101.3.4.2.7")){
			return Hash.SHA3_224;
		} else if(algo.equals("SHA3-256")|| algo.equals("2.16.840.1.101.3.4.2.8")){
			return Hash.SHA3_256;
		} else if(algo.equals("SHA3-384")|| algo.equals("2.16.840.1.101.3.4.2.9")){
			return Hash.SHA3_384;
		} else if(algo.equals("SHA3-512")|| algo.equals("2.16.840.1.101.3.4.2.10")){
			return Hash.SHA3_512;
		} else if(algo.equals("SM3")|| algo.equals("1.2.156.10197.1.401")){
			return Hash.SM3;
		} else {
			throw new Exception("bad hash algo");
		}
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
	
}
