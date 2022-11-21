import net.netca.pki.*;

import java.io.*;

public class SM9Sign {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java SM9Sign userKeyFile tbsFile signFile");
            return;
        }


        FileInputStream fIn=null;       
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];       
        int len;
        SM9UserKey sm9=null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(in);
             sm9=SM9UserKey.importUserKeyPair(in,0,len);
        	 fIn.close();
             fIn=null;            
             
        	Hash hashObj = SM9UserKey.createHashObjectForSign();               
            fIn=new FileInputStream(arg[1]);
            byte [] tbs=new byte[8192];
        	for (; ; )
            {
            	len=fIn.read(tbs);
                if(len<=0) {
                    break;
                }
                hashObj.update(tbs, 0, len);
            }
        	
        	 fIn.close();
        	  fIn=null; 
        	 fOut=new FileOutputStream(arg[2]);
             byte[] signature=sm9.sign(hashObj);
        	 hashObj.free();
        	 fOut.write(signature);
        	 System.out.println("sign Success");
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
