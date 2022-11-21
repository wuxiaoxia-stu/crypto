; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_DX(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.9"
#define UID  "DF6F6DF1-D1BF-4068-B199-A111A7100CE9"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{DF6F6DF1-D1BF-4068-B199-A111A7100CE9}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(DX)
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
chinesesimp.SetupAppTitle=网证通设备驱动_DX
chinesesimp.SetupWindowTitle=网证通设备驱动_DX

trad.SetupAppTitle=網證通設備驅動_DX
trad.SetupWindowTitle=網證通設備驅動_DX

eng.SetupAppTitle=NETCADevices_DX
eng.SetupWindowTitle=NETCADevices_DX

[Files]
;32位系统设备驱动
Source: ..\..\winX86\设备驱动\鼎信\USBKey\NetcaDingXin.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch
Source: ..\..\winX86\设备驱动\鼎信\USBKey\NetcaDingXin.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch
Source: ..\..\winX86\设备驱动\鼎信\USBKey\NetcaDingXin.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch
Source: ..\..\..\..\证书介质\驱动及开发包\鼎信\USB Key\SKF\win32\SKF_T1.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsOtherArch

;64位系统32位驱动
Source: ..\..\winX86\设备驱动\鼎信\USBKey\NetcaDingXin.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\鼎信\USBKey\NetcaDingXin.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\鼎信\USBKey\NetcaDingXin.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\鼎信\USB Key\SKF\win32\SKF_T1.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位系统设备驱动
Source: ..\..\winX64\设备驱动\鼎信\USBKey\NetcaDingXin.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\鼎信\USBKey\NetcaDingXin.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\鼎信\USBKey\NetcaDingXin.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\鼎信\USB Key\SKF\win64\SKF_T1.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;32位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: class; ValueData: USB; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: signature; ValueData: HJmEWqN6A367fRWTI5EL7m0HfXlRrSi18JfmT6BiTGRy+ScdV3O2tI3ck+/xNfNnHu59BHkNJrv2L54joBXFMA5RZMZ4dpwKN48Zj3mn+jtQUc/i/fEFUwbdF6LHilSeoGBRWI1WF8R66jyokZfiVGFsTRxpFMieUghk7DTirOI=; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaDingXin.dll; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: type; ValueData: $00000042; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: multisz; ValueName: idstring; ValueData: vid_2FD0&pid_1000; Check: IsOtherArch; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsOtherArch; Flags: uninsdeletekey


;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: signature; ValueData: HJmEWqN6A367fRWTI5EL7m0HfXlRrSi18JfmT6BiTGRy+ScdV3O2tI3ck+/xNfNnHu59BHkNJrv2L54joBXFMA5RZMZ4dpwKN48Zj3mn+jtQUc/i/fEFUwbdF6LHilSeoGBRWI1WF8R66jyokZfiVGFsTRxpFMieUghk7DTirOI=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaDingXin.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: type; ValueData: $00000042; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: multisz; ValueName: idstring; ValueData: vid_2FD0&pid_1000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: signature; ValueData: WOw7XfJrqBgh5XUYzF+L8kQIHm5/u7ZndGCWhot96XZ2pp962JjFwFW4qxdHPyXz4w03qvRN7AgayZRyStGRouneYkhqSFP6mLbpwxSBzl5fTYU+gdYNWHcmK8l0Jdrgv9wBI5quQANjC5PSNcsAOKhlADZGKmd7NzRpP/njmu8=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\NetcaDingXin.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: type; ValueData: $00000042; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: multisz; ValueName: idstring; ValueData: vid_2FD0&pid_1000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[InstallDelete]
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files
Name: {app}\Unins_DX.exe; Type: files
Name: {app}\Unins_DX.dat; Type: files

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
if CurStep=ssInstall then
begin
      //MsgBox('确定安装之前，存在的话准备删除旧版本注册表', mbInformation, MB_OK);
        if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyDX') then
       RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyDX');
      if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX') then
       RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyDX');
     //  MsgBox('确定安装之前，存在的话删除注册表成功，开始安装新版本', mbInformation, MB_OK);
end;

if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_DX';
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
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
end;
end;
end;

[_ISTool]
UseAbsolutePaths=false
