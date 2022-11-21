import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.ESSCertID;
import net.netca.pki.encoding.asn1.pki.cms.ESSCertIDv2;
import net.netca.pki.encoding.asn1.pki.cms.SignedData;
import net.netca.pki.encoding.asn1.pki.cms.SignedDataBuilder;
import net.netca.pki.encoding.asn1.pki.cms.Signer;
import net.netca.pki.encoding.asn1.pki.cms.SigningCertificate;
import net.netca.pki.encoding.asn1.pki.cms.SigningCertificateV2;

import java.util.ArrayList;
import java.util.Date;

public class CAdESBESCreate2 {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=7 && argCount!=6) {
            System.out.println("Usage: java CAdESBESCreate2 [-detached] signAlgo tbsFileName certFileName pwd hashAlgo outputFileName");
            return;
        }
		int pos=0;
		boolean detached=false;
		if(argCount==7){
			if(args[0].equalsIgnoreCase("-detached")==false){
				System.out.println("Usage: java CAdESBESCreate2 [-detached] signAlgo tbsFileName certFileName pwd hashAlgo outputFileName");
	            return;
			}
			pos=1;
			detached=true;
		}
		
		AlgorithmIdentifier signAlgo=createSignAlgo(args[pos]);
		if(signAlgo==null){
			System.out.println("不支持的签名算法");
			return;
		}
		pos++;
		
		byte[] tbs=readFile(args[pos]);
		pos++;
		
		X509Certificate cert=getCert(args[pos]);
		pos++;
		
		String pwd=args[pos];
		pos++;
		
		NetcaSigner signer=createSigner(cert,pwd);
		
		AlgorithmIdentifier hashAlgo=createHashAlgo(args[pos]);
		if(hashAlgo==null){
			System.out.println("不支持的Hash算法");
			return;
		}
		pos++;
		
		String outputFileName=args[pos];
		byte[] signedData=createSignedData(detached,tbs,signer,cert,signAlgo,hashAlgo);
		SaveFile(outputFileName,signedData);
		System.out.println("签名成功");
	}
	
	private static void SaveFile(String fileName,byte[] data)throws Exception {
		FileOutputStream f=new FileOutputStream(fileName);
		f.write(data);
		f.close();
	}
	private static Attribute createSigningTimeAttribute()throws PkiException{
		Time t=new Time(new Date());
		return new Attribute(Attribute.SIGNING_TIME,t.getASN1Object());
	}
	
	private static Attribute createSigningCertificateAttribute(Hashable hasher,X509Certificate cert)throws PkiException{
		ESSCertID essCertId=new ESSCertID(cert,hasher,true);
		ArrayList<ESSCertID> essCertIdList=new ArrayList<ESSCertID>();
		essCertIdList.add(essCertId);
		
		SigningCertificate signingCert=new SigningCertificate(essCertIdList,null);
		return new Attribute(Attribute.SIGNING_CERTIFICATE,signingCert.getASN1Object());
	}
	
	private static Attribute createSigningCertificateV2Attribute(AlgorithmIdentifier hashAlgo,Hashable hasher,X509Certificate cert)throws PkiException{
		ESSCertIDv2 essCertId=new ESSCertIDv2(hashAlgo,cert,hasher,true);
		ArrayList<ESSCertIDv2> essCertIdList=new ArrayList<ESSCertIDv2>();
		essCertIdList.add(essCertId);
		
		SigningCertificateV2 signingCert=new SigningCertificateV2(essCertIdList,null);
		return new Attribute(Attribute.SIGNING_CERTIFICATE_V2,signingCert.getASN1Object());
	}
	
	private static Signer createSigner(Signable signer,X509Certificate cert,AlgorithmIdentifier signAlgo,AlgorithmIdentifier hashAlgo,Hashable hasher)throws PkiException {
		Signer signerObj=new Signer(cert,signer);
		signerObj.setSignatureAlgorithm(signAlgo);
		Attribute attr=createSigningTimeAttribute();
		signerObj.addSignedAttribute(attr);
		if(hashAlgo.getOid().equals(AlgorithmIdentifier.SHA1_OID)){
			attr=createSigningCertificateAttribute(hasher,cert);
			signerObj.addSignedAttribute(attr);
		} else {
			attr=createSigningCertificateV2Attribute(hashAlgo,hasher,cert);
			signerObj.addSignedAttribute(attr);
		}
		
		return signerObj;
	}
	
	private static byte[] createSignedData(boolean detached,byte[] tbs,Signable signer,X509Certificate cert,AlgorithmIdentifier signAlgo,AlgorithmIdentifier hashAlgo) throws PkiException {
		SignedDataBuilder builder=new SignedDataBuilder();
		builder.setDetached(detached);
		builder.setContent(tbs);
		Hashable hasher=new JCEHasher();
		builder.setHasher(hasher);
		Signer signerObj=createSigner(signer,cert,signAlgo,hashAlgo,hasher);
		builder.addSigner(signerObj);
		SignedData signedDataObj=builder.sign();
		return signedDataObj.encode(true);
	}
	
	
	private static AlgorithmIdentifier createHashAlgo(String algo) throws PkiException {
		if(algo.equalsIgnoreCase("SHA1")
				|| algo.equalsIgnoreCase("SHA-1")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
		}else if(algo.equalsIgnoreCase("SHA224")
				|| algo.equalsIgnoreCase("SHA-224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA224_OID);
		} else if(algo.equalsIgnoreCase("SHA256")
				|| algo.equalsIgnoreCase("SHA-256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
		} else if(algo.equalsIgnoreCase("SHA384")
				|| algo.equalsIgnoreCase("SHA-384")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA384_OID);
		} else if(algo.equalsIgnoreCase("SHA512")
				|| algo.equalsIgnoreCase("SHA-512")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_OID);
		} else if(algo.equalsIgnoreCase("SHA512/224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_224_OID);
		} else if(algo.equalsIgnoreCase("SHA512/256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_256_OID);
		} else if(algo.equalsIgnoreCase("SHA3-224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_224_OID);
		} else if(algo.equalsIgnoreCase("SHA3-256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_256_OID);
		} else if(algo.equalsIgnoreCase("SHA3-384")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_384_OID);
		} else if(algo.equalsIgnoreCase("SHA3-512")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_512_OID);
		} else if(algo.equalsIgnoreCase("SM3")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3_OID);
		} else {
			return null;
		}
	}
	
	private static NetcaSigner createSigner(X509Certificate x509Cert,String pwd) throws Exception{
		KeyPair keypair=null;
		Certificate cert=null;
		try{
			cert=new Certificate(x509Cert.derEncode());
			keypair=cert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN, pwd);
			if(keypair==null) {
				throw new Exception("证书不在有效期内，没有对应的私钥或者密码错误");
			}
			return new NetcaSigner(keypair);
		} finally{
			if(keypair!=null){
				keypair.free();
			}
			if(cert!=null){
				cert.free();
			}
		}
	}
	
	private static X509Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509Certificate(data);
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
	private static AlgorithmIdentifier createSignAlgo(String algo) throws PkiException {
		if(algo.equalsIgnoreCase("SHA1WITHRSA")
				|| algo.equalsIgnoreCase("SHA-1WITHRSA")
				|| algo.equalsIgnoreCase("SHA1WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA1WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA224WITHRSA")
				|| algo.equalsIgnoreCase("SHA224WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA224WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA256WITHRSA")
				|| algo.equalsIgnoreCase("SHA256WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA384WITHRSA")
				|| algo.equalsIgnoreCase("SHA384WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA384WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA512WITHRSA")
				|| algo.equalsIgnoreCase("SHA512WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA512WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA512/224WITHRSA")
				|| algo.equalsIgnoreCase("SHA512/224WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA512_224WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA512/256WITHRSA")
				|| algo.equalsIgnoreCase("SHA512/256WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA512_256WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA3-224WITHRSA")
				|| algo.equalsIgnoreCase("SHA3-224WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA3_224WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA3-256WITHRSA")
				|| algo.equalsIgnoreCase("SHA3-256WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA3_256WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA3-384WITHRSA")
				|| algo.equalsIgnoreCase("SHA3-384WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA3_384WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SHA3-512WITHRSA")
				|| algo.equalsIgnoreCase("SHA3-512WITHRSAENCRYPTION")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA3_512WithRSA_OID);
		} else if(algo.equalsIgnoreCase("SM3WITHSM2")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA1")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA1_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA224_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA384")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA384_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA512")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA512_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA3-224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA3_224_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA3-256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA3_256_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA3-384")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA3_384_OID);
		} else if(algo.equalsIgnoreCase("ECDSAWITHSHA3-512")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA3_512_OID);
		} else {
			return null;
		}
	}

}
