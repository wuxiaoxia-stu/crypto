<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.security.*,java.io.*,java.security.cert.*,javax.crypto.spec.*,java.util.*,sun.misc.BASE64Encoder" %>

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
    <title>Cipher-RSA/ECB</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
        <h3>"中1Aa~!@#$%^" Cipher-RSA/ECB</h3>
		<h3>非对称加解密</h3>
		<div>
			<div>
				<%	//加密
					String[] Algo={"RSA/ECB/NOPADDING","RSA/ECB/PKCS1PADDING"};
					String[] keyAlgo={"RSA","RSA"};
					
					String str="";  
					File file=new File(request.getRealPath("/")+"clearCipher.txt");  
					BASE64Encoder encode = new BASE64Encoder();
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
					
					for(int i=1; i<Algo.length; i++){
						System.out.println(i+1);
						System.out.println(keyAlgo[i]);
						System.out.println(Algo[i]);
						System.out.println("中1Aa~!@#$%^&*(".getBytes("UTF-8").length);
						
						//获取证书
						CertificateFactory cf=CertificateFactory.getInstance("X.509");
						FileInputStream fIn=new FileInputStream(new File(request.getRealPath("/")+"rsa_cert.cer"));
						X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
						fIn.close();
						
						
						//初始化密码器Cipher
						Cipher cipher=Cipher.getInstance(Algo[i],"NetcaJCE");
						cipher.init(Cipher.ENCRYPT_MODE,certObj);
						
						byte[] result = cipher.doFinal(str.getBytes("UTF-8"));
						
						try { 
							FileOutputStream fos = new FileOutputStream(new File(request.getRealPath("/")+"Cipher/"+Algo[i].replace("/", "_")+"_cipher.txt"));    
							fos.write(result);  
							fos.close();  
						} catch (Exception e) {  
							// TODO Auto-generated catch block  
							e.printStackTrace();  
						}
						
				%>

			</div>
			
        </div>
		
		<div>
				<%	//解密
						//获取私钥
						InputStream inputStream = new FileInputStream(new File(request.getRealPath("/")+"rsa_keystore.json"));
						KeyStore ks = KeyStore.getInstance("NETCA-JSON");
						ks.load(inputStream,null);
						PrivateKey privKey=(PrivateKey)ks.getKey("tomcat","12345678".toCharArray());
				
						cipher.init(Cipher.DECRYPT_MODE,privKey);
						byte[] decryptResult = cipher.doFinal(result);
						String printDecryptResult=new String(decryptResult,"UTF-8");  
						
				%>
						<strong><%=i+1%>. <%=Algo[i]%> : </strong>
						<p>output : <%=request.getRealPath("/")+"Cipher\\"+Algo[i].replace("/", "_")+"_cipher.txt"%></p>
						<p>encrypt(Base64) : <%=encode.encode(result)%></p>
						<p>decrypt : <%=printDecryptResult%></p>
						<hr>
						


			</div>
			
					<%}%>
			
        </div>
    </div>
</body>

</html>