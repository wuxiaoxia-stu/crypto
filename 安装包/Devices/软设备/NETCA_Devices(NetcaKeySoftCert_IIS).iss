; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_NetcaKeySoftCert_IIS"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.6"
#define UID  "B3510793-DD3F-44DE-880D-DDC5EE567CD6"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{B3510793-DD3F-44DE-880D-DDC5EE567CD6}
;应用程序信息
AppName={#DEVICES_APPNAME}
AppVerName={#DEVICES_APPNAME}
AppCopyright={#NETCA}。保留所有权利。
UninstallRestartComputer =no
ShowLanguageDialog=auto
UninstallLogMode=overwrite
UninstallDisplayName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

;应用程序目录
DefaultDirName={pf}\NETCA\NETCA_Devices

;编译输出  压缩
OutputBaseFilename=NETCA_Devices(NetcaKeySoftCert_IIS)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;版本信息
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCompany={#NETCA}
VersionInfoDescription={#DEVICES_APPNAME}驱动
VersionInfoCopyright=(C) {#NETCA}。保留所有权利。
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#DEVICES_APPVERSION}
CreateUninstallRegKey=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_NetcaKeySoftCert_IIS
chinesesimp.SetupWindowTitle=网证通设备驱动_NetcaKeySoftCert_IIS

trad.SetupAppTitle=網證通設備驅動_NetcaKeySoftCert_IIS
trad.SetupWindowTitle=網證通設備驅動_NetcaKeySoftCert_IIS

eng.SetupAppTitle=NETCADevices_NetcaKeySoftCert_IIS
eng.SetupWindowTitle=NETCADevices_NetcaKeySoftCert_IIS

[Files]

;设备dll(32位系统32位文件)
Source: ..\..\..\winX86\设备驱动\软证书\NetcaSoftKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\winX86\设备驱动\软证书\NetcaSoftKeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;设备dll(64位系统的32位文件)
Source: ..\..\..\winX86\设备驱动\软证书\NetcaSoftKeyProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX86\设备驱动\软证书\NetcaSoftKeyProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;设备dll(64位系统的64位文件)
Source: ..\..\..\winX64\设备驱动\软证书\NetcaSoftKeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\winX64\设备驱动\软证书\NetcaSoftKeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32位注册表32位系统-NetcaSoftKeyProv_32.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64

Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64

;32位注册表64位系统-NetcaSoftKeyProv_64.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

;32位注册表32位系统-NetcaSoftKeyProv_IIS_32.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: CertificateFilePath; ValueData: D:\NetcaSoftKey\; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64

;32位注册表64位系统-NetcaSoftKeyProv_IIS_64.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\NetcaSoftKeyProv.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: NiIVp9M/xNlquRyhe/cs5hCVhu89TDdsYn6TxMn625JgJu+GmwKWL2zzrTGWY6Oc0Ocr15etc5pp48oPQ2zLASPNzgb2pxRNtP/uUbEsaNZiKSAB95+aY72OUwVWEmTUrrivcBg02kaYgpHHnHUnxlzzq0Ew1dOheFGlvgADb5w=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: CertificateFilePath; ValueData: D:\NetcaSoftKey\; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64


;64位注册表64位系统-NetcaSoftKeyProv.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: Ma0HA3mrjU/WGVLKUph4MhzcqF0OuQRZUqaTzzGZuFPJLXfdKS2/P0AQSqciUOS6EcknLoswolO3iPpqxR/s2C679/URrelrPLlf/SFc/Nwohc1fm6Bof9XGBkMk2qRP72mb1ksYdxjYzHmgy6wn/WfswXg0nzHgLDG5lY8QuQs=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64

;64位注册表64位系统-NetcaSoftKeyProv_IIS.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: dllpath; ValueData: {app}\NetcaSoftKeyProv.dll; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: signature; ValueData: Ma0HA3mrjU/WGVLKUph4MhzcqF0OuQRZUqaTzzGZuFPJLXfdKS2/P0AQSqciUOS6EcknLoswolO3iPpqxR/s2C679/URrelrPLlf/SFc/Nwohc1fm6Bof9XGBkMk2qRP72mb1ksYdxjYzHmgy6wn/WfswXg0nzHgLDG5lY8QuQs=; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: class; ValueData: Software; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: type; ValueData: $00000034; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: string; ValueName: CertificateFilePath; ValueData: D:\NetcaSoftKey\; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NetcaKeySoftCert; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64



[InstallDelete]
Name: {app}\Unins_NetcaKeySoftCert.dat; Type: files
Name: {app}\Unins_NetcaKeySoftCert.exe; Type: files
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409

[_ISTool]
UseAbsolutePaths=false
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
NewUninsName := 'Unins_NetcaKeySoftCert';
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
