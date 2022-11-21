import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import net.netca.pki.CertReq;
import net.netca.pki.Cipher;
import net.netca.pki.PublicKey;
import net.netca.pki.Signature;
import net.netca.pki.Device;
import net.netca.pki.KeyPair;

public class EncodeEncKeyPair {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=3) {
            System.out.println("Usage: java EncodeEncKeyPair certReq newCertReq encKey");
            return;
        }
		
		String certReqFileName=args[0];
		String newCertReqFileName=args[1];
		String encKeyFileName=args[2];
		
		CertReq certReq=null;
		PublicKey publicKey=null;
		Device device=null;
		KeyPair keypair=null;
		CertReq newCertReq=null;
		
		try{
			certReq=new CertReq(readFile(certReqFileName));
			if(certReq.verify()==false){
				System.out.println("证书请求验证失败");
				return;
			}
			publicKey=certReq.getPublicKey();
			certReq.free();
			certReq=null;
			if(publicKey==null){
				System.out.println("获取公钥失败");
				return;
			}
			if(publicKey.isSM2()==false){
				System.out.println("不是SM2公钥");
				return;
			}
			device=Device.getPseudoDevice();
			keypair=device.generateTempECCKeyPair(Device.ECC_CURVE_SM2);
			byte[] encode=device.encodeGBEncryptKeyPair(Cipher.SM4_ECB, publicKey, keypair);
			newCertReq=new CertReq();
			newCertReq.setCN("SM2测试123");
			byte[] newCertReqEncode=newCertReq.sign(keypair, Signature.SM3WITHSM2);
			save(newCertReqFileName,newCertReqEncode);
			save(encKeyFileName,encode);
		} finally {
			if(certReq!=null){
				certReq.free();
			}
			if(publicKey!=null){
				publicKey.free();
			}
			if(device!=null){
				device.free();
			}
			if(keypair!=null){
				keypair.free();
			}
			if(newCertReq!=null){
				newCertReq.free();
			}
		
		}

		System.out.println("Success");
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
}
