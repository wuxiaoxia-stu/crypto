import net.netca.pki.*;
import java.io.*;

public class DetachedVerifyFile {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java DetachedVerifyFile tbsFile signFile");
            return;
        }


        FileInputStream fIn=null;
        byte [] in=new byte[16384];
        int len;
        Certificate cert=null;
        SignedData sign=null;
        try {

            sign=new  SignedData(false);


            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;

            sign.detachedVerifyInit(in,0,len);

            fIn=new FileInputStream(arg[0]);
            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                sign.detachedVerifyUpdate(in,0,len);
            }
            sign.detachedVerifyFinal();
            fIn.close();
            fIn=null;

            cert=sign.getSignCertificate(0);
            System.out.println("验证成功");
            System.out.println("签名证书的主体："+cert.getSubject());
        } finally {
            if(fIn!=null) {
                fIn.close();
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
