package net.netca.xml.sample.servlet;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLEncoder;
import java.util.Properties;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.netca.pki.Certificate;
import net.netca.pki.xml.XMLSignature;

public class XMLVerifyServlet extends HttpServlet {
	static String passwrod = "78978978";
	static String certPath = "D:\\Cert_sign.cer";
	/**
	 * Constructor of the object.
	 */
	public XMLVerifyServlet() {
		super();
	}

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
		String ret_data = "";
		int code = 0;
		String msg = "";
		Certificate cert = null;
		
		try{
			cert = getSignCert(certPath);
			boolean result = XMLSignature.verifyXMLByteArray(xml.getBytes("GBK"), cert);
			if(result){
				System.out.println("验证成功");
				code = 0;
				msg = "";
			}else{
				System.out.println("验证失败");
				code = 1;
				msg =  URLEncoder.encode("验证失败", "UTF-8").replace("+", "%20");
			}
		}catch(Exception e){
			e.printStackTrace();
			System.out.println("验证失败");
			code = 1;
			msg = URLEncoder.encode(e.getMessage(),"UTF-8").replace("+", "%20");
		}finally{
			if(cert != null){
				cert.free();
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
