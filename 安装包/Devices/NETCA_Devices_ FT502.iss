; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FT502"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "91475A34-A752-47C0-A5B8-FF103014867F"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{91475A34-A752-47C0-A5B8-FF103014867F}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices_FT502
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
VersionInfoProductVersion={#DEVICES_APPVERSION}
ArchitecturesInstallIn64BitMode=x64 ia64

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FT502
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FT502

[Files]
;;32λϵͳ32λ�ļ�
Source: ..\..\winX86\�豸����\����502\ShuttleFT502Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\����502\ShuttleFT502Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����502\֧��X86_64\x86\csp11_ft502.dll; DestDir: {sys}; Flags: ignoreversion; Check: not IsWin64
;;64λϵͳ32λ�ļ�
Source: ..\..\winX86\�豸����\����502\ShuttleFT502Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����502\ShuttleFT502Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����502\֧��X86_64\x86\csp11_ft502.dll; DestDir: {syswow64}; Flags: ignoreversion; Check: IsWin64
;;64λϵͳ64λ�ļ�
Source: ..\..\winX64\�豸����\����502\ShuttleFT502Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����502\ShuttleFT502Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����502\֧��X86_64\x64\csp11_ft502.dll; DestDir: {sys}; Flags: ignoreversion; Check: IsWin64


[Registry]
;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\ShuttleFT502Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: signature; ValueData: oDY0QB8h+qFCU0KPzW9bWxJU+tl2PpCgGmX134oPCUFD2NiOG6aLvcSAd0cjKH7iWuyp/rkG8fO0zNABQmG2fxeagyUdekGBtdTBL4Zw+4GpJr6IqYr7YGBLjIffoOSyL9XZrgExh5Y2U5sMrbBccPUVd99ZiQOHaMgXf+tZVJA=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: type; ValueData: $00000009; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0608{break}Vid_096E&Pid_060D; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: {sys}\csp11_ft502.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: {syswow64}\csp11_ft502.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0608{break}Vid_096E&Pid_060D; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: type; ValueData: $00000009; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: signature; ValueData: oDY0QB8h+qFCU0KPzW9bWxJU+tl2PpCgGmX134oPCUFD2NiOG6aLvcSAd0cjKH7iWuyp/rkG8fO0zNABQmG2fxeagyUdekGBtdTBL4Zw+4GpJr6IqYr7YGBLjIffoOSyL9XZrgExh5Y2U5sMrbBccPUVd99ZiQOHaMgXf+tZVJA=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\ShuttleFT502Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\ShuttleFT502Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: signature; ValueData: GAn6hb5/ZBArctLUXeNciqLAtfPRiXmoDXpw0OhoE+iLixtEhhTls2N0xp2XWfoENzQVIcttUd+Rq/vzN1pmF/YlfzBfMQfVdED3JCmo3HBEma14vh+tzUIqiCtwUwe0O/bVX51vKvIsk8c9/PHgrK2WAWYJcyAeOThwhGOkAL4=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: type; ValueData: $00000009; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0608{break}Vid_096E&Pid_060D; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: {sys}\csp11_ft502.dll
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT502; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64


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
NewUninsName := 'Unins_FT502';
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
