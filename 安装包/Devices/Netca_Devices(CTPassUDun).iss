; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_CTPassUDun(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.1.9"
#define UID "97ACB6F1-A95C-41CA-B4FF-2919304C41E6"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{97ACB6F1-A95C-41CA-B4FF-2919304C41E6}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net
DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(CTPassUDun)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true
VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no
ShowLanguageDialog=auto
CreateUninstallRegKey=true
ArchitecturesInstallIn64BitMode=x64 ia64
UsePreviousAppDir=false
[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl
[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_CTPassUDun
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_CTPassUDun
trad.SetupAppTitle=�W�Cͨ�O����_CTPassUDun
trad.SetupWindowTitle=�W�Cͨ�O����_CTPassUDun
eng.SetupAppTitle=NETCADevices_CTPassUDun
eng.SetupWindowTitle=NETCADevices_CTPassUDun
[Files]
;32λ�ļ������ļ�
Source: ..\..\winX86\�豸����\����U��\CTPassUDunProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����U��\CTPassUDunProv.dll _driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����U��\CTPassUDunProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\����U��\CTPassUDunConfigModuleSkin.xml; DestDir: {pf32}\NETCA\KeyX\skin; Flags: ignoreversion uninsrestartdelete
;32λCTPass�ļ�
Source: ..\..\winX86\�豸����\����U��\netcamcpwin2.exe; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64
Source: ..\..\winX86\�豸����\����U��\CTPassUDunConfigRun.exe; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\����U��\netcamcpwin2.ini; DestDir: {sys}; Flags: onlyifdoesntexist uninsrestartdelete; Check: not IsWin64
Source: ..\..\winX86\�豸����\����U��\proxyp11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;64λϵͳ32λCTPass�ļ�
Source: ..\..\winX86\�豸����\����U��\netcamcpwin2.exe; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\winX86\�豸����\����U��\CTPassUDunConfigRun.exe; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����U��\netcamcpwin2.ini; DestDir: {syswow64}; Flags: onlyifdoesntexist uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\�豸����\����U��\proxyp11.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64λϵͳ����
Source: ..\..\winX64\�豸����\����U��\CTPassUDunProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\�豸����\����U��\CTPassUDunProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\�豸����\����U��\CTPassUDunProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
;64λϵͳCTPass�ļ�
Source: ..\..\winX64\�豸����\����U��\netcamcpwin2.exe; DestDir: {sys}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\�豸����\����U��\netcamcpwin2.ini; DestDir: {sys}; Flags: onlyifdoesntexist uninsrestartdelete; Check: IsWin64
Source: ..\..\winX64\�豸����\����U��\proxyp11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;innosetup���
Source: ..\..\..\..\ͳһ���ʹ�����\current\������\����Ĳ��\ISTask.dll; DestDir: {app}; Flags: onlyifdoesntexist uninsrestartdelete
Source: ..\..\..\..\ͳһ���ʹ�����\current\������\����Ĳ��\ISTask.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsrestartdelete
[Registry]
;32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: dllpath; ValueData: {app}\CTPassUDunProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: signature; ValueData: EcRTnKzgv40sX0wQpEXUFrSPsMqou08tjo4HYytB680BqWEFSwUtCFAig5E9vGc3USLId3gW2b0Q6Dz2vDWg4ZNRzp787N5JpKeptfectyoMlvaJafdNLapQbpN3G4C6Iigfb1MVlxlNMneujI+OzjIWA4w6/Tswi54B+v56TZ8=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: type; ValueData: $0000003a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: multisz; ValueName: idstring; ValueData: Vid_096F&Pid_0001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: KeyXTimeOut; ValueData: $0001fbd0; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\NETCAKeyUDun; ValueType: string; ValueName: uid; ValueData: 97ACB6F1-A95C-41CA-B4FF-2919304C41E6; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\\NETCAKeyUDun; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\NETCAKeyUDun; ValueType: string; ValueName: MonitorTitle; ValueData: �ƶ�������Կ; Flags: uninsdeletekey; Check: not IsWin64
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: dllpath; ValueData: {app}\CTPassUDunProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: signature; ValueData: EcRTnKzgv40sX0wQpEXUFrSPsMqou08tjo4HYytB680BqWEFSwUtCFAig5E9vGc3USLId3gW2b0Q6Dz2vDWg4ZNRzp787N5JpKeptfectyoMlvaJafdNLapQbpN3G4C6Iigfb1MVlxlNMneujI+OzjIWA4w6/Tswi54B+v56TZ8=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: type; ValueData: $0000003a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: multisz; ValueName: idstring; ValueData: Vid_096F&Pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: KeyXTimeOut; ValueData: $0001fbd0; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\NETCAKeyUDun; ValueType: string; ValueName: uid; ValueData: 97ACB6F1-A95C-41CA-B4FF-2919304C41E6; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\\NETCAKeyUDun; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\NETCAKeyUDun; ValueType: string; ValueName: MonitorTitle; ValueData: �ƶ�������Կ; Flags: uninsdeletekey; Check: IsWin64
;64λϵͳע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\CTPassUDunProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: signature; ValueData: gmrYVaEYfxwdB2Ifd3LapELbosCuQmt+P6eAVjIGXT1uHsIfYhn7EruH36P46uTiGvL1sXdmdT1x4aq0VmT8rdW9ZTzYueXpBxrn0pkaBU4u2ya3PlsCw0ekyyEB7Bx0H5E/TmOt03geSvSdO+CKjHm2TJ7bnhSaBzMuz7bf7l8=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: type; ValueData: $0000003a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: multisz; ValueName: idstring; ValueData: Vid_096F&Pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUDun; ValueType: dword; ValueName: KeyXTimeOut; ValueData: $0001fbd0; Flags: uninsdeletekey; Check: IsWin64
[InstallDelete]
Name: {app}\Unins_CTPassUDun.dat; Type: files
Name: {app}\Unins_CTPassUDun.exe; Type: files
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
function RunTask(FileName: string; bFullpath: Boolean): Boolean;
  external 'RunTask@files:ISTask.dll stdcall delayload';
function KillTask(ExeFileName: string): Integer;
  external 'KillTask@files:ISTask.dll stdcall delayload';

function InitializeSetup():boolean;
begin
	Result:=true;
	KillTask('netcamcpwin2.exe');
end;

procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_CTPassUDun';

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
