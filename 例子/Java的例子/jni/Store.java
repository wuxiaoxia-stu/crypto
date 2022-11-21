import net.netca.pki.*;
import java.io.*;

public class Store {
    public static void main(String[] arg) throws Exception {
        CertStore store=new CertStore(CertStore.CURRENT_USER,CertStore.MY);
        Certificate cert;
        int count=store.getCertificateCount();
        for(int i=0; i<count; i++) {
            cert=store.getCertificate(i);
            System.out.println(cert.getSubject());
            cert.free();
        }
        store.close();

    }



}
