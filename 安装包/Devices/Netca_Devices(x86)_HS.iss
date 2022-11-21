; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_HS(32位)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.2"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{B4D08D47-C8AE-4C96-ACBC-0483071A9C5E}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(HS)
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


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_华申
chinesesimp.SetupWindowTitle=网证通设备驱动_华申

trad.SetupAppTitle=網證通設備驅動_HS
trad.SetupWindowTitle=網證通設備驅動_HS

eng.SetupAppTitle=NETCADevices_HS
eng.SetupWindowTitle=NETCADevices_HS
[Files]

;公司动态设备DLL(32位)
Source: ..\..\winX86\设备驱动\华申\HSuKeyCI800Prov.dll; DestDir: {app}; Flags: restartreplace ignoreversion uninsrestartdelete
Source: ..\..\winX86\设备驱动\华申\HSuKeyCI800Prov.dll_device.ini; DestDir: {app}; Flags: restartreplace ignoreversion uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华申\HDPKCS11\x86\HSuKeyCI800Prov.dll_driver.ini; DestDir: {app}; Flags: restartreplace ignoreversion uninsrestartdelete
;介质驱动文件(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\华申\HDPKCS11\x86\HD_hdcos480.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\华申\HDPKCS11\x86\HDIFD20B.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\华申\HDPKCS11\x86\hdpkcs11_jit.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
;CCID驱动
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x86\cidcusb.cat; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x86\CIDCUSB.inf; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x86\CIDCUSB.sys; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x86\dpinstx86.exe; DestDir: {sys}\HS; Check: IsOtherArch; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x64\cidcusb.cat; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x64\CIDCUSB.inf; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x64\CIDCUSB.sys; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit
Source: ..\..\..\..\证书介质\驱动及开发包\华申\驱动程序\x64\dpinstx64.exe; DestDir: {sys}\HS; Check: IsWin64; Flags: uninsrestartdelete 64bit

[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: string; ValueName: dllpath; ValueData: {app}\HSuKeyCI800Prov.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: string; ValueName: signature; ValueData: mCqKZklMtgFzbNbWjgSpTwiOG1TjGh7lOQ/rgE/s+16XmsqTv7Tyii65S1ltPV556d7COSR6nxDOeTZbfDX4jGHfAe9QBjSG4/VBHNJis0MONwrp2whq3zU7C1FiZMj1yX40ngDoHjFChMLq30R5YkOVuXvnX1RZSQUQG3jVNnw=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: dword; ValueName: type; ValueData: $0000002e; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHS800; ValueType: multisz; ValueName: idstring; ValueData: Vid_1677&Pid_0101; Flags: uninsdeletekey

[Run]
Filename: {sys}\HS\dpinstx86.exe; Parameters: /s /F /sa; Flags: runminimized runhidden; Check: IsOtherArch; WorkingDir: {sys}
Filename: {sys}\HS\dpinstx64.exe; Flags: runminimized runhidden 64bit; Parameters: /s /F /sa; WorkingDir: {sys}; Check: not IsOtherArch

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
NewUninsName := 'Unins_HS';
// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
MyAppName := 'B4D08D47-C8AE-4C96-ACBC-0483071A9C5E';
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
