import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;
import net.netca.pki.encoding.asn1.pki.cms.cades.*;
import net.netca.pki.encoding.asn1.pki.ocsp.BasicOCSPResponse;
import net.netca.pki.encoding.asn1.pki.tsp.MessageImprintMisMatchException;

public class CAdESVerify {
	private static X509Certificate[] signCerts;
	
	public static void main(String[] args) throws Exception{
		if (args.length!=2) {
			System.out.println("Usage: java CAdESVerify tbsFileName signedDataFileName");
            return;
		}
		byte[] tbs=readFile(args[0]);
		byte[] signedData=readFile(args[1]);
		
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
		System.out.printf("一共有%d个签名\n", signerInfoCount);
		signCerts=new X509Certificate[signerInfoCount];
		for(int i=0;i<signerInfoCount;i++){
			if(signedDataObj.verify(i, tbs,verifier, hasher)==false){
				System.out.printf("验证第%d个签名失败\n",i);
				signCerts[i]=null;
			} else {
				signCerts[i]=signedDataObj.getSignCert(i);
			}
		}
		
		ArrayList<SignerInfo> signerInfos=signedDataObj.getSignerInfos();
		int count=signerInfos.size();
		for(int i=0;i<count;i++){
			verifySignerInfo(signedDataObj,tbs,signerInfos.get(i),i,verifier,hasher);
		}
	}
	
	private static void verifySignerInfo(SignedData signedDataObj,byte[] tbs,SignerInfo signerInfo,int index,Verifible verifier,Hashable hasher) throws Exception{
		checkBES(signerInfo,index);
		checkT(signerInfo,index);
		checkXLong(signerInfo,index,verifier,hasher);
		checkEscTimeStamp(signerInfo,index);
		checkCertCRLTimestamp(signerInfo,index);
		checkAtsv2(signedDataObj,tbs,signerInfo,index);
		checkAtsv3(signedDataObj,tbs,signerInfo,index,hasher);
	}
	
	private static void checkBES(SignerInfo signerInfo,int index) throws Exception{
		boolean hasSigningCert=signerInfo.hasSigningCertificateAttribute();
		boolean hasSigningCertV2=signerInfo.hasSigningCertificateV2Attribute();
		if(hasSigningCert==false && hasSigningCertV2==false){
			System.out.printf("第%d个签名既没有SigningCertificate属性，也没有SigningCertificateV2。\n",index);
			return;
		}
		if(hasSigningCert){
			System.out.printf("第%d个签名有SigningCertificate属性\n",index);
		}
		if(hasSigningCertV2) {
			System.out.printf("第%d个签名有SigningCertificateV2属性\n",index);
		}
	}
	
	private static void checkT(SignerInfo signerInfo,int index) throws Exception{
		if(signerInfo.hasSignatureTimeStamp()==false){
			System.out.printf("第%d个签名没有SignatureTimeStamp属性。\n",index);
			return;
		}
		System.out.printf("第%d个签名有SignatureTimeStamp属性。\n",index);
		try{
			if(signerInfo.verifySignatureTimeStamp()){
				System.out.printf("验证第%d个签名的SignatureTimeStamp属性成功，时间戳时间:%s。\n",index,signerInfo.getSignatureTimeStampTime().toString());
			}else{
				System.out.printf("验证第%d个签名的SignatureTime失败。\n",index);
			}
		}catch(MessageImprintMisMatchException e) {
			System.out.printf("第%d个签名的SignatureTime时间戳的Hash值不符。\n",index);
		}
	}
	
