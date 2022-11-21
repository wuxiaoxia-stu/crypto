<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="javax.crypto.*,javax.crypto.spec.*,java.security.*,java.io.*,java.security.cert.*,sun.misc.BASE64Encoder" %>



<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Signature</title>
</head>
<style>
p{
	word-wrap:break-word;
}
</style>
<body>
    <div class="container" id="container">
        <h3>"中1Aa~!@#$%^&*()_+" Signature</h3>
		<div>
			<div>
				<%	//签名
					//RSA
					//String[] Algo={"MD5withRSA","1.2.840.113549.1.1.4","SHA1withRSA","1.2.840.113549.1.1.5","SHA224withRSA","1.2.840.113549.1.1.14","SHA256withRSA","1.2.840.113549.1.1.11","SHA384withRSA","1.2.840.113549.1.1.12","SHA512withRSA","1.2.840.113549.1.1.13","SM3withRSA","1.2.156.10197.1.504","NONEwithRSA","SHA512_224withRSA","1.2.840.113549.1.1.15","SHA512_256withRSA","1.2.840.113549.1.1.16","SHA3_224withRSA","2.16.840.1.101.3.4.3.13","SHA3_256withRSA","2.16.840.1.101.3.4.3.14","SHA3_384withRSA","2.16.840.1.101.3.4.3.15","SHA3_512withRSA","2.16.840.1.101.3.4.3.16"};
					//ECDSA
					//String[] Algo={"SHA1withECDSA","1.2.840.10045.4.1","SHA256withECDSA","1.2.840.10045.4.3.2","SHA3_256withECDSA"};
					//String[] Algo={"SHA1withECDSA","1.2.840.10045.4.1","SHA224withECDSA","1.2.840.10045.4.3.1","SHA256withECDSA","1.2.840.10045.4.3.2","SHA384withECDSA","1.2.840.10045.4.3.3","SHA512withECDSA","1.2.840.10045.4.3.4","NONEwithECDSA","SHA3_224withECDSA","2.16.840.1.101.3.4.3.9","SHA3_256withECDSA","2.16.840.1.101.3.4.3.10","SHA3_384withECDSA","2.16.840.1.101.3.4.3.11","SHA3_512withECDSA","2.16.840.1.101.3.4.3.12"};
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
						InputStream inputStream = new FileInputStream(new File(request.getRealPath("/")+"sm2_keystore.json"));
						KeyStore ks = KeyStore.getInstance("NETCA-JSON");
						ks.load(inputStream,null);
						PrivateKey privKey=(PrivateKey)ks.getKey("tomcat","12345678".toCharArray());

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
						Signature verifyObj =Signature.getInstance(Algo[i],"NetcaJCE"); 
						
						//获取证书
						CertificateFactory cf=CertificateFactory.getInstance("X.509");
						FileInputStream fIn=new FileInputStream(new File(request.getRealPath("/")+"sm2_cert.cer"));
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