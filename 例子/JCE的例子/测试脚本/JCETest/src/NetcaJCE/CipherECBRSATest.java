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
public class CipherECBRSATest {
    public static void main (String args[]){
        System.out.println("Cipher-RSA/ECB");
	//加密
        String[] Algo={"RSA/ECB/NOPADDING","RSA/ECB/PKCS1PADDING"};
        String[] keyAlgo={"RSA","RSA"};
        System.out.println("算法个数 ："+Algo.length);
        for(int i=0; i<Algo.length; i++){
            String filePath="";
            if(i==0){
                //RSA_NOPADDING填充模式要求:输入必须与RSA密钥长度相同,NetcaJCE仅处理补全到RSA模长（字节数）的数据，不够长自己前面补0
                filePath="src/source/clearCipherRSA2048-255.txt";
            }
            else{
                //RSA_PKCS1PADDING填充模式要求:输入必须比RSA密钥长度短至少11个字节
                filePath="src/source/clearCipher.txt";
            }

            String str="";  
            File file=new File(filePath);  
            //2M文件
            //File file=new File("src/source/2Mclear.txt");
            
            BASE64Encoder encode = new BASE64Encoder();
            try {  
                    FileInputStream in=new FileInputStream(file);  
                    // size  为字串的长度 ，这里一次性读完  
                    int size=in.available();  
                    if(i==0){
                        byte[] buffer=new byte[256];  
                        in.read(buffer,256-size,size); 
                        in.close();  
                        str=new String(buffer);
                    }
                    else{
                        byte[] buffer=new byte[size];  
                        in.read(buffer); 
                        in.close();  
                        str=new String(buffer);
                    }
                      
            } catch (IOException e) {  
                    // TODO Auto-generated catch block  
                    e.printStackTrace();  
            }  
            //System.out.println("原文："+str);
                              
        
            try {

                //获取证书
                CertificateFactory cf=CertificateFactory.getInstance("X.509");
                FileInputStream fIn=new FileInputStream(new File("src/source/rsa_cert.cer"));
                X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                fIn.close();


                //初始化密码器Cipher
                Cipher cipher=Cipher.getInstance(Algo[i],"NetcaJCE");
                cipher.init(Cipher.ENCRYPT_MODE,certObj);

                byte[] result = cipher.doFinal(str.getBytes());

                try { 
                        FileOutputStream fos = new FileOutputStream(new File("src/Cipher/["+(i+1)+"]"+Algo[i].replace("/", "_")+"_Cipher.txt"));    
                        fos.write(result);  
                        fos.close();  
                } catch (Exception e) {  
                        // TODO Auto-generated catch block  
                        e.printStackTrace();  
                }
                
                //解密
                //获取私钥
                
                InputStream inputStream = new FileInputStream(new File("src/source/rsa_keystore.json"));
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
                System.out.println("原文路径 ："+filePath);
                //System.out.println("原文 ："+toHexString(str.getBytes()));
                System.out.println("output : src/Cipher/["+(i+1)+"]"+Algo[i].replace("/", "_")+"_Cipher.txt");
                System.out.println("【NetcaJCE加密】verify : " + verify);
                //System.out.println("原文 : " + str);
                //System.out.println("解密 : " + printDecryptResult);
                //System.out.println("key : "+new String(raw));
                //System.out.println("key(HEX) : "+TestTool.toHexString(raw));
                //System.out.println("IV : "+new String(iv));
                //System.out.println("IV(HEX) : "+TestTool.toHexString(iv));
                //System.out.println("encrypt (Base64) : "+encode.encode(result));
                //System.out.println("decrypt : "+printDecryptResult);
                //System.out.println("NetcaJCE : "+printResult);

                
            } catch (Exception e) {
               System.out.println((i+1)+") "+Algo[i]+" : False");
               System.out.println("原文路径 ："+filePath);
               e.printStackTrace(); 
            } 
            
            try {

                //获取证书
                CertificateFactory cf=CertificateFactory.getInstance("X.509");
                FileInputStream fIn=new FileInputStream(new File("src/source/rsa_cert.cer"));
                X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                fIn.close();


                //初始化密码器Cipher
                Cipher cipherbc=Cipher.getInstance(Algo[i],"BC");
                cipherbc.init(Cipher.ENCRYPT_MODE,certObj);

                byte[] resultbc = cipherbc.doFinal(str.getBytes());

                
                //解密
                //获取私钥
                
                InputStream inputStream = new FileInputStream(new File("src/source/rsa_keystore.json"));
                KeyStore ks = KeyStore.getInstance("NETCA-JSON");
                ks.load(inputStream,null);
                PrivateKey privKey=(PrivateKey)ks.getKey("tomcat","12345678".toCharArray());
                
                cipherbc=Cipher.getInstance(Algo[i],"NetcaJCE");
                cipherbc.init(Cipher.DECRYPT_MODE,privKey);
                byte[] decryptResult = cipherbc.doFinal(resultbc);
                String printDecryptResult=new String(decryptResult); 
                
                
                String verify = "False";
                if(printDecryptResult.equals(str)==true){
                    verify = "True";
                }

                System.out.println("【BC加密】verify : " + verify);
                //System.out.println("原文 : " + str);
                //System.out.println("解密 : " + printDecryptResult);
                 
            } catch (Exception e) {
               System.out.println("【BC加密】 : False");
               e.printStackTrace(); 
            } 
                                         
        }
      
    }
    
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


