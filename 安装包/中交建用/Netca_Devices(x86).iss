; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.12"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{A1B114F4-8C78-4A74-934F-F439774A795C}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

OutputBaseFilename=NETCA_Devices_ZJIAO
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(中交建)
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

;海泰驱动
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GEC00001.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.ini; DestDir: {sys}; Flags: uninsrestartdelete


;海泰SM2
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\HKDriver.dll; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\HKDriver32.exe; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\HKeyEnum.sys; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\HKeyIFD.sys; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\HKeyUsb.sys; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\htfykey.cat; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\Driver\HTFYKey.inf; DestDir: {sys}\Driver; Flags: uninsrestartdelete

;公司动态设备DLL
Source: ..\..\winX86\设备驱动\海泰\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll; DestDir: {app}; Flags: uninsrestartdelete
;华大SDKey
Source: ..\..\winX86\设备驱动\华大SDKey\HDMicroSDKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\驱动文件\HD_Token.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\驱动文件\HD_Cryptoki.dll; DestDir: {sys}; Flags: uninsrestartdelete

;亚略特
DestDir: {app}; Source: ..\..\winX86\设备驱动\亚略特指纹USBKey\AratekFPKeyProv.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\..\..\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\ASCryptoki.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\..\..\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\ASFKeyAPI.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\..\..\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\FDcgi.dll; Flags: uninsrestartdelete
DestDir: {sys}; Source: ..\..\..\..\证书介质\驱动及开发包\亚略特指纹USBKey\亚略特PKCS11库\TokenASApi.dll; Flags: uninsrestartdelete

[Registry]
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {app}\HTEKey.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: G8crgHKKB9D93apERnELDQJQP49dnF7kQAJbAsXoHc9zLwM1ZtJdlZrR8LeVxbhbLKogKw2zrYz5dShiu6NkDtYpqzXykWIZeFeZhUkOvqygwqWOZnPK8DzysRsdoY4jFY5yoU6NNh4GpMGKYDyennshHlup4OF8hL53SzJwyFQ=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey

;HTSM2注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {app}\HaitaiSM2Key.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: Z5nO56kha/rfQLzUCNv7JSe+ixXK14kBTlGzbuCrUsZUBQBvIw3YaXytDP/uFuWn8KDaIzhaSDU5OPlRjA6qfxkWwWgScuxeH25UVb2Q9Qzlwe2d4u1Lp1OPGdSiCiGYgcoQZ8cLF6/IVhLU4NGOZAtqWJwf902b3pJo8WhZi2I=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey

;华大SDKey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {app}\HDMicroSDKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: IyuBtU82NmW9hgPjVve30wbg8sr6c+pVwC62a1LBozK+aYv5Xi0ybeHQvlSHbty3SsLJGRDDOOz5T0WISlEilxum4R7bW7I96bSa6qbz5gFSbgxfNpC+BxVE9zcU9gOBBbEWXKZX45onpL4bCq/BKJaDQG4jrL4pvxh/rXNdjr8=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletekey

;亚略特
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: dllpath; ValueData: {app}\AratekFPKeyProv.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: signature; ValueData: i2YUF2cht86gXQkDiWhD5qhr6OTQw9Hj0kDnoqM4HjqeR51j71ejuYfewZlp5kR1TrBPXgsrGNUqjK6D2EstC0+NnhBqsm862YCudnvoeeo/j4ON9yZL6FZUPMmzXdCNuevXLGNc5QTWfbkQFSsjFJLjWYyOkrf3BzZoQ00X2FM=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: type; ValueData: $0000002a; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: multisz; ValueName: idstring; ValueData: Vid_2010&Pid_1200; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAAratekFPKey; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

[Run]
Filename: {sys}\Driver\HKDriver32.exe; Parameters: -i; WorkingDir: {sys}; Flags: runhidden
[UninstallRun]
Filename: {sys}\Driver\HKDriver32.exe; Parameters: -u; WorkingDir: {sys}; Flags: runhidden
[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
