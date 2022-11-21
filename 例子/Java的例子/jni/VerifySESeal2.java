
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
			System.out.println("����ǩ��û��ʱ���");
		}else {
			if(seal.verifyTimeStamp()){
				System.out.println("����ǩ�µ�ʱ�����֤�ɹ�");
				TimeStamp timeStamp=seal.getTimeStamp();
				if(timeStamp==null){
					System.out.println("����ǩ�»�ȡʱ�������ʧ��");
				} else {
					try{
						tsaTime=timeStamp.getTime();
						cert=timeStamp.getTsaCertificate();
						if(cert==null){
							System.out.println("����ǩ�»�ȡʱ���֤��ʧ��");
						}else{
							System.out.println("ʱ���֤��:"+cert.getSubject());
						}
						System.out.println("ʱ���ʱ��:"+tsaTime);
						
					} finally{
						if(cert!=null){
							cert.free();
							cert=null;
						}
						timeStamp.free();
					}
				}
			} else {
				System.out.println("����ǩ�µ�ʱ�����֤ʧ��");
			}
		}
		try{
			try {
				if(seal.verify(tsaTime)==false) {
					System.out.println("��֤ʧ��");
				} else {
					System.out.println("��֤�ɹ�");
				} 
			} catch(Exception e) {
				System.out.println("��֤ʧ�ܣ�������Ϣ:"+e.getMessage());
			}
			byte[] hashValue=seal.getDataHash();
			int signAlgo=seal.getSignAlgorithm();
			if(args.length==2) {
				int hashAlgo=SESeal.getHashAlgorithmFromSignAlgorithm(signAlgo);
				byte[] hashValue2=hashFile(hashAlgo,args[1]);
				if(Arrays.equals(hashValue, hashValue2)) {
					System.out.println("ԭ���Ӵ�ֵ��֤ͨ��");
				} else {
					System.out.println("ԭ���Ӵ�ֵ��ƥ��");
				}
			}
			int format=seal.getFormat();
			if (format==SESeal.GBT_38540){
				System.out.println("��GB/T 38540�ĵ���ǩ��");
			} else {
				System.out.println("��GM/T 0031�ĵ���ǩ��");
			}
			System.out.println("�汾��:"+seal.getVersion());
			stamp=seal.getStamp();
			System.out.println("����ӡ�°汾��:"+stamp.getVersion());
			System.out.println("����ӡ��vid:"+stamp.getVid());
			System.out.println("����ӡ��id:"+stamp.getId());
			
			System.out.println("����ӡ������:"+stamp.getType());
			System.out.println("����ӡ������:"+stamp.getName());
			
			int certlistType=stamp.getCertListType();
			if(certlistType==SEStamp.CERTLIST_TYPE_CERT){
				int count=stamp.getCertCount();
				
				for(int i=0;i<count;i++){
					try{
						cert=stamp.getCert(i);
						if(cert==null){
							System.out.println("��ȡ����ӡ�µ�ǩ����֤��"+i+"ʧ��");
						} else {
							System.out.println("����ӡ��֤��"+i+":"+cert.getSubject());
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
					System.out.println("����ӡ��֤��"+i+"���Ӵ�����:"+type+",֤��"+i+"���Ӵ�ֵ:"+Hex.encode(true, value));
				}
			}
			
			System.out.println("����ӡ�´���ʱ��:"+stamp.getCreateDate());
			System.out.println("����ӡ����Ч�ڿ�ʼʱ��:"+stamp.getValidStart());
			System.out.println("����ӡ����Ч�ڽ���ʱ��:"+stamp.getValidEnd());
			
			
			System.out.println("����ӡ��ͼƬ����:"+stamp.getPictureType());
			System.out.println("����ӡ��ͼƬ���:"+stamp.getPictureWidth());
			System.out.println("����ӡ��ͼƬ�߶�:"+stamp.getPictureHeigth());
					
			
			int count=stamp.getExtensionCount();
			if(count==0){
				System.out.println("����ӡ��û����չ");
			} else {
				String oid;
				boolean critical;
				byte[] value;
				for(int i=0;i<count;i++){
					oid=stamp.getExtensionOid(i);
					critical=stamp.isExtensionCritical(i);
					value=stamp.getExtensionValue(i);
					if(critical){
						System.out.println("����ӡ�¹ؼ���չ("+oid+"):"+Hex.encode(true, value));
					}else {
						System.out.println("����ӡ�·ǹؼ���չ("+oid+"):"+Hex.encode(true, value));
					}
				}
			}
			cert=stamp.getSignCert();
			if(cert==null){
				System.out.println("��ȡ����ӡ��������֤��ʧ��");
			}else {
				try {
					System.out.println("����ӡ��������֤��:"+cert.getSubject());
				} finally{
					cert.free();
					cert=null;
				}
			}
			System.out.println("����ӡ��ǩ���㷨:"+stamp.getSignAlgorithm());
			
			cert=seal.getSignCert();
			if(cert==null){
				System.out.println("��ȡ����ǩ��ǩ����֤��ʧ��");
			}else {
				try {
					System.out.println("����ǩ��ǩ����֤��:"+cert.getSubject());
				} finally{
					cert.free();
					cert=null;
				}
			}
			System.out.println("ǩ���㷨:"+signAlgo);
			
			Date time=seal.getTime();
			System.out.println("ǩ��ʱ��:"+time);
			System.out.println("ԭ�ĵ��Ӵ�ֵ:"+Hex.encode(true, hashValue));
			System.out.println("ԭ������:"+seal.getProperty());
				
			count=seal.getExtensionCount();
			if(count==0){
				System.out.println("����ǩ��û����չ");
			} else {
				String oid;
				boolean critical;
				byte[] value;
				for(int i=0;i<count;i++){
					oid=seal.getExtensionOid(i);
					critical=seal.isExtensionCritical(i);
					value=seal.getExtensionValue(i);
					if(critical){
						System.out.println("����ǩ�¹ؼ���չ("+oid+"):"+Hex.encode(true, value));
					}else {
						System.out.println("����ǩ�·ǹؼ���չ("+oid+"):"+Hex.encode(true, value));
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
