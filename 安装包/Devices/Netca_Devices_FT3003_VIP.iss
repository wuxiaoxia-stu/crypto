; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FT3003_VIP(32&64)"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"
#define UID  "868DD5BC-6F47-4901-8ADD-741F6FF93272"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{868DD5BC-6F47-4901-8ADD-741F6FF93272}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FT3003)_VIP
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#SETUP_FILE_VERSION}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FT3003_VIP
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FT3003_VIP

trad.SetupAppTitle=�W�Cͨ�O����_FT3003_VIP
trad.SetupWindowTitle=�W�Cͨ�O����_FT3003_VIP

eng.SetupAppTitle=NETCADevices_FT3003_VIP
eng.SetupWindowTitle=NETCADevices_FT3003_VIP
[Files]
;����3003������32λ��
Source: ..\..\..\..\֤�����\������������\����\ΨƷ����Ŀ������\WZTCsp11_3003.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64
;��˾��̬�豸DLL(32λ)
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����\ΨƷ����Ŀ������\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64

;64λϵͳ�·���3003������64λ��
Source: ..\..\..\..\֤�����\������������\����\ΨƷ����Ŀ������\WZTCsp11_3003.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
;64λϵͳ��˾��̬�豸DLL(64λ)

;64λϵͳ�·���3003������32λ��
;64λϵͳ��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\����\ΨƷ����Ŀ������\Epass3003Prov.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\ΨƷ����Ŀ������\WZTCsp11_3003.dll; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\ΨƷ����Ŀ������\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64


[Registry]
;32λϵͳע���
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: R8lscfaINgUqnnTvicoyVdjFcCOdDBTZEAE9KTd4XJARtePqM5vI6LifTXDvQPaWywWnCFic457oucgW0OILyvfKwPxhkiwh0H74vvt5fsUYrjrYUOEngpxV/rictpvy5f8vjY7N0SlIz4fjEJOoOWmDaB0tH785eGvQM7EGhv8=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: ROxE1aGrrWdpwMa9UrmYxYqbIr81YsRnZQCs60uZ/4v0JkFN8/cwjSTSZXJLY7aA4lJRpAbw8xNjTbFnJiqfzjL56RxhutD5sFYRAlLg2L/Rt5q/FS2BgrvqvowbkS6pW96SDR2HYec44H42qzzjb6yy6+wzAL9Wy0fNMeVcdbU=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: R8lscfaINgUqnnTvicoyVdjFcCOdDBTZEAE9KTd4XJARtePqM5vI6LifTXDvQPaWywWnCFic457oucgW0OILyvfKwPxhkiwh0H74vvt5fsUYrjrYUOEngpxV/rictpvy5f8vjY7N0SlIz4fjEJOoOWmDaB0tH785eGvQM7EGhv8=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

[InstallDelete]
Name: {app}\Unins_FT3003.dat; Type: files
Name: {app}\Unins_FT3003.exe; Type: files
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
NewUninsName := 'Unins_FT3003';

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
