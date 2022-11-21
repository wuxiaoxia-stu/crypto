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
    <title>JCEWeb</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
		<h3>单向/双向验证</h3>
		<div>
			<div>
				<%
					//获取证书
					X509Certificate[] certs=(X509Certificate[])request.getAttribute("javax.servlet.request.X509Certificate");
					if(certs!=null){
						for(int i=0;i<certs.length;i++){
						X509Certificate certObj=certs[i];
						%>
						<p>双向验证:有客户端证书</p>
						<p>版本号 : <%=certObj.getVersion()%></p>
						<p>序列号 : <%=certObj.getSerialNumber().toString(16)%></p>
						<p>全名 : <%=certObj.getSubjectDN()%></p>
						<p>签发者全名 : <%=certObj.getIssuerDN()%></p>
						<p>有效期起始日 : <%=certObj.getNotBefore()%></p>
						<p>有效期截至日 : <%=certObj.getNotAfter()%></p>
						<p>签名算法 : <%=certObj.getSigAlgName()%></p>
						<hr>
						
						<%}
					}
					else{
						%>
						<p>单向验证:无客户端证书</p>
					
					<%}%>
					
					
					
					
			</div>
			
		</div>
			
					
    </div>
</body>

</html>