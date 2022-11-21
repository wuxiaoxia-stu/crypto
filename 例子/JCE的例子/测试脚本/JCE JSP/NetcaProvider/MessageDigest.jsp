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
                String[] Algo={"SM3","1.2.156.10197.1.401"};
				String[] CTTResult={"2026041a17a580e806ceea73be0f676be0088bc21f579fe4d8a9a2b8cd655f52","2026041a17a580e806ceea73be0f676be0088bc21f579fe4d8a9a2b8cd655f52"};
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
					
					MessageDigest md= MessageDigest.getInstance(Algo[i],"NetcaProvider");
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