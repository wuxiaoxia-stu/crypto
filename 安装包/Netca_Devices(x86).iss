; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.1.1.4"

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
AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename=NETCA_Devices_x86
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32位
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
;明华驱动
Source: ..\..\..\证书介质\驱动及开发包\明华\NETCAKEY_MWV2V3.exe; DestDir: {app}; Flags: deleteafterinstall ignoreversion
Source: ..\..\..\证书介质\驱动及开发包\明华\MWTokenAPI.dll; DestDir: {sys}; Flags: restartreplace ignoreversion

;海泰驱动
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GEC00001.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\GECSP00001.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HTCSPApi.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰\NETCAKEY_HT安装包文件\NETCA_Win32\HtPkcs11.ini; DestDir: {sys}; Flags: uninsrestartdelete

;飞天3003
Source: ..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\wztCsp11_3003_s.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\飞天\飞天3003无界面统一安装包打包说明20111101\飞天3003_files_64位系统\SysWOW64\WZTCsp11_3003.sig; DestDir: {sys}; Flags: uninsrestartdelete

;文鼎创
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217API.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217CFG.bin; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217CSP.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217CSPSi.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217Drv00.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217Pkcs.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217SKF.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\深圳文鼎创\网证通自定义打包\64位系统\SysWOW64\SJK1217SKF_API.dll; DestDir: {sys}; Flags: uninsrestartdelete


;海泰SM2
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\证书介质\驱动及开发包\海泰SM2的Key\海泰sm2驱动2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: uninsrestartdelete

;飞天SM2
Source: ..\..\..\证书介质\驱动及开发包\飞天SM2\GmCsp\GmCsp.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion

;公司动态设备DLL
Source: ..\winX86\设备驱动\明华2版\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\winX86\设备驱动\明华3版\MWEKeyV3Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\winX86\设备驱动\海泰\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\设备驱动\飞天3003\Epass3003Prov.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\设备驱动\文鼎创\ESKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\设备驱动\海泰SM2的Key\HaitaiSM2Key.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\设备驱动\飞天SM2的Key\FeiTianSM2Key.dll; DestDir: {app}; Flags: uninsrestartdelete


[Registry]
;明华3版
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV3Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: 00000006; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;明华2版
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV2Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: type; ValueData: 00000002; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMW2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey


;海泰
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {app}\HTEKey.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: U80zoR77rMXYD7SLQhHKcAA8wD0ATknWlMY17KLcDvawGOZTUfQnVhF5mDiJ9Idtd8JEi89PwZUyFltsMo81Nkdz/8DEJLWhVMeEbcZfwvc9hR02fzFVbxbNg7Zfz/SI9Kixy9Q/4du+0sKhgrGkNpTjmgyOJkiRzm1rfmwoFi4=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;飞天3003
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {app}\Epass3003Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: GePmY+/jCaH1xQPzlCpzmZTVoVWab8J3YScWd9DQn9DGQgM3dzvC4zsqg8TUEFsyBwg04Emn75eZwe+SwTrKYDFiuvdOHfk9JP2izLUA9w97chZE58M4Y3hnMH7vtzBapfBOPr2ub+boJCjLmhzBkVA6Stzd/6KuQMwRREn4KvQ=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;文鼎创
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: l87/vs6JFhdDlD6CrZfBlXhxyMLBXhTwHQt1nGx30ATSnQbID5LPaF+VlPHZyIiuiZmMuICfSyfcHLaqTCmPgToZjY703rz2ud3XmZ0fygc3+xpglsppXPk+jlr1BHW2AyB19xyLCKUZj7rVnTWJTZpQXBs2ThPFzL1WQRXJdH4=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {app}\ESKeyProv.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey

;HTSM2注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: dllpath; ValueData: {app}\HaitaiSM2Key.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey

;飞天SM2
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: dllpath; ValueData: {app}\FeiTianSM2Key.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: string; ValueName: signature; ValueData: dsKkK+FKTdKEMvBiwk1X6ED7EXVTmvsgM3/3M/I1IACMrYW6YGYVoqmuQJVnV9P1DsDeTao9Rh5KoT296TY4lHTlW6aOPAcBndXEs5OFQkKyU8hXK+1gF3fJHf0OAdEf8WHyzScMc+ykW0YIk0QxDVjvMvNCOarq3SBo2qc6xrQ=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey

[Run]
Filename: {app}\NETCAKEY_MWV2V3.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {sys}; Flags: runminimized runhidden

[UninstallRun]
Filename: {pf}\NETCA\NETCAKEY_MWHS\unins000.exe; WorkingDir: {pf}\NETCA\NETCAKEY_MWHS; Parameters: /SP- /VERYSILENT /NORESTART

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
