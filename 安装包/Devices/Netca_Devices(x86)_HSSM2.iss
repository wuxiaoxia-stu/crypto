; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_HSSM2(32λ)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.15"
#define UID  "3BA3B438-0B5C-49D2-9B23-8023E10C5EA0"


[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{3BA3B438-0B5C-49D2-9B23-8023E10C5EA0}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(HSSM2)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32λ
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
;UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductVersion={#DEVICES_APPVERSION}
UninstallDisplayName={#DEVICES_APPNAME}
VersionInfoCompany={#NETCA}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
VersionInfoCopyright={#NETCA}����������Ȩ����
CreateUninstallRegKey=false


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_����SM2
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_����SM2

trad.SetupAppTitle=�W�Cͨ�O����_HSSM2
trad.SetupWindowTitle=�W�Cͨ�O����_HSSM2

eng.SetupAppTitle=NETCADevices_HSSM2
eng.SetupWindowTitle=NETCADevices_HSSM2

[Files]

;��˾��̬�豸DLL(32λ)
Source: ..\..\winX86\�豸����\����SM2\NETCAHSICKey.dll; DestDir: {app}; Flags: ignoreversion restartreplace
Source: ..\..\winX86\�豸����\����SM2\NETCAHSICKey.dll_device.ini; DestDir: {app}; Flags: ignoreversion restartreplace
Source: ..\..\..\..\֤�����\������������\����SM2\�ӿڿ�\SKF_APP.dll; DestDir: {sys}; Flags: ignoreversion restartreplace
Source: ..\..\..\..\֤�����\������������\����SM2\�ӿڿ�\SKF_Token_HSIC.dll; DestDir: {sys}; Flags: ignoreversion restartreplace
Source: ..\..\..\..\֤�����\������������\����SM2\�ӿڿ�\HSIC DriverSetup.exe; DestDir: {app}; Flags: ignoreversion deleteafterinstall
Source: ..\..\..\..\֤�����\������������\����SM2\�ӿڿ�\NETCAHSICKey.dll_driver.ini; DestDir: {app}; Flags: ignoreversion restartreplace

[Registry]
;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: dllpath; ValueData: {app}\NETCAHSICKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: signature; ValueData: rpn26O+UTycdlX3EoAzdghLXC6VRtz4fM0wAmiVCfMOEku0Y55iJ7NV9daTuZr0VfsxUQKGZ9tMgTG0pcaI0NYqvbWcreLg9V0nN7M6utJTpjPBMCenEdNqAO/l/owoLt4ua+c1uMH8MNbb1sMga+Nk60+AR9YCb8t1hy8268dY=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: type; ValueData: $00000031; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_1D99&Pid_0001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: dllpath; ValueData: {app}\NETCAHSICKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: signature; ValueData: rpn26O+UTycdlX3EoAzdghLXC6VRtz4fM0wAmiVCfMOEku0Y55iJ7NV9daTuZr0VfsxUQKGZ9tMgTG0pcaI0NYqvbWcreLg9V0nN7M6utJTpjPBMCenEdNqAO/l/owoLt4ua+c1uMH8MNbb1sMga+Nk60+AR9YCb8t1hy8268dY=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: type; ValueData: $00000031; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_1D99&Pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

[InstallDelete]
Name: {app}\Unins_HSSM2.dat; Type: files
Name: {app}\Unins_HSSM2.exe; Type: files

[Run]
Filename: {app}\HSIC DriverSetup.exe; WorkingDir: {app}; Flags: runminimized runhidden runascurrentuser; Parameters: /sp- /VERYSILENT /norestart  /s

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

function IsOtherArch: Boolean;
begin
  Result := not IsX64 and not IsIA64;
end;

function IsWin64: Boolean;
begin
  Result :=IsX64 or IsIA64;
end;

function TestBit: Boolean;
begin
  Result := Is64BitInstallMode;

   if Is64BitInstallMode then
    MsgBox('Installing in 64-bit mode', mbInformation, MB_OK)
  else
    MsgBox('Installing in 32-bit mode', mbInformation, MB_OK)
end;

procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_HSSM2';
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
