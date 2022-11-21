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
				System.out.println("����JWSǩ���ĸ���̫��");
				return;
			}
			if(jwsObj.isSignature(0)){
				System.out.println("��JWSǩ��");
				return;
			}
			
			if(jwsObj.verifyMac(0, key)==false){
				System.out.println("��֤MACʧ��");
				return;
			}
						
			byte[] payLoad2=jwsObj.getPayload();
			if(Arrays.equals(payLoad2, payLoad.getBytes("UTF-8"))==false){
				System.out.println("��Ч�غɲ�ƥ��");
				return;
			}
			
			ArrayList<String> headers=jwsObj.getAllCriticalHeader(0);
			if(headers.size()==0){
				System.out.println("û�йؼ�ͷ");
			} else {
				System.out.println("�ؼ�ͷ:");
				for(String header:headers){
					System.out.println(header);
				}
			}
			System.out.println("��֤JWS MAC�ɹ�");
		}finally{
			if(jwsObj!=null){
				jwsObj.free();
			}
			
		}

	}

}
