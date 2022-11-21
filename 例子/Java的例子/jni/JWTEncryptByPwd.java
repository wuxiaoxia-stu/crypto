import net.netca.pki.*;

public class JWTEncryptByPwd {

	public static void main(String[] args) throws Exception{
		if(args.length <=2 || args.length%2!=1) {
            System.out.println("Usage: java JWTEncryptByPwd  pwd claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }
		
		String pwd;
		pwd=args[0];
		
		JWT jwtObj=new JWT(JWT.JWE_TYPE);
		
		try {
			for(int i=1;i<args.length;i+=2){
				jwtObj.setClaim(args[i],args[i+1]);
			}
			
			int cekAlgo=JWE.AES_256_GCM;
			int kekAlgo=JWE.PBES2_HMAC_SHA512_AES_256_KEYWRAP;
			String jwt=jwtObj.encryptByPwd(cekAlgo, pwd.getBytes("UTF-8"), kekAlgo, 32,4096);
			System.out.println(jwt);
		}finally {
			jwtObj.free();
		}

	}

}
