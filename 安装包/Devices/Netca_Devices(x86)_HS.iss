; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_HS(32λ)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.2"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{B4D08D47-C8AE-4C96-ACBC-0483071A9C5E}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(HS)
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


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_����
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_����

trad.SetupAppTitle=�W�Cͨ�O����_HS
trad.SetupWindowTitle=�W�Cͨ�O����_HS

eng.SetupAppTitle=NETCADevices_HS
eng.SetupWindowTitle=NETCADevices_HS
[Files]

;��˾��̬�豸DLL(32λ)
Source: ..\..\winX86\�豸����\����\HSuKeyCI800Prov.dll; DestDir: {app}; Flags: restartreplace ignoreversion uninsrestartdelete
Source: ..\..\winX86\�豸����\����\HSuKeyCI800Prov.dll_device.ini; DestDir: {app}; Flags: restartreplace ignoreversion uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\HDPKCS11\x86\HSuKeyCI800Prov.dll_driver.ini; DestDir: {app}; Flags: restartreplace ignoreversion uninsrestartdelete
;���������ļ�(32λ)
Source: ..\..\..\..\֤�����\������������\����\HDPKCS11\x86\HD_hdcos480.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\..\..\֤�����\������������\����\HDPKCS11\x86\HDIFD20B.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\..\..\֤�����\������������\����\HDPKCS11\x86\hdpkcs11_jit.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
;CCID����
Source: ..\..\..\..\֤�����\������������\����\��������\x86\cidcusb.cat; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\��������\x86\CIDCUSB.inf; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\��������\x86\CIDCUSB.sys; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\��������\x86\dpinstx86.exe; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\��������\x64\cidcusb.cat; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit
Source: ..\..\..\..\֤�����\������������\����\��������\x64\CIDCUSB.inf; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit
Source: ..\..\..\..\֤�����\������������\����\��������\x64\CIDCUSB.sys; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit
Source: ..\..\..\..\֤�����\������������\����\��������\x64\dpinstx64.exe; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit

[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: string; ValueName: dllpath; ValueData: {app}\HSuKeyCI800Prov.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: string; ValueName: signature; ValueData: mCqKZklMtgFzbNbWjgSpTwiOG1TjGh7lOQ/rgE/s+16XmsqTv7Tyii65S1ltPV556d7COSR6nxDOeTZbfDX4jGHfAe9QBjSG4/VBHNJis0MONwrp2whq3zU7C1FiZMj1yX40ngDoHjFChMLq30R5YkOVuXvnX1RZSQUQG3jVNnw=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: dword; ValueName: type; ValueData: $0000002e; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: multisz; ValueName: idstring; ValueData: Vid_1677&Pid_0101; Flags: uninsdeletekey

[Run]
Filename: {sys}\HS\dpinstx86.exe; Parameters: /s /F /sa; Flags: runminimized runhidden; Check: IsOtherArch; WorkingDir: {sys}
Filename: {sys}\HS\dpinstx64.exe; Flags: runminimized runhidden 64bit; Parameters: /s /F /sa; WorkingDir: {sys}; Check: not IsOtherArch

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
NewUninsName := 'Unins_HS';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
MyAppName := 'B4D08D47-C8AE-4C96-ACBC-0483071A9C5E';
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
