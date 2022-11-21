import net.netca.pki.*;
import java.io.*;

public class VerifyTimeStamp {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java VerifyTimeStamp infile token");
            return;
        }

        TimeStamp ts=null;
        Hash hash=null;
        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;

        try {
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;

            ts=new TimeStamp(in,0,len,null);


            int algo;
            algo=ts.getHashAlgorithm();

            hash=new Hash(algo);

            fIn=new FileInputStream(arg[0]);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                hash.update(in,0,len);
            }
            fIn.close();
            fIn=null;

            byte[] md=hash.doFinal();
            hash.free();
            hash=null;

            if(java.util.Arrays.equals(md,ts.getMessageImprint())==false) {
                System.out.println("Hash值不同");
                return;
            }

            System.out.println("时间戳时间： "+ts.getTime());

            cert=ts.getTsaCertificate();
            System.out.println("时间戳证书的主体：" +cert.getSubject() );
        } finally {
            if(fIn!=null) {
                fIn.close();
            }


            if(cert!=null) {
                cert.free();
            }

            if(ts!=null) {
                ts.free();
            }

            if(hash!=null) {
                hash.free();
            }
        }

    }


}
