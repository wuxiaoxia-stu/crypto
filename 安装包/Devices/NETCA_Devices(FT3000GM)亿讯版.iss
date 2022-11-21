; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_FT3000GM(32&64)"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.1"
#define UID  "FE9FDA9D-D4AA-48AE-8772-04AC1EE8EE9C"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{FE9FDA9D-D4AA-48AE-8772-04AC1EE8EE9C}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(FT3000GM)亿讯版
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}亿讯版
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

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_FT3000GM
chinesesimp.SetupWindowTitle=网证通设备驱动_FT3000GM

trad.SetupAppTitle=網證通設備驅動_FT3000GM
trad.SetupWindowTitle=網證通設備驅動_FT3000GM

eng.SetupAppTitle=NETCADevices_FT3000GM
eng.SetupWindowTitle=NETCADevices_FT3000GM

[Files]
;设备dll(32位系统32位文件)
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;设备dll(64位系统64位文件)
Source: ..\..\winX64\设备驱动\飞天SM2的COS\FT3000GMProv.dll; DestDir: {app}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天SM2的COS\FT3000GMProv.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64

;设备dll(64位系统的32位文件)
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;驱动检测文件(32位系统32位文件和64位系统的64位文件)
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll_driver.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion
;64位系统的32位文件
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

[Registry]
;系统注册表(32位系统32位文件)
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {app}\FT3000GMProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: P9SsZdoEn0hfyCtvLJGtWjoWLtV2TR9iwRkE/JMPcBe8o27Q1AawCXkb1Oqlf6FjnpBNpMdK9z4qno26nQDODG3F0WdVsWMs0v91Iv0/jvC2oQ1NSeyHGqOqXpvj8FywV/iRTRFSKmWxpg4OdnAAj933Qs+nRxXhHmeaNdJdWC0=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314{break}Vid_096E&Pid_0316; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
;系统驱动文件(32位系统32位文件和64位系统的64位注册表)
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey
;系统驱动文件(64位系统的32位注册表)
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Check: IsWin64; Flags: uninsdeletekey
;64位系统注册表64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {app}\FT3000GMProv.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: M5gfLyqsGeKUIN4Jgv89Q84v4elihKWEwsCKxf1Ci9Yw6odc/NEEV8sBwwsL95YRobDL60i4rzY8Akacu5xH5DQdszUBMLqkNg3vLRQwE6cqcln4dTprVcQ58wrQQhKCnZFY8yQHxK+k17oWbRGStCEwitowWQ9PPMuKKvTs/lk=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314{break}Vid_096E&Pid_0316; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: P9SsZdoEn0hfyCtvLJGtWjoWLtV2TR9iwRkE/JMPcBe8o27Q1AawCXkb1Oqlf6FjnpBNpMdK9z4qno26nQDODG3F0WdVsWMs0v91Iv0/jvC2oQ1NSeyHGqOqXpvj8FywV/iRTRFSKmWxpg4OdnAAj933Qs+nRxXhHmeaNdJdWC0=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314{break}Vid_096E&Pid_0316; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
;32位系统的32位文件，64位系统64位文件
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey
;64位系统的32位文件
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
[InstallDelete]
Name: {app}\Unins_FT3000GM.dat; Type: files
Name: {app}\Unins_FT3000GM.exe; Type: files
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
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_FT3000GM';
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
