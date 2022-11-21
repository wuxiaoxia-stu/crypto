import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.algorithm.ecc.Curve;
import net.netca.pki.algorithm.ecc.ECCKeyPair;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.BitString;
import net.netca.pki.encoding.asn1.IA5String;
import net.netca.pki.encoding.asn1.PrintableString;
import net.netca.pki.encoding.asn1.UTF8String;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.AttributeTypeAndValue;
import net.netca.pki.encoding.asn1.pki.CertificationRequest;
import net.netca.pki.encoding.asn1.pki.CertificationRequestBuilder;
import net.netca.pki.encoding.asn1.pki.ECCPublicKey;
import net.netca.pki.encoding.asn1.pki.ECPrivateKey;
import net.netca.pki.encoding.asn1.pki.JCESigner;
import net.netca.pki.encoding.asn1.pki.NetcaPublicKeyEncrypter;
import net.netca.pki.encoding.asn1.pki.NetcaSecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.NetcaSymEncrypter;
import net.netca.pki.encoding.asn1.pki.NetcaVerifier;
import net.netca.pki.encoding.asn1.pki.PrivateKeyInfo;
import net.netca.pki.encoding.asn1.pki.RelativeDistinguishedName;
import net.netca.pki.encoding.asn1.pki.SM2EnvelopedKey;
import net.netca.pki.encoding.asn1.pki.SubjectPublicKeyInfo;
import net.netca.pki.encoding.asn1.pki.X500Name;
public class EncodeEncKeyPair2 {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=3) {
            System.out.println("Usage: java EncodeEncKeyPair2 certReq newCertReq encKey");
            return;
        }

		String certReqFileName=args[0];
		String newCertReqFileName=args[1];
		String encKeyFileName=args[2];
		
		NetcaVerifier verifier=null;
		NetcaSecureRandomGenerator rand=null;
		NetcaPublicKeyEncrypter publicKeyEncrypter=null;
		NetcaSymEncrypter symEncrypter=null;
		
		try{
			CertificationRequest certReq=CertificationRequest.decode(readFile(certReqFileName));
			verifier=new NetcaVerifier();
			if(certReq.verify(verifier)==false){
				System.out.println("证书请求验证失败");
				return;
			}
			SubjectPublicKeyInfo spki=certReq.getSubjectPublicKeyInfo();
			if(spki.isSM2()==false){
				System.out.println("不是SM2公钥");
				return;
			}
			Curve curve=Curve.getCurve(AlgorithmIdentifier.SM2Curve_OID);
			rand=new NetcaSecureRandomGenerator();
			ECCKeyPair eccKeyPair=ECCKeyPair.generateKeyPair(curve, rand);
			ECPrivateKey ecPrivateKey=new ECPrivateKey(eccKeyPair);
			
			PrivateKeyInfo privKeyInfo=PrivateKeyInfo.NewEC(ecPrivateKey);
			
			CertificationRequestBuilder builder=new CertificationRequestBuilder();
			builder.setSubject(createName("C=CN"));
			AlgorithmIdentifier signAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
			
			SubjectPublicKeyInfo newSpki=getECCPublicKey(AlgorithmIdentifier.SM2Curve_OID,ecPrivateKey.getPublicKey());
			builder.setSubjectPublicKeyInfo(newSpki);
			CertificationRequest p10=builder.sign(new JCESigner(privKeyInfo), 
					signAlgo);
			
			save(newCertReqFileName,p10.derEncode());
			AlgorithmIdentifier symAlgID=AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam("1.2.156.10197.1.104");
			ECCPublicKey sm2PublicKey=new ECCPublicKey(spki);
			byte[] sm2PrivateKey=ecPrivateKey.getPrivateKey().toByteArray();
			System.out.println(Hex.encode(true, sm2PrivateKey));
			System.out.println(sm2PrivateKey.length);
			
			System.out.println(Hex.encode(true,ecPrivateKey.getPublicKey()));
			
			byte[] d=new byte[32];
			if(sm2PrivateKey.length==33){
				System.arraycopy(sm2PrivateKey, 1, d, 0, 32);
			}else {
				System.arraycopy(sm2PrivateKey,0 , d, 32-sm2PrivateKey.length, sm2PrivateKey.length);
			}
			System.out.println(Hex.encode(true, d));
			
			publicKeyEncrypter=new NetcaPublicKeyEncrypter();
			symEncrypter=new NetcaSymEncrypter();
			SM2EnvelopedKey sm2Key=SM2EnvelopedKey.create(symAlgID,sm2PublicKey,d,rand,publicKeyEncrypter,symEncrypter);
			save(encKeyFileName,sm2Key.getASN1Object().encode());
		}finally{
			if(verifier!=null){
				verifier.free();
			}
			if(rand!=null){
				rand.free();
			}
			if(publicKeyEncrypter!=null){
				publicKeyEncrypter.free();
			}
			if(symEncrypter!=null){
				symEncrypter.free();
			}
		}
		System.out.println("Success2");
	}
	
	private static SubjectPublicKeyInfo getECCPublicKey(String curveOid,byte[] publicKey)throws Exception{
		AlgorithmIdentifier algo=AlgorithmIdentifier.CreateECCPublicKeyAlgorithmIdentifier(curveOid);
		return new SubjectPublicKeyInfo(algo,new BitString(0,publicKey));
	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=Integer.MAX_VALUE) {
			throw new Exception("file too big");
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail");
			}
			return data;
		} finally {
			fIn.close();
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
