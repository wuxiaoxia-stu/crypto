import net.netca.pki.*;

import java.io.*;

public class SM9Encrypt {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=4) {
            System.out.println("Usage: java SM9Encrypt masterKeyFile id clearFile cipherFile");
            return;
        }


        FileInputStream fIn=null;       
        FileOutputStream fOut=null;
        byte [] masterfile=new byte[8192];              
        int len;
        SM9MasterKey sm9=null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(masterfile);
             sm9=SM9MasterKey.importPublicKey(masterfile,0,len);
        	 fIn.close();
             fIn=null;
           
            byte[] id=arg[1].getBytes("utf-8");
        	
            fIn=new FileInputStream(arg[2]);             
            byte[] data =new byte[fIn.available()];           
            len=fIn.read(data);           
            fIn.close();
            fIn=null;
           
            int macKeyLen = 32;
            byte[] cipher = sm9.encrypt(id, data, macKeyLen);
            if(cipher!=null)
            {
            	fOut=new FileOutputStream(arg[3]);           
            	fOut.write(cipher);            	
            	System.out.println("encrypt Success");
            }
            else
            	System.out.println("encrypt fail");
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
