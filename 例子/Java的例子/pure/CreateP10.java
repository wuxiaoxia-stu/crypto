import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.*;
import net.netca.pki.*;
import java.io.*;


public class CreateP10 {
	public static void main(String[] arg) throws Exception {
		if(arg.length!=7) {
            System.out.println("Usage: java CreateP10 deviceType deviceSN pwd enc|sign keypairLabel sha1withrsa|sm3withsm2 p10FileName");
            return;
        }

        int type=java.lang.Integer.valueOf(arg[0]).intValue();
        String sn=arg[1];
        String pwd=arg[2];
        int keypairType=getKeyPairType(arg[3]);
        String label=arg[4];
        AlgorithmIdentifier signAlgo=getSignAlgo(arg[5]);
        String p10FileName=arg[6];

        CertificationRequestBuilder builder=new CertificationRequestBuilder();
        X500Name subject=CreateSubjcet();
        builder.setSubject(subject);

        KeyPair keypair=null;
        net.netca.pki.PublicKey pubkey=null;
        NetcaSigner signer=null;
        NetcaVerifier verifier=null;
        
        try {
	        keypair=KeyPair.findKeyPair(type,sn,Device.DEVICE_FLAG_SILENT,pwd,keypairType,label);
	        if(keypair==null) {
	        	System.out.println("no such keypair or pwd error");
	        	return;
	        }
	        pubkey=keypair.getPublicKey();
	        builder.setSubjectPublicKeyInfo(new SubjectPublicKeyInfo(pubkey.encode()));
	        pubkey.free();
	        pubkey=null;

	        signer=new NetcaSigner(keypair);
	        keypair.free();
	        keypair=null;
	        
	        CertificationRequest p10=builder.sign(signer, signAlgo);
	        signer.free();
	        signer=null;

	        writeFile(p10FileName,p10.derEncode());
	        
	        verifier=new NetcaVerifier();
	        System.out.println(p10.verify(verifier));

    	} finally {
    		if(keypair!=null) {
    			keypair.free();
    		}

    		if(pubkey!=null) {
    			pubkey.free();
    		}
    		
    		if(signer!=null) {
    			signer.free();
    		}
    		
    		if(verifier!=null) {
    			verifier.free();
    		}
    	}
	}

	private static int getKeyPairType(String typeName) throws Exception {
		String lowerName=typeName.toLowerCase();
		if(lowerName.equals("enc")) {
			return KeyPair.ENCRYPT;
		} else if(lowerName.equals("sign")) {
			return KeyPair.SIGNATURE;
		} else {
			throw new Exception("bad keypair type "+ typeName);
		}
	}

	private static AlgorithmIdentifier getSignAlgo(String algoName) throws Exception {
		String lowerName=algoName.toLowerCase();
		if(lowerName.equals("sha1withrsa")) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA1WithRSA_OID);
		} else if(lowerName.equals("sha256withrsa")) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
		} else if(lowerName.equals("sha512withrsa")) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA512WithRSA_OID);
		} else if(lowerName.equals("sm3withsm2")) {
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SM3WithSM2_OID);
		} else {
			throw new Exception("unknown sign algo "+ algoName);
		}	
	}

	private static X500Name CreateSubjcet() throws Exception {
		X500Name subject=new X500Name();

		AttributeTypeAndValue attr;
		attr=new AttributeTypeAndValue(X500Name.COUNTRYNAME_OID,new PrintableString("CN"));
		RelativeDistinguishedName rdn=new RelativeDistinguishedName(attr);
		subject.add(rdn);

		attr=new AttributeTypeAndValue(X500Name.ORGANIZATIONNAME_OID,new UTF8String("≤‚ ‘O"));
		rdn=new RelativeDistinguishedName(attr);
		subject.add(rdn);		

		return subject;
	}

	private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
}
