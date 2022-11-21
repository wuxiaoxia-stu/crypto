import java.io.FileOutputStream;

import net.netca.pki.encoding.asn1.pki.JCESecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.cms.ContentInfo;
import net.netca.pki.encoding.asn1.pki.scvp.ValPolRequest;
public class CreateValPolRequest {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java CreateValPolRequest outFileName");
            return;
        }
		
		byte[] nonce=JCESecureRandomGenerator.getInstance().generate(32);
		ValPolRequest req=new ValPolRequest(1,nonce);
		ContentInfo contentInfo=new ContentInfo(ValPolRequest.OID,req.getASN1Object());
		byte[] data=contentInfo.getASN1Object().encode();
		writeFile(args[0],data);
		System.out.println("Success");
	}
	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
}
