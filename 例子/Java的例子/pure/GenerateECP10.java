import java.io.FileOutputStream;

import net.netca.pki.algorithm.ecc.Curve;
import net.netca.pki.algorithm.ecc.ECCKeyPair;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.BitString;
import net.netca.pki.encoding.asn1.IA5String;
import net.netca.pki.encoding.asn1.PrintableString;
import net.netca.pki.encoding.asn1.UTF8String;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.AttributeTypeAndValue;
import net.netca.pki.encoding.asn1.pki.CertificationRequest;
import net.netca.pki.encoding.asn1.pki.CertificationRequestBuilder;
import net.netca.pki.encoding.asn1.pki.ECPrivateKey;
import net.netca.pki.encoding.asn1.pki.EncryptedPrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.JCESecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.JCESigner;
import net.netca.pki.encoding.asn1.pki.JCESymEncrypter;
import net.netca.pki.encoding.asn1.pki.Pkcs5PBKDF2;
import net.netca.pki.encoding.asn1.pki.PrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.RelativeDistinguishedName;
import net.netca.pki.encoding.asn1.pki.SubjectPublicKeyInfo;
import net.netca.pki.encoding.asn1.pki.X500Name;

public class GenerateECP10 {

	public static void main(String[] args)throws Exception {
		if(args.length!=5) {
            System.out.println("Usage: java GenerateECP10 curve subject pwd privKeyFileName p10FileName");
            return;
        }
		
		String curveName=args[0];
		String subject=args[1];
		String pwd=args[2];
		String privKeyFileName=args[3];
		String p10FileName=args[4];
		String curveOid=getCurveOid(curveName);
		Curve curve=Curve.getCurve(curveOid);
		if(curve==null){
			System.out.println("unsupport curve:"+curveName);
			return;
		}
		JCESecureRandomGenerator rand=JCESecureRandomGenerator.getInstance();
		
		ECCKeyPair eccKeyPair=ECCKeyPair.generateKeyPair(curve, rand);
		ECPrivateKey ecPrivateKey=new ECPrivateKey(eccKeyPair);
		PrivateKeyInfo privKeyInfo=PrivateKeyInfo.NewEC(ecPrivateKey);
		int iterationCount=10240;
		int saltLength=32;
		EncryptedPrivateKeyInfo encPrivKeyInfo=privKeyInfo.pkcs5Encrypt(pwd.getBytes("UTF-8"),
					AlgorithmIdentifier.SHA256_OID,
					iterationCount, saltLength,
					new Pkcs5PBKDF2(),
					AlgorithmIdentifier.AES128CBCPAD_OID,
					new JCESymEncrypter(), 
					rand);
		save(privKeyFileName,encPrivKeyInfo.getASN1Object().encode());
		//save(privKeyFileName,privKeyInfo.getASN1Object().encode());
		
		
		CertificationRequestBuilder builder=new CertificationRequestBuilder();
		builder.setSubject(createName(subject));
		
		AlgorithmIdentifier signAlgo=getSignAlgo(curveOid);
		builder.setSubjectPublicKeyInfo(getECCPublicKey(curveOid,ecPrivateKey.getPublicKey()));
		CertificationRequest p10=builder.sign(new JCESigner(privKeyInfo), 
				signAlgo);
		
		save(p10FileName,p10.derEncode());
		
		
		System.out.println("success");
		
	}
	
	private static SubjectPublicKeyInfo getECCPublicKey(String curveOid,byte[] publicKey)throws Exception{
		AlgorithmIdentifier algo=AlgorithmIdentifier.CreateECCPublicKeyAlgorithmIdentifier(curveOid);
		return new SubjectPublicKeyInfo(algo,new BitString(0,publicKey));
	}
	
	private static AlgorithmIdentifier getSignAlgo(String curveOid)throws Exception{
		if(curveOid.equals(AlgorithmIdentifier.SM2Curve_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
		}else if(curveOid.equals(AlgorithmIdentifier.P192_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA1_OID);
		} else if(curveOid.equals(AlgorithmIdentifier.P224_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA224_OID);
		} else if(curveOid.equals(AlgorithmIdentifier.P256_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
		} else if(curveOid.equals(AlgorithmIdentifier.P384_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA384_OID);
		} else if(curveOid.equals(AlgorithmIdentifier.P521_OID)){
			return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA512_OID);
		} else {
			throw new Exception("unsupport curve:"+curveOid);
		}
	}
	
	private static String getCurveOid(String name){
		if(name.equalsIgnoreCase("SM2")){
			return AlgorithmIdentifier.SM2Curve_OID;
		} else if(name.equalsIgnoreCase("P192")){
			return AlgorithmIdentifier.P192_OID;
		} else if(name.equalsIgnoreCase("P224")){
			return AlgorithmIdentifier.P224_OID;
		} else if(name.equalsIgnoreCase("P256")){
			return AlgorithmIdentifier.P256_OID;
		} else if(name.equalsIgnoreCase("P384")){
			return AlgorithmIdentifier.P384_OID;
		} else if(name.equalsIgnoreCase("P521")){
			return AlgorithmIdentifier.P521_OID;
		} else {
			return name;
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
