; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_ESA(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "B8F9FABB-42A6-498E-9F5E-D393DA02762F"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{B8F9FABB-42A6-498E-9F5E-D393DA02762F}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(ESA)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
CreateUninstallRegKey=false
UninstallLogMode=overwrite
VersionInfoProductVersion={#APPVERSION}
VersionInfoCopyright=(C) {#NETCA}。保留所有权利。

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_ESA
chinesesimp.SetupWindowTitle=网证通设备驱动_ESA

trad.SetupAppTitle=網證通設備驅動_ESA
trad.SetupWindowTitle=網證通設備驅動_ESA

eng.SetupAppTitle=NETCADevices_ESA
eng.SetupWindowTitle=NETCADevices_ESA

[Files]
;驱动(32位系统)
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x86\SJK1944_NETCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x86\SJK1944_NETCASV2.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;32位设备dll文件
Source: ..\..\..\winX86\设备驱动\文鼎创\安可Key\SJK1944GProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\设备驱动\文鼎创\安可Key\SJK1944GProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x86\SJK1944GProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64位设备64位dll文件
Source: ..\..\..\winX64\设备驱动\文鼎创\安可Key\SJK1944GProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\设备驱动\文鼎创\安可Key\SJK1944GProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x64\SJK1944GProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位设备32位dll文件
Source: ..\..\..\winX86\设备驱动\文鼎创\安可Key\SJK1944GProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\设备驱动\文鼎创\安可Key\SJK1944GProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x86\SJK1944GProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;驱动(64位系统)
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x86\SJK1944_NETCA.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x86\SJK1944_NETCASV2.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x64\SJK1944_NETCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\安可Key\SKF接口\Windows\x64\SJK1944_NETCASV2.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;32位系统
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
;64位系统32位注册表
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

;64位系统64位注册表
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
	// 指定新的卸载文件名（不包含扩展名），请相应修改！
		NewUninsName := 'Unins_ESA';
		// 以下重命名卸载文件
		uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
		uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
		RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
		RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
		// 以下修改相应的注册表内容
		if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
		begin
			//MsgBox('检测到系统需要改', mbInformation, MB_OK);
			RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
			RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
			//MsgBox('检测到系统改完', mbInformation, MB_OK);
			RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
		end;
	end;
end;


[_ISTool]
UseAbsolutePaths=false
