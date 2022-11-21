import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

import net.netca.pki.Device;
import net.netca.pki.KeyPair;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.ocsp.*;
import net.netca.pki.PkiException;
import java.util.Date;
import net.netca.pki.Util;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.*;

public class OCSPServer extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private Date producedAt;
	private ResponderID responderID;
	private AlgorithmIdentifier signAlgo;
	private NetcaSigner signer;
	private X509Certificate signCert;
	private Date thisUpdate;
	private Date nextUpdate;
	private boolean useCRLTime;
	private X509CRL crl;
	private X509Certificate issuerCert;
	private boolean useNonce;
	private byte[] nonce;
	private boolean defaultGood;
	
	public void init() throws ServletException {
		producedAt=getProducedAt();
		signer=getSignable();
		signCert=getCert();
		thisUpdate=getThisUpdate();
		nextUpdate=getNextUpdate();
		crl=getCRL();
		issuerCert=getIssuerCert();
		responderID=getResponderID();
		nonce=getNonce();
		defaultGood=getDefaultGood();
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
	
	private NetcaSigner getSignable() throws ServletException {
		KeyPair keypair=getKeyPair();
		try{
			signAlgo=getSignAlgo(keypair);
			return new NetcaSigner(keypair);
		} catch(PkiException e) {
			throw new ServletException(e);
		} finally {
			keypair.free(); 
		}
	}
	
	private AlgorithmIdentifier getSignAlgo(KeyPair keypair) throws ServletException {
		String str;
		str=getInitParameter("signAlgo");
		if(str==null) {
			return getDefaultSignAlgo(keypair);
		}
		
		try {
			String oid=getsignatureAlgorithmOid(str);
			str=getInitParameter("signAlgoParam");
			if(str==null) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifier(oid);
			}
			if(str.equalsIgnoreCase("null")) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(oid);
			} else {
				byte[] value=Hex.decode(str);
				ASN1Object paramValue=ASN1Object.decode(value, AnyType.getInstance());
				return new AlgorithmIdentifier(oid,paramValue);
			}
		} catch(PkiException e) {
			throw new ServletException(e);
		} 
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
	
	private static AlgorithmIdentifier getDefaultSignAlgo(KeyPair keypair)throws ServletException {
		int algo=keypair.getAlgorithm();
		try {
			if(algo==KeyPair.RSA) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SHA256WithRSA_OID);
			} else if(algo==KeyPair.DSA) {
				return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.DSAWithSHA1_OID);
			} else if(algo==KeyPair.ECC) {
				int curve=keypair.getECCCurve();
				if(curve==Device.ECC_CURVE_P256) {
					return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA256_OID);
				} else if(curve==Device.ECC_CURVE_P384) {
					return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA384_OID);
				} else if(curve==Device.ECC_CURVE_P521) {
					return AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.ECDSAWithSHA512_OID);
				} else if(curve==Device.ECC_CURVE_SM2) {
					return AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
				} 
			}
		} catch(PkiException e) {
			throw new ServletException(e);
		} 
		throw new ServletException("get default sign algo fail");
	}
	private Date getProducedAt() throws ServletException {
		String str;
		str=getInitParameter("producedAt");
		if(str==null) {
			return null;
		}
		try {
			return Util.UTCTimeDecode(str.getBytes("UTF-8"));
		} catch (Exception e) {
			return null;
		}
		
	}
	
	private X509Certificate getCert() throws ServletException {
		String str;
		str=getInitParameter("cert");
		if(str==null) {
			throw new ServletException("no sign cert");
		}
		try {
			return new X509Certificate(str);
		} catch (PkiException e) {
			throw new ServletException(e);
		}
		
	}
	
	private X509Certificate getIssuerCert() throws ServletException {
		String str;
		str=getInitParameter("issuerCert");
		if(str==null) {
			throw new ServletException("no issuer cert");
		}
		try {
			return new X509Certificate(str);
		} catch (PkiException e) {
			throw new ServletException(e);
		}
		
	}
	
	private Date getThisUpdate() throws ServletException {
		String str;
		str=getInitParameter("thisUpdate");
		if(str==null) {
			return null;
		}
		try {
			return Util.UTCTimeDecode(str.getBytes("UTF-8"));
		} catch (Exception e) {
			return null;
		}
		
	}
	
	private X509CRL getCRL() throws ServletException {
		String str;
		str=getInitParameter("useCRLTime");
		if(str==null) {
			useCRLTime=false;
		} else if(str.equalsIgnoreCase("true")){
			useCRLTime=true;
		} else if(str.equalsIgnoreCase("false")){
			useCRLTime=false;
		} else {
			throw new ServletException("bad useCRLTime");
		}
		
		InputStream stream = getServletContext().getResourceAsStream("/WEB-INF/test.crl");
		if(stream==null) {
			throw new ServletException("no crl");
		}
		
		try {
			byte[] crlData=getData(stream);
			stream.close();
			
			return new X509CRL(crlData);
		} catch(Exception e) {
			throw new ServletException(e);
		}
	}
	
	private ResponderID  getResponderID()  throws ServletException {
		String str;
		int type;
		str=getInitParameter("byKey");
		if(str==null) {
			type=ResponderID.BYNAME_TYPE;
		} else if(str.equalsIgnoreCase("true")){
			type=ResponderID.BYKEY_TYPE;
		} else if(str.equalsIgnoreCase("false")){
			type=ResponderID.BYNAME_TYPE;
		} else {
			throw new ServletException("bad byKey");
		}
		try {
			return new ResponderID(type,signCert,new JCEHasher());
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	private byte[] getData(InputStream stream) throws ServletException{
		try {
			ByteArrayOutputStream outStream=new ByteArrayOutputStream();
			byte[] data=new byte[8192];
			int len;
			for(;;){
				len=stream.read(data);
				if(len==-1) {
					break;
				}
				outStream.write(data,0,len);
			}
			return outStream.toByteArray();
		} catch(IOException e) {
			throw new ServletException(e);
		}
	}
	
	private Date getNextUpdate() throws ServletException {
		String str;
		str=getInitParameter("nextUpdate");
		if(str==null) {
			return null;
		}
		try {
			return Util.UTCTimeDecode(str.getBytes("UTF-8"));
		} catch (Exception e) {
			return null;
		}
		
	}
	
	
	private boolean getDefaultGood() throws ServletException {
		String str;
		str=getInitParameter("defaultGood");
		if(str==null) {
			return true;
		} else if(str.equalsIgnoreCase("true")){
			return true;
		} else if(str.equalsIgnoreCase("false")){
			return false;
		} else {
			throw new ServletException("bad defaultGood");
		}
	}
	
	private byte[] getNonce() throws ServletException {
		String str;
		str=getInitParameter("useNonce");
		if(str==null) {
			useNonce=true;
		} else if(str.equalsIgnoreCase("true")){
			useNonce=true;
		} else if(str.equalsIgnoreCase("false")){
			useNonce=false;
		} else {
			throw new ServletException("bad useNonce");
		}
		
		str=getInitParameter("nonce");
		if(str==null) {
			return null;
		}
		try {
			return Hex.decode(str);
		} catch (PkiException e) {
			throw new ServletException("bad nonce");
		}
	}
	
	
	public void doPost(HttpServletRequest request,
            HttpServletResponse response)
            		throws ServletException, IOException {
		if("application/ocsp-request".equals(request.getContentType())==false) {
			throw new ServletException("bad req content-type");
		}
		byte[] data=getRequestData(request);
		NetcaVerifier verifier=null;
		try {
			OCSPRequest ocspReq;
			try {
				ocspReq=new OCSPRequest(data);
			} catch(PkiException e) {
				OCSPResponse ocspResp=OCSPResponse.NewErrorResponse(OCSPResponse.MALFORMEDREQUEST);
				
				byte[] respData=ocspResp.derEncode();
				response.setContentType("application/ocsp-response");
				response.setContentLength(respData.length);
				ServletOutputStream stream=response.getOutputStream();
				stream.write(respData);
				stream.close();
				return;
			} 
			if(ocspReq.hasSignature()) {
				verifier=new NetcaVerifier();
				if(ocspReq.verifySignature(verifier, null)==false){
					throw new ServletException("verify ocsp req signature fail");
				}
			}
			
			BasicOCSPResponseBuilder builder=new BasicOCSPResponseBuilder();
			builder.setResponderID(responderID);
			
			Date now=new Date();
			if(producedAt!=null){
				now=producedAt;
				builder.setProducedAt(producedAt);
			} else {
				builder.setProducedAt(now);
			}
			builder.addCert(signCert);
			
			Responses resps=getResponses(ocspReq.getRequestList(),now);
			builder.setResponses(resps);
			/* 仅仅处理Nonce扩展 */
			setNonce(builder,ocspReq.getExtensions());
			
			BasicOCSPResponse basicOcspResp=builder.sign(signer, signAlgo);
			OCSPResponse ocspResp=OCSPResponse.NewBasicOCSPResponse(basicOcspResp);
			
			byte[] respData=ocspResp.derEncode();
			response.setContentType("application/ocsp-response");
			response.setContentLength(respData.length);
			ServletOutputStream stream=response.getOutputStream();
			stream.write(respData);
			stream.close();
			
		} catch(PkiException e) {
			throw new ServletException(e);
		} finally {
			if(verifier!=null) {
				verifier.free();
			}
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
	
	private Responses getResponses(RequestList reqList,Date now)throws ServletException {
		try {
			Responses resps=new Responses();
			SingleResponse resp;
			int count=reqList.size();
			CertID certId;
			SingleRequest req;
			for(int i=0;i<count;i++) {
				req=reqList.get(i);
				certId=req.getReqCert();
				/*
				 * 忽略扩展 
				 */
				resp=getResponse(certId,now);
				resps.add(resp);
			}
			return resps;
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private SingleResponse getResponse(CertID certId,Date now) throws ServletException {
		NetcaHasher hasher=null;
		try{
			AlgorithmIdentifier hashAlgo=certId.getHashAlgorithm();
			hasher=new NetcaHasher();
			byte[] issuerKeyHash=certId.getIssuerKeyHash();
			byte[] issuerKey=issuerCert.getSubjectPublicKeyInfo().getSubjectPublicKey().getValue();
			byte[] issuerKeyHash2=hasher.hash(hashAlgo, issuerKey, 0, issuerKey.length);
			
			if(isByteArrayEqual(issuerKeyHash,issuerKeyHash2)==false) {
				return getDefaultResponse(certId,now);
			}
			
			byte[] issuerNameHash=certId.getIssuerNameHash();
			/* 假定CRL不是间接CRL */
			byte[] issuerName=crl.getIssuer().getASN1Object().encode();
			byte[] issuerNameHash2=hasher.hash(hashAlgo, issuerName, 0, issuerName.length);
			
			if(isByteArrayEqual(issuerNameHash,issuerNameHash2)==false) {
				return getDefaultResponse(certId,now);
			}
			
			/* 假定CRL不是间接CRL也不是Delta CRL */
			CRLEntry entry=getCRLEntry(crl,certId.getSerialNumber());
			
			if(entry==null) {
				return getDefaultResponse(certId,now);
			}
			return getRevokedResponse(certId,entry,now);
			
		}catch (PkiException e) {
			throw new ServletException(e);
		} finally {
			if(hasher!=null) {
				hasher.free();
			}
		}
	}
	
	private boolean isByteArrayEqual(byte[] b1,byte[] b2) {
		if(b1.length!= b2.length) {
			return false;
		}
		
		for(int i=0;i<b1.length;i++) {
			if(b1[i]!=b2[i]) {
				return false;
			}
		}
		return true;
	}
	
	private SingleResponse getDefaultResponse(CertID certId,Date now) throws ServletException {
		try {
			if(defaultGood) {
				return new SingleResponse(certId,CertStatus.NewGood(),
					getResponseThisUpdate(now),getResponseNextUpdate(),null);
			} else {
				return new SingleResponse(certId,CertStatus.NewUnknown(),
						getResponseThisUpdate(now),getResponseNextUpdate(),null);
			}
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	
	private Date getResponseThisUpdate(Date now) throws ServletException{
		if(useCRLTime) {
			try {
				return crl.getThisUpdate();
			} catch (PkiException e) {
				throw new ServletException("getThisUpdate fail");
			}
		} else {
			if(thisUpdate!=null) {
				return thisUpdate;
			} else {
				return now;
			}
		}
	}
	
	private Date getResponseNextUpdate() throws ServletException{
		if(useCRLTime) {
			try {
				return crl.getNextUpdate();
			} catch (PkiException e) {
				throw new ServletException("getNextUpdate fail");
			}
		} else {
			return nextUpdate;
		}
	}
	
	private CRLEntry getCRLEntry(X509CRL crl,byte[] sn)throws ServletException{
		try {
			
			CRLEntries entries=crl.getCRLEntries();
			if(entries==null) {
				return null;
			}
			CRLEntry entry;
			byte[] sn2;
			int count=entries.size();
			for(int i=0;i<count;i++) {
				entry=entries.get(i);
				sn2=entry.getSerialNumber();
				
				if(isByteArrayEqual(sn,sn2)) {
					return entry;
				}
			}
			
			return null;
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private SingleResponse getRevokedResponse(CertID certId,CRLEntry entry,Date now) throws ServletException {
		try {
			Date revocationTime=entry.getRevocationDate();
			int revocationReason=getRevocationReason(entry);
			RevokedInfo revoked=new RevokedInfo(revocationTime,revocationReason);
			/*
			 * 不处理其他CRL条目扩展
			 */
			return new SingleResponse(certId,CertStatus.NewRevoked(revoked),
					getResponseThisUpdate(now),getResponseNextUpdate(),null);
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private int getRevocationReason(CRLEntry entry) throws ServletException {
		try {
			Extensions exts=entry.getExtensions();
			if(exts==null) {
				return -1;
			}
			Extension ext;
			ext=exts.get(Extension.CRLREASONS_OID);
			if(ext==null) {
				return -1;
			}
			ExtensionObject extObj=ext.getExtensionObject();
			ASN1Object asn1Obj=extObj.getASN1Object();
			if (asn1Obj instanceof  Enumerated) {
				return ((Enumerated)asn1Obj).getIntegerValue();
			} else {
				throw new ServletException("bad crl reason extension");
			}
		} catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	private void setNonce(BasicOCSPResponseBuilder builder,Extensions reqExts) throws ServletException {
		try {
			if(useNonce==false) {
				return;
			}
			Extensions respExts=new Extensions();
			Extension nonceExt=null;
			if(reqExts!=null) {
				nonceExt=reqExts.get(Extension.OCSP_NONCE_OID);
			}
			if(nonce==null) {
				if(nonceExt==null) {
					return;
				} else {
					respExts.add(nonceExt);
				}
			} else {
				nonceExt=new Extension(Extension.OCSP_NONCE_OID,false,new OctetStringExtension(nonce));
				respExts.add(nonceExt);
			}
			builder.setExtensions(respExts);
		}  catch (PkiException e) {
			throw new ServletException(e);
		}
	}
	
	public void destroy() {
		if(signer!=null) {
			signer.free();
		}
	}
}
