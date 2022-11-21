import net.netca.pki.Certificate;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;
import net.netca.pki.Certificate;
import java.io.*;
import java.util.ArrayList;

public class SignedDataVerify {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java SignedDataVerify signFile tbsFile");
            return;
        }


        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in;
        byte[] out;
        int len;
        X509Certificate cert=null;
        SignedData sign=null;
        File f;
        
        NetcaVerifier verifier=null;
        NetcaHasher hasher=null;
        try {

        	f=new File(arg[0]);
            if(f.length()>java.lang.Integer.MAX_VALUE) {
            	System.out.println("文件太大");
                return;
            }
            in=new byte[(int)f.length()];
            fIn=new FileInputStream(f);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
       
            sign=new SignedData(in);
            
            verifier=new NetcaVerifier();
            hasher=new NetcaHasher();
            int count=sign.getSignerInfoCount();
            for(int i=0;i<count;i++) {
            	if(sign.verify(i, verifier, hasher)==false) {
            		System.out.println("Verify Signature "+i+" Fail");
            	} else {
            		System.out.println("Verify Signature "+i+" Success");
            	}
            	cert=sign.getSignCert(i);
            	if(cert!=null) {
            		Certificate signCert=null;
            		try {
            			signCert=new Certificate(cert.derEncode());
            			System.out.println("签名证书"+ i +"的主体: "+signCert.getSubject());
            		} finally {
            			if(signCert!=null) {
            				signCert.free();
            			}
            		}
            	}
            }
            
            out=sign.getEncapContentInfo().getTbs();
            fOut=new FileOutputStream(arg[1]);
            fOut.write(out);
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }
            
            if(verifier!=null) {
            	verifier.free();
            }
            
            if(hasher!=null) {
            	hasher.free();
            }
        }

    }
}
