import net.netca.pki.EnvelopedData;
import java.io.*;
import net.netca.pki.asn1.RecipientInfos;
import net.netca.pki.asn1.KeyTransRecipientInfo;
import net.netca.pki.asn1.RecipientIdentifier;
import net.netca.pki.asn1.AlgorithmIdentifier;
import net.netca.pki.encoding.Hex;

public class GetEncryptedKey {

	public static void main(String[] args) throws Exception{
		if(args.length!=2) {
            System.out.println("Usage: java getEncryptedKey envelopedDataFileName skid");
            return;
        }
		
		String fileName=args[0];
		byte[] keyId=Hex.decode(args[1]);

		byte[] recipientInfo=getRecipientInfos(fileName);
		
		RecipientInfos recipientInfos=new RecipientInfos(recipientInfo);
		KeyTransRecipientInfo []ktris=recipientInfos.getKeyTransRecipientInfo();
		RecipientIdentifier rid;
		for(int i=0;i<ktris.length;i++) {
			rid=ktris[i].getRecipientIdentifier();
			if(matchRecipientIdentifier(rid,keyId)) {
				printEncryptAlgorithm(ktris[i].getKeyEncryptionAlgorithm());
				System.out.println("EncryptedKey:"+Hex.encode(true, ktris[i].getEncryptedKey()));
				return;
			}
		}
		System.out.println("no match skid");
	}

	private static byte[] getRecipientInfos(String fileName) throws Exception {
		FileInputStream fIn=new FileInputStream(fileName);
		EnvelopedData env=null;
		try {
			env=new EnvelopedData(false);
			env.dontDecrypt();
			byte[] data=new byte[8192];
			env.decryptInit();
			int len;
			byte[] info;
			for(;;) {
				len=fIn.read(data);
				if(len==-1){
					throw new Exception("no enveloped data");
				}
				env.decryptUpdate(data,0, len);
				info=env.getRecipientInfosEncode();
				if(info!=null) {
					return info;
				}
			}
		} finally {
			fIn.close();
			
			if(env!=null) {
				env.free();
			}
		}
		
	}
	
	private static boolean matchRecipientIdentifier(RecipientIdentifier rid,byte[] keyid) {
		if(rid.getType()!=RecipientIdentifier.SUBJECT_KEY_IDENTIFIER) {
			return false;
		}
		
		byte[] keyid2=rid.getSubjectKeyIdentifier();
		if(keyid.length!=keyid2.length){
			return false;
		}
		
		for(int i=0;i<keyid.length;i++) {
			if(keyid[i]!=keyid2[i]){
				return false;
			}
		}
		return true;
	}
	
	private static void printEncryptAlgorithm(AlgorithmIdentifier algo) {
		String oid=algo.getAlgorithm();
		if(oid.equals("1.2.840.113549.1.1.1")) {
			System.out.println("RSA");
		} else if(oid.equals("1.2.156.10197.1.301.3")) {
			System.out.println("SM2");
		} else {
			System.out.println("Unknown Algo:" +oid);
		}
	}
}
