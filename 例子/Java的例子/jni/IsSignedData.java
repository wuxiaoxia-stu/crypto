import net.netca.pki.*;
import java.io.*;

public class IsSignedData {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=1) {
            System.out.println("Usage: java IsSignedData inFile");
            return;
        }


        FileInputStream fIn=null;
        byte [] data=new byte[8192];
        int len;
        
        try {

            fIn=new FileInputStream(arg[0]);
            len=fIn.read(data);
            fIn.close();
            fIn=null;
            
            if(SignedData.isSign(data,0,len))
            {
            	if(SignedData.isDetachedSign(data,0,len))
            	{
            		System.out.println("detached SignedData");  
            	}
            	else
            	{
            		System.out.println("SignedData,but not detached");
            	}
            }
            else
            {
            	System.out.println("not SignedData");            	
            }
            
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

        }

    }
}
