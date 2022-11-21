import java.io.File;
import java.io.FileInputStream;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.scvp.HttpSCVPVerifyCert;
import net.netca.pki.encoding.asn1.pki.scvp.CertReply;
public class SCVPVerifyCert {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java SCVPGetCertPath url pkcFileName scvpCertFileName");
            return;
        }
		String url=args[0];
		String certFileName=args[1];
		String scvpCertFileName=args[2];
		
		byte[] data=readFile(certFileName);
		X509Certificate cert=new X509Certificate(data);
		
		data=readFile(scvpCertFileName);
		X509Certificate scvpCert=new X509Certificate(data);
		
		
		HttpSCVPVerifyCert verifyCert=new HttpSCVPVerifyCert();
		verifyCert.setCert(cert);
		verifyCert.setOnlyGetStatus(true);
		verifyCert.setSCVPServerCert(scvpCert);
		verifyCert.setVerifyRevoke(true);
		int status=verifyCert.getStatus(url);
		System.out.println(getReplyStatusString(status));
			
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
	
	
	private static String getReplyStatusString(int replyStatus) throws Exception{
		switch(replyStatus){
		case CertReply.SUCCESS:
			return "success";
		case CertReply.MALFORMED_PKC:
			return "malformedPKC";
		case CertReply.MALFORMED_AC:
			return "malformedAC";
		case CertReply.UNAVAILABLE_VALIDATION_TIME:
			return "unavailableValidationTime";
		case CertReply.REFERENCE_CERT_HASH_FAIL:
			return "referenceCertHashFail";
		case CertReply.CERT_PATH_CONSTRUCT_FAIL:
			return "certPathConstructFail";
		case CertReply.CERT_PATH_NOT_VALID:
			return "certPathNotValid";
		case CertReply.CERT_PATH_NOT_VALID_NOW:
			return "certPathNotValidNow";
		case CertReply.WANT_BACK_UNSATISFIED:
			return "wantBackUnsatisfied";
		default:
			return ""+replyStatus;
		}
	}
	
}
