import net.netca.pki.encoding.asn1.pki.*;
import net.netca.pki.encoding.asn1.pki.cms.*;

import java.io.*;
import java.util.Iterator;

public class SM2SignedDataSign {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=3) {
            System.out.println("Usage: java SM2SignedDataSign cert inFile outFile");
            return;
        }


        FileInputStream fIn=null;
        FileOutputStream fOut=null;
        byte [] in=new byte[8192];
        int len;
        X509Certificate cert=null;
        SignedData sign=null;
        SignedDataBuilder builder=null;
        Signer signer=null;
        NetcaMyStore store=null;
        NetcaHasher hasher=null;
        File f;
        try {

        	builder=new  SignedDataBuilder();
        	builder.setIncludeSignCert(true);
        	builder.setDetached(false);
			builder.setSM2Q7(true);
            
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new X509Certificate(in,0,len);
            fIn.close();
            fIn=null;
            
            store=new NetcaMyStore();
            signer=createSigner(cert,store);
            builder.addSigner(signer);
            
            hasher=new NetcaHasher();
            builder.setHasher(hasher);
            
            f=new File(arg[1]);
            if(f.length()>java.lang.Integer.MAX_VALUE) {
            	System.out.println("ÎÄ¼þÌ«´ó");
                return;
            }
            in=new byte[(int)f.length()];
            fIn=new FileInputStream(f);
            len=fIn.read(in);
            fIn.close();
            fIn=null;
            
            builder.setContent(in);
            
            sign=builder.sign();
            
            fOut=new FileOutputStream(arg[2]);
            fOut.write(sign.encode(true));
            System.out.println("Success");
        } finally {
            if(fIn!=null) {
                fIn.close();
            }

            if(fOut!=null) {
                fOut.close();
            }
            if(store!=null) {
            	store.free();
            }

            if(hasher!=null) {
            	hasher.free();
            }
        }

    }
    
    private static Signer createSigner(X509Certificate cert,NetcaMyStore store) throws Exception{
    	Signable signable=getSignable(store,cert);
    	if(signable==null) {
    		throw new Exception("no private key");
    	}
    	Signer signer=new Signer(cert,signable);
    	AlgorithmIdentifier algo=AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3WithSM2_OID);
    	signer.setSignatureAlgorithm(algo);
    	
    	Attribute attribute=new Attribute(Attribute.SIGNING_TIME,
    			(new Time(new java.util.Date())).getASN1Object());
    	signer.addSignedAttribute(attribute);
    	return signer;
    }
    
    private static Signable getSignable(NetcaMyStore store,X509Certificate cert)throws Exception{
    	Iterator it=store.iterator();
    	X509CertificateAndPrivateKey certAndPrivKey;
    	Signable signer=null;
    	while(it.hasNext()) {
    		certAndPrivKey=(X509CertificateAndPrivateKey)it.next();
    		if(certAndPrivKey.getCert().equals(cert)) {
    			signer=certAndPrivKey.getSigner();
    			if(signer!=null) {
    				return signer;
    			}
    		}
    	}
    	return null;
    }
}
