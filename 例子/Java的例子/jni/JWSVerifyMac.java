import java.util.ArrayList;
import java.util.Arrays;

import net.netca.pki.JWS;
import net.netca.pki.Util;

public class JWSVerifyMac {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=4) {
			System.out.println("Usage: java JWSVerifyMac [-compact] hexKey payLoad jws");
            return;
        }
		int type;
		String payLoad;
		String jwsData;
		byte[] key;
		
		if(args.length==3){
			type=JWS.JSON_SERIALIZATION;
			key=Util.HexDecode(args[0]);
			payLoad=args[1];
			jwsData=args[2];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSVerifyMac [-compact] hexKey payLoad jws");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			key=Util.HexDecode(args[1]);
			payLoad=args[2];
			jwsData=args[3];
		}
		JWS jwsObj=null;
		try {
			jwsObj=new JWS(type,jwsData);
			if (jwsObj.getSignCount()!=1) {
				System.out.println("不是JWS签名的个数太多");
				return;
			}
			if(jwsObj.isSignature(0)){
				System.out.println("是JWS签名");
				return;
			}
			
			if(jwsObj.verifyMac(0, key)==false){
				System.out.println("验证MAC失败");
				return;
			}
						
			byte[] payLoad2=jwsObj.getPayload();
			if(Arrays.equals(payLoad2, payLoad.getBytes("UTF-8"))==false){
				System.out.println("有效载荷不匹配");
				return;
			}
			
			ArrayList<String> headers=jwsObj.getAllCriticalHeader(0);
			if(headers.size()==0){
				System.out.println("没有关键头");
			} else {
				System.out.println("关键头:");
				for(String header:headers){
					System.out.println(header);
				}
			}
			System.out.println("验证JWS MAC成功");
		}finally{
			if(jwsObj!=null){
				jwsObj.free();
			}
			
		}

	}

}
