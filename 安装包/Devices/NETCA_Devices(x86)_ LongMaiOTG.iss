; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_LongMaiOTG"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.18"
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
OutputBaseFilename=NETCA_Devices(LongMaiOTG)
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
chinesesimp.SetupAppTitle=网证通设备驱动_LongMaiOTG.exe
chinesesimp.SetupWindowTitle=网证通设备驱动_LongMaiOTG.exe

[Files]
;;32位系统32位文件
Source: ..\..\winX86\设备驱动\龙脉GM3000\OTG KEY\LMaiOTGKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\龙脉GM3000\OTG KEY\LMaiOTGKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\LMaiOTGKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\mtoken_gm3000.dll; DestDir: {sys}; Check: not IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
;;64位系统32位文件
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\mtoken_gm3000.dll; DestDir: {syswow64}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\龙脉GM3000\OTG KEY\LMaiOTGKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\龙脉GM3000\OTG KEY\LMaiOTGKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\win32\LMaiOTGKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64位系统64位文件
Source: ..\..\winX64\设备驱动\龙脉GM3000\OTG KEY\LMaiOTGKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\设备驱动\龙脉GM3000\OTG KEY\LMaiOTGKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\x64\LMaiOTGKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\OTG KEY\skf\api\windows\x64\mtoken_gm3000.dll; DestDir: {sys}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion

[Registry]
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMgm; Flags: deletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E618{break}Vid_055C&Pid_DB08{break}Vid_055C&Pid_E508; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: type; ValueData: $00000036; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: signature; ValueData: bdEm0lOcBG95f3R3MCcjLjBwY/AKeh0rui9lzWApJFJD1nZ+tMOLq0Vp0EqUYY3jDpEHaIoMyxD/bOhdKFvQBUV0oVDF4mwvYQkO2mLXEVfTDOFJ0c7q6I7IlVgl4Ys06vXIREXNCaRKj1oSvEtTNwUhHf/w/TBvPXXqP8mwAAc=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\LMaiOTGKey.dll; Flags: uninsdeletekey; Check: IsWin64
;32位系统
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMgm; Flags: deletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E618{break}Vid_055C&Pid_DB08{break}Vid_055C&Pid_E508; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: type; ValueData: $00000036; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: signature; ValueData: bdEm0lOcBG95f3R3MCcjLjBwY/AKeh0rui9lzWApJFJD1nZ+tMOLq0Vp0EqUYY3jDpEHaIoMyxD/bOhdKFvQBUV0oVDF4mwvYQkO2mLXEVfTDOFJ0c7q6I7IlVgl4Ys06vXIREXNCaRKj1oSvEtTNwUhHf/w/TBvPXXqP8mwAAc=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\LMaiOTGKey.dll; Flags: uninsdeletekey; Check: not IsWin64
;64位系统
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: multisz; ValueName: idstring; ValueData: Vid_055C&Pid_E618{break}Vid_055C&Pid_DB08{break}Vid_055C&Pid_E508; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: dword; ValueName: type; ValueData: $00000036; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: signature; ValueData: CsCu7sjxf2BqL3wp/vMk4CwoIVcvK4a24iud/mTF8cW3oomoE/dSSmk3IW6bwIbZaKRDYleq12LyXp1fsEDtsV7git97joOZTi0hKFotJ2/cJAR+4hscQqeZKZQp2rBQ8CpfWXC62YgIMMs5T+kMJfZynb4ALFiEzmCdTvajBW0=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMOTG; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\LMaiOTGKey.dll; Check: IsWin64; Flags: uninsdeletekey
;


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
NewUninsName := 'Unins_LongMaiOTG';
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
[InstallDelete]
Name: {app}\Unins_LongMaiOTG.exe; Type: files
Name: {app}\Unins_LongMaiOTG.dat; Type: files
