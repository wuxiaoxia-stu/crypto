import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.util.Date;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.asn1.pki.AlgorithmIdentifier;
import net.netca.pki.encoding.asn1.pki.Hashable;
import net.netca.pki.encoding.asn1.pki.JCEHasher;
import net.netca.pki.encoding.asn1.pki.JCEVerifier;
import net.netca.pki.encoding.asn1.pki.Verifible;
import net.netca.pki.encoding.asn1.pki.cms.SignedData;
import net.netca.pki.encoding.asn1.pki.cms.SignerInfo;
import net.netca.pki.encoding.asn1.pki.cms.cades.ATSHashIndex;
import net.netca.pki.encoding.asn1.pki.cms.cades.ATSHashIndexV3;

public class CAdESAtsV3Create {

	public static void main(String[] args) throws Exception{
		int argCount=args.length;
		if(argCount!=6 && argCount!=7) {
            System.out.println("Usage: java CAdESAtsV3Create [new] tbsFileName oldSignedDataFileName hashAlgo url atsHashIndexHashAlgo outputFileName");
            return;
        }
		boolean useATSHashIndexV3=false;
		int pos=0;
		if(argCount==7){
			if(args[0].equalsIgnoreCase("new")==false) {
				System.out.println("Usage: java CAdESAtsV3Create [new] tbsFileName oldSignedDataFileName hashAlgo url atsHashIndexHashAlgo outputFileName");
	            return;
			}
			pos=1;
			useATSHashIndexV3=true;
		}
		String tbsFileName=args[pos];
		pos++;
		String oldSignedDataFileName=args[pos];
		pos++;
		String hashAlgoName=args[pos];
		pos++;
		String url=args[pos];
		pos++;
		String atsHashIndexHashAlgoName=args[pos];
		pos++;
		String outputFileName=args[pos];
		byte[] tbs=readFile(tbsFileName);
		byte[] signedData=readFile(oldSignedDataFileName);
		AlgorithmIdentifier hashAlgo=createHashAlgo(hashAlgoName);
		if(hashAlgo==null){
			System.out.println("不支持的Hash算法");
			return;
		}
		
		AlgorithmIdentifier atsHashIndexHashAlgo=createHashAlgo(atsHashIndexHashAlgoName);
		if(atsHashIndexHashAlgo==null){
			System.out.println("不支持的ATSHashIndex Hash算法");
			return;
		}
		
		SignedData signedDataObj=new SignedData(signedData);
		boolean isDetached=signedDataObj.isDetached();
		if(isDetached==false){
			byte[] tbs2=signedDataObj.getEncapContentInfo().getTbs();
			if(Arrays.equals(tbs, tbs2)==false) {
				System.out.println("原文不匹配");
	            return;
			}
		}
		Verifible verifier=new JCEVerifier();
		Hashable hasher=new JCEHasher();
		int signerInfoCount=signedDataObj.getSignerInfoCount();
		if(signerInfoCount!=1){
			System.out.println("签名个数不为1");
            return;
		}
		if(signedDataObj.verify(0, tbs,verifier, hasher)==false){
			System.out.println("验证签名失败");
			return;
		}
		
		if(signedDataObj.hasSigningCertificateAttribute(0)==false 
				&& signedDataObj.hasSigningCertificateV2Attribute(0)==false){
			System.out.println("既没有SigningCertificate属性也没有SigningCertificateV2属性，不是CAdES-BES");
			return;
		}
		
		SignerInfo signerInfo=signedDataObj.getSignerInfos().get(0);
		Date t=null;
		if(useATSHashIndexV3) {
			ATSHashIndexV3 atsHashIndexV3=new ATSHashIndexV3(atsHashIndexHashAlgo,hasher,
					signedDataObj.getCertificates(),
					signedDataObj.getCrls(),
					signerInfo.getUnsignedAttrs()); 
			t=signerInfo.attachArchiveTimeStampTokenV3(signedDataObj, tbs, atsHashIndexV3, url, hashAlgo);
		} else {
			ATSHashIndex atsHashIndex=new ATSHashIndex(atsHashIndexHashAlgo,hasher,
					signedDataObj.getCertificates(),
					signedDataObj.getCrls(),
					signerInfo.getUnsignedAttrs());
			t=signerInfo.attachArchiveTimeStampTokenV3(signedDataObj, tbs, atsHashIndex, url, hashAlgo);
		}
		
		signedData=signedDataObj.encode(signedDataObj.isContentInfo());
		SaveFile(outputFileName,signedData);
		System.out.println("追加ATSV3时间戳成功，时间戳时间:"+t);

	}

	private static void SaveFile(String fileName,byte[] data)throws Exception {
		FileOutputStream f=new FileOutputStream(fileName);
		f.write(data);
		f.close();
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
	
	private static AlgorithmIdentifier createHashAlgo(String algo) throws PkiException {
		if(algo.equalsIgnoreCase("SHA1")
				|| algo.equalsIgnoreCase("SHA-1")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA1_OID);
		}else if(algo.equalsIgnoreCase("SHA224")
				|| algo.equalsIgnoreCase("SHA-224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA224_OID);
		} else if(algo.equalsIgnoreCase("SHA256")
				|| algo.equalsIgnoreCase("SHA-256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA256_OID);
		} else if(algo.equalsIgnoreCase("SHA384")
				|| algo.equalsIgnoreCase("SHA-384")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA384_OID);
		} else if(algo.equalsIgnoreCase("SHA512")
				|| algo.equalsIgnoreCase("SHA-512")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_OID);
		} else if(algo.equalsIgnoreCase("SHA512/224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_224_OID);
		} else if(algo.equalsIgnoreCase("SHA512/256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA512_256_OID);
		} else if(algo.equalsIgnoreCase("SHA3-224")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_224_OID);
		} else if(algo.equalsIgnoreCase("SHA3-256")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_256_OID);
		} else if(algo.equalsIgnoreCase("SHA3-384")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_384_OID);
		} else if(algo.equalsIgnoreCase("SHA3-512")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifier(AlgorithmIdentifier.SHA3_512_OID);
		} else if(algo.equalsIgnoreCase("SM3")) {
			return 	AlgorithmIdentifier.CreateAlgorithmIdentifierNullParam(AlgorithmIdentifier.SM3_OID);
		} else {
			return null;
		}
	}
}
