import net.netca.pki.*;
import java.io.*;

public class AesGcm {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=6 && arg.length!=7) {
            System.out.println("Usage: java AesGcm -e|-d key iv tLen [aad] inFile outFile");
            return;
        }
        int algo=Cipher.AES_GCM;
        boolean enc;

        if(arg[0].equals("-e") || arg[0].equals("/e")) {
            enc=true;
        } else if(arg[0].equals("-d") || arg[0].equals("/d")) {
            enc=false;
        } else {
            System.out.println("Usage: java AesGcm -e|-d key iv tLen [aad] inFile outFile");
            return;
        }

        byte[] key=Util.HexDecode(arg[1]);
        byte[] iv=Util.HexDecode(arg[2]);
        int tLen=Integer.parseInt(arg[3]);
        byte[] aad;
        String inFileName;
        String outFileName;
        
        if(arg.length==6) {
        	aad=null;
        	inFileName=arg[4];
        	outFileName=arg[5];
        } else {
        	aad=Util.HexDecode(arg[4]);
        	inFileName=arg[5];
        	outFileName=arg[6];
        }
        Cipher cipher=new Cipher(algo);
        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        File f;
        byte [] in;
        byte[]out;
        int len;
        try {
            cipher.setKey(key);
            cipher.setGcmParam(tLen, iv, aad);
            cipher.init(enc);
            f=new File(inFileName);
            if(f.length()>Integer.MAX_VALUE) {
            	System.out.println("ÎÄ¼þÌ«´ó");
                return;
            }
            in=new byte[(int)f.length()];
            fIn=new FileInputStream(f);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
            out=cipher.cipher(in,0,len);
            
            fOut=new FileOutputStream(outFileName);
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
