import net.netca.pki.*;
import java.io.*;

public class RSADecrypt {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java RSADecrypt cert cipher clear");
            return;
        }
        int algo=KeyPair.RSA_PKCS1_V1_5_ENC;
        Certificate cert=null;
        KeyPair keypair=null;
        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            keypair=cert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_CURRENT_USER,Certificate.PURPOSE_ENCRYPT,null);
            cert.free();
            cert=null;
            if(keypair==null) {
                System.out.println("Get Encrypt KeyPair Fail");
                return;
            }
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
            byte[] clear=keypair.decrypt(algo,in,0,len);
            fOut=new FileOutputStream(arg[2]);
            fOut.write(clear);
            System.out.println("Success");
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }

            if(cert!=null) {
                cert.free();
            }

            if(keypair!=null) {
                keypair.free();
            }
        }

    }
}
