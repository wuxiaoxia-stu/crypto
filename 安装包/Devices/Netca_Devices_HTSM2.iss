; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_HTSM2(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.8"
#define UID "EAB2175A-C7CE-4FFF-BF32-C56C7CDBAD64"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{EAB2175A-C7CE-4FFF-BF32-C56C7CDBAD64}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(HTSM2)
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


ShowLanguageDialog=auto
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoCompany=NETCA
VersionInfoProductVersion={#SETUP_FILE_VERSION}
CreateUninstallRegKey=true
UninstallLogMode=new

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_HTSM2
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_HTSM2

trad.SetupAppTitle=�W�Cͨ�O����_HTSM2
trad.SetupWindowTitle=�W�Cͨ�O����_HTSM2

eng.SetupAppTitle=NETCADevices_HTSM2
eng.SetupWindowTitle=NETCADevices_HTSM2

[Files]
;��̩����(32λ)
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\HaitaiSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\��̩SM2��Key\HaitaiSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\��̩SM2��Key\HaitaiSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64

;��̩������64λ��
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GECN20524.dat; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GECSP20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GECSP20524.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GER20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\HTCSPApi20524.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\SKFAPI20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GEA20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GEC20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\GECFG20524.dat; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\SKFApi20524.lib; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;��˾��̬�豸DLL(64λ)
Source: ..\..\winX64\�豸����\��̩SM2��Key\HaiTaiSM2Key.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\��̩SM2��Key\HaiTaiSM2Key.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win64\HaitaiSM2Key.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;��̩����(32λ)
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
;Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\HaitaiSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\��̩SM2��Key\HaitaiSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\��̩SM2��Key\HaitaiSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64



[Registry]
;HTSM2ע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch


Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: cG8TDLCNtEJyuv2h3lJlOleQ2vcLgyGD8moHChiUVoxJjqtFbqqoqsgucRXh5YRs/VC+KKUcHjg98c/83J8NKOhwRzooltkkKu1sgYxQRTT5L1B+LtD9Hnl469rmngzeeKuIsSuubtswKmvmB8NOrnIfbZovcPIena4mgNLk1qE=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

[InstallDelete]
Name: {app}\Unins_HTSM2.dat; Type: files
Name: {app}\Unins_HTSM2.exe; Type: files
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
uninspath, uninsname, NewUninsName, MyAppName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_HTSM2';
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
