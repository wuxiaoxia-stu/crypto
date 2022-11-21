import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Date;

import net.netca.pki.SEStamp;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Hashable;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.seseal.CertDigestList;
import net.netca.pki.encoding.asn1.pki.seseal.CertDigestObj;
import net.netca.pki.encoding.asn1.pki.seseal.ESPictureInfo;
import net.netca.pki.encoding.asn1.pki.seseal.ESPropertyInfo;
import net.netca.pki.encoding.asn1.pki.seseal.ExtData;
import net.netca.pki.encoding.asn1.pki.seseal.ExtensionDatas;
import net.netca.pki.encoding.asn1.pki.seseal.Header;
import net.netca.pki.encoding.asn1.pki.seseal.Seal;
import net.netca.pki.encoding.asn1.pki.seseal.Stamp;
import net.netca.pki.encoding.asn1.pki.seseal.StampInfo;


public class VerifySESeal {

	public static void main(String[] args) throws Exception{
		if(args.length!=1 && args.length!=2) {
            System.out.println("Usage: java VerifySESeal sealFileName [dataFileName]");
            return;
        }

		String sealFileName=args[0];
		byte[] sealData=readFile(sealFileName);
		Seal seal=Seal.decode(sealData);
		Date tsaTime=null;
		try {
			if(seal.hasTimeStamp()==false){
				System.out.println("no timestamp");
			} else {
				if(seal.verifyTimeStamp()){
					System.out.println("verify timestamp ok");
					tsaTime=seal.getTimeStampTime();
					System.out.println("timestamp time:"+tsaTime);
					System.out.println("timestamp cert:"+seal.getTimeStampCert().getSubject().getLdapName());
				}else {
					System.out.println("verify timestamp fail");
				}
				
			} 
			if(seal.verify(tsaTime,new JCEVerifier(),new JCEHasher())==false) {
				System.out.println("verify fail");
			} else {
				System.out.println("verify ok");
			} 
		} catch(Exception e) {
			System.out.println("verify fail,errMsg:"+e.getMessage());
		}
		byte[] hashValue=seal.getDataHash();
		if(args.length==2) {
			AlgorithmIdentifier hashAlgo=seal.getHashAlgorithm();
			Hashable hasher=new JCEHasher();
			byte[] hashValue2=hashFile(hashAlgo,hasher,args[1]);
			if(Arrays.equals(hashValue, hashValue2)) {
				System.out.println("hash match");
			} else {
				System.out.println("hash mismatch");
			}
		}
		int format=seal.getSealType();
		if(format==Seal.GBT_38540){
			System.out.println("GB/T 38540 seal");
		} else if(format==Seal.GMT_0031){
			System.out.println("GM/T 0031 seal");
		} else {
			System.out.println("bad seal format");
		}
		System.out.println("version:"+seal.getVersion());
		Stamp stamp=seal.getStamp();
		format=stamp.getStampType();
		if(format==Stamp.GBT_38540){
			System.out.println("GB/T 38540 stamp");
		} else if(format==Stamp.GMT_0031){
			System.out.println("GM/T 0031 stamp");
		} else {
			System.out.println("bad stamp format");
		}
		StampInfo info=stamp.getEstampInfo();
		Header header=info.getHeader();
		System.out.println("stamp version:"+header.getVersion());
		System.out.println("stamp vid:"+header.getVid());
		System.out.println("stamp id:"+info.getEsID());
		
		ESPropertyInfo property=info.getProperty();
		System.out.println("stamp type:"+property.getType());
		System.out.println("stamp name:"+property.getName());
		int certListType=property.getCertListType();
		if(certListType==SEStamp.CERTLIST_TYPE_CERT){
			X509Certificate[] certs=property.getCertList();
			System.out.println("seal signer cert count:"+certs.length);
			for(int i=0;i<certs.length;i++) {
				System.out.println("\tstamp cert "+i+":"+certs[i].getSubject().getLdapName());
			}
		} else {
			CertDigestList certDigestList=property.getCertDigestList();
			CertDigestObj certDigest;
			int count=certDigestList.size();
			System.out.println("seal signer cert digest count:"+certDigestList.size());
			for(int i=0;i<count;i++){
				certDigest=certDigestList.get(i);
				System.out.println("\tstamp cert digest "+i+" type:"+certDigest.getType()+",stamp cert digest "+i+" value:"+Hex.encode(true,certDigest.getValue()));
			}
		}
		System.out.println("stamp createData:"+property.getCreateDate());
		System.out.println("stamp validStart:"+property.getValidStart());
		System.out.println("stamp validEnd:"+property.getValidEnd());
		
		ESPictureInfo picture=info.getPicture();
		System.out.println("stamp picture type:"+picture.getType());
		System.out.println("stamp picture width:"+picture.getWidth());
		System.out.println("stamp picture height:"+picture.getHeight());
				
		ExtensionDatas exts=info.getExtDatas();
		if(exts==null) {
			System.out.println("stamp no extension");
		} else {
			int count=exts.size();
			ExtData ext;
			System.out.println("stamp extension count:"+count);
			for(int i=0;i<count;i++) {
				System.out.println("stamp extension "+i);
				ext=exts.get(i);
				System.out.println("\textnID:"+ext.getOid());
				System.out.println("\tcritical:"+ext.isCritical());
				System.out.println("\textnValue:"+Hex.encode(true, ext.getExtensionValue()));
			}
		}
		
		System.out.println("stamp maker cert:"+stamp.getCert().getSubject().getLdapName());
		System.out.println("stamp signAlgorithm:"+stamp.getSignatureAlgorithm());
		
		Date time=seal.getTime();
		System.out.println("time:"+time);
		System.out.println("dataHash:"+Hex.encode(true, hashValue));
		System.out.println("propertyInfo:"+seal.getPropertyInfo());
		
		exts=seal.getExtensions();
		if(exts==null) {
			System.out.println("seal no extension");
		} else {
			int count=exts.size();
			ExtData ext;
			System.out.println("seal extension count:"+count);
			for(int i=0;i<count;i++) {
				System.out.println("seal extension "+i);
				ext=exts.get(i);
				System.out.println("\textnID:"+ext.getOid());
				System.out.println("\tcritical:"+ext.isCritical());
				System.out.println("\textnValue:"+Hex.encode(true, ext.getExtensionValue()));
			}
		}
		
		System.out.println("sign cert:"+seal.getCert().getSubject().getLdapName());
		System.out.println("signAlgorithm:"+seal.getSignatureAlgorithm());
		
		
	}

	private static byte[] hashFile(AlgorithmIdentifier hashAlgo,Hashable hasher,String fileName) throws Exception{
		FileInputStream fIn=new FileInputStream(fileName);
		byte[] data=new byte[8192];
		int length;
		hasher.init(hashAlgo);
		try {
			for(;;) {
				length=fIn.read(data);
				if(length==-1) {
					break;
				}
				hasher.update(data, 0, length);
			}
			return hasher.digest();
		}finally {
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
