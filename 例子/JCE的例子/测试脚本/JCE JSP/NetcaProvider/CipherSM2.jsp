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
    <title>Cipher-SM2</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
        <h3>"中1Aa~!@#$%^&*(" Cipher-SM2</h3>
		<h3>对称加解密</h3>
		<p>NetcaProvider加密，NetcaJCE解密</p>
		<hr>
		<div>
			<div>
				<%
					//加密
					System.out.println("SM2/ECB/NOPADDING");
					
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
					
					
					//获取证书
					CertificateFactory cf=CertificateFactory.getInstance("X.509","NetcaProvider");
					FileInputStream fIn=new FileInputStream(new File(request.getRealPath("/")+"SM2_enc.cer"));
					X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
					fIn.close();
					
					
					//初始化密码器Cipher
					Cipher cipher=Cipher.getInstance("SM2/ECB/NOPADDING","NetcaProvider");
					cipher.init(Cipher.ENCRYPT_MODE,certObj);
					
					byte[] result = cipher.doFinal(str.getBytes("UTF-8"));
					try { 
						FileOutputStream fos = new FileOutputStream(new File(request.getRealPath("/")+"Cipher/SM2_cipher.txt"));    
						fos.write(result);  
						fos.close();  
					} catch (Exception e) {  
						// TODO Auto-generated catch block  
						e.printStackTrace();  
					}
				%>

			</div>
			<div>
				<%	//解密
					//获取私钥
					KeyStore ks = KeyStore.getInstance("NETCA-DEVICE");
					ks.load(null,null);
					PrivateKey privKey=(PrivateKey)ks.getKey("4#4B43353230066062#275357A4-B3B3-419D-8738-29760F890F8F#S","12345678".toCharArray());

					Cipher cipherDecrypt=Cipher.getInstance("SM2/ECB/NOPADDING","NetcaJCE");
					cipherDecrypt.init(Cipher.DECRYPT_MODE,privKey);
					byte[] decryptResult = cipherDecrypt.doFinal(result);
					String printDecryptResult=new String(decryptResult,"UTF-8");  
					
				%>
				
					<strong><%="SM2"%> : </strong>
					<p>output : <%=request.getRealPath("/")+"SM2_enc.cer"%></p>
					<p>encrypt(Base64) : <%=encode.encode(result)%></p>
					<p>decrypt : <%=printDecryptResult%></p>
					<hr>	
			</div>
			
		</div>
			
					
    </div>
</body>

</html>