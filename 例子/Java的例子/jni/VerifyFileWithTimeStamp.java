import net.netca.pki.*;
import java.io.*;

public class VerifyFileWithTimeStamp {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java VerifyFileWithTimeStamp signFile tbsFile");
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


            fIn=new FileInputStream(arg[0]);
            fOut=new FileOutputStream(arg[1]);
            sign.verifyInit();

            for(;;) {
                len=fIn.read(in);
                if(len<=0) {
                    break;
                }
                out=sign.verifyUpdate(in,0,len);
                fOut.write(out);
            }
            sign.verifyFinal();
            fIn.close();
            fIn=null;
            fOut.close();
            fOut=null;



            System.out.println("验证成功");
            int count=sign.getSignerCount();
            System.out.println("共"+count+"个签名");
            for(int i=0; i<count; i++) {
                cert=sign.getSignCertificate(i);
                System.out.println("第"+(i+1)+"个签名证书的主体："+cert.getSubject());
                cert.free();
                cert=null;
            }

            int countersignCount;
            for(int i=0; i<count; i++) {
                if(sign.hasTimeStamp(i)) {
                    if(sign.verifyTimeStamp(i)==false) {
                        System.out.println("验证第"+(i+1)+"个签名的时间戳签名失败");
                    } else {
                        cert=sign.getTimeStampTsaCert(i);
                        System.out.println("第"+(i+1)+"个签名的时间戳签名的签名证书的主体："+cert.getSubject());
                        cert.free();
                        cert=null;
                        System.out.println("第"+(i+1)+"个签名的时间戳签名的时间："+sign.getTimeStampTime(i));
                    }
                }

            }


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
