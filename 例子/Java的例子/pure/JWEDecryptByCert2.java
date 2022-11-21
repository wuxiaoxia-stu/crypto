import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaMyStore;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaHash;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaJWECipher;
public class JWEDecryptByCert2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=1 && args.length!=2) {
            System.out.println("Usage: java JWEDecryptByCert2 [-compact] jwe");
            return;
        }
		int type;
		String jweData;
		if(args.length==1){
			type=JWE.JSON_SERIALIZATION;
			jweData=args[0];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWEDecryptByCert2 [-compact] jwe");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			jweData=args[1];
		}
		
		NetcaMyStore store=NetcaMyStore.NewDeviceStore();
		try{
			JWE jweObj=JWE.decode(type, jweData)
					.setHashImplement(new NetcaHash())
					.setSymEncrypter(new NetcaJWECipher())
					.setX509CertificateAndPrivateKeys(store.getList());
			byte[] clear=jweObj.decrypt();
			System.out.println("ClearText:"+new String(clear,"UTF-8"));
			X509Certificate encCert=jweObj.getDecryptCert();
			System.out.println("Decrypt Cert Subject:"+encCert.getSubject().getLdapName());
			System.out.println("enc:"+jweObj.getContentEncAlgo());
			System.out.println("algo:"+jweObj.getDecryptCekAlgo());
			
			
		}finally{
			store.free();
		}
		
		
	}
	
	

}
