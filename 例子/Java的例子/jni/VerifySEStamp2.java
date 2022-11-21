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
				System.out.println("��֤ʧ��");
			} else {
				System.out.println("��֤�ɹ�");
			}
			int format=	stamp.getFormat();
			if (format==SEStamp.GBT_38540){
				System.out.println("��GB/T 38540�ĵ���ӡ��");
			} else {
				System.out.println("��GM/T 0031�ĵ���ӡ��");
			}
			
			System.out.println("�汾��:"+stamp.getVersion());
			System.out.println("vid:"+stamp.getVid());
			System.out.println("id:"+stamp.getId());
			
			System.out.println("����:"+stamp.getType());
			System.out.println("����:"+stamp.getName());
			
			int certlistType=stamp.getCertListType();
			if(certlistType==SEStamp.CERTLIST_TYPE_CERT){
				int count=stamp.getCertCount();
				Certificate cert;
				for(int i=0;i<count;i++){
					cert=null;
					try{
						cert=stamp.getCert(i);
						if(cert==null){
							System.out.println("��ȡǩ����֤��"+i+"ʧ��");
						} else {
							System.out.println("֤��"+i+":"+cert.getSubject());
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
					System.out.println("֤��"+i+"���Ӵ�����:"+type+",֤��"+i+"���Ӵ�ֵ:"+Hex.encode(true, value));
				}
			}
			
			System.out.println("����ʱ��:"+stamp.getCreateDate());
			System.out.println("��Ч�ڿ�ʼʱ��:"+stamp.getValidStart());
			System.out.println("��Ч�ڽ���ʱ��:"+stamp.getValidEnd());
			
			
			System.out.println("ͼƬ����:"+stamp.getPictureType());
			System.out.println("ͼƬ���:"+stamp.getPictureWidth());
			System.out.println("ͼƬ�߶�:"+stamp.getPictureHeigth());
					
			
			int count=stamp.getExtensionCount();
			if(count==0){
				System.out.println("û����չ");
			} else {
				String oid;
				boolean critical;
				byte[] value;
				for(int i=0;i<count;i++){
					oid=stamp.getExtensionOid(i);
					critical=stamp.isExtensionCritical(i);
					value=stamp.getExtensionValue(i);
					if(critical){
						System.out.println("�ؼ���չ("+oid+"):"+Hex.encode(true, value));
					}else {
						System.out.println("�ǹؼ���չ("+oid+"):"+Hex.encode(true, value));
					}
				}
			}
			Certificate cert=stamp.getSignCert();
			if(cert==null){
				System.out.println("��ȡ������֤��ʧ��");
			}else {
				try {
					System.out.println("������֤��:"+cert.getSubject());
				} finally{
					cert.free();
				}
			}
			System.out.println("ǩ���㷨:"+stamp.getSignAlgorithm());
		}finally{
			stamp.free();
		}
	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
			throw new Exception("�ļ�̫��:"+ fileName);
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("���ļ�ʧ��:" + fileName);
			}
			return data;
		} finally {
			fIn.close();
		}
	}
}

