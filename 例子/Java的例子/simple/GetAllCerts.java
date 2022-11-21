import java.util.Iterator;
import java.util.List;

import net.netca.pki.Freeable;
import net.netca.pki.global.Pki;
import net.netca.pki.global.X509Certificate;

public class GetAllCerts {

	public static void main(String[] args)  throws Exception{
		Pki pki=Pki.getInstance("netca");
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        List<X509Certificate> certs=null;
        Iterator<X509Certificate> it;

        try {
        	certs=pki.getAllCertificates();
        	it=certs.iterator();
        	int index=1;
        	while(it.hasNext()) {
        		cert=it.next();
        		System.out.println("Cert "+index+":");
        		System.out.println("\tSubject:"+cert.getSubject());
        		System.out.println("\tEnd Date:"+cert.getValidityEnd());
        		index++;
        	}
        } finally {
        	if(certs!=null) {
	        	it=certs.iterator();
	        	while(it.hasNext()) {
	        		cert=it.next();
	        		if (cert instanceof Freeable) {
	            		((Freeable)cert).free();
	            	}
	        	}
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
        	}
        }

	}

}
