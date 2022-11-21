import net.netca.pki.*;
import java.io.*;

public class SignFile4 {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java SignFile4 cert inFile outFile");
            return;
        }


        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        byte[]out;
        int len;
        Certificate cert=null;
        SignedData sign=null;
        try {

            sign=new  SignedData(true);

            sign.setDetached(false);

            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;
            sign.setSignCertificate(cert);
            cert.free();
            cert=null;

            sign.setSignAlgorithm(0,Signature.SHA256WITHRSA);

            sign.addSignedAttribute(0, "1.2.3.4",new byte[] {
            		0x31,0x04,0x04,0x02,0x33,0x34});
            
            fIn=new FileInputStream(arg[1]);
            fOut=new FileOutputStream(arg[2]);
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
        }

    }
}
