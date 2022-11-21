import java.io.FileOutputStream;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.SecureRandom;

import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.IA5String;
import net.netca.pki.encoding.asn1.PrintableString;
import net.netca.pki.encoding.asn1.UTF8String;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.EncryptedPrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.JCESecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.JCESymEncrypter;
import net.netca.pki.encoding.asn1.pki.Pkcs5PBKDF2;
import net.netca.pki.encoding.asn1.pki.PrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.X500Name;
import net.netca.pki.encoding.asn1.pki.RelativeDistinguishedName;
import net.netca.pki.encoding.asn1.pki.AttributeTypeAndValue;
import net.netca.pki.encoding.asn1.pki.RSAPrivateKey;
import net.netca.pki.encoding.asn1.pki.CertificationRequestBuilder;
import net.netca.pki.encoding.asn1.pki.SubjectPublicKeyInfo;
import net.netca.pki.encoding.asn1.pki.RSAPublicKey;
import net.netca.pki.encoding.asn1.pki.JCESigner;
import net.netca.pki.encoding.asn1.pki.CertificationRequest;

public final class GenerateRSAP10 {
	public static void main(String[] args) throws Exception{
		if(args.length!=5) {
            System.out.println("Usage: java GenerateRSAP10 bits subject pwd privKeyFileName p10FileName");
            return;
        }
		
		int bits=Integer.parseInt(args[0]);
		String subject=args[1];
		String pwd=args[2];
		String privKeyFileName=args[3];
		String p10FileName=args[4];
		
		KeyPairGenerator keypairGenerator=KeyPairGenerator.getInstance("RSA");
		keypairGenerator.initialize(bits,new SecureRandom());
		KeyPair keypair=keypairGenerator.generateKeyPair();
		PrivateKey privateKey=keypair.getPrivate();
		if("PKCS#8".equals(privateKey.getFormat())){
			PrivateKeyInfo privKeyInfo=PrivateKeyInfo.decode(privateKey.getEncoded());
			
			RSAPrivateKey rsa=RSAPrivateKey.decode(privKeyInfo.getPrivateKey());
			
			CertificationRequestBuilder builder=new CertificationRequestBuilder();
			builder.setSubject(createName(subject));
			builder.setSubjectPublicKeyInfo(getRSAPublicKey(rsa));
			CertificationRequest p10=builder.sign(new JCESigner(privateKey), 
					AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID));
			
			save(p10FileName,p10.derEncode());
			
			int iterationCount=10240;
			int saltLength=32;
			EncryptedPrivateKeyInfo encPrivKeyInfo=privKeyInfo.pkcs5Encrypt(pwd.getBytes("UTF-8"),
						AlgorithmIdentifier.SHA256_OID,
						iterationCount, saltLength,
						new Pkcs5PBKDF2(),
						AlgorithmIdentifier.AES128CBCPAD_OID,
						new JCESymEncrypter(), 
						JCESecureRandomGenerator.getInstance());
			save(privKeyFileName,encPrivKeyInfo.getASN1Object().encode());
			
			System.out.println("success");
		} else {
			System.out.println("unknown private key format");
			return;
		}
		
		
	}
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
		}
	}
	
	private static SubjectPublicKeyInfo getRSAPublicKey(RSAPrivateKey rsa)throws Exception{
		RSAPublicKey publicKey=new RSAPublicKey(rsa.getModulus(),rsa.getPublicExponent());
		return publicKey.toSubjectPublicKeyInfo(); 
	}
	
	private static X500Name createName(String str)throws Exception{
		String attrs[]=str.split(",");
		X500Name name=new X500Name();
		RelativeDistinguishedName rdn;
		for(int i=0;i<attrs.length;i++){
			rdn=createRDN(attrs[i]);
			name.add(rdn);
		}
		return name;
	}
	private static RelativeDistinguishedName createRDN(String str)throws Exception{
		return new RelativeDistinguishedName(createAttribute(str));
	}
	private static AttributeTypeAndValue createAttribute(String str)throws Exception{
		String values[]=str.split("=");
		if(values==null || values.length!=2){
			throw new Exception("bad attribute");
		}
		String attrOid=getAttributeTypeOid(values[0]);
		ASN1Object value=null;
		if(attrOid.equals(X500Name.COUNTRYNAME_OID)){
			value=new PrintableString(values[1]);
		} else if(attrOid.equals(X500Name.EMAILADDRESS_OID)
				|| attrOid.equals(X500Name.DOMAIN_COMPONENT_OID)){
			value=new IA5String(values[1]);
		} else {
			value=new UTF8String(values[1]);
		}
		return new AttributeTypeAndValue(attrOid,value);
	}
	
	private static String getAttributeTypeOid(String type){
		if(type.equalsIgnoreCase("C")){
			return X500Name.COUNTRYNAME_OID;
		} else if(type.equalsIgnoreCase("CN")){
			return X500Name.COMMONNAME_OID;
		} else if(type.equalsIgnoreCase("ST")
				|| type.equalsIgnoreCase("S")){
			return X500Name.STATEORPROVINCENAME_OID;
		} else if(type.equalsIgnoreCase("L")){
			return X500Name.LOCALITYNAME_OID;
		} else if(type.equalsIgnoreCase("O")){
			return X500Name.ORGANIZATIONNAME_OID;
		} else if(type.equalsIgnoreCase("OU")){
			return X500Name.ORGANIZATIONUNITNAME_OID;
		} else if(type.equalsIgnoreCase("E")){
			return X500Name.EMAILADDRESS_OID;
		} else if(type.equalsIgnoreCase("DC")){
			return X500Name.DOMAIN_COMPONENT_OID;
		} else {
			return type;
		}
	}
}
