import net.netca.pki.*;
import java.io.*;

public class EnvelopedDataDecrypt {
    public static void main(String[] arg) throws Exception {

        if(arg.length!=2) {
            System.out.println("Usage: java EnvelopedDataDecrypt infile outfile");
            return;
        }

        EnvelopedData env=null;
        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        FileOutputStream fOut=null;
        byte[]out;

        try {
            env=new EnvelopedData(false);



            fIn=new FileInputStream(arg[0]);
            fOut=new FileOutputStream(arg[1]);

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
            System.out.println("����֤�������: "+cert.getSubject());
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
        }
    }

    static void PrintEncAlgo(int algo) {
        if(algo==EnvelopedData.DESCBC) {
            System.out.println("�����㷨: DESCBC");
        } else if(algo==EnvelopedData.RC2CBC) {
            System.out.println("�����㷨: RC2CBC");
        } else if(algo==EnvelopedData.TDESCBC) {
            System.out.println("�����㷨: TDESCBC");
        } else if(algo==EnvelopedData.AES128CBC) {
            System.out.println("�����㷨: AES128CBC");
        } else if(algo==EnvelopedData.AES192CBC) {
            System.out.println("�����㷨: AES192CBC");
        } else if(algo==EnvelopedData.AES256CBC) {
            System.out.println("�����㷨: AES256CBC");
        } else if(algo==EnvelopedData.SSF33CBC) {
            System.out.println("�����㷨: SSF33CBC");
        } else if(algo==EnvelopedData.SM1CBC) {
            System.out.println("�����㷨: SM1CBC");
        } else {
            System.out.println("�����㷨: δ֪�ļ����㷨("+algo+")");
        }
    }






}
