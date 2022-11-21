; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define NETCA "广东省电子商务认证有限公司"
#define SETUP_APPNAME "加密机配置安装包"
#define SETUP_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"


[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{92EBD7A1-9684-4800-8F72-1276800BE751}
AppName={#SETUP_APPNAME}
AppVersion={#SETUP_APPVERSION}
AppVerName={#SETUP_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

AppCopyright=? {#NETCA}。保留所有权利。
OutputBaseFilename={#SETUP_APPNAME}
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#SETUP_APPNAME}
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}
VersionInfoProductName={#SETUP_APPNAME}
VersionInfoProductVersion={#SETUP_FILE_VERSION}
VersionInfoVersion={#SETUP_APPVERSION}


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=加密机配置安装包
chinesesimp.SetupWindowTitle=加密机配置安装包

trad.SetupAppTitle=加密机配置安装包
trad.SetupWindowTitle=加密机配置安装包

eng.SetupAppTitle=NETCACrypto
eng.SetupWindowTitle=NETCACrypto

[Files]
;得安SJJ0929加密机设备文件
;32位系统得安ECC加密机32位文件
Source: ..\winX86\设备驱动\得安ECC加密机\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ0929
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\sdk\Windows\32\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ0929
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ0929

;64位系统得安加密机64位文件
Source: ..\winX64\设备驱动\得安ECC加密机\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\sdk\Windows\64\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929

;64位系统得安加密机32位文件
Source: ..\winX86\设备驱动\得安ECC加密机\SJJ0929Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\sdk\Windows\32\SJJ0929_dtcsp.dll; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\SJJ0929_dtcrypt.ini; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929

;得安SJY05B加密机设备文件
;32位系统得安加密机32位文件
Source: ..\winX86\设备驱动\得安ECC加密机\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJY05B
Source: ..\..\..\证书介质\驱动及开发包\得安\Windows\32\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJY05B
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJY05B

;64位系统得安加密机64位文件
Source: ..\winX64\设备驱动\得安ECC加密机\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\证书介质\驱动及开发包\得安\Windows\64\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B

;64位系统得安加密机32位文件
Source: ..\winX86\设备驱动\得安ECC加密机\SJJ0929Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\证书介质\驱动及开发包\得安\Windows\32\SJJ0929_dtcsp.dll; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\证书介质\驱动及开发包\得安ECC加密机\SJJ0929_dtcrypt.ini; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B

;普华加密机SJJ1011设备文件
;32位系统32位文件
Source: ..\winX86\设备驱动\普华加密机\PHSJJ1011Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ1011
Source: ..\..\..\证书介质\驱动及开发包\上海普华加密机\20131206客户端升级\网政通客户端升级\接口库\win32\stdcall\ph_sdf.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ1011
Source: ..\..\..\证书介质\驱动及开发包\上海普华加密机\module.conf; DestDir: {pf}\phgcs; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ1011

;64位系统64位文件
Source: ..\winX64\设备驱动\普华加密机\PHSJJ1011Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\证书介质\驱动及开发包\上海普华加密机\20131206客户端升级\网政通客户端升级\接口库\win64\stdcall\ph_sdf.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\证书介质\驱动及开发包\上海普华加密机\module.conf; DestDir: {pf}\phgcs; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011

;64位系统32位文件
Source: ..\winX86\设备驱动\普华加密机\PHSJJ1011Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\证书介质\驱动及开发包\上海普华加密机\20131206客户端升级\网政通客户端升级\接口库\win32\stdcall\ph_sdf.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\证书介质\驱动及开发包\上海普华加密机\module.conf; DestDir: {pf32}\phgcs; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: Readme.txt; DestDir: {app}; Flags: isreadme

[Registry]
;得安SJJ0929加密机注册表
;32位系统注册表得安ECC32
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: dllpath; ValueData: {app}\SJJ0929Prov.dll; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: mustLogin; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: type; ValueData: $00000066; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: signature; ValueData: p+YQbHs3ZxruQ9RlI5Mf+OlyTWCJJ2Jj4kPYba4qtLX0+nG9tGOm9pUPMDTMbKB7T9x/Wpr33+2JhVl0YeSbAYU6fT5UBty1L1Pl/s2Cng7CX25Jp4pnYyO3X1IKX4BTp3Qj5yONIIojziYk296FGCu9fRC7mBLptw1YNydreAg=; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: string; ValueName: SerialNumber; ValueData: 12345678; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: string; ValueName: ConfigFileName; ValueData: C:\Windows\System32\SJJ0929_dtcrypt.ini; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM2; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasECDSA; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSHA256; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSHA1; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSSF33CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM1CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasAES; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: Has3DES; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasDES; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasP256; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: MaxOperationLen; ValueData: $00002000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ0929
;64位系统注册表得安ECC64位注册表
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: dllpath; ValueData: {app}\SJJ0929Prov.dll; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: mustLogin; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: type; ValueData: $00000066; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: signature; ValueData: jC4+EtI1SY2eQLMbyuT3sa/rytUqMEV0SnegNndybjtGMCejFiv5ZodrqQcQYo9NH+XlPSTsk0Pbbsfzug5PVBHupuBNfv14skiN1KYuqXLu/l6CYYhNakVNfasyfpmNSM7z9aSYhwaXmHkKaP5p4PV/fXmIoZor8Vb1NhIGpds=; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: string; ValueName: SerialNumber; ValueData: 12345678; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: string; ValueName: ConfigFileName; ValueData: C:\Windows\System32\SJJ0929_dtcrypt.ini; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM2; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasECDSA; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSHA256; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSHA1; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSSF33CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM1CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasAES; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: Has3DES; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasDES; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasP256; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: MaxOperationLen; ValueData: $00002000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929

;64位系统注册表得安ECC32位注册表
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\SJJ0929Prov.dll; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: mustLogin; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: type; ValueData: $00000066; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: signature; ValueData: p+YQbHs3ZxruQ9RlI5Mf+OlyTWCJJ2Jj4kPYba4qtLX0+nG9tGOm9pUPMDTMbKB7T9x/Wpr33+2JhVl0YeSbAYU6fT5UBty1L1Pl/s2Cng7CX25Jp4pnYyO3X1IKX4BTp3Qj5yONIIojziYk296FGCu9fRC7mBLptw1YNydreAg=; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: string; ValueName: SerialNumber; ValueData: 12345678; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: string; ValueName: ConfigFileName; ValueData: C:\Windows\System32\SJJ0929_dtcrypt.ini; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM2; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasECDSA; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSHA256; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSHA1; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSSF33CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasSM1CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasAES; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: Has3DES; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasDES; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: HasP256; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.0; ValueType: dword; ValueName: MaxOperationLen; ValueData: $00002000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ0929

;得安SJY05B加密机设备注册表
;32位系统注册表32
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: dllpath; ValueData: {app}\SJJ0929Prov.dll; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: mustLogin; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: type; ValueData: $00000066; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: signature; ValueData: p+YQbHs3ZxruQ9RlI5Mf+OlyTWCJJ2Jj4kPYba4qtLX0+nG9tGOm9pUPMDTMbKB7T9x/Wpr33+2JhVl0YeSbAYU6fT5UBty1L1Pl/s2Cng7CX25Jp4pnYyO3X1IKX4BTp3Qj5yONIIojziYk296FGCu9fRC7mBLptw1YNydreAg=; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: string; ValueName: SerialNumber; ValueData: 87654321; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: string; ValueName: ConfigFileName; ValueData: C:\Windows\System32\SJJ0929_dtcrypt.ini; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM1; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM2; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasECDSA; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSSF33CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM1CBC; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasAES; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: Has3DES; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasDES; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasP256; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: MaxOperationLen; ValueData: $00000400; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B

;64位系统注册表64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: dllpath; ValueData: {app}\SJJ0929Prov.dll; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: mustLogin; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: type; ValueData: $00000066; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: signature; ValueData: b658ZD52/KjFyuLpwNbV7XbdaPTu1dd36UorG0oYmp/U3UQPW8mZi6a/gRc41AuL5Ld7HDFZBa5CTsfMiz6ieckiyQSto7bW3Ikr1Ak0KhMmZJqCsF6LFSJ3TWb1SZLT9tBcfhBvQPSTg7hQnrOh7TmccrQ3DDVSnPfTEY0hU84=; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: string; ValueName: SerialNumber; ValueData: 87654321; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: string; ValueName: ConfigFileName; ValueData: C:\Windows\System32\SJJ0929_dtcrypt.ini; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM1; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM2; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasECDSA; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSSF33CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM1CBC; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasAES; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: Has3DES; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasDES; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasP256; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: MaxOperationLen; ValueData: $00000400; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B

;64位系统注册表32
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\SJJ0929Prov.dll; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: mustLogin; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: type; ValueData: $00000066; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: string; ValueName: signature; ValueData: p+YQbHs3ZxruQ9RlI5Mf+OlyTWCJJ2Jj4kPYba4qtLX0+nG9tGOm9pUPMDTMbKB7T9x/Wpr33+2JhVl0YeSbAYU6fT5UBty1L1Pl/s2Cng7CX25Jp4pnYyO3X1IKX4BTp3Qj5yONIIojziYk296FGCu9fRC7mBLptw1YNydreAg=; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: string; ValueName: SerialNumber; ValueData: 87654321; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: string; ValueName: ConfigFileName; ValueData: C:\Windows\syswow64\SJJ0929_dtcrypt.ini; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM1; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM2; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasECDSA; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSSF33CBC; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasSM1CBC; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasAES; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: Has3DES; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasDES; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: HasP256; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SJJ0929\192.168.0.1; ValueType: dword; ValueName: MaxOperationLen; ValueData: $00000400; Flags: uninsdeletevalue; Check: IsWin64; Components: SJY05B

;普华加密机注册表
;32位系统注册表32
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: type; ValueData: $00000067; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: signature; ValueData: FrXYYmG8wHBXJ8eZdrSK/JgxvUkeKbiOssysS5Md68/UY93gEyLsE+CTnOm8RaXO/v+LCfdoqNCrGacDWFw4ljVJ++Lzd0ayASmJWDn0U7yT3+bccySXZAgt4mnopHRnaUOl/FCv78nw0jXdv70qGBw3aFd6E3WLItsGfpAx6QQ=; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: KeyPairStatus; ValueData: 0555555555566666666666656565261561661166660000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSMS4; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: MultiDevice; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: DisplayName; ValueData: 普华加密机; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: Server; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: NoCert; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\PHSJJ1011Prov.dll; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
;64位系统注册表64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: type; ValueData: $00000067; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: signature; ValueData: BLzFBHXLiwCXxPcdbfW2qn9RkyEdMOoIiGFg1pwh2FEunvLDcLBeTSDO7vLJIkIQaCHg+ah+ygvuPvG6q6ZiBcZlWhbgtIA4NSjDrJBIaXZiSEw7wxA1/zNKQei7fuebnFujvpdMDiVhQWFLzzucg0bE9XBOVaIcY4xCqj6xCnw=; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: KeyPairStatus; ValueData: 0555555555566666666666656565261565665566665000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000005; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSMS4; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: MultiDevice; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: DisplayName; ValueData: 普华加密机; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: Server; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: NoCert; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\PHSJJ1011Prov.dll; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
;64位系统注册表32
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: type; ValueData: $00000067; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: signature; ValueData: FrXYYmG8wHBXJ8eZdrSK/JgxvUkeKbiOssysS5Md68/UY93gEyLsE+CTnOm8RaXO/v+LCfdoqNCrGacDWFw4ljVJ++Lzd0ayASmJWDn0U7yT3+bccySXZAgt4mnopHRnaUOl/FCv78nw0jXdv70qGBw3aFd6E3WLItsGfpAx6QQ=; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: KeyPairStatus; ValueData: 0555555555566666666666656565261561661166660000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSMS4; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: MultiDevice; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: DisplayName; ValueData: 普华加密机; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: Server; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: NoCert; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\PHSJJ1011Prov.dll; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011



[Components]
Name: SJJ0929; Description: 得安加密机SJJ0929; Flags: checkablealone; Types: compact
Name: SJY05B; Description: 得安加密机SJY05B; Flags: checkablealone; Types: compact
Name: SJJ1011; Description: 普华加密机SJJ1011; Flags: checkablealone; Types: compact

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
uninspath, uninsname, NewUninsName, MyAppName: string;
begin
if CurStep=ssDone then
begin
// 指定新的卸载文件名（不包含扩展名），请相应修改！
NewUninsName := 'Unins_JMJ';
// 应用程序名称，与 [SEUTP] 段的 AppName 必须一致，请相应修改！
MyAppName := '92EBD7A1-9684-4800-8F72-1276800BE751';
// 以下重命名卸载文件
uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
// 以下修改相应的注册表内容
if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1') then
begin
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
end;
end;
end;
