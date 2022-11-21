import net.netca.pki.*;

import java.io.*;

public class VerifyCert2 {
    public static void main(String[] arg) throws Exception {
        if(arg.length<2) {
            System.out.println("Usage: java VerifyCert2 cert [cacert ...] rootcert");
            return;
        }


        Certificate cert=null;
        CertStore rootCerts=null;
        CertStore caCerts=null;
        int count=arg.length;
        try {
        	rootCerts=getCertStore(arg,count-1,count-1);
        	Util.setRootCert(Util.STORE_FLAG_REPLACE,rootCerts);
        	
        	caCerts=getCertStore(arg,1,count-2);
        	Util.setCACert(Util.STORE_FLAG_REPLACE,caCerts);
        	
        	cert=getCert(arg[0]);
                        
            int status=cert.verify(Certificate.STATUS_VERIFY_FLAG_VERIFY_REVOKE
                                   |Certificate.STATUS_VERIFY_FLAG_ONLINE
                                   |Certificate.STATUS_VERIFY_FLAG_VERIFY_CRL);
            if(status==Certificate.CERT_STATUS_UNREVOKED) {
                System.out.println("证书状态正常");
            } else if(status==Certificate.STATUS_UNDETERMINED) {
                System.out.println("不能确定证书的状态");
            } else if(status==Certificate.STATUS_REVOKED || status==Certificate.STATUS_CA_REVOKED) {
                RevokeInfo info=cert.getRevokeInfo();
                if(status==Certificate.STATUS_REVOKED) {
                	System.out.println("证书已经作废");
				} else {
					System.out.println("证书路径中存在已经作废的CA证书");
				}
		
                PrintReason(info.getReason());
                System.out.println("作废时间: "+info.getTime());
            }


        } finally {
            if(cert!=null) {
                cert.free();
            }
            
            if(rootCerts!=null) {
            	rootCerts.free();
            }
            
            if(caCerts!=null) {
            	caCerts.free();
            }

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

    private static Certificate getCert(String fileName)throws Exception{
		byte [] in=new byte[8192];
		FileInputStream fIn=new FileInputStream(fileName);
		try {
			int len;
			len=fIn.read(in);
			Certificate cert=new Certificate(in,0,len);
			return cert;
		} finally {
			fIn.close();
		}
	}
    
    
    private static CertStore getCertStore(String[] fileNames,int begin,int end)throws Exception{
    	CertStore store=CertStore.createMemoryStore();
    	Certificate cert;
    	try{
	    	for(int i=begin;i<=end;i++) {
	    		cert=getCert(fileNames[i]);
	    		store.addCertificate(cert);
	    		cert.free();
	    	}
	    	return store;
    	} catch(Exception e) {
    		store.free();
    		throw e;
    	}
	}
}
