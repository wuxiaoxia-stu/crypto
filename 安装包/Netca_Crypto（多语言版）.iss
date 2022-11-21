; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{9A7B68E0-AFBA-4361-80C7-72DD090ED45E}
AppName=NETCACrypto
AppVersion=1.5.0.2
AppVerName=NETCACrypto 1.5.0.2
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Crypto
ShowLanguageDialog=auto
OutputBaseFilename=NETCA_Crypto_Setup
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true


VersionInfoVersion =1.5.0.2

ArchitecturesAllowed=x86 x64 ia64
;不提示重启
UninstallRestartComputer =no

;不在"添加/删除程序"面板中显示卸载
;CreateUninstallRegKey =no

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl


[Files]
Source: ..\动态库\NETCA_USBKeySvr.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_RSACSP_IMP.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI_RES_2052.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_URL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_UTIL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_ASN1.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_XML.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\netca_libxml2.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\COM\NetcaPkiCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\CSP签名文件\NETCA_CRYPTO_RSACSP.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\安全环境\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_LOG.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\libgmp-10.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI_RES_1028.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\动态库\NETCA_CRYPTO_UI_RES_1033.DLL; DestDir: {sys}; Flags: uninsrestartdelete

;常用的设备DLL
Source: ..\动态库\公司证书签名设备dll\飞天3003\Epass3003Prov.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\动态库\公司证书签名设备dll\海泰\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\动态库\公司证书签名设备dll\明华2版\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\动态库\公司证书签名设备dll\明华3版\MWEKeyV3Prov.dll; DestDir: {app}; Flags: uninsrestartdelete





[Registry]
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: string; ValueName: IMAGE PATH; ValueData: {app}\NETCA_CRYPTO_RSACSP.dll
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: binary; ValueName: SIGNATURE; ValueData: 83 7d df a4 7d b0 6a c3 f1 e3 49 16 30 f4 e2 be 07 23 ee 70 3b fb 60 13 8c 3a 63 8e 64 93 df 99 b6 69 f8 0e 79 ea f3 46 1e 97 2f f2 a6 f7 22 43 36 56 04 7c e3 e1 cb 94 e9 1e 66 fa 24 bf 3b 1a df de 3d 5f fc ff 54 c2 ca 3c 4f bc 57 7d 69 83 25 ac 72 43 41 ad a9 af b3 8f e8 c2 1d eb 4d 91 61 af 32 8b f7 44 5f f4 d5 de cb a4 2a cc 54 62 41 1e cf de dd 74 18 1a ad 8f d6 eb 0e 44 c9 6c 00 00 00 00 00 00 00 00; Flags: uninsdeletevalue
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: dword; ValueName: TYPE; ValueData: $1

Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {app}\Epass3003Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: OoL1Pbq4WESXLvZo19o8cpypkNiciKxcNOldOZRYOLa7q8MmC///ONq7A8l9Xj6QqsfrVgLsfGM4ydM9F+P3K1pHa7Pk9b4KEMbvnjAkBo5s39EIvk2yh40zsOOpuzWt1RNHDBGWarG24D1BFtBZJi55Aq5HD8+JD3eaXFrsxAU=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey

Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV3Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: lxtQMuwFAuyRlypBd92p1fsKCA/3fGsTIik/YzvviIrDz+HpxbWwv6Ir4x+P882YzPu0lnt3QvxdIYSUJeevYhgKj6W8qvQ7kXm2RpVgnR7fBrUKZf6w2BmLXyAYqJVVd3OPdl7ZWRzGVzdScnxtOBVXK7RiXKPN0d2Fkqz5Flk=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: 00000006; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey

Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV2Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: type; ValueData: 00000002; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey

Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {app}\HTEKey.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: G8crgHKKB9D93apERnELDQJQP49dnF7kQAJbAsXoHc9zLwM1ZtJdlZrR8LeVxbhbLKogKw2zrYz5dShiu6NkDtYpqzXykWIZeFeZhUkOvqygwqWOZnPK8DzysRsdoY4jFY5yoU6NNh4GpMGKYDyennshHlup4OF8hL53SzJwyFQ=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
