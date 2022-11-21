import net.netca.pki.*;
import java.io.*;

public class AesCbc {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=5) {
            System.out.println("Usage: java AesCbc -e|-d key iv inFile outFile");
            return;
        }
        int algo=Cipher.AES_CBC;
        boolean enc;

        if(arg[0].equals("-e") || arg[0].equals("/e")) {
            enc=true;
        } else if(arg[0].equals("-d") || arg[0].equals("/d")) {
            enc=false;
        } else {
            System.out.println("Usage: java AesCbc -e|-d key iv inFile outFile");
            return;
        }

        Cipher cipher=new Cipher(algo);
        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        byte[]out;
        int len;
        try {
            cipher.setKey(Util.HexDecode(arg[1]));
            cipher.setIV(Util.HexDecode(arg[2]));
            cipher.setPadding(Cipher.PADDING_PKCS5);
            cipher.init(enc);
            fIn=new FileInputStream(arg[3]);
            fOut=new FileOutputStream(arg[4]);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                out=cipher.update(in,0,len);
                fOut.write(out);
            }
            out=cipher.doFinal();
            fOut.write(out);
            System.out.println("Success");
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }
            cipher.free();
        }

    }
}
