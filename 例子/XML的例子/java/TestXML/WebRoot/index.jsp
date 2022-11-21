<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<HTML>
	<HEAD>
		<SCRIPT LANGUAGE=javascript>
			try{
				var utilobj=new ActiveXObject("NetcaPki.Utilities");
				var certobj=new ActiveXObject("NetcaPki.Certificate");
				var builder=new ActiveXObject("NETCA_XMLCOM.Factory");
			}catch(e){
			}
			var NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS		=1;
			var NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS			=2;
			var NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS   	=3;
			var NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS  	=4;
			var NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS   	=6;
			var NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITH_COMMENTS   		=7;
			

			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA1			=65;
			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA256			= 68;
			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA512		= 70;
			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM2_SM3			= 83;

			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1			= 1;
			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256			= 4;
			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA512			= 6;
			var NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM3			= 8;

			var NETCA_XMLCOM_SIGNATURE_TRANSFORM_BASE64			= 16;
			var NETCA_XMLCOM_SIGNATURE_TRANSFORM_XPATH_FILTER		= 32;
			var NETCA_XMLCOM_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE	= 48;
			var NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS			=0;
			var NETCAPKI_SEARCH_KEYPAIR_FLAG_DEVICE = 268435456;
			var NETCAPKI_SEARCH_KEYPAIR_FLAG_CURRENT_USER			=1073741824;
			var NETCAPKI_CERT_PURPOSE_SIGN 					=2;
			
			var NETCA_XMLCOM_SIGNATURE_INCLUDE_CERT_FLAG_NONE = 1;
			var NETCA_XMLCOM_SIGNATURE_INCLUDE_CERT_FLAG_SELF = 2;

			function sign()
			{
				var xmltemplate = document.getElementById("xmltemplate");
				var signCert = document.getElementById("signCert");
				var password = document.getElementById("password");
				var xmlsignature = document.getElementById("xmlsignature");
				if(xmltemplate.value.length==0)
				{
					alert("没有输入XML模板");
					return;
				}

				if(signCert.value.length==0)
				{
					alert("没有输入签名证书");
					return;
				}
				if(password.value.length==0){
					alert("请输入密码");
					return;
				}

				try
				{
					var utilobj=new ActiveXObject("NetcaPki.Utilities");
					var signCert=signCert.value;
					var certobj=new ActiveXObject("NetcaPki.Certificate");
					certobj.Decode(signCert);
					var keypair = certobj.GetKeyPair(password.value, NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS|NETCAPKI_SEARCH_KEYPAIR_FLAG_DEVICE,NETCAPKI_CERT_PURPOSE_SIGN);
					certobj.SetKeyPair(keypair);
					
					var builder=new ActiveXObject("NETCA_XMLCOM.Factory");
					var doc=builder.CreateXMLDocumentObject();
					doc.LoadXML(xmltemplate.value,"GBK");
					var doc_value = xmltemplate.value;
					var root=doc.GetRootElementNode();
					var signList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")
					if (signList.Count==0)
					{
						var sign =builder.CreateXMLNodeObject();
						sign.NewElementNode("Signature");
						sign.NewNameSpaceNode("","http://www.w3.org/2000/09/xmldsig#");
						root.AddChild(sign);
						doc_value =doc.Encode(0,"GBK");
					}
					else if(signList.Count>1)
					{
						alert("XML签名节点太多");
						return;
					}
					var doc=builder.CreateXMLDocumentObject();
					doc.LoadXML(doc_value,"GBK");
							
					var root=doc.GetRootElementNode();
					var signList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")
					var signNode=signList.Item(1);

					
					var xmlsign=builder.CreateXMLSignatureObject();
					xmlsign.CanonicalizationMethod=NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS;
					xmlsign.SignatureMethod=NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA1;

					var tran = builder.CreateTransformObject();
					tran.Algorithm  = NETCA_XMLCOM_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE
					
					var trans = builder.CreateTransformsObject();
					trans.Add(tran);
					
					var ref=builder.CreateReferenceObject();
					ref.DigestMethod=NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1;
					ref.URI="";
					ref.Transforms = trans;

					var refs=builder.CreateReferencesObject();
					refs.Add(ref);
					
					xmlsign.References=refs;
					

					
					xmlsign.Sign(signNode, certobj, NETCA_XMLCOM_SIGNATURE_INCLUDE_CERT_FLAG_NONE);

					
					xmlsignature.value=doc.Encode(0,"GBK");

				}	
				catch(e)
				{
					alert("XML签名出错，错误原因是"+e.description);
					return;
				}
			}


			function attachtimestamp()
			{
				if(xmlsignature.value.length==0)
				{
					alert("没有输入XML签名");
					return;
				}

				try
				{
					var builder=new ActiveXObject("NETCA_XMLCOM.Factory");
					var doc=builder.CreateXMLDocumentObject();
					doc.LoadXML(xmlsignature.value,"GBK");
							
					var root=doc.GetRootElementNode();
					var signList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")
					if (signList.Count==0)
					{
						alert("没有XML签名节点");
						return;
					}
					else if(signList.Count>1)
					{
						alert("XML签名节点太多");
						return;
					}

					var signNode=signList.Item(1);
					
					var xmlsign=builder.CreateXMLSignatureObject();
					xmlsign.Verify(signNode);
					alert("XML签名验证成功");

				}	
				catch(e)
				{
					alert("XML签名出错，错误原因是"+e.description);
					return;
				}
			}


			function GetC14NAlgoName(algo)
			{
				switch(algo)
				{
				case NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS:
					return "XMLC14N";
				case NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS:
					return "XMLC14N With Comments";
				case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS:
					return  "EXC XMLC14N";
				case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS:
					return "XMLC14N With Comments";
				case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS:
					return "XMLC14N V1.1";
				case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITH_COMMENTS:
					return "XMLC14N V1.1 With Comments";
				default:
				return " Unknown XML C14N Algo (" + algo +")";
				}
			}

			function GetHashAlgoName(algo)
			{
				switch(algo)
				{
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA1:
					return "SHA1";
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA256:
					return "SHA256";
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SHA512:
					return "SHA512";
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM3:
					return "SM3";
				default:
					return " Unknown Hash Algo (" + algo + ")";
				}
			}

			function GetSignAlgoName(algo)
			{
				switch(algo)
				{
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA1:
					return "SHA1WithRSA";
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA256:
					return "SHA256WithRSA";
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_RSA_SHA512:
					return "SHA512WithRSA";
				case NETCA_XMLCOM_SIGNATURE_ALGORITHM_SM2_SM3:
					return "SM3WithSM2";
				default:
					return " Unknown Sign Algo (" + algo + ")";
				}
			}

			function GetTransformAlgoName(algo)
			{
				switch(algo)
				{
				case NETCA_XMLCOM_SIGNATURE_C14N_WITHOUT_COMMETNTS:
					return "XMLC14N";
				case NETCA_XMLCOM_SIGNATURE_C14N_WITH_COMMENTS:
					return "XMLC14N With Comments";
				case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS:
					return  "EXC XMLC14N";
				case NETCA_XMLCOM_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS:
					return "XMLC14N With Comments";
				case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS:
					return "XMLC14N V1.1";
				case NETCA_XMLCOM_SIGNATURE_C14NV1_1_WITH_COMMENTS:
					return "XMLC14N V1.1 With Comments";
				case NETCA_XMLCOM_SIGNATURE_TRANSFORM_BASE64:
					return "Base64";
				case NETCA_XMLCOM_SIGNATURE_TRANSFORM_XPATH_FILTER:
					return "XPath Filter";
				case NETCA_XMLCOM_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE:
					return "Enveloped Signature";
				default:
					return " Unknown Transform Algo (" + algo + ")";
				}
			}
			
			function TransformString(tran)
			{
				return "Transform Algo: " + GetTransformAlgoName(tran.Algorithm) +"\n";
			}
			
			function TransformsString(trans)
			{
				var i;
				var count;
				var str="";
				count=trans.Count;
				for(i=1;i<=count;i++)
				{	
					str+= "Transform " + i +":\n";
					str+=TransformString(trans.Item(i));
				}
				return str;
			}
			
			
			
			function ReferenceString(ref)
			{
				var str="";
				var util=new ActiveXObject("NetcaPki.Utilities");
				if (ref.Id.length!=0)
				{
					str+="Id: " + ref.Id+"\n";
				}
				str+="URI: " + ref.URI+"\n";
				str+="Hash Algo: " + GetHashAlgoName(ref.DigestMethod)+"\n";
				str+="Hash Value: " + util.BinaryToHex(ref.DigestValue)+"\n";
				
				if(ref.Transforms!=null)
				{
					str+=TransformsString(ref.Transforms);
				}
				return str;
			}


			function ReferencesString(refs)
			{
				var i;
				var count;
				var str="";
				count=refs.Count;
				for(i=1;i<=count;i++)
				{	
					str+= "Reference  " + i + ":\n";
					str+=ReferenceString(refs.Item(i));
				}
				return str;
			}

			function SignatureTimeStampInfo(xmlsign)
			{
				var i;
				var str="";
				var count=xmlsign.GetSignatureTimestampCount();
				for(i=1;i<=count;i++)	
				{
					if( xmlsign.VerifySignatureTimestamp(i))
					{
						str+=	 "VerifySignatureTimestamp " + i + ": OK\n" 
						str+=   "SignatureTimestamp " + i + ": " + xmlsign.GetSignatureTimestamp()+"\n";
					}
					else
					{
						str+=	 "VerifySignatureTimestamp " + i + ": Fail\n" 
					}
				}
				
				return str;
			}


				

			function CounterSignInfo(xmlsign)
			{
				var i;
				var str="";
				var count=xmlsign.GetCounterSignCount();
				for(i=1;i<=count;i++)	
				{
					if (xmlsign.VerifyCounterSign(i))
					{
						str+=	 "VerifyCounterSign " + i + ": OK\n" 
					}
					else
					{
						str+=	 "VerifyCounterSign " + i + ": Fail\n" 
					}
				}
				
				return str;
			}
			
			
		function XMLSignInfo(xmlsign)
		{
			var c14nalgo;
			var signalgo;
			
			var str="";
			c14nalgo=xmlsign.CanonicalizationMethod;
			str+= "C14N Algo: " + GetC14NAlgoName(c14nalgo) +"\n";

			signalgo=xmlsign.SignatureMethod;
			str+= "Sign Algo: " + GetSignAlgoName(signalgo) +"\n";

			str+=ReferencesString(xmlsign.References);

			var id=xmlsign.SignatureValueId;
			if  (id.length!=0)
			{
				str+= "SignatureValue Id: " + id +"\n";
			}

			if (xmlsign.HasSigningTime)
			{
				str+= "SigningTime: " +xmlsign.SigningTime+"\n";
			}
			
			if (xmlsign.HasSigningCertAttribute())
			{
				str+="Has SigningCert Attribute\n";
			}

			str+=SignatureTimeStampInfo(xmlsign);
			str+=CounterSignInfo(xmlsign);
			return str;
		}
				
			
			function verify()
			{
				var xmltemplate = document.getElementById("xmltemplate");
				var signCert = document.getElementById("signCert");
				var password = document.getElementById("password");
				var xmlsignature = document.getElementById("xmlsignature");
				var xmlsigninfo = document.getElementById("xmlsigninfo");
				
				if(xmlsignature.value.length==0||xmlsignature.value == "")
				{
					alert("没有输入XML签名");
					return;
				}
				if(signCert.value.length==0 || signCert.value == ""){
					alert("证书为空");
					return;
				}

				try
				{
					var builder=new ActiveXObject("NETCA_XMLCOM.Factory");
					var doc=builder.CreateXMLDocumentObject();
					doc.LoadXML(xmlsignature.value,"GBK");
							
					var root=doc.GetRootElementNode();
					var signList=root.GetElementList("Signature","http://www.w3.org/2000/09/xmldsig#")
					if (signList.Count==0)
					{
						alert("没有XML签名节点");
						return;
					}
					else if(signList.Count>1)
					{
						alert("XML签名节点太多");
						return;
					}

					var signNode=signList.Item(1);
					var signCert=signCert.value;
					var certobj=new ActiveXObject("NetcaPki.Certificate");
					certobj.Decode(signCert);
					var xmlsign=builder.CreateXMLSignatureObject();
					xmlsign.SetVerifyCert(signCert);
					xmlsign.Verify(signNode);
					alert("XML签名验证成功");

					xmlsigninfo.value=XMLSignInfo(xmlsign);


				}	
				catch(e)
				{
					alert("XML签名出错，错误原因是"+e.description);
					return;
				}
			}
		function server_sign(){
				var xmlhttp=null;
				 if (window.ActiveXObject)
				{
				  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
				}else if (window.XMLHttpRequest)
				{
				  xmlhttp=new XMLHttpRequest();
				}
				var xmltemplate = document.getElementById("xmltemplate");
				if(xmltemplate.value.length==0)
				{
					alert("没有输入XML模板");
					return;
				}
				var data = "xml="+encodeURIComponent(xmltemplate.value);
				var url = "/TestXML/servlet/XMLSignatureServlet";
				xmlhttp.open('POST', url, false);
				xmlhttp.setRequestHeader("Content-Type"
			, "application/x-www-form-urlencoded");
				xmlhttp.onreadystatechange = function(){
				    if(xmlhttp.readyState==4 && xmlhttp.status==200){
				       var result = eval('(' + xmlhttp.responseText + ')');
				       if(typeof(result) != "undefined"){
				           if(result.code== 0){
				               var data = result.data;
				               var xmlsignature = document.getElementById("xmlsignature");
				               xmlsignature.value = decodeURIComponent(data);
				           }else{
				           		alert(decodeURIComponent(result.msg));
				           }
				       }
				    }
				}
				
				xmlhttp.send(data);
		}
		function server_verify(){
			     var xmlhttp=null;
				 if (window.ActiveXObject)
				{
				  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
				}else if (window.XMLHttpRequest)
				{
				  xmlhttp=new XMLHttpRequest();
				}
				var xmlsignature = document.getElementById("xmlsignature");
				if(xmlsignature.value.length==0)
				{
					alert("XML签名为空");
					return;
				}
				var data = "xml="+encodeURIComponent(xmlsignature.value);
				var url = "/TestXML/servlet/XMLVerifyServlet";
				xmlhttp.open('POST', url, false);
				xmlhttp.setRequestHeader("Content-Type"
			, "application/x-www-form-urlencoded");
				xmlhttp.onreadystatechange = function(){
				    if(xmlhttp.readyState==4 && xmlhttp.status==200){
				       var result = eval('(' + xmlhttp.responseText + ')');
				       if(typeof(result) != "undefined"){
				           if(result.code== 0){
				           		alert("验证成功");
				           }else{
				           		alert(decodeURIComponent(result.msg));
				           }
				       }
				    }
				}
				
				xmlhttp.send(data);
		}
		</SCRIPT>
	</HEAD>
	<FORM id="form1">
	<table>
	    <tr hidden="hidden" style="visibility:hidden" ><td>加密机签名密码:  </td><td><input type="text" id = "password"/></td></tr>
		<tr><td>XML模板：        </td><td><TEXTAREA name="xmltemplate" id="xmltemplate" rows="10" cols="60"></TEXTAREA></td></tr>
		<tr><td>加密机签名证书：</td><td><TEXTAREA name="signCert" id="signCert" rows="5" cols="60"></TEXTAREA></td></tr>
		<tr><td>XML签名：         </td><td><TEXTAREA name="xmlsignature" id="xmlsignature" rows="15" cols="60"></TEXTAREA></td></tr>
		<tr><td>XML签名信息：   </td><td> <TEXTAREA name="xmlsigninfo" id="xmlsigninfo" rows="15" cols="60"></TEXTAREA></td></tr>
		<tr><td><INPUT type="button" value="com 签名" hidden="hidden" style="visibility:hidden"  LANGUAGE=javascript  onclick="return sign();"></td><td><INPUT type="button" value="服务器签名" LANGUAGE=javascript  onclick="return server_sign();"></td></tr>
		<tr><td><INPUT type="button" value="com 验证" LANGUAGE=javascript  onclick="return verify();"></td><td><INPUT type="button" value="服务器验证" LANGUAGE=javascript  onclick="return server_verify();"></td></tr>
</table>
	</FORM>
	<BODY>
	</BODY>
</HTML>


