; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "�ƶ�������Կ(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "3.0.0"
#define SETUP_FILE_VERSION "3.0.0.2"
#define UID "6F1F5761-D9FC-4A9B-96C3-09D93E020EEA"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{6F1F5761-D9FC-4A9B-96C3-09D93E020EEA}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPVERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net
DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=Copyright 2019 @ NETCA.��������Ȩ����
OutputBaseFilename=NETCA_Devices(MobileKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

;����ʾ����
UninstallRestartComputer =no
ShowLanguageDialog=auto
CreateUninstallRegKey=false
ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
UsePreviousAppDir=false
VersionInfoCompany={#NETCA}
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#DEVICES_APPVERSION}
UninstallLogMode=overwrite
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCopyright=Copyright 2019 @ NETCA.��������Ȩ����
UninstallDisplayName={#DEVICES_APPNAME}
VersionInfoDescription={#DEVICES_APPNAME}������
UpdateUninstallLogAppName=false
[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl
[Messages]
chinesesimp.SetupAppTitle=�ƶ�������Կ
chinesesimp.SetupWindowTitle=�ƶ�������Կ
trad.SetupAppTitle=�Ƅ�������
trad.SetupWindowTitle=�Ƅ�������
eng.SetupAppTitle=NETCADevices_MobileKey
eng.SetupWindowTitle=NETCADevices_MobileKey
[Files]
;32λϵͳ�ļ�
Source: ..\..\winX86\�豸����\�ƶ�������Կ\MobilekeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\MobilekeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeyproxy.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\winX86\�豸����\�ƶ�������Կ\paho-mqtt3a.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeywin.exe; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeywin.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeyconfigtool.exe; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\paho-mqtt3as.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64λϵͳ�ļ�
Source: ..\..\winX64\�豸����\�ƶ�������Կ\MobilekeyProv.dll; DestDir: {app}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\�豸����\�ƶ�������Կ\netcamobilekeyproxy.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\�ƶ�������Կ\MobilekeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ��32λ�ļ�
Source: ..\..\winX86\�豸����\�ƶ�������Կ\MobilekeyProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\MobilekeyProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeyproxy.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\winX86\�豸����\�ƶ�������Կ\paho-mqtt3a.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeywin.exe; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeywin.ini; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\netcamobilekeyconfigtool.exe; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\paho-mqtt3as.dll; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

Source: ..\..\..\..\ͳһ���ʹ�����\current\������\����Ĳ��\ISTask.dll; DestDir: {app}

;3.0.0�����ļ�
;32λϵͳ�ļ�

Source: ..\..\winX86\�豸����\�ƶ�������Կ\NetcaMobileKeyUI.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\NetcaMobileKey.exe; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\NetcaMobileKey.json; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64λϵͳ32λ�ļ�

Source: ..\..\winX86\�豸����\�ƶ�������Կ\NetcaMobileKeyUI.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\NetcaMobileKey.exe; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\�ƶ�������Կ\NetcaMobileKey.json; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;64λϵͳ64λ�ļ�
Source: ..\..\winX64\�豸����\�ƶ�������Կ\NetcaMobileKeyUI.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64



[Registry]
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: type; ValueData: $0000003b; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: signature; ValueData: gxpAVaBItN6R/+/9zoz5pvkmAtBlbd5SlzltN/QUDl1Fu4B8w+rmhaV6fDJsF0ebHWKZjg2Lc8F0Rvi68i+OG1URYsecP2bDjNufam/7dYy4jgsFb3NqNpU/dAcu/yHKg+RuJZKrtPRAytiX4tRRbPheBtEA5iIeejRCF0dnkG0=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MobilekeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: multisz; ValueName: idstring; ValueData: vid_096F&pid_0002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetAllDevicesTimeOut; ValueData: $00000008; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadCertTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: SignTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DecryptTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetPwdRetryNumberTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: CreateDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: WriteDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DeleteDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetDataLengthTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: VerifyPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ChangePwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: UnlockUserPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: type; ValueData: $0000003b; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: signature; ValueData: adtCDTgkmeomJzrZQVJVm4a2sEYm2q76EEQch6wPTRg0VayA4wD7GgkhxxjA6kPtD13JSG4v1MwIVuDfe+AUb/FeVrK5ycaXjhOzz9n1PAbU7YAwNbLos1kfxwwVfY/owpWgFz49I4Paj2q+0zgsi3+4FxcMbH1Il1NSm6A2y1E=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\MobilekeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: multisz; ValueName: idstring; ValueData: vid_096F&pid_0002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetAllDevicesTimeOut; ValueData: $00000008; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadCertTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: SignTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DecryptTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetPwdRetryNumberTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: CreateDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: WriteDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DeleteDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetDataLengthTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: VerifyPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ChangePwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: UnlockUserPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64

;32λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: type; ValueData: $0000003b; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: signature; ValueData: gxpAVaBItN6R/+/9zoz5pvkmAtBlbd5SlzltN/QUDl1Fu4B8w+rmhaV6fDJsF0ebHWKZjg2Lc8F0Rvi68i+OG1URYsecP2bDjNufam/7dYy4jgsFb3NqNpU/dAcu/yHKg+RuJZKrtPRAytiX4tRRbPheBtEA5iIeejRCF0dnkG0=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MobilekeyProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: multisz; ValueName: idstring; ValueData: vid_096F&pid_0002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetAllDevicesTimeOut; ValueData: $00000008; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadCertTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: SignTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DecryptTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetPwdRetryNumberTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: CreateDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: WriteDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DeleteDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetDataLengthTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: VerifyPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ChangePwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: UnlockUserPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64

[InstallDelete]
Name: {app}\Unins_MobileKey.dat; Type: files
Name: {app}\Unins_MobileKey.exe; Type: files
[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804
trad.LanguageName=TradChinese
trad.LanguageID=$0404
eng.LanguageName=English
eng.LanguageID=$0409
[Code]
#include '..\..\..\..\ͳһ���ʹ�����\current\��װ�ű�\NETCA.iss'

function RunTask(FileName: string; bFullpath: Boolean): Boolean;
  external 'RunTask@files:ISTask.dll stdcall delayload';
function KillTask(ExeFileName: string): Integer;
  external 'KillTask@files:ISTask.dll stdcall delayload';

function InitializeSetup():boolean;
begin
	Result:=true;
	KillTask('netcamobilekeywin.exe');
end;

procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_MobileKey';

// ����������ж���ļ�
uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
// �����޸���Ӧ��ע�������
if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
begin
  //MsgBox('��⵽ϵͳ��Ҫ��', mbInformation, MB_OK);
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
  //MsgBox('��⵽ϵͳ����', mbInformation, MB_OK);
end  else  if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
begin
  //MsgBox('��⵽ϵͳ��Ҫ��', mbInformation, MB_OK);
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
  //MsgBox('��⵽ϵͳ����', mbInformation, MB_OK);
end;
 RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
end;
end;

