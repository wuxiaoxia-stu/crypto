; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_MWScard(32λ)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.8"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{4AE61B82-01F4-4188-A004-AAF968A57965}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(MWScard)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32λ
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
;UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
UninstallRestartComputer=false
UninstallLogMode=overwrite
ArchitecturesInstallIn64BitMode=x64 ia64


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_MWScard
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_MWScard

trad.SetupAppTitle=�W�Cͨ�O����_MWScard
trad.SetupWindowTitle=�W�Cͨ�O����_MWScard

eng.SetupAppTitle=NETCADevices_MWScard
eng.SetupWindowTitle=NETCADevices_MWScard
[Files]
;MWScard������32λ����

;��˾��̬�豸DLL(32λ)
Source: ..\..\winX86\�豸����\������\��һҽԺ\MWScardProv.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\������\��һҽԺ\MWScardProv.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\..\winX86\�豸����\������\��һҽԺ\MWScardProv.dll_driver.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion

[Registry]
;32λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: dllpath; ValueData: {app}\MWScardProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: signature; ValueData: YqYsiP7STyEzanSnkAAaMVrRIR31jZh+hu9a9RLg/dnymN5gNCXQh/jY6isbBKVG6eyGykannjzVNmLgVCtq2wjT1NZYt1PYTqGpmFeblJSFmwtqlIhcaBRqfs7IsRGkYsNWOFPDaUAMXUz24nED3hNtzcLBLx94Ns/CiztjzfQ=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: class; ValueData: PC/SC; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: type; ValueData: $0000002d; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: multisz; ValueName: idstring; ValueData: ACS ACR1281 1S Dual Reader PICC 0; Flags: uninsdeletekey; Check: not IsWin64

;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: multisz; ValueName: idstring; ValueData: ACS ACR1281 1S Dual Reader PICC 0; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: type; ValueData: $0000002d; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: class; ValueData: PC/SC; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: signature; ValueData: YqYsiP7STyEzanSnkAAaMVrRIR31jZh+hu9a9RLg/dnymN5gNCXQh/jY6isbBKVG6eyGykannjzVNmLgVCtq2wjT1NZYt1PYTqGpmFeblJSFmwtqlIhcaBRqfs7IsRGkYsNWOFPDaUAMXUz24nED3hNtzcLBLx94Ns/CiztjzfQ=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: dllpath; ValueData: {app}\MWScardProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64



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
NewUninsName := 'Unins_MWScard';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
MyAppName := '4AE61B82-01F4-4188-A004-AAF968A57965';
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
