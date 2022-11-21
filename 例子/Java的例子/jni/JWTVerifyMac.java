import java.util.Date;

import net.netca.pki.JWT;
import net.netca.pki.Util;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONArray;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;

public class JWTVerifyMac {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java JWTVerifyMac hexKey jwt");
            return;
        }
		byte[] key;
		String jwtData;
		key=Util.HexDecode(args[0]);
		jwtData=args[1];
		
		JWT jwtObj=null;
		try {
			jwtObj=new JWT(jwtData);
			if (jwtObj.getType()!=JWT.JWS_TYPE){
				System.out.println("����JWTǩ��");
	            return;
			}
			
			if(jwtObj.verifyMac(key)==false){
				System.out.println("��֤JWTʧ��");
				return;
			}
			System.out.println("��֤JWT�ɹ�");
			printClaim(jwtObj);
		}finally{
			if(jwtObj!=null){
				jwtObj.free();
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
