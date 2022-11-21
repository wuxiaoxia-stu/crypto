; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_FT2003(32&64)"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"
#define UID  "20432922-9DB7-437E-B04E-C175B8A47FEC"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{20432922-9DB7-437E-B04E-C175B8A47FEC}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(FT2003)
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
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
CreateUninstallRegKey=true
PrivilegesRequired=none

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_FT2003
chinesesimp.SetupWindowTitle=网证通设备驱动_FT2003

trad.SetupAppTitle=網證通設備驅動_FT2003
trad.SetupWindowTitle=網證通設備驅動_FT2003

eng.SetupAppTitle=NETCADevices_FT2003
eng.SetupWindowTitle=NETCADevices_FT2003

[Files]
;驱动(32位系统)
Source: ..\..\winX86\设备驱动\飞天2003\Epass2003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\飞天2003\Epass2003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天epass2003\pkcs11库\x86\eps2003csp11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天epass2003\pkcs11库\x86\Epass2003Prov.dll_driver.ini; DestDir: {pf}\NETCA; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64位系统64位驱动
Source: ..\..\winX64\设备驱动\飞天2003\Epass2003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\设备驱动\飞天2003\Epass2003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\飞天epass2003\pkcs11库\x64\eps2003csp11.dll; DestDir: {sys}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\飞天epass2003\pkcs11库\x64\Epass2003Prov.dll_driver.ini; DestDir: {pf}\NETCA; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion

;64位系统32位公司动态设备DLL
Source: ..\..\winX86\设备驱动\飞天2003\Epass2003Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\飞天2003\Epass2003Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天epass2003\pkcs11库\x86\eps2003csp11.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天epass2003\pkcs11库\x86\Epass2003Prov.dll_driver.ini; DestDir: {pf32}\NETCA; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;32位系统
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass2003Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: signature; ValueData: hJRbsx0Nspt20bP3fr44IFLPZSKReRXtF7lJMFuQlf+qS1DBde4hXBfvQWSvOszuPNgQV5VcWrcVEmFuNrAoFF2qvN4Ue09rTLIuKKiJwYvVsp1VNM2Xv6pxZtXQop3PtnSWALqJu0lbqyYDMEbRjorRwSiF4/iXEjUsOJhRIwE=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: type; ValueData: $00000033; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0807; Flags: uninsdeletekey; Check: not IsWin64
;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass2003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: signature; ValueData: K7VqbFyEx2YP8zkJk6b/86DRneVku1oE2uwDCJu1s4Gf3iCKb4GK+86+Ak6RPa1mfRu9nN7G/mXdJ3UnyU+OOvhg3u8tuRDHHaSWZxWz6Mp9j3ANk2sMs0QIRu0KmvfmlvghIPzJqagZlLd70nW+uRPRDqQSKcSaROJvBlTvhoI=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: type; ValueData: $00000033; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0807; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0807; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: type; ValueData: $00000033; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: signature; ValueData: hJRbsx0Nspt20bP3fr44IFLPZSKReRXtF7lJMFuQlf+qS1DBde4hXBfvQWSvOszuPNgQV5VcWrcVEmFuNrAoFF2qvN4Ue09rTLIuKKiJwYvVsp1VNM2Xv6pxZtXQop3PtnSWALqJu0lbqyYDMEbRjorRwSiF4/iXEjUsOJhRIwE=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\Epass2003Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT2003; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

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
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_FT2003';
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
[_ISTool]
UseAbsolutePaths=false
