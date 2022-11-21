import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.ArrayList;

import net.netca.pki.Util;
import net.netca.pki.encoding.asn1.ASN1Object;
import net.netca.pki.encoding.asn1.BitString;
import net.netca.pki.encoding.asn1.SetOf;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Attribute;
import net.netca.pki.encoding.asn1.pki.GeneralName;
import net.netca.pki.encoding.asn1.pki.GeneralNames;
import net.netca.pki.encoding.asn1.pki.NetcaMyStore;
import net.netca.pki.encoding.asn1.pki.NetcaSymEncrypter;
import net.netca.pki.encoding.asn1.pki.OtherName;
import net.netca.pki.encoding.asn1.pki.X500Name;
import net.netca.pki.encoding.asn1.pki.cms.EnvelopedData;
import net.netca.pki.encoding.asn1.pmi.EncryptAttributeBuilder;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntax;
import net.netca.pki.encoding.asn1.pmi.IetfAttrSyntaxValue;
import net.netca.pki.encoding.asn1.pmi.RFC3281Clearance;
import net.netca.pki.encoding.asn1.pmi.RoleSyntax;
import net.netca.pki.encoding.asn1.pmi.SecurityCategory;
import net.netca.pki.encoding.asn1.pmi.SvceAuthInfo;
import net.netca.pki.encoding.asn1.pmi.ACClearAttrs;
import net.netca.pki.encoding.asn1.pmi.Clearance;

public class DecryptAttribute {

	public static void main(String[] args) throws Exception{
		 if(args.length!=2) {
	            System.out.println("Usage: java DecryptAttribute infile outfile");
	            return;
	        }

	        EnvelopedData env=null;
	        FileInputStream fIn=null;
	        byte [] in;
	        int len;
	        FileOutputStream fOut=null;
	        byte[]out;

	        File f;
	        NetcaMyStore store=null;
	        NetcaSymEncrypter symEncrypter=null;
	        try {
	        	
	        	f=new File(args[0]);
	            if(f.length()>java.lang.Integer.MAX_VALUE) {
	            	System.out.println("文件太大");
	                return;
	            }
	            in=new byte[(int)f.length()];
	            fIn=new FileInputStream(f);
	            len=fIn.read(in);
	            fIn.close();
	            fIn=null;
	             
	            env=new EnvelopedData(in,0,len);
	            store=NetcaMyStore.NewDeviceStore();
	            
	            env.setCertAndPrivKeys(store.iterator());
	            symEncrypter=new NetcaSymEncrypter();
	            env.setSymEncrypter(symEncrypter);
	            
	            out=env.decrypt();
	            
	            fOut=new FileOutputStream(args[1]);
	            fOut.write(out);
	                       
	            
	            System.out.println("解密成功");
	            
	            PrintEncAlgo(env.getEncryptedContentInfo().getContentEncryptionAlgorithm().getOid());

	            System.out.println("解密证书的主体: "+env.getDecryptCert().getSubject().getLdapName());
	            
	            if(env.getEncryptedContentInfo().getContentType().equals(EncryptAttributeBuilder.ATTR_CERT_ENC_ATTRS_CONTENT_TYPE)==false){
	            	System.out.println("Content—Type不匹配,不是加密属性");
	            	return;
	            }
	            
	            
	            
	            
	        } finally {
	            if(fIn!=null) {
	                fIn.close();
	            }

	            if(fOut!=null) {
	                fOut.close();
	            }
	           
	            
	            if(symEncrypter!=null) {
	            	symEncrypter.free();
	            }
	            
	            if(store!=null) {
	            	store.free();
	            }
	        }

	        ACClearAttrs clearAttrs=ACClearAttrs.decode(out);
	        
	        System.out.println("颁发者名:");
	        printGeneralName(1,clearAttrs.getACIssuer());
	        
	        byte[] sn=clearAttrs.getACSerial();
			System.out.printf("序列号:0X%s\n",Util.HexEncode(true, sn));
			
			ArrayList<Attribute> attrs=clearAttrs.getAttrs();
			System.out.printf("属性(%d个)：\n",attrs.size());
			printAttributes(1,attrs);
	}
	static void PrintEncAlgo(String algo) {
        if(algo.equals(AlgorithmIdentifier.DESCBC_OID)) {
            System.out.println("加密算法: DESCBC");
        } else if(algo.equals(AlgorithmIdentifier.RC2CBC_OID)) {
            System.out.println("加密算法: RC2CBC");
        } else if(algo.equals(AlgorithmIdentifier.DESEDE3CBC_OID)) {
            System.out.println("加密算法: TDESCBC");
        } else if(algo.equals(AlgorithmIdentifier.AES128CBCPAD_OID)) {
            System.out.println("加密算法: AES128CBC");
        } else if(algo.equals(AlgorithmIdentifier.AES192CBCPAD_OID)) {
            System.out.println("加密算法: AES192CBC");
        } else if(algo.equals(AlgorithmIdentifier.AES256CBCPAD_OID)) {
            System.out.println("加密算法: AES256CBC");
        } else if(algo.equals(AlgorithmIdentifier.SSF33CBC_OID)) {
            System.out.println("加密算法: SSF33CBC");
        } else if(algo.equals(AlgorithmIdentifier.SM1CBC_OID)) {
            System.out.println("加密算法: SM1CBC");
        } else if(algo.equals(AlgorithmIdentifier.SM4CBC_OID)) {
            System.out.println("加密算法: SM4CBC");
        } else {
            System.out.println("加密算法: 未知的加密算法("+algo+")");
        }
    }
	
	private static void printAttributes(int indentNumber,ArrayList<Attribute> attrs) throws Exception{
		for(Attribute attr:attrs){
			printAttribute(indentNumber,attr);
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
	
	private static void indent(int number)throws Exception{
		for(int i=0;i<number;i++){
			System.out.print("\t");
		}
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
}
