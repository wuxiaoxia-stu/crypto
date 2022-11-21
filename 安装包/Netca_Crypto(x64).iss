; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define CRYPTO_APPNAME "��֤ͨ��ȫ�м��"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define CRYPTO_APPVERSION "1.7"
#define SETUP_FILE_VERSION "1.7.2.2"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{9F9912F4-A5A8-4F7C-968E-DC4E540A7F58}
AppName={#CRYPTO_APPNAME}
AppVersion={#CRYPTO_APPVERSION}
AppVerName={#CRYPTO_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher={#NETCA}
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf64}\NETCA\NETCA_Crypto
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Crypto_x64
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#CRYPTO_APPNAME}64λ
VersionInfoVersion ={#SETUP_FILE_VERSION}
UninstallDisplayName  ={#CRYPTO_APPNAME}(x64)

;ArchitecturesAllowed=x86 x64 ia64
ArchitecturesInstallIn64BitMode=x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
;CreateUninstallRegKey =no
ShowLanguageDialog=auto
VersionInfoCompany={#NETCA}

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ��ȫ�м��
chinesesimp.SetupWindowTitle=��֤ͨ��ȫ�м��

trad.SetupAppTitle=�W�Cͨ��ȫ���g��
trad.SetupWindowTitle=�W�Cͨ��ȫ���g��

eng.SetupAppTitle=NETCA_Crypto
eng.SetupWindowTitle=NETCA_Crypto

[Files]
Source: ..\winX64\��̬��\Crypto\libgmp-10.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_ASN1.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_CRYPTO.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_CRYPTO_UI.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI_RES_2052.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI_RES_1028.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI_RES_1033.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_LOG.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_URL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_USBKeySvr.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_UTIL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_XML.dll; DestDir: {sys}; Flags: uninsrestartdelete

;COM
Source: ..\winX64\��̬��\COM\NetcaPkiCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\winX64\��̬��\COM\NETCA_XMLCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;CSPǩ���ļ�
Source: ..\winX64\CSP\NETCA_CRYPTO_RSACSP.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\NETCA_CRYPTO_RSACSP_IMP.dll; DestDir: {sys}; Flags: uninsrestartdelete

; SecuInter
Source: ..\..\..\SecuInter\4.1\x64\SecuInter.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;��ȫ����
Source: ..\��ȫ����\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete
Source: ..\winX64\��̬��\Crypto\record_file_crypto.ini; DestDir: {pf64}\NETCA\keyx; Flags: uninsrestartdelete

[Registry]
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: string; ValueName: IMAGE PATH; ValueData: {app}\NETCA_CRYPTO_RSACSP.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: dword; ValueName: TYPE; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: binary; ValueName: SIGNATURE; ValueData: 56 7A 0B FA D6 66 51 FC 69 80 BE DA BC 9E E6 37 1D B4 D8 74 1D F5 61 39 9E 21 10  7A 8B BD FD F6 86 4B 67 F2 98 C6 0D 8C 90 A7 2E 9F 4D 0E 63 E0 B2 86 E4 EC 0D E5  2C CC 60 04 C8 A2 69 B8 C4 C2 78 1A 8E BD F0 D2 69 1F 8B F3 1C 2E 09 D1 0E AE  7B 15 47 D6 B9 CD AE 74 92 99 7C 97 BB 24 BD 90 F2 08 68 7C 14 0B C4 3F 0E 09 B9 9E B2 0E 78 0D A7 78 E2 2F 25 13 E0 94 DC 6A 76 B9 34 CB D2 9E 00 00 00 00 00 00 00 00; Flags: uninsdeletekey

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
