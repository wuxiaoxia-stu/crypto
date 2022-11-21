package net.netca.sample;


import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;






import net.netca.pki.xml.Document;
import net.netca.pki.xml.Node;
import net.netca.pki.xml.Reference;
import net.netca.pki.xml.SignedInfo;
import net.netca.pki.xml.Transform;
import net.netca.pki.xml.XMLSignature;
import net.netca.pki.Certificate;
import net.netca.pki.PkiException;

public class XMLSignatureTest {

	public static void main(String []args) throws IOException, PkiException{
		testXMLSignatureByJson();
//		testXMLSignatureBySignedInfo();
	}
	
	/**
	 * 获取inputstream 的byte 数组
	 * @param is
	 * @return
	 * @throws IOException
	 */
	public static byte[] getBytes(InputStream is) throws IOException {
		byte[] retData = new byte[0];
		if (is == null) {
			return retData;
		}
		ByteArrayOutputStream byteStream = new ByteArrayOutputStream();
		try{
			byte[] buf = new byte[1024];
			int len;
			while ((len = is.read(buf)) > 0) {
				byteStream.write(buf, 0, len);
			}
			retData = byteStream.toByteArray();
		}finally{
			try{
				byteStream.close();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		return retData;

	}
	
	public static void testXMLSignatureBySignedInfo() throws IOException, PkiException{
		//签名xml 模板路径
		String filePath = "D://test0.xml";
		//签名xml 保存路径
		String saveFilePath = "D://test_signed.xml";
		
		String passwrod = "12345678";
		
		FileInputStream fis = null;
		Certificate cert = null;
		Document doc = null;
		SignedInfo signedInfo = null;
		
		try{
			cert = getSignCert();
			List<Transform> transList = new ArrayList<Transform>();
			//设置转换算法为 enveloped signature
			Transform trans = new Transform(Transform.TRANSFORM_ENVELOPED_SIGNATURE, null);
			transList.add(trans);
			
			List<Reference> refList = new ArrayList<Reference>();
			//设置reference hash 算法为 SHA1 引用内容为""
			Reference ref = new Reference(Reference.HASH_ALGORITHM_SHA1, null, "", null, null, transList);
			refList.add(ref);
			
			//创建签名信息对象
			signedInfo = new SignedInfo(null, SignedInfo.NETCA_XML_SIGNATURE_C14NV1_0_WITHOUT_COMMETNTS, null, SignedInfo.SIGNATURE_ALGORITHM_RSA_SHA1, refList);
			//设置包含证书  :不包含证书使用 INCLUDE_CERT_FLAG_NONE
			//signedInfo.setIncludeCertFlag(SignedInfo.INCLUDE_CERT_FLAG_SELF);
			
			//设置不包含证书
			signedInfo.setIncludeCertFlag(SignedInfo.INCLUDE_CERT_FLAG_NONE);
			
			//读取文件
			fis = new FileInputStream(new File(filePath));
			byte[] xmlData = getBytes(fis);
			
			//创建 Document 对象
			doc = new Document(xmlData);
			//从doc获取跟节点
			Node rootNode = doc.getRootElementNode();
			//rootNode 节点下插入Signature 节点,并签名
			if(XMLSignature.signXMLDataBySignedInfo(doc, rootNode, null, signedInfo, cert, passwrod)){
				System.out.println("签名成功");
				doc.saveToFile(saveFilePath, "GBK");
			}else{
				System.out.println("签名失败");
			}
			
			//验证文件
			if(XMLSignature.verifyXMLFile(saveFilePath, cert)){
				System.out.println("验证成功");
			}else{
				System.out.println("验证失败");
			}
			}finally{
				if(fis != null){
					fis.close();
				}
				if(cert != null){
					cert.free();
				}
				if(doc != null){
					doc.free();
				}
				if(signedInfo != null){
					signedInfo.free();
				}
			}
	}
	
	public static void testXMLSignatureByJson() throws IOException, PkiException{
		//签名xml 模板路径
		String filePath = "D://test.xml";
		//签名xml 保存路径
		String saveFilePath = "D://test_signed.xml";
		
		String passwrod = "12345678";
		
		FileInputStream fis = null;
		Certificate cert = null;
		Document doc = null;
		
		try{
		//从设备获取证书
		cert = getSignCert();
		String jsonParam = "{"+
				"\"C14NAlgo\":\"C14N\","+
				//设置签名算法为 SHA1WithRSA
				"\"SignAlgo\":\"SHA1WithRSA\","+
				//设置包含证书 不包含签名使用 None
				//"\"IncludeCertOption\":\"Self\","+
				//设置不包含证书
				"\"IncludeCertOption\":\"None\","+
				"\"References\":"+
					"["+
						"{"+
							//设置hash 算法为sha1
							"\"HashAlgo\":\"Sha1\","+
							"\"URI\":\"\","+
							"\"Transforms\":"+
							"["+
								"{"+
									//设置转换为 EnvelopedSignature
									"\"TransformAlgo\":\"EnvelopedSignature\""+
								"}"+
							"]"+

						"}"+
					"]"+
		"}";
		
		fis = new FileInputStream(new File(filePath));
		//读取文件
		byte[] xmlData = getBytes(fis);
		
		//创建Document 对象
		doc = new Document(xmlData);
		//找到Document 的根节点
		Node rootNode = doc.getRootElementNode();
		//从根节点找到Signature 节点
		List<Node> signNodeList = rootNode.getElementList("Signature", "http://www.w3.org/2000/09/xmldsig#");
		if(signNodeList ==null || signNodeList.isEmpty()){
			System.out.println("不包含 Signature 节点");
			return;
		}
		//找到第一个Signature 节点(一般情况下Signature 只有一个)
		Node signNode = signNodeList.get(0);
		//对xml 进行签名
		if(XMLSignature.signXMLDataByJson(signNode, jsonParam, cert, passwrod)){
			System.out.println("签名成功");
			//以gbk 编码保存文件到 saveFilePath 的路径
			doc.saveToFile(saveFilePath, "GBK");
		}else{
			System.out.println("签名失败");
		}
		
		//使用证书 验证xml文件(xml签名包含证书,可以不输入cert)
		if(XMLSignature.verifyXMLFile(saveFilePath, cert)){
			System.out.println("验证成功");
		}else{
			System.out.println("验证失败");
		}
		}finally{
			if(fis != null){
				fis.close();
			}
			if(cert != null){
				cert.free();
			}
			if(doc != null){
				doc.free();
			}
		}
		
		
	}
	
	/**
	 * 从设备获取NETCA 的有效证书
	 * @return
	 * @throws PkiException
	 */
	public static Certificate getSignCert() throws PkiException {
		String issuerCN = "NETCA";
		StringBuilder filter = new StringBuilder(
				"InValidity='True' && IssuerCN~'");
		filter.append(issuerCN);
		filter.append("'");
		Certificate cert = Certificate.select("Signature", filter.toString());
		return cert;
	}
}
