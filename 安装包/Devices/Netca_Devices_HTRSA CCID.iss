; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_HT_CCID_RSA(32&64)"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.4"
#define UID  "69ED31C5-7183-4BD3-AC00-87E0F4B8F703"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{69ED31C5-7183-4BD3-AC00-87E0F4B8F703}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(HTCCID RSA)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#SETUP_FILE_VERSION}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_HT_CCID RSA
chinesesimp.SetupWindowTitle=网证通设备驱动_HT_CCID RSA

trad.SetupAppTitle=網證通設備驅動_HT_CCID RSA
trad.SetupWindowTitle=網證通設備驅動_HT_CCID RSA

eng.SetupAppTitle=NETCADevices_HT_CCID RSA
eng.SetupWindowTitle=NETCADevices_HT_CCID RSA
[Files]

;海泰智能卡阅读器Driver
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; DestDir: {pf}\NETCA\NETCA_Devices; Flags: deleteafterinstall

;64位系统动态设备DLL
Source: ..\..\winX64\设备驱动\海泰\海泰RSA COS\CCID\HaitaiCCIDRSAKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰\海泰RSA COS\CCID\HaitaiCCIDRSAKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64

;32位系统动态设备DLL
Source: ..\..\winX86\设备驱动\海泰\海泰RSA COS\CCID\HaitaiCCIDRSAKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\海泰\海泰RSA COS\CCID\HaitaiCCIDRSAKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64

;64位系统32位文件设备DLL
Source: ..\..\winX86\设备驱动\海泰\海泰RSA COS\CCID\HaitaiCCIDRSAKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\海泰\海泰RSA COS\CCID\HaitaiCCIDRSAKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]

;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaitaiCCIDRSAKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: signature; ValueData: g1T12wstOgRR4ekK5Uu0MrhbHoUutqDsFBnfhqSqCyHRq72geHIZS/jPnKVZT7sNspLFHlFePxVC5kzcGpUWpaaWG4bZTlA0NJsuwqHtHfLTHyRoCxkOHUb84q9dcSJ5ykuEdMOobNFcHXKDa2SyzKj1Wl9FNNA1pAM57aqs/LY=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: type; ValueData: $0000000c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

;32位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaitaiCCIDRSAKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: signature; ValueData: HrqzQdRQ2FTPbSScCsa+qWTUViHLnR50xDEwryZaitdsP34h5jRUxglTKAEGztLygoDm4/JK8IlaJwiYd9aqnbJR7G4gASCt9s5NMmrAI3Zh7QH4/Sq6Acj7w5muvTVJAoXY/7x6aY/DM3SUzFgJwu/HpDu+oCzDM8CIExI6/Dg=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: type; ValueData: $0000000c; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64

;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: type; ValueData: $0000000c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: signature; ValueData: HrqzQdRQ2FTPbSScCsa+qWTUViHLnR50xDEwryZaitdsP34h5jRUxglTKAEGztLygoDm4/JK8IlaJwiYd9aqnbJR7G4gASCt9s5NMmrAI3Zh7QH4/Sq6Acj7w5muvTVJAoXY/7x6aY/DM3SUzFgJwu/HpDu+oCzDM8CIExI6/Dg=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiCCIDRSAKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTCCIDRSA; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64

[Run]
Filename: {pf}\NETCA\NETCA_Devices\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {pf}\NETCA\NETCA_Devices; Flags: runminimized runhidden

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
NewUninsName := 'Unins_HT_CCID RSA';

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
