import net.netca.pki.*;
import java.io.*;

public class Verify {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=4) {
            System.out.println("Usage: java Verify sha1withRSA|sha256withRSA cert tbs signature");
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
            System.out.println("Usage: java Verify sha1withRSA|sha256withRSA cert tbs signature");
            return;
        }

        Certificate cert=null;
        PublicKey publicKey=null;
        Signature sign=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            publicKey=cert.getPublicKey(Certificate.PURPOSE_SIGN);
            cert.free();
            cert=null;
            if(publicKey==null) {
                System.out.println("Get Signature Public Key Fail");
                return;
            }

            sign=new Signature(algo,publicKey);
            publicKey.free();
            publicKey=null;

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

            fIn=new FileInputStream(arg[3]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;

            byte[] signValue=new byte[len];
            System.arraycopy(in,0,signValue,0,len);
            if(sign.verify(signValue)) {
                System.out.println("Verify Success");
            } else {
                System.out.println("Verify Fail");
            }
        } finally {
            if(fIn!=null) {
                fIn.close();
            }


            if(cert!=null) {
                cert.free();
            }

            if(publicKey!=null) {
                publicKey.free();
            }

            if(sign!=null) {
                sign.free();
            }
        }

    }
}
