import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Date;
import net.netca.pki.Util;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.BitString;
import net.netca.pki.encoding.asn1.SetOf;
import net.netca.pki.encoding.asn1.pki.AccessDescription;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Attribute;
import net.netca.pki.encoding.asn1.pki.AuthorityKeyIdentifierExtension;
import net.netca.pki.encoding.asn1.pki.BasicConstraintsExtension;
import net.netca.pki.encoding.asn1.pki.CRLDistributionPointsExtension;
import net.netca.pki.encoding.asn1.pki.DistributionPoint;
import net.netca.pki.encoding.asn1.pki.DistributionPointName;
import net.netca.pki.encoding.asn1.pki.Extension;
import net.netca.pki.encoding.asn1.pki.Extensions;
import net.netca.pki.encoding.asn1.pki.GeneralName;
import net.netca.pki.encoding.asn1.pki.GeneralNames;
import net.netca.pki.encoding.asn1.pki.InfoAccessExtension;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.NamedBitStringExtension;
import net.netca.pki.encoding.asn1.pki.NullExtension;
import net.netca.pki.encoding.asn1.pki.OctetStringExtension;
import net.netca.pki.encoding.asn1.pki.OtherName;
import net.netca.pki.encoding.asn1.pki.RelativeDistinguishedName;
import net.netca.pki.encoding.asn1.pki.X500Name;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pmi.AttCertIssuer;
import net.netca.pki.encoding.asn1.pmi.AttributeCertificate;
import net.netca.pki.encoding.asn1.pmi.Clearance;
import net.netca.pki.encoding.asn1.pmi.Holder;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntax;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntaxValue;
import net.netca.pki.encoding.asn1.pmi.IssuerSerial;
import net.netca.pki.encoding.asn1.pmi.ObjectDigestInfo;
import net.netca.pki.encoding.asn1.pmi.RFC3281Clearance;
import net.netca.pki.encoding.asn1.pmi.RoleSyntax;
import net.netca.pki.encoding.asn1.pmi.SecurityCategory;
import net.netca.pki.encoding.asn1.pmi.SvceAuthInfo;
import net.netca.pki.encoding.asn1.pmi.Target;
import net.netca.pki.encoding.asn1.pmi.TargetCert;
import net.netca.pki.encoding.asn1.pmi.TargetInformationExtension;
import net.netca.pki.encoding.asn1.pmi.Targets;
import net.netca.pki.encoding.asn1.pmi.V2Form;


