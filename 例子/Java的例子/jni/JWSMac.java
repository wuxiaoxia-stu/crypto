import net.netca.pki.JWS;
import net.netca.pki.Util;

public class JWSMac {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=4) {
            System.out.println("Usage: java JWSMac [-compact] hmac-sha256|hmac-sm3 hexKey payLoad");
            return;
        }
		int type;
		String payLoad;
		int algo;
		byte[] key;
		if(args.length==3){
			type=JWS.JSON_SERIALIZATION;
			algo=getMacAlgo(args[0].toLowerCase());
			key=Util.HexDecode(args[1]);
			payLoad=args[2];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSMac [-compact] hmac-sha256|hmac-sm3 hexKey payLoad");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			algo=getMacAlgo(args[1].toLowerCase());
			key=Util.HexDecode(args[2]);
			payLoad=args[3];
		}
		
		if(algo==-1){
			System.out.println("´íÎóµÄMACËã·¨");
			return;
		}
		
		JWS jwsObj=new JWS(type);
		try {
			jwsObj.setPayload(payLoad.getBytes("UTF-8"));
			
			byte[] jwsEncode=jwsObj.mac(algo, key);
			System.out.println(new String(jwsEncode,"UTF-8"));
		}finally{
			jwsObj.free();
			
		}

	}

	private static int getMacAlgo(String name) throws Exception{
		if(name.equals("hmac-sha256")){
			return JWS.HMAC_SHA256;
		} else if(name.equals("hmac-sha384")){
			return JWS.HMAC_SHA384;
		} else if(name.equals("hmac-sha512")){
			return JWS.HMAC_SHA512;
		} else if(name.equals("hmac-sm3")){
			return JWS.HMAC_SM3;
		} else {
			return -1;
		}
	}
}
