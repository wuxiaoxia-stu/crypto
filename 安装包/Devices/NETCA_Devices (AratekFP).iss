; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_AratekFP"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.2.0"
#define SETUP_FILE_VERSION "1.2.0.1"
#define UID  "5C34EE4C-059B-4E03-A344-7021D7753010"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{5C34EE4C-059B-4E03-A344-7021D7753010}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=(C) {#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(AratekFP)
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
;ArchitecturesInstallIn64BitMode=x64 ia64
VersionInfoTextVersion={#DEVICES_APPVERSION}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_AratekFP
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_AratekFP

[Files]
Source: Y:\svn\NETCA_CRYPTO\current\winX86\�豸����\������ָ��USBKey\AratekFPKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\NETCA_CRYPTO\current\winX86\�豸����\������ָ��USBKey\AratekFPKeyProv.dll_device.ini; DestDir: {app}; Flags: ignoreversion
Source: Y:\svn\֤�����\������������\������ָ��USBKey\������PKCS11��\ASCryptoki.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\֤�����\������������\������ָ��USBKey\������PKCS11��\ASFKeyAPI.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\֤�����\������������\������ָ��USBKey\������PKCS11��\FDcgi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\֤�����\������������\������ָ��USBKey\������PKCS11��\TokenASApi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\NETCA_CRYPTO\current\winX86\�豸����\������ָ��USBKey\AratekFPKeyProv.dll_driver.ini; DestDir: {app}; Flags: ignoreversion

[Registry]
;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: dllpath; ValueData: {app}\AratekFPKeyProv.dll; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: signature; ValueData: i2YUF2cht86gXQkDiWhD5qhr6OTQw9Hj0kDnoqM4HjqeR51j71ejuYfewZlp5kR1TrBPXgsrGNUqjK6D2EstC0+NnhBqsm862YCudnvoeeo/j4ON9yZL6FZUPMmzXdCNuevXLGNc5QTWfbkQFSsjFJLjWYyOkrf3BzZoQ00X2FM=; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: type; ValueData: $0000002a; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_2010&Pid_1200; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletevalue


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
NewUninsName := 'Unins_AratekFP';
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
