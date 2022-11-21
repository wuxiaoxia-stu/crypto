; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FT3000GM HID(32&64)"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.2"
#define UID  "DA58B117-FE54-4942-BFAF-1CD71385BC17"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{DA58B117-FE54-4942-BFAF-1CD71385BC17}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FT3000GM HID)
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
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FT3000GM HID
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FT3000GM HID

trad.SetupAppTitle=�W�Cͨ�O����_FT3000GM HID
trad.SetupWindowTitle=�W�Cͨ�O����_FT3000GM HID

eng.SetupAppTitle=NETCADevices_FT3000GM HID
eng.SetupWindowTitle=NETCADevices_FT3000GM HID
[Files]

;64λϵͳ��̬�豸DLL
Source: ..\..\winX64\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX64\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64

;32λϵͳ��̬�豸DLL
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64

;64λϵͳ32λ�ļ��豸DLL
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����SM2��COS\HID\FT3000GMHIDProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete


[Registry]

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FT3000GMHIDProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: signature; ValueData: Lwgdle+mSEbvMXmOd+gqyloYB1g5x8Md6SsMfnhmsJry/foOQRjzWcVaFRC5litpW2yw7L8PGSouHinFyxew+kVupz62Q9bdxn6WFns75HaS8+jJgivd+A4xjfOOEKwdV5tE4wwCHCRxLRhSC9fZ4g6IhaMYvS95/aAieb9Wa+g=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: type; ValueData: $00000030; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

;32λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FT3000GMHIDProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: signature; ValueData: jpCyrxMtvwFe6yHTSvyr+9vsIignNriHjPkJt6bDqyOWKFelwCCRTGNJeGWehFn/bHh8e5mOOFwNCt2/b7QTC3wMvdN8GTYBRHNfFUtA/Cb0NRv54HjG9U0w+gXuXHypstFEScZFWLkncr+cwsQXSoVFBNEuqISlBF7csoMXJs4=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: type; ValueData: $00000030; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: dword; ValueName: type; ValueData: $00000030; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: signature; ValueData: jpCyrxMtvwFe6yHTSvyr+9vsIignNriHjPkJt6bDqyOWKFelwCCRTGNJeGWehFn/bHh8e5mOOFwNCt2/b7QTC3wMvdN8GTYBRHNfFUtA/Cb0NRv54HjG9U0w+gXuXHypstFEScZFWLkncr+cwsQXSoVFBNEuqISlBF7csoMXJs4=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GMHID; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FT3000GMHIDProv.dll; Flags: uninsdeletekey; Check: IsWin64

[InstallDelete]

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
NewUninsName := 'Unins_FT3000GM HID';

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
