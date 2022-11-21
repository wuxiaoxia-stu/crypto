import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Certificate;
import net.netca.pki.SEStamp;
import net.netca.pki.encoding.Hex;

public class VerifySEStamp2 {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java VerifySEStamp2 stampFileName");
            return;
        }
		String stampFileName=args[0];
		byte[] data=readFile(stampFileName);
		SEStamp stamp=new SEStamp(data);
		
		try{
			if(stamp.verify()==false) {
				System.out.println("验证失败");
			} else {
				System.out.println("验证成功");
			}
			int format=	stamp.getFormat();
			if (format==SEStamp.GBT_38540){
				System.out.println("是GB/T 38540的电子印章");
			} else {
				System.out.println("是GM/T 0031的电子印章");
			}
			
			System.out.println("版本号:"+stamp.getVersion());
			System.out.println("vid:"+stamp.getVid());
			System.out.println("id:"+stamp.getId());
			
			System.out.println("类型:"+stamp.getType());
			System.out.println("名称:"+stamp.getName());
			
			int certlistType=stamp.getCertListType();
			if(certlistType==SEStamp.CERTLIST_TYPE_CERT){
				int count=stamp.getCertCount();
				Certificate cert;
				for(int i=0;i<count;i++){
					cert=null;
					try{
						cert=stamp.getCert(i);
						if(cert==null){
							System.out.println("获取签章人证书"+i+"失败");
						} else {
							System.out.println("证书"+i+":"+cert.getSubject());
						}
					} finally{
						if(cert!=null){
							cert.free();
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
					System.out.println("证书"+i+"的杂凑类型:"+type+",证书"+i+"的杂凑值:"+Hex.encode(true, value));
				}
			}
			
			System.out.println("创建时间:"+stamp.getCreateDate());
			System.out.println("有效期开始时间:"+stamp.getValidStart());
			System.out.println("有效期结束时间:"+stamp.getValidEnd());
			
			
			System.out.println("图片类型:"+stamp.getPictureType());
			System.out.println("图片宽度:"+stamp.getPictureWidth());
			System.out.println("图片高度:"+stamp.getPictureHeigth());
					
			
			int count=stamp.getExtensionCount();
			if(count==0){
				System.out.println("没有扩展");
			} else {
				String oid;
				boolean critical;
				byte[] value;
				for(int i=0;i<count;i++){
					oid=stamp.getExtensionOid(i);
					critical=stamp.isExtensionCritical(i);
					value=stamp.getExtensionValue(i);
					if(critical){
						System.out.println("关键扩展("+oid+"):"+Hex.encode(true, value));
					}else {
						System.out.println("非关键扩展("+oid+"):"+Hex.encode(true, value));
					}
				}
			}
			Certificate cert=stamp.getSignCert();
			if(cert==null){
				System.out.println("获取制章人证书失败");
			}else {
				try {
					System.out.println("制章人证书:"+cert.getSubject());
				} finally{
					cert.free();
				}
			}
			System.out.println("签名算法:"+stamp.getSignAlgorithm());
		}finally{
			stamp.free();
		}
	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
			throw new Exception("文件太大:"+ fileName);
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("读文件失败:" + fileName);
			}
			return data;
		} finally {
			fIn.close();
		}
	}
}

