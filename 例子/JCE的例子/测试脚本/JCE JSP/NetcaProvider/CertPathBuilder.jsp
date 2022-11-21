<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.io.*,java.security.cert.*,javax.crypto.spec.*,java.util.*" %>

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
		<h3>构造证书路径</h3>
		<div>
			<div>
				<%
				String[] arg=new String[]{request.getRealPath("/")+"SM2_enc.cer",request.getRealPath("/")+"SM2_CA01.cer",request.getRealPath("/")+"SM2_ROOTCA.cer"};
				
				CertificateFactory cf = CertificateFactory.getInstance("X.509","NetcaProvider");
				int i;
				List certCol = new ArrayList();
				for (i=0; i<arg.length; i++){
					FileInputStream in=new FileInputStream(arg[i]);
					Certificate c=cf.generateCertificate(in);
					certCol.add(c);
				}

				CertPathBuilder pathBuilder = CertPathBuilder.getInstance("PKIX","NetcaProvider");
				X509CertSelector selector = new X509CertSelector();
				selector.setCertificate((X509Certificate)certCol.get(0));

				//设置锚点
				String trustAnchor = request.getRealPath("/")+"SM2_ROOTCA.cer"; 
				FileInputStream in=new FileInputStream(trustAnchor);  
				Certificate trust=cf.generateCertificate(in);  
				// Create TrustAnchor  
				TrustAnchor anchor = new TrustAnchor( (X509Certificate)trust,null);

				CertStore certStore = CertStore.getInstance("Collection", new CollectionCertStoreParameters(certCol));

				PKIXBuilderParameters params = new PKIXBuilderParameters(Collections.singleton(anchor),selector);
				
				params.addCertStore(certStore);
				params.setRevocationEnabled(false);
				CertPath path = pathBuilder.build(params).getCertPath();
				%>
				<p><%=path%></p>
				<hr>

			</div>
			
		</div>
		<h3>验证证书路径</h3>
		<div>
			<div>
				<%
				// Set the PKIX parameters  
				PKIXParameters PKIXparams = new PKIXParameters(Collections.singleton(anchor));  
				PKIXparams.setRevocationEnabled(false);  
				CertPathValidator cpv = CertPathValidator.getInstance("PKIX","NetcaProvider");  
				PKIXCertPathValidatorResult result = null;
				result =(PKIXCertPathValidatorResult) cpv.validate(path, PKIXparams);  
				System.out.println(result);  
				System.out.println(result.getTrustAnchor()); 

				%>
				<p><%=result.toString()%></p>
				<hr>

			</div>
			
		</div>
		
	</div>
</body>

</html>