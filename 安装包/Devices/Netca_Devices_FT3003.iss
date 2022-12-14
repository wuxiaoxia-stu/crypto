; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_FT3003(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define APPVERSION "1.1.0"
#define SETUP_FILE_VERSION "1.1.0.27"
#define UID  "99DF1990-C302-4DA3-BCEE-AE6F7721E635"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{99DF1990-C302-4DA3-BCEE-AE6F7721E635}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(FT3003)
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
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#APPVERSION}
UninstallLogMode=overwrite
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCopyright=(C) {#NETCA}。保留所有权利。
CreateUninstallRegKey=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_FT3003
chinesesimp.SetupWindowTitle=网证通设备驱动_FT3003

trad.SetupAppTitle=網證通設備驅動_FT3003
trad.SetupWindowTitle=網證通設備驅動_FT3003

eng.SetupAppTitle=NETCADevices_FT3003
eng.SetupWindowTitle=NETCADevices_FT3003
[Files]
;飞天3003驱动（32位）
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003.DLL; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003.sig; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003_s.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003_vip.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;公司动态设备DLL(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\飞天3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64

;64位系统下飞天3003驱动（64位）
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\WZTCsp11_3003.DLL; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\WZTCsp11_3003.sig; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\WZTCsp11_3003_s.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64位系统公司动态设备DLL(64位)
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位系统下飞天3003驱动（32位）
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003.DLL; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003.sig; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003_s.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003_vip.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64位系统公司动态设备DLL(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\Epass3003Prov.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\飞天3003\Epass3003Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
;飞天3003语言包
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\lang\escertd_wzt_1033.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\lang\escertd_wzt_2052.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\lang\escsp_wzt_1033.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\lang\escsp_wzt_2052.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\lang\esmgr_wzt_1033.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\lang\esmgr_wzt_2052.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
; 32位广西CA3003
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\广西CA3003\32位\wztCsp11_3003_GX.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\广西CA3003\32位\wztCsp11_3003_GX.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64位广西CA3003
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\广西CA3003\64位\wztCsp11_3003_GX.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32位系统注册表
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: pkcs11library; ValueData: wztCsp11_3003.dll{break}wztCsp11_3003_GX.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: banSEbEuMG8DfzI/77Qs0cnqWTXkY8WRVEYMImNaZPHpu3CRNBwcx/oJMXMR6LWej9L5XGYsaxsf3eI/QspcjMZItjzBfE1ANf30bkfI7uY4Lyjc77cOxViWOgC+zKBUzInonehcY53rCkRmXEgHE6j+J6psUPfiizV+1RUjZ4w=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64
;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: pkcs11library; ValueData: wztCsp11_3003.dll{break}wztCsp11_3003_GX.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: XnYrq7BT4w/rcITC1g4PUzzlOqJHBnOF7fiMmYw2WxsSBGQzXyKoEm3+WOhprvTx+YHH2S8INrBgmBR1EeZ0bzGL/OuHFA2acSh3WMhnJzguyUbhW1Be0iUjKfNg3GXKIOFtU2F1GrmBuNh03gtIptp8rYjy7qp3i96NdXMIMRw=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: banSEbEuMG8DfzI/77Qs0cnqWTXkY8WRVEYMImNaZPHpu3CRNBwcx/oJMXMR6LWej9L5XGYsaxsf3eI/QspcjMZItjzBfE1ANf30bkfI7uY4Lyjc77cOxViWOgC+zKBUzInonehcY53rCkRmXEgHE6j+J6psUPfiizV+1RUjZ4w=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: pkcs11library; ValueData: wztCsp11_3003.dll{break}wztCsp11_3003_GX.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;32位系统
Root: HKLM; SubKey: SOFTWARE\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Path; ValueData: {pf}\NETCA\NETCA_Devices\; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: LanguageId; ValueData: 2052; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Version; ValueData: 10130204; Flags: uninsdeletevalue
;64位系统
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Path; ValueData: {pf}\NETCA\NETCA_Devices\; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: LanguageId; ValueData: 2052; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Version; ValueData: 10130204; Flags: uninsdeletevalue; Check: IsWin64



[InstallDelete]
Name: {app}\Unins_FT3003.dat; Type: files
Name: {app}\Unins_FT3003.exe; Type: files
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
NewUninsName := 'Unins_FT3003';
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
