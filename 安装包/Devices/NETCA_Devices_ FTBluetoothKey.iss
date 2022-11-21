; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_FTBluetoothKey"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.11"
#define UID  "9F7E355F-4C13-4BF4-B099-59851B342111"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{9F7E355F-4C13-4BF4-B099-59851B342111}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}.保留所有权利。
OutputBaseFilename=NETCA_Devices(FTBluetoothKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoCopyright=C.{#NETCA}.保留所有权利。
ArchitecturesAllowed=x86 x64 ia64
;不提示重启
AlwaysRestart =no

;不在"添加/删除程序"面板中显示卸载
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
VersionInfoProductVersion={#DEVICES_APPVERSION}
ArchitecturesInstallIn64BitMode=x64 ia64
CreateUninstallRegKey=false



[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_FTBluetoothKey
chinesesimp.SetupWindowTitle=网证通设备驱动_FTBluetoothKey

[Files]
;32位系统文件
Source: ..\..\winX86\设备驱动\飞天蓝牙KEY\FtBluetoothKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\飞天蓝牙KEY\FtBluetoothKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天蓝牙KEY\PC端正式发布的接口\x86\FtBluetoothKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天蓝牙KEY\PC端正式发布的接口\x86\WZTBIP3000P11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64位系统文件
Source: ..\..\winX64\设备驱动\飞天蓝牙KEY\FtBluetoothKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天蓝牙KEY\FtBluetoothKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天蓝牙KEY\PC端正式发布的接口\x64\FtBluetoothKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

Source: ..\..\winX86\设备驱动\飞天蓝牙KEY\FtBluetoothKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\飞天蓝牙KEY\FtBluetoothKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天蓝牙KEY\PC端正式发布的接口\x86\FtBluetoothKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

Source: ..\..\..\..\证书介质\驱动及开发包\飞天蓝牙KEY\PC端正式发布的接口\x64\WZTBIP3000P11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天蓝牙KEY\PC端正式发布的接口\x86\WZTBIP3000P11.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
[Registry]
;64位系统文件
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTGM; Flags: deletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: multisz; ValueName: idstring; ValueData: vid_096E&Pid_0309{break}vid_096E&Pid_0811; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: type; ValueData: $00000032; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: signature; ValueData: G0GN2a53L2w6jqmkSPJA/4YuXfOVm4qLEK6ljvbR+FT17FEJoWeNJOGPAVxWTh17ae5sSsZ0fobSt2OXWtUdwinU7h9knueT5UQ7Ov2TcRh3wl+TT1ckR0iSDDafVcvdwtMAs2RaHvccnzSXWzFLO2E6U189ICVuqS20Tiy0Ybw=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FtBluetoothKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64

Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTGM; Flags: deletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: multisz; ValueName: idstring; ValueData: vid_096E&Pid_0309{break}vid_096E&Pid_0811; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: type; ValueData: $00000032; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: signature; ValueData: WmLJurfNpdDZrSOIWEYA65/ftIjhcm7bVUYRZ+OuqVKPLbSVdVXrMk6VmiPHAR9gYXdOwNYVuxMfWYu8LTQSnULl/Jd3xEP3k493qqggKa5BbDZl8tAeGr2Hpvug1anceOlBNrBwrv8ANhwcjolt7QKa6pmaHRXtR81O8L0gdOU=; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FtBluetoothKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64


;32位系统文件
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTGM; Flags: deletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: multisz; ValueName: idstring; ValueData: vid_096E&Pid_0309{break}vid_096E&Pid_0811; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: dword; ValueName: type; ValueData: $00000032; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: class; ValueData: USB; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: signature; ValueData: WmLJurfNpdDZrSOIWEYA65/ftIjhcm7bVUYRZ+OuqVKPLbSVdVXrMk6VmiPHAR9gYXdOwNYVuxMfWYu8LTQSnULl/Jd3xEP3k493qqggKa5BbDZl8tAeGr2Hpvug1anceOlBNrBwrv8ANhwcjolt7QKa6pmaHRXtR81O8L0gdOU=; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FtBluetoothKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTBLE; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64


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


//删除残留的注册信息
function DelReg():Boolean;
begin
if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyEpass3000GM') then
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyEpass3000GM');

if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEpass3000GM') then
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEpass3000GM');
end;


procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
//删除旧注册表
DelReg();
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_FTBluetoothKey';
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
