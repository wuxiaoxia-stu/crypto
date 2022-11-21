import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.Pki;
import net.netca.pki.global.X509Certificate;
import net.netca.pki.global.RevokeInfo;

public class VerifyCert {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java VerifyCert certFileName");
            return;
        }
		
		int flag=0;
		flag=X509Certificate.STATUS_VERIFY_FLAG_VERIFY_REVOKE|
				X509Certificate.STATUS_VERIFY_FLAG_VERIFY_CRL|
				X509Certificate.STATUS_VERIFY_FLAG_ONLINE;
		String certFileName=args[0];
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try {
        	byte[] certData=readFile(certFileName);
	        cert=pki.decodeCert(certData);
	        int status=cert.verify(flag);
	        if(status==X509Certificate.STATUS_UNREVOKED) {
	        	System.out.println("证书正常");
	        } else if(status==X509Certificate.STATUS_REVOKED || 
	        		status==X509Certificate.STATUS_CA_REVOKED) {
	        	if(status==X509Certificate.STATUS_REVOKED) {
	        		System.out.println("证书作废");
	        	} else {
	        		System.out.println("证书路径中存在已经作废的CA证书");
	        	}
	        	RevokeInfo revokeInfo=cert.getRevokeInfo();
	        	PrintReason(revokeInfo.getReason());
	        	System.out.println("作废时间:"+revokeInfo.getTime());
	        	
	        } else {
	        	System.out.println("证书状态不确定");
	        }
        } finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
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
	
	static void PrintReason(int reason) {
        if(reason==-1) {
            System.out.println("作废原因: 没说明作废原因");
        } else if(reason==RevokeInfo.UNSPECIFIED) {
            System.out.println("作废原因: 未指定");
        } else if(reason==RevokeInfo.KEYCOMPROMISE) {
            System.out.println("作废原因: 密钥泄露");
        } else if(reason==RevokeInfo.CACOMPROMISE) {
            System.out.println("作废原因: 本身是CA证书，其密钥泄露");
        } else if(reason==RevokeInfo.AFFILIATION_CHANGED) {
            System.out.println("作废原因: 附属关系改变");
        } else if(reason==RevokeInfo.SUPERSEDED) {
            System.out.println("作废原因: 被取代");
        } else if(reason==RevokeInfo.CESSATION_OF_OPERATION) {
            System.out.println("作废原因: 停止操作");
        } else if(reason==RevokeInfo.CERTIFATE_HOLD) {
            System.out.println("作废原因: 临时作废");
        } else {
            System.out.println("作废原因: 未知的作废原因("+reason+")");
        }
    }
	
	private static Pki getPkiObject() throws Exception{
		String name=System.getProperty("pkiName");
		if(name==null) {
			name="netca";
		}
		String fileName=System.getProperty("pkiParamFileName");
		String param;
		if(fileName==null) {
			param=System.getProperty("pkiParam");
			if(param==null) {
				return Pki.getInstance(name);
			} else {
				return Pki.getInstance(name,param);
			}
		} else {
			byte[] data=readFile(fileName);
			if(data.length>=3 && data[0]==-17 && data[1]==-69 && data[2]==-65) {
				param=new String(data,3,data.length-3,"UTF-8");
			} else {
				param=new String(data,"UTF-8");
			}
			return Pki.getInstance(name,param);
		}
	}
}
