import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;

import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.scvp.PKCReference;
import net.netca.pki.encoding.asn1.pki.scvp.PKCReferences;
import net.netca.pki.encoding.asn1.pki.scvp.RevocationInfo;
import net.netca.pki.encoding.asn1.pki.scvp.ValidationPolicy;
import net.netca.pki.encoding.asn1.pki.scvp.HttpSCVPGetCertPath;

public class SCVPGetCertPath {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java SCVPGetCertPath url pkcFileName outputFileNamePrefix");
            return;
        }
		String url=args[0];
		String certFileName=args[1];
		String prefix=args[2];
				
		byte[] data=readFile(certFileName);
		X509Certificate cert=new X509Certificate(data);
		
		HttpSCVPGetCertPath getCertPath=new HttpSCVPGetCertPath();
		getCertPath.setCert(cert);
		getCertPath.setGetRevInfo(true);
		ArrayList<X509Certificate[]> certPaths=getCertPath.getCertPath(url);
		
		String fileName;
		int count;
		if(certPaths==null || certPaths.size()==0) {
			System.out.println("no cert path");
		} else {
			X509Certificate[] certPath;
			count=certPaths.size();
			System.out.println("has "+count+" cert path");
			for(int i=0;i<count;i++) {
				certPath=certPaths.get(i);
				for(int j=0;j<certPath.length;j++) {
					fileName=prefix+"cert_"+i+"_"+j+".cer";
					save(fileName,certPath[j].derEncode());
				}
				
			}
		}
		ArrayList<RevocationInfo> revInfos=getCertPath.getRevInfo();
		if(revInfos==null || revInfos.size()==0) {
			System.out.println("no rev info");
		} else {
			count=revInfos.size();
			System.out.println("has "+count+" RevocationInfo");
			saveRevocationInfos(prefix,revInfos);
		}
		ValidationPolicy respValidationPolicy=getCertPath.getValidationPolicy();
		if(respValidationPolicy==null){
			System.out.println("no respValidationPolicy");
		} else {
			PKCReferences trustAnchors=respValidationPolicy.getTrustAnchors();
			if(trustAnchors==null){
				System.out.println("no trustAnchor");
			} else {
				count=trustAnchors.size();
				System.out.println("has "+count+" trustAnchor");
				for(int i=0;i<count;i++){
					PKCReference trustAnchor=trustAnchors.get(i);
					if(trustAnchor.getType()==PKCReference.CERT_TYPE){
						cert=trustAnchor.getCert();
						save(prefix+"trustAnchor_"+i+".cer",cert.derEncode());
					}
				}
			}
		}
		
	}
	
	private static void saveRevocationInfos(String prefix,ArrayList<RevocationInfo> revocationInfos) throws Exception{
		int count=revocationInfos.size();
		String fileName;
		int type;
		RevocationInfo revocationInfo;
		for(int i=0;i<count;i++){
			revocationInfo=revocationInfos.get(i);
			type=revocationInfo.getType();
			if(type==RevocationInfo.CRL_TYPE){
				fileName=prefix+"crl_"+i+".crl";
				save(fileName,revocationInfo.getCRL().derEncode());
			} else if(type==RevocationInfo.DELTACRL_TYPE){
				fileName=prefix+"dcrl_"+i+".crl";
				save(fileName,revocationInfo.getDeltaCRL().derEncode());
			} else if(type==RevocationInfo.OCSP_TYPE){
				fileName=prefix+"ocsp_"+i+".ors";
				save(fileName,revocationInfo.getOcsp().derEncode());
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
}
