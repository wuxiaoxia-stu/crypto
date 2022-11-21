import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Attribute;
import net.netca.pki.encoding.asn1.pki.Hashable;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.Verifible;
import net.netca.pki.encoding.asn1.pki.X509CRL;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.SignedData;
import net.netca.pki.encoding.asn1.pki.cms.SignerInfo;
import net.netca.pki.encoding.asn1.pki.cms.cades.CRLListID;
import net.netca.pki.encoding.asn1.pki.cms.cades.CertificateValues;
import net.netca.pki.encoding.asn1.pki.cms.cades.CompleteCertificateRefs;
import net.netca.pki.encoding.asn1.pki.cms.cades.CompleteRevocationRefs;
import net.netca.pki.encoding.asn1.pki.cms.cades.CrlOcspRef;
import net.netca.pki.encoding.asn1.pki.cms.cades.CrlValidatedID;
import net.netca.pki.encoding.asn1.pki.cms.cades.OcspIdentifier;
import net.netca.pki.encoding.asn1.pki.cms.cades.OcspListID;
import net.netca.pki.encoding.asn1.pki.cms.cades.OcspResponsesID;
import net.netca.pki.encoding.asn1.pki.cms.cades.OtherCertID;
import net.netca.pki.encoding.asn1.pki.cms.cades.OtherHash;
import net.netca.pki.encoding.asn1.pki.cms.cades.RevocationValues;
import net.netca.pki.encoding.asn1.pki.ocsp.BasicOCSPResponse;
import net.netca.pki.encoding.asn1.pki.ocsp.OCSPResponse;

public class CAdESXLongCreate {

