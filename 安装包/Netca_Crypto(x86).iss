; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define CRYPTO_APPNAME "网证通安全中间件"
#define NETCA "广东省电子商务认证有限公司"
#define CRYPTO_APPVERSION "1.7"
#define SETUP_FILE_VERSION "1.7.2.3"
#define NPNETCAPKI_VERSION "1.0.0.1"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{A0B399CD-984F-41F2-9A5D-E3BF7A54E696}
AppName={#CRYPTO_APPNAME}
AppVersion={#CRYPTO_APPVERSION}
AppVerName={#CRYPTO_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Crypto

AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Crypto_x86
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#CRYPTO_APPNAME}32位
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通安全中间件
chinesesimp.SetupWindowTitle=网证通安全中间件

trad.SetupAppTitle=網證通安全中間件
trad.SetupWindowTitle=網證通安全中間件

eng.SetupAppTitle=NETCACrypto
eng.SetupWindowTitle=NETCACrypto

[Files]
;网证通安全中间件相关文件
Source: ..\winX86\动态库\Crypto\NETCA_USBKeySvr.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_URL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_UTIL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_ASN1.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_XML.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_LOG.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\libgmp-10.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI_RES_2052.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI_RES_1028.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI_RES_1033.DLL; DestDir: {sys}; Flags: uninsrestartdelete

;COM
Source: ..\winX86\动态库\COM\NetcaPkiCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\winX86\动态库\COM\NETCA_XMLCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\winX86\动态库\Chrome\npnetcapki.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\COM\NetcaRAClientCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;CSP签名文件
Source: ..\winX86\CSP\NETCA_CRYPTO_RSACSP.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_RSACSP_IMP.dll; DestDir: {sys}; Flags: uninsrestartdelete

;SecuInter
Source: ..\..\..\SecuInter\4.1\x86\SecuInter.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;trust文件
Source: ..\安全环境\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\record_file_crypto.ini; DestDir: {pf}\NETCA\keyx; Flags: uninsrestartdelete

[Registry]
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: string; ValueName: IMAGE PATH; ValueData: {sys}\NETCA_CRYPTO_RSACSP.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: binary; ValueName: SIGNATURE; ValueData: 83 7d df a4 7d b0 6a c3 f1 e3 49 16 30 f4 e2 be 07 23 ee 70 3b fb 60 13 8c 3a 63 8e 64 93 df 99 b6 69 f8 0e 79 ea f3 46 1e 97 2f f2 a6 f7 22 43 36 56 04 7c e3 e1 cb 94 e9 1e 66 fa 24 bf 3b 1a df de 3d 5f fc ff 54 c2 ca 3c 4f bc 57 7d 69 83 25 ac 72 43 41 ad a9 af b3 8f e8 c2 1d eb 4d 91 61 af 32 8b f7 44 5f f4 d5 de cb a4 2a cc 54 62 41 1e cf de dd 74 18 1a ad 8f d6 eb 0e 44 c9 6c 00 00 00 00 00 00 00 00; Flags: uninsdeletevalue
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: dword; ValueName: TYPE; ValueData: $00000001; Flags: uninsdeletekey

;npnetcapki.dll的注册表
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Description; ValueData: 中间件应用于Firefox的插件; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Path; ValueData: {app}\npnetcapki.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: ProductName; ValueData: npnetcapki; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Vendor; ValueData: NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Version; ValueData: {#NPNETCAPKI_VERSION}; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
