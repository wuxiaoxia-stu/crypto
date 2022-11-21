import net.netca.pki.*;

import java.io.*;

public class SM9Verify {
    public static void main(String[] arg) throws Exception {
       if(arg.length!=4) {
            System.out.println("Usage: java SM9Verify masterKeyFile id tbsFile signFile");
            return;
        }


        FileInputStream fIn=null;       
        byte [] in=new byte[8192];      
        int len;
        SM9MasterKey masterKey=null;
        Hash hashObj=null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(in);
        	masterKey=SM9MasterKey.importPublicKey(in,0,len);
        	 fIn.close();
             fIn=null;
        	hashObj = SM9MasterKey.createHashObjectForVerify(); 
        	
            byte [] id=arg[1].getBytes("utf-8");       	
             
             fIn=new FileInputStream(arg[2]);
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
              
              fIn=new FileInputStream(arg[3]); 
              byte[] data=new byte[fIn.available()];
           	len=fIn.read(data,0,fIn.available());
            fIn.close();
            fIn=null;
        	
        	 if (masterKey.verify(id, hashObj, data))
             {
        		 System.out.println("verify Success");        		
             }
             else
             {
            	 System.out.println("verify fail"); 
             }
        	 hashObj.free();
        	 hashObj=null;
        	 
        } finally {
            if(fIn!=null) {
                fIn.close();
            }          
            
            if(masterKey!=null)
            {            	
            	masterKey.free();            	
            }
            if(hashObj!=null)
            {
            	hashObj.free();
            }
        }

    }
}
