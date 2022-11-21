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
				System.out.println("不是JWT签名");
	            return;
			}
			
			if(jwtObj.verifyMac(key)==false){
				System.out.println("验证JWT失败");
				return;
			}
			System.out.println("验证JWT成功");
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
			System.out.println("没有颁发者");
		} else {
			System.out.println("颁发者:" +value);
		}
		value=jwtObj.getClaimStringValue(JWT.SUBJECT);
		if(value==null){
			System.out.println("没有主体");
		} else {
			System.out.println("主体:" +value);
		}
		value=jwtObj.getClaimStringValue(JWT.JWT_ID);
		if(value==null){
			System.out.println("没有JWT ID");
		} else {
			System.out.println("JWT ID:" +value);
		}
		
		t=jwtObj.getNotBefore();
		if(t==null){
			System.out.println("没有有效开始时间");
		} else {
			System.out.println("有效开始时间:" +t);
		}
		
		t=jwtObj.getExpirationTime();
		if(t==null){
			System.out.println("没有过期时间");
		} else {
			System.out.println("过期时间:" +t);
		}
		
		t=jwtObj.getIssuedAt();
		if(t==null){
			System.out.println("没有颁发时间");
		} else {
			System.out.println("颁发时间:" +t);
		}
		
		JSONObject jsonObject=jwtObj.getClaims();
		JSON aud=jsonObject.getValue(JWT.AUDIENCE);
		if(aud==null){
			System.out.println("没有观众");
			return;
		}
		if(aud instanceof JSONString){
			value=((JSONString)aud).getString();
			System.out.println("观众:" +value);
		} else if(aud instanceof JSONArray){
			JSONArray audArray=(JSONArray)aud;
			int count=audArray.size();
			JSON item;
			for(int i=0;i<count;i++){
				item=audArray.get(i);
				if(item instanceof JSONString){
					value=((JSONString)item).getString();
					System.out.println("观众"+i+":" +value);
				} else {
					System.out.println("观众类型错误");
				}
			}
		} else {
			System.out.println("观众类型错误");
		}
		
	}
}
