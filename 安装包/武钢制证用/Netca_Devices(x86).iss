; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define DEVICES_APPNAME "网证通设备驱动"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{088B0B78-1430-4C83-A980-4EE3EA7B93E5}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=广东省电子商务认证有限公司
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

OutputBaseFilename=NETCA_Devices_WuGang
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}(武钢)
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

;设备DLL
;天翼税通华为COS
Source: ..\..\winX86\设备驱动\天翼税通华为COS\EtaxHWEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\天翼税通华为COS\USBTOKENlib.dll; DestDir: {sys}
Source: ..\..\winX86\设备驱动\天翼税通华为COS\NetcaEtaxCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\..\winX86\设备驱动\天翼税通华为COS\NetcaEtaxCertificate.dll; DestDir: {sys}; Flags: uninsrestartdelete

;渔翁SJK的key
Source: ..\..\winX86\设备驱动\渔翁SJK的Key\FMSJKEKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\渔翁SJK的Key\FM_SIC_DLL.dll; DestDir: {sys}; Flags: uninsrestartdelete

;天翼税通浪潮COS
Source: ..\..\winX86\设备驱动\天翼税通浪潮COS\EtaxInspurEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\天翼税通浪潮COS\GD_USBKEY_DLL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\天翼税通浪潮COS\CmdDll.dll; DestDir: {sys}
Source: ..\..\winX86\设备驱动\天翼税通浪潮COS\DEVICEIO.dll; DestDir: {sys}; Flags: uninsrestartdelete

;华大SDKey
Source: ..\..\winX86\设备驱动\华大SDKey\HDMicroSDKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\华大SDKey\HD_Cryptoki.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\华大SDKey\HD_Token.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\..\证书介质\驱动及开发包\华大sdkey\x86\IIS_SPISmartDLL.dll; DestDir: {sys}; Flags: uninsrestartdelete


;微柏Epass2001
Source: ..\..\winX86\设备驱动\微柏Epass2001\WeepalEpass2001Prov.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\微柏Epass2001\Weepalp11v211.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\微柏Epass2001\Weepalp11v211.sig; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\微柏Epass2001\Weepalp11v211_s.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\微柏Epass2001\FTATLForWBRJ.dll; DestDir: {sys}; Flags: uninsrestartdelete

;UIMKey
Source: ..\..\winX86\设备驱动\UIMKey\UIMKeyP11.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\winX86\设备驱动\UIMKey\UIMKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete


[Registry]
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI; ValueType: multisz; ValueName: SilentPinKeys; ValueData: FEITIAN ePassNG RSA Cryptographic Service Provider{break}EnterSafe ePass3003 CSP for WZT V1.0{break}HaiTai Cryptographic Service Provider{break}M&W eKey XCSP{break}M&W eKey XCSP V3; Flags: uninsdeletekey
;渔翁SJK的key
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: string; ValueName: dllpath; ValueData: {app}\FMSJKEKeyProv.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: string; ValueName: signature; ValueData: OoL1Pbq4WESXLvZo19o8cpypkNiciKxcNOldOZRYOLa7q8MmC///ONq7A8l9Xj6QqsfrVgLsfGM4ydM9F+P3K1pHa7Pk9b4KEMbvnjAkBo5s39EIvk2yh40zsOOpuzWt1RNHDBGWarG24D1BFtBZJi55Aq5HD8+JD3eaXFrsxAU=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: dword; ValueName: type; ValueData: $00000024; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFMSJK; ValueType: multisz; ValueName: idstring; ValueData: Vid_ABCD&Pid_1000; Flags: uninsdeletekey
;天翼税通华为COS
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: string; ValueName: dllpath; ValueData: {app}\EtaxHWEKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: string; ValueName: signature; ValueData: mGCEMfF6Ub2k4rAoP5qgfewqtjbVJm/DeJnWZCjju9r2VaRQhGX+c8wInww6JxIl7kPRbWxQZVtU3pMaC01Zg0beLmbi4sFz51YFEQwKyc/60IuA7BKkrBSKkdRHAHP8bPGmToauCfBZgyZlvt67DbFeR1fmvc3bEbaDS6q8EEE=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: dword; ValueName: type; ValueData: $0000001f; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHWETax; ValueType: multisz; ValueName: idstring; ValueData: Vid_4612&Pid_04B4{break}Vid_05E3&Pid_0608; Flags: uninsdeletekey
;天翼税通浪潮COS
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: string; ValueName: dllpath; ValueData: {app}\EtaxInspurEKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: string; ValueName: signature; ValueData: OoL1Pbq4WESXLvZo19o8cpypkNiciKxcNOldOZRYOLa7q8MmC///ONq7A8l9Xj6QqsfrVgLsfGM4ydM9F+P3K1pHa7Pk9b4KEMbvnjAkBo5s39EIvk2yh40zsOOpuzWt1RNHDBGWarG24D1BFtBZJi55Aq5HD8+JD3eaXFrsxAU=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: dword; ValueName: type; ValueData: $00000025; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyInspurETax; ValueType: multisz; ValueName: idstring; ValueData: Vid_ABCD&Pid_1000; Flags: uninsdeletekey
;华大SDKey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: dllpath; ValueData: {app}\HDMicroSDKey.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: signature; ValueData: nZ9JdYxbz/MDp3TzkJltwmN5cmXgU9Qo3FI+U0dscNtvhZXlqFOY4Mz6K4YYBGq9zQjzdsgt1mN2dCPt8BZZxpJPnm1sSWCvCkRrCCSmJaI/rAYpdkrT3TT9VRz1jhahkZ6fFPWWyhLW+AP2DfQdKFL8NkOagScX42I/kfstmOo=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: string; ValueName: class; ValueData: COM; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: dword; ValueName: type; ValueData: $00000023; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHDTF; ValueType: multisz; ValueName: idstring; ValueData: Vid_05E3&Pid_0736; Flags: uninsdeletekey
;微柏Epass2001
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: dllpath; ValueData: {app}\WeepalEpass2001Prov.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: signature; ValueData: htAxhzPnU7UM71jKvr+v6qx+zlGmQmUomQ3dOnNS8kjTXwEhF4dJmwooi/fQqmWckE8jAtQJnVwbsBSRKtdzQRP+3LWeYo/PBP9jUoCcNyl8sOSOxdzxz4/09JhEr3Ldu3EHWC3oBK7IjEy3aTEwBb5ASl59ExW/olmGdC3fkvI=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: dword; ValueName: type; ValueData: $00000008; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyWeepal; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0803; Flags: uninsdeletekey

;UIM注册表
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
