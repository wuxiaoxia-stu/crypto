; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "NETCA_Devices_x86(MWV2V3)_YAOJIAO"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "2.1"
#define SETUP_FILE_VERSION "2.1.0.1"
#define UID  "D0CC3586-2289-49da-9E56-6EEC8255CEC0"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{D0CC3586-2289-49da-9E56-6EEC8255CEC0}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=(C){#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86(MWV2V3)_YAOJIAO
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(32位)
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
UninstallLogMode=new


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=NETCA_Devices_x86(MWV2V3)_YAOJIAO
chinesesimp.SetupWindowTitle=NETCA_Devices_x86(MWV2V3)_YAOJIAO

trad.SetupAppTitle=網證通設備驅動_MW23_YAOJIAO
trad.SetupWindowTitle=網證通設備驅動_MW23_YAOJIAO

eng.SetupAppTitle=NETCADevices_MW23_YAOJIAO
eng.SetupWindowTitle=NETCADevices_MW23_YAOJIAO

[Files]

;USBKey驱动明华
Source: ..\..\..\..\证书介质\驱动及开发包\明华\MWTokenAPI.dll; DestDir: {sys}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: not IsWin64

Source: ..\..\..\..\证书介质\驱动及开发包\明华\MWTokenAPI.dll; DestDir: {syswow64}; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\明华\NETCAKEY_MWV2V3.exe; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\..\..\证书介质\驱动及开发包\明华\MWEKeyV2Prov.dll_driver.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\..\..\证书介质\驱动及开发包\明华\MWEKeyV3Prov.dll_driver.ini; DestDir: {app}; Flags: uninsrestartdelete ignoreversion restartreplace

[Registry]
;32位系统注册表 明华二版:
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: JZFdguLYeb9pNNblhflgEw9P54im/RvtTDL11OXj5ZXtZkir8samEtd5FyuZ+86o/gR5I6QwO6fJyRk3QU49Nc0CrHvrnegYSQmj1F2osnXJ4GYtNkglq1RG/pMKQYFYnbzgdBxiqkUwFZXEw/VwR6oNTtrEYJYZKxxtS3NtFws=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
;32位系统注册表 明华三版:
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: $00000006; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
;64位系统注册表 明华二版:
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: JZFdguLYeb9pNNblhflgEw9P54im/RvtTDL11OXj5ZXtZkir8samEtd5FyuZ+86o/gR5I6QwO6fJyRk3QU49Nc0CrHvrnegYSQmj1F2osnXJ4GYtNkglq1RG/pMKQYFYnbzgdBxiqkUwFZXEw/VwR6oNTtrEYJYZKxxtS3NtFws=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
;64位系统注册表 明华三版:
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: $00000006; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

[Run]
Filename: {app}\NETCAKEY_MWV2V3.exe; Parameters: /SP- /VERYSILENT /NORESTART /SUPPRESSMSGBOXES; WorkingDir: {sys}; Flags: runhidden runminimized

[InstallDelete]
Name: {pf}\NETCA\NETCAKEY_MWHS\unins000.exe; Type: filesandordirs
Name: {pf}\NETCA\NETCAKEY_MWHS\unins000.dat; Type: filesandordirs

[UninstallRun]
Filename: {pf32}\NETCA\NETCAKEY_MWHS\unins000.exe; WorkingDir: {pf32}\NETCA\NETCAKEY_MWHS; Parameters: /SP- /VERYSILENT /NORESTART

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

function IsWin64: Boolean;
begin
  Result :=IsX64 or IsIA64;
end;


procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_MWV2V3_YAOJIAO';

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


function InitializeSetup(): boolean;
begin

            if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1') then
            RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1');

            if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1') then
            RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}_is1');
result:= true;
end;
