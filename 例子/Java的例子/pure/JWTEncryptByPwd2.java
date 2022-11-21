import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

import net.netca.pki.encoding.json.jose.JWE;
import net.netca.pki.encoding.json.jose.JWT;
import net.netca.pki.encoding.json.jose.JWTBuilder;
import net.netca.pki.encoding.json.jose.JWTClaimsSet;
import net.netca.pki.encoding.json.jose.impl.jce.JCEGenerateRandom;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWECipher;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWEKDF;
import net.netca.pki.encoding.json.jose.impl.jce.JCEJWEKeyWrap;


public class JWTEncryptByPwd2 {

	public static void main(String[] args)throws Exception {
		if(args.length <=2 || args.length%2!=1) {
            System.out.println("Usage: java JWTEncryptByPwd2  pwd claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }

		String pwd;
		pwd=args[0];
		JWTClaimsSet claimSet=new JWTClaimsSet();
		for(int i=1;i<args.length;i+=2){
			String name=args[i];
			String value=args[i+1];
			addClaim(claimSet,name,value);
		}
		byte[] salt=(new JCEGenerateRandom()).generate(32);
		JWT jwt=JWTBuilder.getInstance(JWT.TYPE_JWE)
				.setClaimsSet(claimSet)
				.setContentEncAlgo(JWE.CONTENT_ENC_ALGO_AES_128_CBC_HMAC_SHA_256)
				.setSymEncrypter(new JCEJWECipher())
				.setSecureRandomGenerator(new JCEGenerateRandom())
				.setKDFImplement(new JCEJWEKDF())
				.setKeyWrapImplement(new JCEJWEKeyWrap())
				.setKey(pwd.getBytes("UTF-8"),JWE.ENCRYPT_CEK_ALGO_PBES2_HMAC_SHA256_AES_128_KEYWRAP)
				.setPBKDF2Params(salt, 4096)
				.encrypt();
		System.out.println(jwt.encode());
	}
	private static void addClaim(JWTClaimsSet claimSet,String name,String value) throws Exception{
		if(name.equals(JWTClaimsSet.ISSUER)){
			claimSet.setIssuerClaim(value);
		} else if(name.equals(JWTClaimsSet.SUBJECT)){
			claimSet.setSubjectClaim(value);
		} else if(name.equals(JWTClaimsSet.AUDIENCE)){
			claimSet.setAudienceClaim(value);
		} else if(name.equals(JWTClaimsSet.JWT_ID)){
			claimSet.setJWTIdClaim(value);
		} else if(name.equals(JWTClaimsSet.EXPIRATION_TIME)){
			claimSet.setExpirationTimeClaim(toDate(value));
		} else if(name.equals(JWTClaimsSet.NOT_BEFORE)){
			claimSet.setNotBeforeClaim(toDate(value));
		} else if(name.equals(JWTClaimsSet.ISSUED_AT)){
			claimSet.setIssuedAtClaim(toDate(value));
		} else {
			claimSet.setOtherClaim(name, value);
		}
	}
	
	private static int GetInteger(char[] data,int offset,int length) {
		int value=0;
		for(int i=0;i<length;i++)
		{
			value*=10;
			value+=(int)(data[i+offset]-(byte)'0');
		}
		return value;
	}
	
	private static Date toDate(String str)throws Exception{
		if(str.length()!=15){
			throw new Exception("bad time format");
		}
		char[] data=str.toCharArray();
		if(data[14]!='Z'){
			throw new Exception("bad time format");
		}
       
        for (int i = 0; i < 14; i++){
        	if (data[i] > '9' || data[i] < '0'){
        		throw new Exception("bad time format");
            }
        }
        
        int year=GetInteger(data,0,4);
        int month=GetInteger(data,4,2);
        int day=GetInteger(data,6,2);
        int hour=GetInteger(data,8,2);
        int minute=GetInteger(data,10,2);
        int second=GetInteger(data,12,2);
        Calendar cal = Calendar.getInstance();
        cal.setTimeZone(TimeZone.getTimeZone("UTC"));
        cal.set(year,month-1,day,hour,minute,second);
                
        return cal.getTime();
	}
}
