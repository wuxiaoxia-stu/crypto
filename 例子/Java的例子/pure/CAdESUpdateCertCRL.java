import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.X509CRL;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.CertificateChoices;
import net.netca.pki.encoding.asn1.pki.cms.CertificateSet;
import net.netca.pki.encoding.asn1.pki.cms.OtherRevocationInfoFormat;
import net.netca.pki.encoding.asn1.pki.cms.RevocationInfoChoice;
import net.netca.pki.encoding.asn1.pki.cms.RevocationInfoChoices;
import net.netca.pki.encoding.asn1.pki.cms.SignedData;
import net.netca.pki.encoding.asn1.pki.ocsp.BasicOCSPResponse;
import net.netca.pki.encoding.asn1.pki.ocsp.OCSPResponse;

public class CAdESUpdateCertCRL {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount<2) {
			usage();
            return;
        }
		String oldSignedDataFileName=args[0];
		String outputFileName=args[1];
		int pos=2;
		
		byte[] signedData=readFile(oldSignedDataFileName);
		
		SignedData signedDataObj=new SignedData(signedData);
						
		X509Certificate cert;
		CertificateSet certs=new CertificateSet();
		String fileName;
		
		X509CRL crl;
		OCSPResponse ocsp;
		RevocationInfoChoices crls=new RevocationInfoChoices();
		
		int i=pos;
		while(i<argCount){
			if(args[i].equalsIgnoreCase("-cert")) {
				fileName=args[i+1];
				cert=getCert(fileName);
				certs.add(new CertificateChoices(cert));
				i+=2;
			} else if(args[i].equalsIgnoreCase("-crl")) {
				fileName=args[i+1];
				crl=getCRL(fileName);
				crls.add(new RevocationInfoChoice(crl));
				i+=2;
			} else if(args[i].equalsIgnoreCase("-ocsp")) {
				fileName=args[i+1];
				ocsp=getOCSP(fileName);
				crls.add(new RevocationInfoChoice(OtherRevocationInfoFormat.NewOCSPResponse(ocsp)));
				i+=2;
			} else {
				usage();
				return;
			}
			
		}
		if(i!=argCount){
			usage();
			return;
		}
		
		if(certs.size()==0){
			certs=null;
		}
		signedDataObj.setCertificates(certs);
		
		if(crls.size()==0){
			crls=null;
		}
		signedDataObj.setCrls(crls);
		signedData=signedDataObj.encode(signedDataObj.isContentInfo());
		SaveFile(outputFileName,signedData);
		System.out.println("替换证书和CRL成功");
	}
	private static void usage() {
		System.out.println("Usage: java CAdESUpdateCertCRL oldSignedDataFileName outputFileName "
        		+ "-cert certFileName1 [-cert certFileName2 ... -cert certFileNameN] "
        		+"-crl crlFileName1 [-crl crlFileName2 ... -crl crlFileNameN] "
        		+"-ocsp ocspFileName1 [-ocsp ocspFileName2 ... -ocsp ocspFileNameN]"
        		);
    }
	
	private static OCSPResponse getOCSP(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		OCSPResponse ocsp=null;
		try {
			ocsp=OCSPResponse.decode(data);
			return ocsp;
		} catch(PkiException e) {
			BasicOCSPResponse basicResp=BasicOCSPResponse.decode(data);
			return OCSPResponse.NewBasicOCSPResponse(basicResp);
		}
		
	}
	
	private static X509CRL getCRL(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509CRL(data);
	}
	
	private static X509Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509Certificate(data);
	}
	
	private static void SaveFile(String fileName,byte[] data)throws Exception {
		FileOutputStream f=new FileOutputStream(fileName);
		f.write(data);
		f.close();
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
