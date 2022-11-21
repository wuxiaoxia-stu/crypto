import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.json.jose.JWS;
import net.netca.pki.encoding.json.jose.JWT;
import net.netca.pki.encoding.json.jose.JWTBuilder;
import net.netca.pki.encoding.json.jose.JWTClaimsSet;

public class JWTMac2 {

	public static void main(String[] args) throws Exception{
		if(args.length<=2 || args.length%2!=0) {
            System.out.println("Usage: java JWTMac2 hmac-sha256|hmac-sm3 hexKey claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }
		String algo;
		byte[] key;
		algo=getMacAlgo(args[0].toLowerCase());
		key=Hex.decode(args[1]);

		JWTClaimsSet claimSet=new JWTClaimsSet();
		for(int i=2;i<args.length;i+=2){
			String name=args[i];
			String value=args[i+1];
			addClaim(claimSet,name,value);
		}
		JWT jwt=JWTBuilder.getInstance(JWT.TYPE_JWS)
				.setClaimsSet(claimSet)
				.setMacImplement(new net.netca.pki.encoding.json.jose.impl.jce.JCEMac())
				.setKey(key, algo)
				.sign();
		System.out.println(jwt.encode());
	}
	private static String getMacAlgo(String name) throws Exception{
		if(name.equals("hmac-sha256")){
			return JWS.HMAC_SHA256;
		} else if(name.equals("hmac-sha384")){
			return JWS.HMAC_SHA384;
		} else if(name.equals("hmac-sha512")){
			return JWS.HMAC_SHA512;
		} else if(name.equals("hmac-sm3")){
			return JWS.HMAC_SM3;
		} else {
			return name;
		}
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
