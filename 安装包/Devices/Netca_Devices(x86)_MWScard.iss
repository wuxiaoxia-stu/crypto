; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_MWScard(32位)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.8"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{4AE61B82-01F4-4188-A004-AAF968A57965}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(MWScard)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32位
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;不提示重启
;UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
UninstallRestartComputer=false
UninstallLogMode=overwrite
ArchitecturesInstallIn64BitMode=x64 ia64


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_MWScard
chinesesimp.SetupWindowTitle=网证通设备驱动_MWScard

trad.SetupAppTitle=網證通設備驅動_MWScard
trad.SetupWindowTitle=網證通設備驅動_MWScard

eng.SetupAppTitle=NETCADevices_MWScard
eng.SetupWindowTitle=NETCADevices_MWScard
[Files]
;MWScard驱动（32位）无

;公司动态设备DLL(32位)
Source: ..\..\winX86\设备驱动\明华卡\广一医院\MWScardProv.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\明华卡\广一医院\MWScardProv.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\明华卡\广一医院\MWScardProv.dll_driver.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion

[Registry]
;32位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: dllpath; ValueData: {app}\MWScardProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: signature; ValueData: YqYsiP7STyEzanSnkAAaMVrRIR31jZh+hu9a9RLg/dnymN5gNCXQh/jY6isbBKVG6eyGykannjzVNmLgVCtq2wjT1NZYt1PYTqGpmFeblJSFmwtqlIhcaBRqfs7IsRGkYsNWOFPDaUAMXUz24nED3hNtzcLBLx94Ns/CiztjzfQ=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: class; ValueData: PC/SC; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: type; ValueData: $0000002d; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: multisz; ValueName: idstring; ValueData: ACS ACR1281 1S Dual Reader PICC 0; Flags: uninsdeletekey; Check: not IsWin64

;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: multisz; ValueName: idstring; ValueData: ACS ACR1281 1S Dual Reader PICC 0; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: type; ValueData: $0000002d; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: class; ValueData: PC/SC; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: signature; ValueData: YqYsiP7STyEzanSnkAAaMVrRIR31jZh+hu9a9RLg/dnymN5gNCXQh/jY6isbBKVG6eyGykannjzVNmLgVCtq2wjT1NZYt1PYTqGpmFeblJSFmwtqlIhcaBRqfs7IsRGkYsNWOFPDaUAMXUz24nED3hNtzcLBLx94Ns/CiztjzfQ=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: string; ValueName: dllpath; ValueData: {app}\MWScardProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMWScard; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64



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
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_MWScard';
// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
MyAppName := '4AE61B82-01F4-4188-A004-AAF968A57965';
// 以下重命名卸载文件
uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
// 以下修改相应的注册表内容
if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1') then
begin
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
end;
end;
end;
