import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.RevokeInfo;
import net.netca.pki.encoding.asn1.pki.*;

public class VerifyCertPath3 {

	public static void main(String[] args) throws Exception{
		
		if(args.length<2) {
            System.out.println("Usage: java VerifyCertPath3 rootCertFileName  [caCertFileName1 ... caCertFileNameN] certFileName");
            return;
        }
		int certCount=args.length;
		X509Certificate[] certPath=new X509Certificate[certCount];
		for(int i=0;i<certCount;i++){
			certPath[i]=getCert(args[i]);
		}
		X509CertificatePathValidator validator=new X509CertificatePathValidator();
		validator.setVerifier(new JCEVerifier());
		validator.setVerifyLevel(X509CertificatePathValidator.VERIFY_LEVEL_VERIFY_CERTPATH_REVOKE);
		validator.setOption(X509CertificatePathValidator.VERIFY_OPTION_ONLINE_GETCRL);
		try{
			validator.verify(certPath);
			System.out.println("证书路径验证成功");
		}catch(NoRevokeInfoException e1) {
			System.out.printf("证书%d没有作废信息用来验证作废状态\n",validator.getNoRevokeInfoCertIndex());
		}catch(CertStatusRevokedException e2) {
			RevokeInfo revokeInfo=validator.getRevokeInfo();
			System.out.printf("证书%d已经作废，作废时间是%s，作废原因是%s\n",validator.getRevokedCertIndex(),
					revokeInfo.getTime().toString(),getReasonString(revokeInfo.getReason()));
		} catch(CertStatusUndeterminedException e3) {
			System.out.printf("证书%d的作废状态不能确定\n",validator.getUndeterminerCertIndex());
		}
	}
	
	static String getReasonString(int reason) {
        if(reason==-1) {
            return "没说明作废原因";
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
