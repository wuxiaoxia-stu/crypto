; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FT3000GM(32&64)"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.1"
#define UID  "FE9FDA9D-D4AA-48AE-8772-04AC1EE8EE9C"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{FE9FDA9D-D4AA-48AE-8772-04AC1EE8EE9C}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FT3000GM)��Ѷ��
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}��Ѷ��
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FT3000GM
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FT3000GM

trad.SetupAppTitle=�W�Cͨ�O����_FT3000GM
trad.SetupWindowTitle=�W�Cͨ�O����_FT3000GM

eng.SetupAppTitle=NETCADevices_FT3000GM
eng.SetupWindowTitle=NETCADevices_FT3000GM

[Files]
;�豸dll(32λϵͳ32λ�ļ�)
Source: ..\..\winX86\�豸����\����SM2��COS\FT3000GMProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\����SM2��COS\FT3000GMProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;�豸dll(64λϵͳ64λ�ļ�)
Source: ..\..\winX64\�豸����\����SM2��COS\FT3000GMProv.dll; DestDir: {app}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����SM2��COS\FT3000GMProv.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64

;�豸dll(64λϵͳ��32λ�ļ�)
Source: ..\..\winX86\�豸����\����SM2��COS\FT3000GMProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����SM2��COS\FT3000GMProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;��������ļ�(32λϵͳ32λ�ļ���64λϵͳ��64λ�ļ�)
Source: ..\..\winX86\�豸����\����SM2��COS\FT3000GMProv.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
;64λϵͳ��32λ�ļ�
Source: ..\..\winX86\�豸����\����SM2��COS\FT3000GMProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;ϵͳע���(32λϵͳ32λ�ļ�)
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {app}\FT3000GMProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: P9SsZdoEn0hfyCtvLJGtWjoWLtV2TR9iwRkE/JMPcBe8o27Q1AawCXkb1Oqlf6FjnpBNpMdK9z4qno26nQDODG3F0WdVsWMs0v91Iv0/jvC2oQ1NSeyHGqOqXpvj8FywV/iRTRFSKmWxpg4OdnAAj933Qs+nRxXhHmeaNdJdWC0=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314{break}Vid_096E&Pid_0316; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
;ϵͳ�����ļ�(32λϵͳ32λ�ļ���64λϵͳ��64λע���)
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey
;ϵͳ�����ļ�(64λϵͳ��32λע���)
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Check: IsWin64; Flags: uninsdeletekey
;64λϵͳע���64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {app}\FT3000GMProv.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: M5gfLyqsGeKUIN4Jgv89Q84v4elihKWEwsCKxf1Ci9Yw6odc/NEEV8sBwwsL95YRobDL60i4rzY8Akacu5xH5DQdszUBMLqkNg3vLRQwE6cqcln4dTprVcQ58wrQQhKCnZFY8yQHxK+k17oWbRGStCEwitowWQ9PPMuKKvTs/lk=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314{break}Vid_096E&Pid_0316; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: P9SsZdoEn0hfyCtvLJGtWjoWLtV2TR9iwRkE/JMPcBe8o27Q1AawCXkb1Oqlf6FjnpBNpMdK9z4qno26nQDODG3F0WdVsWMs0v91Iv0/jvC2oQ1NSeyHGqOqXpvj8FywV/iRTRFSKmWxpg4OdnAAj933Qs+nRxXhHmeaNdJdWC0=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314{break}Vid_096E&Pid_0316; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
;32λϵͳ��32λ�ļ���64λϵͳ64λ�ļ�
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
;64λϵͳ��32λ�ļ�
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
[InstallDelete]
Name: {app}\Unins_FT3000GM.dat; Type: files
Name: {app}\Unins_FT3000GM.exe; Type: files
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files

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
NewUninsName := 'Unins_FT3000GM';
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
