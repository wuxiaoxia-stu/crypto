; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_MWV2V3"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define APPVERSION "1.1.0"
#define SETUP_FILE_VERSION "1.1.0.22"
#define UID  "96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(MWV2V3)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(32λ)


ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
UninstallLogMode=overwrite
CreateUninstallRegKey=false
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCompany={#NETCA}
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#APPVERSION}


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_MW23
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_MW23

trad.SetupAppTitle=�W�Cͨ�O����_MW23
trad.SetupWindowTitle=�W�Cͨ�O����_MW23

eng.SetupAppTitle=NETCADevices_MW23
eng.SetupWindowTitle=NETCADevices_MW23

[Files]

;USBKey��������
Source: ..\..\..\..\֤�����\������������\����\MWTokenAPI.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64

Source: ..\..\..\..\֤�����\������������\����\MWTokenAPI.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\NETCA_V2V3_02320.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

Source: ..\..\winX86\�豸����\����2��\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\�豸����\����2��\MWEKeyV2Prov.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\..\..\֤�����\������������\����\MWEKeyV2Prov.dll_driver.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

Source: ..\..\winX86\�豸����\����3��\MWEKeyV3Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\�豸����\����3��\MWEKeyV3Prov.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\..\..\֤�����\������������\����\MWEKeyV3Prov.dll_driver.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace


[Registry]
;32λϵͳע��� ��������:
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: gB9+QFd5676Yi9pZrzPBDQpRKOSnVQxNpQcPnJ3J34o2YU6RfIZkw5/U7jbeWG/g8e4PboXdTH4BMENOub28MCwXssZK5dRvCdxTsfE4Yi9HKYVFjXTZQBiTi1DkYtLPXw0vdKvXnw5ZhB/H+QpuJCvylrZtF/YBv/aIT/NU8ts=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64
;32λϵͳע��� ��������:
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: dUhkvdzcJkqPGX0mIQOKDDk4rIJLifWE3UAhFauB8VgkBUwhWwlWp+I+NPAVzype1hV3RRCV0FrsweMKZLQEKIijnykZ0/L6v6/qa/g5Q724xmsuihXw4ev4g7I/8uJwBMnu0MlFrKTsL+Gs/TlhqJWL+w0nJAOd/7gTKbZvNBo=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: $00000006; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
;64λϵͳע��� ��������:
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: gB9+QFd5676Yi9pZrzPBDQpRKOSnVQxNpQcPnJ3J34o2YU6RfIZkw5/U7jbeWG/g8e4PboXdTH4BMENOub28MCwXssZK5dRvCdxTsfE4Yi9HKYVFjXTZQBiTi1DkYtLPXw0vdKvXnw5ZhB/H+QpuJCvylrZtF/YBv/aIT/NU8ts=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;64λϵͳע��� ��������:
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: $00000006; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: dUhkvdzcJkqPGX0mIQOKDDk4rIJLifWE3UAhFauB8VgkBUwhWwlWp+I+NPAVzype1hV3RRCV0FrsweMKZLQEKIijnykZ0/L6v6/qa/g5Q724xmsuihXw4ev4g7I/8uJwBMnu0MlFrKTsL+Gs/TlhqJWL+w0nJAOd/7gTKbZvNBo=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64



[Run]
Filename: {app}\NETCA_V2V3_02320.exe; Parameters: /SP- /VERYSILENT /NORESTART /SUPPRESSMSGBOXES; WorkingDir: {sys}; Flags: runhidden runminimized

[InstallDelete]
Name: {pf}\NETCA\NETCAKEY_MWHS\unins000.exe; Type: filesandordirs
Name: {pf}\NETCA\NETCAKEY_MWHS\unins000.dat; Type: filesandordirs

[UninstallRun]
Filename: {pf32}\NETCA\NETCAKEY_MWHS\unins000.exe; WorkingDir: {pf32}\NETCA\NETCAKEY_MWHS; Parameters: /SP- /VERYSILENT /NORESTART

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

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
NewUninsName := 'Unins_MWV2V3';

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
end;
end;


function InitializeSetup(): boolean;
begin

            if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1') then
            RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1');

            if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1') then
            RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1');
result:= true;
end;
