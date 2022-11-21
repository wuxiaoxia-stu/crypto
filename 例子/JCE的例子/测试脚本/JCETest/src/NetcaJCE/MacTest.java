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


/**
 *
 * @author Administrator
 */
public class MacTest {
    public static void main (String args[]){
        System.out.println("NetcaJCE-Mac");
        //net.netca.pki.jce.NetcaJCEProvider.mac.enabled="off";
        String[] Algo={"HMACMD5","HMACSHA1","1.2.840.113549.2.7","HMACSHA224","1.2.840.113549.2.8","HMACSHA256","1.2.840.113549.2.9","HMACSHA384","1.2.840.113549.2.10","HMACSHA512","1.2.840.113549.2.11","HMACSM3","HMACSHA512/224","HMACSHA512/256","HMACSHA3-224","2.16.840.1.101.3.4.2.13","HMACSHA3-256","2.16.840.1.101.3.4.2.14","HMACSHA3-384","2.16.840.1.101.3.4.2.15","HMACSHA3-512","2.16.840.1.101.3.4.2.16"};
        String str="";  
        String filePath="src/source/clear.txt";
        File file=new File(filePath);  
        //2M文件
        //File file=new File("src/source/2Mclear.txt");  
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
                Mac mac= Mac.getInstance(Algo[i],"NetcaJCE");
                SecretKeySpec keySpec=new SecretKeySpec(new byte[]{(byte)0x31,(byte)0x32,(byte)0x33,(byte)0x34,(byte)0x35,(byte)0x36,(byte)0x37,(byte)0x38},Algo[i]);
                
                mac.init(keySpec);
                mac.update(str.getBytes());
                byte[] result=mac.doFinal();
                String printResult=toHexString(result);
                
                
                
                //BC
                if(i!=11){
                    Mac macBC= Mac.getInstance(Algo[i],"BC");
                    macBC.init(keySpec);
                    macBC.update(str.getBytes());
                    byte[] resultBC=macBC.doFinal();
                    String printResultBC=toHexString(resultBC);
                    String match = "False";
                    if(printResult.equals(printResultBC)==true){
                        match = "True";
                    }
                    System.out.println((i+1)+") "+Algo[i]+" : ");
                    System.out.println("【BC】match : "+match);
                    
                    //System.out.println("NetcaJCE : "+printResult);
                    //System.out.println("BC : "+printResultBC);
                }
                else{
                    String match = "False";
                    if(printResult.equals("3b3f2a5300388e01b0ae5a1c018a4abed546c17c76694835c72a344580b25473")==true){
                        match = "True";
                    }
                    System.out.println((i+1)+") "+Algo[i]+" : ");
                    //System.out.println("NetcaJCE : "+printResult);
                    System.out.println("【CryptoTestTool】match : " + match);
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


