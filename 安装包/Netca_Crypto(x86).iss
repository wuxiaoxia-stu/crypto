; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define CRYPTO_APPNAME "��֤ͨ��ȫ�м��"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define CRYPTO_APPVERSION "1.7"
#define SETUP_FILE_VERSION "1.7.2.3"
#define NPNETCAPKI_VERSION "1.0.0.1"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{A0B399CD-984F-41F2-9A5D-E3BF7A54E696}
AppName={#CRYPTO_APPNAME}
AppVersion={#CRYPTO_APPVERSION}
AppVerName={#CRYPTO_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Crypto

AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Crypto_x86
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#CRYPTO_APPNAME}32λ
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
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

eng.SetupAppTitle=NETCACrypto
eng.SetupWindowTitle=NETCACrypto

[Files]
;��֤ͨ��ȫ�м������ļ�
Source: ..\winX86\��̬��\Crypto\NETCA_USBKeySvr.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_URL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_UTIL.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_ASN1.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_XML.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_LOG.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\libgmp-10.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI_RES_2052.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI_RES_1028.DLL; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_UI_RES_1033.DLL; DestDir: {sys}; Flags: uninsrestartdelete

;COM
Source: ..\winX86\��̬��\COM\NetcaPkiCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\winX86\��̬��\COM\NETCA_XMLCOM.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete
Source: ..\winX86\��̬��\Chrome\npnetcapki.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\COM\NetcaRAClientCom.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;CSPǩ���ļ�
Source: ..\winX86\CSP\NETCA_CRYPTO_RSACSP.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\NETCA_CRYPTO_RSACSP_IMP.dll; DestDir: {sys}; Flags: uninsrestartdelete

;SecuInter
Source: ..\..\..\SecuInter\4.1\x86\SecuInter.dll; DestDir: {sys}; Flags: regserver uninsrestartdelete

;trust�ļ�
Source: ..\��ȫ����\trust; DestDir: {commonappdata}\NETCA\certs; Flags: uninsrestartdelete
Source: ..\winX86\��̬��\Crypto\record_file_crypto.ini; DestDir: {pf}\NETCA\keyx; Flags: uninsrestartdelete

[Registry]
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: string; ValueName: IMAGE PATH; ValueData: {sys}\NETCA_CRYPTO_RSACSP.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: binary; ValueName: SIGNATURE; ValueData: 83 7d df a4 7d b0 6a c3 f1 e3 49 16 30 f4 e2 be 07 23 ee 70 3b fb 60 13 8c 3a 63 8e 64 93 df 99 b6 69 f8 0e 79 ea f3 46 1e 97 2f f2 a6 f7 22 43 36 56 04 7c e3 e1 cb 94 e9 1e 66 fa 24 bf 3b 1a df de 3d 5f fc ff 54 c2 ca 3c 4f bc 57 7d 69 83 25 ac 72 43 41 ad a9 af b3 8f e8 c2 1d eb 4d 91 61 af 32 8b f7 44 5f f4 d5 de cb a4 2a cc 54 62 41 1e cf de dd 74 18 1a ad 8f d6 eb 0e 44 c9 6c 00 00 00 00 00 00 00 00; Flags: uninsdeletevalue
Root: HKLM; Subkey: SOFTWARE\Microsoft\Cryptography\Defaults\Provider\NETCA CRYPTO RSA Cryptographic Provider; ValueType: dword; ValueName: TYPE; ValueData: $00000001; Flags: uninsdeletekey

;npnetcapki.dll��ע���
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Description; ValueData: �м��Ӧ����Firefox�Ĳ��; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Path; ValueData: {app}\npnetcapki.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: ProductName; ValueData: npnetcapki; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Vendor; ValueData: NETCA; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\MozillaPlugins\npnetcapki; ValueType: string; ValueName: Version; ValueData: {#NPNETCAPKI_VERSION}; Flags: uninsdeletekey


[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
