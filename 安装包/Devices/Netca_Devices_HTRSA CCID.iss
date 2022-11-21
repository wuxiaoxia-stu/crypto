; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_HT_CCID_RSA(32&64)"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.4"
#define UID  "69ED31C5-7183-4BD3-AC00-87E0F4B8F703"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{69ED31C5-7183-4BD3-AC00-87E0F4B8F703}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(HTCCID RSA)
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
chinesesimp.SetupAppTitle=��֤ͨ�豸����_HT_CCID RSA
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_HT_CCID RSA

trad.SetupAppTitle=�W�Cͨ�O����_HT_CCID RSA
trad.SetupWindowTitle=�W�Cͨ�O����_HT_CCID RSA

eng.SetupAppTitle=NETCADevices_HT_CCID RSA
eng.SetupWindowTitle=NETCADevices_HT_CCID RSA
[Files]

;��̩���ܿ��Ķ���Driver
Source: ..\..\..\..\֤�����\������������\��̩\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; DestDir: {pf}\NETCA\NETCA_Devices; Flags: deleteafterinstall

;64λϵͳ��̬�豸DLL
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\CCID\HaitaiCCIDRSAKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\CCID\HaitaiCCIDRSAKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64

;32λϵͳ��̬�豸DLL
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\CCID\HaitaiCCIDRSAKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\CCID\HaitaiCCIDRSAKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64

;64λϵͳ32λ�ļ��豸DLL
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\CCID\HaitaiCCIDRSAKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\CCID\HaitaiCCIDRSAKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaitaiCCIDRSAKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: signature; ValueData: g1T12wstOgRR4ekK5Uu0MrhbHoUutqDsFBnfhqSqCyHRq72geHIZS/jPnKVZT7sNspLFHlFePxVC5kzcGpUWpaaWG4bZTlA0NJsuwqHtHfLTHyRoCxkOHUb84q9dcSJ5ykuEdMOobNFcHXKDa2SyzKj1Wl9FNNA1pAM57aqs/LY=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: type; ValueData: $0000000c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

;32λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaitaiCCIDRSAKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: signature; ValueData: HrqzQdRQ2FTPbSScCsa+qWTUViHLnR50xDEwryZaitdsP34h5jRUxglTKAEGztLygoDm4/JK8IlaJwiYd9aqnbJR7G4gASCt9s5NMmrAI3Zh7QH4/Sq6Acj7w5muvTVJAoXY/7x6aY/DM3SUzFgJwu/HpDu+oCzDM8CIExI6/Dg=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: type; ValueData: $0000000c; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: type; ValueData: $0000000c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: signature; ValueData: HrqzQdRQ2FTPbSScCsa+qWTUViHLnR50xDEwryZaitdsP34h5jRUxglTKAEGztLygoDm4/JK8IlaJwiYd9aqnbJR7G4gASCt9s5NMmrAI3Zh7QH4/Sq6Acj7w5muvTVJAoXY/7x6aY/DM3SUzFgJwu/HpDu+oCzDM8CIExI6/Dg=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiCCIDRSAKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64

[Run]
Filename: {pf}\NETCA\NETCA_Devices\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {pf}\NETCA\NETCA_Devices; Flags: runminimized runhidden

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
NewUninsName := 'Unins_HT_CCID RSA';

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
