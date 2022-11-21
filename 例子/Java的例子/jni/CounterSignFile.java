import net.netca.pki.*;
import java.io.*;

public class CounterSignFile {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java CounterSignFile oldsign cert newFile");
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

            sign=new  SignedData(false);

            sign.keepTbs(true);

            fIn=new FileInputStream(arg[0]);
            sign.verifyInit();
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                sign.verifyUpdate(in,0,len);
            }
            sign.verifyFinal();
            fIn.close();
            fIn=null;

            int count= sign.getSignerCount();
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            fOut=new FileOutputStream(arg[2]);
            out=sign.countersign(0,Signature.SHA1WITHRSA,cert,null);
            fOut.write(out);
            cert.free();
            cert=null;
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
