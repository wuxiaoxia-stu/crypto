import java.io.File;
import java.io.FileInputStream;
import net.netca.pki.encoding.asn1.pki.seseal.Stamp;
import net.netca.pki.SEStamp;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.seseal.Header;
import net.netca.pki.encoding.asn1.pki.seseal.StampInfo;
import net.netca.pki.encoding.asn1.pki.seseal.ESPropertyInfo;
import net.netca.pki.encoding.asn1.pki.seseal.ExtData;
import net.netca.pki.encoding.asn1.pki.seseal.ExtensionDatas;
import net.netca.pki.encoding.asn1.pki.seseal.CertDigestList;
import net.netca.pki.encoding.asn1.pki.seseal.CertDigestObj;
import net.netca.pki.encoding.asn1.pki.seseal.ESPictureInfo;
import net.netca.pki.encoding.asn1.pki.X509Certificate;


public class VerifySEStamp {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java VerifySEStamp stampFileName");
            return;
        }
		String stampFileName=args[0];
		byte[] data=readFile(stampFileName);
		Stamp stamp=Stamp.decode(data);
		if(stamp.verifySignature(new JCEVerifier())==false) {
			System.out.println("verify fail");
		} else {
			System.out.println("verify ok");
		}
		
		int format=stamp.getStampType();
		if(format==Stamp.GBT_38540){
			System.out.println("GB/T 38540 stamp");
		} else if(format==Stamp.GMT_0031){
			System.out.println("GM/T 0031 stamp");
		} else {
			System.out.println("bad stamp format");
		}
		
		StampInfo info=stamp.getEstampInfo();
		Header header=info.getHeader();
		System.out.println("version:"+header.getVersion());
		System.out.println("vid:"+header.getVid());
		System.out.println("id:"+info.getEsID());
		
		ESPropertyInfo property=info.getProperty();
		System.out.println("type:"+property.getType());
		System.out.println("name:"+property.getName());
		
		int certListType=property.getCertListType();
		if(certListType==SEStamp.CERTLIST_TYPE_CERT){
			X509Certificate[] certs=property.getCertList();
			System.out.println("seal signer cert count:"+certs.length);
			for(int i=0;i<certs.length;i++) {
				System.out.println("\tcert "+i+":"+certs[i].getSubject().getLdapName());
			}
		} else {
			CertDigestList certDigestList=property.getCertDigestList();
			CertDigestObj certDigest;
			int count=certDigestList.size();
			System.out.println("seal signer cert digest count:"+certDigestList.size());
			for(int i=0;i<count;i++){
				certDigest=certDigestList.get(i);
				System.out.println("\tcert digest "+i+" type:"+certDigest.getType()+",cert digest "+i+" value:"+Hex.encode(true,certDigest.getValue()));
			}
		}
		System.out.println("createData:"+property.getCreateDate());
		System.out.println("validStart:"+property.getValidStart());
		System.out.println("validEnd:"+property.getValidEnd());
		
		ESPictureInfo picture=info.getPicture();
		System.out.println("picture type:"+picture.getType());
		System.out.println("picture width:"+picture.getWidth());
		System.out.println("picture height:"+picture.getHeight());
				
		ExtensionDatas exts=info.getExtDatas();
		if(exts==null) {
			System.out.println("no extension");
		} else {
			int count=exts.size();
			ExtData ext;
			System.out.println("extension count:"+count);
			for(int i=0;i<count;i++) {
				System.out.println("extension "+i);
				ext=exts.get(i);
				System.out.println("\textnID:"+ext.getOid());
				System.out.println("\tcritical:"+ext.isCritical());
				System.out.println("\textnValue:"+Hex.encode(true, ext.getExtensionValue()));
			}
		}
		
		System.out.println("stamp maker cert:"+stamp.getCert().getSubject().getLdapName());
		System.out.println("signAlgorithm:"+stamp.getSignatureAlgorithm());
		
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
