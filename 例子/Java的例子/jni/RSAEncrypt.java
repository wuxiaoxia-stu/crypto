import net.netca.pki.*;
import java.io.*;

public class RSAEncrypt {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java RSAEncrypt cert clear");
            return;
        }
        int algo=KeyPair.RSA_PKCS1_V1_5_ENC;
        Certificate cert=null;
        PublicKey pubkey=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            pubkey=cert.getPublicKey(Certificate.PURPOSE_ENCRYPT);
            cert.free();
            cert=null;
            if(pubkey==null) {
                System.out.println("Get Encrypt PublicKey Fail");
                return;
            }
            byte[] cipher=pubkey.encrypt(algo,arg[1].getBytes("UTF-8"));
            System.out.println(Util.HexEncode(true,cipher));
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(cert!=null) {
                cert.free();
            }

            if(pubkey!=null) {
                pubkey.free();
            }
        }

    }
}
