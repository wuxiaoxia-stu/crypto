import net.netca.pki.*;
import java.io.*;

public class VerifyCertByCRL {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java VerifyCertByCRL cert crl");
            return;
        }


        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192*1024];
        int len;
        try {
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            if(cert.isInValidity()==false) {
                System.out.println("֤�鲻����Ч����");
            }
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;

            byte[] crl=new byte[len];
            System.arraycopy(in,0,crl,0,len);

            int status=cert.verifyWithCrl(crl);
            if(status==Certificate.CERT_STATUS_UNREVOKED) {
                System.out.println("֤��״̬����");
            } else if(status==Certificate.STATUS_UNDETERMINED) {
                System.out.println("����ȷ��֤���״̬");
            } else if(status==Certificate.STATUS_REVOKED) {
                RevokeInfo info=cert.getRevokeInfo();
                System.out.println("֤���Ѿ�����");
                PrintReason(info.getReason());
                System.out.println("����ʱ��: "+info.getTime());
            }


        } finally {
            if(fIn!=null) {
                fIn.close();
            }


            if(cert!=null) {
                cert.free();
            }


        }

    }

    static void PrintReason(int reason) {
        if(reason==-1) {
            System.out.println("����ԭ��: û˵������ԭ��");
        } else if(reason==RevokeInfo.UNSPECIFIED) {
            System.out.println("����ԭ��: δָ��");
        } else if(reason==RevokeInfo.KEYCOMPROMISE) {
            System.out.println("����ԭ��: ��Կй¶");
        } else if(reason==RevokeInfo.CACOMPROMISE) {
            System.out.println("����ԭ��: ������CA֤�飬����Կй¶");
        } else if(reason==RevokeInfo.AFFILIATION_CHANGED) {
            System.out.println("����ԭ��: ������ϵ�ı�");
        } else if(reason==RevokeInfo.SUPERSEDED) {
            System.out.println("����ԭ��: ��ȡ��");
        } else if(reason==RevokeInfo.CESSATION_OF_OPERATION) {
            System.out.println("����ԭ��: ֹͣ����");
        } else if(reason==RevokeInfo.CERTIFATE_HOLD) {
            System.out.println("����ԭ��: ��ʱ����");
        } else {
            System.out.println("����ԭ��: δ֪������ԭ��("+reason+")");
        }
    }


}
