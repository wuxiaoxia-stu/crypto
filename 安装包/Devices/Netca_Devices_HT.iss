; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_HT(32&64)"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.1"
#define SETUP_FILE_VERSION "1.1.0.14"
#define UID  "FAC4239C-91E5-468C-99E6-70A6C1EA580A"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{FAC4239C-91E5-468C-99E6-70A6C1EA580A}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(HT)
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

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
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
chinesesimp.SetupAppTitle=网证通设备驱动_HT
chinesesimp.SetupWindowTitle=网证通设备驱动_HT

trad.SetupAppTitle=網證通設備驅動_HT
trad.SetupWindowTitle=網證通設備驅動_HT

eng.SetupAppTitle=NETCADevices_HT
eng.SetupWindowTitle=NETCADevices_HT

[Files]
;海泰驱动(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GEC00001.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.ini; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.ini; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
;公司动态设备DLL（32位）
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTEKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64

;64位系统海泰驱动(64位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GEC00001.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64位系统公司动态设备DLL（64位）
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTEKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰\HTEKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰\HTEKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位系统海泰驱动(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {syswow64}\GECSP00001; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GEC00001.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.ini; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.dll; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.ini; DestDir: {syswow64}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64

;64位系统公司动态设备DLL（32位）
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTEKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64



[Registry]
;32位系统注册表
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HTEKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: RjkFvPzjzs9A2s+oYh3624nxNnhhaECseNQN42Wjd5YUqecZRHuwFynTimFIon8BcaRs/OOOcLfJPQ5yvhxHirK0UJ55FeS8UPUD9uBuVpID3frUpZpQB+mGavaF/QeGU/tIiKCcVC1eeeVg/X0oEf817+hx6oRNMRIh3yQiku8=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletekey
;64位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HTEKey.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: K8ZRpuV5u4nhBjhzsfRzsJNLoc/VCUjj5Dl2yqisr8cuGaw80+oKUiR+IdN4qq3CFkNGi7vUzKqWrynWiFHTKbMTLf4Cb3+BeDELVsmd+Pgp0EdOs/353fTK1u3e7FuscdFLNQd2+FaDU7Bz+soKm5TAEkH4WMfFuCqTZ9lz0Hk=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HTEKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: RjkFvPzjzs9A2s+oYh3624nxNnhhaECseNQN42Wjd5YUqecZRHuwFynTimFIon8BcaRs/OOOcLfJPQ5yvhxHirK0UJ55FeS8UPUD9uBuVpID3frUpZpQB+mGavaF/QeGU/tIiKCcVC1eeeVg/X0oEf817+hx6oRNMRIh3yQiku8=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey




[InstallDelete]
Name: {app}\Unins_HT.dat; Type: files
Name: {app}\Unins_HT.exe; Type: files
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins003.dat; Type: files
Name: {app}\unins003.exe; Type: files


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
NewUninsName := 'Unins_HT';
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
