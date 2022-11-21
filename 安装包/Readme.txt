
安装结束后需要手动配置一些文件。

一、在32位系统环境下：
1、如果安装了得安加密机（SJJ0929或SJY05B） 
   *****1、打开C:\Windows\System32\SJJ0929_dtcrypt.ini文件，SserverIpAddresses项表示加密机的IP地址，请填写正确的IP地址。
  
   *****2、HKEY_LOCAL_MACHINE\SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0注册表节点，将“192.168.0.0”重命名为加密机的IP地址。
   
2、如果安装了普华加密机  
   *****1、打开C:\Program Files\phgcs\module.conf文件，HOST1项表示加密机的IP地址，请填写正确的IP地址。
   
   *****2、打开注册HKEY_LOCAL_MACHINE\SOFTWARE\NETCA\PKI\Devices\PHSJJ1011，修改KeyPairStatus项的值。
           KeyPairStatus的值通过GetKeyPairStatus.exe工具获取。

二、在64位系统环境下：
1、如果安装了得安加密机（SJJ0929或SJY05B）
   *****1.1、打开C:\Windows\SysWOW64\SJJ0929_dtcrypt.ini文件，SserverIpAddresses项表示加密机的IP地址，请填写正确的IP地址。
   *****1.2、打开C:\Windows\System32\SJJ0929_dtcrypt.ini文件，SserverIpAddresses项表示加密机的IP地址，请填写正确的IP地址。

   *****2.1、HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SJJ0929\192.168.0.0注册表节点，将“192.168.0.0”重命名为加密机的IP地址。
   *****2.2、HKEY_LOCAL_MACHINE\SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0注册表节点，将“192.168.0.0”重命名为加密机的IP地址。

2、如果安装了普华加密机
   *****1.1、打开C:\Program Files（x86）\phgcs\module.conf文件，HOST1项表示加密机的IP地址，请填写正确的IP地址。
   *****1.2、打开C:\Program Files\phgcs\module.conf文件，HOST1项表示加密机的IP地址，请填写正确的IP地址。

   *****2.1、打开注册HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\NETCA\PKI\Devices\PHSJJ1011，修改KeyPairStatus项的值。
             KeyPairStatus的值通过GetKeyPairStatus.exe工具获取。
   *****2.2、打开注册HKEY_LOCAL_MACHINE\SOFTWARE\NETCA\PKI\Devices\PHSJJ1011，修改KeyPairStatus项的值。
             KeyPairStatus的值通过GetKeyPairStatus.exe工具获取。