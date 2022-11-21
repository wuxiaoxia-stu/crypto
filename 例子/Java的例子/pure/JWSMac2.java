import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.Hex;

public class JWSMac2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=4) {
            System.out.println("Usage: java JWSMac2 [-compact] hmac-sha256|hmac-sm3 hexKey payLoad");
            return;
        }
		int type;
		String payLoad;
		String algo;
		byte[] key;
		if(args.length==3){
			type=JWS.JSON_SERIALIZATION;
			algo=getMacAlgo(args[0].toLowerCase());
			key=Hex.decode(args[1]);
			payLoad=args[2];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSMac2 [-compact] hmac-sha256|hmac-sm3 hexKey payLoad");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			algo=getMacAlgo(args[1].toLowerCase());
			key=Hex.decode(args[2]);
			payLoad=args[3];
		}
		JWSSigner jwsSigner=JWSSigner.getInstance()
				.setMacImplement(new net.netca.pki.encoding.json.jose.impl.jce.JCEMac())
				.setMacKey(key, algo);
				
		JWS jws=JWSBuilder.getInstance(type)
				.addSigner(jwsSigner)
				.setPayload(payLoad.getBytes("UTF-8"))
				.sign();
		System.out.println(jws.encode());
	}
	
	private static String getMacAlgo(String name) throws Exception{
		if(name.equals("hmac-sha256")){
			return JWS.HMAC_SHA256;
		} else if(name.equals("hmac-sha384")){
			return JWS.HMAC_SHA384;
		} else if(name.equals("hmac-sha512")){
			return JWS.HMAC_SHA512;
		} else if(name.equals("hmac-sm3")){
			return JWS.HMAC_SM3;
		} else {
			return name;
		}
	}

}
