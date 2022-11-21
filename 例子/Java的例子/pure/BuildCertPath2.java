import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.X509CertificatePathBuilder;

public class BuildCertPath2 {
	public static void main(String[] args) throws Exception{
		if(args.length<2) {
            System.out.println("Usage: java BuildCertPath2 certFileName rootCertFileName [caCertFileName1 ... caCertFileNameN]");
            return;
        }
		String certFileName=args[0];
		String rootCertFileName=args[1];
		
		X509Certificate cert=getCert(certFileName);
		X509Certificate rootCert=getCert(rootCertFileName);
		X509CertificatePathBuilder builder=new X509CertificatePathBuilder();
		builder.addRootCert(rootCert);
		
		X509Certificate caCert;
		for(int i=2;i<args.length;i++){
			caCert=getCert(args[i]);
			builder.addCACert(caCert);
		}
		ArrayList<X509Certificate[]> certPaths=builder.build(true, cert);
		int certPathCount=certPaths.size();
		System.out.printf("构造出%d条证书路径\n",certPathCount);
		for(int i=0;i<certPathCount;i++){
			printCertPath(i,certPaths.get(i));
		}
	
	}
	private static void printCertPath(int index,X509Certificate[] certPath) throws Exception{
		System.out.printf("第%d条证书路径\n",index);
		for(int i=0;i<certPath.length;i++){
			System.out.printf("\t%s\n",certPath[i].getSubject().getLdapName());
			
		}
	}
	
	private static X509Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509Certificate(data);
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
}
