import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.ServletInputStream;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.PkiException;
import net.netca.pki.RevokeInfo;
//import net.netca.pki.RevokeInfoSource;
import net.netca.pki.encoding.asn1.pki.scvp.*;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.pki.cms.*;
import net.netca.pki.encoding.asn1.*;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.X509CertificatePathBuilder;
import net.netca.pki.encoding.asn1.pki.X509CertificatePathValidator;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Attribute;
import net.netca.pki.encoding.asn1.pki.CertStatusRevokedException;
import net.netca.pki.encoding.asn1.pki.CertStatusUndeterminedException;
import net.netca.pki.encoding.asn1.pki.CertificatePolicyException;
import net.netca.pki.encoding.asn1.pki.GeneralName;
import net.netca.pki.encoding.asn1.pki.GeneralNames;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.NetcaSigner;
import net.netca.pki.encoding.asn1.pki.NoRevokeInfoException;
import net.netca.pki.encoding.asn1.pki.PolicyInformation;
import net.netca.pki.encoding.asn1.pki.Signable;
import net.netca.pki.encoding.asn1.pki.X509CRL;
import java.lang.Boolean;

public class SCVPServer extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	private AlgorithmIdentifier signAlgo;
	private X509Certificate signCert;
	private Signable signObj;
	private byte[] serverConfigurationID;
	private String authPolicy;
	private ArrayList<X509Certificate> caCerts=new ArrayList<X509Certificate>();
	private X509Certificate rootCert;
	private ArrayList<X509CRL> crls=new ArrayList<X509CRL>();
	private ArrayList<X509CRL> eeCrls=new ArrayList<X509CRL>();
	private ArrayList<X509CRL> caCrls=new ArrayList<X509CRL>();
	
	
	private ArrayList<AlgorithmIdentifier> supportVerifyAlgos;
	private ArrayList<String> hashAlgos;
	private int clockSkew=10;
	
	
	private final int CERT_CHECK_TYPE_BUILD_PKC_PATH=1;
	private final int CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH=2;
	private final int CERT_CHECK_TYPE_BUILD_STATUS_CHECKED_PKC_PATH=3;
	
	
	private final int WANTBACK_TYPE_PKC_BEST_CERT_PATH=1;
	private final int WANTBACK_TYPE_PKC_REVOCATION_INFO=2;
	private final int WANTBACK_TYPE_PKC_ALL_CERT_PATHS=4;
	private final int WANTBACK_TYPE_PKC_EE_REVOCATION_INFO=8;
	private final int WANTBACK_TYPE_PKC_CAS_REVOCATION_INFO=16;
	
	public void init() throws ServletException {
		getAuthPolicy();
		getCertInfo();
		initSupportVerifyAlgos();
		initServerConfigurationID();
		initHashAlgos();
		getSignCert();
		getClockSkew();
		getCRLInfo();
	}
	private ArrayList<X509CRL> getCRLInfo(String fileName)throws ServletException{
		if(fileName==null) {
			return new ArrayList<X509CRL>();
		}
		try {
			fileName=getServletContext().getRealPath(fileName);
			byte[] data=readFile(fileName);
			SignedData signedData=null;
			try {
				signedData=new SignedData(data);
			} catch(Exception e) {
				X509CRL crl=new X509CRL(data);
				ArrayList<X509CRL> list=new ArrayList<X509CRL>();
				list.add(crl);
				return list;
			}
			
			RevocationInfoChoices crls=signedData.getCrls();
			ArrayList<X509CRL> list= crls.getCRLs();
			if(list==null) {
				return new ArrayList<X509CRL>();
			} else {
				return list;
			}
			
		}catch(Exception e){
			throw new ServletException(e);
		}
	}
	private void getCRLInfo()throws ServletException{
		try {
			String fileName=getInitParameter("eeCrls");
			eeCrls=getCRLInfo(fileName);
			fileName=getInitParameter("caCrls");
			caCrls=getCRLInfo(fileName);
			fileName=getInitParameter("crls");
			if(fileName!=null) {
				crls=getCRLInfo(fileName);
			} else {
				crls=new ArrayList<X509CRL>();
				for(X509CRL crl:eeCrls) {
					crls.add(crl);
				}
				for(X509CRL crl:caCrls) {
					crls.add(crl);
				}
			}
		}catch(Exception e){
			throw new ServletException(e);
		}
	}
	
	private void getClockSkew() throws ServletException {
		String str;
		str=getInitParameter("clockSkew");
		if(str==null) {
			return;
		}
		try{
			clockSkew=java.lang.Integer.parseInt(str);
		} catch(Exception e){
			throw new ServletException("bad clockSkew",e);
		}
		if(clockSkew<=0){
			throw new ServletException("bad clockSkew");
		}
	}
	
	private void initSignAlgo(String algo)throws ServletException {
		try{
			if(algo==null){
				signAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
				return;
			}
			algo=algo.toUpperCase();
			if(algo.equals("SHA256WITHRSA")
					|| algo.equals(AlgorithmIdentifier.SHA256WithRSA_OID)){
				signAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
			} else if(algo.equals("SHA512WITHRSA")
					|| algo.equals(AlgorithmIdentifier.SHA512WithRSA_OID)){
				signAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA512WithRSA_OID);
			}  else {
				throw new ServletException("bad algo");
			}
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private void getSignCert() throws ServletException {
		String str;
		str=getInitParameter("cert");
		if(str==null) {
			throw new ServletException("no sign cert");
		}
		String pwd=getInitParameter("pwd");
		if(pwd==null) {
			throw new ServletException("no pwd");
		}
		String algo=getInitParameter("signAlgo");
		initSignAlgo(algo);
				
		
		Certificate cert=null;
		KeyPair keypair=null;
		try {
			cert=new Certificate(str);
			signCert=new X509Certificate(str);
			keypair=cert.getKeyPair(Certificate.SEARCH_KEYPAIR_FLAG_DEVICE, Certificate.PURPOSE_SIGN, pwd);
			if(keypair==null){
				throw new ServletException("no keypair,or pwd error");
			}
			signObj=new NetcaSigner(keypair);
		} catch (PkiException e) {
			if(cert!=null) {
				cert.free();
			}
			throw new ServletException(e);
		} 
		
	}
	
	private void initHashAlgos()throws ServletException{
		hashAlgos=new ArrayList<String>();
		hashAlgos.add(AlgorithmIdentifier.SHA256_OID);
		hashAlgos.add(AlgorithmIdentifier.SHA512_OID);
	}
	
	private void initServerConfigurationID()throws ServletException{
		String str=getInitParameter("serverConfigurationID");
		if(str==null) {
			throw new ServletException("no serverConfigurationID");
		}
		try{
			serverConfigurationID=net.netca.pki.encoding.Hex.decode(str);
		} catch(PkiException e){
			throw new ServletException("bad serverConfigurationID,not hex",e);
		}
	}
	
	private void initSupportVerifyAlgos()throws ServletException{
		try{
			supportVerifyAlgos=new ArrayList<AlgorithmIdentifier>();
			supportVerifyAlgos.add(AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID));
			supportVerifyAlgos.add(AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA512WithRSA_OID));
			supportVerifyAlgos.add(AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID));
			supportVerifyAlgos.add(AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA512_OID));
		} catch(PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private void getAuthPolicy()throws ServletException{
		authPolicy=getInitParameter("authPolicy");
		if(authPolicy==null) {
			throw new ServletException("no authPolicy");
		}
		try{
			new net.netca.pki.encoding.asn1.ObjectIdentifier(authPolicy);
		} catch(PkiException e){
			throw new ServletException("bad authPolicy",e);
		}
	}
	
	private boolean isSelfSign(X509Certificate cert){
		try{
			if(Arrays.equals(cert.getIssuer().getASN1Object().encode(),cert.getSubject().getASN1Object().encode())==false){
				return false;
			}
			
			return cert.verifySignature(new JCEVerifier(), cert.getSubjectPublicKeyInfo().getPublicKey());
		} catch(Exception e){
			return false;
		}
	}
	private void getCertInfo()throws ServletException{
		try {
			String fileName=getInitParameter("certs");
			fileName=getServletContext().getRealPath(fileName);
			byte[] data=readFile(fileName);
			SignedData signedData=new SignedData(data);
			CertificateSet certs=signedData.getCertificates();
			if(certs==null){
				throw new Exception("no cert");
			}
			ArrayList<X509Certificate> certList=certs.getX509PublicKeyCerts();
			for(X509Certificate cert:certList){
				if(isSelfSign(cert)){
					if(rootCert!=null){
						throw new Exception("too much rootCert");
					}
					rootCert=cert;
				}else {
					caCerts.add(cert);
				}
			}
						
		}catch(Exception e){
			throw new ServletException(e);
		}
	}
	
	public void doPost(HttpServletRequest request,
            HttpServletResponse response)
            		throws ServletException, IOException {
		String reqContentType=request.getContentType();
		if("application/scvp-vp-request".equalsIgnoreCase(reqContentType)) {
			procValidationPolicy(request,response);
		} else if("application/scvp-cv-request".equalsIgnoreCase(reqContentType)) {
			procCVRequest(request,response);
		} else {
			throw new ServletException("bad req content-type:"+reqContentType);
		}
	}
	public void procCVRequest(HttpServletRequest request,
            HttpServletResponse response)
            		throws ServletException, IOException {
		try{
			byte[] data=getRequestData(request);
			CVRequest cvReq=decodeCVRequest(data);
			CVResponse cvResp=buildCVResponse(cvReq);
			byte[] respData;
			if(requireProtectResponse(cvReq)){
				respData=sign(CVResponse.OID,cvResp.getASN1Object().encode());
			} else {
				ContentInfo contentInfo=new ContentInfo(CVResponse.OID,cvResp.getASN1Object());
				respData=contentInfo.getASN1Object().encode();
			}
			response.setContentType("application/scvp-cv-response");
			response.setContentLength(respData.length);
			ServletOutputStream stream=response.getOutputStream();
			stream.write(respData);
			stream.close();
		}catch(PkiException e){
			throw new ServletException(e);
		}
	}
	
	private boolean requireProtectResponse(CVRequest cvReq) throws PkiException{
		Query query=cvReq.getQuery();
		ResponseFlags flags=query.getResponseFlags();
		if(flags==null){
			return true;
		} else {
			return flags.getProtectResponse();
		}
	}
	
	private int getCertCheckType(CertChecks checks)throws PkiException{
		int count=checks.size();
		if(count!=1){
			throw new PkiException("too much CertChecks,not support");
		}
		String oid=checks.get(0);
		if(oid.equals(CertChecks.BUILD_PKC_PATH)){
			return CERT_CHECK_TYPE_BUILD_PKC_PATH;
		} else if(oid.equals(CertChecks.BUILD_VALID_PKC_PATH)){
			return CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH;
		} else if(oid.equals(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH)){
			return CERT_CHECK_TYPE_BUILD_STATUS_CHECKED_PKC_PATH;
		} else {
			throw new PkiException("unsupported certcheck:"+oid);
		}
	}
	
	private int getWantBackType(int certcheckType,WantBack wantBack)throws PkiException{
		if(certcheckType==CERT_CHECK_TYPE_BUILD_PKC_PATH){
			if(wantBack==null){
				throw new PkiException("require wantback");
			}
		}
		int type=0;
		if(wantBack==null){
			return type;
		}
		int count=wantBack.size();
		for(int i=0;i<count;i++){
			String oid=wantBack.get(i);
			if(oid.equals(WantBack.PKC_BEST_CERT_PATH)){
				type|=WANTBACK_TYPE_PKC_BEST_CERT_PATH;
			} else if(oid.equals(WantBack.PKC_REVOCATION_INFO)){
				type|=WANTBACK_TYPE_PKC_REVOCATION_INFO;
			} else if(oid.equals(WantBack.PKC_ALL_CERT_PATHS)){
				type|=WANTBACK_TYPE_PKC_ALL_CERT_PATHS;
			} else if(oid.equals(WantBack.PKC_EE_REVOCATION_INFO)){
				type|=WANTBACK_TYPE_PKC_EE_REVOCATION_INFO;
			} else if(oid.equals(WantBack.PKC_CAS_REVOCATION_INFO)){
				type|=WANTBACK_TYPE_PKC_CAS_REVOCATION_INFO;
			} else {
				throw new PkiException("unsupported wantback"+oid);
			}
		}
		return type;
	}
	private CertReply buildCertReply(Query query,X509Certificate cert)throws PkiException{
		CertChecks checks=query.getChecks();
		WantBack wantBack=query.getWantBack();
		ValidationPolicy validationPolicy=query.getValidationPolicy();
		Date validationTime=query.getValidationTime();
		if(validationTime==null){
			validationTime=new Date();
		}
		
		//TODO 处理intermediateCerts、revInfos和queryExtensions
		
		int certcheckType=getCertCheckType(checks);
		int wantBackType=getWantBackType(certcheckType,wantBack);
		
		CertReplyBuilder builder=CertReplyBuilder.getInstance()
				.setCert(cert)
				.setReplyValTime(validationTime);
						
		
		X509CertificatePathBuilder certPathBuilder=new X509CertificatePathBuilder();
		certPathBuilder.addRootCert(rootCert);
		for(X509Certificate caCert:caCerts){
			certPathBuilder.addCACert(caCert);
		}
		ArrayList<X509Certificate[]> certPaths=certPathBuilder.build(cert);
		if(certPaths.size()==0){
			if(certcheckType==CERT_CHECK_TYPE_BUILD_PKC_PATH){
				builder.addReplyCheck(CertChecks.BUILD_PKC_PATH,1);
			} 
			else if(certcheckType==CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH)
			{
				builder.addReplyCheck(CertChecks.BUILD_VALID_PKC_PATH,1);				
			}
			else if(certcheckType==CERT_CHECK_TYPE_BUILD_STATUS_CHECKED_PKC_PATH)
			{
				builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,1);				
			}
			builder.setReplyStatus(CertReply.CERT_PATH_CONSTRUCT_FAIL)
					.addValidationError(CertReply.BVAE_NO_VALID_CERT_PATH);
			
			return builder.build();
		}
		//只管第一条证书链
		X509Certificate[] certs=certPaths.get(0);
		if(certcheckType==CERT_CHECK_TYPE_BUILD_PKC_PATH){
			builder.setReplyStatus(CertReply.SUCCESS)
				.addReplyCheck(CertChecks.BUILD_PKC_PATH,0);
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			if((wantBackType&WANTBACK_TYPE_PKC_ALL_CERT_PATHS)!=0){
				builder.addReplyWantBack(WantBack.PKC_ALL_CERT_PATHS, certPath2CertBundles(certPaths).getASN1Object().encode());
			}
			if((wantBackType&WANTBACK_TYPE_PKC_REVOCATION_INFO)!=0){
				//TODO 处理CRL，判断是否合规
				builder.addReplyWantBack(WantBack.PKC_REVOCATION_INFO, toRevInfoWantBack(crls).getASN1Object().encode());
			}
			
			if((wantBackType&WANTBACK_TYPE_PKC_EE_REVOCATION_INFO)!=0){
				//TODO 处理CRL，判断是否合规
				builder.addReplyWantBack(WantBack.PKC_EE_REVOCATION_INFO, toRevInfoWantBack(eeCrls).getASN1Object().encode());
			}
			
			if((wantBackType&WANTBACK_TYPE_PKC_CAS_REVOCATION_INFO)!=0){
				//TODO 处理CRL，判断是否合规
				builder.addReplyWantBack(WantBack.PKC_CAS_REVOCATION_INFO, toRevInfoWantBack(caCrls).getASN1Object().encode());
			}
			
			return builder.build();
		}
		if(cert.getNotBefore().after(validationTime)){
			builder.setReplyStatus(CertReply.CERT_PATH_NOT_VALID);
			if(certcheckType==CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH){
				builder.addReplyCheck(CertChecks.BUILD_VALID_PKC_PATH,1);
			} else {
				builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,1);
			}
			builder.addValidationError(CertReply.BVAE_NOT_YET_VALID);
			return builder.build();
		}
		if(cert.getNotAfter().before(validationTime)){
			builder.setReplyStatus(CertReply.CERT_PATH_NOT_VALID);
			if(certcheckType==CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH){
				builder.addReplyCheck(CertChecks.BUILD_VALID_PKC_PATH,1);
			} else {
				builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,1);
			}
			builder.addValidationError(CertReply.BVAE_EXPIRED);
			return builder.build();
		}
		
		X509CertificatePathValidator validator=newCertPathValidator(validationPolicy);
		validator.setCheckTime(validationTime);
		validator.setTimeTolerance(clockSkew*60L);
		if(certcheckType==CERT_CHECK_TYPE_BUILD_STATUS_CHECKED_PKC_PATH){
			validator.setVerifyLevel(X509CertificatePathValidator.VERIFY_LEVEL_VERIFY_CERTPATH_REVOKE);
			for(X509CRL crl:crls){
				validator.addCRL(crl);
			}
		}
		try{
			validator.verify(certs);
			//TODO 验证keyUsages、extendedKeyUsages和specifiedKeyUsages
			builder.setReplyStatus(CertReply.SUCCESS);
			if(certcheckType==CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH){
				builder.addReplyCheck(CertChecks.BUILD_VALID_PKC_PATH,0);
			} else {
				builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,0);
			}
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			if((wantBackType&WANTBACK_TYPE_PKC_REVOCATION_INFO)!=0){
				//TODO 处理CRL，判断是否合规
				builder.addReplyWantBack(WantBack.PKC_REVOCATION_INFO, toRevInfoWantBack(crls).getASN1Object().encode());
			}
			return builder.build();
		}catch(CertStatusRevokedException e) {
			RevokeInfo revInfo=validator.getRevokeInfo();
			int revStatus=CertReply.CERT_PATH_NOT_VALID;
			if(revInfo!=null) {
				if(revInfo.getReason()==RevokeInfo.CERTIFATE_HOLD) {
					revStatus=CertReply.CERT_PATH_NOT_VALID_NOW;
				}
			}
			builder.setReplyStatus(revStatus)
				.addValidationError(CertReply.BVAE_REVOKED);
			
			builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,1);
			builder.addValidationError(CertReply.BVAE_REVOKED);
			/*
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			if((wantBackType&WANTBACK_TYPE_PKC_REVOCATION_INFO)!=0){
				int index=validator.getRevokedCertIndex();
				RevokeInfoSource[] source=validator.getRevokeInfoSource(index);
				ArrayList<X509CRL> crlList=new ArrayList<X509CRL>();
				for(int i=0;i<source.length;i++){
					if(source[i].getType()==RevokeInfoSource.CRL){
						crlList.add(new X509CRL(source[i].getData()));
					}
				}
				builder.addReplyWantBack(WantBack.PKC_REVOCATION_INFO, toRevInfoWantBack(crlList).getASN1Object().encode());
			}
			*/
			return builder.build();
						
		} catch(CertificatePolicyException e1) {
			builder.setReplyStatus(CertReply.CERT_PATH_NOT_VALID)
				.addValidationError(CertReply.BVAE_INVALID_CERT_POLICY);
			if(certcheckType==CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH){
				builder.addReplyCheck(CertChecks.BUILD_VALID_PKC_PATH,0);
			} else {
				builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,1);
			}
			/*
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			*/
			return builder.build();
			
		} catch(NoRevokeInfoException e2) {
			builder.setReplyStatus(CertReply.CERT_PATH_NOT_VALID)
				.addValidationError(CertReply.BVAE_NO_VALID_CERT_PATH)
				.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,4);
			/*
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			*/
			return builder.build();
			
		} catch(CertStatusUndeterminedException e3) {
			builder.setReplyStatus(CertReply.CERT_PATH_NOT_VALID)
				.addValidationError(CertReply.BVAE_NO_VALID_CERT_PATH)
				.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,4);
			/*
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			*/
			return builder.build();
		
		} catch(PkiException e3) {
			builder.setReplyStatus(CertReply.CERT_PATH_NOT_VALID)
				.addValidationError(CertReply.BVAE_NO_VALID_CERT_PATH);
			if(certcheckType==CERT_CHECK_TYPE_BUILD_VALID_PKC_PATH){
				builder.addReplyCheck(CertChecks.BUILD_VALID_PKC_PATH,0);
			} else {
				builder.addReplyCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH,1);
			}
			/*
			if((wantBackType&WANTBACK_TYPE_PKC_BEST_CERT_PATH)!=0){
				builder.addReplyWantBack(WantBack.PKC_BEST_CERT_PATH, certPath2CertBundle(certs).getASN1Object().encode());
			}
			*/
			return builder.build();
		}
		
	}
	
	private X509CertificatePathValidator newCertPathValidator(ValidationPolicy validationPolicy) throws PkiException{
		X509CertificatePathValidator validator=new X509CertificatePathValidator();
		ArrayList<String> userPolicySet=validationPolicy.getUserPolicySet();
		if(userPolicySet!=null){
			validator.setUserInitialPolicySet(userPolicySet.toArray(new String[0]));
		}
		Boolean inhibitPolicyMapping=validationPolicy.getInhibitPolicyMapping();
		if(inhibitPolicyMapping!=null){
			validator.setInitialPolicyMappingInhibit(inhibitPolicyMapping.booleanValue());
		}
		
		Boolean requireExplicitPolicy=validationPolicy.getRequireExplicitPolicy();
		if(requireExplicitPolicy!=null){
			validator.setInitialExplicitPolicy(requireExplicitPolicy.booleanValue());
		}
		
		Boolean inhibitAnyPolicy=validationPolicy.getInhibitAnyPolicy();
		if(inhibitAnyPolicy!=null){
			validator.setInitialAnyPolicyInhibit(inhibitAnyPolicy.booleanValue());
		}
		validator.setVerifyLevel(X509CertificatePathValidator.VERIFY_LEVEL_NO_REVOKE);
		
		return validator;
	}
	private RevInfoWantBack toRevInfoWantBack(List<X509CRL>crls) throws PkiException{
		RevocationInfos infos=null;
		boolean first=true;
		RevocationInfo info;
		for(X509CRL crl:crls){
			info=RevocationInfo.NewCRL(crl);
			if(first){
				infos=new RevocationInfos(info);
				first=false;
			} else {
				infos.add(info);
			}
		}
		return new RevInfoWantBack(infos,null);
	}
	private CertBundle certPath2CertBundle(X509Certificate[] certs) throws PkiException{
		int count=certs.length;
		CertBundle certBundle=new CertBundle(certs[count-1]);
		for(int i=count-2;i>0;i--){
			certBundle.add(certs[i]);
		}
		return certBundle;
	}
	
	private CertBundles certPath2CertBundles(ArrayList<X509Certificate[]> certPath) throws PkiException{
		CertBundles certBundles=new CertBundles();
		for(X509Certificate[] certs:certPath) {
			CertBundle certBundle=certPath2CertBundle(certs);
			certBundles.add(certBundle);
		}
		return certBundles;
	}
	private ReplyObjects buildReplyObjects(CVRequest cvReq)throws PkiException{
		ReplyObjects replyObjects=null;
		boolean first=true;
		Query query=cvReq.getQuery();
		CertReferences certRefs=query.getQueriedCerts();
		PKCReferences pkcRefs=certRefs.getPkcRefs();
		PKCReference pkcRef;
		for(int i=0;i<pkcRefs.size();i++){
			pkcRef=pkcRefs.get(i);
			if(pkcRef.getType()==PKCReference.CERT_TYPE){
				X509Certificate cert=pkcRef.getCert();
				CertReply certReply=buildCertReply(query,cert);
				if(first){
					replyObjects=new ReplyObjects(certReply);
					first=false;
				} else{
					replyObjects.add(certReply);
				}
			} else {
				throw new PkiException("not cert");
			}
		}
		if(replyObjects==null){
			throw new PkiException("not replyObjects");
		}
		return replyObjects;
	}
	
	private RequestReference buildRequestReference(CVRequest cvReq)throws PkiException{
		Query query=cvReq.getQuery();
		ResponseFlags responseFlags=query.getResponseFlags();
		boolean fullRequestInResponse;
		if(responseFlags==null){
			fullRequestInResponse=false;
		} else {
			fullRequestInResponse=responseFlags.getFullRequestInResponse();
		}
		
		if(fullRequestInResponse){
			return RequestReference.NewFullRequest(cvReq);
		} else {
			String hashAlgoOid=cvReq.getHashAlg();
			AlgorithmIdentifier hashAlgo;
			if(hashAlgoOid==null){
				hashAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
			} else {
				boolean match=false;
				for(String oid:hashAlgos){
					if(oid.equals(hashAlgoOid)){
						match=true;
						break;
					}
				}
				if(match==false){
					hashAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
				} else {
					hashAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifier(hashAlgoOid);
				}
			}
			return RequestReference.NewRequestHash(hashAlgo, cvReq, new JCEHasher());
		}
	}
	private ValidationPolicy buildRespValidationPolicy(CVRequest cvReq)throws PkiException{
		Query query=cvReq.getQuery();
		ResponseFlags responseFlags=query.getResponseFlags();
		boolean responseValidationPolByRef;
		if(responseFlags==null){
			responseValidationPolByRef=true;
		} else {
			responseValidationPolByRef=responseFlags.getResponseValidationPolByRef();
		}
		
		ValidationPolicy valPol=query.getValidationPolicy();
		ValidationPolicyBuilder builder=ValidationPolicyBuilder.getInstance();
		if(valPol.getValidationPolRef().getValPolId().equals(ValidationPolRef.DEFAULT_VAL_POLICY)==false){
			throw new PkiException("not id-svp-defaultValPolicy");
		}
		builder.setValidationPolRef(ValidationPolRef.newDefaultValPolicy());
		ValidationAlg validationAlg=valPol.getValidationAlg();
		if(validationAlg==null){
			if(responseValidationPolByRef){
				builder.setValidationAlg(new ValidationAlg(ValidationAlg.BASIC_VAL_ALG,null));
			}
		} else {
			if(validationAlg.getValAlgId().equals(ValidationAlg.BASIC_VAL_ALG)==false){
				throw new PkiException("not id-svp-basicValAlg");
			}
		}
		
		ArrayList<String> userPolicySet=valPol.getUserPolicySet();
		if(userPolicySet==null){
			if(responseValidationPolByRef){
				builder.addUserPolicy(PolicyInformation.ANYPOLICY_OID);
			}
		} else {
			for(String policy:userPolicySet){
				builder.addUserPolicy(policy);
			}
		}
		
		Boolean inhibitPolicyMapping=valPol.getInhibitPolicyMapping();
		if(inhibitPolicyMapping==null){
			if(responseValidationPolByRef){
				builder.setInhibitPolicyMapping(false);
			}
		} else {
			builder.setInhibitPolicyMapping(inhibitPolicyMapping.booleanValue());
		}
		
		Boolean requireExplicitPolicy=valPol.getRequireExplicitPolicy();
		if(requireExplicitPolicy==null){
			if(responseValidationPolByRef){
				builder.setRequireExplicitPolicy(false);
			}
		} else {
			builder.setRequireExplicitPolicy(requireExplicitPolicy.booleanValue());
		}
		
		
		Boolean inhibitAnyPolicy=valPol.getInhibitAnyPolicy();
		if(inhibitAnyPolicy==null){
			if(responseValidationPolByRef){
				builder.setInhibitAnyPolicy(false);
			}
		} else {
			builder.setInhibitAnyPolicy(inhibitAnyPolicy.booleanValue());
		}
		
		PKCReferences trustAnchors=valPol.getTrustAnchors();
		if(trustAnchors==null){
			builder.addTrustAnchor(PKCReference.NewCert(rootCert));
		} else {
			boolean match=false;
			for(int i=0;i<trustAnchors.size();i++){
				PKCReference trustAnchor=trustAnchors.get(i);
				if(trustAnchor.match(rootCert, new JCEHasher())) {
					if(match==false){
						builder.addTrustAnchor(trustAnchor);
					}
					match=true;
				}
			}
			if(match==false){
				throw new PkiException("unsupport trustAnchor");
			}
		}
		ArrayList<BitString> keyUsages=valPol.getKeyUsages();
		if(keyUsages!=null){
			for(BitString keyUsage:keyUsages){
				builder.addKeyUsage(keyUsage);
			}
		}
		
		ArrayList<String> extendedKeyUsages=valPol.getExtendedKeyUsages();
		if(extendedKeyUsages!=null){
			for(String extendedKeyUsage:extendedKeyUsages){
				builder.addExtendedKeyUsage(extendedKeyUsage);
			}
		}
		
		ArrayList<String> specifiedKeyUsages=valPol.getSpecifiedKeyUsages();
		if(specifiedKeyUsages!=null){
			for(String specifiedKeyUsage:specifiedKeyUsages){
				builder.addSpecifiedKeyUsage(specifiedKeyUsage);
			}
		}
		return builder.build();
	}
	
	private CVResponse buildCVResponse(CVRequest cvReq)throws PkiException, ServletException{
		
		if(cvReq.getCvRequestVersion()!=1){
			throw new ServletException("bad version");
		}
		if(hasAC(cvReq)){
			throw new ServletException("has ac");
		}
		
		CVResponseBuilder builder=CVResponseBuilder.getInstance()
				.setCvResponseVersion(1)
				.setServerConfigurationID(serverConfigurationID)
				.setProducedAt(new Date())
				.setResponseStatus(ResponseStatus.OKAY,null);//TODO 处理其他的错误状态
		
		ValidationPolicy valPol=buildRespValidationPolicy(cvReq);
		builder.setRespValidationPolicy(valPol);
		
		RequestReference requestRef=buildRequestReference(cvReq);
		builder.setRequestRef(requestRef);
		
		GeneralNames requestorRef=cvReq.getRequestorRef();
		if(requestorRef!=null){
			builder.setRequestorRef(requestorRef);
		}
		
		GeneralName requestorName=cvReq.getRequestorName();
		if(requestorName!=null){
			builder.setRequestorName(requestorName);
		}
		
		builder.setReplyObjects(buildReplyObjects(cvReq));
		byte[] nonce=cvReq.getRequestNonce();
		if(nonce!=null){
			builder.setRespNonce(nonce);
		}
		String requestorText=cvReq.getRequestorText();
		if(requestorText!=null){
			builder.setRequestorText(requestorText);
		}
		return builder.build();
	}
	private boolean hasAC(CVRequest cvReq) throws PkiException{
		Query query=cvReq.getQuery();
		CertReferences queriedCerts=query.getQueriedCerts();
		return queriedCerts.getType()==CertReferences.ACREFS_TYPE;
	}
	
	private CVRequest decodeCVRequest(byte[] data)throws ServletException,PkiException{
		ContentInfo contentInfo=ContentInfo.decode(data);
		String contentType=contentInfo.getContentType();
		if(contentType.equals(SignedData.OID)){
			SignedData signObj=new SignedData(data);
			if(signObj.getSignerInfoCount()!=1){
				throw new ServletException("too much signedInfo");
			}
			if(signObj.verify(0, new JCEVerifier(), new JCEHasher())==false){
				throw new ServletException("Verify SignedData Fail");
			}
			//TODO：证书验证
			EncapsulatedContentInfo econtentInfo=signObj.getEncapContentInfo();
			if(econtentInfo.isEncapsulatedContentInfo()==false){
				throw new ServletException("not EncapsulatedContentInfo");
			}
			if(econtentInfo.getContentType().equals(CVRequest.OID)==false){
				throw new ServletException("not CVRequest");
			}
			data=econtentInfo.getTbs();
			return CVRequest.decode(data);
		} else if(contentType.equals(CVRequest.OID)){
			ASN1Object content=contentInfo.getContent();
			if(content==null){
				throw new PkiException("no content");
			}
			return new CVRequest((Sequence)(content.to(CVRequest.getASN1Type())));
		} else {
			throw new ServletException("unsupport content type");
		}
	}
	public void procValidationPolicy(HttpServletRequest request,
            HttpServletResponse response)
            		throws ServletException, IOException {
		byte[] data=getRequestData(request);
		try{
			ValPolRequest valPolReq=decodeValPolRequest(data);
			if(valPolReq.getVpRequestVersion()!=1){
				throw new PkiException("bad version");
			}
			byte[] nonce=valPolReq.getRequestNonce();
			ValPolResponse valPolResp=buildValPolResponse(nonce);
			byte[] respData=sign(ValPolResponse.OID,valPolResp.getASN1Object().encode());
			response.setContentType("application/scvp-vp-response");
			response.setContentLength(respData.length);
			ServletOutputStream stream=response.getOutputStream();
			stream.write(respData);
			stream.close();
			
		} catch(PkiException e){
			throw new ServletException(e);
		}
	}
	
	private ValidationPolicy buildDefaultValidationPolicy()throws PkiException{
		return ValidationPolicyBuilder.getInstance()
				.setValidationPolRef(ValidationPolRef.newDefaultValPolicy())
				.setValidationAlg(new ValidationAlg(ValidationAlg.BASIC_VAL_ALG,null))
				.addUserPolicy(PolicyInformation.ANYPOLICY_OID)
				.setInhibitPolicyMapping(false)
				.setRequireExplicitPolicy(false)
				.setInhibitAnyPolicy(false)
				.addTrustAnchor(PKCReference.NewCert(rootCert))
				.build();
	}
	private boolean hasRevokeInfo() {
		if(crls==null || crls.isEmpty()){
			return false;
		}
		return true;
	}
	
	private void addVerifyAlgos(ValPolResponseBuilder builder)throws PkiException{
		for(AlgorithmIdentifier algo: supportVerifyAlgos){
			builder.addSignatureVerificationAlgo(algo);
		}
		
	}
	private void addHashAlgos(ValPolResponseBuilder builder)throws PkiException{
		for(String algo: hashAlgos){
			builder.addHashAlgorithm(algo);
		}
		
	}
	private ValPolResponse buildValPolResponse(byte[] nonce)throws PkiException{
		
		ValPolResponseBuilder builder=		
				ValPolResponseBuilder.getInstance()
				.setVpResponseVersion(1)
				.setMaxCVRequestVersion(1)
				.setMaxVPRequestVersion(1)
				.setServerConfigurationID(serverConfigurationID)
				.setThisUpdate(new Date())
				.addSupportedCheck(CertChecks.BUILD_PKC_PATH)
				.addSupportedCheck(CertChecks.BUILD_VALID_PKC_PATH)
				.addSupportedWantBack(WantBack.PKC_BEST_CERT_PATH)
				.addValidationPolicy(ValidationPolRef.DEFAULT_VAL_POLICY)
				.addValidationAlg(ValidationAlg.BASIC_VAL_ALG)
				.addAuthPolicy(authPolicy)
				.setResponseTypes(ValPolResponse.RESPONSE_TYPES_NON_CACHED_ONLY)
				.setDefaultPolicyValues(buildDefaultValidationPolicy())
				.addSignatureGenerationAlgo(signAlgo)
				.setClockSkew(clockSkew)
				.setRequestNonce(nonce)
				;
		addVerifyAlgos(builder);
		addHashAlgos(builder);
		if(hasRevokeInfo()){
			builder.addSupportedCheck(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH)
			.addSupportedWantBack(WantBack.PKC_REVOCATION_INFO)
			//暂不检查CRL的类型
			.setRevocationInfoTypes(new BitString(new boolean[]{true,false,false,false}));
		} else {
			builder
			.setRevocationInfoTypes(new BitString(new boolean[]{false,false,false,false}));
		}
		return builder.build();
	}
	
	private ValPolRequest decodeValPolRequest(byte[] data) throws PkiException{
		ContentInfo contentInfo=ContentInfo.decode(data);
		if(contentInfo.getContentType().equals(ValPolRequest.OID)==false){
			throw new PkiException("bad content type");
		}
		ASN1Object content=contentInfo.getContent();
		if(content==null){
			throw new PkiException("no content");
		}
		return new ValPolRequest((Sequence)(content.to(ValPolRequest.getASN1Type())));
	}
	
	private byte[] getRequestData(HttpServletRequest request)throws IOException {
		int length=request.getContentLength();
		if(length<0) {
			throw new IOException("no content-length");
		}
		byte[] data=new byte[length];
		ServletInputStream  stream=request.getInputStream();
		try{
			int readLen;
			int pos=0;
			int remLen;
			while(pos<length) {
				remLen=length-pos;
				readLen=stream.read(data,pos,remLen);
				if(readLen<=0) {
					throw new IOException("read fail");
				}
				pos+=readLen;
			}
			return data;
		} finally {
			stream.close();
		}
	}
	private static byte[] readFile(String fileName) throws IOException{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
			throw new IOException("file too big");
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new IOException("read file fail");
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private byte[] sign(String contentType,byte[] tbs)throws  PkiException{
		SignedDataBuilder builder=new SignedDataBuilder();
		builder.setContentType(contentType);
		builder.setContent(tbs);
		Signer signer=new Signer(signCert,signObj);
		signer.setSignatureAlgorithm(signAlgo);
        ESSCertID essCertID=new ESSCertID(signCert,new JCEHasher(),true);
        ArrayList<ESSCertID> essCertIDList=new ArrayList<ESSCertID>();
        essCertIDList.add(essCertID);
        SigningCertificate signingCert=new SigningCertificate(essCertIDList,null);
        Attribute attr=new Attribute(Attribute.SIGNING_CERTIFICATE,signingCert.getASN1Object());
        signer.addSignedAttribute(attr);
		builder.addSigner(signer);
		builder.setHasher(new JCEHasher());
		SignedData signedData=builder.sign();
		return signedData.encode(true);
	}
}
