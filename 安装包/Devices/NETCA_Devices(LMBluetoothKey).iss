; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_LMBluetoothKey"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.0"
#define UID  "317BF162-900D-403C-A265-61E4DD387A2B"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{317BF162-900D-403C-A265-61E4DD387A2B}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(LMBluetoothKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}

ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;不提示重启
AlwaysRestart =no

ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=new
VersionInfoProductVersion={#DEVICES_APPVERSION}


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_LMBluetoothKey.exe
chinesesimp.SetupWindowTitle=网证通设备驱动_LMBluetoothKey.exe

[Files]
;32位文件
Source: ..\..\winX86\设备驱动\龙脉GM3000\蓝牙KEY\LMaiBluetoothKey.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\龙脉GM3000\蓝牙KEY\LMaiBluetoothKey.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\蓝牙KEY\skf\win32\LMaiBluetoothKey.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\蓝牙KEY\skf\win32\mtoken_k5.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;64位文件
Source: ..\..\winX64\设备驱动\龙脉GM3000\蓝牙KEY\LMaiBluetoothKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\龙脉GM3000\蓝牙KEY\LMaiBluetoothKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\蓝牙KEY\skf\x64\LMaiBluetoothKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\蓝牙KEY\skf\win32\mtoken_k5.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\蓝牙KEY\skf\x64\mtoken_k5.dll; DestDir: {sys}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion

[Registry]
;32位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E425{break}Vid_055C&Pid_E623; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: type; ValueData: $00000037; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: signature; ValueData: ThrYNfJCBv11gFzkNlGpmLP/P3kFvl3ehTHlVJ7kWRAh1qbLS3iuC/wrDKMxb+2rL54VMpr0AM+D4y57CCt3ivkzr7YE8xFXMayZ+hd6Aaz9f1jNOjCt+oow1oTu7Gncj49WCDAeFw+pK8nNEK32CB+B0SSuGtSaJHJlJ5ECJiU=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: dllpath; ValueData: {app}\LMaiBluetoothKey.dll; Flags: uninsdeletekey; Check: not IsWin64
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E425{break}Vid_055C&Pid_E623; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: type; ValueData: $00000037; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: signature; ValueData: ThrYNfJCBv11gFzkNlGpmLP/P3kFvl3ehTHlVJ7kWRAh1qbLS3iuC/wrDKMxb+2rL54VMpr0AM+D4y57CCt3ivkzr7YE8xFXMayZ+hd6Aaz9f1jNOjCt+oow1oTu7Gncj49WCDAeFw+pK8nNEK32CB+B0SSuGtSaJHJlJ5ECJiU=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: dllpath; ValueData: {app}\LMaiBluetoothKey.dll; Flags: uninsdeletekey; Check: IsWin64

;64位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E425{break}Vid_055C&Pid_E623; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: dword; ValueName: type; ValueData: $00000037; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: signature; ValueData: i1aJsQXMf2JBHm6TnNdhbAQ/lHTQdOQI0OXGXmW+3pzPew6w24wCD+MS/9gGDwwwQv7t7eIApG+O3M7A+8Njla2LWE7UvL9vVbsIb9zbM9Yx3pE05399R/DcOhzSX8HkSvEcENIN8TZpkX7r4mPb/IqSLVvAAPYpCrttn49o4E4=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMBLE; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\LMaiBluetoothKey.dll; Flags: uninsdeletevalue; Check: IsWin64

[Code]
function IsX64: Boolean;
begin
  Result := (ProcessorArchitecture = paX64);
end;

function IsIA64: Boolean;
begin
  Result := (ProcessorArchitecture = paIA64);
end;

function IsWin64: Boolean;
begin
  Result :=IsX64 or IsIA64;
end;


procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_LMBluetoothKey';
// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
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
end;
end;
end;
