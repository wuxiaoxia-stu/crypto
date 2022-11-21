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
import java.util.*;

/**
 *
 * @author Administrator
 */
public class CertificateFactoryTest {
    public static void main (String args[]){
        System.out.println("NetcaProvider-CertificateFactory");
        //解析公钥证书
	String[] certArray={"X.509","X509"};
        System.out.println("算法个数 ："+certArray.length);
        try{
            for(int i=0; i<certArray.length; i++){
                //获取证书
                CertificateFactory cf=CertificateFactory.getInstance(certArray[i],"NetcaProvider");
                FileInputStream fIn=new FileInputStream(new File("src/source/SM2_enc.cer"));
                X509Certificate certObj=(X509Certificate)cf.generateCertificate(fIn);
                fIn.close();
                
                System.out.println((i+1)+") "+certArray[i]);
                System.out.println("版本号 ： "+certObj.getVersion());
                System.out.println("序列号 ： "+certObj.getSerialNumber().toString(16));
                System.out.println("全名 ： "+certObj.getSubjectDN());
                System.out.println("签发者全名 ： "+certObj.getIssuerDN());
                System.out.println("有效期起始日 ： "+certObj.getNotBefore());
                System.out.println("有效期截至日 ： "+certObj.getNotAfter());
                System.out.println("签名算法 ： "+certObj.getSigAlgName());
                
            }
            
        } catch (Exception e) {  
            // TODO Auto-generated catch block  
            e.printStackTrace();  
        }
    }
    
}


