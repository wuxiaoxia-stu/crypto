import net.netca.pki.*;

public class JWSSign {

	public static void main(String[] args) throws Exception{
		if(args.length!=1 && args.length!=2) {
            System.out.println("Usage: java JWSSign [-compact] payLoad");
            return;
        }
		int type;
		String payLoad;
		
		if(args.length==1){
			type=JWS.JSON_SERIALIZATION;
			payLoad=args[0];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSSign [-compact] payLoad");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			payLoad=args[1];
		}
		
		JWS jwsObj=new JWS(type);
		int algo=JWS.SHA256WITHRSA;
		Certificate cert=null;
		try {
			jwsObj.setCertIdType(JWS.CERTID_TYPE_X5T_S256);
			jwsObj.setPayload(payLoad.getBytes("UTF-8"));
			
			cert=Certificate.getUserCert(Certificate.USERCERT_TYPE_SIGN);
			if(cert==null){
				System.out.println("没有签名证书");
				return;
			}
			algo=getSignAlgo(cert);
						
			byte[] jwsEncode=jwsObj.sign(algo, cert);
			System.out.println(new String(jwsEncode,"UTF-8"));
		}finally{
			jwsObj.free();
			if(cert!=null){
				cert.free();
			}
		}
		
	}
	
	private static int getSignAlgo(Certificate cert) throws Exception{
		int publicKeyAlgo=cert.getPublicKeyAlgorithm();
		if(publicKeyAlgo==KeyPair.RSA){
			return JWS.SHA256WITHRSA;
		} else if(publicKeyAlgo!=KeyPair.ECC){
			throw new Exception("不支持的公钥算法");
		}
		
		int curve=cert.getPublicKeyEccCurve();
		if(curve==Device.ECC_CURVE_P256){
			return JWS.ECDSAWITHSHA256;
		} else if(curve==Device.ECC_CURVE_P384){
			return JWS.ECDSAWITHSHA384;
		} else if(curve==Device.ECC_CURVE_P521){
			return JWS.ECDSAWITHSHA512;
		} else if(curve==Device.ECC_CURVE_SM2){
			return JWS.SM3WITHSM2;
		} else {
			throw new Exception("不支持的椭圆曲线");
		}
	}
}
