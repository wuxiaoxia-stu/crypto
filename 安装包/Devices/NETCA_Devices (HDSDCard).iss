; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_HDSDCard"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.11"
#define UID  "133E929D-A847-43F4-A534-4928CCB17D1A"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{133E929D-A847-43F4-A534-4928CCB17D1A}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(HDSDCard)
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
ArchitecturesInstallIn64BitMode=x64 ia64

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_HDSDCard
chinesesimp.SetupWindowTitle=网证通设备驱动_HDSDCard

[Files]
Source: ..\..\winX86\设备驱动\华大SDKey\HDMicroSDKey.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\华大SDKey\HDMicroSDKey.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\华大SM2\Release_2015-12-08\Win32\HDMicroSDKey.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\华大SM2\Release_2015-12-08\Win32\HD_Cryptoki.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\华大SM2\Release_2015-12-08\Win32\HD_Token.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\华大SM2\Release_2015-12-08\Win32\HD_Token.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\华大SM2\Release_2015-12-08\Win32\HD_Cryptoki.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
[Registry]
;32位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HDMicroSDKey.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: MzlBuDQqzTgVINISN48bqqPBJDgCwQ+da1oe8sSb0PyST0qKweSYmSbHeOrRnlfmkHsjcPcG4YhW9Eygk29KPtLUB5iB+QiJMkAzrIMn901+ydxrdLD9ho+8aDtJzrwHSWMBUpeecyOEXH73NUlR3YGX26qWTiuSlxdrLsfnKhk=; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: C:\Windows\system32\HD_Cryptoki.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64

;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: PKCS11DriverDLLUsage; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: PKCS11DriverDLLPath; ValueData: C:\Windows\SysWOW64\HD_Cryptoki.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: MzlBuDQqzTgVINISN48bqqPBJDgCwQ+da1oe8sSb0PyST0qKweSYmSbHeOrRnlfmkHsjcPcG4YhW9Eygk29KPtLUB5iB+QiJMkAzrIMn901+ydxrdLD9ho+8aDtJzrwHSWMBUpeecyOEXH73NUlR3YGX26qWTiuSlxdrLsfnKhk=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HDMicroSDKey.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: 1; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: 1; Flags: uninsdeletevalue; Check: IsWin64

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
NewUninsName := 'Unins_HDSDCard';
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
