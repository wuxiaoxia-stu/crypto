import net.netca.pki.JWE;

public class JWEEncryptByPwd {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=2) {
            System.out.println("Usage: java JWEEncryptByPwd [-compact] pwd clear");
            return;
        }
		
		int type;
		String pwd;
		String clear;
		if(args.length==2){
			type=JWE.JSON_SERIALIZATION;
			pwd=args[0];
			clear=args[1];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWEEncryptByPwd [-compact] hexKey clear");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			pwd=args[1];
			clear=args[2];
		}
		
		JWE jweObj=new JWE(type);
				
		try {
			int cekAlgo=JWE.AES_256_GCM;
			jweObj.setContentEncAlgo(cekAlgo);
			int kekAlgo=JWE.PBES2_HMAC_SHA512_AES_256_KEYWRAP;
			jweObj.addPwd(kekAlgo, pwd.getBytes("UTF-8"),32,4096);
			String jwe=jweObj.encrypt(clear.getBytes("UTF-8"));
			System.out.println(jwe);
		}finally {
			jweObj.free();
		}

	}

}
