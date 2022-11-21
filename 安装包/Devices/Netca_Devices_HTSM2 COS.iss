; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动_海泰SM2 COS(32&64)"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "2.0.0"
#define SETUP_FILE_VERSION "2.0.0.34"
#define UID  "1394738E-C44C-4FB2-AEB5-5407C998792A"
[Setup]
;应用程序信息
AppName={#DEVICES_APPNAME}
AppVerName={#DEVICES_APPNAME}
AppCopyright={#NETCA}。保留所有权利。
;控制面板及卸载信息，不提示重启
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
; 不要为其他安装程序使用相同的AppId值。
AppId={{1394738E-C44C-4FB2-AEB5-5407C998792A}
UninstallRestartComputer =no
ShowLanguageDialog=auto
UninstallLogMode=overwrite
UninstallDisplayName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

;应用程序目录
DefaultDirName={pf}\NETCA\NETCA_Devices

;编译输出  压缩
OutputBaseFilename=NETCA_Devices(HTSM2COS)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;版本信息
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCompany={#NETCA}
VersionInfoDescription={#DEVICES_APPNAME}驱动
VersionInfoCopyright=(C) {#NETCA}。保留所有权利。
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#DEVICES_APPVERSION}
CreateUninstallRegKey=false



[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备驱动_海泰SM2 COS(32&64)
chinesesimp.SetupWindowTitle=网证通设备驱动_海泰SM2 COS(32&64)

trad.SetupAppTitle=網證通設備驅動_海泰SM2 COS(32&64)
trad.SetupWindowTitle=網證通設備驅動_海泰SM2 COS(32&64)

eng.SetupAppTitle=NETCADevices_海泰SM2 COS(32&64)
eng.SetupWindowTitle=NETCADevices_海泰SM2 COS(32&64)
[Files]
;32位系统动态设备DLL
Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll; DestDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
;Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
;64位系统32位文件设备DLL

Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
;Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace

;64位系统动态设备DLL
Source: ..\..\winX64\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰SM2的Key\海泰SM2 COS\HaiTaiSM2Key.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace; Check: IsWin64
;Source: ..\..\winX86\设备驱动\海泰SM2的Key\海泰SM2 COS\HaitaiSM2Key.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace

;Source: ..\..\..\..\证书介质\驱动及开发包\海泰\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; DestDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
;Source: ..\..\..\..\证书介质\驱动及开发包\海泰\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; DestDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64; Flags: uninsrestartdelete ignoreversion restartreplace
;32位厂家驱动文件
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GEC00001.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;32位厂家驱动文件
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GEC00001.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.ini; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64位厂家驱动
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0404.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0409.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0804.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GEControl.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GEC00001.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.ini; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;pkcs11_Win32
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\pkcs11_Win32\HkCommand.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\pkcs11_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\pkcs11_Win32\HkCommand.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\pkcs11_Win32\HtPkcs11.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64




[Registry]
;新32位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: kEdTpIEEGsgpabCr8GWgQFtJG+tCew0ofBJux+tNuS1mqeZT6Hb6f805pJjWxpUVu1QgsZO3LfECPqh5nXs5WykYcT1JdYY2h/8iUg9CAorp5pBFuxGo8rMdCzKPfMtHBKyOXUhYCkbMKiBZTzjyUVdOTl56eQwev6glydHgPWw=; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0103{break}vid_5448&pid_0004{break}vid_5448&pid_0203; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaiTaiSM2Key.dll; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletevalue; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletevalue; Check: not IsWin64
;64位系统32位注册表

;新64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: kEdTpIEEGsgpabCr8GWgQFtJG+tCew0ofBJux+tNuS1mqeZT6Hb6f805pJjWxpUVu1QgsZO3LfECPqh5nXs5WykYcT1JdYY2h/8iUg9CAorp5pBFuxGo8rMdCzKPfMtHBKyOXUhYCkbMKiBZTzjyUVdOTl56eQwev6glydHgPWw=; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0103{break}vid_5448&pid_0004{break}vid_5448&pid_0203; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaiTaiSM2Key.dll; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletevalue; Check: IsWin64

;新64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: HzaGX2dneLFiq+lUZxtKVp2J0mAusQs2HjE033tvlRaTu0XYeAWte8K+4McJn5IuVD13XI/GFHywXUyi7xxIG2ecQCiAlRZDrP84vXOG8PWe0jYmiByCtDe+1gFpA2FbrMAGOm/Be9zm92p+Gamj50Y3n2t6CzzO/Hv6ProKDVE=; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0103{break}vid_5448&pid_0004{break}vid_5448&pid_0203; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HaiTaiSM2Key.dll; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletevalue; Check: IsWin64
;
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKCS11Providers\HaiTai Cryptographic Service Provider; ValueType: string; ValueName: Image Path; ValueData: {syswow64}\HTPKCS11.dll; Check: IsWin64; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKCS11Providers\HaiTai Cryptographic Service Provider; ValueType: string; ValueName: Image Path; ValueData: {sys}\HTPKCS11.dll; Check: not IsWin64; Flags: uninsdeletevalue
;

[Run]
;Filename: {pf}\NETCA\NETCA_Devices\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; Parameters: /sp- /VERYSILENT /norestart; Flags: runhidden; WorkingDir: {pf}\NETCA\NETCA_Devices; Check: not IsWin64
;Filename: {pf32}\NETCA\NETCA_Devices\HaiKey_Driver_Silent_x86_x64_5.0.2015.12031.exe; Parameters: /sp- /VERYSILENT /norestart; Flags: runhidden; WorkingDir: {pf32}\NETCA\NETCA_Devices; Check: IsWin64
[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
[InstallDelete]
Name: {pf}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Type: files
Name: {pf}\NETCA\NETCA_Devices\HaitaiSM2Key.dll_driver.ini; Type: files
Name: {pf}\NETCA\NETCA_Devices\HaiTaiSM2Key.dll_device.ini; Type: files
Name: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Type: files; Check: not IsWin64
Name: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll_device.ini; Type: files; Check: not IsWin64
Name: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll_driver.ini; Type: files; Check: not IsWin64
Name: {pf}\NETCA\NETCA_Devices\HaitaiRSAKey.dll; Type: files
Name: {pf}\NETCA\NETCA_Devices\HaitaiRSAKey.dll_device.ini; Type: files
Name: {pf}\NETCA\NETCA_Devices\HaiTaiRSAKey.dll_driver.ini; Type: files
Name: {pf32}\NETCA\NETCA_Devices\HaiTaiRSAKey.dll_driver.ini; Type: files; Check: not IsWin64
Name: {pf32}\NETCA\NETCA_Devices\HaitaiRSAKey.dll_device.ini; Type: files; Check: not IsWin64
Name: {pf32}\NETCA\NETCA_Devices\HaitaiRSAKey.dll; Type: files; Check: not IsWin64
Name: {app}\Unins_HTSM2COS.exe; Type: files
Name: {app}\Unins_HTSM2COS.dat; Type: files
[_ISTool]
UseAbsolutePaths=false
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
NewUninsName := 'Unins_HTSM2COS';

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
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');

//MsgBox('检测到系统改完', mbInformation, MB_OK);
end;
end;
end;

function DelReg():Boolean;
var
  path1:String;
begin
   if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT') then
    RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT');

	if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA') then
    RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTRSA');

    if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2') then
    RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2');

   if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT') then
    RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA');

    if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHT') then
    RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTRSA');

    if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTSM2') then
    RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyHTSM2');


   if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{FAC4239C-91E5-468C-99E6-70A6C1EA580A}_is1') then
	RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{FAC4239C-91E5-468C-99E6-70A6C1EA580A}_is1');

	if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{FAC4239C-91E5-468C-99E6-70A6C1EA580A}_is1') then
	RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{FAC4239C-91E5-468C-99E6-70A6C1EA580A}_is1');


    if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{1394738E-C44C-4FB2-AEB5-5407C998792A}_is1') then
	RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{1394738E-C44C-4FB2-AEB5-5407C998792A}_is1');

	if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{1394738E-C44C-4FB2-AEB5-5407C998792A}_is1') then
	RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{1394738E-C44C-4FB2-AEB5-5407C998792A}_is1');

	if  RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{ECF7AFA0-E127-4910-9DBF-B490D9BB5028}_is1') then
	RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{1394738E-C44C-4FB2-AEB5-5407C998792A}_is1');

	if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{ECF7AFA0-E127-4910-9DBF-B490D9BB5028}_is1') then
	RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{1394738E-C44C-4FB2-AEB5-5407C998792A}_is1');
end;

function InitializeSetup(): boolean;
begin
//删除海泰SM2和海泰RSA的注册表
	DelReg();
	Result:=true;
end;
