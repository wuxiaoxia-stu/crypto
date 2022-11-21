import net.netca.pki.*;
import java.io.*;

public class Base64File {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java Base64File -e|-d inFile outFile");
            return;
        }

        boolean enc;
        int flag=0;

        if(arg[0].equals("-e") || arg[0].equals("/e")) {
            enc=true;

        } else if(arg[0].equals("-d") || arg[0].equals("/d")) {
            enc=false;
        } else {
            System.out.println("Usage: java Base64File -e|-d inFile outFile");
            return;
        }


        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        byte[]out;
        int len;
        Base64 b64=null;
        try {
            b64=new Base64(enc,flag);
            fIn=new FileInputStream(arg[1]);
            fOut=new FileOutputStream(arg[2]);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                out=b64.update(in,0,len);
                fOut.write(out);
            }
            out=b64.doFinal();
            fOut.write(out);
            System.out.println("Success");
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }
            if(b64!=null) {
                b64.free();
            }
        }

    }
}
