import net.netca.pki.*;

import java.io.*;

public class SM9EnvDec {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java SM9EnvDec userKeyFile envFile clearFile ");
            return;
        }


        FileInputStream fIn=null;       
        FileOutputStream fOut=null;
        byte [] userkeyfile=new byte[8192];               
        int len;          
        SM9UserKey sm9=null;
        Cipher c=null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(userkeyfile);
             sm9=SM9UserKey.importUserKeyPair(userkeyfile,0,len);
        	 fIn.close();
             fIn=null;             
          
             fIn=new FileInputStream(arg[1]);
             byte[] encKey =new byte[65];
             len =fIn.read(encKey,0,65);
            
             byte[] key = sm9.decryptSessionKey(16, encKey);
             byte[] iv =new byte[16];
             len =fIn.read(iv,0,16);           	
                                
                  	 
             c = new Cipher(Cipher.SM4_CBC);            
             c.setIV(iv);
             c.setKey(key);
             c.setPadding(Cipher.PADDING_PKCS5);
             c.init(false);
             
             byte [] data=new byte[8192];  
            
             fOut=new FileOutputStream(arg[2]);   
             byte[] clear;       
         	for (; ; )
             {
             	len=fIn.read(data);
                 if(len<=0) {
                     break;
                 }
                 clear=c.update(data, 0, len);
                 if (clear.length > 0)
                 {
                     fOut.write(clear, 0, clear.length);
                 }                 
             }
         	fIn.close();
        	fIn=null; 
        	clear = c.doFinal();
        	fOut.write(clear);
         	System.out.println("SM9EnvDec Success");    	
            
            
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
