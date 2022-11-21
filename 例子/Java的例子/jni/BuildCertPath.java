import net.netca.pki.*;
import java.io.*;

public class BuildCertPath {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=1) {
            System.out.println("Usage: java BuildCertPath cert");
            return;
        }


        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        Certificate [] certpath=null;
        try {
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            certpath=cert.buildCertPath();
            for(int i=0; i<certpath.length; i++) {
                System.out.println(certpath[i].getSubject());
            }

        } finally {
            if(fIn!=null) {
                fIn.close();
            }


            if(cert!=null) {
                cert.free();
            }

            if(certpath!=null) {
                for(int i=0; i<certpath.length; i++) {
                    certpath[i].free();
                }
            }

        }

    }


}
