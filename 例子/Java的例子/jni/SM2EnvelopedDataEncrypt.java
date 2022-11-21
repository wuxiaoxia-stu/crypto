import net.netca.pki.*;
import java.io.*;

public class SM2EnvelopedDataEncrypt {
    public static void main(String[] arg) throws Exception {

        if(arg.length!=3) {
            System.out.println("Usage: java SM2EnvelopedDataEncrypt cert infile outfile");
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
            env=new EnvelopedData(true);
            env.setEncryptAlgorithm(EnvelopedData.AES256CBC);

            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            env.addCertificate(cert,false);
            cert.free();
            cert=null;

            fIn=new FileInputStream(arg[1]);
            fOut=new FileOutputStream(arg[2]);

            env.setIntegerAttribute(EnvelopedData.ATTRIBUTE_USE_SM2_Q7, 1);
            out=env.encryptInit();
            fOut.write(out);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                out=env.encryptUpdate(in,0,len);
                fOut.write(out);
            }
            out=env.encryptFinal();
            fOut.write(out);
            System.out.println("Success");
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



}
