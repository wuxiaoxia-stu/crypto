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
			    		System.out.println("Ҫ��֤��֤��ֻ����һ��");
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
				System.out.println("û��Ҫ��֤��֤��");
				return;
			}
			int status=certVerify.verify(cert);
			if(status==CertVerify.CERT_STATUS_UNREVOKED){
				System.out.println("֤��û������");
				return;
			}else if(status==CertVerify.STATUS_UNDETERMINED){
				System.out.println("֤���״̬����ȷ��");
				return;
			}else if(status==CertVerify.STATUS_CA_REVOKED
					||status==CertVerify.STATUS_REVOKED){
				if(status==CertVerify.STATUS_CA_REVOKED){
					System.out.println("CA֤���Ѿ�����");
				}else{
					System.out.println("֤���Ѿ�����");
				}
				RevokeInfo revInfo=certVerify.getRevokeInfo();
				System.out.println("����ʱ�䣺"+revInfo.getTime());
				System.out.println("����ԭ��"+getReasonString(revInfo.getReason()));
				return;
				
			}else{
				System.out.println("֤����֤ʧ�ܣ�ԭ��"+getStatusString(status));
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
            return "û������ԭ��";
        } else if(reason==RevokeInfo.UNSPECIFIED) {
            return "δָ��";
        } else if(reason==RevokeInfo.KEYCOMPROMISE) {
        	return "��Կй¶";
        } else if(reason==RevokeInfo.CACOMPROMISE) {
            return "������CA֤�飬����Կй¶";
        } else if(reason==RevokeInfo.AFFILIATION_CHANGED) {
            return "������ϵ�ı�";
        } else if(reason==RevokeInfo.SUPERSEDED) {
            return "��ȡ��";
        } else if(reason==RevokeInfo.CESSATION_OF_OPERATION) {
            return "ֹͣ����";
        } else if(reason==RevokeInfo.CERTIFATE_HOLD) {
            return "��ʱ����";
        } else {
            return "δ֪������ԭ��("+reason+")";
        }
    }
	
	private static String getStatusString(int status) {
		switch(status){
		case CertVerify.STATUS_OTHER_ERROR:
			return "��������";
		case CertVerify.STATUS_BULID_CERTPATH_FAIL:
			return "����֤��·��ʧ��";
		case CertVerify.STATUS_VERIFY_CERTPATH_FAIL:
			return "��֤֤��·��ʧ��";
		case CertVerify.STATUS_NOT_IN_VALIDITY:
			return "֤�鲻����Ч����";
		case CertVerify.STATUS_NO_ROOTCERT:
			return "û�и�֤��";
		case CertVerify.STATUS_NO_REVOKE_INFO:
			return "û�к��ʵ�������Ϣ";
		case CertVerify.STATUS_NO_CA_REVOKE_INFO:
			return "û�к��ʵ�������Ϣ";
		default:
			return "δ֪��״̬("+status+")";
		}
	}
}
