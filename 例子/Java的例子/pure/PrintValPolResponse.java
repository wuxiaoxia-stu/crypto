import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Date;

import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.BitString;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.cms.*;
import net.netca.pki.encoding.asn1.pki.scvp.CertChecks;
import net.netca.pki.encoding.asn1.pki.scvp.KeyAgreePublicKey;
import net.netca.pki.encoding.asn1.pki.scvp.PKCReference;
import net.netca.pki.encoding.asn1.pki.scvp.PKCReferences;
import net.netca.pki.encoding.asn1.pki.scvp.ValPolResponse;
import net.netca.pki.encoding.asn1.pki.scvp.ValidationAlg;
import net.netca.pki.encoding.asn1.pki.scvp.ValidationPolRef;
import net.netca.pki.encoding.asn1.pki.scvp.ValidationPolicy;
import net.netca.pki.encoding.asn1.pki.scvp.WantBack;

public class PrintValPolResponse {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java PrintValPolResponse cvRespFileName");
            return;
        }
		String cvRespFileName=args[0];
		byte[] data=readFile(cvRespFileName);
		SignedData signObj=new SignedData(data);
		ValPolResponse valPolResponse=verifySignedData(signObj);
		System.out.println("Verify SignedData Success");
		printValPolResponse(valPolResponse);
	}
	private static void printValPolResponse(ValPolResponse valPolResponse)throws Exception{
		int cvResponseVersion=valPolResponse.getVpResponseVersion();
		System.out.println("cvResponseVersion:"+cvResponseVersion);
		
		int maxCVRequestVersion=valPolResponse.getMaxCVRequestVersion();
		System.out.println("maxCVRequestVersion:"+maxCVRequestVersion);
		
		int maxVPRequestVersion=valPolResponse.getMaxVPRequestVersion();
		System.out.println("maxVPRequestVersion:"+maxVPRequestVersion);
		
		byte[] serverConfigurationID=valPolResponse.getServerConfigurationID();
		System.out.println("serverConfigurationID:"+Hex.encode(true, serverConfigurationID));
		
		Date thisUpdate=valPolResponse.getThisUpdate();
		System.out.println("thisUpdate:"+thisUpdate);
		
		Date nextUpdate=valPolResponse.getNextUpdate();
		if(nextUpdate==null){
			System.out.println("no nextUpdate");
		} else {
			System.out.println("nextUpdate:"+nextUpdate);
		}
		
		CertChecks certChecks=valPolResponse.getSupportedChecks();
		int count=certChecks.size();
		System.out.println("supportedChecks:");
		for(int i=0;i<count;i++){
			System.out.println("\t"+getCertCheckName(certChecks.get(i)));
		}
		
		WantBack wantBack=valPolResponse.getSupportedWantBacks();
		count=wantBack.size();
		System.out.println("supportedWantBacks:");
		for(int i=0;i<count;i++){
			System.out.println("\t"+getWantBackName(wantBack.get(i)));
		}
		
		ArrayList<String> validationPolicies=valPolResponse.getValidationPolicies();
		count=validationPolicies.size();
		System.out.println("validationPolicies:");
		for(int i=0;i<count;i++){
			System.out.println("\t"+getValidationPolicyName(validationPolicies.get(i)));
		}
		
		ArrayList<String> validationAlgs=valPolResponse.getValidationAlgs();
		count=validationAlgs.size();
		System.out.println("validationAlgs:");
		for(int i=0;i<count;i++){
			System.out.println("\t"+getValidationAlgName(validationAlgs.get(i)));
		}
		
		ArrayList<String> authPolicies=valPolResponse.getAuthPolicies();
		count=authPolicies.size();
		System.out.println("authPolicies:");
		for(int i=0;i<count;i++){
			System.out.println("\t"+authPolicies.get(i));
		}
		
		int responseTypes=valPolResponse.getResponseTypes();
		if(responseTypes==ValPolResponse.RESPONSE_TYPES_CACHED_ONLY){
			System.out.println("responseTypes:cached-only");
		} else if(responseTypes==ValPolResponse.RESPONSE_TYPES_NON_CACHED_ONLY){
			System.out.println("responseTypes:non-cached-only");
		} else if(responseTypes==ValPolResponse.RESPONSE_TYPES_CACHED_AND_NON_CACHED){
			System.out.println("responseTypes:cached-and-non-cached");
		} else {
			System.out.println("responseTypes:unknown responseTypes("+responseTypes+")");
		}
		
		ValidationPolicy defaultPolicyValues=valPolResponse.getDefaultPolicyValues();
		System.out.println("defaultPolicyValues:");
		printValidationPolicy(defaultPolicyValues,1);
		
		BitString revocationInfoTypes=valPolResponse.getRevocationInfoTypes();
		System.out.println("revocationInfoTypes:"+getRevocationInfoTypes(revocationInfoTypes));
		
		ArrayList<AlgorithmIdentifier> signatureGeneration=valPolResponse.getSignatureGeneration();
		count=signatureGeneration.size();
		System.out.println("signatureGeneration:");
		for(int i=0;i<count;i++){
			printSignAlgorithmIdentifier(signatureGeneration.get(i),1);
		}
		
		ArrayList<AlgorithmIdentifier> signatureVerification=valPolResponse.getSignatureVerification();
		count=signatureVerification.size();
		System.out.println("signatureVerification:");
		for(int i=0;i<count;i++){
			printSignAlgorithmIdentifier(signatureVerification.get(i),1);
		}
		
		ArrayList<String> hashAlgorithms=valPolResponse.getHashAlgorithms();
		count=hashAlgorithms.size();
		System.out.println("hashAlgorithms:");
		for(int i=0;i<count;i++){
			System.out.println("\t"+getHashName(hashAlgorithms.get(i)));
		}
		
		
		ArrayList<KeyAgreePublicKey> serverPublicKeys=valPolResponse.getServerPublicKeys();
		if(serverPublicKeys==null){
			System.out.println("no serverPublicKeys");
		} else {
			count=hashAlgorithms.size();
			System.out.println("serverPublicKeys: TODO");
			//TODO
		}
		
		int clockSkew=valPolResponse.getClockSkew();
		System.out.println("clockSkew:"+clockSkew);
		
		byte[] requestNonce=valPolResponse.getRequestNonce();
		if(requestNonce==null){
			System.out.println("no requestNonce");
		} else {
			System.out.println("requestNonce:"+Hex.encode(true, requestNonce));
		}
	}
	
	private static String getHashName(String oid){
		if(oid.equals(AlgorithmIdentifier.SHA1_OID)){
			return "SHA1";
		} else if(oid.equals(AlgorithmIdentifier.SHA224_OID)){
			return "SHA224";
		} else if(oid.equals(AlgorithmIdentifier.SHA256_OID)){
			return "SHA256";
		} else if(oid.equals(AlgorithmIdentifier.SHA384_OID)){
			return "SHA384";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_OID)){
			return "SHA512";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_224_OID)){
			return "SHA512/224";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_256_OID)){
			return "SHA512/256";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_224_OID)){
			return "SHA3-224";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_256_OID)){
			return "SHA3-256";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_384_OID)){
			return "SHA3-384";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_512_OID)){
			return "SHA3-512";
		} else if(oid.equals(AlgorithmIdentifier.SM3_OID)){
			return "SM3";
		} else {
			return oid;
		}
	}
	private static String getSignAlgorithmIdentifierName(String oid){
		if(oid.equals(AlgorithmIdentifier.SHA1WithRSA_OID)){
			return "SHA1WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA224WithRSA_OID)){
			return "SHA224WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA256WithRSA_OID)){
			return "SHA256WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA384WithRSA_OID)){
			return "SHA384WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA512WithRSA_OID)){
			return "SHA512WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_224WithRSA_OID)){
			return "SHA512/224WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_256WithRSA_OID)){
			return "SHA512/256WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_224WithRSA_OID)){
			return "SHA3-224WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_256WithRSA_OID)){
			return "SHA3-256WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_384WithRSA_OID)){
			return "SHA3-384WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_512WithRSA_OID)){
			return "SHA3-512WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SM3WithSM2_OID)){
			return "SM3WithSM2";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA1_OID)){
			return "ECDSAWithSHA1";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA224_OID)){
			return "ECDSAWithSHA224";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA256_OID)){
			return "ECDSAWithSHA256";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA384_OID)){
			return "ECDSAWithSHA384";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA512_OID)){
			return "ECDSAWithSHA512";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_224_OID)){
			return "ECDSAWithSHA3_224";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_256_OID)){
			return "ECDSAWithSHA3_256";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_384_OID)){
			return "ECDSAWithSHA3_384";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_512_OID)){
			return "ECDSAWithSHA3_512";
		} else {
			return oid;
		}
	}
	
	private static void printSignAlgorithmIdentifier(AlgorithmIdentifier algo,int index)throws Exception{
		printIndex(index);
		System.out.println("algorithm:"+getSignAlgorithmIdentifierName(algo.getOid()));
		ASN1Object parameters=algo.getParam();
		if(parameters==null){
			printIndex(index);
			System.out.println("no parameters");
		} else {
			printIndex(index);
			if(algo.hasNullParam()){
				System.out.println("parameters:NULL");
			} else {
				System.out.println("parameters:"+Hex.encode(true, parameters.encode()));
			}
		}
	}
	
	
	private static String getRevocationInfoTypes(BitString revocationInfoTypes)throws Exception{
		boolean first=true;
		StringBuilder builder=new StringBuilder();
		if(revocationInfoTypes.isSet(0)){
			builder.append("fullCRLs");
			if(first){
				first=false;
			}
		}
		
		if(revocationInfoTypes.isSet(1)){
			if(first==false){
				builder.append(",");
			}
			builder.append("deltaCRLs");
			if(first){
				first=false;
			}
		}
		
		if(revocationInfoTypes.isSet(2)){
			if(first==false){
				builder.append(",");
			}
			builder.append("indirectCRLs");
			if(first){
				first=false;
			}
		}
		
		if(revocationInfoTypes.isSet(3)){
			if(first==false){
				builder.append(",");
			}
			builder.append("oCSPResponses");
			if(first){
				first=false;
			}
		}
		
		
		return builder.toString();
	}
	private static void printIndex(int index)throws Exception{
		for(int i=0;i<index;i++){
			System.out.print("\t");
		}
	}
	private static void printValidationPolicy(ValidationPolicy validationPolicy,int index)throws Exception{
		ValidationPolRef validationPolRef=validationPolicy.getValidationPolRef();
		
		printIndex(index);
		System.out.println("validationPolRef:");
		printIndex(index+1);
		System.out.println("valPolId:"+getValidationPolicyName(validationPolRef.getValPolId()));
		ASN1Object param=validationPolRef.getValPolParams();
		printIndex(index+1);
		if(param==null){
			System.out.println("no valPolParams");
		} else {
			System.out.println("valPolParams:"+Hex.encode(true, param.encode()));
		}
		
		ValidationAlg validationAlg=validationPolicy.getValidationAlg();
		if(validationAlg==null){
			printIndex(index);
			System.out.println("no validationAlg");
		} else {
			printIndex(index);
			System.out.println("validationAlg:");
			printIndex(index+1);
			System.out.println("valAlgId:"+getValidationAlgName(validationAlg.getValAlgId()));
			param=validationAlg.getParameters();
			printIndex(index+1);
			if(param==null){
				System.out.println("no parameters");
			} else {
				System.out.println("parameters:"+Hex.encode(true, param.encode()));
			}
		}
		int count;
		ArrayList<String> userPolicySet=validationPolicy.getUserPolicySet();
		if(userPolicySet==null){
			printIndex(index);
			System.out.println("no userPolicySet");
		} else {
			printIndex(index);
			System.out.println("userPolicySet:");
			count=userPolicySet.size();
			for(int i=0;i<count;i++){
				printIndex(index+1);
				System.out.println(userPolicySet.get(i));
			}
		}
		
		Boolean inhibitPolicyMapping=validationPolicy.getInhibitPolicyMapping();
		if(inhibitPolicyMapping==null){
			printIndex(index);
			System.out.println("no inhibitPolicyMapping");
		} else {
			printIndex(index);
			System.out.println("inhibitPolicyMapping:"+inhibitPolicyMapping);
		}
		
		Boolean requireExplicitPolicy=validationPolicy.getRequireExplicitPolicy();
		if(requireExplicitPolicy==null){
			printIndex(index);
			System.out.println("no requireExplicitPolicy");
		} else {
			printIndex(index);
			System.out.println("requireExplicitPolicy:"+requireExplicitPolicy);
		}
		
		Boolean inhibitAnyPolicy=validationPolicy.getInhibitAnyPolicy();
		if(inhibitAnyPolicy==null){
			printIndex(index);
			System.out.println("no inhibitAnyPolicy");
		} else {
			printIndex(index);
			System.out.println("inhibitAnyPolicy:"+inhibitAnyPolicy);
		}
		
		PKCReferences trustAnchors=validationPolicy.getTrustAnchors();
		if(trustAnchors==null){
			printIndex(index);
			System.out.println("no trustAnchors");
		} else {
			count=trustAnchors.size();
			printIndex(index);
			System.out.println("trustAnchors:");
			PKCReference trustAnchor;
			for(int i=0;i<count;i++){
				trustAnchor=trustAnchors.get(i);
				printTrustAnchor(trustAnchor,index+1);
			}
		}
		
		ArrayList<BitString> keyUsages=validationPolicy.getKeyUsages();
		if(keyUsages==null){
			printIndex(index);
			System.out.println("no keyUsages");
		} else {
			count=keyUsages.size();
			printIndex(index);
			System.out.println("keyUsages:");
			BitString keyUsage;
			for(int i=0;i<count;i++){
				keyUsage=keyUsages.get(i);
				printIndex(index+1);
				System.out.println(getKeyUsagesString(keyUsage));
			}
		}
		
		ArrayList<String> extendedKeyUsages=validationPolicy.getExtendedKeyUsages();
		if(extendedKeyUsages==null){
			printIndex(index);
			System.out.println("no extendedKeyUsages");
		} else {
			count=extendedKeyUsages.size();
			printIndex(index);
			System.out.println("extendedKeyUsages:");
			for(int i=0;i<count;i++){
				printIndex(index+1);
				System.out.println(extendedKeyUsages.get(index));
			}
		}
		
		ArrayList<String> specifiedKeyUsages=validationPolicy.getExtendedKeyUsages();
		if(specifiedKeyUsages==null){
			printIndex(index);
			System.out.println("no specifiedKeyUsages");
		} else {
			count=specifiedKeyUsages.size();
			printIndex(index);
			System.out.println("specifiedKeyUsages:");
			for(int i=0;i<count;i++){
				printIndex(index+1);
				System.out.println(specifiedKeyUsages.get(index));
			}
		}
	}
	
	private static String getKeyUsagesString(BitString keyUsage)throws Exception{
		boolean first=true;
		StringBuilder builder=new StringBuilder();
		if(keyUsage.isSet(0)){
			builder.append("digitalSignature");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(1)){
			if(first==false){
				builder.append(",");
			}
			builder.append("nonRepudiation/contentCommitment");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(2)){
			if(first==false){
				builder.append(",");
			}
			builder.append("keyEncipherment");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(3)){
			if(first==false){
				builder.append(",");
			}
			builder.append("dataEncipherment");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(4)){
			if(first==false){
				builder.append(",");
			}
			builder.append("keyAgreement");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(5)){
			if(first==false){
				builder.append(",");
			}
			builder.append("keyCertSign");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(6)){
			if(first==false){
				builder.append(",");
			}
			builder.append("cRLSign");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(7)){
			if(first==false){
				builder.append(",");
			}
			builder.append("encipherOnly");
			if(first){
				first=false;
			}
		}
		
		if(keyUsage.isSet(8)){
			if(first==false){
				builder.append(",");
			}
			builder.append("decipherOnly");
			if(first){
				first=false;
			}
		}
		
		return builder.toString();
	}
	
	private static void printTrustAnchor(PKCReference trustAnchor,int index)throws Exception{
		int type=trustAnchor.getType();
		if(type==PKCReference.CERT_TYPE){
			printIndex(index);
			System.out.println("Cert:");
			X509Certificate cert=trustAnchor.getCert();
			printIndex(index+1);
			System.out.println("Subject:"+cert.getSubject().getLdapName());
		} else{
			printIndex(index);
			System.out.println("pkcRef: TODO");
			//TODO
		}
	}
	
	private static String getValidationAlgName(String oid){
		if(oid.equals(ValidationAlg.BASIC_VAL_ALG)){
			return "id-svp-basicValAlg";
		} else {
			return oid;
		}
	}
	
	private static String getValidationPolicyName(String oid){
		if(oid.equals(ValidationPolRef.DEFAULT_VAL_POLICY)){
			return "id-svp-defaultValPolicy";
		} else {
			return oid;
		}
	}
	
	private static String getWantBackName(String oid){
		if(oid.equals(WantBack.PKC_BEST_CERT_PATH)){
			return "id-swb-pkc-best-cert-path";
		} else if(oid.equals(WantBack.PKC_REVOCATION_INFO)){
			return "id-swb-pkc-revocation-info";
		} else if(oid.equals(WantBack.PKC_PUBLIC_KEY_INFO)){
			return "id-swb-pkc-public-key-info";
		} else if(oid.equals(WantBack.AA_CERT_PATH)){
			return "id-swb-aa-cert-path";
		} else if(oid.equals(WantBack.AA_REVOCATION_INFO)){
			return "id-swb-aa-revocation-info";
		} else if(oid.equals(WantBack.AC_REVOCATION_INFO)){
			return "id-swb-ac-revocation-info";
		} else if(oid.equals(WantBack.RELAYED_RESPONSES)){
			return "id-swb-relayed-responses";
		} else if(oid.equals(WantBack.PKC_CERT)){
			return "id-swb-pkc-cert";
		} else if(oid.equals(WantBack.AC_CERT)){
			return "id-swb-ac-cert";
		} else if(oid.equals(WantBack.PKC_ALL_CERT_PATHS)){
			return "id-swb-pkc-all-cert-paths";
		} else if(oid.equals(WantBack.PKC_EE_REVOCATION_INFO)){
			return "id-swb-pkc-ee-revocation-info";
		} else if(oid.equals(WantBack.PKC_CAS_REVOCATION_INFO)){
			return "id-swb-pkc-CAs-revocation-info";
		} else {
			return oid;
		}
	}
	private static String getCertCheckName(String oid){
		if(oid.equals(CertChecks.BUILD_PKC_PATH)){
			return "id-stc-build-pkc-path";
		} else if(oid.equals(CertChecks.BUILD_VALID_PKC_PATH)){
			return "id-stc-build-valid-pkc-path";
		} else if(oid.equals(CertChecks.BUILD_STATUS_CHECKED_PKC_PATH)){
			return "id-stc-build-status-checked-pkc-path";
		} else if(oid.equals(CertChecks.BUILD_AA_PATH)){
			return "id-stc-build-aa-path";
		} else if(oid.equals(CertChecks.BUILD_VALID_AA_PATH)){
			return "id-stc-build-valid-aa-path";
		} else if(oid.equals(CertChecks.BUILD_STATUS_CHECKED_AA_PATH)){
			return "id-stc-build-status-checked-aa-path";
		} else if(oid.equals(CertChecks.STATUS_CHECK_AC_AND_BUILD_STATUS_CHECKED_AA_PATH)){
			return "id-stc-status-check-ac-and-build-status-checked-aa-path";
		} else {
			return oid;
		}
		
	}
	
	private static ValPolResponse verifySignedData(SignedData signObj)throws Exception{
		if(signObj.getSignerInfoCount()!=1){
			throw new Exception("too much signedInfo");
		}
		if(signObj.isContentInfo()==false){
			throw new Exception("not ContentInfo");
		}
		if(signObj.verify(0, new JCEVerifier(), new JCEHasher())==false){
			throw new Exception("Verify SignedData Fail");
		}
		//TODO：证书验证
		EncapsulatedContentInfo contentInfo=signObj.getEncapContentInfo();
		if(contentInfo.isEncapsulatedContentInfo()==false){
			throw new Exception("not EncapsulatedContentInfo");
		}
		if(contentInfo.getContentType().equals(ValPolResponse.OID)==false){
			throw new Exception("not ValPolResponse");
		}
		byte[] data=contentInfo.getTbs();
		return ValPolResponse.decode(data);
	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=java.lang.Integer.MAX_VALUE) {
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
}
