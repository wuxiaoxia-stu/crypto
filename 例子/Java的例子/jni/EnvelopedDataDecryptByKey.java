import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.*;

public class EnvelopedDataDecryptByKey {

	public static void main(String[] args) throws Exception{
		if(args.length!=3) {
            System.out.println("Usage: java EnvelopedDataDecryptByKey envFileName clearTextFileName key");
            return;
        }
		String clearFileName=args[1];
		String cipherName=args[0];
		byte[] key=Util.HexDecode(args[2]);
		
		FileInputStream fIn=null;
		FileOutputStream fOut=null;
		EnvelopedData env=null;
		
		try {
			fIn=new FileInputStream(cipherName);
			env=new EnvelopedData(false);
			env.setKey(key);
			env.decryptInit();
			fOut=new FileOutputStream(clearFileName);
			byte[] data=new byte[8192];
			int len;
			byte[] outData;
			for(;;){
				len=fIn.read(data);
				if(len==-1) {
					break;
				}
				outData=env.decryptUpdate(data, 0, len);
				fOut.write(outData);
			}
			env.decryptFinal();
			
		} finally {
			if(env!=null) {
				env.free();
			}
			
			if(fIn!=null) {
				fIn.close();
			}
			
			if(fOut!=null) {
				fOut.close();
			}
		}
		System.out.println("Success");
	}

}
