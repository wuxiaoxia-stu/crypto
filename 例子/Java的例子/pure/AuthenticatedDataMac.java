import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Date;

import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;
import net.netca.pki.encoding.asn1.GeneralizedTime;
public class AuthenticatedDataMac {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java AuthenticatedDataMac cert infile outfile");
            return;
        }
		X509Certificate cert=null;
		String fileName=args[0];
		byte[] data;
		
		AuthenticatedDataBuilder builder=AuthenticatedDataBuilder.getInstance();
		data= readFile(fileName);
		cert=new X509Certificate(data);
		byte[] content= readFile(args[1]);
		Attribute attr=new Attribute(Attribute.SIGNING_TIME,new GeneralizedTime(new Date()));
		
		AuthenticatedData authData=builder.addCert(cert)
				.setPublicKeyEncrypter(new NetcaPublicKeyEncrypter())
				.setKeyAgreementImplement(new NetcaKeyAgreement())
				.setKDFImplement(new NetcaKDF())
				.setKeyWrapImplement(new NetcaKeyWrap())
				.setMacImplement(new NetcaMac())
				.setMacAlgorithm(AuthenticatedDataBuilder.HMAC_SHA256)
				.setContent(content)
				.setDigestAlgorithm(AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID))
				.setHasher(new NetcaHasher())
				.addAuthAttributes(attr)
				.mac();
		data=authData.encode(true);
						
		save(args[2],data);		
		System.out.println("Success");
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
