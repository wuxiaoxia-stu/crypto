; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define CRYPTO_APPNAME "网证通安全中间件"
#define NETCA "广东省电子商务认证有限公司"
#define CRYPTO_APPVERSION "1.7"
#define SETUP_FILE_VERSION "1.7.2.2"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{9F9912F4-A5A8-4F7C-968E-DC4E540A7F58}
AppName={#CRYPTO_APPNAME}
AppVersion={#CRYPTO_APPVERSION}
AppVerName={#CRYPTO_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf64}\NETCA\NETCA_Crypto
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Crypto_x64
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#CRYPTO_APPNAME}64位
VersionInfoVersion ={#SETUP_FILE_VERSION}
UninstallDisplayName  ={#CRYPTO_APPNAME}(x64)

;ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
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

eng.SetupAppTitle=NETCA_Crypto
eng.SetupWindowTitle=NETCA_Crypto

[Files]
Source: ..\winX64\动态库\Crypto\libgmp-10.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_ASN1.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_CRYPTO.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_CRYPTO_UI.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI_RES_2052.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI_RES_1028.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\动态库\Crypto\NETCA_CRYPTO_UI_RES_1033.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_LOG.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_URL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_USBKeySvr.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_UTIL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_XML.dll; DestDir: {sys}; Flags: uninsrestartdelete

;COM
Source: ..\winX64\动态库\COM\NetcaPkiCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\winX64\动态库\COM\NETCA_XMLCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;CSP签名文件
Source: ..\winX64\CSP\NETCA_CRYPTO_RSACSP.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\NETCA_CRYPTO_RSACSP_IMP.dll; DestDir: {sys}; Flags: uninsrestartdelete

; SecuInter
Source: ..\..\..\SecuInter\4.1\x64\SecuInter.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;安全环境
Source: ..\安全环境\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete
Source: ..\winX64\动态库\Crypto\record_file_crypto.ini; DestDir: {pf64}\NETCA\keyx; Flags: uninsrestartdelete

[Registry]
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: string; ValueName: IMAGE PATH; ValueData: {app}\NETCA_CRYPTO_RSACSP.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: dword; ValueName: TYPE; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: binary; ValueName: SIGNATURE; ValueData: 56 7A 0B FA D6 66 51 FC 69 80 BE DA BC 9E E6 37 1D B4 D8 74 1D F5 61 39 9E 21 10  7A 8B BD FD F6 86 4B 67 F2 98 C6 0D 8C 90 A7 2E 9F 4D 0E 63 E0 B2 86 E4 EC 0D E5  2C CC 60 04 C8 A2 69 B8 C4 C2 78 1A 8E BD F0 D2 69 1F 8B F3 1C 2E 09 D1 0E AE  7B 15 47 D6 B9 CD AE 74 92 99 7C 97 BB 24 BD 90 F2 08 68 7C 14 0B C4 3F 0E 09 B9 9E B2 0E 78 0D A7 78 E2 2F 25 13 E0 94 DC 6A 76 B9 34 CB D2 9E 00 00 00 00 00 00 00 00; Flags: uninsdeletekey

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
