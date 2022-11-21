此文档是Root CA的ARL签发工具使用说明

1.开发目的
（1）替代早期的CA三期系统的ARL签发工具，使用旧款的得安SJY03-B加密卡，实现签发RootCA的ARL

2.准备材料
	（1）硬件：SJY03B加密卡一个、操作员IC卡一张、一台主机（系统要求必须为32位，已测试XP和Win7）
	（2）软件：SignCRLTools.exe（签发工具）、deviceInfo.txt（设备信息文件）、RootCA.cer（根证书）
				可从如下地址获取 http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/工具/签发ARL工具/

3.使用步骤
	3.1 部署步骤（该步骤部署过一次后，以后可以不用操作）
	（1）安装加密卡、安装加密卡驱动
		通过管理软件对加密卡进行密钥管理，可见用户手册（PCI接口密码卡用户手册.PDF）
		用户盘：http://192.168.0.11:8081/svn/rdrelease/软件发布/证书介质/驱动及开发包/得安加密卡/SJY03B加密卡
	（2）安装网证通安全中间件，要求版本为5.6以上
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/安装包/NETCA_Crypto.exe
	（3）配置SJY03B加密卡的设备层驱动
		CheckOut下SVN的该文件夹，运行SJY03B.reg文件，并将其他所有文件拷贝到C:\Windows\System32系统目录下
		http://192.168.0.11:8081/svn/rdrelease/软件发布/NETCA_CRYPTO/current/winX86/设备驱动/得安加密卡/
	（3） 配置设备信息文件，具体配置详见第5点
	3.2 操作步骤（该步骤每次签发ARL时都需要进行）
	（1）安装加密卡和插入操作员IC卡
	（2）找到"签发工具"并运行，选择"设备信息文件"、"根证书文件"，输入"CRL数字"，选择是否设置更新时间，选择"CRL文件保存地址"，点击"签发CRL"按钮，生成XXX.crl

4.补充
（1）因为加密卡使用到门限技术，因此每次使用该ARL签发工具时，请确保插入操作员IC卡
（2）CRL数字必须由用户输入，要求为Hex编码，例如0x12345678，必须以0x开头，中间不可以有空格
	
5.设备信息文件说明
（1）该文件内容为JSON结构对象，故不可随便改动文件结构，修改对应字段的值即可
（2）具体字段说明如下：
	{
		"_keypair":
		{
			"deviceType":101,（设备类型101，固定）
			"deviceSn":"SJY03B",（设备序列号SJY03B，固定）
			"pwd":"12345678",（加密卡密码暂无，可为"12345678"）
			"keypairType":1,（密钥对类型，可由CryptoTestTool.exe工具查看）
			"keypairLabel":"RSA_1"（密钥对标签，可由CryptoTestTool.exe工具查看，1是密钥号，用户必须设置为根证书对应的密钥对的密钥号）
		}
	}