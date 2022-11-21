import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;


import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpInputMessage;
import org.springframework.http.HttpOutputMessage;
import org.springframework.http.MediaType;
import org.springframework.http.converter.HttpMessageNotReadableException;
import org.springframework.http.converter.HttpMessageNotWritableException;

import net.netca.pki.PkiException;
import net.netca.pki.encoding.json.JSON;
import net.netca.pki.encoding.json.JSONObject;
import net.netca.pki.encoding.json.serialization.JSONSerialization;
import net.netca.pki.encoding.json.serialization.Serializable;

import org.springframework.http.converter.AbstractHttpMessageConverter;

/*
   *  在Spring的XML文件中添加
 * <mvc:annotation-driven>
 *   	<mvc:message-converters register-defaults="false">
 *   		<bean id="jsonConverter" class="JsonConverter"/>
 *	    </mvc:message-converters>
 *   </mvc:annotation-driven>
 *
 */
public class JsonConverter extends AbstractHttpMessageConverter<Object>{
	
	public JsonConverter() {
		super(MediaType.APPLICATION_JSON);
	}
	
	@Override
	protected Object readInternal(Class<? extends Object> cls, HttpInputMessage inputMessage)
			throws IOException, HttpMessageNotReadableException {
		HttpHeaders headers=inputMessage.getHeaders();
		
		if(headers==null) {
			throw new HttpMessageNotReadableException("no http header",inputMessage);
		}
		long length=headers.getContentLength();
		if(length<0) {
			throw new HttpMessageNotReadableException("no content length",inputMessage);
		}
		if(length>Integer.MAX_VALUE) {
			throw new HttpMessageNotReadableException("content length too long:"+length,inputMessage);
		}
		int len=(int)length;
		byte[] data=new byte[len];
		try(InputStream stream=inputMessage.getBody()){
			int pos=0;
			int readLen;
			while(pos<len) {
				readLen=stream.read(data, pos, len-pos);
				if(readLen==-1) {
					break;
				}
				pos+=readLen;
			}
			if(pos!=len) {
				throw new IOException("read data fail");
			}
		}
		String str=new String(data,"UTF-8");
		JSON json=JSON.decode(str);
		if(json==null) {
			throw new HttpMessageNotReadableException("not json:"+str,inputMessage);
		}
		if(json instanceof JSONObject==false) {
			throw new HttpMessageNotReadableException("not json object:"+str,inputMessage);
		}
		
		try {
			return JSONSerialization.parse(json, cls);
		} catch (PkiException e) {
			throw new HttpMessageNotReadableException("unserialize fail",e,inputMessage);
		}
	}

	@Override
	protected boolean supports(Class<?> cls) {
		if(cls.getAnnotation(Serializable.class)==null) {
			return false;
		}
		return true;
	}

	@Override
	protected void writeInternal(Object object, HttpOutputMessage outputMessage)
			throws IOException, HttpMessageNotWritableException {
		JSON json;
		try {
			json = JSONSerialization.encode(object);
		} catch (PkiException e) {
			throw new HttpMessageNotWritableException("serialize fail",e);
		}
		byte[] data=json.encode().getBytes("UTF-8");
		HttpHeaders headers=outputMessage.getHeaders();
		if(headers==null) {
			throw new HttpMessageNotWritableException("no header");
		}
		headers.setContentType(MediaType.APPLICATION_JSON);
		headers.setContentLength(data.length);
		
		try(OutputStream stream=outputMessage.getBody()){
			stream.write(data);
		}
		
	}
	
	


}
