import net.netca.pki.*;

import java.io.*;

public class SM9Test {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=8) {
            System.out.println("Usage: java SM9Test hid type masterFile publickeyfile  userkeyaid userkeyafile  userkeybid userkeybfile");
            return;
        }
    	
        FileInputStream fIn=null;       
        FileOutputStream fOut=null;        
        int hid;
        hid=Integer.parseInt(arg[0]);
        int type=Integer.parseInt(arg[1]); //2:«©√˚ 1£∫º”√‹  3√‹‘øΩªªª       
        SM9UserKey userKeya=null;
        SM9UserKey userKeyb=null;
        SM9MasterKey masterKey=null;
        
        try {
        	 
        	
        	masterKey=SM9MasterKey.generateKeyPair(type, hid);
        	String id=arg[4];         	       	
        	
        	userKeya=masterKey.generateUserKey(id.getBytes("utf-8"));      
           
            
        	byte[] data=masterKey.exportKeypair();
        	byte[] data2=masterKey.exportPublicKey();
        	byte[] userdata=userKeya.export();	
        	
        	 String idb=arg[6];
        	 userKeyb=masterKey.generateUserKey(idb.getBytes("utf-8"));
        	 byte[] data3=userKeyb.export();
        	 fOut=new FileOutputStream(arg[2]);           
        	 fOut.write(data);
        	 fOut.close();
        	 fOut=null;
        	 System.out.println("masterKey  exportKeypair success");
        	 
        	 fOut=new FileOutputStream(arg[5]);           
        	 fOut.write(userdata);
        	 fOut.close();
        	 fOut=null;
        	 System.out.println("userKeya  export success");
        	 
        	 fOut=new FileOutputStream(arg[3]);           
        	 fOut.write(data2);
        	 fOut.close();
        	 fOut=null;
        	 System.out.println("masterKey  exportPublicKey success");
        	 
        	 fOut=new FileOutputStream(arg[7]);           
        	 fOut.write(data3);
        	 fOut.close();
        	 fOut=null;
        	 System.out.println("userKeyb  export success");
        	 
        	
        } finally {
            if(fIn!=null) {
                fIn.close();
            }          
            if(fOut!=null) {
                fOut.close();
            }
            if(userKeya!=null)
            {            	
            	userKeya.free();            	
            }
            
            if(masterKey!=null)
            {            	
            	masterKey.free();            	
            }
            
            if(userKeyb!=null)
            {            	
            	userKeyb.free();            	
            }
        }

    }
}
