import net.netca.pki.JWE;

public class JWEDecryptByPwd {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=2) {
            System.out.println("Usage: java JWEDecryptByPwd [-compact] pwd jwe");
            return;
        }
		int type;
		String pwd;
		String jweData;
		if(args.length==2){
			type=JWE.JSON_SERIALIZATION;
			pwd=args[0];
			jweData=args[1];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWEDecryptByPwd [-compact] pwd jwe");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			pwd=args[1];
			jweData=args[2];
		}
		
		JWE jweObj=new JWE(type,jweData);
		try{
			jweObj.setPwd(0, pwd.getBytes("UTF-8"));
			byte[] clear=jweObj.decrypt();
			
			System.out.println(new String(clear,"UTF-8"));
		} finally{
			jweObj.free();
		}
	}

}
