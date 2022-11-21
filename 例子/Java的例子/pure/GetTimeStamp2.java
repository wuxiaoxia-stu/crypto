import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.Arrays;
import java.util.Date;
import net.netca.pki.encoding.asn1.pki.tsp.*;
import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;

public class GetTimeStamp2 {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java GetTimeStamp2 url infile token");
            return;
        }

        String url=arg[0];
        String inputFileName=arg[1];
        String outputFileName=arg[2];
        
        byte[] data=readFile(inputFileName);
        TimeStampReq req=createTimeStampReq(data);
        byte[] respData=getHttpData(url,req.derEncode());
        TimeStampResp resp=new TimeStampResp(respData);
        PKIStatusInfo info=resp.getStatus();
        int status;
        status=info.getStatus();
        if(status!=PKIStatusInfo.GRANTED
        		&& status!=PKIStatusInfo.GRANTEDWITHMODS) {
        	System.out.println("get timestamp resp fail,status="+status);
        	return;
        }
        
        SignedData sign=resp.getTimeStampTokenObject();
        if(sign==null) {
        	System.out.println("no timestmp");
        	return;
        }
        if(sign.getSignerInfoCount()!=1) {
        	System.out.println("to much signerinfo");
        	return;
        }
        
        if(sign.verify(0, new JCEVerifier(), new JCEHasher())==false) {
        	System.out.println("verify fail");
        	return;
        }
        
        if(checkTimeStampCert(sign.getSignCert(0))==false) {
        	System.out.println("bad TimeStamp cert");
        	return;
        }
        
        SignerInfo signerInfo=(SignerInfo)sign.getSignerInfos().get(0);
        if(signerInfo.hasSigningCertificateAttribute()==false
        	&& signerInfo.hasSigningCertificateV2Attribute()) {
        	System.out.println("bad timestamp resp,no SigningCertificate or SigningCertificateV2 attribute");
        	return;
        }
        
        TSTInfo tstInfo=resp.getTstInfo();
        if(tstInfo==null) {
        	System.out.println("bad TSTInfo");
        	return;
        }
        
        if(matchMessageImprint(req.getMessageImprint(),tstInfo.getMessageImprint())==false) {
        	System.out.println("bad MessageImprint");
        	return;
        }
        
        writeFile(outputFileName,resp.getTimeStampToken());
        System.out.println("TimeStamp:"+tstInfo.getTime());
    }


    private static void writeFile(String fileName,byte[]data) throws Exception {
		FileOutputStream out=new FileOutputStream(fileName);
		out.write(data);
		out.close();
	}
    
    private static byte[] readFile(String fileName) throws Exception {
    	File f=new File(fileName);
    	if(f.length()>Integer.MAX_VALUE) {
    		throw new Exception("file to big");
    	}
    	int len=(int)f.length();
    	byte[] data=new byte[len];
    	FileInputStream stream=new FileInputStream(f);
    	len=stream.read(data);
    	stream.close();
    	if(len!=data.length) {
    		throw new Exception("read file fail");
    	}
    	return data;
    }
    
    private static TimeStampReq createTimeStampReq(byte[]data) throws Exception {
    	TimeStampReqBuilder builder=new TimeStampReqBuilder();
    	AlgorithmIdentifier hashAlgo=AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
    	
    	byte[] hashValue=(new JCEHasher()).hash(hashAlgo, data, 0, data.length);
    	MessageImprint messageImprint=new MessageImprint(hashAlgo,hashValue);
    	
    	builder.setMessageImprint(messageImprint);
		builder.setCertReq(true);
		builder.setNonce(new JCESecureRandomGenerator());
		
		return builder.build();
    }
    
    private static byte[] getHttpData(String url,byte[] req) throws Exception{
    	URL urlObj=new URL(url);
    	URLConnection conn=urlObj.openConnection();
    	if(conn instanceof HttpURLConnection==false) {
    		throw new Exception("not http url");
    	}
    	HttpURLConnection httpConn=(HttpURLConnection)conn;
    	httpConn.setRequestMethod("POST");
    	httpConn.setRequestProperty("Content-Type", "application/timestamp-query");
    	httpConn.addRequestProperty("Content-Length", req.length+"");
    	httpConn.setDoOutput(true);
    	
    	httpConn.connect();
    	
    	OutputStream out = httpConn.getOutputStream();
    	out.write(req);
    	out.close();
    	
    	int status=httpConn.getResponseCode();
    	if(status!=HttpURLConnection.HTTP_OK) {
    		httpConn.disconnect();
    		throw new Exception("bad http status "+status);
    	}
    	
    	String nLenStr=httpConn.getHeaderField("Content-Length");
    	if(nLenStr==null) {
    		httpConn.disconnect();
    		throw new Exception("no content length");
    	}
    	
    	int nLen = java.lang.Integer.parseInt(nLenStr);
    	byte []resp=new byte[nLen];
    	int ic;
		BufferedInputStream bis=new BufferedInputStream(httpConn.getInputStream());
		for ( int i = 0 ;i < nLen ; i++ ) {
			ic = bis.read();
			if(ic==-1) {
				bis.close();
				httpConn.disconnect();
				throw new Exception("bad resp");
			}
						
			resp[i]=(byte)ic;
		}
		
		bis.close();
		httpConn.disconnect();
		
		return resp;
    }
    
    private static boolean checkTimeStampCert(X509Certificate cert) throws Exception{
    	Date now =new Date();
    	
    	if(now.before(cert.getNotBefore())) {
    		return false;
    	}
    	
    	if(now.after(cert.getNotAfter())) {
    		return false;
    	}
    	
    	Extensions exts=cert.getExtensions();
    	if(exts==null) {
    		return false;
    	}
    	
    	Extension ext=exts.get(Extension.EXTKEYUSAGE_OID);
    	if(ext==null) {
    		return false;
    	}
    	ExtKeyUsageExtension extKu=(ExtKeyUsageExtension)ext.getExtensionObject();
    	int count=extKu.size();
    	if(count!=1) {
    		return false;
    	}
    	if(extKu.get(0).equals("1.3.6.1.5.5.7.3.8")) {
    		return true;
    	}
    	    	
    	return false;
    }
    
    private static boolean matchMessageImprint(MessageImprint messageImprint1,MessageImprint messageImprint2) throws Exception {
    	if(messageImprint1.getHashAlgorithm().getOid().equals(messageImprint2.getHashAlgorithm().getOid())==false) {
    		return false;
    	}
    	return Arrays.equals(messageImprint1.getHashedMessage(), messageImprint2.getHashedMessage());
    }
}
