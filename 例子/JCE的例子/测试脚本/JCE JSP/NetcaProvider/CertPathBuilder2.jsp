<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.spec.*,java.io.*,java.security.cert.*,javax.crypto.spec.*,java.util.*" %>

<%!
private static class TestTool {
	private static final char[] HEX_CHAR = {'0', '1', '2', '3', '4', '5', 
		    '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	public static String toHexString(byte[] bytes) {
		char[] buf = new char[bytes.length * 2];
		int index = 0;
		for(byte b : bytes) { // 利用位运算进行转换，可以看作方法一的变种
		    buf[index++] = HEX_CHAR[b >>> 4 & 0xf];
		    buf[index++] = HEX_CHAR[b & 0xf];
		}

		return new String(buf);
    }
}
%>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>CertPathBuilder</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
	<div class="container" id="container">
		<h3>CertPathBuilder</h3>
		<h3>构造和验证公钥证书</h3>
		<div>
			<div>
				<%
				String[] arg=new String[]{request.getRealPath("/")+"SM2_enc.cer",request.getRealPath("/")+"SM2_CA01.cer",request.getRealPath("/")+"SM2_ROOTCA.cer"};
				String trustAnchor = request.getRealPath("/")+"SM2_ROOTCA.cer"; 
				CertificateFactory cf = CertificateFactory.getInstance("X.509","NetcaProvider");
				int i;
				List mylist = new ArrayList();
				for (i=0; i<arg.length; i++){
					FileInputStream in=new FileInputStream(arg[i]);
					Certificate c=cf.generateCertificate(in);
					mylist.add(c);
				}
				CertPath cp = cf.generateCertPath(mylist);
				//以上将证书列表转换成证书链
				//设置锚点  
				FileInputStream in=new FileInputStream(trustAnchor);  
				Certificate trust=cf.generateCertificate(in);  
				// Create TrustAnchor  
				TrustAnchor anchor = new TrustAnchor( (X509Certificate)trust,null);  
				// Set the PKIX parameters  
				PKIXParameters params = new PKIXParameters(Collections.singleton(anchor));  
				params.setRevocationEnabled(false);  
				CertPathValidator cpv = CertPathValidator.getInstance("PKIX","NetcaProvider");  
				PKIXCertPathValidatorResult result = null;
				result =(PKIXCertPathValidatorResult) cpv.validate(cp, params);  
				System.out.println(result);  
				System.out.println(result.getTrustAnchor()); 

				%>
				<p><%=result.toString()%></p>
				<br />
				<p><%=result.getTrustAnchor()%></p>
				<hr>

			</div>
			
		</div>
	</div>
</body>

</html>