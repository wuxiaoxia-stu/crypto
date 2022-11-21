import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.CertVerify;
import net.netca.pki.Certificate;
import net.netca.pki.Util;
import net.netca.pki.RevokeInfo;

public class VerifyCertPath2 {
	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if (argCount<2 || argCount%2!=0){
			usage();
			return;
		}
		CertVerify certVerify=new CertVerify();
		Certificate cert=null;
		Certificate rootCert=null;
		Certificate caCert=null;
		Certificate ocspCert=null;
		try{
			int i=0;
			while(i<argCount){
			    if (args[i].equals("-cert")){
			    	if(cert!=null){
			    		System.out.println("要验证的证书只能有一个");
						return;
			    	}
			        cert=readCert(args[i+1]);
			        i=i+2;
     
			    }else if(args[i].equals("-rootCert")){
			    	rootCert=readCert(args[i+1]);
			    	i=i+2;
			    	certVerify.addRootCert(rootCert);
			    	rootCert.free();
			    	rootCert=null;
			    }else if(args[i].equals("-caCert")){
			    	caCert=readCert(args[i+1]);
			    	i=i+2;
			    	certVerify.addCACert(caCert);
			    	caCert.free();
			    	caCert=null;
			    }else if(args[i].equals("-option")){
			    	int option=Integer.parseInt(args[i+1]);
			    	i=i+2;
			    	certVerify.setOption(option);
			    }else if(args[i].equals("-param")){
			    	certVerify.setParam(args[i+1]);
			    	i=i+2;
			    }else if(args[i].equals("-verifyTime")){
			    	certVerify.setVerifyTime(Util.UTCTimeDecode(args[i+1].getBytes("UTF-8")));
			    	i=i+2;
			    }else if(args[i].equals("-ignoreExt")){
			    	certVerify.addIgnoreExtension(args[i+1]);
			    	i=i+2;
			    }else if(args[i].equals("-crl")){
			    	byte[] crl=readFile(args[i+1]);
			    	i=i+2;
			    	certVerify.addCRL(crl);
			    } else if(args[i].equals("-ocsp")){
			    	byte[] ocsp=readFile(args[i+1]);
			    	i=i+2;
			    	if(i+2<=argCount && args[i].equals("-vaCert")){
			    		ocspCert=readCert(args[i+1]);
			    		certVerify.addOCSP(ocsp, ocspCert);
			    		i=i+2;
			    		ocspCert.free();
			    		ocspCert=null;
			    	}else{
			    		certVerify.addOCSP(ocsp);
			    	}
			    }else{
			    	usage();
			    	return;
			    }
			}
			if(cert==null){
				System.out.println("没有要验证的证书");
				return;
			}
			int status=certVerify.verify(cert);
			if(status==CertVerify.CERT_STATUS_UNREVOKED){
				System.out.println("证书没有作废");
				return;
			}else if(status==CertVerify.STATUS_UNDETERMINED){
				System.out.println("证书的状态不能确定");
				return;
			}else if(status==CertVerify.STATUS_CA_REVOKED
					||status==CertVerify.STATUS_REVOKED){
				if(status==CertVerify.STATUS_CA_REVOKED){
					System.out.println("CA证书已经作废");
				}else{
					System.out.println("证书已经作废");
				}
				RevokeInfo revInfo=certVerify.getRevokeInfo();
				System.out.println("作废时间："+revInfo.getTime());
				System.out.println("作废原因："+getReasonString(revInfo.getReason()));
				return;
				
			}else{
				System.out.println("证书验证失败，原因："+getStatusString(status));
				return;
			}
		}finally{
			certVerify.free();
			if(cert!=null){
				cert.free();
			}
			if(rootCert!=null){
				rootCert.free();
			}
			if(caCert!=null){
				caCert.free();
			}
			if(ocspCert!=null){
				ocspCert.free();
			}
			
		}
	}
	
	private static void usage(){
		System.out.println("java VerifyCertPath2 -cert certFileName [-rootCert rootCertFileName -caCert caCertFileName -option option -param -param param -verifyTime verifyTime -ignoreExt extOid -crl crlFileName -ocsp ocspFileName -vaCert ocspCertFileName]");
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
	
	private static Certificate readCert(String fileName) throws Exception{
		return new Certificate(readFile(fileName));
	}
	
	private static String getReasonString(int reason) {
        if(reason==-1) {
            return "没有作废原因";
        } else if(reason==RevokeInfo.UNSPECIFIED) {
            return "未指定";
        } else if(reason==RevokeInfo.KEYCOMPROMISE) {
        	return "密钥泄露";
        } else if(reason==RevokeInfo.CACOMPROMISE) {
            return "本身是CA证书，其密钥泄露";
        } else if(reason==RevokeInfo.AFFILIATION_CHANGED) {
            return "附属关系改变";
        } else if(reason==RevokeInfo.SUPERSEDED) {
            return "被取代";
        } else if(reason==RevokeInfo.CESSATION_OF_OPERATION) {
            return "停止操作";
        } else if(reason==RevokeInfo.CERTIFATE_HOLD) {
            return "临时作废";
        } else {
            return "未知的作废原因("+reason+")";
        }
    }
	
	private static String getStatusString(int status) {
		switch(status){
		case CertVerify.STATUS_OTHER_ERROR:
			return "其他错误";
		case CertVerify.STATUS_BULID_CERTPATH_FAIL:
			return "构造证书路径失败";
		case CertVerify.STATUS_VERIFY_CERTPATH_FAIL:
			return "验证证书路径失败";
		case CertVerify.STATUS_NOT_IN_VALIDITY:
			return "证书不在有效期内";
		case CertVerify.STATUS_NO_ROOTCERT:
			return "没有根证书";
		case CertVerify.STATUS_NO_REVOKE_INFO:
			return "没有合适的作废信息";
		case CertVerify.STATUS_NO_CA_REVOKE_INFO:
			return "没有合适的作废信息";
		default:
			return "未知的状态("+status+")";
		}
	}
}
