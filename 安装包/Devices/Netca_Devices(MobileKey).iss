; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "移动电子密钥(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "3.0.0"
#define SETUP_FILE_VERSION "3.0.0.2"
#define UID "6F1F5761-D9FC-4A9B-96C3-09D93E020EEA"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{6F1F5761-D9FC-4A9B-96C3-09D93E020EEA}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPVERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net
DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=Copyright 2019 @ NETCA.保留所有权利。
OutputBaseFilename=NETCA_Devices(MobileKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

;不提示重启
UninstallRestartComputer =no
ShowLanguageDialog=auto
CreateUninstallRegKey=false
ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
UsePreviousAppDir=false
VersionInfoCompany={#NETCA}
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#DEVICES_APPVERSION}
UninstallLogMode=overwrite
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCopyright=Copyright 2019 @ NETCA.保留所有权利。
UninstallDisplayName={#DEVICES_APPNAME}
VersionInfoDescription={#DEVICES_APPNAME}驱动包
UpdateUninstallLogAppName=false
[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl
[Messages]
chinesesimp.SetupAppTitle=移动电子密钥
chinesesimp.SetupWindowTitle=移动电子密钥
trad.SetupAppTitle=移動電子密鑰
trad.SetupWindowTitle=移動電子密鑰
eng.SetupAppTitle=NETCADevices_MobileKey
eng.SetupWindowTitle=NETCADevices_MobileKey
[Files]
;32位系统文件
Source: ..\..\winX86\设备驱动\移动电子密钥\MobilekeyProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\MobilekeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeyproxy.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\winX86\设备驱动\移动电子密钥\paho-mqtt3a.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeywin.exe; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeywin.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeyconfigtool.exe; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\paho-mqtt3as.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64位系统文件
Source: ..\..\winX64\设备驱动\移动电子密钥\MobilekeyProv.dll; DestDir: {app}; Check: IsWin64; Flags: restartreplace uninsrestartdelete ignoreversion
Source: ..\..\winX64\设备驱动\移动电子密钥\netcamobilekeyproxy.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\移动电子密钥\MobilekeyProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位系统下32位文件
Source: ..\..\winX86\设备驱动\移动电子密钥\MobilekeyProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\MobilekeyProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeyproxy.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\winX86\设备驱动\移动电子密钥\paho-mqtt3a.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeywin.exe; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeywin.ini; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\netcamobilekeyconfigtool.exe; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\paho-mqtt3as.dll; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

Source: ..\..\..\..\统一介质管理工具\current\发布版\打包的插件\ISTask.dll; DestDir: {app}

;3.0.0新增文件
;32位系统文件

Source: ..\..\winX86\设备驱动\移动电子密钥\NetcaMobileKeyUI.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\NetcaMobileKey.exe; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\NetcaMobileKey.json; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;64位系统32位文件

Source: ..\..\winX86\设备驱动\移动电子密钥\NetcaMobileKeyUI.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\NetcaMobileKey.exe; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\设备驱动\移动电子密钥\NetcaMobileKey.json; DestDir: {pf32}\NETCA\NETCA_Devices\; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


;64位系统64位文件
Source: ..\..\winX64\设备驱动\移动电子密钥\NetcaMobileKeyUI.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64



[Registry]
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: type; ValueData: $0000003b; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: signature; ValueData: gxpAVaBItN6R/+/9zoz5pvkmAtBlbd5SlzltN/QUDl1Fu4B8w+rmhaV6fDJsF0ebHWKZjg2Lc8F0Rvi68i+OG1URYsecP2bDjNufam/7dYy4jgsFb3NqNpU/dAcu/yHKg+RuJZKrtPRAytiX4tRRbPheBtEA5iIeejRCF0dnkG0=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MobilekeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: multisz; ValueName: idstring; ValueData: vid_096F&pid_0002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetAllDevicesTimeOut; ValueData: $00000008; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadCertTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: SignTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DecryptTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetPwdRetryNumberTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: CreateDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: WriteDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DeleteDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetDataLengthTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: VerifyPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ChangePwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: UnlockUserPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64

;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: type; ValueData: $0000003b; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: signature; ValueData: adtCDTgkmeomJzrZQVJVm4a2sEYm2q76EEQch6wPTRg0VayA4wD7GgkhxxjA6kPtD13JSG4v1MwIVuDfe+AUb/FeVrK5ycaXjhOzz9n1PAbU7YAwNbLos1kfxwwVfY/owpWgFz49I4Paj2q+0zgsi3+4FxcMbH1Il1NSm6A2y1E=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\MobilekeyProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: multisz; ValueName: idstring; ValueData: vid_096F&pid_0002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetAllDevicesTimeOut; ValueData: $00000008; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadCertTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: SignTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DecryptTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetPwdRetryNumberTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: CreateDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: WriteDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DeleteDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetDataLengthTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: VerifyPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ChangePwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: UnlockUserPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: IsWin64

;32位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: type; ValueData: $0000003b; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: signature; ValueData: gxpAVaBItN6R/+/9zoz5pvkmAtBlbd5SlzltN/QUDl1Fu4B8w+rmhaV6fDJsF0ebHWKZjg2Lc8F0Rvi68i+OG1URYsecP2bDjNufam/7dYy4jgsFb3NqNpU/dAcu/yHKg+RuJZKrtPRAytiX4tRRbPheBtEA5iIeejRCF0dnkG0=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MobilekeyProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey; ValueType: multisz; ValueName: idstring; ValueData: vid_096F&pid_0002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetAllDevicesTimeOut; ValueData: $00000008; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadCertTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: SignTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DecryptTimeOut; ValueData: $0000003c; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetPwdRetryNumberTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: CreateDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ReadDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: WriteDataTimeOut; ValueData: $0000000a; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: DeleteDataTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: GetDataLengthTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: VerifyPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: ChangePwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMobileKey\TimeOutSec; ValueType: dword; ValueName: UnlockUserPwdTimeOut; ValueData: $00000004; Flags: uninsdeletekey; Check: not IsWin64

[InstallDelete]
Name: {app}\Unins_MobileKey.dat; Type: files
Name: {app}\Unins_MobileKey.exe; Type: files
[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804
trad.LanguageName=TradChinese
trad.LanguageID=$0404
eng.LanguageName=English
eng.LanguageID=$0409
[Code]
#include '..\..\..\..\统一介质管理工具\current\安装脚本\NETCA.iss'

function RunTask(FileName: string; bFullpath: Boolean): Boolean;
  external 'RunTask@files:ISTask.dll stdcall delayload';
function KillTask(ExeFileName: string): Integer;
  external 'KillTask@files:ISTask.dll stdcall delayload';

function InitializeSetup():boolean;
begin
	Result:=true;
	KillTask('netcamobilekeywin.exe');
end;

procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_MobileKey';

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
 RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
end;
end;

