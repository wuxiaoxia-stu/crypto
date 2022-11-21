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
public class CipherECBTest {
    public static void main (String args[]){
        System.out.println("Cipher-ECB");
	//加密
        String[] Algo={"RC4/ECB/NOPADDING","RC2/ECB/NOPADDING","RC2/ECB/PKCS5PADDING","RC2/ECB/PKCS7PADDING","DES/ECB/NOPADDING","DES/ECB/PKCS5PADDING","DES/ECB/PKCS7PADDING","DESEDE/ECB/NOPADDING","DESEDE/ECB/PKCS5PADDING","DESEDE/ECB/PKCS7PADDING","AES/ECB/NOPADDING","AES/ECB/PKCS5PADDING","AES/ECB/PKCS7PADDING","AES_128/ECB/NOPADDING","AES_128/ECB/PKCS5PADDING","AES_128/ECB/PKCS7PADDING","AES_192/ECB/NOPADDING","AES_192/ECB/PKCS5PADDING","AES_192/ECB/PKCS7PADDING","AES_256/ECB/NOPADDING","AES_256/ECB/PKCS5PADDING","AES_256/ECB/PKCS7PADDING","SM4/ECB/NOPADDING","SM4/ECB/PKCS5PADDING","SM4/ECB/PKCS7PADDING"};
        String[] keyAlgo={"RC4","RC2","RC2","RC2","DES","DES","DES","DESEDE","DESEDE","DESEDE","AES","AES","AES","AES","AES","AES","AES","AES","AES","AES","AES","AES","SM4","SM4","SM4"};
        //取决于密钥长度(与位数对应)
        int[] keyLen={64,64,64,64,64,64,64,192,192,192,128,128,128,128,128,128,192,192,192,256,256,256,128,128,128};
        byte [] RAW={(byte)0x30,(byte)0x31,(byte)0x32,(byte)0x33,(byte)0x34,(byte)0x35,(byte)0x36,(byte)0x37,(byte)0x38,(byte)0x39,(byte)0x61,(byte)0x62,(byte)0x63,(byte)0x64,(byte)0x65,(byte)0x66,(byte)0x67,(byte)0x68,(byte)0x69,(byte)0x6a,(byte)0x6b,(byte)0x6c,(byte)0x6d,(byte)0x6e,(byte)0x6f,(byte)0x70,(byte)0x71,(byte)0x72,(byte)0x73,(byte)0x74,(byte)0x75,(byte)0x76}; 

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
        for(int i=0; i<Algo.length; i++){
            try {

                byte[] raw = new byte[keyLen[i]/8];
                System.arraycopy(RAW, 0, raw, 0, keyLen[i]/8); 

                //根据字节数组生成AES密钥 
                SecretKeySpec keySpec=new SecretKeySpec(raw, keyAlgo[i]);

                //初始化密码器Cipher
                Cipher cipher=Cipher.getInstance(Algo[i],"NetcaJCE");
                cipher.init(Cipher.ENCRYPT_MODE,keySpec);

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
                cipher=Cipher.getInstance(Algo[i],"NetcaJCE");
                cipher.init(Cipher.DECRYPT_MODE,keySpec);
                byte[] decryptResult = cipher.doFinal(result);
                String printDecryptResult=new String(decryptResult);	
                String verify = "False";
                if(printDecryptResult.equals(str)==true){
                    verify = "True";
                }
                
                System.out.println((i+1)+") "+Algo[i]+" : ");
                System.out.println("output : src/Cipher/["+(i+1)+"]"+Algo[i].replace("/", "_")+"_Cipher.txt");
                System.out.println("key(HEX) : "+toHexString(raw));
                System.out.println("【NetcaJCE】verify : " + verify);
                //System.out.println("key : "+new String(raw));
                
                
                //System.out.println("encrypt (Base64) : "+encode.encode(result));
                //System.out.println("decrypt : "+printDecryptResult);
                //System.out.println("NetcaJCE : "+printResult);
                
                //BC
                if(i<=12||i>=22){
                    Cipher cipherBC=Cipher.getInstance(Algo[i],"BC");
                    cipherBC.init(Cipher.ENCRYPT_MODE,keySpec);

                    byte[] resultBC = cipherBC.doFinal(str.getBytes());
                    String match = "False";
                    if(new String(result).equals(new String(resultBC))==true){
                        match = "True";
                    }
                    System.out.println("【BC】match : " + match);
                
                }else{
                    System.out.println("No such algorithm for BC!" );
                }
            
            } catch (Exception e) {
               System.out.println((i+1)+") "+Algo[i]+" : False");
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


