; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_HTSM2(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.8"
#define UID "EAB2175A-C7CE-4FFF-BF32-C56C7CDBAD64"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{EAB2175A-C7CE-4FFF-BF32-C56C7CDBAD64}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(HTSM2)
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


ShowLanguageDialog=auto
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoCompany=NETCA
VersionInfoProductVersion={#SETUP_FILE_VERSION}
CreateUninstallRegKey=true
UninstallLogMode=new

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_HTSM2
chinesesimp.SetupWindowTitle=网证通设备驱动_HTSM2

trad.SetupAppTitle=網證通設備驅動_HTSM2
trad.SetupWindowTitle=網證通設備驅動_HTSM2

eng.SetupAppTitle=NETCADevices_HTSM2
eng.SetupWindowTitle=NETCADevices_HTSM2

[Files]
;海泰驱动(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;公司动态设备DLL(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\HaitaiSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64

;海泰驱动（64位）
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GECN20524.dat; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GECSP20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GECSP20524.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GER20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\HTCSPApi20524.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\SKFAPI20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GEA20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GEC20524.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\GECFG20524.dat; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\SKFApi20524.lib; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;公司动态设备DLL(64位)
Source: ..\..\winX64\设备驱动\海泰SM2的Key\HaiTaiSM2Key.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰SM2的Key\HaiTaiSM2Key.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win64\HaitaiSM2Key.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;海泰驱动(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;公司动态设备DLL(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\HaitaiSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64



[Registry]
;HTSM2注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch


Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: cG8TDLCNtEJyuv2h3lJlOleQ2vcLgyGD8moHChiUVoxJjqtFbqqoqsgucRXh5YRs/VC+KKUcHjg98c/83J8NKOhwRzooltkkKu1sgYxQRTT5L1B+LtD9Hnl469rmngzeeKuIsSuubtswKmvmB8NOrnIfbZovcPIena4mgNLk1qE=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

[InstallDelete]
Name: {app}\Unins_HTSM2.dat; Type: files
Name: {app}\Unins_HTSM2.exe; Type: files
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
NewUninsName := 'Unins_HTSM2';
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
