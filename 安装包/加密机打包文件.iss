; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define SETUP_APPNAME "���ܻ����ð�װ��"
#define SETUP_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.1"


[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{92EBD7A1-9684-4800-8F72-1276800BE751}
AppName={#SETUP_APPNAME}
AppVersion={#SETUP_APPVERSION}
AppVerName={#SETUP_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices

AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename={#SETUP_APPNAME}
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#SETUP_APPNAME}
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
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
chinesesimp.SetupAppTitle=���ܻ����ð�װ��
chinesesimp.SetupWindowTitle=���ܻ����ð�װ��

trad.SetupAppTitle=���ܻ����ð�װ��
trad.SetupWindowTitle=���ܻ����ð�װ��

eng.SetupAppTitle=NETCACrypto
eng.SetupWindowTitle=NETCACrypto

[Files]
;�ð�SJJ0929���ܻ��豸�ļ�
;32λϵͳ�ð�ECC���ܻ�32λ�ļ�
Source: ..\winX86\�豸����\�ð�ECC���ܻ�\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ0929
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\sdk\Windows\32\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ0929
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ0929

;64λϵͳ�ð����ܻ�64λ�ļ�
Source: ..\winX64\�豸����\�ð�ECC���ܻ�\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\sdk\Windows\64\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929

;64λϵͳ�ð����ܻ�32λ�ļ�
Source: ..\winX86\�豸����\�ð�ECC���ܻ�\SJJ0929Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\sdk\Windows\32\SJJ0929_dtcsp.dll; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\SJJ0929_dtcrypt.ini; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ0929

;�ð�SJY05B���ܻ��豸�ļ�
;32λϵͳ�ð����ܻ�32λ�ļ�
Source: ..\winX86\�豸����\�ð�ECC���ܻ�\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJY05B
Source: ..\..\..\֤�����\������������\�ð�\Windows\32\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJY05B
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJY05B

;64λϵͳ�ð����ܻ�64λ�ļ�
Source: ..\winX64\�豸����\�ð�ECC���ܻ�\SJJ0929Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\֤�����\������������\�ð�\Windows\64\SJJ0929_dtcsp.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\SJJ0929_dtcrypt.ini; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B

;64λϵͳ�ð����ܻ�32λ�ļ�
Source: ..\winX86\�豸����\�ð�ECC���ܻ�\SJJ0929Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\֤�����\������������\�ð�\Windows\32\SJJ0929_dtcsp.dll; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B
Source: ..\..\..\֤�����\������������\�ð�ECC���ܻ�\SJJ0929_dtcrypt.ini; DestDir: {syswow64}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJY05B

;�ջ����ܻ�SJJ1011�豸�ļ�
;32λϵͳ32λ�ļ�
Source: ..\winX86\�豸����\�ջ����ܻ�\PHSJJ1011Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ1011
Source: ..\..\..\֤�����\������������\�Ϻ��ջ����ܻ�\20131206�ͻ�������\����ͨ�ͻ�������\�ӿڿ�\win32\stdcall\ph_sdf.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ1011
Source: ..\..\..\֤�����\������������\�Ϻ��ջ����ܻ�\module.conf; DestDir: {pf}\phgcs; Flags: uninsrestartdelete; Check: not IsWin64; Components: SJJ1011

;64λϵͳ64λ�ļ�
Source: ..\winX64\�豸����\�ջ����ܻ�\PHSJJ1011Prov.dll; DestDir: {app}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\֤�����\������������\�Ϻ��ջ����ܻ�\20131206�ͻ�������\����ͨ�ͻ�������\�ӿڿ�\win64\stdcall\ph_sdf.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\֤�����\������������\�Ϻ��ջ����ܻ�\module.conf; DestDir: {pf}\phgcs; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011

;64λϵͳ32λ�ļ�
Source: ..\winX86\�豸����\�ջ����ܻ�\PHSJJ1011Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\֤�����\������������\�Ϻ��ջ����ܻ�\20131206�ͻ�������\����ͨ�ͻ�������\�ӿڿ�\win32\stdcall\ph_sdf.dll; DestDir: {sys}; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: ..\..\..\֤�����\������������\�Ϻ��ջ����ܻ�\module.conf; DestDir: {pf32}\phgcs; Flags: uninsrestartdelete; Check: IsWin64; Components: SJJ1011
Source: Readme.txt; DestDir: {app}; Flags: isreadme

[Registry]
;�ð�SJJ0929���ܻ�ע���
;32λϵͳע���ð�ECC32
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
;64λϵͳע���ð�ECC64λע���
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

;64λϵͳע���ð�ECC32λע���
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

;�ð�SJY05B���ܻ��豸ע���
;32λϵͳע���32
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

;64λϵͳע���64
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

;64λϵͳע���32
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

;�ջ����ܻ�ע���
;32λϵͳע���32
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: class; ValueData: NETWORK; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: type; ValueData: $00000067; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: signature; ValueData: FrXYYmG8wHBXJ8eZdrSK/JgxvUkeKbiOssysS5Md68/UY93gEyLsE+CTnOm8RaXO/v+LCfdoqNCrGacDWFw4ljVJ++Lzd0ayASmJWDn0U7yT3+bccySXZAgt4mnopHRnaUOl/FCv78nw0jXdv70qGBw3aFd6E3WLItsGfpAx6QQ=; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: KeyPairStatus; ValueData: 0555555555566666666666656565261561661166660000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSM1; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSSF33; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: HasSMS4; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: ECB2CTR; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: MultiDevice; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: DisplayName; ValueData: �ջ����ܻ�; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: Server; ValueData: $00000001; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: NoCert; ValueData: $00000000; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\PHSJJ1011Prov.dll; Flags: uninsdeletevalue; Check: not IsWin64; Components: SJJ1011
;64λϵͳע���64
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
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: DisplayName; ValueData: �ջ����ܻ�; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: Server; ValueData: $00000001; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: NoCert; ValueData: $00000000; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\PHSJJ1011Prov.dll; Flags: uninsdeletevalue; Check: IsWin64; Components: SJJ1011
;64λϵͳע���32
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
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: DisplayName; ValueData: �ջ����ܻ�; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: Server; ValueData: $00000001; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: dword; ValueName: NoCert; ValueData: $00000000; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\PHSJJ1011; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\PHSJJ1011Prov.dll; Flags: uninsdeletekey; Check: IsWin64; Components: SJJ1011



[Components]
Name: SJJ0929; Description: �ð����ܻ�SJJ0929; Flags: checkablealone; Types: compact
Name: SJY05B; Description: �ð����ܻ�SJY05B; Flags: checkablealone; Types: compact
Name: SJJ1011; Description: �ջ����ܻ�SJJ1011; Flags: checkablealone; Types: compact

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
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_JMJ';
// Ӧ�ó������ƣ��� [SEUTP] �ε� AppName ����һ�£�����Ӧ�޸ģ�
MyAppName := '92EBD7A1-9684-4800-8F72-1276800BE751';
// ����������ж���ļ�
uninspath:= ExtractFilePath(ExpandConstant('{uninstallexe}'));
uninsname:= Copy(ExtractFileName(ExpandConstant('{uninstallexe}')),1,8);
RenameFile(uninspath + uninsname + '.exe', uninspath + NewUninsName + '.exe');
RenameFile(uninspath + uninsname + '.dat', uninspath + NewUninsName + '.dat');
// �����޸���Ӧ��ע�������
if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1') then
begin
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE/Microsoft/Windows/CurrentVersion/Uninstall/' + MyAppName + '_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
end;
end;
end;
