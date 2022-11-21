import net.netca.pki.*;

import java.io.*;

public class AttachTimeStamp {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java AttachTimeStamp oldsign url newFile");
            return;
        }


        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        byte[]out;
        int len;
        String url=arg[1];
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
                       
            sign.attachSignatureTimeStamp(count-1, Hash.SHA1, url);
            fOut=new FileOutputStream(arg[2]);
            out=sign.encode();
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

            
        }

    }
    
 }
