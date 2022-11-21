<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.security.*,java.io.*" %>

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
    <title>MessageDigest</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>

<body>
    <div class="container" id="container">
        <div>
			<h3>"中1Aa~!@#$%^&*()_+" MessageDigest</h3>
            
        	<%
                String[] Algo={"MD5","1.2.840.113549.2.5","SHA1","1.3.14.3.2.26","SHA-1","SHA","SHA-224","2.16.840.1.101.3.4.2.4","SHA-256","2.16.840.1.101.3.4.2.1","SHA-384","2.16.840.1.101.3.4.2.2","SHA-512","2.16.840.1.101.3.4.2.3","SM3","1.2.156.10197.1.401","SHA-512/224","2.16.840.1.101.3.4.2.5","SHA-512/256","2.16.840.1.101.3.4.2.6","SHA3-224","2.16.840.1.101.3.4.2.7","SHA3-256","2.16.840.1.101.3.4.2.8","SHA3-384","2.16.840.1.101.3.4.2.9","SHA3-512","2.16.840.1.101.3.4.2.10"};
				String[] CTTResult={"52d11622f297f74282ce5f400ead556d","52d11622f297f74282ce5f400ead556d","183bb867c4bc98e80f1a1865cb2369b9018f03fc","183bb867c4bc98e80f1a1865cb2369b9018f03fc","183bb867c4bc98e80f1a1865cb2369b9018f03fc","183bb867c4bc98e80f1a1865cb2369b9018f03fc","4c9b13ed3f97a010de338937a22f8ba643c3f922beabb0a1228c2782","4c9b13ed3f97a010de338937a22f8ba643c3f922beabb0a1228c2782","3002bc5c2cfbc4ea26fa636cf3dd3727501203ecdc0dd729c43ce01a63d4ba57","3002bc5c2cfbc4ea26fa636cf3dd3727501203ecdc0dd729c43ce01a63d4ba57","0f057dfff0e380863bc329858d1166620ece94c2030b66aa80531a0b35c15add6f19af9335ed3275f4bf3740c7a69579","0f057dfff0e380863bc329858d1166620ece94c2030b66aa80531a0b35c15add6f19af9335ed3275f4bf3740c7a69579","a546e0b73d42c99dd1cf62efc43d118a4780d696b975c1520f5dd60e9b2647b9b6d846ec2d88dce5dd95a034ccd4710b008679e159764cdfc93e0ac6008cb308","a546e0b73d42c99dd1cf62efc43d118a4780d696b975c1520f5dd60e9b2647b9b6d846ec2d88dce5dd95a034ccd4710b008679e159764cdfc93e0ac6008cb308","2026041a17a580e806ceea73be0f676be0088bc21f579fe4d8a9a2b8cd655f52","2026041a17a580e806ceea73be0f676be0088bc21f579fe4d8a9a2b8cd655f52","3136db5373c6ed468a8bf879be41b453d12a56e69f5ca58abd2363fb","3136db5373c6ed468a8bf879be41b453d12a56e69f5ca58abd2363fb","b249719909be8469c92725630a1e201144af62bfbcbfbbd035437121e87912a1","b249719909be8469c92725630a1e201144af62bfbcbfbbd035437121e87912a1","3c48e9eef6212cbc1cf0f29ff092dc998b7b2adee83cc12e7c49ab5e","3c48e9eef6212cbc1cf0f29ff092dc998b7b2adee83cc12e7c49ab5e","ca790f3ac04628c55355dbace23cdf4c32751fcecbfbef11c56dd498c75a1840","ca790f3ac04628c55355dbace23cdf4c32751fcecbfbef11c56dd498c75a1840","93e7d4070aa209124b71acc83767b8d67f772f4ed16e9344f32794cfffd05070aeebe1eb5cd3ec6dc95f0f5217df5e32","93e7d4070aa209124b71acc83767b8d67f772f4ed16e9344f32794cfffd05070aeebe1eb5cd3ec6dc95f0f5217df5e32","a3bb23ecb27944c05bb6b18d2922cf0a9d1bb77c76dda14940899fcfc0c0c7936cfa7415dd2e1c1af51584b7c8d0b0a0595dc3aa0e5fb4c60399cc74d195092c","a3bb23ecb27944c05bb6b18d2922cf0a9d1bb77c76dda14940899fcfc0c0c7936cfa7415dd2e1c1af51584b7c8d0b0a0595dc3aa0e5fb4c60399cc74d195092c"};
				String str="";  
				File file=new File(request.getRealPath("/")+"clear.txt");  
				try {  
					FileInputStream in=new FileInputStream(file);  
					// size  为字串的长度 ，这里一次性读完  
					int size=in.available();  
					byte[] buffer=new byte[size];  
					in.read(buffer);  
					in.close();  
					str=new String(buffer,"UTF-8");  
				} catch (IOException e) {  
					// TODO Auto-generated catch block  
					e.printStackTrace();  
				}  
				
				for(int i=0; i<Algo.length; i++){
					
					MessageDigest md= MessageDigest.getInstance(Algo[i],"NetcaJCE");
					md.update(str.getBytes("UTF-8"));
					byte[] result=md.digest();
					String printResult=TestTool.toHexString(result);  
					String match = "False";
					if(printResult.equals(CTTResult[i])==true){
						match = "True";
					}
			%>
					<p><%=Algo[i]%> = <%=printResult%></p>
					<p>CryptoTestTool : <%=CTTResult[i]%></p>
					<p style="color:red;">match : <%=match%></p>
					<hr>
				<%}%>

        </div>
        
    </div>
</body>

</html>