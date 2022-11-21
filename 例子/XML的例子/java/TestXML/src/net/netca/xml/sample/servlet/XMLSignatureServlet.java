package net.netca.xml.sample.servlet;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.netca.pki.Certificate;
import net.netca.pki.xml.Document;
import net.netca.pki.xml.Node;
import net.netca.pki.xml.Reference;
import net.netca.pki.xml.SignedInfo;
import net.netca.pki.xml.Transform;
import net.netca.pki.xml.XMLSignature;


public class XMLSignatureServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public XMLSignatureServlet() {
		super();
	}

	static String passwrod = "78978978";
	static String certPath = "D:\\Cert_sign.cer";
	/**
	 * Destruction of the servlet. <br>
	 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		out.print("    This is ");
		out.print(this.getClass());
		out.println(", using the GET method");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String xml = request.getParameter("xml");
		xml = new String(xml.getBytes("ISO8859-1"), "UTF-8");
		System.out.println(xml);
		
		Certificate cert = null;
		Document doc = null;
		SignedInfo signedInfo = null;
		String ret_data;
		int code = 0;
		String msg = "";
		
		try{
			cert = getSignCert(certPath);
			List<Transform> transList = new ArrayList<Transform>();
			//����ת���㷨Ϊ enveloped signature
			Transform trans = new Transform(Transform.TRANSFORM_ENVELOPED_SIGNATURE, null);
			transList.add(trans);
			
			List<Reference> refList = new ArrayList<Reference>();
			//����reference hash �㷨Ϊ SHA1 ��������Ϊ""
			Reference ref = new Reference(Reference.HASH_ALGORITHM_SHA1, null, "", null, null, transList);
			refList.add(ref);
			
			//����ǩ����Ϣ����
			signedInfo = new SignedInfo(null, SignedInfo.NETCA_XML_SIGNATURE_C14NV1_0_WITHOUT_COMMETNTS, null, SignedInfo.SIGNATURE_ALGORITHM_RSA_SHA1, refList);
			//���ð���֤��  :������֤��ʹ�� INCLUDE_CERT_FLAG_NONE
			//signedInfo.setIncludeCertFlag(SignedInfo.INCLUDE_CERT_FLAG_SELF);
			
			//���ò�����֤��
			signedInfo.setIncludeCertFlag(SignedInfo.INCLUDE_CERT_FLAG_NONE);
			
			//��ȡxml
			byte[] xmlData = xml.getBytes("GBK");
			
			//���� Document ����
			doc = new Document(xmlData);
			//��doc��ȡ���ڵ�
			Node rootNode = doc.getRootElementNode();
			//rootNode �ڵ��²���Signature �ڵ�,��ǩ��
			if(XMLSignature.signXMLDataBySignedInfo(doc, rootNode, null, signedInfo, cert, passwrod)){
				System.out.println("ǩ���ɹ�");
				String signed_doc = new String( doc.encode("GBK"), "GBK");
				//����ո��+������
				ret_data = URLEncoder.encode(signed_doc, "UTF-8").replace("+", "%20");
				code = 0;
				msg = "";
			}else{
				code = 1;
				msg = URLEncoder.encode("ǩ��ʧ��", "UTF-8").replace("+", "%20");
				ret_data = "";
				System.out.println("ǩ��ʧ��");
			}
			}catch(Exception e){
				code = 1;
				msg = URLEncoder.encode(e.getMessage(), "UTF-8").replace("+", "%20");
				ret_data = "";
			}finally{
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

		String data = "{\"data\":\"%s\",\"code\":%d,\"msg\":\"%s\"}";
		
		response.setContentType("text/json");
		PrintWriter out = response.getWriter();
		out.print(String.format(data, ret_data, code, msg));
		out.flush();
		out.close();
	}
	

	private Certificate getSignCert(String certPath) throws Exception {
		// TODO Auto-generated method stub
		FileInputStream fis = null;
		ByteArrayOutputStream baos = null;
		try{
			fis = new FileInputStream(new File(certPath));
			byte[]buf = new byte[1024];
			int line = 0;
			baos = new ByteArrayOutputStream();
			while((line = fis.read(buf))>0){
				baos.write(buf, 0, line);
			}
			byte[] arr = baos.toByteArray();
			return new Certificate(arr);
		}finally{
			if(fis !=null){
				fis.close();
			}
			if(baos != null){
				baos.close();
			}
		}
	}

	   
	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
		try{
		String config = getServletContext().getRealPath("/WEB-INF/")+"/config.properties"; 
		 Properties p = new Properties();
		 p.load(new FileInputStream(config));
		 certPath =  p.getProperty("HSM_bpmssign_certFilePath");
		 passwrod = p.getProperty("HSM_bpmssign_pwd");
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}
