import net.netca.pki.*;
import java.io.*;

public class MacFile {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java MacFile hmac-sha1|hmac-sha256|hmac-sm3 key Filename");
            return;
        }
        int algo;

        if(arg[0].equals("hmac-md5")) {
            algo=Mac.HMAC_MD5;
        } else if(arg[0].equals("hmac-sha1")) {
            algo=Mac.HMAC_SHA1;
        } else if(arg[0].equals("hmac-sha224")) {
            algo=Mac.HMAC_SHA224;
        } else if(arg[0].equals("hmac-sha256")) {
            algo=Mac.HMAC_SHA256;
        } else if(arg[0].equals("hmac-sha384")) {
            algo=Mac.HMAC_SHA384;
        } else if(arg[0].equals("hmac-sha512")) {
            algo=Mac.HMAC_SHA512;
        } else if(arg[0].equals("hmac-sm3")) {
            algo=Mac.HMAC_SM3;
        } else {
            System.out.println("Usage: java MacFile hmac-sha1|hmac-sha256|hmac-sm3 key Filename");
            return;
        }

        Mac mac=new Mac(algo,Util.HexDecode(arg[1]));
        FileInputStream fIn=null;
        byte [] data=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[2]);
            for(;;) {
                len=fIn.read(data);
                if(len<=0) {
                    break;
                }
                mac.update(data,0,len);
            }

            byte[] value=mac.doFinal();
            System.out.println(Util.HexEncode(true,value));
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            mac.free();
        }

    }
}
