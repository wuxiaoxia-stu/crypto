import net.netca.pki.JWS;
import net.netca.pki.JWT;
import net.netca.pki.Util;

public class JWTMac {

	public static void main(String[] args) throws Exception{
		if(args.length<=2 || args.length%2!=0) {
            System.out.println("Usage: java JWTMac hmac-sha256|hmac-sm3 hexKey claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }
		int algo;
		byte[] key;
		algo=getMacAlgo(args[0].toLowerCase());
		if(algo==-1){
			System.out.println("´íÎóµÄMACËã·¨");
			return;
		}
		key=Util.HexDecode(args[1]);
		
		JWT jwtObj=new JWT(JWT.JWS_TYPE);
		try {
			for(int i=2;i<args.length;i+=2){
				jwtObj.setClaim(args[i],args[i+1]);
			}
			
			String jwtEncode=jwtObj.mac(algo, key);
			System.out.println(jwtEncode);
		}finally{
			jwtObj.free();
			
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
