; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_NetcaKeySoftCert_IIS"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "B3510793-DD3F-44DE-880D-DDC5EE567CD6"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{B3510793-DD3F-44DE-880D-DDC5EE567CD6}
;Ӧ�ó�����Ϣ
AppName={#DEVICES_APPNAME}
AppVerName={#DEVICES_APPNAME}
AppCopyright={#NETCA}����������Ȩ����
UninstallRestartComputer =no
ShowLanguageDialog=auto
UninstallLogMode=overwrite
UninstallDisplayName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

;Ӧ�ó���Ŀ¼
DefaultDirName={pf}\NETCA\NETCA_Devices

;�������  ѹ��
OutputBaseFilename=NETCA_Devices(NetcaKeySoftCert_IIS)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;�汾��Ϣ
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCompany={#NETCA}
VersionInfoDescription={#DEVICES_APPNAME}����
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#DEVICES_APPVERSION}
CreateUninstallRegKey=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_NetcaKeySoftCert_IIS
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_NetcaKeySoftCert_IIS

trad.SetupAppTitle=�W�Cͨ�O����_NetcaKeySoftCert_IIS
trad.SetupWindowTitle=�W�Cͨ�O����_NetcaKeySoftCert_IIS

eng.SetupAppTitle=NETCADevices_NetcaKeySoftCert_IIS
eng.SetupWindowTitle=NETCADevices_NetcaKeySoftCert_IIS

[Files]

;�豸dll(32λϵͳ32λ�ļ�)
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;�豸dll(64λϵͳ��32λ�ļ�)
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\�豸����\��֤��\NetcaSoftKeyProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;�豸dll(64λϵͳ��64λ�ļ�)
Source: ..\..\..\winX64\�豸����\��֤��\NetcaSoftKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\��֤��\NetcaSoftKeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32λע���32λϵͳ-NetcaSoftKeyProv_32.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64

Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64

;32λע���64λϵͳ-NetcaSoftKeyProv_64.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

;32λע���32λϵͳ-NetcaSoftKeyProv_IIS_32.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: CertificateFilePath; ValueData: D:\NetcaSoftKey\; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64

;32λע���64λϵͳ-NetcaSoftKeyProv_IIS_64.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaSoftKeyProv.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: CertificateFilePath; ValueData: D:\NetcaSoftKey\; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64


;64λע���64λϵͳ-NetcaSoftKeyProv.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: Ma0HA3mrjU/WGVLKUph4MhzcqF0OuQRZUqaTzzGZuFPJLXfdKS2/P0AQSqciUOS6EcknLoswolO3iPpqxR/s2C679/URrelrPLlf/SFc/Nwohc1fm6Bof9XGBkMk2qRP72mb1ksYdxjYzHmgy6wn/WfswXg0nzHgLDG5lY8QuQs=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64

;64λע���64λϵͳ-NetcaSoftKeyProv_IIS.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: Ma0HA3mrjU/WGVLKUph4MhzcqF0OuQRZUqaTzzGZuFPJLXfdKS2/P0AQSqciUOS6EcknLoswolO3iPpqxR/s2C679/URrelrPLlf/SFc/Nwohc1fm6Bof9XGBkMk2qRP72mb1ksYdxjYzHmgy6wn/WfswXg0nzHgLDG5lY8QuQs=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: CertificateFilePath; ValueData: D:\NetcaSoftKey\; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64



[InstallDelete]
Name: {app}\Unins_NetcaKeySoftCert.dat; Type: files
Name: {app}\Unins_NetcaKeySoftCert.exe; Type: files
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

[_ISTool]
UseAbsolutePaths=false
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
NewUninsName := 'Unins_NetcaKeySoftCert';
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
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
end;
end;
end;
