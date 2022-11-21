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
    <title>Mac</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
        <div>
			<h3>"中1Aa~!@#$%^&*()_+" Mac</h3>
            
        	<%
				//net.netca.pki.jce.NetcaJCEProvider.mac.enabled="off";
                String[] macAlgo={"HMACMD5","HMACSHA1","1.2.840.113549.2.7","HMACSHA224","1.2.840.113549.2.8","HMACSHA256","1.2.840.113549.2.9","HMACSHA384","1.2.840.113549.2.10","HMACSHA512","1.2.840.113549.2.11","HMACSM3","HMACSHA512/224","HMACSHA512/256","HMACSHA3-224","2.16.840.1.101.3.4.2.13","HMACSHA3-256","2.16.840.1.101.3.4.2.14","HMACSHA3-384","2.16.840.1.101.3.4.2.15","HMACSHA3-512","2.16.840.1.101.3.4.2.16"};
				String[] CTTResult={"47fd7c7f1c2283e6e58870b7c650a562","30803182909aa334b3eacd514b7699aa84a61089","30803182909aa334b3eacd514b7699aa84a61089","815c4b53eb1a6b5c84281d10634eb4951dbf521c4480306c09c16e51","815c4b53eb1a6b5c84281d10634eb4951dbf521c4480306c09c16e51","557cb881ec00c83c365de215f515b7e84a67cc54d787906cef2dd87ffb1a0c85","557cb881ec00c83c365de215f515b7e84a67cc54d787906cef2dd87ffb1a0c85","4dcc4db69a4065a99f84aa0e7034b5d57ace1e38872103fd8ba3637a7a1f8606c1ccb4e51f78a54e2028147d655b0110","4dcc4db69a4065a99f84aa0e7034b5d57ace1e38872103fd8ba3637a7a1f8606c1ccb4e51f78a54e2028147d655b0110","52af509daeb883a9523b4c1d2ede4b86b4bdc0185290f19fe518a188a37bf9651d944444ec3a03801b2c7a4d8041d8c3e6812d128041514b9a36dd1a9e459106","52af509daeb883a9523b4c1d2ede4b86b4bdc0185290f19fe518a188a37bf9651d944444ec3a03801b2c7a4d8041d8c3e6812d128041514b9a36dd1a9e459106","b162fb0d25ef4100b8560d17f0bf926703d221745767a763915168e45912dc24","180da463f4834a1276a473dc10efc3c6f4aa0260bc8d440b8e90d570","25af7345eff51fa9b0adf95b005cb919f89bc162b03a162defbf4b3e888275d3","bd26a19db207f19f945891c569a097aa4f59adcce990daad4de04e8e","bd26a19db207f19f945891c569a097aa4f59adcce990daad4de04e8e","4f9085feee585c3069a79a9df008dc0a883686ab47bd152068211ee31dc69cc2","4f9085feee585c3069a79a9df008dc0a883686ab47bd152068211ee31dc69cc2","830b1f7405b8ee8bd560fbc168e654960ec897703a5e48a0fc2faab4e56c985da929a6248b2f7f8b9e8b66a42e020f0c","830b1f7405b8ee8bd560fbc168e654960ec897703a5e48a0fc2faab4e56c985da929a6248b2f7f8b9e8b66a42e020f0c","2bfd2c3275099d30078d6d1bcb2681c289c5d802dbaa55e90ed21a785658c4322cb92337c209eed2f12d734ff488a75cb3bf831c1d5ad8b7f60738ffb8aa93f5","2bfd2c3275099d30078d6d1bcb2681c289c5d802dbaa55e90ed21a785658c4322cb92337c209eed2f12d734ff488a75cb3bf831c1d5ad8b7f60738ffb8aa93f5"};
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
				
				
				for(int i=0; i<macAlgo.length; i++){
					
					Mac mac= Mac.getInstance(macAlgo[i],"NetcaJCE");
					SecretKeySpec keySpec=new SecretKeySpec(new byte[]{(byte)0x31,(byte)0x32,(byte)0x33,(byte)0x34,(byte)0x35,(byte)0x36,(byte)0x37,(byte)0x38},macAlgo[i]);

					mac.init(keySpec);
					mac.update(str.getBytes("UTF-8"));
					byte[] result=mac.doFinal();
					String printResult=TestTool.toHexString(result);
					String match = "False";
					if(printResult.equals(CTTResult[i])==true){
						match = "True";
					}

					
			%>
					<p><%=macAlgo[i]%> : <%=printResult%></p>
					<p>CryptoTestTool : <%=CTTResult[i]%></p>
					<p style="color:red;">match : <%=match%></p>
					<hr>
				<%}%>

        </div>
        
    </div>
</body>

</html>