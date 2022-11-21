; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{5A68E393-0038-473C-A3C0-6ED50F775CAB}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

OutputBaseFilename=NETCA_Devices_x86(ADBSDKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(ADBSDKey)
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����
chinesesimp.SetupWindowTitle=��֤ͨ�豸����

trad.SetupAppTitle=�W�Cͨ�O����
trad.SetupWindowTitle=�W�Cͨ�O����

eng.SetupAppTitle=NETCADevices
eng.SetupWindowTitle=NETCADevices
[Files]
DestDir: {app}; Source: ..\..\winX86\�豸����\ADBSDKey\ADBSDKeyProvider.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\�豸����\ADBSDKey\����\adb.exe; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\�豸����\ADBSDKey\����\adbp11.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\�豸����\ADBSDKey\����\AdbWinApi.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\�豸����\ADBSDKey\����\AdbWinUsbApi.dll; Flags: uninsrestartdelete


[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: string; ValueName: signature; ValueData: oz0g2VLEseMv3e2YVeAg/0CN36x2XzFj7cyjOZvrhZtBue/zTnTQ/A5O1w6Gge0yLD7p+QU8YK94s0bdLLApmu/WW19KHukgRDxgUOKDz/pk1avjdT2HzL++8FSkjJT7m5puXoXDFInSIAERtKABOW0oak48ES72rm8V87JtMCQ=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: string; ValueName: class; ValueData: SDKey; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: dword; ValueName: type; ValueData: $00000026; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: multisz; ValueName: idstring; ValueData: Vid_12D1&Pid_1035; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: string; ValueName: dllpath; ValueData: {app}\ADBSDKeyProvider.dll; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
