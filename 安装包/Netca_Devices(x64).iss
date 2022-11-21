; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动"
#define KEYX "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.1.1"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{FAA9D9FE-E80E-4725-8FB8-8595A48BDFCA}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher={#KEYX}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf64}\NETCA\NETCA_Devices

AppCopyright=? {#KEYX}。保留所有权利。

OutputBaseFilename=NETCA_Devices_x64
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}64位
VersionInfoVersion ={#SETUP_FILE_VERSION}
UninstallDisplayName  ={#DEVICES_APPNAME}(x64)

;ArchitecturesAllowed=x86 x64 ia64
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
chinesesimp.SetupAppTitle=网证通设备驱动
chinesesimp.SetupWindowTitle=网证通设备驱动

trad.SetupAppTitle=網證通設備驅動
trad.SetupWindowTitle=網證通設備驅動

eng.SetupAppTitle=NETCA_Devices
eng.SetupWindowTitle=NETCA_Devices

[Files]
;明华USBKey驱动文件
Source: ..\..\..\证书介质\驱动及开发包\明华\NETCAKEY_MWV2V3.exe; DestDir: {app}; Flags: deleteafterinstall

;飞天3003驱动文件
Source: ..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\system32\WZTCsp11_3003.DLL; DestDir: {sys}; Flags: uninsrestartdelete 64bit

;海泰驱动文件
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GEC00001.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\GECSP00001.ini; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win64\64system32\HTCSPApi.ini; DestDir: {sys}; Flags: uninsrestartdelete 64bit

;文鼎创驱动文件
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217API.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217CFG.bin; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217CSP.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217CSPSi.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217Drv00.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包V1.4\64位系统\system32\SJK1217Pkcs.dll; DestDir: {sys}; Flags: uninsrestartdelete 64bit

;设备接口库
;明华V2
Source: ..\winX64\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit
;飞天3003
Source: ..\winX64\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit
;海泰
Source: ..\winX64\设备驱动\海泰\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit
;文鼎创
Source: ..\winX64\设备驱动\文鼎创\ESKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete 64bit


[Registry]

;明华V2
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV2Prov.dll; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: signature; ValueData: QDy/OmyWW3qxbRINsA1N9EMi+R3lXHGvZHUYPbyCetc/9lyhA86Pc2SwxyfeLli+gtPc0N7W5cWn8K58KCsf5pao1Xm7zsLgQ5IGutxDT6IVvAlrruDGdYSjlncR2URE5n40cgN/I4VC5bK3v0SoGAwq0Ip/T+LJBez0hsFOxWc=; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: type; ValueData: $00000002; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;飞天3003 64bit注册表文件
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {app}\Epass3003Prov.dll; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: RlptXqyJkDjVPrdSzomVQ+AGltoL2jAcRwn/orif9yTeshJmJWENoUJhHM3lVSdWn73waW38teheOZUt3aMm0OBvhULHXmZURWQ54fjQgftm7qdCS02Li+kvFO3Rfo/jdesqjDbkNsrh0U4G38+GaVaJn1WB9hoKcxogSOHTC4I=; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;海泰64位注册表
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {app}\HTEKey.dll; Flags: uninsdeletekey
Root: HKLM64; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: kYPWom3kXhLzKYMPIE142dug1nWZ83CYQ99glHyUDgFEwPmgLIcU0e7uHMzWltfKxmW7wiOn2qZqRUMW7BLC75+o1fBw9j6urPouH+Hl2YFJwj6KyXIKZ6ewigWEJD/snYW3RUFUPTGvGPXYmLORYzWUzxiXfPk8ZhGMhnyykMM=; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: $00000004; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;文鼎创64bit注册表文件
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: YxfF3hyoB9vXKRkmri4T8Gs3M5e8fb/P96Nt311nr0HSVVbASVLGoyquFZIGruO9YvzU+1LKMt11RNaw+f/hRDkeuF9p50X7wMPZHga70e4MPPDcBFcaAHq5bGdEqfWCsdHpqJt+QFg1kHrDVXOQpWyAqNgela9xvWTStpq1930=; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {app}\ESKeyProv.dll; Flags: uninsdeletekey
Root: HKLM64; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

[Run]
Filename: {app}\NETCAKEY_MWV2V3.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {sys}

[UninstallRun]
Filename: {pf32}\NETCA\NETCAKEY_MWHS1\unins000.exe; WorkingDir: {pf32}\NETCA\NETCAKEY_MWHS; Parameters: /SP- /VERYSILENT /NORESTART

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
