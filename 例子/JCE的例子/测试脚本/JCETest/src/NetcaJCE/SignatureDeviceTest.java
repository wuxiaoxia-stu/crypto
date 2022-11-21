/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NetcaJCE;
import javax.crypto.*;
import javax.crypto.spec.*;
import java.security.*;
import java.io.*;
import java.security.cert.*;
import sun.misc.BASE64Encoder;

/**
 *
 * @author Administrator
 */
public class SignatureDeviceTest {
    public static void main (String args[]){
        System.out.println("NetcaJCE-SignatureDevice");
	//RSA
        String[] Algo={"MD5withRSA","1.2.840.113549.1.1.4","SHA1withRSA","1.2.840.113549.1.1.5","SHA224withRSA","1.2.840.113549.1.1.14","SHA256withRSA","1.2.840.113549.1.1.11","SHA384withRSA","1.2.840.113549.1.1.12","SHA512withRSA","1.2.840.113549.1.1.13","SM3withRSA","1.2.156.10197.1.504","NONEwithRSA","SHA512_224withRSA","1.2.840.113549.1.1.15","SHA512_256withRSA","1.2.840.113549.1.1.16","SHA3_224withRSA","2.16.840.1.101.3.4.3.13","SHA3_256withRSA","2.16.840.1.101.3.4.3.14","SHA3_384withRSA","2.16.840.1.101.3.4.3.15","SHA3_512withRSA","2.16.840.1.101.3.4.3.16"};
        //SM2
        //String[] Algo={"SM3withSM2","1.2.156.10197.1.501"};
				
        String str="";  
        String filePath="src/source/clear.txt";
        File file=new File(filePath); 
         
        //2M文件
        //File file=new File("src/source/2Mclear.txt");
        BASE64Encoder encode = new BASE64Encoder();
        try {  
                FileInputStream in=new FileInputStream(file);  
                // size  为字串的长度 ，这里一次性读完  
                int size=in.available();  
                byte[] buffer=new byte[size];  
                in.read(buffer);  
                in.close();  
                str=new String(buffer);  
        } catch (IOException e) {  
                // TODO Auto-generated catch block  
                e.printStackTrace();  
        }  
        String clear=str;
        
        System.out.println("原文路径 ："+filePath);
        //System.out.println("原文："+str);
        System.out.println("算法个数 ："+Algo.length);
        for(int i=0; i<Algo.length; i++){
            str=clear;
            
            if(Algo[i].equals("NONEwithRSA")){
                //"123456"的Hash值
                //md5(32):e10adc3949ba59abbe56e057f20f883e
                //sha1(40):7c4a8d09ca3762af61e59520943dc26494f8941b
                //sha256(64):8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92
                str="e10adc3949ba59abbe56e057f20f883e";
            }
            try {
                //签名
                Signature signObj =Signature.getInstance(Algo[i],"NetcaJCE"); 
						
                //获取私钥
                KeyStore ks = KeyStore.getInstance("NETCA-DEVICE");
                ks.load(null,null);
                //RSA
                PrivateKey privKey=(PrivateKey)ks.getKey("7#0616700742062E37#0BE9BBF3-5988-44DC-8CEA-07D6B59E7F94#S","12345678".toCharArray());
                //SM2
                //PrivateKey privKey=(PrivateKey)ks.getKey("4#4B43353230066062#275357A4-B3B3-419D-8738-29760F890F8F#S","12345678".toCharArray());


                signObj.initSign(privKey); 
                signObj.update(str.getBytes());	
                
                byte[] result=signObj.sign();	

                try { 
                        FileOutputStream fos = new FileOutputStream(new File("src/Signature/["+(i+1)+"]"+Algo[i]+"_SignatureDevice.txt"));    
                        fos.write(result);  
                        fos.close();  
                } catch (Exception e) {  
                        // TODO Auto-generated catch block  
                        e.printStackTrace();  
                }
                System.out.println((i+1)+") "+Algo[i]+" : ");
                if(Algo[i].equals("NONEwithECDSA")||Algo[i].equals("NONEwithRSA")){
                    System.out.println("传入Hash值（\"123456\"的MD5值）："+ str);
                }
                System.out.println("output : src/Signature/["+(i+1)+"]"+Algo[i]+"_SignatureDevice.txt");
                //System.out.println("sign (Base64) : "+encode.encode(result));
                //System.out.println(str);
            
                //验签
                Signature verifyObj=null;
                //RSA
                if(Algo.length==27){
                    if(i!=12&&i!=13&&i!=15&&i!=17&&i!=19&&i!=21&&i!=23&&i!=25){
                        verifyObj =Signature.getInstance(Algo[i],"NetcaJCE"); 

                        //获取证书
                        CertificateFactory cf=CertificateFactory.getInstance("X.509");
                        FileInputStream fIn=new FileInputStream(new File("src/source/RSA_sign.cer"));
                        X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                        fIn.close();

                        verifyObj.initVerify(certObj); 
                        verifyObj.update(str.getBytes());	

                        boolean verifyResult=verifyObj.verify(result);
                        System.out.println("【NetcaJCE】verify : "+verifyResult);
                        
                        verifyObj =Signature.getInstance(Algo[i],"BC"); 
                        verifyObj.initVerify(certObj); 
                        verifyObj.update(str.getBytes());	

                        verifyResult=verifyObj.verify(result);
                        System.out.println("【BC】verify : "+verifyResult);
                    }
                    else{
                        verifyObj =Signature.getInstance(Algo[i],"NetcaJCE"); 
                        //获取证书
                        CertificateFactory cf=CertificateFactory.getInstance("X.509");
                        FileInputStream fIn=new FileInputStream(new File("src/source/RSA_sign.cer"));
                        X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                        fIn.close();

                        verifyObj.initVerify(certObj); 
                        verifyObj.update(str.getBytes());	

                        boolean verifyResult=verifyObj.verify(result);
                         System.out.println("【NetcaJCE】verify : "+verifyResult);
                    }
                }
                //SM2
                else{
                    if(true){
                        verifyObj =Signature.getInstance(Algo[i],"NetcaJCE"); 

                        //获取证书
                        CertificateFactory cf=CertificateFactory.getInstance("X.509");
                        FileInputStream fIn=new FileInputStream(new File("src/source/SM2_sign.cer"));
                        X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                        fIn.close();

                        verifyObj.initVerify(certObj); 
                        verifyObj.update(str.getBytes());	

                        boolean verifyResult=verifyObj.verify(result);
                        System.out.println("【NetcaJCE】verify : "+verifyResult);
                        
                        verifyObj =Signature.getInstance(Algo[i],"BC"); 
                        verifyObj.initVerify(certObj); 
                        verifyObj.update(str.getBytes());	

                        verifyResult=verifyObj.verify(result);
                        System.out.println("【BC】verify : "+verifyResult);
                    }
                    else{
                        verifyObj =Signature.getInstance(Algo[i],"NetcaJCE"); 
                        //获取证书
                        CertificateFactory cf=CertificateFactory.getInstance("X.509");
                        FileInputStream fIn=new FileInputStream(new File("src/source/SM2_sign.cer"));
                        X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                        fIn.close();

                        verifyObj.initVerify(certObj); 
                        verifyObj.update(str.getBytes());	

                        boolean verifyResult=verifyObj.verify(result);
                         System.out.println("【NetcaJCE】verify : "+verifyResult);
                    }
                }
                 
                 
            } catch (Exception e) {
               System.out.println((i+1)+") "+Algo[i]+" : False");
               e.printStackTrace(); 
            } 
                                         
        }
      
    }
   
}


