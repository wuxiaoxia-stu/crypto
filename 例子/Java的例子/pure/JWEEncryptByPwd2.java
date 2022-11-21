import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.json.jose.impl.jce.JCEGenerateRandom;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWECipher;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWEKDF;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWEKeyWrap;

public class JWEEncryptByPwd2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=2) {
            System.out.println("Usage: java JWEEncryptByPwd2 [-compact] pwd clear");
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
				 System.out.println("Usage: java JWEEncryptByPwd2 [-compact] hexKey clear");
		         return;
			}
			type=JWE.COMPACT_SERIALIZATION;
			pwd=args[1];
			clear=args[2];
		}
		
		byte[] salt=(new JCEGenerateRandom()).generate(32);
		JWERecipienter recipienter=JWERecipienter.getInstance()
				.setKey(pwd.getBytes("UTF-8"),JWE.ENCRYPT_CEK_ALGO_PBES2_HMAC_SHA256_AES_128_KEYWRAP)
				.setPBKDF2Params(salt, 2048);
		JWE jwe=JWEBuilder.getInstance(type)
				.setContentEncAlgo(JWE.CONTENT_ENC_ALGO_AES_128_CBC_HMAC_SHA_256)
				.setSymEncrypter(new JCEJWECipher())
				.setSecureRandomGenerator(new JCEGenerateRandom())
				.setKDFImplement(new JCEJWEKDF())
				.setKeyWrapImplement(new JCEJWEKeyWrap())
				.addRecipienter(recipienter)
				.encrypt(clear.getBytes("UTF-8"));
		System.out.println(jwe.encode());
	}

}
