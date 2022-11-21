import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.encoding.asn1.pki.X509CRL;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.*;

public class CreateP7b {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount<=1){
			usage();
	        return;
		}
		if((argCount-1)%2!=0) {
			usage();
	        return;
		}
		String p7bFileName=args[0];
		SignedDataBuilder builder=new SignedDataBuilder();
		builder.setDetached(true);
		byte[] data;
		X509Certificate cert;
		X509CRL crl;
		for(int i=1;i<argCount;i+=2){
			if(args[i].equals("-cert")
					|| args[i].equals("/cert")){
				data=readFile(args[i+1]);
				cert=new X509Certificate(data);
				builder.addX509PublicKeyCertificate(cert);
			} else if(args[i].equals("-crl")
					|| args[i].equals("/crl")){
				data=readFile(args[i+1]);
				crl=new X509CRL(data);
				builder.addCRL(crl);
			} else {
				usage();
		        return;
			}
		}
		SignedData signObj=builder.sign();
		data=signObj.encode(true);
		save(p7bFileName,data);
		System.out.println("Success");
				
	}
	private static void usage(){
		System.out.println("Usage: java CreateP7b p7bFileName [-cert certFileName] [-crl crlFileName]");
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
}
