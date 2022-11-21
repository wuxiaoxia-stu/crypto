; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define Crypto_APPNAME "NetcaCryptoSvr"
#define Crypto_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.7"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{5A1A5767-6103-4C39-A9E4-DF4FBBD919FC}
AppName={#Crypto_APPNAME}
AppVersion={#Crypto_APPVERSION}
AppVerName={#Crypto_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\netca\NetcaCryptoSvr

OutputBaseFilename=NetcaCryptoSvr
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#Crypto_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
;安装包的图标
;SetupIconFile=..\..\..\统一介质管理工具\current\发布版\NETCA.ico
CreateUninstallRegKey=false
Uninstallable=false
PrivilegesRequired=none
ShowLanguageDialog=no

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=NetcaCryptoSvr
chinesesimp.SetupWindowTitle=NetcaCryptoSvr

[Files]
Source: ..\winX86\非IE调用中间件\NetcaCryptoSvr.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\winX86\非IE调用中间件\ModefyFireFoxSet.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\winX86\非IE调用中间件\ModifyChromeSet.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\winX86\非IE调用中间件\setting.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

[Registry]
Root: HKCU; SubKey: Software\Microsoft\Internet Explorer\ProtocolExecute\NetcaCryptoSvr; ValueType: dword; ValueName: WarnOnOpen; ValueData: $00000000
Root: HKCR; SubKey: NetcaCryptoSvr; ValueType: string; ValueName: ; ValueData: URL:RunApp Protocol
Root: HKCR; SubKey: NetcaCryptoSvr; ValueType: string; ValueName: URL Protocol; ValueData: {app}\NetcaCryptoSvr.exe
Root: HKCR; SubKey: NetcaCryptoSvr\DefaultIcon; ValueType: string; ValueName: ; ValueData: {app}\NetcaCryptoSvr.exe,1
Root: HKCR; SubKey: NetcaCryptoSvr\shell\open\command; ValueType: string; ValueName: ; ValueData: """{app}\NetcaCryptoSvr.exe"" ""%1"""

[Run]
Filename: {app}\ModifyChromeSet.exe; Parameters: /sp- /VERYSILENT /norestart; WorkingDir: {app}; Flags: runminimized runhidden
Filename: {app}\ModefyFireFoxSet.exe; Parameters: /sp- /VERYSILENT /norestart; WorkingDir: {app}; Flags: runminimized runhidden

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
