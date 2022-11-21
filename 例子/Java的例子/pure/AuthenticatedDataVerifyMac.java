import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import net.netca.pki.CertStore;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;

public class AuthenticatedDataVerifyMac {

	public static void main(String[] args) throws Exception{
		if(args.length!=4) {
            System.out.println("Usage: java AuthenticatedDataVerifyMac pfxFile pwd infile outfile");
            return;
        }
		String pfxFileName=args[0];
		String pwd=args[1];
		String macFileName=args[2];
		String contentFileName=args[3];
		
		byte[] data=readFile(pfxFileName);
		CertStore certStore=CertStore.loadPfx(data, pwd);
		NetcaMyStore store=null;
		try{
			store=new NetcaMyStore(certStore);
			data=readFile(macFileName);
			AuthenticatedData authData=new AuthenticatedData(data);
			authData.setCertAndPrivKeys(store.iterator());
			authData.setHasher(new NetcaHasher());
			authData.setKDFImplement(new NetcaKDF());
			authData.setKeyUnwrapImplement(new NetcaKeyUnwrap());
			authData.setMacImplement(new NetcaMac());
			if(authData.verify()==false){
				System.out.println("verify mac fail");
				return;
			}
			byte[] content=authData.getEncapContentInfo().getTbs();
			save(contentFileName,content);
			System.out.println("verify Success");
            		
            PrintMacAlgo(authData.getMacAlgorithm().getOid());

            X509Certificate cert=authData.getDecryptCert();
            System.out.println("证书的主体: "+cert.getSubject().getLdapName());
		}finally{
			certStore.close();
			if(store!=null){
				store.free();
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
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
	}
	
	private static void PrintMacAlgo(String algo) {
		 if(algo.equals(AlgorithmIdentifier.HMAC_SHA1_OID)
				 || algo.equals(AlgorithmIdentifier.PKCS5_HMAC_SHA1_OID)) {
			 System.out.println("MAC算法: HMAC-SHA-1");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA224_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA224");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA224_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA224");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA256_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA256");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA384_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA384");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA512_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA512");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_224_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA3_224");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_256_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA3_256");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_384_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA3_384");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_512_OID)) {
	    	 System.out.println("MAC算法: HMAC-SHA3_512");
	     } else {
	    	 System.out.println("MAC算法: 未知的MAC算法("+algo+")");
	     }
	}
}
