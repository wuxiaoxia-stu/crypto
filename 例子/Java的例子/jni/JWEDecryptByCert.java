import net.netca.pki.Certificate;
import net.netca.pki.JWE;

public class JWEDecryptByCert {

	public static void main(String[] args) throws Exception{
		if(args.length!=1 && args.length!=2) {
            System.out.println("Usage: java JWEDecryptByCert [-compact] jwe");
            return;
        }
		int type;
		String jweData;
		if(args.length==1){
			type=JWE.JSON_SERIALIZATION;
			jweData=args[0];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWEDecryptByCert [-compact] jwe");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			jweData=args[1];
		}
		
		JWE jweObj=new JWE(type,jweData);
		Certificate cert=null;
		try{
			cert=Certificate.getUserCert(Certificate.USERCERT_TYPE_ENCRYPT);
			if(cert==null){
				System.out.println("没有解密证书");
		        return;
			}
			jweObj.setDecryptCert(0, cert);
			byte[] clear=jweObj.decrypt();
			
			System.out.println(new String(clear,"UTF-8"));
		} finally{
			jweObj.free();
			if(cert!=null){
				cert.free();
			}
		}

	}

}
