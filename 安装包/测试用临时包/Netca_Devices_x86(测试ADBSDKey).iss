; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{5A68E393-0038-473C-A3C0-6ED50F775CAB}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

OutputBaseFilename=NETCA_Devices_x86(ADBSDKey)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(ADBSDKey)
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
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
chinesesimp.SetupAppTitle=网证通设备驱动
chinesesimp.SetupWindowTitle=网证通设备驱动

trad.SetupAppTitle=網證通設備驅動
trad.SetupWindowTitle=網證通設備驅動

eng.SetupAppTitle=NETCADevices
eng.SetupWindowTitle=NETCADevices
[Files]
DestDir: {app}; Source: ..\..\winX86\设备驱动\ADBSDKey\ADBSDKeyProvider.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\设备驱动\ADBSDKey\驱动\adb.exe; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\设备驱动\ADBSDKey\驱动\adbp11.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\设备驱动\ADBSDKey\驱动\AdbWinApi.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\winX86\设备驱动\ADBSDKey\驱动\AdbWinUsbApi.dll; Flags: uninsrestartdelete


[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: string; ValueName: signature; ValueData: oz0g2VLEseMv3e2YVeAg/0CN36x2XzFj7cyjOZvrhZtBue/zTnTQ/A5O1w6Gge0yLD7p+QU8YK94s0bdLLApmu/WW19KHukgRDxgUOKDz/pk1avjdT2HzL++8FSkjJT7m5puXoXDFInSIAERtKABOW0oak48ES72rm8V87JtMCQ=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: string; ValueName: class; ValueData: SDKey; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: dword; ValueName: type; ValueData: $00000026; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: multisz; ValueName: idstring; ValueData: Vid_12D1&Pid_1035; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyADB; ValueType: string; ValueName: dllpath; ValueData: {app}\ADBSDKeyProvider.dll; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
