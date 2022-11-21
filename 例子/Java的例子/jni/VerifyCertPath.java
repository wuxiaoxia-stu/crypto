import net.netca.pki.*;
import java.io.*;

public class VerifyCertPath {
    public static void main(String[] arg) throws Exception {
        if(arg.length<2) {
            System.out.println("Usage: java VerifyCertPath cert [cacert ...] rootcert");
            return;
        }

        Certificate cert=null;
        Certificate rootCert=null;
        CertVerify verify=null;
	try {
        	cert=getCert(arg[0]);
        	int count=arg.length;
        	rootCert=getCert(arg[count-1]);
        	verify=new CertVerify();
		verify.addRootCert(rootCert);
		Certificate caCert=null;
        	for(int i=1;i<count-1;i++) {
			try {
		     		caCert=getCert(arg[i]);
        			verify.addCACert(caCert);
				caCert.free();
        			caCert=null;
			} finally {
				if(caCert!=null) {
					caCert.free();	
					caCert=null;
				}
			}
		}
		System.out.println(verify.verify(cert));
	} finally {
		if(cert!=null) {
			cert.free();
		}
		
		if(rootCert!=null) {
			rootCert.free();
		}
		
		if(verify!=null) {
			verify.free();
		}
	}		
    }	

    private static Certificate getCert(String fileName)throws Exception{
		byte [] in=new byte[8192];
		FileInputStream fIn=new FileInputStream(fileName);
		int len;
		len=fIn.read(in);
		Certificate cert=new Certificate(in,0,len);
		fIn.close();
		return cert;
	}


}
