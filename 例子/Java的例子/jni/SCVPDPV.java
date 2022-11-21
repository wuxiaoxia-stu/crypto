import net.netca.pki.SCVP;

import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Certificate;
public class SCVPDPV {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java SCVPDPV url certFileName scvpCertFileName");
            return;
        }
		String url=args[0];
		String certFileName=args[1];
		String scvpCertFileName=args[2];
		
		boolean verifyRevoke=true;
		int responseFlags=SCVP.RESPONSE_FLAGS_FULL_REQUEST_IN_RESPONSE|SCVP.RESPONSE_FLAGS_PROTECT_RESPONSE;
		
		Certificate cert=null;
		Certificate scvpCert=null;
		try {
			cert=new Certificate(readFile(certFileName));
			scvpCert=new Certificate(readFile(scvpCertFileName));
			int status=SCVP.DPV(cert, url, verifyRevoke, responseFlags, scvpCert);
			System.out.println(getStatusName(status));
		}finally {
			if(cert!=null) {
				cert.free();
			}
			if(scvpCert!=null) {
				scvpCert.free();
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
	
	private static String getStatusName(int status) {
		switch(status) {
		case SCVP.CERT_STATUS_CONSTRUCT_FAIL:
			return "构造证书路径失败";
		case SCVP.CERT_STATUS_GOOD:
			return "正常";
		case SCVP.CERT_STATUS_NOT_VALID:
			return "无效";
		case SCVP.CERT_STATUS_NOT_VALID_NOW:
			return "当前时间无效";
		default:
			return "未知状态("+status+")";
					
		}
	}
}
