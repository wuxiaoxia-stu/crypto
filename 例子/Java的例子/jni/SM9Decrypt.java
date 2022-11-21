import net.netca.pki.*;

import java.io.*;

public class SM9Decrypt {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java SM9Decrypt userKeyFile cipherFile clearFile");
            return;
        }


        FileInputStream fIn=null;       
        FileOutputStream fOut=null;
        byte [] userkey=new byte[8192];           
        int len;
        SM9UserKey sm9=null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(userkey);
             sm9=SM9UserKey.importUserKeyPair(userkey,0,len);
        	 fIn.close();
             fIn=null;             
           
        	
            fIn=new FileInputStream(arg[1]);            
            byte[] data =new byte[fIn.available()];            
            len=fIn.read(data);           
            fIn.close();
            fIn=null;
            int macKeyLen = 32;
            byte[] clear = sm9.decrypt(data, macKeyLen);
            if(clear!=null)
            {
            	fOut=new FileOutputStream(arg[2]);           
            	fOut.write(clear);
            	System.out.println("decrypt Success");
            }
            else
            	System.out.println("decrypt fail");
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
        }

    }
}
