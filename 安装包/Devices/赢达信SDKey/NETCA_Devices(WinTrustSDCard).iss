; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_WinTrustSDCard"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.3"
#define UID  "8B290D38-F328-409E-8D3B-184F674C847F"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{8B290D38-F328-409E-8D3B-184F674C847F}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(WinTrustSDCard)
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
chinesesimp.SetupAppTitle=��֤ͨ�豸����_WinTrustSDCard
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_WinTrustSDCard

[Files]
;{app}
Source: ..\..\..\winX86\�豸����\Ӯ����SDKey\WinTrustSDKey.dll; DestDir: {app}; Flags: restartreplace ignoreversion
Source: ..\..\..\winX86\�豸����\Ӯ����SDKey\WinTrustSDKey.dll_device.ini; DestDir: {app}; Flags: restartreplace ignoreversion
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\WinTrustSDKey.dll_driver.ini; DestDir: {app}; Flags: ignoreversion

;32λ�ļ�
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\TFSC_W.dll; DestDir: {sys}; Flags: restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\TFTknCrypt_TF.dll; DestDir: {sys}; Flags: restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\WTSKFInterfaceTF.dll; DestDir: {sys}; Flags: restartreplace ignoreversion; Check: not IsWin64

Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\TFSC_W.dll; DestDir: {syswow64}; Flags: restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\TFTknCrypt_TF.dll; DestDir: {syswow64}; Flags: restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x86\WTSKFInterfaceTF.dll; DestDir: {syswow64}; Flags: restartreplace ignoreversion; Check: IsWin64

;64λ�ļ�
Source: ..\..\..\winX64\�豸����\Ӯ����SDKey\WinTrustSDKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\Ӯ����SDKey\WinTrustSDKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x64\WinTrustSDKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64

Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x64\TFSC_W.dll; DestDir: {sys}; Flags: restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x64\TFTknCrypt_TF.dll; DestDir: {sys}; Flags: restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\Ӯ����SD��\SKF\x64\WTSKFInterfaceTF.dll; DestDir: {sys}; Flags: restartreplace ignoreversion; Check: IsWin64


[Registry]
;32λ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: dllpath; ValueData: {app}\WinTrustSDKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: multisz; ValueName: idstring; ValueData: vid_05e3&pid_0723; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: signature; ValueData: oBSPk3td10eemh1O166+FJq0lFl7MnGdJg/vlblf9VUyW68dysRBI012S4O9FUdac8JauZuFPMMXmyL1RgrNOqEGbOKZaToveIhCVU3y8weieJHDKZJYJHIS97tmtZzUWK4eOe5P2p4NLegdHFhLW3rF6U7WIxiyH3aTPBF8TQU=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: type; ValueData: $00000039; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: UID; Flags: uninsdeletekey; Check: not IsWin64; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: version; Flags: uninsdeletekey; Check: not IsWin64; ValueData: {#SETUP_FILE_VERSION}

Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: dllpath; ValueData: {app}\WinTrustSDKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: multisz; ValueName: idstring; ValueData: vid_05e3&pid_0723; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: signature; ValueData: oBSPk3td10eemh1O166+FJq0lFl7MnGdJg/vlblf9VUyW68dysRBI012S4O9FUdac8JauZuFPMMXmyL1RgrNOqEGbOKZaToveIhCVU3y8weieJHDKZJYJHIS97tmtZzUWK4eOe5P2p4NLegdHFhLW3rF6U7WIxiyH3aTPBF8TQU=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: type; ValueData: $00000039; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: UID; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: version; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#SETUP_FILE_VERSION}

;64λ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\WinTrustSDKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: multisz; ValueName: idstring; ValueData: vid_05e3&pid_0723; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: signature; ValueData: BDDhb6qNTyiwBPt6rtwA6nrgZoMaIYeM0cXgt5Baxlsr/UvMYqym+1u0P3v667Mwl2WKvI9HRBfTMFV5al2JtYEePTkm05U4p2PXDvCkSo5GM1KJmGFY0GR4ToAf7SvA7EGFd7fOFPE+sq/lY13KvwHGsRAepAUFj0V/R6PPjTI=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: type; ValueData: $00000039; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: version; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#SETUP_FILE_VERSION}
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyWTTF; ValueType: string; ValueName: UID; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#UID}

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
NewUninsName := 'Unins_WTTFSDCard';
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
Name: {app}\Unins_WTTFSDCard.exe; Type: files
Name: {app}\Unins_WTTFSDCard.dat; Type: files
