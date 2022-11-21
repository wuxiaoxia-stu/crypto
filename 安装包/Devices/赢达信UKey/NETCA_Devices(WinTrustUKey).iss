; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_WinTrustUKey"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.4"
#define UID  "A50723BF-2852-43B5-B475-3179AB0F96E7"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{A50723BF-2852-43B5-B475-3179AB0F96E7}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(WinTrustUKey)
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
CreateUninstallRegKey=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_WinTrustUKey
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_WinTrustUKey

[Files]
;{app}
Source: ..\..\..\winX86\�豸����\Ӯ����UKey\NETCAWTKey.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\winX86\�豸����\Ӯ����UKey\NETCAWTKey.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\NETCAWTKey.dll_driver.ini; DestDir: {app}; Flags: ignoreversion

;32λ�ļ�
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\TFTknCrypt_UKey.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\UKeySC.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\WTSKFInterfaceUKey.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\TFTknCrypt_UKey.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\UKeySC.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x86\WTSKFInterfaceUKey.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λ�ļ�
Source: ..\..\..\winX64\�豸����\Ӯ����UKey\NETCAWTKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\Ӯ����UKey\NETCAWTKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x64\NETCAWTKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64

Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x64\TFTknCrypt_UKey.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x64\UKeySC.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����UKey\SKF\x64\WTSKFInterfaceUKey.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32λ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_3A59&Pid_4458; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: type; ValueData: $0000003e; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: class; ValueData: USB; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: signature; ValueData: JzwJbD2MoR7K2/N9SR7MZqA0va20btDramIuHThbXI4Vf+a0qVMDVWiH83lmDR0uVZWStELl3WLmqkBp0KM0XzPJ1U2dk7HLP+tHTQgKMA0jRuF3OynKG6fybJYJ9W5AD4OHeFkz9Vfr+/PQ/iVyZCedL6fzqMJRH2qaS2a7KN8=; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: dllpath; ValueData: {app}\NETCAWTKey.dll; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: UID; ValueData: {#UID}; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Check: not IsWin64; Flags: uninsdeletekey

Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_3A59&Pid_4458; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: type; ValueData: $0000003e; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: signature; ValueData: JzwJbD2MoR7K2/N9SR7MZqA0va20btDramIuHThbXI4Vf+a0qVMDVWiH83lmDR0uVZWStELl3WLmqkBp0KM0XzPJ1U2dk7HLP+tHTQgKMA0jRuF3OynKG6fybJYJ9W5AD4OHeFkz9Vfr+/PQ/iVyZCedL6fzqMJRH2qaS2a7KN8=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: dllpath; ValueData: {app}\NETCAWTKey.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: UID; ValueData: {#UID}; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Check: IsWin64; Flags: uninsdeletekey

;64λ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_3A59&Pid_4458; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: dword; ValueName: type; ValueData: $0000003e; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: signature; ValueData: eYlAjA4OlqlazaucnjsR6hIKcTGTUJoxICstyDePZo4+vU1uUD/ZF1yL6oLQX8vo35RHul/4gXopkepNVX2LFa0xzPQjs9vQ1nc5Q/RqtiN2laUJy8K8epmTcPfwl00L7quqzqP70nqm93D6bSabhSdgxokU9h1lwudlb3tJlr8=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\NETCAWTKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: UID; ValueData: {#UID}; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAWTKey; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Check: IsWin64; Flags: uninsdeletekey


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
NewUninsName := 'Unins_WTTFUKey';
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
[InstallDelete]
Name: {app}\Unins_WTTFUKey.exe; Type: files
Name: {app}\Unins_WTTFUKey.dat; Type: files
