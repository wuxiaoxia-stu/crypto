/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NetcaProvider;
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
public class SignatureTest {
    public static void main (String args[]){
        System.out.println("NetcaProvider-Signature");
	//签名
        //SM2
        String[] Algo={"SM3withSM2","1.2.156.10197.1.501"};

				
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
        
        System.out.println("原文路径 ："+filePath);
        //System.out.println("原文："+str);
        System.out.println("算法个数 ："+Algo.length);
        System.out.println("NetcaJCE签名，NetcaProvider验签");
        for(int i=0; i<Algo.length; i++){
            try {
                //签名
                Signature signObj =Signature.getInstance(Algo[i],"NetcaJCE"); 
						
                //获取私钥
                InputStream inputStream = new FileInputStream(new File("src/source/sm2_keystore.json"));
                KeyStore ks = KeyStore.getInstance("NETCA-JSON");
                ks.load(inputStream,null);
                PrivateKey privKey=(PrivateKey)ks.getKey("tomcat","12345678".toCharArray());

                signObj.initSign(privKey); 
                signObj.update(str.getBytes("UTF-8"));	


                byte[] result=signObj.sign();	

                try { 
                    FileOutputStream fos = new FileOutputStream(new File("src/Signature/"+Algo[i]+"_Signature_Provider.txt"));     
                    fos.write(result);  
                    fos.close();  
                } catch (Exception e) {  
                    // TODO Auto-generated catch block  
                    e.printStackTrace();  
                }
                System.out.println((i+1)+") "+Algo[i]+" : ");
                System.out.println("output : src/Signature/"+Algo[i]+"_Signature_Provider.txt");
                //System.out.println("sign (Base64) : "+encode.encode(result));
                //System.out.println("NetcaJCE : "+printResult);
            
                //验签
                Signature verifyObj =Signature.getInstance(Algo[i],"NetcaProvider"); 

                //获取证书
                CertificateFactory cf=CertificateFactory.getInstance("X.509");
                FileInputStream fIn=new FileInputStream(new File("src/source/sm2_cert.cer"));
                X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                fIn.close();

                verifyObj.initVerify(certObj); 
                verifyObj.update(str.getBytes("UTF-8"));	

                boolean verifyResult=verifyObj.verify(result);	
                 System.out.println("verify : "+verifyResult);
                 
                 
            } catch (Exception e) {
               System.out.println((i+1)+") "+Algo[i]+" : False");
               e.printStackTrace(); 
            } 
                                         
        }
      
    }
   
}


