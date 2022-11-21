import net.netca.pki.*;
import java.io.*;

public class Sign {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=4) {
            System.out.println("Usage: java Sign sha1withRSA|sha256withRSA cert tbs signature");
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
        } else  if(arg[0].equals("ECDSAWithSha1")) {
            algo=Signature.ECDSAWITHSHA1;
        } else  if(arg[0].equals("ECDSAWithSha224")) {
            algo=Signature.ECDSAWITHSHA224;
        } else  if(arg[0].equals("ECDSAWithSha256")) {
            algo=Signature.ECDSAWITHSHA256;
        } else  if(arg[0].equals("ECDSAWithSha384")) {
            algo=Signature.ECDSAWITHSHA384;
        } else  if(arg[0].equals("ECDSAWithSha512")) {
            algo=Signature.ECDSAWITHSHA512;
        } else  if(arg[0].equals("SM3WithSM2")) {
            algo=Signature.SM3WITHSM2;
        } else {
            System.out.println("Usage: java Sign sha1withRSA|sha256withRSA cert tbs signature");
            return;
        }

        Certificate cert=null;
        KeyPair keypair=null;
        Signature sign=null;
        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            keypair=cert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_CURRENT_USER,Certificate.PURPOSE_SIGN,null);
            cert.free();
            cert=null;
            if(keypair==null) {
                System.out.println("Get Signature KeyPair Fail");
                return;
            }

            sign=new Signature(algo,keypair);
            keypair.free();
            keypair=null;

            fIn=new FileInputStream(arg[2]);
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
            fOut=new FileOutputStream(arg[3]);
            fOut.write(signValue);
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

            if(sign!=null) {
                sign.free();
            }
        }

    }
}
