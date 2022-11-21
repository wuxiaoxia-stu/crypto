import net.netca.pki.*;
import java.io.*;

public class TestSignP10 {
    public static void main(String[] arg) throws Exception {

        Device device=null;
        CertReq p10=null;
        KeyPair keypair=null;
        FileOutputStream fOut=null;
        try {
            device=Device.getPseudoDevice();
            keypair=device.generateRSAKeyPair(1024,KeyPair.SIGNATURE,"TestRSA1024KeyPair");
            device.free();
            device=null;
            if(keypair==null) {
                System.out.println("产生RSA密钥对失败");
                return;
            }
            p10=new CertReq();
            p10.setSubject("C=CN,CN=测试123");
            byte[] data=p10.sign(keypair,Signature.SHA1WITHRSA);
            keypair.free();
            keypair=null;
            p10.free();
            p10=null;

            fOut=new FileOutputStream("test.req");
            fOut.write(data);
            fOut.close();
            fOut=null;

            System.out.println("产生证书请求成功");
        } finally {
            if(fOut!=null) {
                fOut.close();
            }

            if(device!=null) {
                device.free();
            }

            if(p10!=null) {
                p10.free();
            }

            if(keypair!=null) {
                keypair.free();
            }

        }

    }



}
