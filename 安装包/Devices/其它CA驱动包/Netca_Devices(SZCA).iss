; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通安全客户端兼容深圳CA插件"
#define NETCA "广东省电子商务认证有限公司"
#define DEVICES_APPVERSION "1.0.0"
#define SETUP_FILE_VERSION "1.0.0.2"
#define UID "5B64121E-05C1-49A7-8EF1-7D87024FAAD2"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{5B64121E-05C1-49A7-8EF1-7D87024FAAD2}
AppName={#DEVICES_APPNAME}
AppVersion={#SETUP_FILE_VERSION}
AppVerName={#DEVICES_APPVERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net
DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=Copyright 2019 @ NETCA.保留所有权利。
OutputBaseFilename=NETCA_Devices(SZCA)
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
chinesesimp.SetupAppTitle=网证通安全客户端兼容深圳CA插件
chinesesimp.SetupWindowTitle=网证通安全客户端兼容深圳CA插件
trad.SetupAppTitle=網證通安全客戶端兼容深圳CA插件
trad.SetupWindowTitle=網證通安全客戶端兼容深圳CA插件
eng.SetupAppTitle=NETCADevices_SZCA
eng.SetupWindowTitle=NETCADevices_SZCA
[Files]
;trust文件
Source: ..\..\..\..\..\统一介质管理工具\current\发布版\InnoSetup\Netca_Crypto\InnoSetupInstallOperator.dll; DestDir: {tmp}; Flags: dontcopy solidbreak
Source: ..\..\..\..\..\项目\公共资源类项目\深圳产权交易集团\SZCA\trust; DestDir: {tmp}; Flags: uninsrestartdelete ignoreversion
Source: ..\..\..\..\..\项目\公共资源类项目\深圳产权交易集团\SZCA\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete restartreplace ignoreversion; check: IsTrustNoModify1
Source: ..\..\..\..\..\项目\公共资源类项目\深圳产权交易集团\SZCA\trust; DestDir: {localappdata}\VirtualStore\ProgramData\NETCA\certs; Flags: uninsrestartdelete restartreplace ignoreversion; check: IsTrustNoModify2 and (not IsXp)


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
;Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: idstring; ValueData: vid_096E&pid_0309
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSM4; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: string; ValueName: SkfDllPath; ValueData: ShuttleCsp11_3000GM_SZCA.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: AES128ECB; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: AES128CBC; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: multisz; ValueName: FilterProcess; ValueData: KeyX.exe{break}netcakeyxserver.exe; Flags: uninsdeletekey; Check: IsWin64

;32位系统32位注册表
;注册表去除idstring，通过代码增量添加idstring里的vidpid
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: type; ValueData: $00000045; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: dword; ValueName: mustLgoin; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: signature; ValueData: OSYMwLiEWh3uiRzpFHA8TCpeAj5pyC/rwFSSk6QyIRVbWxUK8fW69Q8SCeeYNx1yiDg3b1zkiJxbYNeslcZ6pKe6ocozQgKCSQ2yBS02l2V4nYPXBvXjdzbvSs1vAJ1nSvWznQvhESqTGqmxw6pZrUV/1zborb/62DGtZO6Lygk=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\SKFManageProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
;Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice; ValueType: string; ValueName: idstring; ValueData: vid_096E&pid_0309
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSM3; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSM4; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: string; ValueName: SkfDllPath; ValueData: ShuttleCsp11_3000GM_SZCA.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSHA1; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: HasSHA256; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: AES128ECB; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: dword; ValueName: AES128CBC; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\SKFDevice\SZCA-1; ValueType: multisz; ValueName: FilterProcess; ValueData: KeyX.exe{break}netcakeyxserver.exe; Flags: uninsdeletekey; Check: not IsWin64

;证书链
;SZCA SM2 CA.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\SystemCertificates\CA\Certificates\689BE6929126EA39C7B346EB7A74EC18A24AC138; ValueType: binary; ValueName: Blob; ValueData: 04 00 00 00 01 00 00 00 10 00 00 00 09 00 59 21 13 06 dc 9f 49 4f 49 d3 80 25 8d 9d 0f 00 00 00 01 00 00 00 20 00 00 00 79 a3 f6 bd 2c a6 fb b3 cb cf 33 73 5d 32 6f fa 18 2f 68 6a 7e f7 da 83 77 bf e9 24 e2 8d c8 ab 14 00 00 00 01 00 00 00 14 00 00 00 8a 7b 46 5a ce 11 65 d8 53 b9 51 7a 42 ef 47 3d 0a 8c b8 e8 19 00 00 00 01 00 00 00 10 00 00 00 9c d5 48 7f d7 b9 83 d6 2f 7d 49 4f bb d1 0c 16 5c 00 00 00 01 00 00 00 04 00 00 00 00 01 00 00 18 00 00 00 01 00 00 00 10 00 00 00 e1 00 0d 36 17 21 6d 6b 58 90 25 f0 18 a2 b0 19 03 00 00 00 01 00 00 00 14 00 00 00 68 9b e6 92 91 26 ea 39 c7 b3 46 eb 7a 74 ec 18 a2 4a c1 38 20 00 00 00 01 00 00 00 db 02 00 00 30 82 02 d7 30 82 02 7b a0 03 02 01 02 02 10 39 bf 7c 1f 81 70 fd 01 d4 63 7e a7 26 70 85 d5 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 30 2e 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0f 30 0d 06 03 55 04 03 0c 06 52 4f 4f 54 43 41 30 1e 17 0d 31 33 30 37 32 38 30 37 33 35 34 30 5a 17 0d 33 33 30 37 32 33 30 37 33 35 34 30 5a 30 81 82 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 12 30 10 06 03 55 04 08 0c 09 47 75 61 6e 67 64 6f 6e 67 31 11 30 0f 06 03 55 04 07 0c 08 53 68 65 6e 7a 68 65 6e 31 27 30 25 06 03 55 04 0a 0c 1e 53 68 65 6e 5a 68 65 6e 20 43 65 72 74 69 66 69 63 61 74 65 20 41 75 74 68 6f 72 69 74 79 31 0d 30 0b 06 03 55 04 0b 0c 04 73 7a 63 61 31 14 30 12 06 03 55 04 03 0c 0b 53 5a 43 41 20 53 4d 32 20 43 41 30 59 30 13 06 07 2a 86 48 ce 3d 02 01 06 08 2a 81 1c cf 55 01 82 2d 03 42 00 04 cd 15 18 fc a6 6e 33 91 df 0e d7 13 26 31 45 1d 58 0d cc 22 cd 59 62 58 12 ed d9 dc 48 65 13 ac 5a 2e b5 75 97 d5 02 b4 33 7c 47 0c 13 40 88 09 45 4b 90 4e 81 51 b2 c5 bc a4 92 ed 86 0c ec 8e a3 82 01 22 30 82 01 1e 30 1f 06 03 55 1d 23 04 18 30 16 80 14 4c 32 b1 97 d9 33 1b c4 a6 05 c1 c6 e5 8b 62 5b f0 97 76 58 30 0f 06 03 55 1d 13 01 01 ff 04 05 30 03 01 01 ff 30 81 ba 06 03 55 1d 1f 04 81 b2 30 81 af 30 41 a0 3f a0 3d a4 3b 30 39 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0c 30 0a 06 03 55 04 0b 0c 03 41 52 4c 31 0c 30 0a 06 03 55 04 03 0c 03 61 72 6c 30 2a a0 28 a0 26 86 24 68 74 74 70 3a 2f 2f 77 77 77 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 2f 61 72 6c 2f 61 72 6c 2e 63 72 6c 30 3e a0 3c a0 3a 86 38 6c 64 61 70 3a 2f 2f 6c 64 61 70 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 3a 33 38 39 2f 43 4e 3d 61 72 6c 2c 4f 55 3d 41 52 4c 2c 4f 3d 4e 52 43 41 43 2c 43 3d 43 4e 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 1d 06 03 55 1d 0e 04 16 04 14 8a 7b 46 5a ce 11 65 d8 53 b9 51 7a 42 ef 47 3d 0a 8c b8 e8 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 03 48 00 30 45 02 21 00 fe 0a c2 a9 e1 b2 16 67 09 45 ef 78 ae 0c a8 ed 4c 81 ef a8 6c 80 f0 aa cd 18 1c 45 a5 32 14 d2 02 20 09 e7 60 c1 cf 83 93 07 fc 0a 39 58 f2 2b 56 c0 92 f2 63 53 ea a4 16 37 ad 3e 8d 59 41 d6 e3 27
Root: HKLM; SubKey: SOFTWARE\WOW6432Node\Microsoft\SystemCertificates\CA\Certificates\689BE6929126EA39C7B346EB7A74EC18A24AC138; ValueType: binary; ValueName: Blob; ValueData: 04 00 00 00 01 00 00 00 10 00 00 00 09 00 59 21 13 06 dc 9f 49 4f 49 d3 80 25 8d 9d 0f 00 00 00 01 00 00 00 20 00 00 00 79 a3 f6 bd 2c a6 fb b3 cb cf 33 73 5d 32 6f fa 18 2f 68 6a 7e f7 da 83 77 bf e9 24 e2 8d c8 ab 14 00 00 00 01 00 00 00 14 00 00 00 8a 7b 46 5a ce 11 65 d8 53 b9 51 7a 42 ef 47 3d 0a 8c b8 e8 19 00 00 00 01 00 00 00 10 00 00 00 9c d5 48 7f d7 b9 83 d6 2f 7d 49 4f bb d1 0c 16 5c 00 00 00 01 00 00 00 04 00 00 00 00 01 00 00 18 00 00 00 01 00 00 00 10 00 00 00 e1 00 0d 36 17 21 6d 6b 58 90 25 f0 18 a2 b0 19 03 00 00 00 01 00 00 00 14 00 00 00 68 9b e6 92 91 26 ea 39 c7 b3 46 eb 7a 74 ec 18 a2 4a c1 38 20 00 00 00 01 00 00 00 db 02 00 00 30 82 02 d7 30 82 02 7b a0 03 02 01 02 02 10 39 bf 7c 1f 81 70 fd 01 d4 63 7e a7 26 70 85 d5 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 30 2e 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0f 30 0d 06 03 55 04 03 0c 06 52 4f 4f 54 43 41 30 1e 17 0d 31 33 30 37 32 38 30 37 33 35 34 30 5a 17 0d 33 33 30 37 32 33 30 37 33 35 34 30 5a 30 81 82 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 12 30 10 06 03 55 04 08 0c 09 47 75 61 6e 67 64 6f 6e 67 31 11 30 0f 06 03 55 04 07 0c 08 53 68 65 6e 7a 68 65 6e 31 27 30 25 06 03 55 04 0a 0c 1e 53 68 65 6e 5a 68 65 6e 20 43 65 72 74 69 66 69 63 61 74 65 20 41 75 74 68 6f 72 69 74 79 31 0d 30 0b 06 03 55 04 0b 0c 04 73 7a 63 61 31 14 30 12 06 03 55 04 03 0c 0b 53 5a 43 41 20 53 4d 32 20 43 41 30 59 30 13 06 07 2a 86 48 ce 3d 02 01 06 08 2a 81 1c cf 55 01 82 2d 03 42 00 04 cd 15 18 fc a6 6e 33 91 df 0e d7 13 26 31 45 1d 58 0d cc 22 cd 59 62 58 12 ed d9 dc 48 65 13 ac 5a 2e b5 75 97 d5 02 b4 33 7c 47 0c 13 40 88 09 45 4b 90 4e 81 51 b2 c5 bc a4 92 ed 86 0c ec 8e a3 82 01 22 30 82 01 1e 30 1f 06 03 55 1d 23 04 18 30 16 80 14 4c 32 b1 97 d9 33 1b c4 a6 05 c1 c6 e5 8b 62 5b f0 97 76 58 30 0f 06 03 55 1d 13 01 01 ff 04 05 30 03 01 01 ff 30 81 ba 06 03 55 1d 1f 04 81 b2 30 81 af 30 41 a0 3f a0 3d a4 3b 30 39 31 0b 30 09 06 03 55 04 06 13 02 43 4e 31 0e 30 0c 06 03 55 04 0a 0c 05 4e 52 43 41 43 31 0c 30 0a 06 03 55 04 0b 0c 03 41 52 4c 31 0c 30 0a 06 03 55 04 03 0c 03 61 72 6c 30 2a a0 28 a0 26 86 24 68 74 74 70 3a 2f 2f 77 77 77 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 2f 61 72 6c 2f 61 72 6c 2e 63 72 6c 30 3e a0 3c a0 3a 86 38 6c 64 61 70 3a 2f 2f 6c 64 61 70 2e 72 6f 6f 74 63 61 2e 67 6f 76 2e 63 6e 3a 33 38 39 2f 43 4e 3d 61 72 6c 2c 4f 55 3d 41 52 4c 2c 4f 3d 4e 52 43 41 43 2c 43 3d 43 4e 30 0e 06 03 55 1d 0f 01 01 ff 04 04 03 02 01 06 30 1d 06 03 55 1d 0e 04 16 04 14 8a 7b 46 5a ce 11 65 d8 53 b9 51 7a 42 ef 47 3d 0a 8c b8 e8 30 0c 06 08 2a 81 1c cf 55 01 83 75 05 00 03 48 00 30 45 02 21 00 fe 0a c2 a9 e1 b2 16 67 09 45 ef 78 ae 0c a8 ed 4c 81 ef a8 6c 80 f0 aa cd 18 1c 45 a5 32 14 d2 02 20 09 e7 60 c1 cf 83 93 07 fc 0a 39 58 f2 2b 56 c0 92 f2 63 53 ea a4 16 37 ad 3e 8d 59 41 d6 e3 27

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
	newVid[0] := 'vid_096E&pid_0309';
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
