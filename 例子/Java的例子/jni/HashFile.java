import net.netca.pki.*;
import java.io.*;

public class HashFile {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java HashFile sha1|sha256|sm3 Filename");
            return;
        }
        int algo;

        if(arg[0].equals("md5")) {
            algo=Hash.MD5;
        } else if(arg[0].equals("sha1")) {
            algo=Hash.SHA1;
        } else if(arg[0].equals("sha224")) {
            algo=Hash.SHA224;
        } else if(arg[0].equals("sha256")) {
            algo=Hash.SHA256;
        } else if(arg[0].equals("sha384")) {
            algo=Hash.SHA384;
        } else if(arg[0].equals("sha512")) {
            algo=Hash.SHA512;
        } else if(arg[0].equals("sm3")) {
            algo=Hash.SM3;
        } else {
            System.out.println("Usage: java HashFile sha1|sha256|sm3 Filename");
            return;
        }

        Hash hash=new Hash(algo);
        FileInputStream fIn=null;
        byte [] data=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[1]);
            for(;;) {
                len=fIn.read(data);
                if(len<=0) {
                    break;
                }
                hash.update(data,0,len);
            }

            byte[] md=hash.doFinal();
            System.out.println(arg[0]+":"+Util.HexEncode(true,md));
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            hash.free();
        }

    }
}