	private static void checkAtsv2(SignedData signedDataObj,byte[] tbs,SignerInfo signerInfo,int index) throws Exception{
		ArrayList<Attribute> attrs=signerInfo.getArchiveTimeStampV2Attributes();
		int count=attrs.size();
		if(count==0){
			System.out.printf("第%d个签名没有ArchiveTimeStampV2属性。\n",index);
			return;
		}
		System.out.printf("第%d个签名有%d个ArchiveTimeStampV2属性。\n",index,count);
		Attribute attr;
		for(int i=0;i<count;i++){
			attr=attrs.get(i);
				try{
				if(signerInfo.verifyArchiveTimeStampTokenV2(attr, signedDataObj, tbs)){
					System.out.printf("验证第%d个签名的第%d个ArchiveTimeStampV2属性成功，时间戳时间:%s。\n",index,i,signerInfo.getArchiveTimeStampV2Time());
				} else {
					System.out.printf("验证第%d个签名的第%d个ArchiveTimeStampV2属性失败。\n",index,i);
				}
			}catch(MessageImprintMisMatchException e) {
				System.out.printf("第%d个签名的第%d个ArchiveTimeStampV2时间戳的Hash值不符。\n",index,i);
			}
		}
		
	}
	
	private static void checkAtsv3(SignedData signedDataObj,byte[] tbs,SignerInfo signerInfo,int index,Hashable hasher) throws Exception{
		ArrayList<Attribute> attrs=signerInfo.getArchiveTimeStampV3Attributes();
		int count=attrs.size();
		if(count==0){
			System.out.printf("第%d个签名没有ArchiveTimeStampV3属性。\n",index);
			return;
		}
		System.out.printf("第%d个签名有%d个ArchiveTimeStampV3属性。\n",index,count);
		Attribute attr;
		for(int i=0;i<count;i++){
			attr=attrs.get(i);
				try{
				if(signerInfo.verifyArchiveTimeStampTokenV3(attr, signedDataObj, tbs)){
					System.out.printf("验证第%d个签名的第%d个ArchiveTimeStampV3属性成功，时间戳时间:%s。\n",index,i,signerInfo.getArchiveTimeStampV3Time());
					ATSHashIndex atsIndex=signerInfo.getATSHashIndex();
					ATSHashIndexV3 atsIndexV3=signerInfo.getATSHashIndexV3();
					if(atsIndex!=null) {
						System.out.printf("第%d个签名的第%d个ArchiveTimeStampV3属性有ATSHashIndex\n",index,i);
						if(atsIndex.isIncludedIn(signedDataObj.getCertificates(),
								signedDataObj.getCrls(),signerInfo.getUnsignedAttrs(),hasher)==false){
							System.out.printf("第%d个签名的第%d个ArchiveTimeStampV3属性的ATSHashIndex存在不包含的Hash数据\n",index,i);	
						} else {
							System.out.printf("验证第%d个签名的第%d个ArchiveTimeStampV3属性的ATSHashIndex成功\n",index,i);
						}
								
					} else {
						System.out.printf("第%d个签名的第%d个ArchiveTimeStampV3属性有ATSHashIndexV3\n",index,i);
						if(atsIndexV3.isIncludedIn(signedDataObj.getCertificates(), signedDataObj.getCrls(),
								signerInfo.getUnsignedAttrs(),hasher)==false) {
							System.out.printf("第%d个签名的第%d个ArchiveTimeStampV3属性的ATSHashIndexV3存在不包含的Hash数据\n",index,i);
						} else {
							System.out.printf("验证第%d个签名的第%d个ArchiveTimeStampV3属性的ATSHashIndexV3成功\n",index,i);
						}
					}
					
				} else {
					System.out.printf("验证第%d个签名的第%d个ArchiveTimeStampV3属性失败。\n",index,i);
				}
			}catch(MessageImprintMisMatchException e) {
				System.out.printf("第%d个签名的第%d个ArchiveTimeStampV3时间戳的Hash值不符。\n",index,i);
			}
		}
		
	}
	
