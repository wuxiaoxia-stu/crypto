; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����"
#define KEYX "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.1.10"

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
OutputBaseFilename=�㶫ʡ��֯��������֤���豸����
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
Source: ..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003.sig; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\wztCsp11_3003_s.dll; DestDir: {sys}; Flags: uninsrestartdelete

;�Ķ���
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217API.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217CFG.bin; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217CSP.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217CSPSi.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217Drv00.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217Pkcs.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217SKF.dll; DestDir: {sys}; Flags: uninsrestartdelete
Source: ..\..\..\֤�����\������������\�����Ķ���\��֤ͨ�Զ�����\64λϵͳ\SysWOW64\SJK1217SKF_API.dll; DestDir: {sys}; Flags: uninsrestartdelete

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
Source: ..\..\..\֤�����\������������\����SM2\����SM2�㷨ePass3000GMCCID\FTGM.dll; DestDir: {sys}; Flags: uninsrestartdelete

;����
;Source: ..\winX86\�豸����\GDCA�������\W-Usb Driver Setup.exe; DestDir: {app}; Flags: uninsrestartdelete
;Source: ..\winX86\�豸����\GDCA�������\wdcrwv.dll; DestDir: {sys}; Flags: uninsrestartdelete


;��˾��̬�豸DLL
Source: ..\winX86\�豸����\����2��\MWEKeyV2Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\winX86\�豸����\����3��\MWEKeyV3Prov.dll; DestDir: {app}; Flags: uninsrestartdelete ignoreversion
Source: ..\winX86\�豸����\��̩\HTEKey.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\����3003\Epass3003Prov.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\�Ķ���\ESKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\��̩SM2��Key\HaitaiSM2Key.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\����SM2��Key\FeiTianSM2Key.dll; DestDir: {app}; Flags: uninsrestartdelete
Source: ..\winX86\�豸����\GDCA�������\GDCAWatchKeyProv.dll; DestDir: {app}; Flags: uninsrestartdelete

[Registry]
;����3��
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: dllpath; ValueData: {app}\MWEKeyV3Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMw3; ValueType: string; ValueName: signature; ValueData: HS8fJt8Ww9QEdZqx+IxvVJStRyIGX2H09uWmqbnE6vf7hj3CdoW8CgTuLcJn1mpyKx76r2Gv9w7OAfZuY58syfHEIOVJ6svwGUxL3eNKr+S/V1B5dt+brzBMHICwUVEpSoVZXgup1qfhmwKXzeQBZQ0iiW8xsUJULDx4/7gG7Pk=; Flags: uninsdeletekey
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
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {app}\Epass3003Prov.dll; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: OoL1Pbq4WESXLvZo19o8cpypkNiciKxcNOldOZRYOLa7q8MmC///ONq7A8l9Xj6QqsfrVgLsfGM4ydM9F+P3K1pHa7Pk9b4KEMbvnjAkBo5s39EIvk2yh40zsOOpuzWt1RNHDBGWarG24D1BFtBZJi55Aq5HD8+JD3eaXFrsxAU=; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey

;�Ķ���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: signature; ValueData: LhH5P3FJTiyqg615+9OJihPC2FV+GQoU8OdEkXnZ0h9qkzdynO5lUNbzxVCOSVrvTQNZ1VHFKSVIWrhfW4lELuud7nH1hdkdqpc8nuVQn7NTtTf5OyhYgYON8YcXFgtRcAmmR6iuunFfaaX+U8nc+6HMtThn/od3JDKGqz2X1nM=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: dword; ValueName: type; ValueData: $00000007; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: multisz; ValueName: idstring; ValueData: Vid_1EA8&Pid_C001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyMwES; ValueType: string; ValueName: dllpath; ValueData: {app}\ESKeyProv.dll; Flags: uninsdeletekey

;HTSM2ע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: dllpath; ValueData: {app}\HaitaiSM2Key.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: multisz; ValueName: idstring; ValueData: vid_5448&pid_0103; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: string; ValueName: signature; ValueData: i1ZrCrMqWCyL5ludNrZ0IeuQBgZqoJN148+H8zFSpMBAsbpPXY5ZOz1QGSpdlsTawOvomjN7r5obNhdNBuW+b0OGsHBnYixjvWcQ5lILzqHWmHV8QNZ/MnH/RJJyFQp4sVey8MiDadZnf33wiGlx7JpMz4EvFgHdEVbl3mjBEWc=; Flags: uninsdeletekey deletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: type; ValueData: $00000021; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\HTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey

;����SM2
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: dllpath; ValueData: {app}\FeiTianSM2Key.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: multisz; ValueName: idstring; ValueData: Vid_096e&Pid_0303; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: ImportOnlyEncKeypair; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: string; ValueName: signature; ValueData: dsKkK+FKTdKEMvBiwk1X6ED7EXVTmvsgM3/3M/I1IACMrYW6YGYVoqmuQJVnV9P1DsDeTao9Rh5KoT296TY4lHTlW6aOPAcBndXEs5OFQkKyU8hXK+1gF3fJHf0OAdEf8WHyzScMc+ykW0YIk0QxDVjvMvNCOarq3SBo2qc6xrQ=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: type; ValueData: $0000000a; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: NoUnload; ValueData: $00000001; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\FTSM2; ValueType: dword; ValueName: SupportGDKMSM2Import; ValueData: $00000001; Flags: uninsdeletekey
;GDCA����key
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\GDCAKeyWD2; ValueType: multisz; ValueName: idstring; ValueData: Vid_163C&Pid_0401{break}Vid_6513&Pid_0089; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\GDCAKeyWD2; ValueType: dword; ValueName: type; ValueData: $00000193; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\GDCAKeyWD2; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\GDCAKeyWD2; ValueType: string; ValueName: signature; ValueData: a+Bg4ghB+SqDjN7e5wyyMandmaYmwjgdzeAmrnsBeGhxbdUugGA1OK8dnNsnjzp5yhPnLRQV2yaz8wJYqGr/rSBMlxOTNjD7+vy/I1ZV2w93crAaJUq+kG9/Y0NauV0QQxMDDEd4czsjKihhvT4fmDTm05UmejPWepsJlUJwSv0=; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\GDCAKeyWD2; ValueType: string; ValueName: dllpath; ValueData: {app}\GDCAWatchKeyProv.dll; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\GDCAKeyWD2; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletekey

[Run]
Filename: {app}\NETCAKEY_MWV2V3.exe; Parameters: /SP- /VERYSILENT /NORESTART; WorkingDir: {sys}
;Filename: {app}\W-Usb Driver Setup.exe; WorkingDir: {sys}; Flags: runminimized runhidden hidewizard
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
