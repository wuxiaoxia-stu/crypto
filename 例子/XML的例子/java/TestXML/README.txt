1. ����jdk ������crypto ����
	

2. ���� java crypto
	����java ����64��32λѡ��dll
	
	64λdll http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX64/��̬��/Java/NetcaJCrypto.dll
	32λdll http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/NetcaJCrypto.dll
	
	jar �� 
		http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/log4j.jar
		http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/netcajce.jar
		http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/NetcaJCrypto.jar
		http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/slf4j-api-1.7.7.jar
		http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/slf4j-log4j12-1.7.7.jar
	
	��dll ���õ��� JDK/jre/bin Ŀ¼��
	��jar �������� JDK/jre/lib/ext Ŀ¼��
	
	
3. ���� java xml ǩ��
	����java ����64��32λѡ��dll
	64λdll http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX64/��̬��/Java/NetcaJXML.dll
	32λdll http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/NetcaJXML.dll
	
	jar �� http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/winX86/��̬��/Java/NetcaJXML.jar
	��dll ���õ��� NetcaJCyrpto.dll ��ͬ��Ŀ¼��
	��jar �������� NetcaJCyrpto.jar ��ͬ��Ŀ¼��

4. ���ü��ܻ�
	�ο� http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/�ĵ�/���ܻ���windows�µ�����ָ��.doc
	
5. ������վ���ܻ�ǩ��֤�������
   ��WebRoot/WEB-INF/config.properties Ŀ¼��
   �޸� HSM_bpmssign_certFilePath ��֤��·��
   �޸� HSM_bpmssign_pwd ��֤������

6. �� TestXML.war http://192.168.0.11:8081/svn/rdrelease/�������/NETCA_CRYPTO/current/����/XML������/java/TestXML/TestXML.war �������� tomcat webapps Ŀ¼�£�����tomcat

	
7. �� http://localhost:8080/TestMXL/index.jsp ���� xml ǩ���� xml ��֤

XML ǩ��ģ�����ʹ��  xml_sign.xml

���ܻ�֤�����ʹ��      Cert_sign.cer
���ܻ�����                  78978978
���ܻ�IP                     192.168.0.24
���ܻ�����                  �°����ܻ� SJY05B