; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_MWV2V3"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.1.0.6"
#define UID  "96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{96AD65F7-E1BA-4E01-ABA0-146D3B45CFCF}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}。保留所有权利。
OutputBaseFilename=NETCA_Devices(MWV2V3)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_MW23
chinesesimp.SetupWindowTitle=网证通设备驱动_MW23

trad.SetupAppTitle=網證通設備驅動_MW23
trad.SetupWindowTitle=網證通設備驅動_MW23

eng.SetupAppTitle=NETCADevices_MW23
eng.SetupWindowTitle=NETCADevices_MW23

[Files]
;USBKey驱动明华
;Source: ..\..\..\..\证书介质\驱动及开发包\明华\NETCAKEY_MWV2V3.exe; DestDir: {app}; Flags: deleteafterinstall uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\明华\MWTokenAPI.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64

;公司动态设备DLL
Source: ..\..\..\..\证书介质\驱动及开发包\明华\MWTokenAPI.dll; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\明华\NETCA_V2V3_02320.exe; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: not IsWin64
Source: ..\..\winX64\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX64\设备驱动\明华2版\MWEKeyV2Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX64\设备驱动\明华2版\MWEKeyV2Prov.sig; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64

[Registry]
;明华3版

;明华2版
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: $00000006; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: QDy/OmyWW3qxbRINsA1N9EMi+R3lXHGvZHUYPbyCetc/9lyhA86Pc2SwxyfeLli+gtPc0N7W5cWn8K58KCsf5pao1Xm7zsLgQ5IGutxDT6IVvAlrruDGdYSjlncR2URE5n40cgN/I4VC5bK3v0SoGAwq0Ip/T+LJBez0hsFOxWc=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: $00000006; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64

[Run]
Filename: {pf}\NETCA\NETCA_Devices\NETCA_V2V3_02320.exe; WorkingDir: {pf}\NETCA\NETCA_Devices\; Flags: runminimized runhidden; Parameters: /SP- /VERYSILENT /NORESTART

[UninstallRun]
Filename: {pf32}\NETCA\NETCAKEY_MWHS\unins000.exe; WorkingDir: {pf32}\NETCA\NETCAKEY_MWHS; Check: IsWin64; Parameters: /SP- /VERYSILENT /NORESTART
Filename: {pf}\NETCA\NETCAKEY_MWHS\unins000.exe; WorkingDir: {pf}\NETCA\NETCAKEY_MWHS; Check: not IsWin64; Parameters: /SP- /VERYSILENT /NORESTART

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
NewUninsName := 'Unins_MWV2V3';

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

