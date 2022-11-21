; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_HSSM2(32位)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.15"
#define UID  "3BA3B438-0B5C-49D2-9B23-8023E10C5EA0"


[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{3BA3B438-0B5C-49D2-9B23-8023E10C5EA0}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(HSSM2)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32位
ArchitecturesAllowed=x86 x64 ia64
;不提示重启
;UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductVersion={#DEVICES_APPVERSION}
UninstallDisplayName={#DEVICES_APPNAME}
VersionInfoCompany={#NETCA}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
VersionInfoCopyright={#NETCA}。保留所有权利。
CreateUninstallRegKey=false


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_华申SM2
chinesesimp.SetupWindowTitle=网证通设备驱动_华申SM2

trad.SetupAppTitle=網證通設備驅動_HSSM2
trad.SetupWindowTitle=網證通設備驅動_HSSM2

eng.SetupAppTitle=NETCADevices_HSSM2
eng.SetupWindowTitle=NETCADevices_HSSM2

[Files]

;公司动态设备DLL(32位)
Source: ..\..\winX86\设备驱动\华申SM2\NETCAHSICKey.dll; DestDir: {app}; Flags: ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\华申SM2\NETCAHSICKey.dll_device.ini; DestDir: {app}; Flags: ignoreversion restartreplace
Source: ..\..\..\..\证书介质\驱动及开发包\华申SM2\接口库\SKF_APP.dll; DestDir: {sys}; Flags: ignoreversion restartreplace
Source: ..\..\..\..\证书介质\驱动及开发包\华申SM2\接口库\SKF_Token_HSIC.dll; DestDir: {sys}; Flags: ignoreversion restartreplace
Source: ..\..\..\..\证书介质\驱动及开发包\华申SM2\接口库\HSIC DriverSetup.exe; DestDir: {app}; Flags: ignoreversion deleteafterinstall
Source: ..\..\..\..\证书介质\驱动及开发包\华申SM2\接口库\NETCAHSICKey.dll_driver.ini; DestDir: {app}; Flags: ignoreversion restartreplace

[Registry]
;32位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: dllpath; ValueData: {app}\NETCAHSICKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: signature; ValueData: rpn26O+UTycdlX3EoAzdghLXC6VRtz4fM0wAmiVCfMOEku0Y55iJ7NV9daTuZr0VfsxUQKGZ9tMgTG0pcaI0NYqvbWcreLg9V0nN7M6utJTpjPBMCenEdNqAO/l/owoLt4ua+c1uMH8MNbb1sMga+Nk60+AR9YCb8t1hy8268dY=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: type; ValueData: $00000031; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_1D99&Pid_0001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: dllpath; ValueData: {app}\NETCAHSICKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: signature; ValueData: rpn26O+UTycdlX3EoAzdghLXC6VRtz4fM0wAmiVCfMOEku0Y55iJ7NV9daTuZr0VfsxUQKGZ9tMgTG0pcaI0NYqvbWcreLg9V0nN7M6utJTpjPBMCenEdNqAO/l/owoLt4ua+c1uMH8MNbb1sMga+Nk60+AR9YCb8t1hy8268dY=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: type; ValueData: $00000031; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_1D99&Pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAHSICKey; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

[InstallDelete]
Name: {app}\Unins_HSSM2.dat; Type: files
Name: {app}\Unins_HSSM2.exe; Type: files

[Run]
Filename: {app}\HSIC DriverSetup.exe; WorkingDir: {app}; Flags: runminimized runhidden runascurrentuser; Parameters: /sp- /VERYSILENT /norestart  /s

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
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_HSSM2';
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
