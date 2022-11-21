; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FTSM2"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{DCF40849-03AE-4497-90E8-2F3D8C6B8243}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FTSM2)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32λ
VersionInfoVersion ={#SETUP_FILE_VERSION}
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FTSM2
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FTSM2

trad.SetupAppTitle=�W�Cͨ�O����_FTSM2
trad.SetupWindowTitle=�W�Cͨ�O����_FTSM2

eng.SetupAppTitle=NETCADevices_FTSM2
eng.SetupWindowTitle=NETCADevices_FTSM2

[Files]

;32λϵͳ32λ����SM2����
Source: ..\..\..\..\֤�����\������������\����SM2\GmCsp\32λ\GmCsp.dll; DestDir: {sys}; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\����SM2\GmCsp\32λ\FeiTianSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion
;32λϵͳ32λ��˾��̬�豸DLL
Source: ..\..\winX86\�豸����\����SM2��Key\FeiTianSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����SM2��Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion


;64λϵͳ32λ����SM2����
Source: ..\..\..\..\֤�����\������������\����SM2\GmCsp\64λ\GmCsp.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����SM2\GmCsp\64λ\FeiTianSM2Key.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ32λ��˾��̬�豸DLL
Source: ..\..\winX64\�豸����\����SM2��Key\FeiTianSM2Key.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����SM2��Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;64λϵͳ32λ����SM2����
Source: ..\..\..\..\֤�����\������������\����SM2\GmCsp\32λ\GmCsp.dll; DestDir: {syswow64}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\֤�����\������������\����SM2\GmCsp\32λ\FeiTianSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
;64λϵͳ32λ��˾��̬�豸DLL
Source: ..\..\winX86\�豸����\����SM2��Key\FeiTianSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����SM2��Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion


[Registry]
;����SM2
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: JgNgzowo0v4ow77gLTv+/jf27NrKuAjcpKV/jwqHI9ARLrvN14LuexjCc7V07JkQKfsZuyQKvrnkw+tzoZwhDM7/4u6ZCsTGGew0RV9JEDeHFJ4uLsLpaf+4BDdY52tNlGH7vaRm7K/oukMLbP0lapiCJD1+5krg7V0M3UZHK3I=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch


Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: gCFRS9Mv7lhLCeuX0jKXXq2SjrtIPrE2ogzYtNMpoNo3lGyUhnNNYrR+lXA+OU9im6AoLVj6nmHH4i9L7HlA0i1khiixu3CFcXd1cPRJ1jottlMkiofjg1PhAhiZS2f8QQkemVFnRHIkAjRUNrJ1p0UKKUeLu6kyb0gnDwFm5ac=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: JgNgzowo0v4ow77gLTv+/jf27NrKuAjcpKV/jwqHI9ARLrvN14LuexjCc7V07JkQKfsZuyQKvrnkw+tzoZwhDM7/4u6ZCsTGGew0RV9JEDeHFJ4uLsLpaf+4BDdY52tNlGH7vaRm7K/oukMLbP0lapiCJD1+5krg7V0M3UZHK3I=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64


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
uninspath, uninsname, NewUninsName, MyAppName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_FTSM2';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
MyAppName := 'DCF40849-03AE-4497-90E8-2F3D8C6B8243';
// ����������ж���ļ�
uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
// �����޸���Ӧ��ע�������
if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1') then
begin
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
end;
end;
end;