	private static void checkXLong(SignerInfo signerInfo,int index,Verifible verifier,Hashable hasher)throws Exception{
		X509Certificate signCert=signCerts[index];
		Attributes attrs=signerInfo.getUnsignedAttrs();
		if(attrs==null){
			System.out.printf("第%d个签名没有不签名属性。\n",index);
			return;
		}
		Attribute attr;
		CompleteCertificateRefs certRef=null;
		attr=attrs.get(Attribute.COMPLETE_CERTIFICATE_REFS);
		if(attr!=null){
			certRef=CompleteCertificateRefs.decode(attr.getValue(0).encode());
			System.out.printf("第%d个签名有CompleteCertificateRefs属性。\n",index);
		} else {
			System.out.printf("第%d个签名没有CompleteCertificateRefs属性。\n",index);
		}
		
		CompleteRevocationRefs revRefs=null;
		attr=attrs.get(Attribute.COMPLETE_REVOCATION_REFS);
		if(attr!=null){
			revRefs=CompleteRevocationRefs.decode(attr.getValue(0).encode());
			System.out.printf("第%d个签名有CompleteRevocationRefs属性。\n",index);
		} else {
			System.out.printf("第%d个签名没有CompleteRevocationRefs属性。\n",index);
		}
		
		
		attr=attrs.get(Attribute.CERTIFICATE_VALUES);
		CertificateValues certValues=null;
		
		if(attr!=null){
			certValues=CertificateValues.decode(attr.getValue(0).encode());
			System.out.printf("第%d个签名有CertificateValues属性。\n",index);
		} else {
			System.out.printf("第%d个签名没有CertificateValues属性。\n",index);
		}
		
		attr=attrs.get(Attribute.REVOCATION_VALUES);
		RevocationValues revValues=null;
		
		if(attr!=null){
			revValues=RevocationValues.decode(attr.getValue(0).encode());
			System.out.printf("第%d个签名有RevocationValues属性。\n",index);
		} else {
			System.out.printf("第%d个签名没有RevocationValues属性。\n",index);
		}
		
		boolean certMatch=false;
		if(certRef!=null && certValues!=null){
			certMatch=certValues.match(certRef, signCert,hasher);
			if(certMatch==false){
				System.out.printf("第%d个签名CertificateValues属性和CompleteCertificateRefs属性不匹配。\n",index);
			} else {
				System.out.printf("第%d个签名CertificateValues属性和CompleteCertificateRefs属性匹配。\n",index);
			}
		}
		
		boolean revMatch=false;
		if(revRefs!=null && revValues!=null){
			revMatch=revValues.match(revRefs, hasher);
			if(revMatch==false) {
				System.out.printf("第%d个签名RevocationValues属性和CompleteRevocationRefs属性不匹配。\n",index);
			} else {
				System.out.printf("第%d个签名RevocationValues属性和CompleteRevocationRefs属性匹配。\n",index);
			}
			
		}
		if(signCert==null){
			return;
		}
		X509Certificate[] certPath=null;
		if(certValues!=null) {
			try {
				certPath=getCertPath(verifier,signCert,certValues);
				System.out.printf("第%d个签名构造证书链成功。\n",index);
			}catch(Exception e) {
				System.out.printf("第%d个签名构造证书链失败。\n",index);
			}
		}
		if(certPath==null){
			return;
		}
		try{
			verifyCertPath(verifier,certPath,revValues);
			System.out.printf("第%d个签名验证证书链成功。\n",index);
		} catch(Exception e) {
			System.out.printf("第%d个签名验证证书链失败:%s\n",index,e.getMessage());
		}
	}
	
	private static X509Certificate[] getCertPath(Verifible verifier,X509Certificate signCert,CertificateValues certValues)throws Exception{
		X509CertificatePathBuilder builder=new X509CertificatePathBuilder();
		X509Certificate rootCert=getRootCert(verifier,certValues);
		if(rootCert==null) {
			throw new Exception("没有根证书");
		}
		builder.addRootCert(rootCert);
		X509Certificate cert;
		int count=certValues.size();
		int caCertCount=0;
		for(int i=0;i<count;i++){
			cert=certValues.get(i);
			if(cert.equals(signCert)==false && cert.equals(rootCert)==false){
				caCertCount++;
				builder.addCACert(cert);
			}
		}
		ArrayList<X509Certificate[]> list=builder.build(signCert);
		int certPathCount=list.size();
		X509Certificate[] certPath=null;
		for(int i=0;i<certPathCount;i++){
			if(list.get(i).length==caCertCount+2){
				certPath=list.get(i);
				break;
			}
		}
		if(certPath==null){
			throw new Exception("没有构造出合适的证书链");
		}
		return certPath;
	}
	
	
	
