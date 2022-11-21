; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_SoftCert"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.2"
#define UID  "D31DCAEE-1110-4522-8984-D14ABE57686C"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{D31DCAEE-1110-4522-8984-D14ABE57686C}
;Ӧ�ó�����Ϣ
AppName={#DEVICES_APPNAME}
AppVerName={#DEVICES_APPNAME}
AppCopyright={#NETCA}����������Ȩ����
UninstallRestartComputer =no
ShowLanguageDialog=auto
UninstallLogMode=overwrite
UninstallDisplayName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

;Ӧ�ó���Ŀ¼
DefaultDirName={pf}\NETCA\NETCA_Devices

;�������  ѹ��
OutputBaseFilename=NETCA_Devices(SoftCert)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;�汾��Ϣ
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCompany={#NETCA}
VersionInfoDescription={#DEVICES_APPNAME}����
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#DEVICES_APPVERSION}
CreateUninstallRegKey=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_SoftCert
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_SoftCert

trad.SetupAppTitle=�W�Cͨ�O����_SoftCert
trad.SetupWindowTitle=�W�Cͨ�O����_SoftCert

eng.SetupAppTitle=NETCADevices_SoftCert
eng.SetupWindowTitle=NETCADevices_SoftCert

[Files]

;�豸dll(32λϵͳ32λ�ļ�)
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;�豸dll(64λϵͳ��32λ�ļ�)
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;�豸dll(64λϵͳ��64λ�ļ�)
Source: ..\..\..\winX64\�豸����\��֤��\NetcaSoftKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\��֤��\NetcaSoftKeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32λϵͳ32λע���-NetcaSoftKeyProv_32.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: cLQpKQ8WyZo7cMxLjr8I9PoknkGuW0/UL36W4QR2G6PfVuOlCdqhcv5DU+T76PKCl12abyqEWHONOKYamwPuVH/xQHJZ6Y1TL/HN7K/SNSkJv3KXTyA7q8LXnNuAu9yn5nvht2nr/fYWtYOZ52sinsiSEpxi1FAZyAozaEW5QkQ=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64

Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���-NetcaSoftKeyProv_64.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: cLQpKQ8WyZo7cMxLjr8I9PoknkGuW0/UL36W4QR2G6PfVuOlCdqhcv5DU+T76PKCl12abyqEWHONOKYamwPuVH/xQHJZ6Y1TL/HN7K/SNSkJv3KXTyA7q8LXnNuAu9yn5nvht2nr/fYWtYOZ52sinsiSEpxi1FAZyAozaEW5QkQ=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64

;64λϵͳ64λע���-NetcaSoftKeyProv.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: Tph153TQPqh33+xO+/oLn55utzU3Wi6qck18CrVkbezRIt+fIwdLvPK8U+Y9YmfRbK0ihmA6tgTZbXxtqE73rInfSPgAKt8zn8bpzzzGX9H9zwEriex/BSCkjzNQdeeLRCp+TJv+U4OBSJa99PAGj8sDzjIYdQDIkmCJ7PxpGwk=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64




[InstallDelete]
Name: {app}\Unins_NetcaKeySoftCert.dat; Type: files
Name: {app}\Unins_NetcaKeySoftCert.exe; Type: files
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[_ISTool]
UseAbsolutePaths=false
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
NewUninsName := 'Unins_SoftCert';
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
