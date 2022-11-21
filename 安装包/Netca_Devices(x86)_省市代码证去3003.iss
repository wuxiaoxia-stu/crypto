; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.1.2"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{5A68E393-0038-473C-A3C0-6ED50F775CAB}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME} {#SETUP_FILE_VERSION}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#KEYX}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}32λ
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
;��������
Source: ..\..\..\֤�����\������������\����\NETCAKEY_MWV2V3.exe; DestDir: {app}; Flags: deleteafterinstall ignoreversion
Source: ..\..\..\֤�����\������������\����\MWTokenAPI.dll; DestDir: {sys}; Flags: restartreplace ignoreversion

;��̩����
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\GEControl.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\GECSP.dll; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\BKEY0404.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\BKEY0409.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\BKEY0804.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\BKEYLngIndex.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\GECSP.ini; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001\HTCloseCSP.exe; DestDir: {sys}\GECSP00001; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GEC00001.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\GECSP00001.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\HTCSPApi.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\HTCSPApi.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\HtPkcs11.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩\NETCAKEY_HT��װ���ļ�\NETCA_Win32\HtPkcs11.ini; DestDir: {sys}; Flags: uninsrestartdelete

;����3003

;�Ķ���
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����V1.4\32λϵͳ\system32\SJK1217API.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����V1.4\32λϵͳ\system32\SJK1217CFG.bin; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����V1.4\32λϵͳ\system32\SJK1217CSP.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����V1.4\32λϵͳ\system32\SJK1217CSPSi.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����V1.4\32λϵͳ\system32\SJK1217Drv00.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����V1.4\32λϵͳ\system32\SJK1217Pkcs.dll; DestDir: {sys}; Flags: uninsrestartdelete

;��̩SM2
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GEA20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GEC20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECFG20524.dat; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECN20524.dat; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECSP20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GECSP20524.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\GER20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\HTCSPApi20524.ini; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFAPI20524.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\SKFApi20524.lib; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\HKDriver.dll; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\HKDriver32.exe; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\HKeyEnum.sys; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\HKeyIFD.sys; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\HKeyUsb.sys; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\htfykey.cat; DestDir: {sys}\Driver; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\��̩SM2��Key\��̩sm2����2012-9-11\NETCA_Win32\Driver\HTFYKey.inf; DestDir: {sys}\Driver; Flags: uninsrestartdelete

;����SM2

;��˾��̬�豸DLL
Source: ..\winX86\�豸����\����2��\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\winX86\�豸����\����3��\MWEKeyV3Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\winX86\�豸����\��̩\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\�Ķ���\ESKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\��̩SM2��Key\HaitaiSM2Key.dll; DestDir: {app}; Flags: uninsrestartdelete

[Registry]
;����3��
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV3Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: lxtQMuwFAuyRlypBd92p1fsKCA/3fGsTIik/YzvviIrDz+HpxbWwv6Ir4x+P882YzPu0lnt3QvxdIYSUJeevYhgKj6W8qvQ7kXm2RpVgnR7fBrUKZf6w2BmLXyAYqJVVd3OPdl7ZWRzGVzdScnxtOBVXK7RiXKPN0d2Fkqz5Flk=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: type; ValueData: 00000006; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: multisz; ValueName: idstring; ValueData: Vid_1483&Pid_1200{break}Vid_04B4&Pid_1234; Flags: uninsdeletekey
;����2��
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV2Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: signature; ValueData: c8QKaNCXSpSp0rcfysgtMuqrMOl2i4tezS/XsxmtNo3mekcVuFRkhpAVKFip+S6ju4VFcXq3tIJVCp3eVHxWG4JjzD+NN2QxnXx72SE+w0Rz4UlLuoMPW6AY1p0D1ZG/6Mkul2hzRMVUWZr0EfmMJAeDyRP2aWnIe3PxbkuJGes=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: type; ValueData: 00000002; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw2; ValueType: multisz; ValueName: idstring; ValueData: Vid_04b4&Pid_1234; Flags: uninsdeletekey
;��̩
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: dllpath; ValueData: {app}\HTEKey.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0001{break}vid_5448&pid_0003{break}vid_5448&pid_0004; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: string; ValueName: signature; ValueData: U80zoR77rMXYD7SLQhHKcAA8wD0ATknWlMY17KLcDvawGOZTUfQnVhF5mDiJ9Idtd8JEi89PwZUyFltsMo81Nkdz/8DEJLWhVMeEbcZfwvc9hR02fzFVbxbNg7Zfz/SI9Kixy9Q/4du+0sKhgrGkNpTjmgyOJkiRzm1rfmwoFi4=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: mustLgoin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyHT; ValueType: dword; ValueName: type; ValueData: 00000004; Flags: uninsdeletekey

;����3003

;�Ķ���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: ACIBOcD0IAIHrGa56s1J5wvILyDQnBx5SR8jrwSrGn9a2HNy10/kHkZvY0dAsc9W6OpgumFpmlceD1SJ3MdT3q7lI1AtSwSYcCjY/NHU4PCC5tDkJ9f3iQS+9Z7gRSOnNJkRcR+AMO5wKCAL4KJJKsATpOSkbOh4ywAfFAhM4Z0=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {app}\ESKeyProv.dll; Flags: uninsdeletekey

;HTSM2ע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {app}\HaitaiSM2Key.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: Z5nO56kha/rfQLzUCNv7JSe+ixXK14kBTlGzbuCrUsZUBQBvIw3YaXytDP/uFuWn8KDaIzhaSDU5OPlRjA6qfxkWwWgScuxeH25UVb2Q9Qzlwe2d4u1Lp1OPGdSiCiGYgcoQZ8cLF6/IVhLU4NGOZAtqWJwf902b3pJo8WhZi2I=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey

;����SM2

[Run]
Filename: {app}\NETCAKEY_MWV2V3.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {sys}
Filename: {sys}\Driver\HKDriver32.exe; Parameters: -i; WorkingDir: {sys}; Flags: runhidden

[UninstallRun]
Filename: {pf}\NETCA\NETCAKEY_MWHS\unins000.exe; WorkingDir: {pf}\NETCA\NETCAKEY_MWHS; Parameters: /SP- /VERYSILENT /NORESTART
Filename: {sys}\Driver\HKDriver32.exe; Parameters: -u; WorkingDir: {sys}; Flags: runhidden

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
