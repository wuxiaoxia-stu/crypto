import net.netca.pki.*;

import java.io.*;

import net.netca.pki.KeyPair;
import java.security.*;

public class RSADecrypt2 {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=5) {
            System.out.println("Usage: java RSADecrypt2 keystoreName alias pwd cipher clear");
            return;
        }
        int algo=KeyPair.RSA_PKCS1_V1_5_ENC;
        KeyStore keystore=KeyStore.getInstance(KeyStore.getDefaultType());
        FileInputStream fIn=null;
        fIn=new FileInputStream(arg[0]);
        keystore.load(fIn,arg[2].toCharArray());
        fIn.close();

        KeyPair keypair=null;
        fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        int len;
        try {
            keypair=Util.getKeyPairFromKeyStore(keystore,arg[1],arg[2]);
            if(keypair==null) {
                System.out.println("Get Enc KeyPair Fail");
                return;
            }

            fIn=new FileInputStream(arg[3]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
            byte[] clear=keypair.decrypt(algo,in,0,len);
            fOut=new FileOutputStream(arg[4]);
            fOut.write(clear);
            System.out.println("Success");
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }

            if(keypair!=null) {
                keypair.free();
            }
        }

    }
}
