import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Iterator;

import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.NetcaMyStore;
import net.netca.pki.encoding.asn1.pki.NetcaPublicKeyEncrypter;
import net.netca.pki.encoding.asn1.pki.NetcaSecureRandomGenerator;
import net.netca.pki.encoding.asn1.pki.NetcaSymEncrypter;
import net.netca.pki.encoding.asn1.pki.Signable;
import net.netca.pki.encoding.asn1.pki.X509Certificate;
import net.netca.pki.encoding.asn1.pki.X509CertificateAndPrivateKey;
import net.netca.pki.encoding.asn1.pki.cms.SignedAndEnvelopedDataBuilder;
import net.netca.pki.encoding.asn1.pki.cms.Signer;

public class CreateSM2SignedAndEnvelopedData {

	public static void main(String[] args) throws Exception{
		if(args.length!=4) {
            System.out.println("Usage: java CreateSM2SignedAndEnvelopedData enCert signCert infile outfile");
            return;
        }
		
		String encCertFileName=args[0];
		String signCertFileName=args[1];
		String inFileName=args[2];
		String outFileName=args[3];
		NetcaMyStore store=null;
		
		try{
			byte[] data= readFile(encCertFileName);
			X509Certificate encCert=new X509Certificate(data);
			
			data= readFile(signCertFileName);
			X509Certificate signCert=new X509Certificate(data);
			store=new NetcaMyStore();
			Signer signer=createSigner(signCert,store);
	        
			byte[] content=readFile(inFileName);
			
			
	        
			byte[] outData=SignedAndEnvelopedDataBuilder.getInstance()
					.addEncCert(encCert)
					.setIncludeSignCert(true)
					.setSM2Q7(true)
					.setSigner(signer)
					.setSymEncrypter(new NetcaSymEncrypter())
					.setPublicKeyEncrypter(new NetcaPublicKeyEncrypter())
					.setSecureRandomGenerator(new NetcaSecureRandomGenerator())
					.signAndEncrypt(content)
					.encode(true);
			save(outFileName,outData);
			System.out.println("Success");
		}finally{
			if(store!=null){
				store.free();
			}
		}

	}
	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=Integer.MAX_VALUE) {
			throw new Exception("file too big");
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail");
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private static void save(String fileName,byte[] data) throws Exception{
		FileOutputStream fOut=new FileOutputStream(fileName);
		try {
			fOut.write(data);
		} finally {
			fOut.close();
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
    	
    	return signer;
    }
    
    private static Signable getSignable(NetcaMyStore store,X509Certificate cert)throws Exception{
    	Iterator<X509CertificateAndPrivateKey> it=store.iterator();
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