	public static void main(String[] args) throws Exception {
		int argCount=args.length;
		if(argCount<7) {
			usage();
            return;
        }
		String tbsFileName=args[0];
		String oldSignedDataFileName=args[1];
		String outputFileName=args[2];
		int pos=3;
		
		AlgorithmIdentifier certHashAlgo=createHashAlgo(args[pos]);
		if(certHashAlgo==null){
			System.out.println("不支持的证书引用Hash算法");
			return;
		}
		pos++;
		
		boolean hasIssuerSerial=false;
		if(args[pos].equalsIgnoreCase("hasIssuerSerial")) {
			hasIssuerSerial=true;
			pos++;
		}
		
		AlgorithmIdentifier crlHashAlgo=createHashAlgo(args[pos]);
		if(crlHashAlgo==null){
			System.out.println("不支持的CRL引用Hash算法");
			return;
		}
		pos++;
		
		boolean hasCrlIdentifier=false;
		if(args[pos].equalsIgnoreCase("hasCrlIdentifier")) {
			hasCrlIdentifier=true;
			pos++;
		}
		
		AlgorithmIdentifier ocspHashAlgo=null;
		String head=args[pos].substring(0,1);
		if(head.equals("-")==false) {
			ocspHashAlgo=createHashAlgo(args[pos]);
			if(ocspHashAlgo==null){
				System.out.println("不支持的OCSP引用Hash算法");
				return;
			}
			pos++;
		}

		
		
		AlgorithmIdentifier certcrltimstampHashAlgo=null;
		String certcrltimstampUrl=null;
		
		AlgorithmIdentifier esctimstampHashAlgo=null;
		String esctimstampUrl=null;
		
		
		byte[] tbs=readFile(tbsFileName);
		byte[] signedData=readFile(oldSignedDataFileName);
		
		SignedData signedDataObj=new SignedData(signedData);
		boolean isDetached=signedDataObj.isDetached();
		if(isDetached==false){
			byte[] tbs2=signedDataObj.getEncapContentInfo().getTbs();
			if(Arrays.equals(tbs, tbs2)==false) {
				System.out.println("原文不匹配");
	            return;
			}
		}
		Verifible verifier=new JCEVerifier();
		Hashable hasher=new JCEHasher();
		int signerInfoCount=signedDataObj.getSignerInfoCount();
		if(signerInfoCount!=1){
			System.out.println("签名个数不为1");
            return;
		}
		if(signedDataObj.verify(0, tbs,verifier, hasher)==false){
			System.out.println("验证签名失败");
			return;
		}
		
		if(signedDataObj.hasSigningCertificateAttribute(0)==false 
				&& signedDataObj.hasSigningCertificateV2Attribute(0)==false){
			System.out.println("既没有SigningCertificate属性也没有SigningCertificateV2属性，不是CAdES-BES");
			return;
		}
		
		SignerInfo signerInfo=signedDataObj.getSignerInfos().get(0);
		if(signerInfo.hasSignatureTimeStamp()==false){
			System.out.println("没有SignatureTimeStamp属性，不是CAdES-T");
			return;
		}
		
		if(signerInfo.verifySignatureTimeStamp()==false){
			System.out.println("验证SignatureTimeStamp失败");
			return;
		}
		Date t=signerInfo.getSignatureTimeStampTime();
		System.out.println("SignatureTimeStamp的时间："+t);
		
		X509Certificate cert;
		ArrayList<X509Certificate> certs=new ArrayList<X509Certificate>();
		String fileName;
		
		X509CRL crl;
		ArrayList<X509CRL> crls=new ArrayList<X509CRL>();
		
		CompleteRevocationRefs completeRevocationRefs=new CompleteRevocationRefs();
		CrlOcspRef crlOcspRef;
		
		BasicOCSPResponse ocsp;
		ArrayList<BasicOCSPResponse> ocsps=new ArrayList<BasicOCSPResponse>();
		
		int i=pos;
		while(i<argCount){
			if(args[i].equalsIgnoreCase("-cert")) {
				fileName=args[i+1];
				cert=getCert(fileName);
				certs.add(cert);
				i+=2;
			} else if(args[i].equalsIgnoreCase("-crl")) {
				fileName=args[i+1];
				crl=getCRL(fileName);
				crls.add(crl);
				crlOcspRef=createCrlOcspRef(crl,crlHashAlgo,hasher,hasCrlIdentifier);
				completeRevocationRefs.add(crlOcspRef);
				i+=2;
			} else if(args[i].equalsIgnoreCase("-ocsp")) {
				fileName=args[i+1];
				ocsp=getOCSP(fileName);
				ocsps.add(ocsp);
				crlOcspRef=createCrlOcspRef(ocsp,ocspHashAlgo,hasher);
				completeRevocationRefs.add(crlOcspRef);
				i+=2;
			} else if(args[i].equalsIgnoreCase("-certcrltimstamp")) {
				certcrltimstampHashAlgo=createHashAlgo(args[i+1]);
				if(certcrltimstampHashAlgo==null){
					System.out.println("不支持的CertCRL时间戳Hash算法");
					return;
				}
				certcrltimstampUrl=args[i+2];
				i+=3;
			} else if(args[i].equalsIgnoreCase("-esctimstamp")) {
				esctimstampHashAlgo=createHashAlgo(args[i+1]);
				if(esctimstampHashAlgo==null){
					System.out.println("不支持的ESC时间戳Hash算法");
					return;
				}
				esctimstampUrl=args[i+2];
				i+=3;
			} else {
				usage();
				return;
			}
			
		}
		
		if(i!=argCount){
			usage();
			return;
		}
		
		if(completeRevocationRefs.size()==0){
			System.out.println("既没有CRL也没有OCSP");
			return;
		}
		
		CompleteCertificateRefs completeCertificateRefs=createCompleteCertificateRefs(certs,certHashAlgo,hasher,hasIssuerSerial);
		Attribute attr;
		attr=new Attribute(Attribute.COMPLETE_CERTIFICATE_REFS,completeCertificateRefs.getASN1Object());
		signerInfo.addUnsignedAttrs(attr);
		
		attr=new Attribute(Attribute.COMPLETE_REVOCATION_REFS,completeRevocationRefs.getASN1Object());
		signerInfo.addUnsignedAttrs(attr);
		
		if(certcrltimstampHashAlgo!=null){
			signerInfo.attachCertCRLTimeStamp(certcrltimstampUrl, certcrltimstampHashAlgo);
			t=signerInfo.getCertCRLTimeStampTime();
			System.out.println("CertCRL时间戳时间:"+t);
		}
		
		if(esctimstampHashAlgo!=null){
			signerInfo.attachESCTimeStamp(esctimstampUrl, esctimstampHashAlgo);
			t=signerInfo.getESCTimeStampTime();
			System.out.println("ESC时间戳时间:"+t);
		}
		
		CertificateValues certValues=createCertificateValues(certs);
		attr=new Attribute(Attribute.CERTIFICATE_VALUES,certValues.getASN1Object());
		signerInfo.addUnsignedAttrs(attr);
		
		RevocationValues revocationValues=createRevocationValues(crls,ocsps);
		attr=new Attribute(Attribute.REVOCATION_VALUES,revocationValues.getASN1Object());
		signerInfo.addUnsignedAttrs(attr);
		signerInfo.updateUnsignedAttrs();
		
		signedData=signedDataObj.encode(signedDataObj.isContentInfo());
		SaveFile(outputFileName,signedData);
		System.out.println("创建CAdES-XLong成功");
	}
	
