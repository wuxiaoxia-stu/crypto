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


/**
 *
 * @author Administrator
 */
public class MessageDigestTest {
    public static void main (String args[]){
        System.out.println("NetcaProvider-MessageDigest");
        String[] Algo={"SM3","1.2.156.10197.1.401"};
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
                MessageDigest md= MessageDigest.getInstance(Algo[i],"NetcaProvider");
                md.update(str.getBytes());
                byte[] result=md.digest();
                String printResult=toHexString(result);  
                
                if(i==0){
                    MessageDigest mdBC= MessageDigest.getInstance(Algo[i],"BC");
                    mdBC.update(str.getBytes());
                    byte[] resultBC=mdBC.digest();
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
                    if(printResult.equals("f7dff4040fb4e73029bac2e871d93faba59c70feb4974763f317f819bffc0f62")==true){
                        match = "True";
                    }
                    System.out.println((i+1)+") "+Algo[i]+" : ");
                    //System.out.println("NetcaJCE : "+printResult);
                    System.out.println("【CryptoTestTool】 match : " + match);
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


