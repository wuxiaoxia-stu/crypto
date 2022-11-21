1. 配置jdk 环境和crypto 环境
	

2. 配置 java crypto
	根据java 环境64或32位选择dll
	
	64位dll http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX64/动态库/Java/NetcaJCrypto.dll
	32位dll http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/NetcaJCrypto.dll
	
	jar 包 
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/log4j.jar
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/netcajce.jar
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/NetcaJCrypto.jar
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/slf4j-api-1.7.7.jar
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/slf4j-log4j12-1.7.7.jar
	
	将dll 放置到于 JDK/jre/bin 目录下
	将jar 包放置于 JDK/jre/lib/ext 目录下
	
	
3. 配置 java xml 签名
	根据java 环境64或32位选择dll
	64位dll http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX64/动态库/Java/NetcaJXML.dll
	32位dll http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/NetcaJXML.dll
	
	jar 包 http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/动态库/Java/NetcaJXML.jar
	将dll 放置到与 NetcaJCyrpto.dll 相同的目录下
	将jar 包放置与 NetcaJCyrpto.jar 相同的目录下

4. 配置加密机
	参考 http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/文档/加密机在windows下的配置指导.doc
	
5. 配置网站加密机签名证书和密码
   在WebRoot/WEB-INF/config.properties 目录中
   修改 HSM_bpmssign_certFilePath 的证书路径
   修改 HSM_bpmssign_pwd 的证书密码

6. 将 TestXML.war http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/例子/XML的例子/java/TestXML/TestXML.war 包放在于 tomcat webapps 目录下，运行tomcat

	
7. 打开 http://localhost:8080/TestMXL/index.jsp 测试 xml 签名和 xml 验证

XML 签名模板可以使用  xml_sign.xml

加密机证书可以使用      Cert_sign.cer
加密机密码                  78978978
加密机IP                     192.168.0.24
加密机类型                  德安加密机 SJY05B