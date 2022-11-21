; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备接口"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.4"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{B8ECEC3E-4A02-4E69-BFC2-078F959A4413}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf32}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_设备接口
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true


;开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCompany={#NETCA}
VersionInfoDescription={#DEVICES_APPNAME}32&64位
VersionInfoTextVersion={#SETUP_FILE_VERSION}
VersionInfoCopyright=C) {#NETCA}。保留所有权利。
SetupLogging=true

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=网证通设备接口
chinesesimp.SetupWindowTitle=网证通设备接口

trad.SetupAppTitle=網證通設備驅動
trad.SetupWindowTitle=網證通設備驅動

eng.SetupAppTitle=NETCADevices
eng.SetupWindowTitle=NETCADevices

[Files]
;64位系统64位公司动态设备DLL
Source: ..\..\winX64\设备驱动\文鼎创\ESKeyProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\文鼎创\ESKeyProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;32&64位系统32位公司动态设备DLL
Source: ..\..\winX86\设备驱动\文鼎创\ESKeyProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\文鼎创\ESKeyProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion


;64位系统公司动态设备DLL(64位)
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;32&64位系统公司动态设备DLL(32位)
Source: ..\..\..\..\证书介质\驱动及开发包\飞天\32位\Epass3003Prov.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\飞天3003\Epass3003Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion



;64位系统公司动态设备DLL（64位）
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTEKey.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰\HTEKey.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\海泰\HTEKey.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;32&64位系统公司动态设备DLL（32位）
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTEKey.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion

;公司动态设备DLL  飞天SM2
Source: ..\..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion

;公司动态设备DLL海泰SM2
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion

;公司动态设备DLL明华
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete ignoreversion restartreplace
Source: ..\..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
;公司动态设备DLL  飞天3000GM  32位
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\设备驱动\飞天SM2的COS\FT3000GMProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion

;公司动态设备DLL  飞天3000GM  64位
Source: ..\..\winX64\设备驱动\飞天SM2的COS\FT3000GMProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX64\设备驱动\飞天SM2的COS\FT3000GMProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64


[Registry]
;文鼎创
;32位系统
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: l87/vs6JFhdDlD6CrZfBlXhxyMLBXhTwHQt1nGx30ATSnQbID5LPaF+VlPHZyIiuiZmMuICfSyfcHLaqTCmPgToZjY703rz2ud3XmZ0fygc3+xpglsppXPk+jlr1BHW2AyB19xyLCKUZj7rVnTWJTZpQXBs2ThPFzL1WQRXJdH4=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\ESKeyProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64

;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: f90yW20eORma/z+HvJ6C8e1gafoBegck0Sm905RVUZ2wliu5nWVsD0vvacwrzAiJOIHMB991L+GPzAatdcjkYhu72gSYjbzcHRJ+uHtq5dK6MHQ7oJZaLmWLkaUeYvTwZoyOe6lPVZdvv0dFZ06dG2ZY1pkJ/uM8Szn6YYV925U=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\ESKeyProv.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: l87/vs6JFhdDlD6CrZfBlXhxyMLBXhTwHQt1nGx30ATSnQbID5LPaF+VlPHZyIiuiZmMuICfSyfcHLaqTCmPgToZjY703rz2ud3XmZ0fygc3+xpglsppXPk+jlr1BHW2AyB19xyLCKUZj7rVnTWJTZpQXBs2ThPFzL1WQRXJdH4=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\ESKeyProv.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

;3003设备dll注册表
;32位系统注册表
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\Epass3003Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: GePmY+/jCaH1xQPzlCpzmZTVoVWab8J3YScWd9DQn9DGQgM3dzvC4zsqg8TUEFsyBwg04Emn75eZwe+SwTrKYDFiuvdOHfk9JP2izLUA9w97chZE58M4Y3hnMH7vtzBapfBOPr2ub+boJCjLmhzBkVA6Stzd/6KuQMwRREn4KvQ=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
;64位系统64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: A1F5z4EpJ3FVvokrSZMslomUWso2cmmfSdE4v3YESuEv3NKMkpoM9VOdcDcqvKqYaaPEG4lA2fGjhZzMkD1lQDaOR2lYRnUc1QR36JBnPiRHkmODdRhLs0ZSQoEoWNNlFasEroIBv+msp5P1sqr22hb+VUsF0MaCQ0BSpfSjP6g=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
;64位系统32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: GePmY+/jCaH1xQPzlCpzmZTVoVWab8J3YScWd9DQn9DGQgM3dzvC4zsqg8TUEFsyBwg04Emn75eZwe+SwTrKYDFiuvdOHfk9JP2izLUA9w97chZE58M4Y3hnMH7vtzBapfBOPr2ub+boJCjLmhzBkVA6Stzd/6KuQMwRREn4KvQ=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

;海泰普通注册表
;32位系统注册表
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HTEKey.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: U80zoR77rMXYD7SLQhHKcAA8wD0ATknWlMY17KLcDvawGOZTUfQnVhF5mDiJ9Idtd8JEi89PwZUyFltsMo81Nkdz/8DEJLWhVMeEbcZfwvc9hR02fzFVbxbNg7Zfz/SI9Kixy9Q/4du+0sKhgrGkNpTjmgyOJkiRzm1rfmwoFi4=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: not IsWin64; Flags: uninsdeletekey
;64位系统注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\HTEKey.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: kYPWom3kXhLzKYMPIE142dug1nWZ83CYQ99glHyUDgFEwPmgLIcU0e7uHMzWltfKxmW7wiOn2qZqRUMW7BLC75+o1fBw9j6urPouH+Hl2YFJwj6KyXIKZ6ewigWEJD/snYW3RUFUPTGvGPXYmLORYzWUzxiXfPk8ZhGMhnyykMM=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey

Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HTEKey.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: U80zoR77rMXYD7SLQhHKcAA8wD0ATknWlMY17KLcDvawGOZTUfQnVhF5mDiJ9Idtd8JEi89PwZUyFltsMo81Nkdz/8DEJLWhVMeEbcZfwvc9hR02fzFVbxbNg7Zfz/SI9Kixy9Q/4du+0sKhgrGkNpTjmgyOJkiRzm1rfmwoFi4=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey






;明华3版
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: 00000006; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch

;明华2版
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: type; ValueData: 00000002; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch


;HTSM2注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch

;飞天SM2
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: signature; ValueData: JgNgzowo0v4ow77gLTv+/jf27NrKuAjcpKV/jwqHI9ARLrvN14LuexjCc7V07JkQKfsZuyQKvrnkw+tzoZwhDM7/4u6ZCsTGGew0RV9JEDeHFJ4uLsLpaf+4BDdY52tNlGH7vaRm7K/oukMLbP0lapiCJD1+5krg7V0M3UZHK3I=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch

Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: bO2cThnFnVAxtuNKe0nbPcnmX4/LSRHnm5WD9gWCXBBGb+siCzMFF45qenZQVBWF2kutdDnrFUW27oOK5MrMAyKHnVKdJ3pdGUJBW9k6qra0olC5gDMqv0OQttzZSKZMAzzyyKbgF7wF4+ffJDm7e58TJD5CKxMCkqsjPuoMxqU=; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsOtherArch
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00

;明华3版
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV3Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: 00000006; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

;明华2版
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\MWEKeyV2Prov.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: type; ValueData: 00000002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; Subkey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64


;HTSM2注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\HaitaiSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64

;飞天SM2
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FeiTianSM2Key.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: signature; ValueData: JgNgzowo0v4ow77gLTv+/jf27NrKuAjcpKV/jwqHI9ARLrvN14LuexjCc7V07JkQKfsZuyQKvrnkw+tzoZwhDM7/4u6ZCsTGGew0RV9JEDeHFJ4uLsLpaf+4BDdY52tNlGH7vaRm7K/oukMLbP0lapiCJD1+5krg7V0M3UZHK3I=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64


;飞天3000GM  32wei dll
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: bO2cThnFnVAxtuNKe0nbPcnmX4/LSRHnm5WD9gWCXBBGb+siCzMFF45qenZQVBWF2kutdDnrFUW27oOK5MrMAyKHnVKdJ3pdGUJBW9k6qra0olC5gDMqv0OQttzZSKZMAzzyyKbgF7wF4+ffJDm7e58TJD5CKxMCkqsjPuoMxqU=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64



;飞天3000GM  64wei dll
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FT3000GMProv.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: dej3x95MTIkDXQsYWtIlVagI+pGJpBptLM5Wk2t6X1Eb0JgM0/pyvWcUHBgpLPEKcBoHfMZ6NI2xiI20jUX7yZix3Q8s7ttYFg0VVMQThn4vdNwSzUPoBjNmXI5e0DImqj1JQiGC3LpvGN76MxsHq299G1mdFX6oHyspgtim93s=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0314; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Check: IsWin64; Flags: uninsdeletekey




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
[_ISTool]
LogFile=C:\Users\yeliqiao\Desktop\8989.txt
LogFileAppend=true
