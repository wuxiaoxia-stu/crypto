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
				System.out.println("ԭ�Ĳ�ƥ��");
	            return;
			}
		}
		Verifible verifier=new JCEVerifier();
		Hashable hasher=new JCEHasher();
		int signerInfoCount=signedDataObj.getSignerInfoCount();
		System.out.printf("һ����%d��ǩ��\n", signerInfoCount);
		signCerts=new X509Certificate[signerInfoCount];
		for(int i=0;i<signerInfoCount;i++){
			if(signedDataObj.verify(i, tbs,verifier, hasher)==false){
				System.out.printf("��֤��%d��ǩ��ʧ��\n",i);
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
			System.out.printf("��%d��ǩ����û��SigningCertificate���ԣ�Ҳû��SigningCertificateV2��\n",index);
			return;
		}
		if(hasSigningCert){
			System.out.printf("��%d��ǩ����SigningCertificate����\n",index);
		}
		if(hasSigningCertV2) {
			System.out.printf("��%d��ǩ����SigningCertificateV2����\n",index);
		}
	}
	
	private static void checkT(SignerInfo signerInfo,int index) throws Exception{
		if(signerInfo.hasSignatureTimeStamp()==false){
			System.out.printf("��%d��ǩ��û��SignatureTimeStamp���ԡ�\n",index);
			return;
		}
		System.out.printf("��%d��ǩ����SignatureTimeStamp���ԡ�\n",index);
		try{
			if(signerInfo.verifySignatureTimeStamp()){
				System.out.printf("��֤��%d��ǩ����SignatureTimeStamp���Գɹ���ʱ���ʱ��:%s��\n",index,signerInfo.getSignatureTimeStampTime().toString());
			}else{
				System.out.printf("��֤��%d��ǩ����SignatureTimeʧ�ܡ�\n",index);
			}
		}catch(MessageImprintMisMatchException e) {
			System.out.printf("��%d��ǩ����SignatureTimeʱ�����Hashֵ������\n",index);
		}
	}
	
	private static void checkAtsv2(SignedData signedDataObj,byte[] tbs,SignerInfo signerInfo,int index) throws Exception{
		ArrayList<Attribute> attrs=signerInfo.getArchiveTimeStampV2Attributes();
		int count=attrs.size();
		if(count==0){
			System.out.printf("��%d��ǩ��û��ArchiveTimeStampV2���ԡ�\n",index);
			return;
		}
		System.out.printf("��%d��ǩ����%d��ArchiveTimeStampV2���ԡ�\n",index,count);
		Attribute attr;
		for(int i=0;i<count;i++){
			attr=attrs.get(i);
				try{
				if(signerInfo.verifyArchiveTimeStampTokenV2(attr, signedDataObj, tbs)){
					System.out.printf("��֤��%d��ǩ���ĵ�%d��ArchiveTimeStampV2���Գɹ���ʱ���ʱ��:%s��\n",index,i,signerInfo.getArchiveTimeStampV2Time());
				} else {
					System.out.printf("��֤��%d��ǩ���ĵ�%d��ArchiveTimeStampV2����ʧ�ܡ�\n",index,i);
				}
			}catch(MessageImprintMisMatchException e) {
				System.out.printf("��%d��ǩ���ĵ�%d��ArchiveTimeStampV2ʱ�����Hashֵ������\n",index,i);
			}
		}
		
	}
	
	private static void checkAtsv3(SignedData signedDataObj,byte[] tbs,SignerInfo signerInfo,int index,Hashable hasher) throws Exception{
		ArrayList<Attribute> attrs=signerInfo.getArchiveTimeStampV3Attributes();
		int count=attrs.size();
		if(count==0){
			System.out.printf("��%d��ǩ��û��ArchiveTimeStampV3���ԡ�\n",index);
			return;
		}
		System.out.printf("��%d��ǩ����%d��ArchiveTimeStampV3���ԡ�\n",index,count);
		Attribute attr;
		for(int i=0;i<count;i++){
			attr=attrs.get(i);
				try{
				if(signerInfo.verifyArchiveTimeStampTokenV3(attr, signedDataObj, tbs)){
					System.out.printf("��֤��%d��ǩ���ĵ�%d��ArchiveTimeStampV3���Գɹ���ʱ���ʱ��:%s��\n",index,i,signerInfo.getArchiveTimeStampV3Time());
					ATSHashIndex atsIndex=signerInfo.getATSHashIndex();
					ATSHashIndexV3 atsIndexV3=signerInfo.getATSHashIndexV3();
					if(atsIndex!=null) {
						System.out.printf("��%d��ǩ���ĵ�%d��ArchiveTimeStampV3������ATSHashIndex\n",index,i);
						if(atsIndex.isIncludedIn(signedDataObj.getCertificates(),
								signedDataObj.getCrls(),signerInfo.getUnsignedAttrs(),hasher)==false){
							System.out.printf("��%d��ǩ���ĵ�%d��ArchiveTimeStampV3���Ե�ATSHashIndex���ڲ�������Hash����\n",index,i);	
						} else {
							System.out.printf("��֤��%d��ǩ���ĵ�%d��ArchiveTimeStampV3���Ե�ATSHashIndex�ɹ�\n",index,i);
						}
								
					} else {
						System.out.printf("��%d��ǩ���ĵ�%d��ArchiveTimeStampV3������ATSHashIndexV3\n",index,i);
						if(atsIndexV3.isIncludedIn(signedDataObj.getCertificates(), signedDataObj.getCrls(),
								signerInfo.getUnsignedAttrs(),hasher)==false) {
							System.out.printf("��%d��ǩ���ĵ�%d��ArchiveTimeStampV3���Ե�ATSHashIndexV3���ڲ�������Hash����\n",index,i);
						} else {
							System.out.printf("��֤��%d��ǩ���ĵ�%d��ArchiveTimeStampV3���Ե�ATSHashIndexV3�ɹ�\n",index,i);
						}
					}
					
				} else {
					System.out.printf("��֤��%d��ǩ���ĵ�%d��ArchiveTimeStampV3����ʧ�ܡ�\n",index,i);
				}
			}catch(MessageImprintMisMatchException e) {
				System.out.printf("��%d��ǩ���ĵ�%d��ArchiveTimeStampV3ʱ�����Hashֵ������\n",index,i);
			}
		}
		
	}
	
	private static void checkXLong(SignerInfo signerInfo,int index,Verifible verifier,Hashable hasher)throws Exception{
		X509Certificate signCert=signCerts[index];
		Attributes attrs=signerInfo.getUnsignedAttrs();
		if(attrs==null){
			System.out.printf("��%d��ǩ��û�в�ǩ�����ԡ�\n",index);
			return;
		}
		Attribute attr;
		CompleteCertificateRefs certRef=null;
		attr=attrs.get(Attribute.COMPLETE_CERTIFICATE_REFS);
		if(attr!=null){
			certRef=CompleteCertificateRefs.decode(attr.getValue(0).encode());
			System.out.printf("��%d��ǩ����CompleteCertificateRefs���ԡ�\n",index);
		} else {
			System.out.printf("��%d��ǩ��û��CompleteCertificateRefs���ԡ�\n",index);
		}
		
		CompleteRevocationRefs revRefs=null;
		attr=attrs.get(Attribute.COMPLETE_REVOCATION_REFS);
		if(attr!=null){
			revRefs=CompleteRevocationRefs.decode(attr.getValue(0).encode());
			System.out.printf("��%d��ǩ����CompleteRevocationRefs���ԡ�\n",index);
		} else {
			System.out.printf("��%d��ǩ��û��CompleteRevocationRefs���ԡ�\n",index);
		}
		
		
		attr=attrs.get(Attribute.CERTIFICATE_VALUES);
		CertificateValues certValues=null;
		
		if(attr!=null){
			certValues=CertificateValues.decode(attr.getValue(0).encode());
			System.out.printf("��%d��ǩ����CertificateValues���ԡ�\n",index);
		} else {
			System.out.printf("��%d��ǩ��û��CertificateValues���ԡ�\n",index);
		}
		
		attr=attrs.get(Attribute.REVOCATION_VALUES);
		RevocationValues revValues=null;
		
		if(attr!=null){
			revValues=RevocationValues.decode(attr.getValue(0).encode());
			System.out.printf("��%d��ǩ����RevocationValues���ԡ�\n",index);
		} else {
			System.out.printf("��%d��ǩ��û��RevocationValues���ԡ�\n",index);
		}
		
		boolean certMatch=false;
		if(certRef!=null && certValues!=null){
			certMatch=certValues.match(certRef, signCert,hasher);
			if(certMatch==false){
				System.out.printf("��%d��ǩ��CertificateValues���Ժ�CompleteCertificateRefs���Բ�ƥ�䡣\n",index);
			} else {
				System.out.printf("��%d��ǩ��CertificateValues���Ժ�CompleteCertificateRefs����ƥ�䡣\n",index);
			}
		}
		
		boolean revMatch=false;
		if(revRefs!=null && revValues!=null){
			revMatch=revValues.match(revRefs, hasher);
			if(revMatch==false) {
				System.out.printf("��%d��ǩ��RevocationValues���Ժ�CompleteRevocationRefs���Բ�ƥ�䡣\n",index);
			} else {
				System.out.printf("��%d��ǩ��RevocationValues���Ժ�CompleteRevocationRefs����ƥ�䡣\n",index);
			}
			
		}
		if(signCert==null){
			return;
		}
		X509Certificate[] certPath=null;
		if(certValues!=null) {
			try {
				certPath=getCertPath(verifier,signCert,certValues);
				System.out.printf("��%d��ǩ������֤�����ɹ���\n",index);
			}catch(Exception e) {
				System.out.printf("��%d��ǩ������֤����ʧ�ܡ�\n",index);
			}
		}
		if(certPath==null){
			return;
		}
		try{
			verifyCertPath(verifier,certPath,revValues);
			System.out.printf("��%d��ǩ����֤֤�����ɹ���\n",index);
		} catch(Exception e) {
			System.out.printf("��%d��ǩ����֤֤����ʧ��:%s\n",index,e.getMessage());
		}
	}
	
	private static X509Certificate[] getCertPath(Verifible verifier,X509Certificate signCert,CertificateValues certValues)throws Exception{
		X509CertificatePathBuilder builder=new X509CertificatePathBuilder();
		X509Certificate rootCert=getRootCert(verifier,certValues);
		if(rootCert==null) {
			throw new Exception("û�и�֤��");
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
			throw new Exception("û�й�������ʵ�֤����");
		}
		return certPath;
	}
	
	
	
	private static X509Certificate getRootCert(Verifible verifier,CertificateValues certValues) throws Exception{
		/* Ӧ�ô��ⲿָ����֤�� ��������������������*/
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
		//TODO ���revValues
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
			System.out.printf("��%d��ǩ��û��ESCTimeStamp���ԡ�\n",index);
			return;
		}
		System.out.printf("��%d��ǩ����ESCTimeStamp���ԡ�\n",index);
		try{
			if(signerInfo.verifyESCTimeStamp()){
				System.out.printf("��֤��%d��ǩ����ESCTimeStamp���Գɹ���ʱ���ʱ��:%s��\n",index,signerInfo.getESCTimeStampTime().toString());
			}else{
				System.out.printf("��֤��%d��ǩ����ESCTimeStampʧ�ܡ�\n",index);
			}
		}catch(MessageImprintMisMatchException e) {
			System.out.printf("��%d��ǩ����ESCTimeStampʱ�����Hashֵ������\n",index);
		}
	}
	
	private static void checkCertCRLTimestamp(SignerInfo signerInfo,int index)throws Exception{
		if(signerInfo.hasCertCRLTimeStamp()==false){
			System.out.printf("��%d��ǩ��û��CertCRLTimestamp���ԡ�\n",index);
			return;
		}
		System.out.printf("��%d��ǩ����CertCRLTimestamp���ԡ�\n",index);
		try{
			if(signerInfo.verifyCertCRLTimeStamp()){
				System.out.printf("��֤��%d��ǩ����CertCRLTimestamp���Գɹ���ʱ���ʱ��:%s��\n",index,signerInfo.getCertCRLTimeStampTime().toString());
			}else{
				System.out.printf("��֤��%d��ǩ����CertCRLTimestampʧ�ܡ�\n",index);
			}
		}catch(MessageImprintMisMatchException e) {
			System.out.printf("��%d��ǩ����CertCRLTimestampʱ�����Hashֵ������\n",index);
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
