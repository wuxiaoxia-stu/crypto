; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{088B0B78-1430-4C83-A980-4EE3EA7B93E5}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

OutputBaseFilename=NETCA_Devices_WuGang
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(���)
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����
chinesesimp.SetupWindowTitle=��֤ͨ�豸����

trad.SetupAppTitle=�W�Cͨ�O����
trad.SetupWindowTitle=�W�Cͨ�O����

eng.SetupAppTitle=NETCADevices
eng.SetupWindowTitle=NETCADevices
[Files]

;�豸DLL
;����˰ͨ��ΪCOS
Source: ..\..\winX86\�豸����\����˰ͨ��ΪCOS\EtaxHWEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����˰ͨ��ΪCOS\USBTOKENlib.dll; DestDir: {sys}
Source: ..\..\winX86\�豸����\����˰ͨ��ΪCOS\NetcaEtaxCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\..\winX86\�豸����\����˰ͨ��ΪCOS\NetcaEtaxCertificate.dll; DestDir: {sys}; Flags: uninsrestartdelete

;����SJK��key
Source: ..\..\winX86\�豸����\����SJK��Key\FMSJKEKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����SJK��Key\FM_SIC_DLL.dll; DestDir: {sys}; Flags: uninsrestartdelete

;����˰ͨ�˳�COS
Source: ..\..\winX86\�豸����\����˰ͨ�˳�COS\EtaxInspurEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����˰ͨ�˳�COS\GD_USBKEY_DLL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����˰ͨ�˳�COS\CmdDll.dll; DestDir: {sys}
Source: ..\..\winX86\�豸����\����˰ͨ�˳�COS\DEVICEIO.dll; DestDir: {sys}; Flags: uninsrestartdelete

;����SDKey
Source: ..\..\winX86\�豸����\����SDKey\HDMicroSDKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����SDKey\HD_Cryptoki.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\����SDKey\HD_Token.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����sdkey\x86\IIS_SPISmartDLL.dll; DestDir: {sys}; Flags: uninsrestartdelete


;΢��Epass2001
Source: ..\..\winX86\�豸����\΢��Epass2001\WeepalEpass2001Prov.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\΢��Epass2001\Weepalp11v211.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\΢��Epass2001\Weepalp11v211.sig; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\΢��Epass2001\Weepalp11v211_s.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\΢��Epass2001\FTATLForWBRJ.dll; DestDir: {sys}; Flags: uninsrestartdelete

;UIMKey
Source: ..\..\winX86\�豸����\UIMKey\UIMKeyP11.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\�豸����\UIMKey\UIMKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete


[Registry]
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI; ValueType: multisz; ValueName: SilentPinKeys; ValueData: FEITIAN ePassNG RSA Cryptographic Service Provider{break}EnterSafe ePass3003 CSP for WZT V1.0{break}HaiTai Cryptographic Service Provider{break}M&W eKey XCSP{break}M&W eKey XCSP V3; Flags: uninsdeletekey
;����SJK��key
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: string; ValueName: dllpath; ValueData: {app}\FMSJKEKeyProv.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: string; ValueName: signature; ValueData: OoL1Pbq4WESXLvZo19o8cpypkNiciKxcNOldOZRYOLa7q8MmC///ONq7A8l9Xj6QqsfrVgLsfGM4ydM9F+P3K1pHa7Pk9b4KEMbvnjAkBo5s39EIvk2yh40zsOOpuzWt1RNHDBGWarG24D1BFtBZJi55Aq5HD8+JD3eaXFrsxAU=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: dword; ValueName: type; ValueData: $00000024; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: multisz; ValueName: idstring; ValueData: Vid_ABCD&Pid_1000; Flags: uninsdeletekey
;����˰ͨ��ΪCOS
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: string; ValueName: dllpath; ValueData: {app}\EtaxHWEKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: string; ValueName: signature; ValueData: mGCEMfF6Ub2k4rAoP5qgfewqtjbVJm/DeJnWZCjju9r2VaRQhGX+c8wInww6JxIl7kPRbWxQZVtU3pMaC01Zg0beLmbi4sFz51YFEQwKyc/60IuA7BKkrBSKkdRHAHP8bPGmToauCfBZgyZlvt67DbFeR1fmvc3bEbaDS6q8EEE=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: dword; ValueName: type; ValueData: $0000001f; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: multisz; ValueName: idstring; ValueData: Vid_4612&Pid_04B4{break}Vid_05E3&Pid_0608; Flags: uninsdeletekey
;����˰ͨ�˳�COS
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: string; ValueName: dllpath; ValueData: {app}\EtaxInspurEKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: string; ValueName: signature; ValueData: OoL1Pbq4WESXLvZo19o8cpypkNiciKxcNOldOZRYOLa7q8MmC///ONq7A8l9Xj6QqsfrVgLsfGM4ydM9F+P3K1pHa7Pk9b4KEMbvnjAkBo5s39EIvk2yh40zsOOpuzWt1RNHDBGWarG24D1BFtBZJi55Aq5HD8+JD3eaXFrsxAU=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: dword; ValueName: type; ValueData: $00000025; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: multisz; ValueName: idstring; ValueData: Vid_ABCD&Pid_1000; Flags: uninsdeletekey
;����SDKey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {app}\HDMicroSDKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: nZ9JdYxbz/MDp3TzkJltwmN5cmXgU9Qo3FI+U0dscNtvhZXlqFOY4Mz6K4YYBGq9zQjzdsgt1mN2dCPt8BZZxpJPnm1sSWCvCkRrCCSmJaI/rAYpdkrT3TT9VRz1jhahkZ6fFPWWyhLW+AP2DfQdKFL8NkOagScX42I/kfstmOo=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletekey
;΢��Epass2001
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: dllpath; ValueData: {app}\WeepalEpass2001Prov.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: signature; ValueData: htAxhzPnU7UM71jKvr+v6qx+zlGmQmUomQ3dOnNS8kjTXwEhF4dJmwooi/fQqmWckE8jAtQJnVwbsBSRKtdzQRP+3LWeYo/PBP9jUoCcNyl8sOSOxdzxz4/09JhEr3Ldu3EHWC3oBK7IjEy3aTEwBb5ASl59ExW/olmGdC3fkvI=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: type; ValueData: $00000008; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0803; Flags: uninsdeletekey

;UIMע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUIM; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUIM; ValueType: string; ValueName: signature; ValueData: o8HVFu8+WDLznPorhmyrflQsJwax9M0PwVn+JZAuVe4hVSifHZaKptFiiVPJvzqzFKfu8UjRANgAq+VcSglwCUTBou22tC89Y/BgtcSoZBMW/oc3coBsc/4si4g42wVCkPmZOaE63j15ZNg+DSwNuweelyZz6pdqw/kR3/AV5A4=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUIM; ValueType: string; ValueName: class; ValueData: ICCard; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUIM; ValueType: dword; ValueName: type; ValueData: $0000045b; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUIM; ValueType: multisz; ValueName: idstring; ValueData: Vid_04E6&Pid_5116; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyUIM; ValueType: string; ValueName: dllpath; ValueData: {app}\UIMKeyProv.dll; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
