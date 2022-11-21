import net.netca.pki.*;
import java.io.*;
import java.util.Date;

public class GetTimeStamp {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java GetTimeStamp url infile token");
            return;
        }

        TimeStamp ts=null;
        Hash hash=null;
        Certificate cert=null;
        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        int len;

        try {
            ts=new TimeStamp();

            ts.setTsaURL(arg[0]);

            int algo=Hash.SHA1;

            hash=new Hash(algo);

            fIn=new FileInputStream(arg[1]);
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

            ts.setHashAlgorithm(algo);
            ts.setMessageImprint(md);

            int status=ts.getResponse ( );

            if(status!=TimeStamp.RESP_STATUS_GRANTED && status!=TimeStamp.RESP_STATUS_GRANTEDWITHMODS) {
                System.out.println("获取TSA响应失败("+status+")");
                return;
            }

            byte[] token=ts.getToken();
            fOut=new  FileOutputStream(arg[2]);
            fOut.write(token);
            fOut.close();
            fOut=null;

            System.out.println("时间戳时间： "+ts.getTime());

            cert=ts.getTsaCertificate();
            System.out.println("时间戳证书的主体：" +cert.getSubject() );
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
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
