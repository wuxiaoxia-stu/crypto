; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_��̩RSA COS(32&64)"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "ECF7AFA0-E127-4910-9DBF-B490D9BB5028"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{ECF7AFA0-E127-4910-9DBF-B490D9BB5028}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(HTRSACOS)
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
chinesesimp.SetupAppTitle=��֤ͨ�豸����_��̩RSA COS(32&64)
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_��̩RSA COS(32&64)

trad.SetupAppTitle=�W�Cͨ�O����_��̩RSA COS(32&64)
trad.SetupWindowTitle=�W�Cͨ�O����_��̩RSA COS(32&64)

eng.SetupAppTitle=NETCADevices_��̩RSA COS(32&64)
eng.SetupWindowTitle=NETCADevices_��̩RSA COS(32&64)
[Files]

;32λϵͳ��̬�豸DLL
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\HID\HaitaiRSAKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\HID\HaitaiRSAKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64

;64λϵͳ32λ�ļ��豸DLL
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\HID\HaiTaiRSAKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64; Flags: uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\HID\HaitaiRSAKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\HID\HaiTaiRSAKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\��̩\��̩RSA COS\HID\HaitaiRSAKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ��̬�豸DLL
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\HID\HaitaiRSAKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\HID\HaiTaiRSAKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\��̩\��̩RSA COS\HID\HaiTaiRSAKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion

;PKCS#11д����֤dll
Source: ..\..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\pkcs11_Win32\HkCommand.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\pkcs11_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\pkcs11_Win32\HtPkcs11.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\pkcs11_Win32\HkCommand.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaiTaiRSAKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: signature; ValueData: U2RbtrcdvRHwoAIbWGuZJkm+nwascdiEjnr7yN7ZkgeYV7UcdRIMKSGcnFad50BOiucOc2OZe7Ro48T6ORk62iN95gMHz9+0RdcHAOnaTnvjJdoSCV+EcoUQK7f4d4TgOPTrbsTvceSrCnuGavmYpbaMypleVLZbttm93PcFHIg=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: type; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: type; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: signature; ValueData: U2RbtrcdvRHwoAIbWGuZJkm+nwascdiEjnr7yN7ZkgeYV7UcdRIMKSGcnFad50BOiucOc2OZe7Ro48T6ORk62iN95gMHz9+0RdcHAOnaTnvjJdoSCV+EcoUQK7f4d4TgOPTrbsTvceSrCnuGavmYpbaMypleVLZbttm93PcFHIg=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaiTaiRSAKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaiTaiRSAKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: string; ValueName: signature; ValueData: aAhx+QWwG8G2PD/Id6A01p/bLQf0zge2elLSwC7IDY18FJ2Xw9s9dMJZHOmqpvoxSdAI9B6jl7GDvFnnA6LNEP0iOMv6e1XRqxJ4l7qdSDUtdOO4IbCFCPvpaXwR3m9MIY3hnhMOFmofb/tQBtI73AXnM1Bnje6jq9rbQYsAGao=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: type; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKCS11Providers\HaiTai Cryptographic Service Provider; ValueType: string; ValueName: Image Path; ValueData: C:\WINDOWS\system32\HTPKCS11.dll; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKCS11Providers\HaiTai Cryptographic Service Provider; ValueType: string; ValueName: Image Path; ValueData: C:\Windows\sysWOW64\HTPKCS11.dll; Check: IsWin64; Flags: uninsdeletekey

[Run]

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
NewUninsName := 'Unins_HTRSACOS';

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
