; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通安全客户端兼容GDCA插件"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.2"
#define UID "6F4128B4-C7A6-40C1-B692-1FFD6211F17B"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{6F4128B4-C7A6-40C1-B692-1FFD6211F17B}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPVERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net
DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=Copyright 2019 @ NETCA.保留所有权利。
OutputBaseFilename=NETCA_Devices(GDCA)
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
Uninstallable=false
[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl
[Messages]
chinesesimp.SetupAppTitle=网证通安全客户端兼容GDCA插件
chinesesimp.SetupWindowTitle=网证通安全客户端兼容GDCA插件
trad.SetupAppTitle=網證通安全客戶端兼容GDCA插件
trad.SetupWindowTitle=網證通安全客戶端兼容GDCA插件
eng.SetupAppTitle=NETCADevices_GDCA
eng.SetupWindowTitle=NETCADevices_GDCA
[Files]
;trust文件
Source: ..\..\..\..\..\统一介质管理工具\current\发布版\InnoSetup\Netca_Crypto\InnoSetupInstallOperator.dll; DestDir: {tmp}; Flags: dontcopy solidbreak
Source: ..\..\..\..\..\项目\公共资源类项目\深圳产权交易集团\GDCA\trust; DestDir: {tmp}; Flags: uninsrestartdelete ignoreversion
Source: ..\..\..\..\..\项目\公共资源类项目\深圳产权交易集团\GDCA\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete restartreplace ignoreversion; check: IsTrustNoModify1
Source: ..\..\..\..\..\项目\公共资源类项目\深圳产权交易集团\GDCA\trust; DestDir: {localappdata}\VirtualStore\ProgramData\NETCA\certs; Flags: uninsrestartdelete restartreplace ignoreversion; check: IsTrustNoModify2 and (not IsXp)


[Registry]
;64位系统32位注册表
;注册表去除idstring，通过代码增量添加idstring里的vidpid
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: type; ValueData: $00000045; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: signature; ValueData: OSYMwLiEWh3uiRzpFHA8TCpeAj5pyC/rwFSSk6QyIRVbWxUK8fW69Q8SCeeYNx1yiDg3b1zkiJxbYNeslcZ6pKe6ocozQgKCSQ2yBS02l2V4nYPXBvXjdzbvSs1vAJ1nSvWznQvhESqTGqmxw6pZrUV/1zborb/62DGtZO6Lygk=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\SKFManageProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
;Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: multisz; ValueName: idstring; ValueData: vid_096E&pid_0312{break}vid_096E&pid_0319{break}vid_163c&pid_0415{break}vid_163c&pid_0423; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSM4; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: string; ValueName: SkfDllPath; ValueData: gdca_dal_szd3003_sm2.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: AES128ECB; ValueData: $00004001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: AES128CBC; ValueData: $00004002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: multisz; ValueName: FilterProcess; ValueData: KeyX.exe{break}netcakeyxserver.exe; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSM4; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: string; ValueName: SkfDllPath; ValueData: gdca_dal_ecc27.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: AES128ECB; ValueData: $00004001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: AES128CBC; ValueData: $00004002; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: multisz; ValueName: FilterProcess; ValueData: KeyX.exe{break}netcakeyxserver.exe; Flags: uninsdeletekey; Check: IsWin64


;32位系统32位注册表
;注册表去除idstring，通过代码增量添加idstring里的vidpid
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: type; ValueData: $00000045; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: signature; ValueData: OSYMwLiEWh3uiRzpFHA8TCpeAj5pyC/rwFSSk6QyIRVbWxUK8fW69Q8SCeeYNx1yiDg3b1zkiJxbYNeslcZ6pKe6ocozQgKCSQ2yBS02l2V4nYPXBvXjdzbvSs1vAJ1nSvWznQvhESqTGqmxw6pZrUV/1zborb/62DGtZO6Lygk=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\SKFManageProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
;Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: multisz; ValueName: idstring; ValueData: vid_096E&pid_0312{break}vid_096E&pid_0319{break}vid_163c&pid_0415{break}vid_163c&pid_0423; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSM4; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: string; ValueName: SkfDllPath; ValueData: gdca_dal_szd3003_sm2.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: AES128ECB; ValueData: $00004001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: dword; ValueName: AES128CBC; ValueData: $00004002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-1; ValueType: multisz; ValueName: FilterProcess; ValueData: KeyX.exe{break}netcakeyxserver.exe; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSM4; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: string; ValueName: SkfDllPath; ValueData: gdca_dal_ecc27.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: AES128ECB; ValueData: $00004001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: dword; ValueName: AES128CBC; ValueData: $00004002; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\GDCA-2; ValueType: multisz; ValueName: FilterProcess; ValueData: KeyX.exe{break}netcakeyxserver.exe; Flags: uninsdeletekey; Check: not IsWin64

;证书链
;GDCA ROOT CA1.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\SystemCertificates\ROOT\Certificates\0A8F0029EA3CD051A30133BD7AA6ECCFF8FFEDC6; ValueType: binary; ValueName: Blob; ValueData: 5c 00 00 00 01 00 00 00 04 00 00 00 00 10 00 00 19 00 00 00 01 00 00 00 10 00 00 00 40 c9 5d 18 e2 c3 a2 54 19 76 80 78 d7 95 61 43 14 00 00 00 01 00 00 00 14 00 00 00 bc 59 ba c0 ac d1 5b a5 ba af 2f 20 95 7e 61 b0 5e 00 c4 2c 03 00 00 00 01 00 00 00 14 00 00 00 0a 8f 00 29 ea 3c d0 51 a3 01 33 bd 7a a6 ec cf f8 ff ed c6 0f 00 00 00 01 00 00 00 20 00 00 00 ce cb 4e e9 40 0f 9d 91 63 b7 5e dd c3 73 d9 49 2f 34 f2 b3 2a 5e 38 ad d5 de e6 c3 2f 66 21 84 04 00 00 00 01 00 00 00 10 00 00 00 43 b9 55 64 a5 d0 01 80 fa 1f 24 60 d8 55 f3 bc 20 00 00 00 01 00 00 00 88 05 00 00 30 82 05 84 30 82 03 6c a0 03 02 01 02 02 08 2d ab 67 ea c5 5a c0 e4 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 16 30 14 06 03 55 04 03 0c 0d 47 44 43 41 20 52 4f 4f 54 20 43 41 31 30 1e 17 0d 31 37 30 36 31 31 30 32 33 38 30 37 5a 17 0d 34 30 31 32 33 31 31 35 35 39 35 39 5a 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 16 30 14 06 03 55 04 03 0c 0d 47 44 43 41 20 52 4f 4f 54 20 43 41 31 30 82 02 22 30 0d 06 09 2a 86 48 86 f7 0d 01 01 01 05 00 03 82 02 0f 00 30 82 02 0a 02 82 02 01 00 a9 f7 8f ef 00 8f 29 09 75 59 6a 49 5b 3b 38 17 a8 62 53 fe c1 a1 61 60 63 e4 69 e0 d6 e1 24 da 1f 6d 69 7b 0e 67 6f a9 e1 2a 57 ea 60 fe a3 7d bc 6e d8 1e 5b 55 ce db 62 0d 65 f5 f0 dd 7c cf 24 12 01 59 7f 89 81 73 c6 48 1a 94 95 04 02 6f 4b 07 93 1b bc e5 ff f3 81 70 a8 ac e1 a6 51 0d 6c a4 6f 92 4c f9 f5 b8 ec f0 fe dc 5e 4c 2b de 07 cf 1c ae 1f 2d 49 85 a0 a7 a4 cd ae da b6 d6 fc d7 35 f4 f3 40 02 e5 78 67 b3 31 9c dc 37 c9 0b 8c 09 71 3c 36 9f 8b 89 cf b7 0b 37 74 57 c0 c3 46 2c 4f 39 36 35 a5 b0 b4 34 99 48 fd d0 b4 f7 73 4a 00 30 79 4b 46 e7 72 ca c3 07 fd 0a af 66 a4 ba a2 a9 7a f0 28 8c e2 53 22 db b9 18 9a 16 74 ef cb 7b a3 7f 83 f5 15 a1 90 af ad df 2a d3 96 b4 4a 25 91 6b 24 aa 53 fd 39 18 c7 33 25 ca c0 af aa 5a c2 cc 40 98 78 8d c4 13 64 9b 0c 4d 43 5e 66 12 11 77 55 db cb af 95 c9 ad d7 ba b2 26 02 39 b9 d5 60 24 a0 0f de 10 d0 34 36 07 d9 26 e0 7b 92 a8 da 2f 25 60 63 45 27 ae c4 41 6e 24 37 24 6e c9 2a 57 a6 8b 13 da ae cc 46 4d d4 19 73 f5 0f 00 0a 9d c0 f0 b0 c5 f3 3d 54 83 3b a6 e7 7c 68 18 5d 5c 02 38 a1 76 2f e7 fb 35 e6 69 77 f6 71 ea 42 1c 6c 7d 88 f9 d8 a1 89 80 09 4a 94 d0 48 22 bf 3e 82 83 95 f7 8a ad 44 2e dd af 31 76 dd fb f9 02 4b 2e 9a be 53 55 11 cf 78 b8 f8 9d 45 3e 47 61 fe 0d 2a 9b c7 31 ee 11 67 80 46 b4 af ba f0 b2 5c 76 ce 95 15 79 63 aa c9 b8 3c 94 03 56 28 88 21 99 bf 8b e3 bf f8 e8 b7 1d 32 d8 2f 98 73 38 a2 44 da 70 93 68 34 53 10 be ad 97 4b 1d a8 f4 67 94 2e f4 69 fa 68 df cb e0 20 85 24 10 d6 7e a9 c9 fa fe cc be c0 87 bc 9e ba 4e c2 c4 38 5b 37 16 43 f4 7c 62 28 e1 02 03 01 00 01 a3 42 30 40 30 1d 06 03 55 1d 0e 04 16 04 14 bc 59 ba c0 ac d1 5b a5 ba af 2f 20 95 7e 61 b0 5e 00 c4 2c 30 0f 06 03 55 1d 13 01 01 ff 04 05 30 03 01 01 ff 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 03 82 02 01 00 22 a8 e1 00 23 20 32 e7 ce 72 79 b3 33 82 ff 77 24 e6 a8 71 ae 47 a8 98 5d b5 4f 00 ce c2 62 69 78 84 d5 ad e7 f8 4e 28 6c 0f 7a ab fd dd 00 f9 e6 d0 47 b5 2d af ee 55 40 ba 03 16 78 bf 1a 09 2d c4 05 67 6f ac b7 20 69 32 31 e4 78 f5 6a 6c a6 e9 8d b2 47 7f ed d2 55 79 15 96 6e 8f bd 6c 9d 25 9f 3f 00 83 b2 41 af bd 87 d3 5b da 26 08 3b 17 f8 4f ca de 98 b0 ff 74 13 d3 16 39 db f7 e3 ec 0d fd f8 cc 3a 8c c6 51 b4 95 98 c2 83 1d 67 88 a5 57 0a b3 55 37 12 3d f7 08 bc c9 b4 27 48 2c 20 85 2a 31 a8 f7 cf e6 2c cf d4 e4 83 82 25 a2 ad 16 65 23 06 19 78 87 ee e0 6b 1b 7f af 59 45 90 c3 ff 7b af ec dc ce 54 54 a3 07 8d 01 2f ca 84 76 7f 4a 28 d2 ad 99 28 ef 43 1a f3 d1 79 05 d0 df 38 2a ad 07 41 7e c9 55 d8 36 92 88 03 f6 d2 5f bd 08 bf 2e a0 aa 9c dd 32 e2 29 71 a1 c2 a2 5f 02 b0 0b 02 22 d6 5d 67 9c 93 ba 2d 93 7b 0c 2f 18 04 71 c0 80 1b b1 83 b8 91 a5 0f 0b 47 c0 42 48 4f f6 b2 0f 0b 55 56 66 2c de 42 14 40 db 0b 6b 2f 6d 06 30 87 4f 80 93 22 ac c5 99 58 de a3 99 ec 1d 09 2c 8a d3 77 b7 54 78 99 a3 99 fb 01 a5 c0 2d 04 2c 09 ac 07 86 1b b7 99 13 18 a4 19 86 69 c6 8d 23 49 cd f1 0e fa 6e 51 36 6d f6 5a af df c1 7f 3b fb 04 e3 b6 e5 c0 27 82 0d 5c 3e af c8 5f 12 54 59 e2 ed d1 a7 48 1b ee db 51 92 ae 13 de e0 3c 77 2b db 21 82 69 c1 91 86 3f 21 e3 8e bb 35 4d e9 6f 1a 59 0f 90 5d 19 71 89 ac 99 62 67 c8 12 de 5e 54 2f f1 e0 ee 81 c4 15 83 e0 e1 10 5a 2b 90 4e 91 46 8d 9a d2 e2 5b fa 0e 3a 33 3b 4a 83 98 fd 87 96 53 7f 38 04 d9 60 74 40 bb 8e d7 78 3e d9 4f 01 df 42 a4 50 2f 71 bb 31 4c 5c 1e dc 13 cc 55 17 ed 65 08
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\Microsoft\SystemCertificates\ROOT\Certificates\0A8F0029EA3CD051A30133BD7AA6ECCFF8FFEDC6; ValueType: binary; ValueName: Blob; ValueData: 5c 00 00 00 01 00 00 00 04 00 00 00 00 10 00 00 19 00 00 00 01 00 00 00 10 00 00 00 40 c9 5d 18 e2 c3 a2 54 19 76 80 78 d7 95 61 43 14 00 00 00 01 00 00 00 14 00 00 00 bc 59 ba c0 ac d1 5b a5 ba af 2f 20 95 7e 61 b0 5e 00 c4 2c 03 00 00 00 01 00 00 00 14 00 00 00 0a 8f 00 29 ea 3c d0 51 a3 01 33 bd 7a a6 ec cf f8 ff ed c6 0f 00 00 00 01 00 00 00 20 00 00 00 ce cb 4e e9 40 0f 9d 91 63 b7 5e dd c3 73 d9 49 2f 34 f2 b3 2a 5e 38 ad d5 de e6 c3 2f 66 21 84 04 00 00 00 01 00 00 00 10 00 00 00 43 b9 55 64 a5 d0 01 80 fa 1f 24 60 d8 55 f3 bc 20 00 00 00 01 00 00 00 88 05 00 00 30 82 05 84 30 82 03 6c a0 03 02 01 02 02 08 2d ab 67 ea c5 5a c0 e4 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 16 30 14 06 03 55 04 03 0c 0d 47 44 43 41 20 52 4f 4f 54 20 43 41 31 30 1e 17 0d 31 37 30 36 31 31 30 32 33 38 30 37 5a 17 0d 34 30 31 32 33 31 31 35 35 39 35 39 5a 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 16 30 14 06 03 55 04 03 0c 0d 47 44 43 41 20 52 4f 4f 54 20 43 41 31 30 82 02 22 30 0d 06 09 2a 86 48 86 f7 0d 01 01 01 05 00 03 82 02 0f 00 30 82 02 0a 02 82 02 01 00 a9 f7 8f ef 00 8f 29 09 75 59 6a 49 5b 3b 38 17 a8 62 53 fe c1 a1 61 60 63 e4 69 e0 d6 e1 24 da 1f 6d 69 7b 0e 67 6f a9 e1 2a 57 ea 60 fe a3 7d bc 6e d8 1e 5b 55 ce db 62 0d 65 f5 f0 dd 7c cf 24 12 01 59 7f 89 81 73 c6 48 1a 94 95 04 02 6f 4b 07 93 1b bc e5 ff f3 81 70 a8 ac e1 a6 51 0d 6c a4 6f 92 4c f9 f5 b8 ec f0 fe dc 5e 4c 2b de 07 cf 1c ae 1f 2d 49 85 a0 a7 a4 cd ae da b6 d6 fc d7 35 f4 f3 40 02 e5 78 67 b3 31 9c dc 37 c9 0b 8c 09 71 3c 36 9f 8b 89 cf b7 0b 37 74 57 c0 c3 46 2c 4f 39 36 35 a5 b0 b4 34 99 48 fd d0 b4 f7 73 4a 00 30 79 4b 46 e7 72 ca c3 07 fd 0a af 66 a4 ba a2 a9 7a f0 28 8c e2 53 22 db b9 18 9a 16 74 ef cb 7b a3 7f 83 f5 15 a1 90 af ad df 2a d3 96 b4 4a 25 91 6b 24 aa 53 fd 39 18 c7 33 25 ca c0 af aa 5a c2 cc 40 98 78 8d c4 13 64 9b 0c 4d 43 5e 66 12 11 77 55 db cb af 95 c9 ad d7 ba b2 26 02 39 b9 d5 60 24 a0 0f de 10 d0 34 36 07 d9 26 e0 7b 92 a8 da 2f 25 60 63 45 27 ae c4 41 6e 24 37 24 6e c9 2a 57 a6 8b 13 da ae cc 46 4d d4 19 73 f5 0f 00 0a 9d c0 f0 b0 c5 f3 3d 54 83 3b a6 e7 7c 68 18 5d 5c 02 38 a1 76 2f e7 fb 35 e6 69 77 f6 71 ea 42 1c 6c 7d 88 f9 d8 a1 89 80 09 4a 94 d0 48 22 bf 3e 82 83 95 f7 8a ad 44 2e dd af 31 76 dd fb f9 02 4b 2e 9a be 53 55 11 cf 78 b8 f8 9d 45 3e 47 61 fe 0d 2a 9b c7 31 ee 11 67 80 46 b4 af ba f0 b2 5c 76 ce 95 15 79 63 aa c9 b8 3c 94 03 56 28 88 21 99 bf 8b e3 bf f8 e8 b7 1d 32 d8 2f 98 73 38 a2 44 da 70 93 68 34 53 10 be ad 97 4b 1d a8 f4 67 94 2e f4 69 fa 68 df cb e0 20 85 24 10 d6 7e a9 c9 fa fe cc be c0 87 bc 9e ba 4e c2 c4 38 5b 37 16 43 f4 7c 62 28 e1 02 03 01 00 01 a3 42 30 40 30 1d 06 03 55 1d 0e 04 16 04 14 bc 59 ba c0 ac d1 5b a5 ba af 2f 20 95 7e 61 b0 5e 00 c4 2c 30 0f 06 03 55 1d 13 01 01 ff 04 05 30 03 01 01 ff 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 03 82 02 01 00 22 a8 e1 00 23 20 32 e7 ce 72 79 b3 33 82 ff 77 24 e6 a8 71 ae 47 a8 98 5d b5 4f 00 ce c2 62 69 78 84 d5 ad e7 f8 4e 28 6c 0f 7a ab fd dd 00 f9 e6 d0 47 b5 2d af ee 55 40 ba 03 16 78 bf 1a 09 2d c4 05 67 6f ac b7 20 69 32 31 e4 78 f5 6a 6c a6 e9 8d b2 47 7f ed d2 55 79 15 96 6e 8f bd 6c 9d 25 9f 3f 00 83 b2 41 af bd 87 d3 5b da 26 08 3b 17 f8 4f ca de 98 b0 ff 74 13 d3 16 39 db f7 e3 ec 0d fd f8 cc 3a 8c c6 51 b4 95 98 c2 83 1d 67 88 a5 57 0a b3 55 37 12 3d f7 08 bc c9 b4 27 48 2c 20 85 2a 31 a8 f7 cf e6 2c cf d4 e4 83 82 25 a2 ad 16 65 23 06 19 78 87 ee e0 6b 1b 7f af 59 45 90 c3 ff 7b af ec dc ce 54 54 a3 07 8d 01 2f ca 84 76 7f 4a 28 d2 ad 99 28 ef 43 1a f3 d1 79 05 d0 df 38 2a ad 07 41 7e c9 55 d8 36 92 88 03 f6 d2 5f bd 08 bf 2e a0 aa 9c dd 32 e2 29 71 a1 c2 a2 5f 02 b0 0b 02 22 d6 5d 67 9c 93 ba 2d 93 7b 0c 2f 18 04 71 c0 80 1b b1 83 b8 91 a5 0f 0b 47 c0 42 48 4f f6 b2 0f 0b 55 56 66 2c de 42 14 40 db 0b 6b 2f 6d 06 30 87 4f 80 93 22 ac c5 99 58 de a3 99 ec 1d 09 2c 8a d3 77 b7 54 78 99 a3 99 fb 01 a5 c0 2d 04 2c 09 ac 07 86 1b b7 99 13 18 a4 19 86 69 c6 8d 23 49 cd f1 0e fa 6e 51 36 6d f6 5a af df c1 7f 3b fb 04 e3 b6 e5 c0 27 82 0d 5c 3e af c8 5f 12 54 59 e2 ed d1 a7 48 1b ee db 51 92 ae 13 de e0 3c 77 2b db 21 82 69 c1 91 86 3f 21 e3 8e bb 35 4d e9 6f 1a 59 0f 90 5d 19 71 89 ac 99 62 67 c8 12 de 5e 54 2f f1 e0 ee 81 c4 15 83 e0 e1 10 5a 2b 90 4e 91 46 8d 9a d2 e2 5b fa 0e 3a 33 3b 4a 83 98 fd 87 96 53 7f 38 04 d9 60 74 40 bb 8e d7 78 3e d9 4f 01 df 42 a4 50 2f 71 bb 31 4c 5c 1e dc 13 cc 55 17 ed 65 08
;GDCA TrustAUTH E1 CA.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\SystemCertificates\CA\Certificates\1DC5335ED35FB4E3AFA710E6619C0F4211FA89F9; ValueType: binary; ValueName: Blob; ValueData: 18 00 00 00 01 00 00 00 10 00 00 00 e1 00 0d 36 17 21 6d 6b 58 90 25 f0 18 a2 b0 19 0f 00 00 00 01 00 00 00 20 00 00 00 b5 cd 9a 7a e5 bf 4a 69 42 b9 9c 75 ce 1e e2 1f 40 18 79 39 d6 5f 99 b5 19 f2 d8 43 d1 59 6c bb 19 00 00 00 01 00 00 00 10 00 00 00 bf 45 e3 ed e4 40 b8 a6 78 b1 14 24 33 47 60 2e 03 00 00 00 01 00 00 00 14 00 00 00 1d c5 33 5e d3 5f b4 e3 af a7 10 e6 61 9c 0f 42 11 fa 89 f9 14 00 00 00 01 00 00 00 14 00 00 00 11 8f e3 fd 39 19 1d 9c 19 1f 49 37 6e ac 44 8c 55 ea 14 bd 04 00 00 00 01 00 00 00 10 00 00 00 8e c4 9d 22 2f 44 6e b9 fd ff a8 24 6d 98 f8 32 5c 00 00 00 01 00 00 00 04 00 00 00 00 01 00 00 20 00 00 00 01 00 00 00 b7 02 00 00 30 82 02 b3 30 82 02 58 a0 03 02 01 02 02 10 3e 7e 54 df dc 3f 77 bd 31 3b c8 31 99 21 8f d2 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 30 2e 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0f 30 0d 06 03 55 04 03 0c 06 52 4f 4f 54 43 41 30 1e 17 0d 31 34 30 36 32 36 30 37 30 32 31 31 5a 17 0d 33 34 30 36 32 31 30 37 30 32 31 31 5a 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 32 30 30 06 03 55 04 0a 0c 29 47 55 41 4e 47 20 44 4f 4e 47 20 43 45 52 54 49 46 49 43 41 54 45 20 41 55 54 48 4f 52 49 54 59 20 43 4f 2e 2c 4c 54 44 2e 31 1d 30 1b 06 03 55 04 03 0c 14 47 44 43 41 20 54 72 75 73 74 41 55 54 48 20 45 31 20 43 41 30 59 30 13 06 07 2a 86 48 ce 3d 02 01 06 08 2a 81 1c cf 55 01 82 2d 03 42 00 04 7a d6 dc 21 31 35 a9 f8 da 0c 05 3d ab 38 e5 54 bd de 5b 49 67 16 67 28 6b 5b 97 14 28 92 7c 35 38 c0 48 50 e3 2a 66 04 aa 4d 7a 16 0c f7 c1 4c d8 03 c7 92 4c 58 6d 4a 8b ec 9e a6 23 27 34 ea a3 82 01 22 30 82 01 1e 30 1f 06 03 55 1d 23 04 18 30 16 80 14 4c 32 b1 97 d9 33 1b c4 a6 05 c1 c6 e5 8b 62 5b f0 97 76 58 30 0f 06 03 55 1d 13 01 01 ff 04 05 30 03 01 01 ff 30 81 ba 06 03 55 1d 1f 04 81 b2 30 81 af 30 41 a0 3f a0 3d a4 3b 30 39 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0c 30 0a 06 03 55 04 0b 0c 03 41 52 4c 31 0c 30 0a 06 03 55 04 03 0c 03 61 72 6c 30 2a a0 28 a0 26 86 24 68 74 74 70 3a 2f 2f 77 77 77 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 2f 61 72 6c 2f 61 72 6c 2e 63 72 6c 30 3e a0 3c a0 3a 86 38 6c 64 61 70 3a 2f 2f 6c 64 61 70 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 3a 33 38 39 2f 43 4e 3d 61 72 6c 2c 4f 55 3d 41 52 4c 2c 4f 3d 4e 52 43 41 43 2c 43 3d 43 4e 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 1d 06 03 55 1d 0e 04 16 04 14 11 8f e3 fd 39 19 1d 9c 19 1f 49 37 6e ac 44 8c 55 ea 14 bd 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 03 47 00 30 44 02 20 1a e1 b3 57 1f 10 51 e9 19 18 1e d9 a4 df 95 58 3c 82 b7 c4 4a bb b7 f2 b0 28 3e 41 79 cf f4 c1 02 20 65 04 8f 75 3e 10 db c5 3e c1 24 72 d4 36 57 9b 15 72 a6 28 5f 3c 82 ae e9 0e 5e 22 db 34 e4 98
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\Microsoft\SystemCertificates\CA\Certificates\1DC5335ED35FB4E3AFA710E6619C0F4211FA89F9; ValueType: binary; ValueName: Blob; ValueData: 18 00 00 00 01 00 00 00 10 00 00 00 e1 00 0d 36 17 21 6d 6b 58 90 25 f0 18 a2 b0 19 0f 00 00 00 01 00 00 00 20 00 00 00 b5 cd 9a 7a e5 bf 4a 69 42 b9 9c 75 ce 1e e2 1f 40 18 79 39 d6 5f 99 b5 19 f2 d8 43 d1 59 6c bb 19 00 00 00 01 00 00 00 10 00 00 00 bf 45 e3 ed e4 40 b8 a6 78 b1 14 24 33 47 60 2e 03 00 00 00 01 00 00 00 14 00 00 00 1d c5 33 5e d3 5f b4 e3 af a7 10 e6 61 9c 0f 42 11 fa 89 f9 14 00 00 00 01 00 00 00 14 00 00 00 11 8f e3 fd 39 19 1d 9c 19 1f 49 37 6e ac 44 8c 55 ea 14 bd 04 00 00 00 01 00 00 00 10 00 00 00 8e c4 9d 22 2f 44 6e b9 fd ff a8 24 6d 98 f8 32 5c 00 00 00 01 00 00 00 04 00 00 00 00 01 00 00 20 00 00 00 01 00 00 00 b7 02 00 00 30 82 02 b3 30 82 02 58 a0 03 02 01 02 02 10 3e 7e 54 df dc 3f 77 bd 31 3b c8 31 99 21 8f d2 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 30 2e 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0f 30 0d 06 03 55 04 03 0c 06 52 4f 4f 54 43 41 30 1e 17 0d 31 34 30 36 32 36 30 37 30 32 31 31 5a 17 0d 33 34 30 36 32 31 30 37 30 32 31 31 5a 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 32 30 30 06 03 55 04 0a 0c 29 47 55 41 4e 47 20 44 4f 4e 47 20 43 45 52 54 49 46 49 43 41 54 45 20 41 55 54 48 4f 52 49 54 59 20 43 4f 2e 2c 4c 54 44 2e 31 1d 30 1b 06 03 55 04 03 0c 14 47 44 43 41 20 54 72 75 73 74 41 55 54 48 20 45 31 20 43 41 30 59 30 13 06 07 2a 86 48 ce 3d 02 01 06 08 2a 81 1c cf 55 01 82 2d 03 42 00 04 7a d6 dc 21 31 35 a9 f8 da 0c 05 3d ab 38 e5 54 bd de 5b 49 67 16 67 28 6b 5b 97 14 28 92 7c 35 38 c0 48 50 e3 2a 66 04 aa 4d 7a 16 0c f7 c1 4c d8 03 c7 92 4c 58 6d 4a 8b ec 9e a6 23 27 34 ea a3 82 01 22 30 82 01 1e 30 1f 06 03 55 1d 23 04 18 30 16 80 14 4c 32 b1 97 d9 33 1b c4 a6 05 c1 c6 e5 8b 62 5b f0 97 76 58 30 0f 06 03 55 1d 13 01 01 ff 04 05 30 03 01 01 ff 30 81 ba 06 03 55 1d 1f 04 81 b2 30 81 af 30 41 a0 3f a0 3d a4 3b 30 39 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0c 30 0a 06 03 55 04 0b 0c 03 41 52 4c 31 0c 30 0a 06 03 55 04 03 0c 03 61 72 6c 30 2a a0 28 a0 26 86 24 68 74 74 70 3a 2f 2f 77 77 77 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 2f 61 72 6c 2f 61 72 6c 2e 63 72 6c 30 3e a0 3c a0 3a 86 38 6c 64 61 70 3a 2f 2f 6c 64 61 70 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 3a 33 38 39 2f 43 4e 3d 61 72 6c 2c 4f 55 3d 41 52 4c 2c 4f 3d 4e 52 43 41 43 2c 43 3d 43 4e 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 1d 06 03 55 1d 0e 04 16 04 14 11 8f e3 fd 39 19 1d 9c 19 1f 49 37 6e ac 44 8c 55 ea 14 bd 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 03 47 00 30 44 02 20 1a e1 b3 57 1f 10 51 e9 19 18 1e d9 a4 df 95 58 3c 82 b7 c4 4a bb b7 f2 b0 28 3e 41 79 cf f4 c1 02 20 65 04 8f 75 3e 10 db c5 3e c1 24 72 d4 36 57 9b 15 72 a6 28 5f 3c 82 ae e9 0e 5e 22 db 34 e4 98
;GDCA Public CA1.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\SystemCertificates\CA\Certificates\6C7749A4167E2CCE64729947D51801EA29ADB7B5; ValueType: binary; ValueName: Blob; ValueData: 18 00 00 00 01 00 00 00 10 00 00 00 40 c9 5d 18 e2 c3 a2 54 19 76 80 78 d7 95 61 43 03 00 00 00 01 00 00 00 14 00 00 00 6c 77 49 a4 16 7e 2c ce 64 72 99 47 d5 18 01 ea 29 ad b7 b5 5c 00 00 00 01 00 00 00 04 00 00 00 00 08 00 00 19 00 00 00 01 00 00 00 10 00 00 00 a2 41 e0 7c 87 bb e2 6e da ce 31 80 f8 47 68 05 14 00 00 00 01 00 00 00 14 00 00 00 95 4d 13 1f 6b 21 91 09 6f 16 12 8a 65 bc 0b 56 0b 11 6b c8 0f 00 00 00 01 00 00 00 20 00 00 00 77 6c 0c 19 ba 7e b3 b7 b4 2b 95 d3 de 2e 60 47 a7 c2 e8 f5 24 d6 4f d5 ab b2 a4 ef ef 3b b9 d2 04 00 00 00 01 00 00 00 10 00 00 00 91 d9 76 b2 8d 1d e7 4a 8a 8c 56 dd d8 f9 3e b8 20 00 00 00 01 00 00 00 39 05 00 00 30 82 05 35 30 82 03 1d a0 03 02 01 02 02 08 16 af 5b 0d a4 89 29 f7 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 16 30 14 06 03 55 04 03 0c 0d 47 44 43 41 20 52 4f 4f 54 20 43 41 31 30 1e 17 0d 31 37 30 37 30 36 30 32 32 37 31 33 5a 17 0d 33 30 31 32 33 30 31 36 30 30 30 30 5a 30 62 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 18 30 16 06 03 55 04 03 0c 0f 47 44 43 41 20 50 75 62 6c 69 63 20 43 41 31 30 82 01 22 30 0d 06 09 2a 86 48 86 f7 0d 01 01 01 05 00 03 82 01 0f 00 30 82 01 0a 02 82 01 01 00 dc 1c c0 23 ee 65 58 33 a9 91 1d bc ff 30 2c 4f f7 52 57 ef ee c6 1b e2 d3 93 dd a4 ad e9 3b dd 78 9e b3 3f 3c be ab af 6a 93 6d 1c 41 f0 c2 c9 2f 9c f7 38 33 92 ee 36 05 b4 05 90 5c 03 54 5c b0 72 78 56 7e 19 5c 68 5e ca e2 94 e2 09 aa f2 e1 fd fd 48 7b bb bc c0 11 42 e1 d5 8e 05 38 e7 f5 3d d6 71 df 4c 27 50 4d 85 84 98 97 e6 37 c9 2c 62 d3 22 5f e8 55 7a fa f6 c6 85 05 ee 96 e2 e8 d2 ec 11 8c ee 35 21 d1 47 c0 b6 16 37 21 b7 39 36 ab fa 35 6b 13 06 82 97 ef 5f 77 1b 6f 6c 91 68 ec 31 b8 18 63 2c c3 dc 3d 2b 45 a5 0c ab 17 c0 c1 c6 43 6b ac c7 e7 3f 0a 18 eb f6 68 17 65 68 76 b5 5c d4 38 5e 20 6c 40 d0 5b 9f bf 17 db 97 81 de 7c 3b 89 03 71 5e 84 b4 cf 8f c0 04 62 fe 6a 7e c2 73 42 c7 49 d0 4f 9e 28 4c 6c 13 e9 8c 8b 51 73 e2 dc 34 52 1e d0 30 9a a6 a4 ab 02 03 01 00 01 a3 81 f0 30 81 ed 30 1d 06 03 55 1d 0e 04 16 04 14 95 4d 13 1f 6b 21 91 09 6f 16 12 8a 65 bc 0b 56 0b 11 6b c8 30 12 06 03 55 1d 13 01 01 ff 04 08 30 06 01 01 ff 02 01 00 30 1f 06 03 55 1d 23 04 18 30 16 80 14 bc 59 ba c0 ac d1 5b a5 ba af 2f 20 95 7e 61 b0 5e 00 c4 2c 30 48 06 03 55 1d 20 04 41 30 3f 30 3d 06 04 55 1d 20 00 30 35 30 33 06 08 2b 06 01 05 05 07 02 01 16 27 68 74 74 70 3a 2f 2f 77 77 77 2e 67 64 63 61 2e 63 6f 6d 2e 63 6e 2f 63 70 73 2f 64 6f 6d 65 73 74 69 63 2d 63 70 73 30 3d 06 03 55 1d 1f 04 36 30 34 30 32 a0 30 a0 2e 86 2c 68 74 74 70 3a 2f 2f 63 72 6c 2e 67 64 63 61 2e 63 6f 6d 2e 63 6e 2f 63 72 6c 2f 47 44 43 41 5f 52 4f 4f 54 5f 43 41 31 2e 63 72 6c 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 03 82 02 01 00 37 30 56 ae 17 aa 68 98 ce d1 c1 cf e8 9e 13 e7 64 15 50 b1 80 03 d7 6a 80 69 0c 0a 16 05 82 60 9b b7 09 0a b3 d3 13 cd e4 aa 03 ab 5b 79 6e 63 d9 8a 79 a9 12 5c f6 20 c4 58 99 23 1c 24 ce 9e 21 84 e7 f5 5f 47 7b 57 fb 60 e0 09 49 b2 58 49 08 39 8b 44 fb 25 f2 8b 1f ac 6e af 38 43 65 b9 50 f8 b5 90 ab 6d 06 24 d6 c7 ca f4 b0 6e 11 e3 ec eb 48 ad 46 fb a5 dc b0 79 2c 4d 71 27 75 96 0f 74 c9 f9 39 29 fa e7 79 d2 c4 2b 07 76 20 a8 93 94 60 7a d3 81 97 ea d6 91 49 14 ec d7 67 c8 31 26 94 aa 4d e6 af 09 47 7b 11 df d6 e7 7d 87 b2 d4 63 dd 0d 36 39 e2 57 ee 10 c3 6a 5b bf 82 65 5d 44 23 cd a2 cf 02 0f b2 62 54 2b bb 9b 23 44 18 ac fb 17 79 b3 68 6a 82 13 df d1 04 8d 98 68 dd 37 86 ca 93 23 43 d5 f3 fa c6 ff 8f 7e 03 e1 ac 53 48 9a d4 ff 24 2c 17 cc 2e 59 c5 30 d6 36 7c 90 68 7d f6 61 3b 2a 4b bf 76 fe 03 12 c5 0a 42 fb b0 62 5c ff 00 40 26 a0 32 48 b1 3f 6c 42 e1 4f a2 ec 6c 54 69 c8 a1 b0 34 cd 8d 18 b7 6e c2 99 1e ca 86 96 94 08 fb 0d 3e 40 ce 88 58 44 28 40 a7 30 14 d2 61 3c c8 82 2b 02 6d 33 86 50 1b 8d 88 57 93 19 e9 61 79 df 64 b3 84 ed b8 03 36 c5 ec d8 42 75 69 f0 20 73 da f3 a7 98 0e f7 05 e3 16 9b b3 81 6d 9e fd 4a e5 06 b3 a6 07 1f 52 33 37 31 9e 54 91 9e 49 a8 24 38 cb 23 e7 40 d6 31 62 2b 78 00 9e d3 58 11 3c 74 0a 0a 8b e3 d6 ba eb 28 9a 11 83 ac e4 8b 41 da b3 40 5e 5d b3 af 2b 15 64 74 05 b0 76 00 55 e5 46 e0 c9 8e 5e 04 a7 55 19 6d 19 c7 5a dd a9 34 c8 ff 54 07 f9 b0 c5 23 f8 65 c6 2e df b7 3d 91 78 ff fc eb 5a 8a 6c e2 b3 8f 67 bb c7 a2 01 d1 15 c7 d0 22 0e 0f 93 cc 06 40 03 bc 0a 3f 3f 25 df 61 03
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\Microsoft\SystemCertificates\CA\Certificates\6C7749A4167E2CCE64729947D51801EA29ADB7B5; ValueType: binary; ValueName: Blob; ValueData: 18 00 00 00 01 00 00 00 10 00 00 00 40 c9 5d 18 e2 c3 a2 54 19 76 80 78 d7 95 61 43 03 00 00 00 01 00 00 00 14 00 00 00 6c 77 49 a4 16 7e 2c ce 64 72 99 47 d5 18 01 ea 29 ad b7 b5 5c 00 00 00 01 00 00 00 04 00 00 00 00 08 00 00 19 00 00 00 01 00 00 00 10 00 00 00 a2 41 e0 7c 87 bb e2 6e da ce 31 80 f8 47 68 05 14 00 00 00 01 00 00 00 14 00 00 00 95 4d 13 1f 6b 21 91 09 6f 16 12 8a 65 bc 0b 56 0b 11 6b c8 0f 00 00 00 01 00 00 00 20 00 00 00 77 6c 0c 19 ba 7e b3 b7 b4 2b 95 d3 de 2e 60 47 a7 c2 e8 f5 24 d6 4f d5 ab b2 a4 ef ef 3b b9 d2 04 00 00 00 01 00 00 00 10 00 00 00 91 d9 76 b2 8d 1d e7 4a 8a 8c 56 dd d8 f9 3e b8 20 00 00 00 01 00 00 00 39 05 00 00 30 82 05 35 30 82 03 1d a0 03 02 01 02 02 08 16 af 5b 0d a4 89 29 f7 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 30 60 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 16 30 14 06 03 55 04 03 0c 0d 47 44 43 41 20 52 4f 4f 54 20 43 41 31 30 1e 17 0d 31 37 30 37 30 36 30 32 32 37 31 33 5a 17 0d 33 30 31 32 33 30 31 36 30 30 30 30 5a 30 62 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 39 30 37 06 03 55 04 0a 0c 30 47 6c 6f 62 61 6c 20 44 69 67 69 74 61 6c 20 43 79 62 65 72 73 65 63 75 72 69 74 79 20 41 75 74 68 6f 72 69 74 79 20 43 6f 2e 2c 20 4c 74 64 2e 31 18 30 16 06 03 55 04 03 0c 0f 47 44 43 41 20 50 75 62 6c 69 63 20 43 41 31 30 82 01 22 30 0d 06 09 2a 86 48 86 f7 0d 01 01 01 05 00 03 82 01 0f 00 30 82 01 0a 02 82 01 01 00 dc 1c c0 23 ee 65 58 33 a9 91 1d bc ff 30 2c 4f f7 52 57 ef ee c6 1b e2 d3 93 dd a4 ad e9 3b dd 78 9e b3 3f 3c be ab af 6a 93 6d 1c 41 f0 c2 c9 2f 9c f7 38 33 92 ee 36 05 b4 05 90 5c 03 54 5c b0 72 78 56 7e 19 5c 68 5e ca e2 94 e2 09 aa f2 e1 fd fd 48 7b bb bc c0 11 42 e1 d5 8e 05 38 e7 f5 3d d6 71 df 4c 27 50 4d 85 84 98 97 e6 37 c9 2c 62 d3 22 5f e8 55 7a fa f6 c6 85 05 ee 96 e2 e8 d2 ec 11 8c ee 35 21 d1 47 c0 b6 16 37 21 b7 39 36 ab fa 35 6b 13 06 82 97 ef 5f 77 1b 6f 6c 91 68 ec 31 b8 18 63 2c c3 dc 3d 2b 45 a5 0c ab 17 c0 c1 c6 43 6b ac c7 e7 3f 0a 18 eb f6 68 17 65 68 76 b5 5c d4 38 5e 20 6c 40 d0 5b 9f bf 17 db 97 81 de 7c 3b 89 03 71 5e 84 b4 cf 8f c0 04 62 fe 6a 7e c2 73 42 c7 49 d0 4f 9e 28 4c 6c 13 e9 8c 8b 51 73 e2 dc 34 52 1e d0 30 9a a6 a4 ab 02 03 01 00 01 a3 81 f0 30 81 ed 30 1d 06 03 55 1d 0e 04 16 04 14 95 4d 13 1f 6b 21 91 09 6f 16 12 8a 65 bc 0b 56 0b 11 6b c8 30 12 06 03 55 1d 13 01 01 ff 04 08 30 06 01 01 ff 02 01 00 30 1f 06 03 55 1d 23 04 18 30 16 80 14 bc 59 ba c0 ac d1 5b a5 ba af 2f 20 95 7e 61 b0 5e 00 c4 2c 30 48 06 03 55 1d 20 04 41 30 3f 30 3d 06 04 55 1d 20 00 30 35 30 33 06 08 2b 06 01 05 05 07 02 01 16 27 68 74 74 70 3a 2f 2f 77 77 77 2e 67 64 63 61 2e 63 6f 6d 2e 63 6e 2f 63 70 73 2f 64 6f 6d 65 73 74 69 63 2d 63 70 73 30 3d 06 03 55 1d 1f 04 36 30 34 30 32 a0 30 a0 2e 86 2c 68 74 74 70 3a 2f 2f 63 72 6c 2e 67 64 63 61 2e 63 6f 6d 2e 63 6e 2f 63 72 6c 2f 47 44 43 41 5f 52 4f 4f 54 5f 43 41 31 2e 63 72 6c 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 0d 06 09 2a 86 48 86 f7 0d 01 01 0b 05 00 03 82 02 01 00 37 30 56 ae 17 aa 68 98 ce d1 c1 cf e8 9e 13 e7 64 15 50 b1 80 03 d7 6a 80 69 0c 0a 16 05 82 60 9b b7 09 0a b3 d3 13 cd e4 aa 03 ab 5b 79 6e 63 d9 8a 79 a9 12 5c f6 20 c4 58 99 23 1c 24 ce 9e 21 84 e7 f5 5f 47 7b 57 fb 60 e0 09 49 b2 58 49 08 39 8b 44 fb 25 f2 8b 1f ac 6e af 38 43 65 b9 50 f8 b5 90 ab 6d 06 24 d6 c7 ca f4 b0 6e 11 e3 ec eb 48 ad 46 fb a5 dc b0 79 2c 4d 71 27 75 96 0f 74 c9 f9 39 29 fa e7 79 d2 c4 2b 07 76 20 a8 93 94 60 7a d3 81 97 ea d6 91 49 14 ec d7 67 c8 31 26 94 aa 4d e6 af 09 47 7b 11 df d6 e7 7d 87 b2 d4 63 dd 0d 36 39 e2 57 ee 10 c3 6a 5b bf 82 65 5d 44 23 cd a2 cf 02 0f b2 62 54 2b bb 9b 23 44 18 ac fb 17 79 b3 68 6a 82 13 df d1 04 8d 98 68 dd 37 86 ca 93 23 43 d5 f3 fa c6 ff 8f 7e 03 e1 ac 53 48 9a d4 ff 24 2c 17 cc 2e 59 c5 30 d6 36 7c 90 68 7d f6 61 3b 2a 4b bf 76 fe 03 12 c5 0a 42 fb b0 62 5c ff 00 40 26 a0 32 48 b1 3f 6c 42 e1 4f a2 ec 6c 54 69 c8 a1 b0 34 cd 8d 18 b7 6e c2 99 1e ca 86 96 94 08 fb 0d 3e 40 ce 88 58 44 28 40 a7 30 14 d2 61 3c c8 82 2b 02 6d 33 86 50 1b 8d 88 57 93 19 e9 61 79 df 64 b3 84 ed b8 03 36 c5 ec d8 42 75 69 f0 20 73 da f3 a7 98 0e f7 05 e3 16 9b b3 81 6d 9e fd 4a e5 06 b3 a6 07 1f 52 33 37 31 9e 54 91 9e 49 a8 24 38 cb 23 e7 40 d6 31 62 2b 78 00 9e d3 58 11 3c 74 0a 0a 8b e3 d6 ba eb 28 9a 11 83 ac e4 8b 41 da b3 40 5e 5d b3 af 2b 15 64 74 05 b0 76 00 55 e5 46 e0 c9 8e 5e 04 a7 55 19 6d 19 c7 5a dd a9 34 c8 ff 54 07 f9 b0 c5 23 f8 65 c6 2e df b7 3d 91 78 ff fc eb 5a 8a 6c e2 b3 8f 67 bb c7 a2 01 d1 15 c7 d0 22 0e 0f 93 cc 06 40 03 bc 0a 3f 3f 25 df 61 03

[InstallDelete]


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804
trad.LanguageName=TradChinese
trad.LanguageID=$0404
eng.LanguageName=English
eng.LanguageID=$0409
[Code]
#include '..\..\..\..\..\统一介质管理工具\current\安装脚本\NETCA.iss'
type
NameArray = array[0..10] of string;
var
  ret1: Integer;
  ret2: Integer;

function NewVidPid():NameArray;
var
newVid:NameArray;
begin
	newVid[0] := 'vid_096E&pid_0312';
	newVid[1] := 'vid_096E&pid_0319';
	newVid[2] := 'vid_163c&pid_0415';
	newVid[3] := 'vid_163c&pid_0423';
	Result:= newVid;
end;


procedure addVidPid;
var
oldVid,allVidPid: string;
RegPath: boolean;
begin
	if IsWin64 then
	begin
		RegPath := RegQueryMultiStringValue(HKLM, 'SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SKFDevice','idstring',oldVid);
		allVidPid := getAllVidPid(NewVidPid(),oldVid);
		RegWriteMultiStringValue(HKLM, 'SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\SKFDevice','idstring',allVidPid);
	end else begin
		RegPath := RegQueryMultiStringValue(HKLM, 'SOFTWARE\NETCA\PKI\Devices\SKFDevice','idstring',oldVid);
		allVidPid := getAllVidPid(NewVidPid(),oldVid);
		RegWriteMultiStringValue(HKLM, 'SOFTWARE\NETCA\PKI\Devices\SKFDevice','idstring',allVidPid);
	end;
end;

procedure CurStepChanged(CurStep: TSetupStep);
begin
	if CurStep=ssDone then
	begin
		addVidPid();
	end;
end;

procedure DoPendingFileRenameOperationsEvent(); external 'DoNetcaCryptoInstallBeginEvent@{tmp}\InnoSetupInstallOperator.dll stdcall delayload';
function DoIncrementTrustCACertsIfNeedEvent(a: AnsiString;b: AnsiString):Integer; external 'DoIncrementTrustCACertsIfNeedEvent@{tmp}\InnoSetupInstallOperator.dll stdcall delayload';


procedure InitializeWizard();
begin
	ExtractTemporaryFile('InnoSetupInstallOperator.dll');

ExtractTemporaryFile('trust');
	//信任trust处理
	ret1:=DoIncrementTrustCACertsIfNeedEvent(ExpandConstant('{commonappdata}\NETCA\certs\trust'),ExpandConstant('{tmp}\trust'));
	if not IsXp then
	begin
		ret2:=DoIncrementTrustCACertsIfNeedEvent(ExpandConstant('{localappdata}\VirtualStore\ProgramData\NETCA\certs\trust'),ExpandConstant('{tmp}\trust'));
	end

end;

//判断trust文件是否需要替换
function IsTrustNoModify1():Boolean;
begin

	if  ret1=1 then
	begin
		//增量添加信任证书成功，不需要替换trust文件
		Result:=false;
   end else
   begin
		//增量添加信任证书成功，需要替换trust文件
		//MsgBox('替换文件ret1！'+IntToStr(ret1), mbInformation, MB_OK);
		Result:=true;

    end

end;


//判断trust文件是否需要替换
function IsTrustNoModify2():Boolean;
begin

	if  ret2=1 then
	begin
		//增量添加信任证书成功，不需要替换trust文件
		//MsgBox('不替换文件ret2！'+IntToStr(ret2), mbInformation, MB_OK);
		Result:=false;
   end else
   begin
		//增量添加信任证书成功，需要替换trust文件
		//MsgBox('替换文件ret2！'+IntToStr(ret2), mbInformation, MB_OK);
		Result:=true;

    end

end;