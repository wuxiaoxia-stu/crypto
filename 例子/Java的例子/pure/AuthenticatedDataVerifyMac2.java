import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.NetcaHasher;
import net.netca.pki.encoding.asn1.pki.NetcaKDF;
import net.netca.pki.encoding.asn1.pki.NetcaKeyUnwrap;
import net.netca.pki.encoding.asn1.pki.NetcaMac;
import net.netca.pki.encoding.asn1.pki.NetcaMyStore;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.AuthenticatedData;

public class AuthenticatedDataVerifyMac2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java AuthenticatedDataVerifyMac2 infile outfile");
            return;
        }
		String macFileName=args[0];
		String contentFileName=args[1];
		
		NetcaMyStore store=null;
		try{
			store=new NetcaMyStore();
			byte[] data=readFile(macFileName);
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
            System.out.println("֤�������: "+cert.getSubject().getLdapName());
		}finally{
			
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
			 System.out.println("MAC�㷨: HMAC-SHA-1");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA224_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA224");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA224_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA224");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA256_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA256");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA384_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA384");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA512_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA512");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_224_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA3_224");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_256_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA3_256");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_384_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA3_384");
	     } else if(algo.equals(AlgorithmIdentifier.HMAC_SHA3_512_OID)) {
	    	 System.out.println("MAC�㷨: HMAC-SHA3_512");
	     } else {
	    	 System.out.println("MAC�㷨: δ֪��MAC�㷨("+algo+")");
	     }
	}
}
