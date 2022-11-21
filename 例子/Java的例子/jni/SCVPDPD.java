import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.SCVP;
import net.netca.pki.Certificate;
import net.netca.pki.RevokeInfoSource;
import net.netca.pki.Base64;

public class SCVPDPD {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java SCVPDPD url certFileName");
            return;
        }
		String url=args[0];
		String certFileName=args[1];
		int wantBackType=SCVP.WANTBACK_TYPE_CERT_PATH/*|SCVP.WANTBACK_TYPE_REVOCATION_INFO*/;
		int responseFlags=SCVP.RESPONSE_FLAGS_FULL_REQUEST_IN_RESPONSE;
		Certificate cert=null;
		Certificate [] certPath=null;
		Certificate [] rootCerts=null;
		
		try {
			cert=new Certificate(readFile(certFileName));
			SCVP scvp=new SCVP();
			certPath=scvp.DPD(cert, url, wantBackType, responseFlags);
						
			System.out.println("CertPath:");
			for(int i=0;i<certPath.length;i++) {
				System.out.println("\tCert "+i+":"+Base64.encode(Base64.ENCODE_NO_NL,certPath[i].derEncode()));
			}
			
			rootCerts=scvp.getRootCerts();
			if(rootCerts!=null) {
				System.out.println("RootCerts:");
				for(int i=0;i<rootCerts.length;i++) {
					System.out.println("\tRootCert "+i+":"+Base64.encode(Base64.ENCODE_NO_NL,rootCerts[i].derEncode()));
				}
			} else {
				System.out.println("no RootCert");
			}
			
			RevokeInfoSource[] revokeInfos=scvp.getRevokeInfoSource();
			if(revokeInfos!=null) {
				System.out.println("RevokeInfoSources:");
				for(int i=0;i<revokeInfos.length;i++) {
					System.out.println("\t" +
							getRevokeInfoSourceTypeName(revokeInfos[i].getType()) +
							" " +
							i+
							":"+
							Base64.encode(Base64.ENCODE_NO_NL,revokeInfos[i].getData()));
				}
			} else {
				System.out.println("no RevokeInfoSource");
			}
			
		}finally {
			if(cert!=null) {
				cert.free();
			}
			if(certPath!=null) {
				for(int i=0;i<certPath.length;i++) {
					certPath[i].free();
				}
			}
			if(rootCerts!=null) {
				for(int i=0;i<rootCerts.length;i++) {
					rootCerts[i].free();
				}
			}
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
	
	private static String getRevokeInfoSourceTypeName(int type) {
		if(type==RevokeInfoSource.CRL) {
			return "CRL";
		} else if(type==RevokeInfoSource.OCSP) {
			return "OCSP";
		} else {
			return "Unknown Type("+type+")";
		}
		
	}
}
