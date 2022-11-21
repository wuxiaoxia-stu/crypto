; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_ESA(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "B8F9FABB-42A6-498E-9F5E-D393DA02762F"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{B8F9FABB-42A6-498E-9F5E-D393DA02762F}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(ESA)
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

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_ESA
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_ESA

trad.SetupAppTitle=�W�Cͨ�O����_ESA
trad.SetupWindowTitle=�W�Cͨ�O����_ESA

eng.SetupAppTitle=NETCADevices_ESA
eng.SetupWindowTitle=NETCADevices_ESA

[Files]
;����(32λϵͳ)
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x86\SJK1944_NETCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x86\SJK1944_NETCASV2.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;32λ�豸dll�ļ�
Source: ..\..\..\winX86\�豸����\�Ķ���\����Key\SJK1944GProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\�豸����\�Ķ���\����Key\SJK1944GProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x86\SJK1944GProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64λ�豸64λdll�ļ�
Source: ..\..\..\winX64\�豸����\�Ķ���\����Key\SJK1944GProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\�豸����\�Ķ���\����Key\SJK1944GProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x64\SJK1944GProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λ�豸32λdll�ļ�
Source: ..\..\..\winX86\�豸����\�Ķ���\����Key\SJK1944GProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\�豸����\�Ķ���\����Key\SJK1944GProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x86\SJK1944GProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;����(64λϵͳ)
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x86\SJK1944_NETCA.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x86\SJK1944_NETCASV2.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x64\SJK1944_NETCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\֤�����\������������\�����Ķ���\����Key\SKF�ӿ�\Windows\x64\SJK1944_NETCASV2.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;32λϵͳ
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: dllpath; ValueData: {app}\SJK1944GProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: multisz; ValueName: idstring; ValueData: vid_1EA8&pid_C11B{break}vid_1EA8&pid_C140; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: signature; ValueData: aTKTxDV/8ZeesXD49zn9enIuglYVVHyX5jprYB9ilOE0M2yIz1d5tXBU7qxHi84bqfjDxvgFnA9kEoZOBKeW35lMmAoi9rohW62ONXMks45uge8Ro1/rtoJosx9trZBhxuLYRirZmWVREcGmrffFe3rUBOdS5hN7zS9D6ibitT0=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: type; ValueData: $00000044; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: UID; Flags: uninsdeletekey; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: version; Flags: uninsdeletekey; ValueData: {#SETUP_FILE_VERSION}
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\SJK1944GProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: multisz; ValueName: idstring; ValueData: vid_1EA8&pid_C11B{break}vid_1EA8&pid_C140; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: signature; ValueData: aTKTxDV/8ZeesXD49zn9enIuglYVVHyX5jprYB9ilOE0M2yIz1d5tXBU7qxHi84bqfjDxvgFnA9kEoZOBKeW35lMmAoi9rohW62ONXMks45uge8Ro1/rtoJosx9trZBhxuLYRirZmWVREcGmrffFe3rUBOdS5hN7zS9D6ibitT0=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: type; ValueData: $00000044; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: UID; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: version; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#SETUP_FILE_VERSION}

;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\SJK1944GProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: multisz; ValueName: idstring; ValueData: vid_1EA8&pid_C11B{break}vid_1EA8&pid_C140; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: string; ValueName: signature; ValueData: J/Eqre0z3JCVqTun9Ix7pUnG0e9oTQLriaWgxpo6b+PbMa3q4riRjUUqYcWgZisK6LodbgaiF1u2NQE/5PeIa4YHFvmopouIbD18VOTz5OTjen2yxbgVsl9xeWC4AzqGG8OS47j/Nk527uz85OG1dVkneckajyzkOepYXs8S6TI=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: type; ValueData: $00000044; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyESA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

;
[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[InstallDelete]
Name: {app}\Unins_ESA.dat; Type: files
Name: {app}\Unins_ESA.exe; Type: files

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
		NewUninsName := 'Unins_ESA';
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


[_ISTool]
UseAbsolutePaths=false
