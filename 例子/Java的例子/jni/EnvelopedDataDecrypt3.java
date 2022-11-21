import net.netca.pki.*;

import java.io.*;

/* 用于得安加密机 */
public class EnvelopedDataDecrypt3 {
    public static void main(String[] arg) throws Exception {

        if(arg.length!=4) {
            System.out.println("Usage: java EnvelopedDataDecrypt3 cert pwd infile outfile");
            return;
        }

        EnvelopedData env=null;
        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        FileOutputStream fOut=null;
        byte[]out;
        KeyPair keypair=null;
        try {
            env=new EnvelopedData(false);
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            keypair=cert.getKeyPair (Certificate.SEARCH_KEYPAIR_FLAG_DEVICE,Certificate.PURPOSE_ENCRYPT|Certificate.PURPOSE_KEYAGREEMENT,arg[1]);
            if(keypair==null) {
                System.out.println("No KeyPair");
                return;
            }

            keypair.free();
            keypair=null;

            env.addDecryptCertificate(cert);
            cert.free();
            cert=null;

            fIn=new FileInputStream(arg[2]);
            fOut=new FileOutputStream(arg[3]);

            env.decryptInit();
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                out=env.decryptUpdate(in,0,len);
                fOut.write(out);
            }
            env.decryptFinal();

            System.out.println("Decrypt Success");
            int algo=env.getEncryptAlgorithm();
            PrintEncAlgo(algo);

            cert=env.getDecryptCertificate();
            System.out.println("解密证书的主体: "+cert.getSubject());
        } finally {
            if(env!=null) {
                env.free();
            }

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

    static void PrintEncAlgo(int algo) {
        if(algo==EnvelopedData.DESCBC) {
            System.out.println("加密算法: DESCBC");
        } else if(algo==EnvelopedData.RC2CBC) {
            System.out.println("加密算法: RC2CBC");
        } else if(algo==EnvelopedData.TDESCBC) {
            System.out.println("加密算法: TDESCBC");
        } else if(algo==EnvelopedData.AES128CBC) {
            System.out.println("加密算法: AES128CBC");
        } else if(algo==EnvelopedData.AES192CBC) {
            System.out.println("加密算法: AES192CBC");
        } else if(algo==EnvelopedData.AES256CBC) {
            System.out.println("加密算法: AES256CBC");
        } else if(algo==EnvelopedData.SSF33CBC) {
            System.out.println("加密算法: SSF33CBC");
        } else if(algo==EnvelopedData.SM1CBC) {
            System.out.println("加密算法: SM1CBC");
        } else if(algo==EnvelopedData.SMS4CBC) {
            System.out.println("加密算法: SMS4CBC");
        } else {
            System.out.println("加密算法: 未知的加密算法("+algo+")");
        }
    }






}
