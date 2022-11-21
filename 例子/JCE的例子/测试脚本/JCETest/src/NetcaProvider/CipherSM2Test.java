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
public class CipherSM2Test {
    public static void main (String args[]){
        System.out.println("Cipher-SM2");
	//加密
        String[] Algo={"SM2/ECB/NOPADDING"};

        String str="";  
        String filePath="src/source/clearCipher.txt";
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
        System.out.println("NetcaProvider加密，NetcaJCE解密");
        for(int i=0; i<Algo.length; i++){
            try {

                //获取证书
                CertificateFactory cf=CertificateFactory.getInstance("X.509","NetcaProvider");
                FileInputStream fIn=new FileInputStream(new File("src/source/sm2_cert.cer"));
                X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                fIn.close();


                //初始化密码器Cipher
                Cipher cipher=Cipher.getInstance(Algo[i],"NetcaProvider");
                cipher.init(Cipher.ENCRYPT_MODE,certObj);

                byte[] result = cipher.doFinal(str.getBytes());

                try { 
                        FileOutputStream fos = new FileOutputStream(new File("src/Cipher/"+Algo[i].replace("/", "_")+"_Cipher_Provider.txt"));    
                        fos.write(result);  
                        fos.close();  
                } catch (Exception e) {  
                        // TODO Auto-generated catch block  
                        e.printStackTrace();  
                }
                
                //解密
                //解密
                InputStream inputStream = new FileInputStream(new File("src/source/sm2_keystore.json"));
                
                //获取私钥
                KeyStore ks = KeyStore.getInstance("NETCA-JSON");
                ks.load(inputStream,null);
                PrivateKey privKey=(PrivateKey)ks.getKey("tomcat","12345678".toCharArray());
                
                cipher=Cipher.getInstance(Algo[i],"NetcaJCE");
                cipher.init(Cipher.DECRYPT_MODE,privKey);
                byte[] decryptResult = cipher.doFinal(result);
                String printDecryptResult=new String(decryptResult); 
                
                
                String verify = "False";
                if(printDecryptResult.equals(str)==true){
                    verify = "True";
                }
                
                System.out.println((i+1)+") "+Algo[i]+" : ");
                System.out.println("output : src/Cipher/"+Algo[i].replace("/", "_")+"_Cipher_Provider.txt");
                System.out.println("verify : " + verify);
                //System.out.println("key : "+new String(raw));
                //System.out.println("key(HEX) : "+TestTool.toHexString(raw));
                //System.out.println("IV : "+new String(iv));
                //System.out.println("IV(HEX) : "+TestTool.toHexString(iv));
                //System.out.println("encrypt (Base64) : "+encode.encode(result));
                //System.out.println("decrypt : "+printDecryptResult);
                //System.out.println("NetcaJCE : "+printResult);
                 
            } catch (Exception e) {
               System.out.println((i+1)+") "+Algo[i]+" : False");
               e.printStackTrace(); 
            } 
                                         
        }
      
    }
    
}


