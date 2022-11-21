; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_ZDScard(32位)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.6"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{C3D345F0-16A7-4FE1-88AB-8FE21568B47A}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(ZDScard)
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
chinesesimp.SetupAppTitle=网证通设备驱动_ZDScard
chinesesimp.SetupWindowTitle=网证通设备驱动_ZDScard

trad.SetupAppTitle=網證通設備驅動_ZDScard
trad.SetupWindowTitle=網證通設備驅動_ZDScard

eng.SetupAppTitle=NETCADevices_ZDScard
eng.SetupWindowTitle=NETCADevices_ZDScard
[Files]
;ZDScard驱动（32位）无

;公司动态设备DLL(32位)
Source: ..\..\winX86\设备驱动\暨大校园卡\ZDScardProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\暨大校园卡\ZDScardProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX86\设备驱动\暨大校园卡\ZDScardProv.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion

[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyZDScard; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyZDScard; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\ZDScardProv.dll; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyZDScard; ValueType: string; ValueName: signature; ValueData: albpUJc82iV+kxSIFYiwX0oVJ4qceHndPylK2d5+B91ZDZ60RWuoAQ3UC8ZwEsq5jfZzDmJpyaDT3kFR8QylbynW//NiFTYRfxPK/5qGDNoiCmt22dSc2husbDAgt9rqHsGS3KWbz1pJm50KMfrmzZZvg55V7Pa7zhIMqWB+eKM=; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyZDScard; ValueType: string; ValueName: class; ValueData: PC/SC; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyZDScard; ValueType: dword; ValueName: type; ValueData: $0000002c; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyZDScard; ValueType: multisz; ValueName: idstring; ValueData: ACS ACR1281 1S Dual Reader PICC 0; Flags: uninsdeletevalue



[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
[Code]


procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName, MyAppName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_ZDScard';
// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
MyAppName := 'C3D345F0-16A7-4FE1-88AB-8FE21568B47A';
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
