import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Arrays;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.Hashable;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.Verifible;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.X509CertificatePathBuilder;
import net.netca.pki.encoding.asn1.pki.X509CertificatePathValidator;
import net.netca.pki.encoding.asn1.pki.cms.CertificateChoices;
import net.netca.pki.encoding.asn1.pki.cms.CertificateSet;
import net.netca.pki.encoding.asn1.pki.cms.OtherRevocationInfoFormat;
import net.netca.pki.encoding.asn1.pki.cms.RevocationInfoChoice;
import net.netca.pki.encoding.asn1.pki.cms.RevocationInfoChoices;
import net.netca.pki.encoding.asn1.pki.cms.SignedData;
import net.netca.pki.encoding.asn1.pki.ocsp.OCSPResponse;


public class CAdESVerify2 {

	public static void main(String[] args) throws Exception{
		if (args.length!=2) {
			System.out.println("Usage: java CAdESVerify2 tbsFileName signedDataFileName");
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
		for(int i=0;i<signerInfoCount;i++){
			if(signedDataObj.verify(i, tbs,verifier, hasher)==false){
				System.out.printf("验证第%d个签名失败\n",i);
			} else {
				System.out.printf("验证第%d个签名成功\n",i);
				X509Certificate cert=signedDataObj.getSignCert(i);
				CertificateSet certs=signedDataObj.getCertificates();
				RevocationInfoChoices crls=signedDataObj.getCrls();
				if(certs!=null && crls!=null) {
					X509Certificate[] certPath=getCertPath(verifier,cert,certs);
					verifyCertPath(verifier,certPath,crls);
					System.out.printf("验证第%d个签名证书成功\n",i);
				}
			}
		}
		
		
	}
	
	private static X509Certificate[] getCertPath(Verifible verifier,X509Certificate signCert,CertificateSet certs)throws Exception{
		if(certs==null){
			throw new Exception("没有证书");
		}
		X509CertificatePathBuilder builder=new X509CertificatePathBuilder();
		
		X509Certificate rootCert=getRootCert(verifier,certs);
		if(rootCert==null) {
			throw new Exception("没有根证书");
		}
		builder.addRootCert(rootCert);
		CertificateChoices cert;
		X509Certificate x509Cert;
		
		int count=certs.size();
		
		for(int i=0;i<count;i++){
			cert=certs.get(i);
			if(cert.getType()!=CertificateChoices.CERT_TYPE) {
				continue;
			}
			x509Cert=cert.getX509PublicKeyCert();
			if(x509Cert.equals(signCert)==false && x509Cert.equals(rootCert)==false){
				builder.addCACert(x509Cert);
			}
		}
		ArrayList<X509Certificate[]> list=builder.build(signCert);
		int certPathCount=list.size();
		if(certPathCount==0){
			throw new Exception("没有构造出合适的证书链");
		}
		return list.get(0);
	}
	
	private static X509Certificate getRootCert(Verifible verifier,CertificateSet certs) throws Exception{
		/* 应该从外部指定根证书 ，下面的做法是有问题的*/
		CertificateChoices cert;
		X509Certificate x509Cert;
		int count=certs.size();
		for(int i=0;i<count;i++){
			cert=certs.get(i);
			if(cert.getType()==CertificateChoices.CERT_TYPE) {
				x509Cert=cert.getX509PublicKeyCert();
				if(isSelfSign(verifier,x509Cert)){
					return x509Cert;
				}
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
	
	private static void verifyCertPath(Verifible verifier,X509Certificate[] certPath,RevocationInfoChoices crls)throws Exception{
		X509CertificatePathValidator validator=new X509CertificatePathValidator();
		int verify_level=X509CertificatePathValidator.VERIFY_LEVEL_VERIFY_CERTPATH_REVOKE;
		if(crls==null){
			throw new Exception("没有作废信息");
		}
		validator.setVerifier(verifier);
		validator.setVerifyLevel(verify_level);
		validator.setOption(X509CertificatePathValidator.VERIFY_OPTION_NOT_VERIFY_TIME);
		addRevokeData(validator,crls);
		
		validator.verify(certPath);
		//TODO 检查revValues
	}
	
	private static void addRevokeData(X509CertificatePathValidator validator,RevocationInfoChoices crls) throws PkiException {
		int count=crls.size();
		RevocationInfoChoice revInfo;
		int type;
		for(int i=0;i<count;i++){
			revInfo=crls.get(i);
			type=revInfo.getType();
			if(type==RevocationInfoChoice.CRL_TYPE)	{
				validator.addCRL(revInfo.getCRL());
			}
			else if(type==RevocationInfoChoice.OTHER_TYPE) {
				OtherRevocationInfoFormat other=revInfo.getOther();
				if(other.getOtherRevInfoFormat().equals(OtherRevocationInfoFormat.OCSP_RESPONSE)){
					validator.addOCSPResponse(OCSPResponse.decode(other.getOtherRevInfo().encode()));
				}
			}
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
