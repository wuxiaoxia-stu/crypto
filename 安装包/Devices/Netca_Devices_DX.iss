; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_DX(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.9"
#define UID  "DF6F6DF1-D1BF-4068-B199-A111A7100CE9"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{DF6F6DF1-D1BF-4068-B199-A111A7100CE9}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(DX)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
CreateUninstallRegKey=false
UninstallLogMode=overwrite
VersionInfoProductVersion={#APPVERSION}
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_DX
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_DX

trad.SetupAppTitle=�W�Cͨ�O����_DX
trad.SetupWindowTitle=�W�Cͨ�O����_DX

eng.SetupAppTitle=NETCADevices_DX
eng.SetupWindowTitle=NETCADevices_DX

[Files]
;32λϵͳ�豸����
Source: ..\..\winX86\�豸����\����\USBKey\NetcaDingXin.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch
Source: ..\..\winX86\�豸����\����\USBKey\NetcaDingXin.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch
Source: ..\..\winX86\�豸����\����\USBKey\NetcaDingXin.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch
Source: ..\..\..\..\֤�����\������������\����\USB Key\SKF\win32\SKF_T1.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch

;64λϵͳ32λ����
Source: ..\..\winX86\�豸����\����\USBKey\NetcaDingXin.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����\USBKey\NetcaDingXin.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����\USBKey\NetcaDingXin.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\USB Key\SKF\win32\SKF_T1.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ�豸����
Source: ..\..\winX64\�豸����\����\USBKey\NetcaDingXin.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����\USBKey\NetcaDingXin.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����\USBKey\NetcaDingXin.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\USB Key\SKF\win64\SKF_T1.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;32λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: class; ValueData: USB; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: signature; ValueData: HJmEWqN6A367fRWTI5EL7m0HfXlRrSi18JfmT6BiTGRy+ScdV3O2tI3ck+/xNfNnHu59BHkNJrv2L54joBXFMA5RZMZ4dpwKN48Zj3mn+jtQUc/i/fEFUwbdF6LHilSeoGBRWI1WF8R66jyokZfiVGFsTRxpFMieUghk7DTirOI=; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaDingXin.dll; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: type; ValueData: $00000042; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: multisz; ValueName: idstring; ValueData: vid_2FD0&pid_1000; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsOtherArch; Flags: uninsdeletekey


;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: signature; ValueData: HJmEWqN6A367fRWTI5EL7m0HfXlRrSi18JfmT6BiTGRy+ScdV3O2tI3ck+/xNfNnHu59BHkNJrv2L54joBXFMA5RZMZ4dpwKN48Zj3mn+jtQUc/i/fEFUwbdF6LHilSeoGBRWI1WF8R66jyokZfiVGFsTRxpFMieUghk7DTirOI=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaDingXin.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: type; ValueData: $00000042; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: multisz; ValueName: idstring; ValueData: vid_2FD0&pid_1000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: signature; ValueData: WOw7XfJrqBgh5XUYzF+L8kQIHm5/u7ZndGCWhot96XZ2pp962JjFwFW4qxdHPyXz4w03qvRN7AgayZRyStGRouneYkhqSFP6mLbpwxSBzl5fTYU+gdYNWHcmK8l0Jdrgv9wBI5quQANjC5PSNcsAOKhlADZGKmd7NzRpP/njmu8=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\NetcaDingXin.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: type; ValueData: $00000042; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: multisz; ValueName: idstring; ValueData: vid_2FD0&pid_1000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[InstallDelete]
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files
Name: {app}\Unins_DX.exe; Type: files
Name: {app}\Unins_DX.dat; Type: files

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
uninspath, uninsname, NewUninsName : string;
begin
if CurStep=ssInstall then
begin
      //MsgBox('ȷ����װ֮ǰ�����ڵĻ�׼��ɾ���ɰ汾ע���', mbInformation, MB_OK);
        if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyDX') then
       RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyDX');
      if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX') then
       RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX');
     //  MsgBox('ȷ����װ֮ǰ�����ڵĻ�ɾ��ע���ɹ�����ʼ��װ�°汾', mbInformation, MB_OK);
end;

if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_DX';
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
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
end;
end;
end;

[_ISTool]
UseAbsolutePaths=false
