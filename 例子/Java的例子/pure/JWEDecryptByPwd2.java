import net.netca.pki.encoding.json.jose.*;

public class JWEDecryptByPwd2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=2) {
            System.out.println("Usage: java JWEDecryptByPwd2 [-compact] pwd jwe");
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
				 System.out.println("Usage: java JWEDecryptByPwd2 [-compact] pwd jwe");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			pwd=args[1];
			jweData=args[2];
		}
		
		JWE jweObj=JWE.decode(type, jweData)
				.setSymEncrypter(new net.netca.pki.encoding.json.jose.impl.jce.JCEJWECipher())
				.setKDFImplement(new net.netca.pki.encoding.json.jose.impl.jce.JCEJWEKDF())
				.setKeyUnWrapImplement(new net.netca.pki.encoding.json.jose.impl.jce.JCEJWEKeyUnwrap());
		jweObj.getRecipientInfo(0).setDecryptKey(pwd.getBytes("UTF-8"));
		
		byte[] clear=jweObj.decrypt();
		System.out.println("ClearText:"+new String(clear,"UTF-8"));
		System.out.println("enc:"+jweObj.getContentEncAlgo());
		System.out.println("algo:"+jweObj.getDecryptCekAlgo());

	}

}
