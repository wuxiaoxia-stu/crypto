; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_LongMaiGM3000"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.8"
#define UID  "6918D487-4079-4BF0-9130-68924C722680"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{6918D487-4079-4BF0-9130-68924C722680}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(x86)_LongMaiGM3000
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}

ArchitecturesAllowed=x86 x64 ia64
;不提示重启
AlwaysRestart =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
VersionInfoProductVersion={#DEVICES_APPVERSION}
ArchitecturesInstallIn64BitMode=x64 ia64

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_LongMaiGM3000(x86)
chinesesimp.SetupWindowTitle=网证通设备驱动_LongMaiGM3000(x86)

[Files]
;;32位系统32位文件
;;64位系统32位文件
Source: ..\..\winX86\设备驱动\龙脉GM3000\LongMaiGM3000.dll; DestDir: {app}; Flags: ignoreversion restartreplace uninsrestartdelete
Source: ..\..\winX86\设备驱动\龙脉GM3000\LongMaiGM3000.dll_device.ini; DestDir: {app}; Flags: ignoreversion restartreplace uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\LongMaiGM3000.dll_driver.ini; DestDir: {app}; Flags: ignoreversion restartreplace uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\mtoken_gm3000.dll; DestDir: {sys}; Flags: ignoreversion restartreplace uninsrestartdelete; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\mtoken_gm3000.dll; DestDir: {syswow64}; Flags: ignoreversion restartreplace uninsrestartdelete; Check: IsWin64

[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: string; ValueName: dllpath; ValueData: {app}\LongMaiGM3000.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: string; ValueName: signature; ValueData: iaanoZf8gkjaAWwpI90LhBjacKQWQVMQUpEmR35eGpCLkrAvV4QXCJHIVum0nMtDH4rySKaaf1L4Oum0fZvIDoiq7d2MRvE0yrByY4b051YvSH/y+ndlJQtoCWuhXLopbhBH0YOMMmMZ38s8IibMOJsAQsKjne9WML81AAsAyv8=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: dword; ValueName: type; ValueData: $00000031; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E618; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64

Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E618; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: dword; ValueName: type; ValueData: $00000031; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: string; ValueName: signature; ValueData: iaanoZf8gkjaAWwpI90LhBjacKQWQVMQUpEmR35eGpCLkrAvV4QXCJHIVum0nMtDH4rySKaaf1L4Oum0fZvIDoiq7d2MRvE0yrByY4b051YvSH/y+ndlJQtoCWuhXLopbhBH0YOMMmMZ38s8IibMOJsAQsKjne9WML81AAsAyv8=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; ValueType: string; ValueName: dllpath; ValueData: {app}\LongMaiGM3000.dll; Flags: uninsdeletekey; Check: IsWin64

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
if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeymTokenGM3000') then
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeymTokenGM3000');

if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeymTokenGM3000') then
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeymTokenGM3000');
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
NewUninsName := 'Unins_LongMaiGM3000';
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
