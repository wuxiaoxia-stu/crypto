; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_Weepal(32λ)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.8"
#define UID "4904D61A-C8E3-4B64-A9F6-948F9E4A6ED5"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{4904D61A-C8E3-4B64-A9F6-948F9E4A6ED5}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(weepal2001)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32λ
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
ShowLanguageDialog=auto
CreateUninstallRegKey=true

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_Weepal2001
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_Weepal2001

trad.SetupAppTitle=�W�Cͨ�O����_Weepal2001
trad.SetupWindowTitle=�W�Cͨ�O����_Weepal2001

eng.SetupAppTitle=NETCADevices_Weepal2001
eng.SetupWindowTitle=NETCADevices_Weepal2001
[Files]
;Weepal2001������32λ��
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211.sig; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211_s.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion

;��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\WeepalEpass2001Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion


[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\WeepalEpass2001Prov.dll; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: signature; ValueData: EJ9gSsWtK36prGZjQG95NqfrQ1FSzod/IIDfAX6V4XJO3VXSfxRd7TTmpZHQjcBBFl8541BhTtge9O7d39y0TuC7pbJDpPG0yeZ/tbHu0/FwO/CuTTzFXZFHfQcWh6ggaCFwQSEYGXwXrXJRDykypiNrNsM7aecvwFb+JlLpVbY=; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: type; ValueData: $00000008; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0803; Flags: uninsdeletevalue

[InstallDelete]
Name: {app}\Unins_weepal2001.dat; Type: files
Name: {app}\Unins_weepal2001.exe; Type: files

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
[Code]

procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_weepal2001';

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
