; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define Crypto_APPNAME "NetcaCryptoSvr"
#define Crypto_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.7"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{5A1A5767-6103-4C39-A9E4-DF4FBBD919FC}
AppName={#Crypto_APPNAME}
AppVersion={#Crypto_APPVERSION}
AppVerName={#Crypto_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
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
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
;��װ����ͼ��
;SetupIconFile=..\..\..\ͳһ���ʹ�����\current\������\NETCA.ico
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
Source: ..\winX86\��IE�����м��\NetcaCryptoSvr.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\winX86\��IE�����м��\ModefyFireFoxSet.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\winX86\��IE�����м��\ModifyChromeSet.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\winX86\��IE�����м��\setting.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

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
