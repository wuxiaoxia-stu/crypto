; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_HDSDCard"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.11"
#define UID  "133E929D-A847-43F4-A534-4928CCB17D1A"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{133E929D-A847-43F4-A534-4928CCB17D1A}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(HDSDCard)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}

ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
AlwaysRestart =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
ArchitecturesInstallIn64BitMode=x64 ia64

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_HDSDCard
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_HDSDCard

[Files]
Source: ..\..\winX86\�豸����\����SDKey\HDMicroSDKey.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����SDKey\HDMicroSDKey.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\����sdkey\����SM2\Release_2015-12-08\Win32\HDMicroSDKey.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\����sdkey\����SM2\Release_2015-12-08\Win32\HD_Cryptoki.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����sdkey\����SM2\Release_2015-12-08\Win32\HD_Token.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����sdkey\����SM2\Release_2015-12-08\Win32\HD_Token.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����sdkey\����SM2\Release_2015-12-08\Win32\HD_Cryptoki.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
[Registry]
;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HDMicroSDKey.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: MzlBuDQqzTgVINISN48bqqPBJDgCwQ+da1oe8sSb0PyST0qKweSYmSbHeOrRnlfmkHsjcPcG4YhW9Eygk29KPtLUB5iB+QiJMkAzrIMn901+ydxrdLD9ho+8aDtJzrwHSWMBUpeecyOEXH73NUlR3YGX26qWTiuSlxdrLsfnKhk=; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: C:\Windows\system32\HD_Cryptoki.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: C:\Windows\SysWOW64\HD_Cryptoki.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: MzlBuDQqzTgVINISN48bqqPBJDgCwQ+da1oe8sSb0PyST0qKweSYmSbHeOrRnlfmkHsjcPcG4YhW9Eygk29KPtLUB5iB+QiJMkAzrIMn901+ydxrdLD9ho+8aDtJzrwHSWMBUpeecyOEXH73NUlR3YGX26qWTiuSlxdrLsfnKhk=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HDMicroSDKey.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: 1; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: 1; Flags: uninsdeletevalue; Check: IsWin64

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
NewUninsName := 'Unins_HDSDCard';
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
