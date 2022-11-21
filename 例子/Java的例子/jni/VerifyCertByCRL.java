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
                System.out.println("证书不在有效期内");
            }
            fIn=new FileInputStream(arg[1]);
            len=fIn.read(in);
            fIn.close();
            fIn=null;

            byte[] crl=new byte[len];
            System.arraycopy(in,0,crl,0,len);

            int status=cert.verifyWithCrl(crl);
            if(status==Certificate.CERT_STATUS_UNREVOKED) {
                System.out.println("证书状态正常");
            } else if(status==Certificate.STATUS_UNDETERMINED) {
                System.out.println("不能确定证书的状态");
            } else if(status==Certificate.STATUS_REVOKED) {
                RevokeInfo info=cert.getRevokeInfo();
                System.out.println("证书已经作废");
                PrintReason(info.getReason());
                System.out.println("作废时间: "+info.getTime());
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
            System.out.println("作废原因: 没说明作废原因");
        } else if(reason==RevokeInfo.UNSPECIFIED) {
            System.out.println("作废原因: 未指定");
        } else if(reason==RevokeInfo.KEYCOMPROMISE) {
            System.out.println("作废原因: 密钥泄露");
        } else if(reason==RevokeInfo.CACOMPROMISE) {
            System.out.println("作废原因: 本身是CA证书，其密钥泄露");
        } else if(reason==RevokeInfo.AFFILIATION_CHANGED) {
            System.out.println("作废原因: 附属关系改变");
        } else if(reason==RevokeInfo.SUPERSEDED) {
            System.out.println("作废原因: 被取代");
        } else if(reason==RevokeInfo.CESSATION_OF_OPERATION) {
            System.out.println("作废原因: 停止操作");
        } else if(reason==RevokeInfo.CERTIFATE_HOLD) {
            System.out.println("作废原因: 临时作废");
        } else {
            System.out.println("作废原因: 未知的作废原因("+reason+")");
        }
    }


}
