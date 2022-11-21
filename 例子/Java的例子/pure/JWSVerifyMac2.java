import java.util.Arrays;

import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.json.jose.*;
public class JWSVerifyMac2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=4) {
			System.out.println("Usage: java JWSVerifyMac2 [-compact] hexKey payLoad jws");
            return;
        }
		int type;
		String payLoad;
		String jwsData;
		byte[] key;
		
		if(args.length==3){
			type=JWS.JSON_SERIALIZATION;
			key=Hex.decode(args[0]);
			payLoad=args[1];
			jwsData=args[2];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSVerifyMac2 [-compact] hexKey payLoad jws");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			key=Hex.decode(args[1]);
			payLoad=args[2];
			jwsData=args[3];
		}

		JWS jwsObj=JWS.decode(type, jwsData);
		
		if(jwsObj.getSignerCount()!=1){
			System.out.println("too much signer");
			return;
		}
		if(jwsObj.getSignerInfo(0).isSignature()){
			System.out.println("not mac");
			return;
		}
		jwsObj.setMacImplement(new net.netca.pki.encoding.json.jose.impl.jce.JCEMac());
		if(jwsObj.verifyMac(0, key)==false){
			System.out.println("verify mac fail");
			return;
		}
		byte[] data=jwsObj.getPayload();
		if(Arrays.equals(data, payLoad.getBytes("UTF-8"))==false){
			System.out.println("payLoad mismatch");
			return;
		}
		System.out.println("Sign Algo:"+jwsObj.getSignerInfo(0).getAlgo());
	}

}
