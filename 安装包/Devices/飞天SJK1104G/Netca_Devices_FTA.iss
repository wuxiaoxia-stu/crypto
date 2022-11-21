; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FTA(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "87C7C0E7-F020-486A-AF10-6E3B45CB9BF4"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{87C7C0E7-F020-486A-AF10-6E3B45CB9BF4}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FTA)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no
AlwaysRestart =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
CreateUninstallRegKey=false
UninstallLogMode=overwrite
VersionInfoProductVersion={#APPVERSION}
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����
UpdateUninstallLogAppName=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FTA
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FTA

trad.SetupAppTitle=�W�Cͨ�O����_FTA
trad.SetupWindowTitle=�W�Cͨ�O����_FTA

eng.SetupAppTitle=NETCADevices_FTA
eng.SetupWindowTitle=NETCADevices_FTA

[Files]
;(32λϵͳ)
Source: ..\..\..\..\..\֤�����\������������\����SM2\֧�ֹ���ӡ��Key\x86\Ft3000GM_Netca_SKF.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\����SM2\֧�ֹ���ӡ��Key\x86\FtSJK1104GProv.dll_driver.ini; DestDir: {app}; Flags: ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\�豸����\����3000GM\SJK1104-G\FTSJK1104GProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\�豸����\����3000GM\SJK1104-G\FTSJK1104GProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64λϵͳ32λ�ļ�
Source: ..\..\..\..\..\֤�����\������������\����SM2\֧�ֹ���ӡ��Key\x86\Ft3000GM_Netca_SKF.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\����SM2\֧�ֹ���ӡ��Key\x86\FtSJK1104GProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\�豸����\����3000GM\SJK1104-G\FTSJK1104GProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\�豸����\����3000GM\SJK1104-G\FTSJK1104GProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ64λ�豸DLL
Source: ..\..\..\..\..\֤�����\������������\����SM2\֧�ֹ���ӡ��Key\x64\Ft3000GM_Netca_SKF.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\����SM2\֧�ֹ���ӡ��Key\x64\FtSJK1104GProv.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\����3000GM\SJK1104-G\FTSJK1104GProv.dll; DestDir: {app}; Flags: sharedfile uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\����3000GM\SJK1104-G\FTSJK1104GProv.dll_device.ini; DestDir: {app}; Flags: ignoreversion; Check: IsWin64


[Registry]
;32λϵͳ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_031E; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: type; ValueData: $00000046; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: signature; ValueData: mwnxSAtiHFgOW/9qf5L7l1uar6bXFcO/mhiWS6HnjevmcmiNJOLBBGoRc68q2EvC4G6F+4n1EZnCGpLq3p0dI06ncIOnX81sT9NEfh9t+hBTAlC7mxgLIZ9ULk4wbO2kmSdHFZKJzkoEmJw/EUjm3HnAyXXb971YwagP1zcQHXY=; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FtSJK1104GProv.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: UID; Flags: uninsdeletekey; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: version; Flags: uninsdeletekey; ValueData: {#SETUP_FILE_VERSION}
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_031E; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: type; ValueData: $00000046; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: signature; ValueData: mwnxSAtiHFgOW/9qf5L7l1uar6bXFcO/mhiWS6HnjevmcmiNJOLBBGoRc68q2EvC4G6F+4n1EZnCGpLq3p0dI06ncIOnX81sT9NEfh9t+hBTAlC7mxgLIZ9ULk4wbO2kmSdHFZKJzkoEmJw/EUjm3HnAyXXb971YwagP1zcQHXY=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FtSJK1104GProv.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: UID; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: version; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#SETUP_FILE_VERSION}

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_031E; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: type; ValueData: $00000046; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: signature; ValueData: R/vL8snPJUeAtY57jWmuy9f6JI5zQha3Xl4ix84NsNAh5qle8weZQJa0vkcBPDbW9mzpNNrTgo3AF7ZYWhi6l/Di7Anq1oSjgb3DZJtRkXhGsHvHYcpAFEnkF2QXA7LYBUII3/JhG6mB4pHD/0sNiJ7jtTu5ZxQefgiSlwz1Xgo=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: dllpath; ValueData: {app}\FtSJK1104GProv.dll; Flags: uninsdeletevalue; Check: IsWin64

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[InstallDelete]
Name: {app}\Unins_FTA.dat; Type: files
Name: {app}\Unins_FTA.exe; Type: files


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
	uninspath, uninsname, NewUninsName : string;
begin
	if CurStep=ssDone then
	begin
		// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
		NewUninsName := 'Unins_FTA';
		// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
		//MyAppName := '5EFB2F66-0220-47D9-AC47-8CCAC42104BB';
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

