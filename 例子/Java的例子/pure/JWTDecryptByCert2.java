import java.util.Date;
import java.util.Iterator;
import java.util.Set;

import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
import net.netca.pki.encoding.json.jose.JWT;
import net.netca.pki.encoding.json.jose.JWTClaimsSet;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaHash;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaJWECipher;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaMyStore;

public class JWTDecryptByCert2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java JWTDecryptByCert2 jwt");
            return;
        }
		String jwtData;
		jwtData=args[0];
		NetcaMyStore store=NetcaMyStore.NewDeviceStore();
		try{
			JWT jwt=JWT.decode(jwtData)
				.setHashImplement(new NetcaHash())
				.setSymEncrypter(new NetcaJWECipher())
				.setX509CertificateAndPrivateKeys(store.getList());
					
			jwt.decrypt();
	
			JWTClaimsSet claimsSet=jwt.getClaimsSet();
			printClaimsSet(claimsSet);
		}finally{
			store.free();
		}
	}

	private static void printClaimsSet(JWTClaimsSet claimsSet)throws Exception{
		printStandardClaimsSet(claimsSet);
		printOtherClaimsSet(claimsSet);
	}
	private static void printOtherClaimsSet(JWTClaimsSet claimsSet)throws Exception{
		JSON json=JSON.decode(new String(claimsSet.encode(),"UTF-8"));
		JSONObject jsonObj=(JSONObject)json;
		Set<String> names=jsonObj.nameSet();
		Iterator<String> it=names.iterator();
		while(it.hasNext()){
			String name=it.next();
			if(name.equals(JWTClaimsSet.AUDIENCE)==false
					&& name.equals(JWTClaimsSet.EXPIRATION_TIME)==false
					&& name.equals(JWTClaimsSet.ISSUED_AT)==false
					&& name.equals(JWTClaimsSet.ISSUER)==false
					&& name.equals(JWTClaimsSet.JWT_ID)==false
					&& name.equals(JWTClaimsSet.NOT_BEFORE)==false
					&& name.equals(JWTClaimsSet.SUBJECT)==false){
				JSON value=jsonObj.getValue(name);
				if(value instanceof JSONString){
					System.out.println(name+":"+((JSONString)value).getString());
				} else {
					System.out.println(name+":"+value.encode());
				}
			}
		}
	}
	private static void printStandardClaimsSet(JWTClaimsSet claimsSet)throws Exception{
		String issuer=claimsSet.getIssuerClaim();
		if(issuer!=null){
			System.out.println("Issuer:"+issuer);
		}
		
		String subject=claimsSet.getSubjectClaim();
		if(subject!=null){
			System.out.println("Subject:"+subject);
		}
		
		String[] audience=claimsSet.getAudienceClaim();
		if(audience!=null){
			System.out.println("audience:");
			for(int i=0;i<audience.length;i++){
				System.out.println("\t"+audience[i]);
			}
		}
		
		String jwtId=claimsSet.getJWTIdClaim();
		if(jwtId!=null){
			System.out.println("JWTId:"+jwtId);
		}
		
		Date issuerAt=claimsSet.getIssuedAtClaim();
		if(issuerAt!=null){
			System.out.println("IssuerAt:"+issuerAt);
		}
		
		Date notBefore=claimsSet.getNotBeforeClaim();
		if(notBefore!=null){
			System.out.println("NotBefore:"+notBefore);
		}
		
		Date notAfter=claimsSet.getExpirationTimeClaim();
		if(notAfter!=null){
			System.out.println("ExpirationTime:"+notAfter);
		}
	}
}
