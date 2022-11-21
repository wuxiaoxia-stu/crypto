import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Arrays;

import net.netca.pki.*;

public class JWSVerify {

	public static void main(String[] args) throws Exception{
		if(args.length!=3 && args.length!=4) {
            System.out.println("Usage: java JWSVerify [-compact] certFileName payLoad jws");
            return;
        }
		int type;
		String fileName;
		String payLoad;
		String jwsData;
		if(args.length==3){
			type=JWS.JSON_SERIALIZATION;
			fileName=args[0];
			payLoad=args[1];
			jwsData=args[2];
		} else {
			if(args[0].toLowerCase().equals("-compact")==false){
				 System.out.println("Usage: java JWSVerify [-compact] payLoad jws");
		         return;
			}
			type=JWS.COMPACT_SERIALIZATION;
			fileName=args[1];
			payLoad=args[2];
			jwsData=args[3];
		}
		JWS jwsObj=null;
		Certificate cert=null;
		try {
			jwsObj=new JWS(type,jwsData);
			if (jwsObj.getSignCount()!=1) {
				System.out.println("不是JWS签名的个数太多");
				return;
			}
			if(jwsObj.isSignature(0)==false){
				System.out.println("不是JWS签名");
				return;
			}
			
			cert=getCert(fileName);
			if(jwsObj.verifySignature(0, cert)==false){
				System.out.println("验证签名失败");
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
			System.out.println("验证JWS签名成功");
		}finally{
			if(jwsObj!=null){
				jwsObj.free();
			}
			if(cert!=null){
				cert.free();
			}
		}
	}

	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=Integer.MAX_VALUE) {
			throw new Exception("file too big");
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail");
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private static Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new Certificate(data);
	}
}
