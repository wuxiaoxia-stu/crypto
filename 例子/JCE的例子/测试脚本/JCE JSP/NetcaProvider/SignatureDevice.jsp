<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.security.*,java.io.*,java.security.cert.*,sun.misc.BASE64Encoder" %>

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
	public static byte[] toByteArray(String hexString) {   
		if (hexString == null || hexString.equals("")) {   
			return null;   
		}   
		hexString = hexString.toUpperCase();   
		int length = hexString.length() / 2;   
		char[] hexChars = hexString.toCharArray();   
		byte[] d = new byte[length];   
		for (int i = 0; i < length; i++) {   
			int pos = i * 2;   
			d[i] = (byte) (charToByte(hexChars[pos]) << 4 | charToByte(hexChars[pos + 1]));   
		}   
		return d;   
	}   
	private static byte charToByte(char c) {  
		return (byte) "0123456789ABCDEF".indexOf(c);  
	}  
}


%>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>SignatureDevice</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>

<body>
    <div class="container" id="container">
		<h3>"中1Aa~!@#$%^&*()_+" SignatureDevice</h3>
		<p>NetcaJCE签名，NetcaProvider验签</p>
		<hr>
        <div>
			<div>
				<%	//签名
					//SM2
					String[] Algo={"SM3withSM2","1.2.156.10197.1.501"};
					
					String str="";  
					File file=new File(request.getRealPath("/")+"clear.txt");  
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
					
					for(int i=0; i<Algo.length; i++){
						System.out.println(Algo[i]);
						Signature signObj =Signature.getInstance(Algo[i],"NetcaJCE"); 
						
						//获取私钥
						KeyStore ks = KeyStore.getInstance("NETCA-DEVICE");
						ks.load(null,null);
						PrivateKey privKey=(PrivateKey)ks.getKey("4#4B43353230066062#275357A4-B3B3-419D-8738-29760F890F8F#S","12345678".toCharArray());

						signObj.initSign(privKey); 
						signObj.update(str.getBytes("UTF-8"));	
								

						byte[] result=signObj.sign();	
						try { 
							FileOutputStream fos = new FileOutputStream(new File(request.getRealPath("/")+"Sign/"+Algo[i]+"_sign.txt"));    
							fos.write(result);  
							fos.close();  
						} catch (Exception e) {  
							// TODO Auto-generated catch block  
							e.printStackTrace();  
						}
				%>
						<p><%=Algo[i]%> : </p>
						<p>output : <%=request.getRealPath("/")+"Sign\\"+Algo[i]+"_sign.txt"%></p>
						<p>sign (Base64) : <%=encode.encode(result)%></p>


			</div>
			<div>
				<%	//验签
						Signature verifyObj =Signature.getInstance(Algo[i],"NetcaProvider"); 
						
						//获取证书
						CertificateFactory cf=CertificateFactory.getInstance("X.509");
						FileInputStream fIn=new FileInputStream(new File(request.getRealPath("/")+"SM2_sign.cer"));
						X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
						fIn.close();

						verifyObj.initVerify(certObj); 
						verifyObj.update(str.getBytes("UTF-8"));	
								
						boolean verifyResult=verifyObj.verify(result);	
				%>
						<p style="color:red;">verify : <%=verifyResult%></p>
						<hr>
					<%}%>

			</div>
        </div>
    </div>
</body>

</html>