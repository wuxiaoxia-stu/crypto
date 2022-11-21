; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_龙脉TF(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.1"
#define UID  "6972F5AA-1DA3-49D3-84FF-9E6F88D77B77"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{6972F5AA-1DA3-49D3-84FF-9E6F88D77B77}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(LMaiTF)
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
chinesesimp.SetupAppTitle=网证通设备驱动_龙脉TF
chinesesimp.SetupWindowTitle=网证通设备驱动_龙脉TF

trad.SetupAppTitle=網證通設備驅動_龍脈TF
trad.SetupWindowTitle=網證通設備驅動_龍脈TF

eng.SetupAppTitle=NETCADevices_LMaiTF
eng.SetupWindowTitle=NETCADevices_LMaiTF

[Files]
;32位系统设备驱动
Source: ..\..\winX86\设备驱动\龙脉GM3000\TF卡\LMaiTFKey.dll; DestDir: {app}; Check: not IsWin64
Source: ..\..\winX86\设备驱动\龙脉GM3000\TF卡\LMaiTFKey.dll_device.ini; DestDir: {app}; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\sd卡\windows\win32\LMaiTFKey.dll_driver.ini; DestDir: {app}; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\sd卡\windows\win32\mtoken_tf.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion; Check: not IsWin64
;64位系统设备驱动
Source: ..\..\winX64\设备驱动\龙脉GM3000\TF卡\LMaiTFKey.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\龙脉GM3000\TF卡\LMaiTFKey.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\sd卡\windows\x64\LMaiTFKey.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\sd卡\windows\x64\mtoken_tf.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64位系统32位驱动
Source: ..\..\winX86\设备驱动\龙脉GM3000\TF卡\LMaiTFKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\龙脉GM3000\TF卡\LMaiTFKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\sd卡\windows\win32\LMaiTFKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\..\..\证书介质\驱动及开发包\龙脉科技\sd卡\windows\win32\mtoken_tf.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64

[Registry]
;32位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: type; ValueData: $00000038; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: signature; ValueData: K9OJyUZwnjHbbiv6IpjWQm+Qm3GjEhd1fyfh2HhfUTXLgiz0e6F70fYu7FkiKulZtTCzDj660gAH1VoCjOAR4aq0OjlRy8Uhakbk85VKUQ9ZBz/cX8C1WZlVl8de5+0POZliIvLXrCWWx8aj/0g80UzDU6Xz2d+MlCrp8iVgIZI=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: dllpath; ValueData: {app}\LMaiTFKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: type; ValueData: $00000038; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: signature; ValueData: K9OJyUZwnjHbbiv6IpjWQm+Qm3GjEhd1fyfh2HhfUTXLgiz0e6F70fYu7FkiKulZtTCzDj660gAH1VoCjOAR4aq0OjlRy8Uhakbk85VKUQ9ZBz/cX8C1WZlVl8de5+0POZliIvLXrCWWx8aj/0g80UzDU6Xz2d+MlCrp8iVgIZI=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\LMaiTFKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: dword; ValueName: type; ValueData: $00000038; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: signature; ValueData: JzxLwnOaycybg8ZZThj2ZYDj/dykBcaTx+8bCU8mrCCpVvhXXwzaEzS+HuRUl2hf2HJkcN1WliLsYv+DeOLzuGNPhlJpsy1Ux6tOu3Ex/Am++XkcEAnAg5qZCw+HidairNRQaWU4ryXu3MnqgChqz94DKxodpDZhY5i1hI0KyJ8=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: dllpath; ValueData: {app}\LMaiTFKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyLMTF; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64

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
Name: {app}\Unins_LMTF.exe; Type: files
Name: {app}\Unins_LMTF.dat; Type: files

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
NewUninsName := 'Unins_LMTF';
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
