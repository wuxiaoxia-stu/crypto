import net.netca.pki.*;

public class JWTSign {

	public static void main(String[] args)throws Exception {
		if(args.length==0 || args.length%2!=0) {
            System.out.println("Usage: java JWTSign claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }
		
		JWT jwtObj=new JWT(JWT.JWS_TYPE);
		Certificate cert=null;
		try {
			for(int i=0;i<args.length;i+=2){
				jwtObj.setClaim(args[i],args[i+1]);
			}
			
			cert=Certificate.getUserCert(Certificate.USERCERT_TYPE_SIGN);
			if(cert==null){
				System.out.println("没有签名证书");
				return;
			}
			int algo=getSignAlgo(cert);
			String jwtEncode=jwtObj.sign(algo, cert,JWT.CERTID_TYPE_X5T_S256);
			System.out.println(jwtEncode);
		}finally{
			jwtObj.free();
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
