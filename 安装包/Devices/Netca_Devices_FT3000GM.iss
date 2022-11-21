; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FT3000GM(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "4.1.0"
#define SETUP_FILE_VERSION "4.1.0.17"
#define UID  "02B0D586-F717-4090-B6FB-44A972E7DEF5"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{02B0D586-F717-4090-B6FB-44A972E7DEF5}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FT3000GM)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoProductName={#DEVICES_APPNAME}
UninstallLogMode=overwrite
PrivilegesRequired=admin
CreateUninstallRegKey=false
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����
VersionInfoProductVersion={#DEVICES_APPVERSION}


[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FT3000GM
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FT3000GM

trad.SetupAppTitle=�W�Cͨ�O����_FT3000GM
trad.SetupWindowTitle=�W�Cͨ�O����_FT3000GM

eng.SetupAppTitle=NETCADevices_FT3000GM
eng.SetupWindowTitle=NETCADevices_FT3000GM

[Files]
;�豸dll(32λϵͳ32λ�ļ�)
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll_device.ini; DestDir: {app}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

;�豸dll(64λϵͳ64λ�ļ�)
Source: ..\..\winX64\�豸����\����3000GM\FT3000GMProv.dll; DestDir: {app}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����3000GM\FT3000GMProv.dll_device.ini; DestDir: {app}; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64

;�豸dll(64λϵͳ��32λ�ļ�)
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;��������ļ�(32λϵͳ32λ�ļ���64λϵͳ��64λ�ļ�)
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����3000GM\FT3000GMProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64

[Registry]
;32λע���32λϵͳ-FT3000_USB_TOKEN_3000GM.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Check: not IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: not IsWin64; Flags: uninsdeletekey
;32λע���64λϵͳ-FT3000_USB_TOKEN_3000GM.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Check: IsWin64; Flags: uninsdeletekey
;32λע���32λϵͳ-NETCAKeyFT3000GM.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: pPQrRDin+6RCptO+2BsuDXA4FARanJ0vIHlTegFuOM6pELKMUdcyd10vUcs5rAvETwd7Lol/PDvx5QhGAwyNg0kYr9CZMH1b9Fu+BjB2uyEkzoPGIUDyO/hherogGOKxMLLpzft/5RAmPLcZgfDI+eLcUZhziE7pxAuN0O84TWM=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317{break}Vid_096E&Pid_0316{break}Vid_096E&Pid_0314{break}Vid_096E&Pid_031A{break}Vid_096E&Pid_031F{break}Vid_096E&Pid_0322; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM4; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM\CCID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0316{break}Vid_096E&Pid_0314{break}Vid_096E&Pid_031F; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM\HID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317{break}Vid_096E&Pid_031A{break}Vid_096E&Pid_0322; Flags: uninsdeletekey; Check: not IsWin64


;32λע���64λϵͳ-NETCAKeyFT3000GM.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: pPQrRDin+6RCptO+2BsuDXA4FARanJ0vIHlTegFuOM6pELKMUdcyd10vUcs5rAvETwd7Lol/PDvx5QhGAwyNg0kYr9CZMH1b9Fu+BjB2uyEkzoPGIUDyO/hherogGOKxMLLpzft/5RAmPLcZgfDI+eLcUZhziE7pxAuN0O84TWM=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317{break}Vid_096E&Pid_0316{break}Vid_096E&Pid_0314{break}Vid_096E&Pid_031A{break}Vid_096E&Pid_031F{break}Vid_096E&Pid_0322; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM4; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM\CCID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0316{break}Vid_096E&Pid_0314{break}Vid_096E&Pid_031F; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3000GM\HID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317{break}Vid_096E&Pid_031A{break}Vid_096E&Pid_0322; Flags: uninsdeletekey; Check: IsWin64
;32λע���32λϵͳ-Netca_3000GM_ATR.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: not IsWin64
;32λע���64λϵͳ-Netca_3000GM_ATR.reg
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: IsWin64
;64λע���64λϵͳ-FT3000_USB_TOKEN_3000GM.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 0; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 0; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 1; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 1; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 2; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 2; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 3; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 3; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 4; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 4; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 5; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 5; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 6; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 6; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: string; ValueName: Device; ValueData: FT USB TOKEN 3000GM 7; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\Readers\FT USB TOKEN 3000GM 7; ValueType: multisz; ValueName: Groups; ValueData: SCard$DefaultReaders{break}SCard$NETCA; Flags: uninsdeletekey; Check: IsWin64


;��64λע���64λϵͳ-NETCAKeyFT3000GM.reg
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\FT3000GMProv.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: signature; ValueData: I6EG5tK3VRjKcKmVceFHCknAUseUqSGG8vD+Nm77m4MyCY/5VXEvpw5d0NMI5niWJSfST9kl74K0uJ/TzfVZAZzSLtvAiEroaxlyaRHgNC4KFdg+Eh/sM667EXBdb6xlymQrX7akvkTCpPntyXyK1DjnCE4g1QJkUqhK3GEkFB4=; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: type; ValueData: $0000002f; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317{break}Vid_096E&Pid_0316{break}Vid_096E&Pid_0314{break}Vid_096E&Pid_031A{break}Vid_096E&Pid_031F{break}Vid_096E&Pid_0322; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM3; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSM4; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM\CCID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0316{break}Vid_096E&Pid_0314{break}Vid_096E&Pid_031F; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM\HID; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0317{break}Vid_096E&Pid_031A{break}Vid_096E&Pid_0322; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3000GM; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64

;64λע���64λϵͳ-Netca_3000GM_ATR.reg
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: string; ValueName: Crypto Provider; ValueData: Microsoft Base Cryptographic Provider v1.0; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATR; ValueData: 3b 9f 95 81 31 fe 9f 00 66 47 44 05 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Calais\SmartCards\ePass3000GM; ValueType: binary; ValueName: ATRMask; ValueData: ff ff ff ff ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00 00 00 00; Flags: uninsdeletekey; Check: IsWin64



[InstallDelete]
Name: {app}\Unins_FT3000GM.dat; Type: files
Name: {app}\Unins_FT3000GM.exe; Type: files
Name: {app}\unins000.dat; Type: files
Name: {app}\unins000.exe; Type: files
Name: {app}\unins001.dat; Type: files
Name: {app}\unins001.exe; Type: files
Name: {app}\unins002.dat; Type: files
Name: {app}\unins002.exe; Type: files

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
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_FT3000GM';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
// ����������ж���ļ�
uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
// �����޸���Ӧ��ע�������
if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
begin
 //MsgBox('��⵽ϵͳ��Ҫ��', mbInformation, MB_OK);
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
//MsgBox('��⵽ϵͳ����', mbInformation, MB_OK);
RegDeleteKeyIncludingSubkeys(HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1');
end;
end;
end;
[_ISTool]
UseAbsolutePaths=false
