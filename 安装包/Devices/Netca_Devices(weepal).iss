; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_Weepal2001"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.13"
#define UID "4904D61A-C8E3-4B64-A9F6-948F9E4A6ED5"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{4904D61A-C8E3-4B64-A9F6-948F9E4A6ED5}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(weepal2001)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
ShowLanguageDialog=auto
CreateUninstallRegKey=true
UninstallLogMode=new


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_Weepal2001
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_Weepal2001

trad.SetupAppTitle=�W�Cͨ�O����_Weepal2001
trad.SetupWindowTitle=�W�Cͨ�O����_Weepal2001

eng.SetupAppTitle=NETCADevices_Weepal2001
eng.SetupWindowTitle=NETCADevices_Weepal2001
[Files]
;Weepal2001������32λ��

;��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\64system32\Weepalp11v211.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\64system32\Weepalp11v211.sig; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\64system32\Weepalp11v211_s.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211.sig; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211_s.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211_s.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211.sig; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\Weepalp11v211.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\WeepalEpass2001Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\winX64\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\64system32\WeepalEpass2001Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\winX64\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\΢��Epass2001\����ĵ��ļ�\NETCA_Win64\32syswow64\WeepalEpass2001Prov.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64


[Registry]
;64λע���
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: string; ValueName: Image Path; ValueData: C:\Windows\system32\Weepalp11v211_s.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: dword; ValueName: Type; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: binary; ValueName: Signature; ValueData: 66 1f fe c8 52 45 65 56 8b 3a a1 d7 c4 94 e3 66 c0 21 7c 93 5f 09 2f 8f 2d ae c2 f7 de 27 b5 53 38 21 88 fe 67 42 f2 73 9e a0 2d b1 f8 87 8f 7b 06 67 fd ff f5 d4 2a e9 8d 46 d0 56 ba 49 b6 d0 35 ea 76 6a 17 16 81 b1 2b 42 4a e9 18 09 79 9d 89 7e 3c c4 45 d4 d9 3a db 3f 2e 0a 30 fd c3 30 b2 d3 a2 45 e2 e8 6e df 25 2c bd e6 1a 46 b4 24 0b 68 03 09 dd ae 65 bc 80 d1 84 dc 64 15 50 13 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\WeepalEpass2001Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: signature; ValueData: px49W3Q9BTMYQhcy/G1jJlrHR8DdXotxJwE8vz3AMn9qHaukJbroSPUy+Zqb7Rns71o4Fxx1a7lqYIppxOH2xf8lP/Xr1k2apsm/H1Bb2zU02ygDjWCdafU7JY1gQSguabYPO6phx+M6we/6czLV+D435Jfg2/EU+5D31DWil5A=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: type; ValueData: $00000008; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0803; Check: IsWin64; Flags: uninsdeletekey

;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\WeepalEpass2001Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: signature; ValueData: K1e0LFTY/O58r2gcDfWuyX1DZC6HMXde2RlTKi7LxjaNVY+etr8D862/62SyvpnE7eXEKO9aRSBS2ZTrXqJVtY4WSyVEH90BNFZm6FDWYUiNRAFMar+MTlZa5j333Lp3Y1HGOLGW/nTLcEDtiISjfzihZrMvQ9jQ8Tpi+QGLAW4=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: type; ValueData: $00000008; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0803; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\WeepalEpass2001Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: signature; ValueData: K1e0LFTY/O58r2gcDfWuyX1DZC6HMXde2RlTKi7LxjaNVY+etr8D862/62SyvpnE7eXEKO9aRSBS2ZTrXqJVtY4WSyVEH90BNFZm6FDWYUiNRAFMar+MTlZa5j333Lp3Y1HGOLGW/nTLcEDtiISjfzihZrMvQ9jQ8Tpi+QGLAW4=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: type; ValueData: $00000008; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0803; Flags: uninsdeletekey; Check: IsWin64

;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: string; ValueName: Image Path; ValueData: C:\Windows\system32\Weepalp11v211_s.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: dword; ValueName: Type; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: binary; ValueName: Signature; ValueData: 66 1f fe c8 52 45 65 56 8b 3a a1 d7 c4 94 e3 66 c0 21 7c 93 5f 09 2f 8f 2d ae c2 f7 de 27 b5 53 38 21 88 fe 67 42 f2 73 9e a0 2d b1 f8 87 8f 7b 06 67 fd ff f5 d4 2a e9 8d 46 d0 56 ba 49 b6 d0 35 ea 76 6a 17 16 81 b1 2b 42 4a e9 18 09 79 9d 89 7e 3c c4 45 d4 d9 3a db 3f 2e 0a 30 fd c3 30 b2 d3 a2 45 e2 e8 6e df 25 2c bd e6 1a 46 b4 24 0b 68 03 09 dd ae 65 bc 80 d1 84 dc 64 15 50 13 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: string; ValueName: Image Path; ValueData: C:\Windows\SysWOW64\Weepalp11v211_s.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: dword; ValueName: Type; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Defaults\Provider\FEITIAN ePassNG CSP For Weepal V1.0; ValueType: binary; ValueName: Signature; ValueData: 66 1f fe c8 52 45 65 56 8b 3a a1 d7 c4 94 e3 66 c0 21 7c 93 5f 09 2f 8f 2d ae c2 f7 de 27 b5 53 38 21 88 fe 67 42 f2 73 9e a0 2d b1 f8 87 8f 7b 06 67 fd ff f5 d4 2a e9 8d 46 d0 56 ba 49 b6 d0 35 ea 76 6a 17 16 81 b1 2b 42 4a e9 18 09 79 9d 89 7e 3c c4 45 d4 d9 3a db 3f 2e 0a 30 fd c3 30 b2 d3 a2 45 e2 e8 6e df 25 2c bd e6 1a 46 b4 24 0b 68 03 09 dd ae 65 bc 80 d1 84 dc 64 15 50 13 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: IsWin64

[InstallDelete]
Name: {app}\Unins_weepal2001.dat; Type: files
Name: {app}\Unins_weepal2001.exe; Type: files

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
NewUninsName := 'Unins_weepal2001';

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
end  else  if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
begin
  //MsgBox('��⵽ϵͳ��Ҫ��', mbInformation, MB_OK);
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
  //MsgBox('��⵽ϵͳ����', mbInformation, MB_OK);
end;
end;
end;
