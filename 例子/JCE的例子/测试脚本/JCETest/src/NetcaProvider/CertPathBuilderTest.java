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
public class CertPathBuilderTest {
    public static void main (String args[]){
        System.out.println("NetcaProvider-CertPathBuilder");
        //构造证书路径
	String[] arg=new String[]{"src/source/SM2_enc.cer","src/source/SM2_CA01.cer","src/source/SM2_ROOTCA.cer"};
        try{
            CertificateFactory cf = CertificateFactory.getInstance("X.509","NetcaProvider");
            int i;
            List certCol = new ArrayList();
            for (i=0; i<arg.length; i++){
                    FileInputStream in=new FileInputStream(arg[i]);
                    X509Certificate c=(X509Certificate)cf.generateCertificate(in);
                    certCol.add(c);
            }

            CertPathBuilder pathBuilder = CertPathBuilder.getInstance("PKIX","NetcaProvider");
            X509CertSelector selector = new X509CertSelector();
            selector.setCertificate((X509Certificate)certCol.get(0));

            //设置锚点
            String trustAnchor = "src/source/SM2_ROOTCA.cer"; 
            FileInputStream in=new FileInputStream(trustAnchor);  
            X509Certificate trust=(X509Certificate)cf.generateCertificate(in);  
            // Create TrustAnchor  
            TrustAnchor anchor = new TrustAnchor( (X509Certificate)trust,null);

            CertStore certStore = CertStore.getInstance("Collection", new CollectionCertStoreParameters(certCol));

            PKIXBuilderParameters params = new PKIXBuilderParameters(Collections.singleton(anchor),selector);

            params.addCertStore(certStore);
            params.setRevocationEnabled(false);
            CertPath path = pathBuilder.build(params).getCertPath();
            System.out.println("构造证书路径：\n" + path);
        
            //验证证书路径
            PKIXParameters PKIXparams = new PKIXParameters(Collections.singleton(anchor));  
            PKIXparams.setRevocationEnabled(false);  
            CertPathValidator cpv = CertPathValidator.getInstance("PKIX","NetcaProvider");  
            PKIXCertPathValidatorResult result = null;
            result =(PKIXCertPathValidatorResult) cpv.validate(path, PKIXparams);  
            System.out.println("验证证书路径：\n" + result);  
            //System.out.println("trustAnchor：" + result.getTrustAnchor()); 
            
        } catch (Exception e) {  
            // TODO Auto-generated catch block  
            e.printStackTrace();  
        }
    }
   
}


