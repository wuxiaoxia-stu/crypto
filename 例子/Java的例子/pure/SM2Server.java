import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.ServletInputStream;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.JSONString;
import net.netca.pki.encoding.json.JSONNumber;
import net.netca.pki.encoding.Hex;
import net.netca.pki.encoding.asn1.pki.JCESecureRandomGenerator;

import java.math.BigInteger;

import net.netca.pki.PkiException;
import net.netca.pki.algorithm.ecc.Curve;
import net.netca.pki.algorithm.ecc.Point;
import net.netca.pki.algorithm.SM3;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class SM2Server extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	

	public void doPost(HttpServletRequest request,
            HttpServletResponse response)
            		throws ServletException, IOException {
		byte[] data=getRequestData(request);
		JSON json=JSON.decode(new String(data,"UTF-8"));
		if(json instanceof JSONObject==false) {
			throw new ServletException("bad json");
		}
		JSONObject jsonObj=(JSONObject)json;
		json=jsonObj.getValue("function");
		if(json instanceof JSONString==false){
			throw new ServletException("bad json");
		}
		
		JSONString jsonString=(JSONString)json;
		String functionName=jsonString.getString();
		
		json=jsonObj.getValue("arguement");
		
		if(functionName.equals("GenerateKeypair")) {
			generateKeypair(json,response);
		} else if(functionName.equals("Sign")) {
			sign(json,response);
		} else if(functionName.equals("Decrypt")) {
			decrypt(json,response);
		} else {
			throw new ServletException("bad function: "+functionName);
		}
	}
	private void decrypt(JSON json,HttpServletResponse response)
    		throws ServletException, IOException {
		if(json instanceof JSONObject==false){
			throw new ServletException("bad json");
		}
		JSONObject arg=(JSONObject)json;
		json=arg.getValue("id");
		if(json instanceof JSONString==false){
			throw new ServletException("bad id");
		}
		JSONString jsonString=(JSONString)json;
		String id=jsonString.getString();
		BigInteger d2=readd2(id);
		
		json=arg.getValue("T1");
		if(json instanceof JSONObject==false){
			throw new ServletException("bad T1");
		}
		JSONObject Q1Object=(JSONObject)json;
		
		BigInteger x=getInteger(Q1Object.getValue("x"));
		BigInteger y=getInteger(Q1Object.getValue("y"));
		
		Curve curve=Curve.getSM2Curve();
		if(curve.match(x, y)==false){
			throw new ServletException("bad Q1");
		}
		
		Point T1=new Point(curve,x,y);
		BigInteger N=curve.getN();
		BigInteger d2Inv=d2.modInverse(N);
		Point T2=T1.multiplek(d2Inv);
			
		JSONObject returnJson=getDecryptReturnJson(id,T2);
		writeResponse(response,returnJson);
	}
	private JSONObject getDecryptReturnJson(String id,Point T2)throws ServletException{
		byte[] data=T2.encode();
		String hex=Hex.encode(true, data);
		JSONObject PObject=new JSONObject();
		PObject.add("x", new JSONString(hex.substring(2,66)));
		PObject.add("y", new JSONString(hex.substring(66)));
		
		JSONObject returnValueObject=new JSONObject();
		returnValueObject.add("T2", PObject);
		returnValueObject.add("id", new JSONString(id));
		returnValueObject.add("status", new JSONNumber(0));
		JSONObject json=new JSONObject();
		json.add("function", new JSONString("Decrypt"));
		json.add("return", returnValueObject);
		return json;
	}
	private void generateKeypair(JSON json,HttpServletResponse response)
    		throws ServletException, IOException {
		if(json instanceof JSONObject==false){
			throw new ServletException("bad json");
		}
		JSONObject arg=(JSONObject)json;
		json=arg.getValue("P1");
		if(json instanceof JSONObject==false){
			throw new ServletException("no P1");
		}
		JSONObject P1Object=(JSONObject)json;
		
		BigInteger x=getInteger(P1Object.getValue("x"));
		BigInteger y=getInteger(P1Object.getValue("y"));
		
		Curve curve=Curve.getSM2Curve();
		if(curve.match(x, y)==false){
			throw new ServletException("bad P1");
		}
		Point P1=new Point(curve,x,y);
		BigInteger N=curve.getN();
		BigInteger d2=genRamdon(N);
		BigInteger d2Inv=d2.modInverse(N);
		
		Point tempP1=P1.multiplek(d2Inv);
		Point tempP2=curve.getG().negate();
		Point P=tempP1.add(tempP2);
		save(P,d2);
		writeGenerateKeypairResponse(response,P);
	}
	
	private void sign(JSON json,HttpServletResponse response)
            		throws ServletException, IOException {
		if(json instanceof JSONObject==false){
			throw new ServletException("bad json");
		}
		JSONObject arg=(JSONObject)json;
		json=arg.getValue("id");
		if(json instanceof JSONString==false){
			throw new ServletException("bad id");
		}
		JSONString jsonString=(JSONString)json;
		String id=jsonString.getString();
		BigInteger d2=readd2(id);
		
		json=arg.getValue("e");
		if(json instanceof JSONString==false){
			throw new ServletException("bad e");
		}
		jsonString=(JSONString)json;
		String str=jsonString.getString();
		if(str.length()!=64){
			throw new ServletException("bad e");
		}
		byte[] eData;
		try {
			eData=Hex.decode(str);
		} catch (PkiException e) {
			throw new ServletException("bad e");
		}
		BigInteger e=new BigInteger(1,eData);
		
		json=arg.getValue("Q1");
		if(json instanceof JSONObject==false){
			throw new ServletException("bad Q1");
		}
		JSONObject Q1Object=(JSONObject)json;
		
		BigInteger x=getInteger(Q1Object.getValue("x"));
		BigInteger y=getInteger(Q1Object.getValue("y"));
		
		Curve curve=Curve.getSM2Curve();
		if(curve.match(x, y)==false){
			throw new ServletException("bad Q1");
		}
		
		Point Q1=new Point(curve,x,y);
		BigInteger N=curve.getN();
		BigInteger k2=genRamdon(N);
		Point Q2=curve.getG().multiplek(k2);
		BigInteger one=BigInteger.ONE;
		BigInteger r_k2;
		BigInteger s2;
		BigInteger r;
		for(;;){
			BigInteger k3=genRamdon(N);
			Point tempP1=Q1.multiplek(k3);
			Point tempP2=tempP1.add(Q2);
			
			BigInteger x1=tempP2.getX();
			r=x1.add(e);
			r=r.mod(N);
			if(r.signum()==0){
				continue;
			}
			
			s2=d2.multiply(k3);
			s2=s2.mod(N);
			
			r_k2=r.add(k2);
			r_k2=r_k2.mod(N);
			if(r_k2.equals(one)){
				continue;
			}
			break;
		}
		BigInteger s3=r_k2.multiply(d2);
		s3=s3.mod(N);
		
		JSONObject returnJson=getSignReturnJson(id,r,s2,s3);
		writeResponse(response,returnJson);
	}
	private JSONObject getSignReturnJson(String id,BigInteger r,BigInteger s2,BigInteger s3)throws ServletException{
		
		JSONObject returnValueObject=new JSONObject();
		returnValueObject.add("id", new JSONString(id));
		returnValueObject.add("r", new JSONString(Hex.encode(true,r.toByteArray())));
		returnValueObject.add("s2", new JSONString(Hex.encode(true,s2.toByteArray())));
		returnValueObject.add("s3", new JSONString(Hex.encode(true,s3.toByteArray())));
		returnValueObject.add("status", new JSONNumber(0));
		JSONObject json=new JSONObject();
		json.add("function", new JSONString("Sign"));
		json.add("return", returnValueObject);
		return json;
	}
	private BigInteger readd2(String id)throws ServletException, IOException{
		try {
			Hex.decode(id);
		} catch (PkiException e) {
			throw new ServletException("bad id");
		}
		String fileName=getServletContext().getRealPath(id+".txt");
		File f=new File(fileName);
		byte[] data=new byte[(int)f.length()];
		FileInputStream in=new FileInputStream(f);
		int length=in.read(data);
		in.close();
		if(length!=data.length){
			throw new ServletException("read file fail");
		}
		
		return new BigInteger(data);
	}
	
	private void save(Point P,BigInteger d2)throws ServletException, IOException{
		byte[] data=P.encode();
		byte[] keyId=SM3.hash(data);
		String hex=Hex.encode(true, keyId);
		
		String fileName=getServletContext().getRealPath(hex+".txt");
		FileOutputStream out=new FileOutputStream(fileName);
		data=d2.toByteArray();
		out.write(data);
		out.close();
	}
	
	private void writeGenerateKeypairResponse(HttpServletResponse response,Point P)throws ServletException, IOException{
		JSONObject json=getGenerateKeypairReturnJson(P);
		writeResponse(response,json);
	}
	
	private void writeResponse(HttpServletResponse response,JSONObject json)throws ServletException, IOException{
			
		byte[] data=json.encode().getBytes("UTF-8");
		response.setContentLength(data.length);
		ServletOutputStream stream=response.getOutputStream();
		stream.write(data);
		stream.close();
		
	}
	
	private JSONObject getGenerateKeypairReturnJson(Point P)throws ServletException{
		byte[] data=P.encode();
		byte[] keyId=SM3.hash(data);
		String hex=Hex.encode(true, data);
		JSONObject PObject=new JSONObject();
		PObject.add("x", new JSONString(hex.substring(2,66)));
		PObject.add("y", new JSONString(hex.substring(66)));
		//PObject.add("p", new JSONString(hex));
		JSONObject returnValueObject=new JSONObject();
		returnValueObject.add("P", PObject);
		returnValueObject.add("id", new JSONString(Hex.encode(true,keyId)));
		returnValueObject.add("status", new JSONNumber(0));
		JSONObject json=new JSONObject();
		json.add("function", new JSONString("GenerateKeypair"));
		json.add("return", returnValueObject);
		return json;
	}
	private BigInteger genRamdon(BigInteger N)throws ServletException{
		BigInteger d;
		BigInteger one=BigInteger.ONE;
		for(;;){
			byte[] data;
			try {
				data = JCESecureRandomGenerator.getInstance().generate(32);
			} catch (PkiException e) {
				throw new ServletException("gen ramdon fail");
			}
			d=new BigInteger(1,data);
			int rv=d.compareTo(N);
			if(rv==0){
				continue;
			} else if(rv>0){
				d=d.mod(N);
			}
			if(d.compareTo(one)<=0){
				continue;
			}
			break;
		}
		return d;
	}
	
	
	private BigInteger getInteger(JSON json)throws ServletException{
		if(json instanceof JSONString==false){
			throw new ServletException("bad json");
		}
		byte[] data;
		try {
			data=Hex.decode(((JSONString)json).getString());
		} catch (PkiException e) {
			throw new ServletException("bad json");
		}
		return new BigInteger(1,data);
	}
	
	
	private byte[] getRequestData(HttpServletRequest request)throws IOException {
		int length=request.getContentLength();
		if(length<0) {
			throw new IOException("no content-length");
		}
		byte[] data=new byte[length];
		ServletInputStream  stream=request.getInputStream();
		try{
			int readLen;
			int pos=0;
			int remLen;
			while(pos<length) {
				remLen=length-pos;
				readLen=stream.read(data,pos,remLen);
				if(readLen<=0) {
					throw new IOException("read fail");
				}
				pos+=readLen;
			}
			return data;
		} finally {
			stream.close();
		}
	}
}