	private static RevocationValues createRevocationValues(ArrayList<X509CRL> crls,ArrayList<BasicOCSPResponse> ocsps) throws Exception{
		if(crls.size()==0){
			crls=null;
		}
		
		if(ocsps.size()==0) {
			ocsps=null;
		}
		return new RevocationValues(crls,ocsps,null);
	}
	
	private static CertificateValues createCertificateValues(ArrayList<X509Certificate> certs) throws Exception{
		CertificateValues certValues=new CertificateValues();
		for(X509Certificate cert:certs){
			certValues.add(cert);
		}
		return certValues;
	}
	
	private static CompleteCertificateRefs createCompleteCertificateRefs(ArrayList<X509Certificate> certs,AlgorithmIdentifier hashAlgo,Hashable hasher,boolean hasIssuerSerial)throws Exception{
		CompleteCertificateRefs refs=new CompleteCertificateRefs();
		OtherCertID certId;
		for(X509Certificate cert:certs){
			certId=new OtherCertID(cert,hashAlgo,hasher,hasIssuerSerial);
			refs.add(certId);
		}
		return refs;
	}
	
	
	private static CrlOcspRef createCrlOcspRef(BasicOCSPResponse ocsp,AlgorithmIdentifier hashAlgo,Hashable hasher) throws Exception{
		OcspIdentifier ocspIdentifier=new OcspIdentifier(ocsp.getResponderID(),ocsp.getProducedAt());
		OtherHash otherHash=null;
		if(hashAlgo!=null){
			otherHash=new OtherHash(hashAlgo,hasher,ocsp.getASN1Object().encode());
		}
		OcspResponsesID ocspId=new OcspResponsesID(ocspIdentifier,otherHash);
		OcspListID ocspids=new OcspListID(ocspId);
		return new CrlOcspRef(null,ocspids,null);
	}
	
	private static BasicOCSPResponse getOCSP(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		BasicOCSPResponse basicResp=null;
		try {
			basicResp=BasicOCSPResponse.decode(data);
			return basicResp;
		} catch(PkiException e) {
			OCSPResponse resp=OCSPResponse.decode(data);
			return resp.getBasicOCSPResponse();
		}
		
	}
	
	private static void usage() {
		System.out.println("Usage: java CAdESXLongCreate tbsFileName oldSignedDataFileName outputFileName "
        		+ "certHashAlgo [hasIssuerSerial] "
        		+ "crlHashAlgo [hasCrlIdentifier] [ocspHashAlgo] "
         		+ "-cert certFileName1 [-cert certFileName2 ... -cert certFileNameN] "
        		+"-crl crlFileName1 [-crl crlFileName2 ... -crl crlFileNameN] "
        		+"-ocsp ocspFileName1 [-ocsp ocspFileName2 ... -ocsp ocspFileNameN] "
        		+"[-certcrltimstamp hashAlgo url ]"
        		+"[-esctimstamp hashAlgo url]"
        		);
    }
	private static CrlOcspRef createCrlOcspRef(X509CRL crl,AlgorithmIdentifier hashAlgo,Hashable hasher,boolean hasCrlIdentifier) throws Exception{
		CrlValidatedID crlId=new CrlValidatedID(crl,hashAlgo,hasher,hasCrlIdentifier);
		CRLListID crlids=new CRLListID(crlId);
		return new CrlOcspRef(crlids,null,null);
	}

	private static X509CRL getCRL(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509CRL(data);
	}
	
	private static X509Certificate getCert(String fileName) throws Exception{
		byte[] data=readFile(fileName);
		return new X509Certificate(data);
	}
	
	private static void SaveFile(String fileName,byte[] data)throws Exception {
		FileOutputStream f=new FileOutputStream(fileName);
		f.write(data);
		f.close();
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
}
