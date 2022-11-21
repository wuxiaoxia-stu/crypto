; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_ESBluetoothKey"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.4"
#define UID  "0F343437-42E4-4042-A8A0-33DF29715903"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{0F343437-42E4-4042-A8A0-33DF29715903}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright={#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices(ESBluetoothKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}

ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;不提示重启
AlwaysRestart =no

;不在"添加/删除程序"面板中显示卸载
ShowLanguageDialog=auto
VersionInfoCompany=NETCA
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
VersionInfoProductVersion={#DEVICES_APPVERSION}
CreateUninstallRegKey=false
VersionInfoCopyright=C.{#NETCA}.保留所有权利。

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_ESBluetoothKey
chinesesimp.SetupWindowTitle=网证通设备驱动_ESBluetoothKey

[Files]
;32位系统文件
Source: ..\..\winX86\设备驱动\文鼎创蓝牙KEY\ESBluetoothKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\文鼎创蓝牙KEY\ESBluetoothKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x86\EsecuDrv04_NetCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x86\EsecuKey_KGM_API_NetCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x86\ESBluetoothKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64


;64位系统文件

Source: ..\..\winX86\设备驱动\文鼎创蓝牙KEY\ESBluetoothKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\文鼎创蓝牙KEY\ESBluetoothKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x86\EsecuDrv04_NetCA.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x86\EsecuKey_KGM_API_NetCA.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x86\ESBluetoothKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

Source: ..\..\winX64\设备驱动\文鼎创蓝牙KEY\ESBluetoothKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\文鼎创蓝牙KEY\ESBluetoothKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x64\EsecuDrv04_NetCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x64\EsecuKey_KGM_API_NetCA.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\深圳文鼎创\文鼎创蓝牙KEY\windows\x64\ESBluetoothKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;64位系统文件
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: multisz; ValueName: idstring; ValueData: vid_1EA8&Pid_C104; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: type; ValueData: $00000035; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: signature; ValueData: C8+7YVNN7LAZ4sFvBq44v4nI38LREuDEi6YOzU2JMBZuHib/ieFYtlzDlrWLUh52HAbcBcaVEeb7KnScmAB+wM3dbQz9YlTQ176U3UkpdenhCV60pVuPShTYRaBYvA0ETnSLO+2AbE9KtZej6DdwvRrcSr4wolhvUlFcZOFQ9wM=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\ESBluetoothKey.dll; Flags: uninsdeletekey; Check: IsWin64

Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: multisz; ValueName: idstring; ValueData: vid_1EA8&Pid_C104; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: type; ValueData: $00000035; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: signature; ValueData: aUCPN5VID1SOzHFVF0gH1ANNj2HAShA2LjvqX0ia4GQ4iqg6C+Lg5Zyb7BesJR8yeltMVp2J7EjINuFVv3CetIwBDaCVceOcS/PxfWXCxylbwFsVmwZvOLmFzICm9YxRv2BXZMx8f9fWgK0BUJ81sut5/33XLfJHwBDWDbcjnKc=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\ESBluetoothKey.dll; Flags: uninsdeletekey; Check: IsWin64


;32位系统文件
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: multisz; ValueName: idstring; ValueData: vid_1EA8&Pid_C104; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: dword; ValueName: type; ValueData: $00000035; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: signature; ValueData: C8+7YVNN7LAZ4sFvBq44v4nI38LREuDEi6YOzU2JMBZuHib/ieFYtlzDlrWLUh52HAbcBcaVEeb7KnScmAB+wM3dbQz9YlTQ176U3UkpdenhCV60pVuPShTYRaBYvA0ETnSLO+2AbE9KtZej6DdwvRrcSr4wolhvUlFcZOFQ9wM=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEsBLE; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\ESBluetoothKey.dll; Flags: uninsdeletekey; Check: not IsWin64

;


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
NewUninsName := 'Unins_ESBluetoothKey';
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
