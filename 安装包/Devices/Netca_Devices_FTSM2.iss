; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_FTSM2"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{DCF40849-03AE-4497-90E8-2F3D8C6B8243}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(FTSM2)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32位
VersionInfoVersion ={#SETUP_FILE_VERSION}
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_FTSM2
chinesesimp.SetupWindowTitle=网证通设备驱动_FTSM2

trad.SetupAppTitle=網證通設備驅動_FTSM2
trad.SetupWindowTitle=網證通設備驅動_FTSM2

eng.SetupAppTitle=NETCADevices_FTSM2
eng.SetupWindowTitle=NETCADevices_FTSM2

[Files]

;32位系统32位飞天SM2驱动
Source: ..\..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\32位\GmCsp.dll; DestDir: {sys}; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\32位\FeiTianSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion
;32位系统32位公司动态设备DLL
Source: ..\..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsOtherArch; Flags: restartreplace uninsrestartdelete ignoreversion


;64位系统32位飞天SM2驱动
Source: ..\..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\64位\GmCsp.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\64位\FeiTianSM2Key.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位系统32位公司动态设备DLL
Source: ..\..\winX64\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;64位系统32位飞天SM2驱动
Source: ..\..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\32位\GmCsp.dll; DestDir: {syswow64}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\32位\FeiTianSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
;64位系统32位公司动态设备DLL
Source: ..\..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion


[Registry]
;飞天SM2
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: JgNgzowo0v4ow77gLTv+/jf27NrKuAjcpKV/jwqHI9ARLrvN14LuexjCc7V07JkQKfsZuyQKvrnkw+tzoZwhDM7/4u6ZCsTGGew0RV9JEDeHFJ4uLsLpaf+4BDdY52tNlGH7vaRm7K/oukMLbP0lapiCJD1+5krg7V0M3UZHK3I=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch


Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: gCFRS9Mv7lhLCeuX0jKXXq2SjrtIPrE2ogzYtNMpoNo3lGyUhnNNYrR+lXA+OU9im6AoLVj6nmHH4i9L7HlA0i1khiixu3CFcXd1cPRJ1jottlMkiofjg1PhAhiZS2f8QQkemVFnRHIkAjRUNrJ1p0UKKUeLu6kyb0gnDwFm5ac=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: JgNgzowo0v4ow77gLTv+/jf27NrKuAjcpKV/jwqHI9ARLrvN14LuexjCc7V07JkQKfsZuyQKvrnkw+tzoZwhDM7/4u6ZCsTGGew0RV9JEDeHFJ4uLsLpaf+4BDdY52tNlGH7vaRm7K/oukMLbP0lapiCJD1+5krg7V0M3UZHK3I=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64


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
NewUninsName := 'Unins_FTSM2';
// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
MyAppName := 'DCF40849-03AE-4497-90E8-2F3D8C6B8243';
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
