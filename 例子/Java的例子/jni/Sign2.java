import net.netca.pki.*;
import java.io.*;
import java.security.*;
import net.netca.pki.Signature;
import net.netca.pki.KeyPair;

public class Sign2 {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=6) {
            System.out.println("Usage: java Sign2 sha1withRSA|sha256withRSA keystoreName alias pwd tbs signature");
            return;
        }
        int algo;

        if(arg[0].equals("sha1withRSA")) {
            algo=Signature.SHA1WITHRSA;
        } else  if(arg[0].equals("sha256withRSA")) {
            algo=Signature.SHA256WITHRSA;
        } else  if(arg[0].equals("sha512withRSA")) {
            algo=Signature.SHA512WITHRSA;
        } else  if(arg[0].equals("md5withRSA")) {
            algo=Signature.MD5WITHRSA;
        } else  if(arg[0].equals("sha224withRSA")) {
            algo=Signature.SHA224WITHRSA;
        } else  if(arg[0].equals("sha384withRSA")) {
            algo=Signature.SHA384WITHRSA;
        } else {
            System.out.println("Usage: java Sign2 sha1withRSA|sha256withRSA keystoreName alias pwd tbs signature");
            return;
        }

        KeyStore keystore=KeyStore.getInstance(KeyStore.getDefaultType());
        FileInputStream fIn=null;
        fIn=new FileInputStream(arg[1]);
        keystore.load(fIn,arg[3].toCharArray());
        fIn.close();
        KeyPair keypair=null;
        Signature sign=null;
        fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        int len;
        try {

            keypair=Util.getKeyPairFromKeyStore(keystore,arg[2],arg[3]);
            if(keypair==null) {
                System.out.println("Get Signature KeyPair Fail");
                return;
            }

            sign=new Signature(algo,keypair);
            keypair.free();
            keypair=null;

            fIn=new FileInputStream(arg[4]);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                sign.update(in,0,len);
            }
            fIn.close();
            fIn=null;
            byte[] signValue=sign.sign();
            fOut=new FileOutputStream(arg[5]);
            fOut.write(signValue);
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

            if(sign!=null) {
                sign.free();
            }
        }

    }
}
