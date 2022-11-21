import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

import net.netca.pki.CertStore;
import net.netca.pki.Certificate;
import net.netca.pki.KeyPair;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.json.jose.*;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaHash;
import net.netca.pki.encoding.json.jose.impl.netcajni.NetcaJWSSigner;

public class JWTSign2 {

	public static void main(String[] args) throws Exception{
		if(args.length==1 || args.length%2!=1) {
            System.out.println("Usage: java JWTSign2 signCert claimName1 claimValue1 ... claimNameN claimValueN");
            return;
        }
		String signCertFileName=args[0];
		X509Certificate signCert=getCert(signCertFileName);
		String algoName=getSignAlgo(signCert);
		JWTClaimsSet claimSet=new JWTClaimsSet();
		for(int i=1;i<args.length;i+=2){
			String name=args[i];
			String value=args[i+1];
			addClaim(claimSet,name,value);
		}
		NetcaJWSSigner signObj=null;
		CertStore store=new CertStore(CertStore.CURRENT_USER,CertStore.DEVICE);
		try{
			signObj=getSignObj(store,signCert);
			JWT jwt=JWTBuilder.getInstance(JWT.TYPE_JWS)
					.setClaimsSet(claimSet)
					.setHashImplement(new NetcaHash())
					.setSignCert(JWS.CERTID_TYPE_X5T_S256,algoName,signCert, signObj)
					.sign();
			System.out.println(jwt.encode());
		}finally{
			store.free();
			if(signObj!=null){
				signObj.free();
			}
		}
		
	}
	
	private static void addClaim(JWTClaimsSet claimSet,String name,String value) throws Exception{
		if(name.equals(JWTClaimsSet.ISSUER)){
			claimSet.setIssuerClaim(value);
		} else if(name.equals(JWTClaimsSet.SUBJECT)){
			claimSet.setSubjectClaim(value);
		} else if(name.equals(JWTClaimsSet.AUDIENCE)){
			claimSet.setAudienceClaim(value);
		} else if(name.equals(JWTClaimsSet.JWT_ID)){
			claimSet.setJWTIdClaim(value);
		} else if(name.equals(JWTClaimsSet.EXPIRATION_TIME)){
			claimSet.setExpirationTimeClaim(toDate(value));
		} else if(name.equals(JWTClaimsSet.NOT_BEFORE)){
			claimSet.setNotBeforeClaim(toDate(value));
		} else if(name.equals(JWTClaimsSet.ISSUED_AT)){
			claimSet.setIssuedAtClaim(toDate(value));
		} else {
			claimSet.setOtherClaim(name, value);
		}
	}
	
	private static int GetInteger(char[] data,int offset,int length) {
		int value=0;
		for(int i=0;i<length;i++)
		{
			value*=10;
			value+=(int)(data[i+offset]-(byte)'0');
		}
		return value;
	}
	
	private static Date toDate(String str)throws Exception{
		if(str.length()!=15){
			throw new Exception("bad time format");
		}
		char[] data=str.toCharArray();
		if(data[14]!='Z'){
			throw new Exception("bad time format");
		}
       
        for (int i = 0; i < 14; i++){
        	if (data[i] > '9' || data[i] < '0'){
        		throw new Exception("bad time format");
            }
        }
        
        int year=GetInteger(data,0,4);
        int month=GetInteger(data,4,2);
        int day=GetInteger(data,6,2);
        int hour=GetInteger(data,8,2);
        int minute=GetInteger(data,10,2);
        int second=GetInteger(data,12,2);
        Calendar cal = Calendar.getInstance();
        cal.setTimeZone(TimeZone.getTimeZone("UTC"));
        cal.set(year,month-1,day,hour,minute,second);
                
        return cal.getTime();
	}
	private static String getSignAlgo(X509Certificate signCert)throws Exception{
		if(signCert.isSM2()){
			return JWS.SM2_SM3;
		} else if(signCert.isRSA()){
			return JWS.RSA_SHA256;
		} else {
			throw new Exception("unsupport cert");
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
	
	private static NetcaJWSSigner getSignObj(CertStore store,X509Certificate signCert)throws Exception{
		int count=store.getCertificateCount();
		for(int i=0;i<count;i++){
			Certificate cert=store.getCertificate(i);
			if(cert!=null){
				KeyPair keypair=null;
				try{
					if(Arrays.equals(cert.derEncode(),signCert.derEncode())){
						keypair=cert.getKeyPair(0, Certificate.PURPOSE_SIGN, null);
						if(keypair!=null){
							return new NetcaJWSSigner(keypair);
						}
					}
				}finally{
					cert.free();
					if(keypair!=null){
						keypair.free();
					}
				}
			}
		}
		return null;
	}
}
