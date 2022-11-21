; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define CRYPTO_APPNAME "网证通安全中间件"
#define KEYX "广东省电子商务认证有限公司"
#define CRYPTO_APPVERSION "1.6"
#define SETUP_FILE_VERSION "1.6.2.6"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{9A7B68E0-AFBA-4361-80C7-72DD090ED45E}
AppName={#CRYPTO_APPNAME}
AppVersion={#CRYPTO_APPVERSION}
AppVerName={#CRYPTO_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher={#KEYX}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf64}\NETCA\NETCA_Crypto

OutputBaseFilename=NETCA_Crypto_x64_Setup
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
Source: ..\动态库\win x64\libgmp-10.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_ASN1.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_CRYPTO.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_CRYPTO_UI.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI_RES_2052.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI_RES_1028.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI_RES_1033.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_LOG.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_URL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_USBKeySvr.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_UTIL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_XML.dll; DestDir: {sys}; Flags: uninsrestartdelete

;COM
Source: ..\动态库\win x64\NetcaPkiCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\动态库\win x64\NETCA_XMLCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;CSP签名文件
Source: ..\动态库\win x64\NETCA_CRYPTO_RSACSP.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\动态库\win x64\NETCA_CRYPTO_RSACSP_IMP.dll; DestDir: {sys}; Flags: uninsrestartdelete

; SecuInter
Source: ..\..\..\SecuInter\4.1\x64\SecuInter.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;安全环境
Source: ..\安全环境\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete

;明华USBKey驱动文件
Source: ..\..\..\证书介质\驱动及开发包\明华\NETCAKEY_MWV2V3.exe; DestDir: {app}; Flags: deleteafterinstall

;飞天3003驱动文件
Source: ..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\WZTCsp11_3003.DLL; DestDir: {sys}; Flags: uninsrestartdelete 64bit

;海泰驱动文件
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GEC00001.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001.ini; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.ini; DestDir: {sys}; Flags: uninsrestartdelete 64bit

;深圳文鼎创驱动文件
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217API.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217CFG.bin; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217CSP.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217CSPSi.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217Drv00.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit


;设备接口库
;明华V2
Source: ..\动态库\公司证书签名设备dll\明华2版\x64\System32\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit
;飞天3003
Source: ..\..\..\NETCA_CRYPTO\current\动态库\公司证书签名设备dll\飞天3003\x64\System32\Epass3003Prov.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit
;海泰
Source: ..\..\..\NETCA_CRYPTO\current\动态库\公司证书签名设备dll\海泰\x64\System32\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit
;文鼎创
Source: ..\..\..\NETCA_CRYPTO\current\动态库\公司证书签名设备dll\文鼎创\x64\System32\ESKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit


[Registry]
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: string; ValueName: IMAGE PATH; ValueData: {app}\NETCA_CRYPTO_RSACSP.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: dword; ValueName: TYPE; ValueData: $1; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: binary; ValueName: SIGNATURE; ValueData: 56 7A 0B FA D6 66 51 FC 69 80 BE DA BC 9E E6 37 1D B4 D8 74 1D F5 61 39 9E 21 10  7A 8B BD FD F6 86 4B 67 F2 98 C6 0D 8C 90 A7 2E 9F 4D 0E 63 E0 B2 86 E4 EC 0D E5  2C CC 60 04 C8 A2 69 B8 C4 C2 78 1A 8E BD F0 D2 69 1F 8B F3 1C 2E 09 D1 0E AE  7B 15 47 D6 B9 CD AE 74 92 99 7C 97 BB 24 BD 90 F2 08 68 7C 14 0B C4 3F 0E 09 B9 9E B2 0E 78 0D A7 78 E2 2F 25 13 E0 94 DC 6A 76 B9 34 CB D2 9E 00 00 00 00 00 00 00 00; Flags: uninsdeletekey

;明华V2
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV2Prov.dll; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: QDy/OmyWW3qxbRINsA1N9EMi+R3lXHGvZHUYPbyCetc/9lyhA86Pc2SwxyfeLli+gtPc0N7W5cWn8K58KCsf5pao1Xm7zsLgQ5IGutxDT6IVvAlrruDGdYSjlncR2URE5n40cgN/I4VC5bK3v0SoGAwq0Ip/T+LJBez0hsFOxWc=; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;飞天3003 64bit注册表文件
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {app}\Epass3003Prov.dll; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: RlptXqyJkDjVPrdSzomVQ+AGltoL2jAcRwn/orif9yTeshJmJWENoUJhHM3lVSdWn73waW38teheOZUt3aMm0OBvhULHXmZURWQ54fjQgftm7qdCS02Li+kvFO3Rfo/jdesqjDbkNsrh0U4G38+GaVaJn1WB9hoKcxogSOHTC4I=; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;海泰64位注册表
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {app}\HTEKey.dll; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: Ej4MzLjXBOmyWvDf2tVghPx8mnrduhSF/tk6xZ/wjFeUlvsFLRVrxTsz94brpleOuL7oihpPV8/CvduQhzU8SscY0NBMnIpy9rDGGFOV2dFFz/bkw9OK0V8eSgs8ZFphBWIgoKnDI5IRh5qsBR64jWZzFyTtUNnaAEO7VJRaNL8=; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;文鼎创64bit注册表文件
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: Q3FsZ9ahZ6PWSnJBGJCPTrcawJ+wfgfJq1DlLOnlPtO5fdN2W0unGTSpGxFmqpTJi+8+AmFfN8xVFrMBpMR29n1/UoET6/02xP8HoY8u5vKvfQuWaIwGKY5FSskfl69mJQQ0KNZaZdy/xCCq3SemQzTl329puVLlYhRN//KG5Zw=; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {app}\ESKeyProv.dll; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey



[Run]
Filename: {app}\NETCAKEY_MWV2V3.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {sys}

[UninstallRun]
Filename: {pf32}\NETCA\NETCAKEY_MWHS1\unins000.exe; WorkingDir: {pf32}\NETCA\NETCAKEY_MWHS; Parameters: /SP- /VERYSILENT /NORESTART

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
