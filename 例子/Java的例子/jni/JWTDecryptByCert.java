import java.util.Date;

import net.netca.pki.*;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
public class JWTDecryptByCert {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java JWTDecryptByCert jwt");
            return;
        }
		String jwtData;
		jwtData=args[0];
		
		JWT jwtObj=new JWT(jwtData);
		Certificate cert=null;
		try{
			if(jwtObj.getType()!=JWT.JWE_TYPE){
				System.out.println("����JWT����");
				return;
			}
			
			cert=Certificate.getUserCert(Certificate.USERCERT_TYPE_ENCRYPT);
			if(cert==null){
				System.out.println("û�н���֤��");
		        return;
			}
			jwtObj.decryptByCert(cert);
						
			System.out.println("���ܳɹ�");
			printClaim(jwtObj);
		} finally{
			jwtObj.free();
			if(cert!=null){
				cert.free();
			}
		}


	}
	
	private static void printClaim(JWT jwtObj)throws Exception{
		String value;
		Date t;
		
		value=jwtObj.getClaimStringValue(JWT.ISSUER);
		if(value==null){
			System.out.println("û�а䷢��");
		} else {
			System.out.println("�䷢��:" +value);
		}
		value=jwtObj.getClaimStringValue(JWT.SUBJECT);
		if(value==null){
			System.out.println("û������");
		} else {
			System.out.println("����:" +value);
		}
		value=jwtObj.getClaimStringValue(JWT.JWT_ID);
		if(value==null){
			System.out.println("û��JWT ID");
		} else {
			System.out.println("JWT ID:" +value);
		}
		
		t=jwtObj.getNotBefore();
		if(t==null){
			System.out.println("û����Ч��ʼʱ��");
		} else {
			System.out.println("��Ч��ʼʱ��:" +t);
		}
		
		t=jwtObj.getExpirationTime();
		if(t==null){
			System.out.println("û�й���ʱ��");
		} else {
			System.out.println("����ʱ��:" +t);
		}
		
		t=jwtObj.getIssuedAt();
		if(t==null){
			System.out.println("û�а䷢ʱ��");
		} else {
			System.out.println("�䷢ʱ��:" +t);
		}
		
		JSONObject jsonObject=jwtObj.getClaims();
		JSON aud=jsonObject.getValue(JWT.AUDIENCE);
		if(aud==null){
			System.out.println("û�й���");
			return;
		}
		if(aud instanceof JSONString){
			value=((JSONString)aud).getString();
			System.out.println("����:" +value);
		} else if(aud instanceof JSONArray){
			JSONArray audArray=(JSONArray)aud;
			int count=audArray.size();
			JSON item;
			for(int i=0;i<count;i++){
				item=audArray.get(i);
				if(item instanceof JSONString){
					value=((JSONString)item).getString();
					System.out.println("����"+i+":" +value);
				} else {
					System.out.println("�������ʹ���");
				}
			}
		} else {
			System.out.println("�������ʹ���");
		}
		
	}
}
