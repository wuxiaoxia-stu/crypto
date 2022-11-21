import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

import net.netca.pki.Device;
import net.netca.pki.KeyPair;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.tsp.*;
import net.netca.pki.PkiException;
import net.netca.pki.Signature;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import java.util.ArrayList;
import java.util.Date;
import net.netca.pki.Util;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.*;
import java.math.BigInteger;
import net.netca.pki.Certificate;
import net.netca.pki.SignedData;
import net.netca.pki.Hash;

public class TSAServer extends HttpServlet{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int signAlgo;
	private Certificate signCert;
	private BigInteger sn;
	private String policy;
	private int accuracy_seconds; 
	private int accuracy_millis;
	private int accuracy_micros;
	private boolean ordering;
	private boolean useTSAName;
	private Date time;
	private boolean useMs;
	private boolean useSigningCertificate;
	private int signingCertificateV2HashAlgo;
	private boolean isSm2;
	private boolean useQ7;
	private boolean usePKCS7;
	
	 
	public void init() throws ServletException {
		signCert=getCert();
		policy=getPolicy();
		sn=getSn();
		getAccuracy();
		ordering=getOrdering();
		useTSAName=getUseTSAName();
		time=getTime();
		getUseQ7();
		useSigningCertificate=getUseSigningCertificate();
		signingCertificateV2HashAlgo=getSigningCertificateV2HashAlgo();
		
		if(useSigningCertificate==false && signingCertificateV2HashAlgo<0) {
			throw new ServletException("bad SigningCertificate");
		}
	}
	
	private KeyPair getKeyPair() throws ServletException {
		String str;
		str=getInitParameter("deviceType");
		if(str==null) {
			throw new ServletException("no deviceType");
		}
		int deviceType=java.lang.Integer.parseInt(str);
		
		String deviceSn=getInitParameter("deviceSerialNumber");
		if(deviceSn==null) {
			throw new ServletException("no deviceSerialNumber");
		}
		
		str=getInitParameter("keypairType");
		if(str==null) {
			throw new ServletException("no keypairType");
		}
		int keypairType;
		if(str.equals("enc") || str.equals("encrypt")) {
			keypairType=KeyPair.ENCRYPT;
		} else if(str.equals("sign") || str.equals("signature")) {
			keypairType=KeyPair.SIGNATURE;
		} else if(str.equals("keyagreement")) {
			keypairType=KeyPair.KEYAGREEMENT;
		} else {
			throw new ServletException("bad keypairType");
		}
		
		String keypairLabel=getInitParameter("keypairLabel");
		if(keypairLabel==null) {
			throw new ServletException("no keypairLabel");
		}
		
		String pwd=getInitParameter("pwd");
		if(pwd==null) {
			throw new ServletException("no pwd");
		}
		try {
			KeyPair keypair=KeyPair.findKeyPair(deviceType, deviceSn, 
					Device.DEVICE_FLAG_NOT_CACHE_PIN|Device.DEVICE_FLAG_SILENT,
					pwd, keypairType, keypairLabel);
			if(keypair==null) {
				throw new ServletException("get keypair fail");
			}
			return keypair;
		} catch(PkiException e) {
			throw new ServletException(e);
		} 
		
	}
	
	
	
