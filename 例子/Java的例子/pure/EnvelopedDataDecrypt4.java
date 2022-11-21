import net.netca.pki.Certificate;
import java.io.*;

import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;


public class EnvelopedDataDecrypt4 {
    public static void main(String[] arg) throws Exception {

        if(arg.length!=2) {
            System.out.println("Usage: java EnvelopedDataDecrypt4 infile outfile");
            return;
        }

        EnvelopedData env=null;
        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in;
        int len;
        FileOutputStream fOut=null;
        byte[]out;

        File f;
        NetcaMyStore store=null;
        NetcaSymEncrypter symEncrypter=null;
        try {
        	
        	f=new File(arg[0]);
            if(f.length()>java.lang.Integer.MAX_VALUE) {
            	System.out.println("文件太大");
                return;
            }
            in=new byte[(int)f.length()];
            fIn=new FileInputStream(f);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
             
            env=new EnvelopedData(in,0,len);
            
            store=new NetcaMyStore();
            
            env.setCertAndPrivKeys(store.iterator());
            symEncrypter=new NetcaSymEncrypter();
            env.setSymEncrypter(symEncrypter);
            
            out=env.decrypt();
            
            fOut=new FileOutputStream(arg[1]);
            fOut.write(out);
                       
            
            System.out.println("Decrypt Success");
            
            PrintEncAlgo(env.getEncryptedContentInfo().getContentEncryptionAlgorithm().getOid());

            cert=new Certificate(env.getDecryptCert().derEncode());
            System.out.println("解密证书的主体: "+cert.getSubject());
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
            
            if(symEncrypter!=null) {
            	symEncrypter.free();
            }
            
            if(store!=null) {
            	store.free();
            }
        }
    }

    static void PrintEncAlgo(String algo) {
        if(algo.equals(AlgorithmIdentifier.DESCBC_OID)) {
            System.out.println("加密算法: DESCBC");
        } else if(algo.equals(AlgorithmIdentifier.RC2CBC_OID)) {
            System.out.println("加密算法: RC2CBC");
        } else if(algo.equals(AlgorithmIdentifier.DESEDE3CBC_OID)) {
            System.out.println("加密算法: TDESCBC");
        } else if(algo.equals(AlgorithmIdentifier.AES128CBCPAD_OID)) {
            System.out.println("加密算法: AES128CBC");
        } else if(algo.equals(AlgorithmIdentifier.AES192CBCPAD_OID)) {
            System.out.println("加密算法: AES192CBC");
        } else if(algo.equals(AlgorithmIdentifier.AES256CBCPAD_OID)) {
            System.out.println("加密算法: AES256CBC");
        } else if(algo.equals(AlgorithmIdentifier.SSF33CBC_OID)) {
            System.out.println("加密算法: SSF33CBC");
        } else if(algo.equals(AlgorithmIdentifier.SM1CBC_OID)) {
            System.out.println("加密算法: SM1CBC");
        } else if(algo.equals(AlgorithmIdentifier.SM4CBC_OID)) {
            System.out.println("加密算法: SM4CBC");
        } else {
            System.out.println("加密算法: 未知的加密算法("+algo+")");
        }
    }






}
