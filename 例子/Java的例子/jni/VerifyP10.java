import net.netca.pki.*;
import java.io.*;

public class VerifyP10 {
    public static void main(String[] arg) throws Exception {

        if(arg.length!=1) {
            System.out.println("Usage: java VerifyP10 p10");
            return;
        }

        CertReq p10=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        PublicKey pubKey=null;
        try {
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            p10=new CertReq(in,0,len);
            fIn.close();
            fIn=null;

            if(p10.verify()==false) {
                System.out.println("验证证书请求失败");
                return;
            }
            System.out.println("验证证书请求成功");
            System.out.println("主体："+p10.getSubject());
            String value=p10.getC();
            if(value!=null) {
                System.out.println("C："+value);
            }

            value=p10.getST();
            if(value!=null) {
                System.out.println("ST："+value);
            }

            value=p10.getL();
            if(value!=null) {
                System.out.println("L："+value);
            }

            value=p10.getO();
            if(value!=null) {
                System.out.println("O："+value);
            }

            value=p10.getOU();
            if(value!=null) {
                System.out.println("OU："+value);
            }

            value=p10.getCN();
            if(value!=null) {
                System.out.println("CN："+value);
            }

            value=p10.getEmail();
            if(value!=null) {
                System.out.println("Email："+value);
            }


            pubKey=p10.getPublicKey();
            if(pubKey==null) {
                System.out.println("获取公钥失败");
                return;
            }
            int algo=pubKey.getAlgorithm();
            PrintPublicKeyAlgo(algo);
            System.out.println("公钥长度:"+pubKey.getBits());

        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(p10!=null) {
                p10.free();
            }

            if(pubKey!=null) {
                pubKey.free();
            }

        }

    }

    static void PrintPublicKeyAlgo(int algo) {
        if(algo==KeyPair.RSA) {
            System.out.println("公钥算法: RSA");
        } else if(algo==KeyPair.DH) {
            System.out.println("公钥算法: DH");
        } else if(algo==KeyPair.DSA) {
            System.out.println("公钥算法: DSA");
        } else if(algo==KeyPair.ECC) {
            System.out.println("公钥算法: ECC");
        } else {
            System.out.println("公钥算法: 未知公钥算法("+algo+")");
        }
    }

}
