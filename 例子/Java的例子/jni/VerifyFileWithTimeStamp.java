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



            System.out.println("��֤�ɹ�");
            int count=sign.getSignerCount();
            System.out.println("��"+count+"��ǩ��");
            for(int i=0; i<count; i++) {
                cert=sign.getSignCertificate(i);
                System.out.println("��"+(i+1)+"��ǩ��֤������壺"+cert.getSubject());
                cert.free();
                cert=null;
            }

            int countersignCount;
            for(int i=0; i<count; i++) {
                if(sign.hasTimeStamp(i)) {
                    if(sign.verifyTimeStamp(i)==false) {
                        System.out.println("��֤��"+(i+1)+"��ǩ����ʱ���ǩ��ʧ��");
                    } else {
                        cert=sign.getTimeStampTsaCert(i);
                        System.out.println("��"+(i+1)+"��ǩ����ʱ���ǩ����ǩ��֤������壺"+cert.getSubject());
                        cert.free();
                        cert=null;
                        System.out.println("��"+(i+1)+"��ǩ����ʱ���ǩ����ʱ�䣺"+sign.getTimeStampTime(i));
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
