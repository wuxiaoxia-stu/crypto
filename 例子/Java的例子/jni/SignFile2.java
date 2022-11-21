import net.netca.pki.*;

import java.io.*;
import java.security.KeyStore;

public class SignFile2 {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=5) {
            System.out.println("Usage: java SignFile2 keystoreName cert pwd inFile outFile");
            return;
        }


        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        byte[]out;
        int len;
        Certificate cert=null;
        SignedData sign=null;
        KeyPair keypair=null;
        try {

            sign=new  SignedData(true);

            sign.setDetached(false);

            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            KeyStore keystore=KeyStore.getInstance(KeyStore.getDefaultType());
            fIn=new FileInputStream(arg[0]);
            keystore.load(fIn,arg[2].toCharArray());
            fIn.close();
            fIn=null;

            keypair=Util.getKeyPairFromKeyStore(keystore,cert,arg[2]);
            if(keypair==null) {
                System.out.println("Get Signature KeyPair Fail");
                return;
            }
            cert.setKeyPair(keypair);
            keypair.free();
            keypair=null;

            sign.setSignCertificate(cert);
            cert.free();
            cert=null;

            sign.setSignAlgorithm(0,Signature.SHA256WITHRSA);

            fIn=new FileInputStream(arg[3]);
            fOut=new FileOutputStream(arg[4]);
            out=sign.signInit();
            fOut.write(out);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                out=sign.signUpdate(in,0,len);
                fOut.write(out);
            }
            out=sign.signFinal();
            fOut.write(out);
            System.out.println("Success");
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }
            if(sign!=null) {
                sign.free();
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
