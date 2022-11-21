; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_AratekFP"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.2.0"
#define SETUP_FILE_VERSION "1.2.0.1"
#define UID  "5C34EE4C-059B-4E03-A344-7021D7753010"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{5C34EE4C-059B-4E03-A344-7021D7753010}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=(C) {#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(AratekFP)
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
;ArchitecturesInstallIn64BitMode=x64 ia64
VersionInfoTextVersion={#DEVICES_APPVERSION}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_AratekFP
chinesesimp.SetupWindowTitle=网证通设备驱动_AratekFP

[Files]
Source: Y:\svn\NETCA_CRYPTO\current\winX86\设备驱动\亚略特指纹USBKey\AratekFPKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\NETCA_CRYPTO\current\winX86\设备驱动\亚略特指纹USBKey\AratekFPKeyProv.dll_device.ini; DestDir: {app}; Flags: ignoreversion
Source: Y:\svn\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\ASCryptoki.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\ASFKeyAPI.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\FDcgi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\TokenASApi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete
Source: Y:\svn\NETCA_CRYPTO\current\winX86\设备驱动\亚略特指纹USBKey\AratekFPKeyProv.dll_driver.ini; DestDir: {app}; Flags: ignoreversion

[Registry]
;32位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: dllpath; ValueData: {app}\AratekFPKeyProv.dll; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: signature; ValueData: i2YUF2cht86gXQkDiWhD5qhr6OTQw9Hj0kDnoqM4HjqeR51j71ejuYfewZlp5kR1TrBPXgsrGNUqjK6D2EstC0+NnhBqsm862YCudnvoeeo/j4ON9yZL6FZUPMmzXdCNuevXLGNc5QTWfbkQFSsjFJLjWYyOkrf3BzZoQ00X2FM=; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: type; ValueData: $0000002a; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_2010&Pid_1200; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletevalue


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
NewUninsName := 'Unins_AratekFP';
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
