import net.netca.pki.*;

import java.io.*;
import java.security.SecureRandom;

public class SM9EnvEnc {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=4) {
            System.out.println("Usage: java SM9EnvEnc masterKeyFile id clearFile envFile");
            return;
        }


        FileInputStream fIn=null;       
        FileOutputStream fOut=null;
        byte [] masterfile=new byte[8192];               
        int len;
        byte[] encKey;       
        SM9MasterKey sm9=null;
        Cipher c =null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(masterfile);
             sm9=SM9MasterKey.importPublicKey(masterfile,0,len);
        	 fIn.close();
             fIn=null;
             
            byte[] id=arg[1].getBytes("utf-8");
            byte[] key=new byte[16];
            encKey = sm9.generateSessionKey(id,16,key);
                                
            fOut=new FileOutputStream(arg[3]);         	 
        	 fOut.write(encKey, 0, encKey.length);
             byte[] iv =(new SecureRandom()).generateSeed(16);;
             fOut.write(iv, 0, iv.length);
             c = new Cipher(Cipher.SM4_CBC);            
             c.setIV(iv);
             c.setKey(key);
             c.setPadding(Cipher.PADDING_PKCS5);
             c.init(true);
             
             byte [] clear=new byte[8192];  
             fIn=new FileInputStream(arg[2]);
             byte[] cipher;       
         	for (; ; )
             {
             	len=fIn.read(clear);
                 if(len<=0) {
                     break;
                 }
                 cipher=c.update(clear, 0, len);
                 if (cipher.length > 0)
                 {
                     fOut.write(cipher, 0, cipher.length);
                 }                 
             }
         	fIn.close();
        	fIn=null; 
         	cipher = c.doFinal();
         	fOut.write(cipher);
         	System.out.println("encrypt Success");
            
        } finally {
            if(fIn!=null) {
                fIn.close();
            }          
            if(fOut!=null) {
                fOut.close();
            }
            if(sm9!=null)
            {            	
            	sm9.free();            	
            }
            if(c!=null)
            {
            	c.free();
            }
        }

    }
}