	private int getSignAlgo(KeyPair keypair) throws ServletException {
		String str;
		str=getInitParameter("signAlgo");
		if(str==null) {
			return getDefaultSignAlgo(keypair);
		}
		
		String oid=getsignatureAlgorithmOid(str);
		if(oid.equals(AlgorithmIdentifier.SHA1WithRSA_OID)) {
			return Signature.SHA1WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.SHA224WithRSA_OID)) {
			return Signature.SHA224WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.SHA256WithRSA_OID)) {
			return Signature.SHA256WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.SHA384WithRSA_OID)) {
			return Signature.SHA256WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.SHA512WithRSA_OID)) {
			return Signature.SHA512WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.SHA512_224WithRSA_OID)) {
			return Signature.SHA512_224WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.SHA512_256WithRSA_OID)) {
			return Signature.SHA512_256WITHRSA;
		} else if(oid.equals(AlgorithmIdentifier.DSAWithSHA1_OID)) {
			return Signature.DSAWITHSHA1;
		} else if(oid.equals(AlgorithmIdentifier.DSAWithSHA224_OID)) {
			return Signature.DSAWITHSHA224;
		} else if(oid.equals(AlgorithmIdentifier.DSAWithSHA256_OID)) {
			return Signature.DSAWITHSHA256;
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA1_OID)) {
			return Signature.ECDSAWITHSHA1;
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA224_OID)) {
			return Signature.ECDSAWITHSHA224;
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA256_OID)) {
			return Signature.ECDSAWITHSHA256;
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA384_OID)) {
			return Signature.ECDSAWITHSHA384;
		} else if(oid.equals(AlgorithmIdentifier.ECDSAWithSHA512_OID)) {
			return Signature.ECDSAWITHSHA512;
		} else if(oid.equals(AlgorithmIdentifier.SM3WithSM2_OID)) {
			return Signature.SM3WITHSM2;
		}
		throw new ServletException("unknown sign algo");
	}
	
	private static String getsignatureAlgorithmOid(String value) {
		if (value.equalsIgnoreCase("SHA1WithRSA") || value.equalsIgnoreCase("SHA-1WithRSA")) {
			return AlgorithmIdentifier.SHA1WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA224WithRSA")) {
			return AlgorithmIdentifier.SHA224WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA256WithRSA")) {
			return AlgorithmIdentifier.SHA256WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA384WithRSA")) {
			return AlgorithmIdentifier.SHA384WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA512WithRSA")) {
			return AlgorithmIdentifier.SHA512WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA512/224WithRSA")) {
			return AlgorithmIdentifier.SHA512_224WithRSA_OID;
		} else if (value.equalsIgnoreCase("SHA512/256WithRSA")) {
			return AlgorithmIdentifier.SHA512_256WithRSA_OID;
		} else if (value.equalsIgnoreCase("DSAWithSHA1")) {
			return AlgorithmIdentifier.DSAWithSHA1_OID;
		} else if (value.equalsIgnoreCase("DSAWithSHA224")) {
			return AlgorithmIdentifier.DSAWithSHA224_OID;
		} else if (value.equalsIgnoreCase("DSAWithSHA256")) {
			return AlgorithmIdentifier.DSAWithSHA256_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA1")) {
			return AlgorithmIdentifier.ECDSAWithSHA1_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA224")) {
			return AlgorithmIdentifier.ECDSAWithSHA224_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA256")) {
			return AlgorithmIdentifier.ECDSAWithSHA256_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA384")) {
			return AlgorithmIdentifier.ECDSAWithSHA384_OID;
		} else if (value.equalsIgnoreCase("ECDSAWithSHA512")) {
			return AlgorithmIdentifier.ECDSAWithSHA512_OID;
		} else if (value.equalsIgnoreCase("SM3WithSM2")) {
			return AlgorithmIdentifier.SM3WithSM2_OID;
		} else {
			return value;
		}
	}
	
	private static int getDefaultSignAlgo(KeyPair keypair)throws ServletException {
		int algo=keypair.getAlgorithm();
		if(algo==KeyPair.RSA) {
			return Signature.SHA256WITHRSA;
		} else if(algo==KeyPair.DSA) {
			return Signature.DSAWITHSHA1;
		} else if(algo==KeyPair.ECC) {
			int curve=keypair.getECCCurve();
			if(curve==Device.ECC_CURVE_P256) {
				return Signature.ECDSAWITHSHA256;
			} else if(curve==Device.ECC_CURVE_P384) {
				return Signature.ECDSAWITHSHA384;
			} else if(curve==Device.ECC_CURVE_P521) {
				return Signature.ECDSAWITHSHA512;
			} else if(curve==Device.ECC_CURVE_SM2) {
				return Signature.SM3WITHSM2;
			} 
		} 
		throw new ServletException("get default sign algo fail");
	}
	
	private Certificate getCert() throws ServletException {
		String str;
		str=getInitParameter("cert");
		if(str==null) {
			throw new ServletException("no sign cert");
		}
		Certificate cert=null;
		KeyPair keypair=null;
		try {
			cert=new Certificate(str);
			keypair=getKeyPair();
			cert.setKeyPair(keypair);
			signAlgo=getSignAlgo(keypair);
			isSm2=keypair.isSM2();
			return cert;
		} catch (PkiException e) {
			if(cert!=null) {
				cert.free();
			}
			throw new ServletException(e);
		} finally {
			if(keypair!=null) {
				keypair.free();
			}
		}
		
	}
	
	private String getPolicy() throws ServletException {
		String str;
		str=getInitParameter("policy");
		if(str==null) {
			throw new ServletException("no policy");
		}
		return str;
	}
	
	private BigInteger getSn()throws ServletException {
		String str;
		str=getInitParameter("sn");
		if(str==null) {
			throw new ServletException("no sn");
		}
		byte[] data;
		try {
			data = Hex.decode(str);
			return new BigInteger(1,data);
		} catch (PkiException e) {
			throw new ServletException(e);
		}
		
	}
	
	private void getAccuracy()throws ServletException {
		String str;
		str=getInitParameter("accuracy_seconds");
		if(str==null) {
			accuracy_seconds=-1;
		} else {
			accuracy_seconds=java.lang.Integer.parseInt(str);
		}
		
		str=getInitParameter("accuracy_millis");
		if(str==null) {
			accuracy_millis=-1;
		} else {
			accuracy_millis=java.lang.Integer.parseInt(str);
		}
		
		str=getInitParameter("accuracy_micros");
		if(str==null) {
			accuracy_micros=-1;
		} else {
			accuracy_micros=java.lang.Integer.parseInt(str);
		}
		
	}
	private boolean getUseSigningCertificate()throws ServletException {
		String str;
		str=getInitParameter("useSigningCertificate");
		if(str==null) {
			return true;
		} else {
			if(str.equalsIgnoreCase("true")) {
				return true;
			} else if(str.equalsIgnoreCase("false")) {
				return false;
			} else {
				throw new ServletException("bad useSigningCertificate");
			}
			
		}
	}
	private int getSigningCertificateV2HashAlgo()throws ServletException {
		String str;
		str=getInitParameter("signingCertificateV2HashAlgo");
		if(str==null) {
			return -1;
		} else {
			if(str.equals(AlgorithmIdentifier.SHA1_OID) || str.equalsIgnoreCase("SHA-1") || str.equalsIgnoreCase("SHA1")) {
				return Hash.SHA1;
			} else if(str.equals(AlgorithmIdentifier.SHA224_OID)|| str.equalsIgnoreCase("SHA-224") || str.equalsIgnoreCase("SHA224")) {
				return Hash.SHA224;
			} else if(str.equals(AlgorithmIdentifier.SHA256_OID)|| str.equalsIgnoreCase("SHA-256") || str.equalsIgnoreCase("SHA256")) {
				return Hash.SHA256;
			} else if(str.equals(AlgorithmIdentifier.SHA384_OID) || str.equalsIgnoreCase("SHA-384") || str.equalsIgnoreCase("SHA384")) {
				return Hash.SHA384;
			} else if(str.equals(AlgorithmIdentifier.SHA512_OID)|| str.equalsIgnoreCase("SHA-512") || str.equalsIgnoreCase("SHA512")) {
				return Hash.SHA512;
			} else if(str.equals(AlgorithmIdentifier.SHA512_224_OID) || str.equalsIgnoreCase("SHA-512/224")) {
				return Hash.SHA512_224;
			} else if(str.equals(AlgorithmIdentifier.SHA512_256_OID) || str.equalsIgnoreCase("SHA-512/256")) {
				return Hash.SHA512_256;
			} else if(str.equals("2.16.840.1.101.3.4.2.7") || str.equalsIgnoreCase("SHA3-224")) {
				return 0xA000;
			} else if(str.equals("2.16.840.1.101.3.4.2.8") || str.equalsIgnoreCase("SHA3-256")) {
				return 0xB000;
			} else if(str.equals("2.16.840.1.101.3.4.2.9") || str.equalsIgnoreCase("SHA3-384")) {
				return 0xC000;
			} else if(str.equals("2.16.840.1.101.3.4.2.10") || str.equalsIgnoreCase("SHA3-512")) {
				return 0xD000;
			} else if(str.equals(AlgorithmIdentifier.SM3_OID) || str.equalsIgnoreCase("SM3")) {
				return Hash.SM3;
			} else {
				throw new ServletException("bad signingCertificateV2HashAlgo");
			}
			
		}
	}
	
	
	private void getUseQ7()throws ServletException {
		String str;
		str=getInitParameter("useQ7");
		if(str==null) {
			useQ7=false;
		} else {
			if(str.equalsIgnoreCase("true")) {
				useQ7=true;
			} else if(str.equalsIgnoreCase("false")) {
				useQ7=false;
			} else {
				throw new ServletException("bad useQ7");
			}
		}
		
		str=getInitParameter("usePKCS7");
		if(str==null) {
			usePKCS7=false;
		} else {
			if(str.equalsIgnoreCase("true")) {
				usePKCS7=true;
			} else if(str.equalsIgnoreCase("false")) {
				usePKCS7=false;
			} else {
				throw new ServletException("bad usePKCS7");
			}
		}
	}
	
	private boolean getOrdering()throws ServletException {
		String str;
		str=getInitParameter("ordering");
		if(str==null) {
			return false;
		} else {
			if(str.equalsIgnoreCase("true")) {
				return true;
			} else if(str.equalsIgnoreCase("false")) {
				return false;
			} else {
				throw new ServletException("bad ordering");
			}
			
		}
	}
	
	private boolean getUseTSAName()throws ServletException {
		String str;
		str=getInitParameter("useTSAName");
		if(str==null) {
			return false;
		} else {
			if(str.equalsIgnoreCase("true")) {
				return true;
			} else if(str.equalsIgnoreCase("false")) {
				return false;
			} else {
				throw new ServletException("bad useTSAName");
			}
			
		}
	}
	
	private Date getTime()throws ServletException {
		String str;
		str=getInitParameter("useMs");
		if(str==null) {
			useMs=false;
		} else {
			if(str.equalsIgnoreCase("true")) {
				useMs=true;
			} else if(str.equalsIgnoreCase("false")) {
				useMs=false;
			} else {
				throw new ServletException("bad useMs");
			}
			
		}
		
		str=getInitParameter("time");
		if(str==null) {
			return null;
		} 
		try {
			return Util.UTCTimeDecode(str.getBytes("UTF-8"));
		} catch (Exception e) {
			return null;
		}
	}
	
	
	public void doPost(HttpServletRequest request,
            HttpServletResponse response)
            		throws ServletException, IOException {
		if("application/timestamp-query".equals(request.getContentType())==false) {
			throw new ServletException("bad req content-type");
		}
		byte[] data=getRequestData(request);
		try {
			TimeStampReq timeStampReq;
			try {
				timeStampReq=new TimeStampReq(data);
			} catch(PkiException e) {
				setErrorResponse(response,"badDataFormat");
				return;
			}
			if(checkTimeStampReq(response,timeStampReq)==false) {
				return;
			}
			byte[] respData=getTSAResponse(timeStampReq);
			response.setContentType("application/timestamp-reply");
			response.setContentLength(respData.length);
			ServletOutputStream stream=response.getOutputStream();
			stream.write(respData);
			stream.close();
		} catch(PkiException e) {
			setErrorResponse(response,"systemFailure");
		} 
			
	}
	
	private byte[] getRequestData(HttpServletRequest request)throws IOException {
		int length=request.getContentLength();
		if(length<0) {
			throw new IOException(" content-length");
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
	
	private void setErrorResponse(HttpServletResponse response,String errorCode) throws ServletException, IOException {
		BitString failInfo;
		boolean []bits;
		if(errorCode.equalsIgnoreCase("badAlg")) {
			bits=new boolean []{true}; 
		} else if(errorCode.equalsIgnoreCase("badRequest")) {
			bits=new boolean []{false,false,true};
		} else if(errorCode.equalsIgnoreCase("badDataFormat")) {
			bits=new boolean []{false,false,false,false,false,true};
		} else if(errorCode.equalsIgnoreCase("timeNotAvailable")) {
			bits=new boolean []{false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,false,true};
		} else if(errorCode.equalsIgnoreCase("unacceptedPolicy")) {
			bits=new boolean []{false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,false,false,true};
		} else if(errorCode.equalsIgnoreCase("unacceptedExtension")) {
			bits=new boolean []{false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,false,false,false,true};
		} else if(errorCode.equalsIgnoreCase("addInfoNotAvailable")) {
			bits=new boolean []{false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,false,false,false,false,true};
		} else if(errorCode.equalsIgnoreCase("systemFailure")) {
			bits=new boolean []{false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,false,false,false,false,
					false,false,true};
		} else {
			throw new ServletException("bad errorCode");
		}
		try{
			failInfo=new BitString(bits);
			PKIStatusInfo statusInfo=new PKIStatusInfo(PKIStatusInfo.REJECTION,null,failInfo);
			TimeStampResp resp=new TimeStampResp(statusInfo);
			byte[] respData=resp.derEncode();
			response.setContentType("application/timestamp-reply");
			response.setContentLength(respData.length);
			ServletOutputStream stream=response.getOutputStream();
			stream.write(respData);
			stream.close();
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private boolean checkTimeStampReq(HttpServletResponse response,TimeStampReq timeStampReq)
			throws ServletException, IOException {
		/* ²»¼ì²é°æ±¾ºÅ */
		try
		{
			String reqPolicy=timeStampReq.getReqPolicy();
			if(reqPolicy!=null && reqPolicy.equals(policy)==false) {
				setErrorResponse(response,"unacceptedPolicy");
				return false;
			}
			
			Extensions exts=timeStampReq.getExtensions();
			if(exts!=null) {
				setErrorResponse(response,"unacceptedExtension");
				return false;
			} 
			MessageImprint messageImprint=timeStampReq.getMessageImprint();
			if(checkMessageImprint(response,messageImprint)==false) {
				setErrorResponse(response,"unacceptedExtension");
				return false;
			}
			return true;
		} catch(PkiException e) {
			setErrorResponse(response,"badAlg");
			return false;
		}
	}
	
	private boolean checkMessageImprint(HttpServletResponse response,MessageImprint messageImprint)
			throws PkiException {
		AlgorithmIdentifier hashAlgorithm=messageImprint.getHashAlgorithm();
		if(hashAlgorithm.hasParam() && hashAlgorithm.hasNullParam()==false) {
			return false;
		}
		byte[] hashValue=messageImprint.getHashedMessage();
		int hashLen=getHashLength(hashAlgorithm.getOid());
		if(hashLen<0) {
			return false;
		}
		
		return hashLen==hashValue.length;
	}
	
	private int getHashLength(String oid) {
		if(oid.equals(AlgorithmIdentifier.SHA1_OID)) {
			return 20;
		} else if(oid.equals(AlgorithmIdentifier.SHA224_OID)) {
			return 28;
		} else if(oid.equals(AlgorithmIdentifier.SHA256_OID)) {
			return 32;
		} else if(oid.equals(AlgorithmIdentifier.SHA384_OID)) {
			return 48;
		} else if(oid.equals(AlgorithmIdentifier.SHA512_OID)) {
			return 64;
		} else if(oid.equals(AlgorithmIdentifier.SHA512_224_OID)) {
			return 28;
		} else if(oid.equals(AlgorithmIdentifier.SHA512_256_OID)) {
			return 32;
		} else if(oid.equals("2.16.840.1.101.3.4.2.7")) {
			return 28;
		} else if(oid.equals("2.16.840.1.101.3.4.2.8")) {
			return 32;
		} else if(oid.equals("2.16.840.1.101.3.4.2.9")) {
			return 48;
		} else if(oid.equals("2.16.840.1.101.3.4.2.10")) {
			return 64;
		} else if(oid.equals(AlgorithmIdentifier.SM3_OID)) {
			return 32;
		} else {
			return -1;
		}
	}
	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	private TSTInfo getTSTInfo(TimeStampReq req)throws PkiException {
		TSTInfoBuilder builder=new TSTInfoBuilder();
		ArrayList acceptablePolicyList=new ArrayList();
		acceptablePolicyList.add(policy);
		builder.setTimeStampReq(req,acceptablePolicyList);
		if(builder.getPolicy()==null) {
			builder.setPolicy(policy);
		}
		builder.setSerialNumber(sn);
		sn=sn.add(BigInteger.ONE);
		if(time==null) {
			builder.setTime(new Date(), useMs);
		} else {
			builder.setTime(new Date(), useMs);
		}
		
		
		if(accuracy_seconds>0 || accuracy_millis>0 || accuracy_micros>0) {
			Accuracy accuracy;
			accuracy=new Accuracy(accuracy_seconds,accuracy_millis,accuracy_micros);
			builder.setAccuracy(accuracy);
		}
		
		builder.setOrdering(ordering);
		if(useTSAName) {
			X509Certificate cert=new X509Certificate(signCert.derEncode());
			builder.setTsaCert(cert);
		}
		return builder.build();
	}
	
	private byte[] getTSAResponse(TimeStampReq req)throws PkiException {
		TSTInfo tstInfo=getTSTInfo(req);
		byte[] signedData=sign(tstInfo,req.isCertReq());
		/*
		Sequence resp=new Sequence((SequenceType)ASN1TypeManager.getInstance().get("TimeStampResp"));
		PKIStatusInfo info=new PKIStatusInfo(PKIStatusInfo.GRANTED,null,null);
		resp.add(info.getASN1Object());
		resp.add(ASN1Object.decode(signedData, ASN1TypeManager.getInstance().get("ContentInfo")));
		return resp.encode();
		*/
		TimeStampResp resp=new TimeStampResp(PKIStatusInfo.GRANTED,signedData);
		return resp.derEncode();
	}
	
	private byte[] sign(TSTInfo tstInfo,boolean includeCert)throws PkiException {
		byte[] tbs=tstInfo.derEncode();
		SignedData signedData=new SignedData(true);
		try {
			signedData.setDetached(false);
			signedData.setSignCertificate(signCert);
			signedData.setSignAlgorithm(0, signAlgo);
			signedData.setContentOid("1.2.840.113549.1.9.16.1.4");
			if(includeCert) {
				signedData.setIncludeCertOption(SignedData.INCLUDE_CERT_OPTION_SELF);
			} else {
				signedData.setIncludeCertOption(SignedData.INCLUDE_CERT_OPTION_NONE);
			}
			if(isSm2 && useQ7) {
				signedData.setSM2Q7(0);
				if(usePKCS7) {
					signedData.setUsePKCS7(true);
				}
			}
			if(useSigningCertificate) {
				signedData.setUseSigningCertificate(0,true);
			}
			
			if(signingCertificateV2HashAlgo>0) {
				signedData.setSigningCertificateV2HashAlgorithm(0, signingCertificateV2HashAlgo);
			}
			return signedData.sign(tbs);
			
		} finally {
			signedData.free();
		}
		
	}
	
	
	public void destroy() {
		if(signCert!=null) {
			signCert.free();
		}
	}
}
