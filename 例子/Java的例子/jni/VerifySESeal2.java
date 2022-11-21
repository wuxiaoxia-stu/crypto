
import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Date;

import net.netca.pki.Certificate;
import net.netca.pki.Hash;
import net.netca.pki.SESeal;
import net.netca.pki.SEStamp;
import net.netca.pki.encoding.Hex;
import net.netca.pki.TimeStamp;

public class VerifySESeal2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=1 && args.length!=2) {
            System.out.println("Usage: java VerifySESeal sealFileName [dataFileName]");
            return;
        }

		String sealFileName=args[0];
		byte[] sealData=readFile(sealFileName);
		SESeal seal=new SESeal(sealData);
		SEStamp stamp=null;
		Certificate cert=null;
		
		Date tsaTime=null;
		if(seal.hasTimeStamp()==false){
			System.out.println("电子签章没有时间戳");
		}else {
			if(seal.verifyTimeStamp()){
				System.out.println("电子签章的时间戳验证成功");
				TimeStamp timeStamp=seal.getTimeStamp();
				if(timeStamp==null){
					System.out.println("电子签章获取时间戳对象失败");
				} else {
					try{
						tsaTime=timeStamp.getTime();
						cert=timeStamp.getTsaCertificate();
						if(cert==null){
							System.out.println("电子签章获取时间戳证书失败");
						}else{
							System.out.println("时间戳证书:"+cert.getSubject());
						}
						System.out.println("时间戳时间:"+tsaTime);
						
					} finally{
						if(cert!=null){
							cert.free();
							cert=null;
						}
						timeStamp.free();
					}
				}
			} else {
				System.out.println("电子签章的时间戳验证失败");
			}
		}
		try{
			try {
				if(seal.verify(tsaTime)==false) {
					System.out.println("验证失败");
				} else {
					System.out.println("验证成功");
				} 
			} catch(Exception e) {
				System.out.println("验证失败，错误消息:"+e.getMessage());
			}
			byte[] hashValue=seal.getDataHash();
			int signAlgo=seal.getSignAlgorithm();
			if(args.length==2) {
				int hashAlgo=SESeal.getHashAlgorithmFromSignAlgorithm(signAlgo);
				byte[] hashValue2=hashFile(hashAlgo,args[1]);
				if(Arrays.equals(hashValue, hashValue2)) {
					System.out.println("原文杂凑值验证通过");
				} else {
					System.out.println("原文杂凑值不匹配");
				}
			}
			int format=seal.getFormat();
			if (format==SESeal.GBT_38540){
				System.out.println("是GB/T 38540的电子签章");
			} else {
				System.out.println("是GM/T 0031的电子签章");
			}
			System.out.println("版本号:"+seal.getVersion());
			stamp=seal.getStamp();
			System.out.println("电子印章版本号:"+stamp.getVersion());
			System.out.println("电子印章vid:"+stamp.getVid());
			System.out.println("电子印章id:"+stamp.getId());
			
			System.out.println("电子印章类型:"+stamp.getType());
			System.out.println("电子印章名称:"+stamp.getName());
			
			int certlistType=stamp.getCertListType();
			if(certlistType==SEStamp.CERTLIST_TYPE_CERT){
				int count=stamp.getCertCount();
				
				for(int i=0;i<count;i++){
					try{
						cert=stamp.getCert(i);
						if(cert==null){
							System.out.println("获取电子印章的签章人证书"+i+"失败");
						} else {
							System.out.println("电子印章证书"+i+":"+cert.getSubject());
						}
					} finally{
						if(cert!=null){
							cert.free();
							cert=null;
						}
					}
				}
			} else {
				int count=stamp.getCertDigestCount();
				String type;
				byte[] value;
				for(int i=0;i<count;i++){
					type=stamp.getCertDigestType(i);
					value=stamp.getCertDigestValue(i);
					System.out.println("电子印章证书"+i+"的杂凑类型:"+type+",证书"+i+"的杂凑值:"+Hex.encode(true, value));
				}
			}
			
			System.out.println("电子印章创建时间:"+stamp.getCreateDate());
			System.out.println("电子印章有效期开始时间:"+stamp.getValidStart());
			System.out.println("电子印章有效期结束时间:"+stamp.getValidEnd());
			
			
			System.out.println("电子印章图片类型:"+stamp.getPictureType());
			System.out.println("电子印章图片宽度:"+stamp.getPictureWidth());
			System.out.println("电子印章图片高度:"+stamp.getPictureHeigth());
					
			
			int count=stamp.getExtensionCount();
			if(count==0){
				System.out.println("电子印章没有扩展");
			} else {
				String oid;
				boolean critical;
				byte[] value;
				for(int i=0;i<count;i++){
					oid=stamp.getExtensionOid(i);
					critical=stamp.isExtensionCritical(i);
					value=stamp.getExtensionValue(i);
					if(critical){
						System.out.println("电子印章关键扩展("+oid+"):"+Hex.encode(true, value));
					}else {
						System.out.println("电子印章非关键扩展("+oid+"):"+Hex.encode(true, value));
					}
				}
			}
			cert=stamp.getSignCert();
			if(cert==null){
				System.out.println("获取电子印章制章人证书失败");
			}else {
				try {
					System.out.println("电子印章制章人证书:"+cert.getSubject());
				} finally{
					cert.free();
					cert=null;
				}
			}
			System.out.println("电子印章签名算法:"+stamp.getSignAlgorithm());
			
			cert=seal.getSignCert();
			if(cert==null){
				System.out.println("获取电子签章签章人证书失败");
			}else {
				try {
					System.out.println("电子签章签章人证书:"+cert.getSubject());
				} finally{
					cert.free();
					cert=null;
				}
			}
			System.out.println("签名算法:"+signAlgo);
			
			Date time=seal.getTime();
			System.out.println("签名时间:"+time);
			System.out.println("原文的杂凑值:"+Hex.encode(true, hashValue));
			System.out.println("原文属性:"+seal.getProperty());
				
			count=seal.getExtensionCount();
			if(count==0){
				System.out.println("电子签章没有扩展");
			} else {
				String oid;
				boolean critical;
				byte[] value;
				for(int i=0;i<count;i++){
					oid=seal.getExtensionOid(i);
					critical=seal.isExtensionCritical(i);
					value=seal.getExtensionValue(i);
					if(critical){
						System.out.println("电子签章关键扩展("+oid+"):"+Hex.encode(true, value));
					}else {
						System.out.println("电子签章非关键扩展("+oid+"):"+Hex.encode(true, value));
					}
				}
			}
		
		}finally{
			if(cert!=null){
				cert.free();
			}
			if(seal!=null){
				seal.free();
			}
			if(stamp!=null){
				stamp.free();
			}
		}

	}
	
	private static byte[] hashFile(int hashAlgo,String fileName) throws Exception{
		FileInputStream fIn=new FileInputStream(fileName);
		byte[] data=new byte[8192];
		int length;
		Hash hash=null;
		try {
			hash=new Hash(hashAlgo);
			for(;;) {
				length=fIn.read(data);
				if(length==-1) {
					break;
				}
				hash.update(data, 0, length);
			}
			return hash.doFinal();
		}finally {
			if(hash!=null){
				hash.free();
			}
			fIn.close();
		}
	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
			throw new Exception("file too big:"+ fileName);
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail:" + fileName);
			}
			return data;
		} finally {
			fIn.close();
		}
	}
}