public class GetACInfo {
	public static void main(String[] args) throws Exception{
		if(args.length!=1 && args.length!=2) {
            System.out.println("Usage: java GetACInfo acFileName [issuerCertFileName]");
            return;
        }
		AttributeCertificate ac=getAC(args[0]);
		if(args.length==2){
			X509Certificate issuerCert=getCert(args[1]);
			checkIssuer(issuerCert);
			
			if(ac.matchIssuerName(issuerCert)==false){
				System.out.println("属性证书的颁发者名和颁发者公钥证书的主体名不匹配");
			}
			if(ac.verify(new JCEVerifier(), issuerCert.getSubjectPublicKeyInfo().getPublicKey())) {
				System.out.println("验证属性证书的签名成功");
			} else {
				System.out.println("验证属性证书的签名失败");
			}
		}
		
		int version=ac.getVersion();
		if(version==AttributeCertificate.V2){
			System.out.println("版本号：V2");
		} else {
			System.out.printf("版本号：未知版本号(%d)\n",version);
			return;
		}
		
		Holder holder=ac.getHolder();
		printHolder(0,"holder:",holder);
		
		AttCertIssuer issuer=ac.getIssuer();
		printAttCertIssuer(0,"颁发者:",issuer);
		
		byte[] sn=ac.getSerialNumber();
		System.out.printf("序列号:0X%s\n",Util.HexEncode(true, sn));
		
		Date notBefore=ac.getNotBefore();
		System.out.printf("有效期开始时间:%s\n",notBefore.toString());
		
		Date notAfter=ac.getNotAfter();
		System.out.printf("有效期结束时间:%s\n",notAfter.toString());
		
		ArrayList<Attribute> attrs=ac.getAttributes();
		System.out.printf("属性(%d个)：\n",attrs.size());
		printAttributes(1,attrs);
		
		BitString issuerUniqueID=ac.getIssuerUniqueID();
		if(issuerUniqueID!=null){
			System.out.println("issuerUniqueID:");
			printBitString(1,issuerUniqueID);
		}
		
		Extensions exts=ac.getExtensions();
		if(exts!=null){
			System.out.printf("扩展(%d个)：\n",exts.size());
			printExtensions(1,exts);
		}
		
		AlgorithmIdentifier signAlgo=ac.getSignatureAlgorithmIdentifier();
		System.out.print("签名算法:");
		printSignAlgorithm(signAlgo);
		
		byte[] signValue=ac.getSignatureValue();
		System.out.println("签名值:");
		indent(1);
		System.out.printf("%s\n",Util.HexEncode(true, signValue));
	}
	private static String getSignAlgorithmName(String oid){
		if(oid.equals(AlgorithmIdentifier.SHA1WithRSA_OID)) {
			return "SHA1WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA224WithRSA_OID)) {
			return "SHA224WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA256WithRSA_OID)) {
			return "SHA256WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA384WithRSA_OID)) {
			return "SHA384WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA512WithRSA_OID)) {
			return "SHA512WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_224WithRSA_OID)) {
			return "SHA512/224WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_256WithRSA_OID)) {
			return "SHA512/256WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_224WithRSA_OID)) {
			return "SHA3_224WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_256WithRSA_OID)) {
			return "SHA3_256WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_384WithRSA_OID)) {
			return "SHA3_384WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.SHA3_512WithRSA_OID)) {
			return "SHA3_512WithRSA";
		} else if(oid.equals(AlgorithmIdentifier.DSAWithSHA1_OID)) {
			return "DSAWithSHA1";
		} else if(oid.equals(AlgorithmIdentifier.DSAWithSHA224_OID)) {
			return "DSAWithSHA224";
		} else if(oid.equals(AlgorithmIdentifier.DSAWithSHA256_OID)) {
			return "DSAWithSHA256";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA1_OID)) {
			return "ECDSAWithSHA1";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA224_OID)) {
			return "ECDSAWithSHA224";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA256_OID)) {
			return "ECDSAWithSHA256";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA384_OID)) {
			return "ECDSAWithSHA384";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA512_OID)) {
			return "ECDSAWithSHA512";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_224_OID)) {
			return "ECDSAWithSHA3_224";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_256_OID)) {
			return "ECDSAWithSHA3_256";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_384_OID)) {
			return "ECDSAWithSHA3_384";
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA3_512_OID)) {
			return "ECDSAWithSHA3_512";
		} else if(oid.equals(AlgorithmIdentifier.SM3WithSM2_OID)) {
			return "SM3WithSM2";
		} else if(oid.equals(AlgorithmIdentifier.RSASSA_PSS_OID)) {
			return "RSA PSS";
		}
				 
		return oid;
	}
	private static void printSignAlgorithm(AlgorithmIdentifier signAlgo)throws Exception {
		String oid=signAlgo.getOid();
		String name=getSignAlgorithmName(oid);
		System.out.print(name);
		if(signAlgo.hasParam() && (signAlgo.hasNullParam()==false)){
			ASN1Object param=signAlgo.getParam();
			System.out.printf("(param:%s\n",Util.HexEncode(true, param.encode()));
		} else {
			System.out.print("\n");
		}
	}
	
	
	private static String getExtensionName(String oid){
		if(oid.equals(Extension.AUTHORITY_KEYIDENTIFIER_OID)){
			return "颁发者密钥标识符";
		} else if(oid.equals(Extension.AC_AUDITIDENTITY_OID)){
			return "Audit Identity";
		} else if(oid.equals(Extension.TARGETINFOMATION_OID)){
			return "AC Targeting";
		} else if(oid.equals(Extension.AUTHORITYINFOACCESS_OID)){
			return "Authority Information Access";
		} else if(oid.equals(Extension.CRLDISTRIBUTIONPOINTS_OID)){
			return "CRL发布点";
		} else if(oid.equals(Extension.NOREVAVAIL_OID)){
			return "No Revocation Available";
		} else if(oid.equals(Extension.AC_PROXYING_OID)){
			return "Proxying";
		}
		return oid;
	}
	private static void printAuthorityKeyIdentifierExtension(int indentNumber,AuthorityKeyIdentifierExtension akidExt) throws Exception{
		byte[] keyIdentifier=akidExt.getKeyIdentifier();
		if(keyIdentifier!=null){
			indent(indentNumber);
			System.out.printf("keyIdentifier:%s\n",Util.HexEncode(true,keyIdentifier));
		}
		GeneralNames authorityCertIssuer=akidExt.getAuthorityCertIssuer();
		if(authorityCertIssuer!=null){
			indent(indentNumber);
			System.out.println("authorityCertSerialNumber:");
			printGeneralNames(indentNumber+1,authorityCertIssuer);
		}
		byte[] sn=akidExt.getAuthorityCertSerialNumber();
		if(sn!=null){
			indent(indentNumber);
			System.out.printf("authorityCertSerialNumber:0X%s\n",Util.HexEncode(true,sn));
		}
	}
	
	private static void printTargetCert(int indentNumber,TargetCert targetCert) throws Exception{
		IssuerSerial targetCertificate=targetCert.getTargetCertificate();
		printIssuerSerial(indentNumber,"targetCertificate:",targetCertificate);
		GeneralName targetName=targetCert.getTargetName();
		if(targetName!=null){
			indent(indentNumber);
			System.out.println("targetName:");
			printGeneralName(indentNumber+1,targetName);
		}
		ObjectDigestInfo certDigestInfo=targetCert.getCertDigestInfo();
		if(certDigestInfo!=null){
			printObjectDigestInfo(indentNumber,"certDigestInfo:",certDigestInfo);
		}
	}
	
	private static void printTarget(int indentNumber,Target target) throws Exception{
		int type=target.getType();
		indent(indentNumber);
		switch(type){
		case Target.TARGETNAME_TYPE:
			GeneralName targetName=target.getTargetName();
			System.out.println("(targetName)");
			printGeneralName(indentNumber+1,targetName);
			break;
		case Target.TARGETGROUP_TYPE:
			GeneralName targetGroup=target.getTargetGroup();
			System.out.println("(targetGroup)");
			printGeneralName(indentNumber+1,targetGroup);
			break;
		case Target.TARGETCERT_TYPE:
			TargetCert targetCert=target.getTargetCert();
			System.out.println("(targetCert)");
			printTargetCert(indentNumber+1,targetCert);
			break;
		default:
			System.out.printf("%s\n",Util.HexEncode(true, target.getASN1Object().encode()));
		}
	}
	private static void printTargetInformationExtension(int indentNumber,TargetInformationExtension targetInfoExt) throws Exception{
		int targetsCount=targetInfoExt.size();
		for(int i=0;i<targetsCount;i++){
			indent(indentNumber);
			System.out.printf("targets %d:\n",i+1);
			Targets targets=targetInfoExt.getTargets(i);
			int count=targets.size();
			Target target;
			for(int j=0;j<count;j++){
				target=targets.get(j);
				printTarget(indentNumber+1,target);
			}
		}
	}
	private static String getAccessMethodName(String oid) throws Exception{
		if(oid.equals(AccessDescription.CAISSUERS_OID)){
			return "caIssuers";
		} else if(oid.equals(AccessDescription.OCSP_OID)){
			return "ocsp";
		} else if(oid.equals(AccessDescription.CAREPOSITORY_OID)){
			return "caRepository";
		} else if(oid.equals(AccessDescription.TIMESTAPING_OID)){
			return "timeStamping";
		}
		
		return oid;
		
	}
	private static void printAccessDescription(int indentNumber,AccessDescription ad) throws Exception{
		String oid=ad.getAccessMethod();
		String name=getAccessMethodName(oid);
		indent(indentNumber);
		System.out.printf("%s:\n",name);
		
		GeneralName accessLocation=ad.getAccessLocation();
		printGeneralName(indentNumber+1,accessLocation);
	}
	private static void printTargetInfoAccessExtension(int indentNumber,InfoAccessExtension ext) throws Exception{
		
		int count=ext.size();
		AccessDescription ad;
		for(int i=0;i<count;i++){
			ad=ext.get(i);
			printAccessDescription(indentNumber,ad);
		}
	}
	private static void printDistributionPointName(int indentNumber,DistributionPointName dpName) throws Exception{
		int type=dpName.getType();
		switch(type){
		case DistributionPointName.FULLNAME_TYPE:
			indent(indentNumber);
			System.out.println("(fullName)");
			GeneralNames fullName=dpName.getFullName();
			printGeneralNames(indentNumber+1,fullName);
			break;
		case DistributionPointName.NAMERELATIVETOISSUER_TYPE:
			indent(indentNumber);
			System.out.println("(nameRelativeToCRLIssuer)");
			RelativeDistinguishedName nameRelativeToCRLIssuer=dpName.getNameRelativeToCRLIssuer();
			indent(indentNumber+1);
			System.out.println(nameRelativeToCRLIssuer.getLdapName());
			break;
		default:
			indent(indentNumber);
			System.out.printf("(未知类型%d)\n",type);
			indent(indentNumber+1);
			System.out.printf("%s\n",Util.HexEncode(true, dpName.getASN1Object().encode()));
		}
	}
	
	private static void printReasonFlags(BitString reasons) throws Exception{
		boolean first=true;
		if(reasons.isSet(0)){
			System.out.print("unused");
			first=false;
		}
		
		if(reasons.isSet(1)){
			if(first){
				System.out.print("keyCompromise");
			} else {
				System.out.print(",keyCompromise");
			}
			first=false;
		}
		
		if(reasons.isSet(2)){
			if(first){
				System.out.print("cACompromise");
			} else {
				System.out.print(",cACompromise");
			}
			first=false;
		}
		
		if(reasons.isSet(3)){
			if(first){
				System.out.print("affiliationChanged");
			} else {
				System.out.print(",affiliationChanged");
			}
			first=false;
		}
		
		if(reasons.isSet(4)){
			if(first){
				System.out.print("superseded");
			} else {
				System.out.print(",superseded");
			}
			first=false;
		}
		if(reasons.isSet(5)){
			if(first){
				System.out.print("cessationOfOperation");
			} else {
				System.out.print(",cessationOfOperation");
			}
			first=false;
		}
		
		if(reasons.isSet(6)){
			if(first){
				System.out.print("certificateHold");
			} else {
				System.out.print(",certificateHold");
			}
			first=false;
		}
		
		if(reasons.isSet(7)){
			if(first){
				System.out.print("privilegeWithdrawn");
			} else {
				System.out.print(",privilegeWithdrawn");
			}
			first=false;
		}
		
		if(reasons.isSet(8)){
			if(first){
				System.out.print("aACompromise");
			} else {
				System.out.print(",aACompromise");
			}
			first=false;
		}
		System.out.print("\n");
	}
	
	private static void printDistributionPoint(int indentNumber,DistributionPoint dp) throws Exception{
		DistributionPointName distributionPoint=dp.getDistributionPoint();
		if(distributionPoint!=null){
			indent(indentNumber);
			System.out.println("distributionPoint:");
			printDistributionPointName(indentNumber+1,distributionPoint);
		}
		
		BitString reasons=dp.getReasons();
		if(reasons!=null){
			indent(indentNumber);
			System.out.println("reasons:");
			indent(indentNumber+1);
			printReasonFlags(reasons);
		}
		
		GeneralNames cRLIssuer=dp.getCRLIssuer();
		if(cRLIssuer!=null){
			indent(indentNumber);
			System.out.println("cRLIssuer:");
			printGeneralNames(indentNumber+1,cRLIssuer);
		}
	}
	
	private static void printCRLDistributionPointsExtension(int indentNumber,CRLDistributionPointsExtension ext) throws Exception{
		
		int count=ext.size();
		DistributionPoint dp;
		for(int i=0;i<count;i++){
			dp=ext.get(i);
			printDistributionPoint(indentNumber,dp);
		}
	}
	
	private static void printExtension(int indentNumber,Extension ext) throws Exception{
		String oid=ext.getOid();
		String name=getExtensionName(oid);
		boolean isCrical=ext.isCritical();
		
		indent(indentNumber);
		System.out.printf("%s:%s\n",name,isCrical?"关键":"非关键");
		if(oid.equals(Extension.AUTHORITY_KEYIDENTIFIER_OID)){
			AuthorityKeyIdentifierExtension akidExt=(AuthorityKeyIdentifierExtension)ext.getExtensionObject();
			printAuthorityKeyIdentifierExtension(indentNumber+1,akidExt);
		} else if(oid.equals(Extension.AC_AUDITIDENTITY_OID)){
			OctetStringExtension octsExt=(OctetStringExtension)ext.getExtensionObject();
			indent(indentNumber+1);
			System.out.printf("%s\n",Util.HexEncode(true, octsExt.getValue()));
		} else if(oid.equals(Extension.TARGETINFOMATION_OID)
				|| oid.equals(Extension.AC_PROXYING_OID)){
			TargetInformationExtension targetInfoExt=(TargetInformationExtension)ext.getExtensionObject();
			printTargetInformationExtension(indentNumber+1,targetInfoExt);
		} else if(oid.equals(Extension.AUTHORITYINFOACCESS_OID)){
			InfoAccessExtension aiaExt=(InfoAccessExtension)ext.getExtensionObject();
			printTargetInfoAccessExtension(indentNumber+1,aiaExt);
		} else if(oid.equals(Extension.CRLDISTRIBUTIONPOINTS_OID)){
			CRLDistributionPointsExtension crlDPExt=(CRLDistributionPointsExtension)ext.getExtensionObject();
			printCRLDistributionPointsExtension(indentNumber+1,crlDPExt);
		} else if(oid.equals(Extension.NOREVAVAIL_OID)){
			NullExtension nullExt=(NullExtension)ext.getExtensionObject();
			indent(indentNumber+1);
			nullExt.encode();
			System.out.println("NULL");
		} else {
			indent(indentNumber+1);
			System.out.printf("扩展编码：%s\n",Util.HexEncode(true,ext.getExtensionValue()));
		}
		
	}
	private static void printExtensions(int indentNumber,Extensions exts) throws Exception{
		int size=exts.size();
		Extension ext;
		for(int i=0;i<size;i++){
			ext=exts.get(i);
			printExtension(indentNumber,ext);
		}
		
	}
	
	
	private static String getAttributeName(String oid) {
		if(oid.equals(Attribute.SERVICE_AUTH_INFO)){
			return "Service Authentication Information";
		} else if(oid.equals(Attribute.ACCESS_IDENTITY)){
			return "Access Identity";
		} else if(oid.equals(Attribute.CHARGING_IDENTITY)){
			return "Charging Identity";
		} else if(oid.equals(Attribute.GROUP)){
			return "Group";
		} else if(oid.equals(Attribute.ROLE)){
			return "Role";
		} else if(oid.equals(Attribute.CLEARANCE)){
			return "Clearance";
		} else if(oid.equals(Attribute.RFC3281_CLEARANCE)){
			return "RFC3281 Clearance";
		} else if(oid.equals(Attribute.ENC_ATTRS)){
			return "Encrypt Attribute";
		} 
		return oid;
	}
	
	private static void printSvceAuthInfo(int indentNumber,SvceAuthInfo authInfo) throws Exception{
		GeneralName service=authInfo.getService();
		indent(indentNumber);
		System.out.println("service:");
		printGeneralName(indentNumber+1,service);
		
		GeneralName ident=authInfo.getIdent();
		indent(indentNumber);
		System.out.println("ident:");
		printGeneralName(indentNumber+1,ident);
		
		byte[] authInfoData=authInfo.getAuthInfo();
		if(authInfoData!=null){
			indent(indentNumber);
			System.out.printf("authInfo:%s\n",Util.HexEncode(true, authInfoData));
		}
	}
	
	private static void printIetfAttrSyntaxValue(int indentNumber,IetfAttrSyntaxValue attrValue) throws Exception{
		int type=attrValue.getType();
		indent(indentNumber);
		switch(type){
			case IetfAttrSyntaxValue.OCTETS_TYPE:
				byte[] octs=attrValue.getOctets();
				System.out.printf("(octets)%s\n",Util.HexEncode(true, octs));
				break;
			case IetfAttrSyntaxValue.OID_TYPE:
				String oid=attrValue.getOid();
				System.out.printf("(oid)%s\n",oid);
				break;
			case IetfAttrSyntaxValue.STRING_TYPE:
				String str=attrValue.getString();
				System.out.printf("(string)%s\n",str);
				break;
			default:
				System.out.printf("(未知类型%d)%s\n",type,Util.HexEncode(true, attrValue.getASN1Object().encode()));
		}
		
	}
	
	private static void printIetfAttrSyntax(int indentNumber,IetfAttrSyntax ietfAttr) throws Exception{
		GeneralNames policyAuthority=ietfAttr.getPolicyAuthority();
		if(policyAuthority!=null){
			indent(indentNumber);
			System.out.println("policyAuthority:");
			printGeneralNames(indentNumber+1,policyAuthority);
		}
		ArrayList<IetfAttrSyntaxValue> values=ietfAttr.getValues();
		indent(indentNumber);
		System.out.println("values:");
		for(IetfAttrSyntaxValue value:values){
			printIetfAttrSyntaxValue(indentNumber+1,value);
		}
		
	}
	
	private static void printRoleSyntax(int indentNumber,RoleSyntax role) throws Exception{
		GeneralNames roleAuthority=role.getRoleAuthority();
		if(roleAuthority!=null){
			indent(indentNumber);
			System.out.println("roleAuthority:");
			printGeneralNames(indentNumber+1,roleAuthority);
		}
		GeneralName roleName=role.getRoleName();
		indent(indentNumber);
		System.out.println("roleName:");
		printGeneralName(indentNumber+1,roleName);
		
	}
	private static void printClassList(BitString classList) throws Exception{
		boolean first=true;
		if(classList.isSet(0)){
			System.out.print("unmarked");
			first=false;
		}
		
		if(classList.isSet(1)){
			if(first){
				System.out.print("unclassified");
			} else {
				System.out.print(",unclassified");
			}
			first=false;
		}
		
		if(classList.isSet(2)){
			if(first){
				System.out.print("restricted");
			} else {
				System.out.print(",restricted");
			}
			first=false;
		}
		
		if(classList.isSet(3)){
			if(first){
				System.out.print("confidential");
			} else {
				System.out.print(",confidential");
			}
			first=false;
		}
		
		if(classList.isSet(4)){
			if(first){
				System.out.print("secret");
			} else {
				System.out.print(",secret");
			}
			first=false;
		}
		if(classList.isSet(5)){
			if(first){
				System.out.print("topSecret");
			} else {
				System.out.print(",topSecret");
			}
			first=false;
		}
		System.out.print("\n");
	}
	
	private static void printSecurityCategory(int indentNumber,SecurityCategory securityCategory) throws Exception{
		String type=securityCategory.getType();
		indent(indentNumber);
		System.out.printf("type:%s\n",type);
		
		ASN1Object value=securityCategory.getValue();
		indent(indentNumber);
		System.out.printf("value:%s\n",Util.HexEncode(true, value.encode()));
	}
	
	private static void printClearance(int indentNumber,Clearance clearance) throws Exception{
		String policyId=clearance.getPolicyId();
		indent(indentNumber);
		System.out.printf("policyId:%s\n",policyId);
		BitString classList=clearance.getClassList();
		indent(indentNumber);
		System.out.print("classList:");
		printClassList(classList);
		
		ArrayList<SecurityCategory> securityCategories=clearance.getSecurityCategories();
		if(securityCategories!=null){
			indent(indentNumber);
			System.out.println("securityCategories:");
			for(SecurityCategory securityCategory:securityCategories){
				printSecurityCategory(indentNumber+1,securityCategory);
			}
		}
		
	}
	
	private static void printRFC3281Clearance(int indentNumber,RFC3281Clearance clearance) throws Exception{
		String policyId=clearance.getPolicyId();
		indent(indentNumber);
		System.out.printf("policyId:%s\n",policyId);
		BitString classList=clearance.getClassList();
		indent(indentNumber);
		System.out.print("classList:");
		printClassList(classList);
		
		ArrayList<SecurityCategory> securityCategories=clearance.getSecurityCategories();
		if(securityCategories!=null){
			indent(indentNumber);
			System.out.println("securityCategories:");
			for(SecurityCategory securityCategory:securityCategories){
				printSecurityCategory(indentNumber+1,securityCategory);
			}
		}
		
	}
	
	private static void printAttribute(int indentNumber,Attribute attr) throws Exception{
		String type=attr.getType();
		String name=getAttributeName(type);
		
		indent(indentNumber);
		System.out.printf("%s:\n",name);
		
		SetOf values=attr.getValue();
		int size=values.size();
		ASN1Object obj;
		for(int i=0;i<size;i++){
			obj=values.get(i);
			indent(indentNumber+1);
			System.out.printf("值%d:\n",i+1);
			if(type.equals(Attribute.SERVICE_AUTH_INFO)
					|| type.equals(Attribute.ACCESS_IDENTITY)){
				SvceAuthInfo authInofo=SvceAuthInfo.decode(obj.encode());
				printSvceAuthInfo(indentNumber+2,authInofo);
			} else if(type.equals(Attribute.CHARGING_IDENTITY)
					|| type.equals(Attribute.GROUP)){
				IetfAttrSyntax ietfAttr=IetfAttrSyntax.decode(obj.encode());
				printIetfAttrSyntax(indentNumber+2,ietfAttr);
			} else if(type.equals(Attribute.ROLE)){
				RoleSyntax role=RoleSyntax.decode(obj.encode());
				printRoleSyntax(indentNumber+2,role);
			} else if(type.equals(Attribute.CLEARANCE)){
				Clearance clearance=Clearance.decode(obj.encode());
				printClearance(indentNumber+2,clearance);
			} else if(type.equals(Attribute.RFC3281_CLEARANCE)){
				RFC3281Clearance clearance=RFC3281Clearance.decode(obj.encode());
				printRFC3281Clearance(indentNumber+2,clearance);
			} else {
				indent(indentNumber+2);
				System.out.printf("%s:\n",Util.HexEncode(true, obj.encode()));
			}
		}
	}
	
	private static void printAttributes(int indentNumber,ArrayList<Attribute> attrs) throws Exception{
		for(Attribute attr:attrs){
			printAttribute(indentNumber,attr);
		}
	}
	
	private static void printAttCertIssuer(int indentNumber,String msg,AttCertIssuer issuer) throws Exception{
		indent(indentNumber);
		System.out.println(msg);
		int type=issuer.getType();
		if(type!=AttCertIssuer.V2FORM){
			indent(indentNumber+1);
			System.out.println("不是V2Form的颁发者不支持");
			return;
		}
		V2Form v2Form=issuer.getV2Form();
		
		GeneralNames issuerName=v2Form.getIssuerName();
		if(issuerName!=null){
			indent(indentNumber+1);
			System.out.println("issuerName:");
			printGeneralNames(indentNumber+2,issuerName);
		}
		
		IssuerSerial baseCertificateID=v2Form.getBaseCertificateID();
		if(baseCertificateID!=null){
			printIssuerSerial(indentNumber+1,"baseCertificateID:",baseCertificateID);
		}
		
		ObjectDigestInfo objectDigestInfo=v2Form.getObjectDigestInfo();
		if(objectDigestInfo!=null){
			printObjectDigestInfo(indentNumber+1,"objectDigestInfo:",objectDigestInfo);
		}
	}
	
	private static void indent(int number)throws Exception{
		for(int i=0;i<number;i++){
			System.out.print("\t");
		}
	}
	private static void printHolder(int indentNumber,String msg,Holder holder) throws Exception{
		indent(indentNumber);
		System.out.print(msg);
		System.out.print("\n");
		IssuerSerial baseCertificateID=holder.getBaseCertificateID();
		if(baseCertificateID!=null){
			printIssuerSerial(indentNumber+1,"baseCertificateID:",baseCertificateID);
		}
		
		GeneralNames entityName=holder.getEntityName();
		if(entityName!=null){
			indent(indentNumber+1);
			System.out.println("entityName:");
			printGeneralNames(indentNumber+2,entityName);
		}
		
		ObjectDigestInfo objectDigestInfo=holder.getObjectDigestInfo();
		if(objectDigestInfo!=null){
			printObjectDigestInfo(indentNumber+1,"objectDigestInfo:",objectDigestInfo);
		}
	}
	private static void printObjectDigestInfo(int indentNumber,String msg,ObjectDigestInfo objectDigestInfo) throws Exception{
		indent(indentNumber);
		System.out.println(msg);
		
		int type=objectDigestInfo.getDigestedObjectType();
		printObjectDigestInfoType(indentNumber+1,type);
		
		String otherObjectTypeID=objectDigestInfo.getOtherObjectTypeID();
		if(otherObjectTypeID!=null){
			indent(indentNumber+1);
			System.out.printf("otherObjectTypeID:%s\n",otherObjectTypeID);
		}
		
		AlgorithmIdentifier digestAlgorithm=objectDigestInfo.getDigestAlgorithm();
		indent(indentNumber+1);
		System.out.print("digestAlgorithm:");
		printHashAlgorithm(digestAlgorithm);
		
		byte[] objectDigest= objectDigestInfo.getObjectDigestValue();
		indent(indentNumber+1);
		System.out.printf("objectDigest:%s\n",Util.HexEncode(true, objectDigest));
	}
	
	private static String getHashAlgorithmName(String oid){
		if(oid.equals(AlgorithmIdentifier.SHA1_OID)){
			return "SHA-1";
		} else if(oid.equals(AlgorithmIdentifier.SHA224_OID)){
			return "SHA-224";
		} else if(oid.equals(AlgorithmIdentifier.SHA256_OID)){
			return "SHA-256";
		} else if(oid.equals(AlgorithmIdentifier.SHA384_OID)){
			return "SHA-384";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_OID)){
			return "SHA-512";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_224_OID)){
			return "SHA-512/224";
		} else if(oid.equals(AlgorithmIdentifier.SHA512_256_OID)){
			return "SHA-512/256";
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
		} else if(oid.equals(AlgorithmIdentifier.MD5_OID)){
			return "MD5";
		} else {
			return oid;
		}
	}
	
	private static void printHashAlgorithm(AlgorithmIdentifier digestAlgorithm)throws Exception {
		String oid=digestAlgorithm.getOid();
		String name=getHashAlgorithmName(oid);
		System.out.print(name);
		if(digestAlgorithm.hasParam() && (digestAlgorithm.hasNullParam()==false)){
			ASN1Object param=digestAlgorithm.getParam();
			System.out.printf("(param:%s\n",Util.HexEncode(true, param.encode()));
		} else {
			System.out.print("\n");
		}
	}
	
	private static void printObjectDigestInfoType(int indentNumber,int type) throws Exception{
		indent(indentNumber);
		switch(type){
		case ObjectDigestInfo.PUBLICKEY:
			System.out.println("digestedObjectType:publicKey");
			break;
		case ObjectDigestInfo.PUBLICKEYCERT:
			System.out.println("digestedObjectType:publicKeyCert");
			break;
		case ObjectDigestInfo.OTHEROBJECTTYPES:
			System.out.println("digestedObjectType:otherObjectTypes");
			break;
		default:
			System.out.printf("digestedObjectType:未知类型(%d)\n",type);
			break;
		}
	}
	
	private static void printIssuerSerial(int indentNumber,String msg,IssuerSerial issuerSerial) throws Exception{
		indent(indentNumber);
		System.out.println(msg);
		
		
		GeneralNames issuer=issuerSerial.getIssuer();
		indent(indentNumber+1);
		System.out.println("issuer:");
		printGeneralNames(indentNumber+2,issuer);
		
		byte[] sn=issuerSerial.getSerialNumber();
		indent(indentNumber+1);
		System.out.printf("serial:0X%s\n",Util.HexEncode(true,sn));
			
		BitString issuerUID=issuerSerial.getIssuerUID();
		if(issuerUID!=null){
			indent(indentNumber+1);
			System.out.println("issuerUID:");
			printBitString(indentNumber+2,issuerUID);
		}
	}
	
	private static void printBitString(int indentNumber,BitString bits) throws Exception{
		int unusedBits=bits.getUnusedBits();
		indent(indentNumber);
		System.out.printf("unusedBits:%d\n",unusedBits);
		indent(indentNumber);
		System.out.printf("data:%s\n",Util.HexEncode(true,bits.getValue()));
	}
	
	private static void printGeneralNames(int indentNumber,GeneralNames gns) throws Exception{
		int count=gns.size();
		GeneralName gn;
		for(int i=0;i<count;i++){
			gn=gns.get(i);
			printGeneralName(indentNumber,gn);
		}
	}
	
	private static void printGeneralName(int indentNumber,GeneralName gn) throws Exception{
		int type=gn.getType();
		switch(type){
		case GeneralName.OTHERNAME_TYPE:
			OtherName otherName=gn.getOtherName();
			printOtherName(indentNumber,otherName);
			break;
		case GeneralName.RFC822NAME_TYPE:
			String rfc822Name=gn.getRFC822Name();
			printRfc822Name(indentNumber,rfc822Name);
			break;
		case GeneralName.DNSNAME_TYPE:
			String dNSName=gn.getDNSName();
			printDNSName(indentNumber,dNSName);
			break;
		case GeneralName.X400ADDRESS_TYPE:
			printX400Address(indentNumber,gn);
			break;
		case GeneralName.DIRECTORYNAME_TYPE:
			X500Name dn=gn.getDirectoryName();
			printX500Name(indentNumber,dn);
			break;
		case GeneralName.EDIPARTYNAME_TYPE:
			printEDIPartyName(indentNumber,gn);
			break;
		case GeneralName.URI_TYPE:
			String uri=gn.getURI();
			printURI(indentNumber,uri);
			break;
		case GeneralName.IPADDRESS_TYPE:
			byte[] ip=gn.getIPAddress();
			printIP(indentNumber,ip);
			break;
		case GeneralName.REGISTEREDID_TYPE:
			String regId=gn.getRegisteredID();
			printRegisteredID(indentNumber,regId);
		default:
			printBadGeneralName(indentNumber,gn);
			break;
		}
		
	}
	
	private static void printBadGeneralName(int indentNumber,GeneralName gn) throws Exception{
		indent(indentNumber);
		System.out.printf("%s\n",Util.HexEncode(true,gn.getASN1Object().encode()));
	}
	
	private static void printRegisteredID(int indentNumber,String registeredID) throws Exception{
		indent(indentNumber);
		System.out.printf("(registeredID)%s\n",registeredID);
	}
	
	
	private static void printIP(int indentNumber,byte[] ip) throws Exception{
		indent(indentNumber);
		System.out.printf("(iPAddress)%s\n",Util.HexEncode(true,ip));
	}
	
	private static void printURI(int indentNumber,String uri) throws Exception{
		indent(indentNumber);
		System.out.printf("(uniformResourceIdentifier)%s\n",uri);
	}
	
	private static void printEDIPartyName(int indentNumber,GeneralName gn) throws Exception{
		indent(indentNumber);
		System.out.printf("(ediPartyName)%s\n",Util.HexEncode(true,gn.getASN1Object().encode()));
	}
	
	private static void printX500Name(int indentNumber,X500Name dn) throws Exception{
		indent(indentNumber);
		System.out.printf("(directoryName)%s\n",dn.getLdapName());
	}
	
	private static void printX400Address(int indentNumber,GeneralName gn) throws Exception{
		indent(indentNumber);
		System.out.printf("(x400Address)%s\n",Util.HexEncode(true,gn.getASN1Object().encode()));
	}
	private static void printDNSName(int indentNumber,String dNSName) throws Exception{
		indent(indentNumber);
		System.out.printf("(dNSName)%s\n",dNSName);
	}
	
	private static void printRfc822Name(int indentNumber,String rfc822Name) throws Exception{
		indent(indentNumber);
		System.out.printf("(rfc822Name)%s\n",rfc822Name);
	}
	
	private static void printOtherName(int indentNumber,OtherName otherName) throws Exception{
		indent(indentNumber);
		System.out.print("(otherName)\n");
		String type=otherName.getType();
		indent(indentNumber+1);
		System.out.printf("type:%s\n",type);
		
		ASN1Object value=otherName.getValue();
		indent(indentNumber+1);
		System.out.printf("value:%s\n",Util.HexEncode(true, value.encode()));
	}
	
	
	private static void checkIssuer(X509Certificate issuerCert) throws Exception{
		Extensions exts=issuerCert.getExtensions();
		if(exts==null){
			System.out.println("颁发者证书没有扩展");
			return;
		}
		Extension ku=exts.get(Extension.KEYUSAGE_OID);
		if(ku==null){
			System.out.println("颁发者证书没有密钥用法扩展");
			return;
		}
		NamedBitStringExtension kuObj=(NamedBitStringExtension)ku.getExtensionObject();
		if(kuObj.isSet(0)==false){
			System.out.println("颁发者证书的密钥用法扩展的签名位没有置位");
			return;
		}
		
		Extension bc=exts.get(Extension.BASIC_CONSTRAINTS_OID);
		if(bc!=null){
			BasicConstraintsExtension bcObj=(BasicConstraintsExtension)bc.getExtensionObject();
			if(bcObj.isCA()){
				System.out.println("颁发者证书不能是CA证书");
				return;
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
	
	private static X509Certificate getCert(String certFileName) throws Exception{
		byte[] certData=readFile(certFileName);
		return new X509Certificate(certData);
	}
	
	private static AttributeCertificate getAC(String certFileName) throws Exception{
		byte[] certData=readFile(certFileName);
		return AttributeCertificate.decode(certData);
	}
	
}
