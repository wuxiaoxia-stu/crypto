import java.io.*;

import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;

public class SM2EnvelopedDataEncrypt2 {
    public static void main(String[] arg) throws Exception {

        if(arg.length!=3) {
            System.out.println("Usage: java SM2EnvelopedDataEncrypt2 cert infile outfile");
            return;
        }
        
        EnvelopedDataBuilder builder=null;

        EnvelopedData env=null;
        X509Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in;
        int len;
        FileOutputStream fOut=null;
        
        NetcaSecureRandomGenerator rndGenerator=null;
        NetcaSymEncrypter symEncrypter=null;
        NetcaPublicKeyEncrypter publicKeyEncrypter=null;
        
        File f;
        try {
        	
        	builder=new EnvelopedDataBuilder();
			
        	
       
        	in=new byte[8192];
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new X509Certificate(in,0,len);
            fIn.close();
            fIn=null;
            
            builder.addCert(cert);
            
            builder.setEncryptAlgorithm(EnvelopedDataBuilder.AES_128);
            
            rndGenerator=new NetcaSecureRandomGenerator();
            builder.setSecureRandomGenerator(rndGenerator);
            
            symEncrypter=new NetcaSymEncrypter();
            builder.setSymEncrypter(symEncrypter);
            
            publicKeyEncrypter=new NetcaPublicKeyEncrypter();
            builder.setPublicKeyEncrypter(publicKeyEncrypter); 

			builder.setSM2Q7(true);

            f=new File(arg[1]);
            if(f.length()>java.lang.Integer.MAX_VALUE) {
            	System.out.println("ÎÄ¼þÌ«´ó");
                return;
            }
            in=new byte[(int)f.length()];
            fIn=new FileInputStream(f);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
            
            env=builder.encypt(in,0,len);
            
            
            fOut=new FileOutputStream(arg[2]);

            fOut.write(env.encode(true));
            System.out.println("Success");
        } finally {
            
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }
                        
            if(rndGenerator!=null) {
            	rndGenerator.free();
            }
            
            if(symEncrypter!=null) {
            	symEncrypter.free();
            }
            
            if(publicKeyEncrypter!=null) {
            	publicKeyEncrypter.free();
            }
        }


    }



}
