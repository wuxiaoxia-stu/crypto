; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_WinTrustUKey(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.1"
#define UID  "B888D8EA-ED40-4D0A-B538-CFEBDB9130B5"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{B888D8EA-ED40-4D0A-B538-CFEBDB9130B5}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(WinTrustUKey)
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
VersionInfoProductVersion={#DEVICES_APPVERSION}
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_WinTrustUKey
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_WinTrustUKey

trad.SetupAppTitle=�W�Cͨ�O����_WinTrustUKey
trad.SetupWindowTitle=�W�Cͨ�O����_WinTrustUKey

eng.SetupAppTitle=NETCADevices_WinTrustUKey
eng.SetupWindowTitle=NETCADevices_WinTrustUKey

[Files]
;32λϵͳ�豸DLL
Source: ..\..\winX86\�豸����\Ӯ����UKey\NETCAWTKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\Ӯ����UKey\NETCAWTKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\NETCAWTKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion
;����(32λϵͳ)
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\TFSC_W.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\TFTknCrypt.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\UKeySC.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\WTSKFInterfaceUKey.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64λ�豸dll
Source: ..\..\winX64\�豸����\Ӯ����UKey\NETCAWTKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\Ӯ����UKey\NETCAWTKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x64\NETCAWTKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λ����(64λϵͳ)
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x64\TFSC_W.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x64\TFTknCrypt.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x64\UKeySC.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x64\WTSKFInterfaceUKey.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ32λ����
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\TFSC_W.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\TFTknCrypt.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\UKeySC.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\Ӯ����UKey\SKF��\x86\WTSKFInterfaceUKey.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;32λϵͳ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_3A59&Pid_4458; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: type; ValueData: $0000003e; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: class; ValueData: USB; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: signature; ValueData: p+IYgSXUN866hprJilufN3jgkhRPQfnwzg5dc/XtcLkgYsvWyHiGBsC54qFOfzcdfHNYEE+xbx0zmsn24Xx9w4AIrckS2cg95SO3e/jUM8azWbFmN5v0RsNJl791MLNcYQ4Mwb58g8Wqn1g2LmUG96bDayEOD+dIpfSqYfQRpCk=; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NETCAWTKey.dll; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsOtherArch
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NETCAWTKey.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: signature; ValueData: p+IYgSXUN866hprJilufN3jgkhRPQfnwzg5dc/XtcLkgYsvWyHiGBsC54qFOfzcdfHNYEE+xbx0zmsn24Xx9w4AIrckS2cg95SO3e/jUM8azWbFmN5v0RsNJl791MLNcYQ4Mwb58g8Wqn1g2LmUG96bDayEOD+dIpfSqYfQRpCk=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: type; ValueData: $0000003e; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_3A59&Pid_4458; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\NETCAWTKey.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: signature; ValueData: JoLrpbi7jAIyaKovWB27iY/npstY0A3dmpst6Hu07zS6FPwSqy8xFTqByZKkRpG97uRkGIjOU+nebhRaSEkZnB1pcumXqDa8MNf6HcjYFEbuHKYipLY0IZtJ7ODoqpzWkx+DIwS9XThm3AgnHgTAART/ccJy5eNemRTCpJp3kxI=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: type; ValueData: $0000003e; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_3A59&Pid_4458; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[InstallDelete]
Name: {app}\Unins_WinTrustUKey.dat; Type: files
Name: {app}\Unins_WinTrustUKey.exe; Type: files
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files

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
uninspath, uninsname, NewUninsName : string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_WinTrustUKey';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
//MyAppName := '5EFB2F66-0220-47D9-AC47-8CCAC42104BB';
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
