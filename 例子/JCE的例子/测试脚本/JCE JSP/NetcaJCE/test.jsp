<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.security.*,java.io.*,java.security.cert.*,javax.crypto.spec.*,java.util.*" %>

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
				CertPathBuilder cpb = CertPathBuilder.getInstance("PKIX","NetcaProvider");
				PKIXRevocationChecker rc = (PKIXRevocationChecker)cpb.getRevocationChecker();
				rc.setOptions(EnumSet.of(Option.PREFER_CRLS));
				params.addCertPathChecker(rc);
				CertPathBuilderResult cpbr = cpb.build(params); 
				%>

			</div>
			
        </div>
    </div>
</body>

</html>