	private static X509Certificate getRootCert(Verifible verifier,CertificateValues certValues) throws Exception{
		/* 应该从外部指定根证书 ，下面的做法是有问题的*/
		X509Certificate cert;
		int count=certValues.size();
		for(int i=0;i<count;i++){
			cert=certValues.get(i);
			if(isSelfSign(verifier,cert)){
				return cert;
			}
		}
		return null;
	}
	
	private static boolean isSelfSign(Verifible verifier,X509Certificate cert) throws Exception{
		byte[] issuerEncode=cert.getIssuer().getASN1Object().encode();
		byte[] subjectEncode=cert.getSubject().getASN1Object().encode();
		if(Arrays.equals(issuerEncode, subjectEncode)==false) {
			return false;
		}
		return cert.verifySignature(verifier, cert.getSubjectPublicKeyInfo().getPublicKey());
	}
	
	
	private static void verifyCertPath(Verifible verifier,X509Certificate[] certPath,RevocationValues revValues)throws Exception{
		X509CertificatePathValidator validator=new X509CertificatePathValidator();
		int verify_level=X509CertificatePathValidator.VERIFY_LEVEL_NO_REVOKE;
		if(revValues!=null){
			verify_level=X509CertificatePathValidator.VERIFY_LEVEL_VERIFY_CERTPATH_REVOKE;
		}
		validator.setVerifier(verifier);
		validator.setVerifyLevel(verify_level);
		validator.setOption(X509CertificatePathValidator.VERIFY_OPTION_NOT_VERIFY_TIME);
		if(revValues!=null){
			addRevokeData(validator,revValues);
		}
		validator.verify(certPath);
		//TODO 检查revValues
	}
	
	private static void addRevokeData(X509CertificatePathValidator validator,RevocationValues revValues) throws PkiException {
		int count;
		ArrayList<X509CRL> crls=revValues.getCrlVals();
		if(crls!=null){
			count=crls.size();
			for(int i=0;i<count;i++){
				validator.addCRL(crls.get(i));
			}
		}
		ArrayList<BasicOCSPResponse> ocsps=revValues.getOcspVals();
		if(ocsps!=null){
			count=ocsps.size();
			for(int i=0;i<count;i++){
				validator.addOCSPResponse(ocsps.get(i));
			}
		}
	}
	
	private static void checkEscTimeStamp(SignerInfo signerInfo,int index)throws Exception{
		if(signerInfo.hasESCTimeStamp()==false){
			System.out.printf("第%d个签名没有ESCTimeStamp属性。\n",index);
			return;
		}
		System.out.printf("第%d个签名有ESCTimeStamp属性。\n",index);
		try{
			if(signerInfo.verifyESCTimeStamp()){
				System.out.printf("验证第%d个签名的ESCTimeStamp属性成功，时间戳时间:%s。\n",index,signerInfo.getESCTimeStampTime().toString());
			}else{
				System.out.printf("验证第%d个签名的ESCTimeStamp失败。\n",index);
			}
		}catch(MessageImprintMisMatchException e) {
			System.out.printf("第%d个签名的ESCTimeStamp时间戳的Hash值不符。\n",index);
		}
	}
	
	private static void checkCertCRLTimestamp(SignerInfo signerInfo,int index)throws Exception{
		if(signerInfo.hasCertCRLTimeStamp()==false){
			System.out.printf("第%d个签名没有CertCRLTimestamp属性。\n",index);
			return;
		}
		System.out.printf("第%d个签名有CertCRLTimestamp属性。\n",index);
		try{
			if(signerInfo.verifyCertCRLTimeStamp()){
				System.out.printf("验证第%d个签名的CertCRLTimestamp属性成功，时间戳时间:%s。\n",index,signerInfo.getCertCRLTimeStampTime().toString());
			}else{
				System.out.printf("验证第%d个签名的CertCRLTimestamp失败。\n",index);
			}
		}catch(MessageImprintMisMatchException e) {
			System.out.printf("第%d个签名的CertCRLTimestamp时间戳的Hash值不符。\n",index);
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
