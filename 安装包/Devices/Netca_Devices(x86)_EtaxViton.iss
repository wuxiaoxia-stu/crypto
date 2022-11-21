; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_EtaxViton(32位)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.2"
#define UID "5CC70FA3-CE40-4C74-A5DF-9AE46A9C6217"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{5CC70FA3-CE40-4C74-A5DF-9AE46A9C6217}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(EtaxViton)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
ShowLanguageDialog=auto
CreateUninstallRegKey=true

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_EtaxViton
chinesesimp.SetupWindowTitle=网证通设备驱动_EtaxViton

trad.SetupAppTitle=網證通設備驅動_EtaxViton
trad.SetupWindowTitle=網證通設備驅動_EtaxViton

eng.SetupAppTitle=NETCADevices_EtaxViton
eng.SetupWindowTitle=NETCADevices_EtaxViton
[Files]
Source: ..\..\winX86\设备驱动\天翼税通网讯COS\E1990\EtaxVitonProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\天翼税通网讯COS\E1990\EtaxVitonProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\天翼税通网讯COS\E1990\WZTTrans.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\天翼税通网讯COS\E1990\EtaxVitonProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion

[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\EtaxVitonProv.dll; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: string; ValueName: signature; ValueData: GArlZhchJdr46i6b5bbcE+NNTUsWw/20UPbMlP3LCEJ9ClNMrCp2Y112LPpx2lMKm7ClPWL81jvTPB6jSG0RZgRgsi8uELlt27URwCRu2EXdNNFV3bEe62jsAURDi4pF1iQBvR6xkVWUie31NhWfOKSHx2of+N+41JuDSqvrDiQ=; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: dword; ValueName: type; ValueData: $00000027; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: multisz; ValueName: idstring; ValueData: Vid_1E89&Pid_1990{break}Vid_F02E&Pid_0101{break}Vid_F02E&Pid_0201; Flags: uninsdeletevalue

[InstallDelete]
Name: {app}\Unins_EtaxViton.dat; Type: files
Name: {app}\Unins_EtaxViton.exe; Type: files

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
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_EtaxViton';

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
end  else  if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
begin
  //MsgBox('检测到系统需要改', mbInformation, MB_OK);
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
  //MsgBox('检测到系统改完', mbInformation, MB_OK);
end;
end;
end;
