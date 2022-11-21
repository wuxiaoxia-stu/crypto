<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.security.*,java.io.*,java.security.cert.*,javax.crypto.spec.*,java.util.*,java.math.*" %>

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
    <title>CertificateFactory</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
        <h3>CertificateFactory</h3>
		<h3>解析公钥证书</h3>
		<div>
			<div>
				<%
				String[] certArray={"X.509","X509"};
				for(int i=0; i<certArray.length; i++){
					//加密
					System.out.println("SM2");
					System.out.println("中1Aa~!@#$%^&*(".getBytes("UTF-8").length);
					
					//获取证书
					CertificateFactory cf=CertificateFactory.getInstance(certArray[i],"NetcaProvider");
					FileInputStream fIn=new FileInputStream(new File(request.getRealPath("/")+"SM2_enc.cer"));
					X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
					fIn.close();
				%>
					<strong><%="SM2("+certArray[i]+")"%> : </strong>
					<p>版本号 : <%=certObj.getVersion()%></p>
					<p>序列号 : <%=certObj.getSerialNumber().toString(16)%></p>
					<p>全名 : <%=certObj.getSubjectDN()%></p>
					<p>签发者全名 : <%=certObj.getIssuerDN()%></p>
					<p>有效期起始日 : <%=certObj.getNotBefore()%></p>
					<p>有效期截至日 : <%=certObj.getNotAfter()%></p>
					<p>签名算法 : <%=certObj.getSigAlgName()%></p>
					<hr>

			</div>
			
				<%}%> 
			
		</div>
			
					
    </div>
</body>

</html>