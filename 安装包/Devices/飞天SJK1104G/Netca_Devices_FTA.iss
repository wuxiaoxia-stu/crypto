; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_FTA(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "87C7C0E7-F020-486A-AF10-6E3B45CB9BF4"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{87C7C0E7-F020-486A-AF10-6E3B45CB9BF4}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(FTA)
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
AlwaysRestart =no

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
UpdateUninstallLogAppName=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_FTA
chinesesimp.SetupWindowTitle=网证通设备驱动_FTA

trad.SetupAppTitle=網證通設備驅動_FTA
trad.SetupWindowTitle=網證通設備驅動_FTA

eng.SetupAppTitle=NETCADevices_FTA
eng.SetupWindowTitle=NETCADevices_FTA

[Files]
;(32位系统)
Source: ..\..\..\..\..\证书介质\驱动及开发包\飞天SM2\支持国脉印章Key\x86\Ft3000GM_Netca_SKF.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\飞天SM2\支持国脉印章Key\x86\FtSJK1104GProv.dll_driver.ini; DestDir: {app}; Flags: ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\设备驱动\飞天3000GM\SJK1104-G\FTSJK1104GProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\设备驱动\飞天3000GM\SJK1104-G\FTSJK1104GProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64位系统32位文件
Source: ..\..\..\..\..\证书介质\驱动及开发包\飞天SM2\支持国脉印章Key\x86\Ft3000GM_Netca_SKF.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\飞天SM2\支持国脉印章Key\x86\FtSJK1104GProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\设备驱动\飞天3000GM\SJK1104-G\FTSJK1104GProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\设备驱动\飞天3000GM\SJK1104-G\FTSJK1104GProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位系统64位设备DLL
Source: ..\..\..\..\..\证书介质\驱动及开发包\飞天SM2\支持国脉印章Key\x64\Ft3000GM_Netca_SKF.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\..\证书介质\驱动及开发包\飞天SM2\支持国脉印章Key\x64\FtSJK1104GProv.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\设备驱动\飞天3000GM\SJK1104-G\FTSJK1104GProv.dll; DestDir: {app}; Flags: sharedfile uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\设备驱动\飞天3000GM\SJK1104-G\FTSJK1104GProv.dll_device.ini; DestDir: {app}; Flags: ignoreversion; Check: IsWin64


[Registry]
;32位系统
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_031E; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: type; ValueData: $00000046; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: signature; ValueData: mwnxSAtiHFgOW/9qf5L7l1uar6bXFcO/mhiWS6HnjevmcmiNJOLBBGoRc68q2EvC4G6F+4n1EZnCGpLq3p0dI06ncIOnX81sT9NEfh9t+hBTAlC7mxgLIZ9ULk4wbO2kmSdHFZKJzkoEmJw/EUjm3HnAyXXb971YwagP1zcQHXY=; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FtSJK1104GProv.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: UID; Flags: uninsdeletekey; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: version; Flags: uninsdeletekey; ValueData: {#SETUP_FILE_VERSION}
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_031E; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: dword; ValueName: type; ValueData: $00000046; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: signature; ValueData: mwnxSAtiHFgOW/9qf5L7l1uar6bXFcO/mhiWS6HnjevmcmiNJOLBBGoRc68q2EvC4G6F+4n1EZnCGpLq3p0dI06ncIOnX81sT9NEfh9t+hBTAlC7mxgLIZ9ULk4wbO2kmSdHFZKJzkoEmJw/EUjm3HnAyXXb971YwagP1zcQHXY=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FtSJK1104GProv.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: UID; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#UID}
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeyFTA; ValueType: string; ValueName: version; Flags: uninsdeletekey; Check: IsWin64; ValueData: {#SETUP_FILE_VERSION}

;64位系统64位注册表
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
		// 指定新的卸载文件名（不包含扩展名），请相应修改！
		NewUninsName := 'Unins_FTA';
		// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
		//MyAppName := '5EFB2F66-0220-47D9-AC47-8CCAC42104BB';
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

