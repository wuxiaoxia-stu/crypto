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
    <title>Cipher-ECB</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
        <h3>"中1Aa~!@#$%^&*(" Cipher-ECB</h3>
		<h3>对称加解密</h3>
		<div>
			<div>
				<%	//加密
					String[] Algo={"RC2/ECB/NOPADDING","RC2/ECB/PKCS5PADDING","RC2/ECB/PKCS7PADDING","DES/ECB/NOPADDING","DES/ECB/PKCS5PADDING","DES/ECB/PKCS7PADDING","DESEDE/ECB/NOPADDING","DESEDE/ECB/PKCS5PADDING","DESEDE/ECB/PKCS7PADDING","AES/ECB/NOPADDING","AES/ECB/PKCS5PADDING","AES/ECB/PKCS7PADDING","AES_128/ECB/NOPADDING","AES_128/ECB/PKCS5PADDING","AES_128/ECB/PKCS7PADDING","AES_192/ECB/NOPADDING","AES_192/ECB/PKCS5PADDING","AES_192/ECB/PKCS7PADDING","AES_256/ECB/NOPADDING","AES_256/ECB/PKCS5PADDING","AES_256/ECB/PKCS7PADDING","SM4/ECB/NOPADDING","SM4/ECB/PKCS5PADDING","SM4/ECB/PKCS7PADDING"};
					String[] keyAlgo={"RC2","RC2","RC2","DES","DES","DES","DESEDE","DESEDE","DESEDE","AES","AES","AES","AES","AES","AES","AES","AES","AES","AES","AES","AES","SM4","SM4","SM4"};
					//取决于密钥长度(与位数对应)
					int[] keyLen={64,64,64,64,64,64,192,192,192,128,128,128,128,128,128,192,192,192,256,256,256,128,128,128};
					byte [] RAW={(byte)0x30,(byte)0x31,(byte)0x32,(byte)0x33,(byte)0x34,(byte)0x35,(byte)0x36,(byte)0x37,(byte)0x38,(byte)0x39,(byte)0x61,(byte)0x62,(byte)0x63,(byte)0x64,(byte)0x65,(byte)0x66,(byte)0x67,(byte)0x68,(byte)0x69,(byte)0x6a,(byte)0x6b,(byte)0x6c,(byte)0x6d,(byte)0x6e,(byte)0x6f,(byte)0x70,(byte)0x71,(byte)0x72,(byte)0x73,(byte)0x74,(byte)0x75,(byte)0x76}; 
					
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
					
					for(int i=0; i<Algo.length; i++){
						System.out.println(i+1);
						System.out.println(keyAlgo[i]);
						System.out.println(Algo[i]);
						
						byte[] raw = new byte[keyLen[i]/8];
						System.arraycopy(RAW, 0, raw, 0, keyLen[i]/8); 
						
						//根据字节数组生成AES密钥 
						SecretKeySpec keySpec=new SecretKeySpec(raw, keyAlgo[i]);
						
						//初始化密码器Cipher
						Cipher cipher=Cipher.getInstance(Algo[i],"NetcaJCE");
						cipher.init(Cipher.ENCRYPT_MODE,keySpec);
						
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
						cipher.init(Cipher.DECRYPT_MODE,keySpec);
						byte[] decryptResult = cipher.doFinal(result);
						String printDecryptResult=new String(decryptResult,"UTF-8");  
				%>
						<strong><%=i+1%>. <%=Algo[i]%> : </strong>
						<p>output : <%=request.getRealPath("/")+"Cipher\\"+Algo[i].replace("/", "_")+"_cipher.txt"%></p>
						<p>key : <%=new String(raw)%></p>
						<p>key(HEX) : <%=TestTool.toHexString(raw)%></p>
						<p>encrypt(Base64) : <%=encode.encode(result)%></p>
						<p>decrypt : <%=printDecryptResult%></p>
						<hr>


			</div>
			
					<%}%>
			
        </div>
    </div>
</body>

</html>