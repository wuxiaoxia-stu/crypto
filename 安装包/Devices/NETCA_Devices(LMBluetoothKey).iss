; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_LMBluetoothKey"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.0"
#define UID  "317BF162-900D-403C-A265-61E4DD387A2B"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{317BF162-900D-403C-A265-61E4DD387A2B}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(LMBluetoothKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}

ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;����ʾ����
AlwaysRestart =no

ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=new
VersionInfoProductVersion={#DEVICES_APPVERSION}


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_LMBluetoothKey.exe
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_LMBluetoothKey.exe

[Files]
;32λ�ļ�
Source: ..\..\winX86\�豸����\����GM3000\����KEY\LMaiBluetoothKey.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����GM3000\����KEY\LMaiBluetoothKey.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\�����Ƽ�\����KEY\skf\win32\LMaiBluetoothKey.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\�����Ƽ�\����KEY\skf\win32\mtoken_k5.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;64λ�ļ�
Source: ..\..\winX64\�豸����\����GM3000\����KEY\LMaiBluetoothKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����GM3000\����KEY\LMaiBluetoothKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\�����Ƽ�\����KEY\skf\x64\LMaiBluetoothKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\�����Ƽ�\����KEY\skf\win32\mtoken_k5.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\�����Ƽ�\����KEY\skf\x64\mtoken_k5.dll; DestDir: {sys}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion

[Registry]
;32λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E425{break}Vid_055C&Pid_E623; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: type; ValueData: $00000037; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: signature; ValueData: ThrYNfJCBv11gFzkNlGpmLP/P3kFvl3ehTHlVJ7kWRAh1qbLS3iuC/wrDKMxb+2rL54VMpr0AM+D4y57CCt3ivkzr7YE8xFXMayZ+hd6Aaz9f1jNOjCt+oow1oTu7Gncj49WCDAeFw+pK8nNEK32CB+B0SSuGtSaJHJlJ5ECJiU=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: dllpath; ValueData: {app}\LMaiBluetoothKey.dll; Flags: uninsdeletekey; Check: not IsWin64
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E425{break}Vid_055C&Pid_E623; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: type; ValueData: $00000037; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: signature; ValueData: ThrYNfJCBv11gFzkNlGpmLP/P3kFvl3ehTHlVJ7kWRAh1qbLS3iuC/wrDKMxb+2rL54VMpr0AM+D4y57CCt3ivkzr7YE8xFXMayZ+hd6Aaz9f1jNOjCt+oow1oTu7Gncj49WCDAeFw+pK8nNEK32CB+B0SSuGtSaJHJlJ5ECJiU=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: dllpath; ValueData: {app}\LMaiBluetoothKey.dll; Flags: uninsdeletekey; Check: IsWin64

;64λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E425{break}Vid_055C&Pid_E623; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: type; ValueData: $00000037; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: signature; ValueData: i1aJsQXMf2JBHm6TnNdhbAQ/lHTQdOQI0OXGXmW+3pzPew6w24wCD+MS/9gGDwwwQv7t7eIApG+O3M7A+8Njla2LWE7UvL9vVbsIb9zbM9Yx3pE05399R/DcOhzSX8HkSvEcENIN8TZpkX7r4mPb/IqSLVvAAPYpCrttn49o4E4=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\LMaiBluetoothKey.dll; Flags: uninsdeletevalue; Check: IsWin64

[Code]
function IsX64: Boolean;
begin
  Result := (ProcessorArchitecture = paX64);
end;

function IsIA64: Boolean;
begin
  Result := (ProcessorArchitecture = paIA64);
end;

function IsWin64: Boolean;
begin
  Result :=IsX64 or IsIA64;
end;


procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_LMBluetoothKey';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
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
end;
end;
end;
