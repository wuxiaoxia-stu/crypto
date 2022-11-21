; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_FT3003(32&64)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define APPVERSION "1.1.0"
#define SETUP_FILE_VERSION "1.1.0.27"
#define UID  "99DF1990-C302-4DA3-BCEE-AE6F7721E635"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{99DF1990-C302-4DA3-BCEE-AE6F7721E635}
AppName={#DEVICES_APPNAME}
AppVersion={#APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright=? {#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices(FT3003)
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
VersionInfoCompany=NETCA
VersionInfoProductName={#DEVICES_APPNAME}
VersionInfoProductVersion={#APPVERSION}
UninstallLogMode=overwrite
VersionInfoVersion={#SETUP_FILE_VERSION}
VersionInfoCopyright=(C) {#NETCA}����������Ȩ����
CreateUninstallRegKey=false

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_FT3003
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_FT3003

trad.SetupAppTitle=�W�Cͨ�O����_FT3003
trad.SetupWindowTitle=�W�Cͨ�O����_FT3003

eng.SetupAppTitle=NETCADevices_FT3003
eng.SetupWindowTitle=NETCADevices_FT3003
[Files]
;����3003������32λ��
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003.DLL; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003.sig; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003_s.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003_vip.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
;��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: not IsWin64

;64λϵͳ�·���3003������64λ��
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\system32\WZTCsp11_3003.DLL; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\system32\WZTCsp11_3003.sig; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\system32\WZTCsp11_3003_s.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64λϵͳ��˾��̬�豸DLL(64λ)
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\system32\Epass3003Prov.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����3003\Epass3003Prov.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\winX64\�豸����\����3003\Epass3003Prov.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64

;64λϵͳ�·���3003������32λ��
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003.DLL; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003.sig; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003_s.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\WZTCsp11_3003_vip.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64λϵͳ��˾��̬�豸DLL(32λ)
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\SysWOW64\Epass3003Prov.dll_driver.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
Source: ..\..\winX86\�豸����\����3003\Epass3003Prov.dll_device.ini; DestDir: {pf32}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion; Check: IsWin64
;����3003���԰�
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\lang\escertd_wzt_1033.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\lang\escertd_wzt_2052.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\lang\escsp_wzt_1033.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\lang\escsp_wzt_2052.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\lang\esmgr_wzt_1033.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
Source: ..\..\..\..\֤�����\������������\����\����3003�޽���ͳһ��װ�����˵��20111101\����3003_files_64λϵͳ\lang\esmgr_wzt_2052.lng; DestDir: {pf}\NETCA\NETCA_Devices\lang\; Flags: uninsrestartdelete
; 32λ����CA3003
Source: ..\..\..\..\֤�����\������������\����\����CA3003\32λ\wztCsp11_3003_GX.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\֤�����\������������\����\����CA3003\32λ\wztCsp11_3003_GX.dll; DestDir: {syswow64}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
;64λ����CA3003
Source: ..\..\..\..\֤�����\������������\����\����CA3003\64λ\wztCsp11_3003_GX.dll; DestDir: {sys}; Flags: restartreplace uninsrestartdelete ignoreversion; Check: IsWin64


[Registry]
;32λϵͳע���
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: 00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: pkcs11library; ValueData: wztCsp11_3003.dll{break}wztCsp11_3003_GX.dll; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: banSEbEuMG8DfzI/77Qs0cnqWTXkY8WRVEYMImNaZPHpu3CRNBwcx/oJMXMR6LWej9L5XGYsaxsf3eI/QspcjMZItjzBfE1ANf30bkfI7uY4Lyjc77cOxViWOgC+zKBUzInonehcY53rCkRmXEgHE6j+J6psUPfiizV+1RUjZ4w=; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: 00000005; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; Subkey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: not IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: not IsWin64
;64λϵͳ64λע���
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: pkcs11library; ValueData: wztCsp11_3003.dll{break}wztCsp11_3003_GX.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: XnYrq7BT4w/rcITC1g4PUzzlOqJHBnOF7fiMmYw2WxsSBGQzXyKoEm3+WOhprvTx+YHH2S8INrBgmBR1EeZ0bzGL/OuHFA2acSh3WMhnJzguyUbhW1Be0iUjKfNg3GXKIOFtU2F1GrmBuNh03gtIptp8rYjy7qp3i96NdXMIMRw=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;64λϵͳ32λע���
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: dllpath; ValueData: {pf32}\NETCA\NETCA_Devices\Epass3003Prov.dll; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: signature; ValueData: banSEbEuMG8DfzI/77Qs0cnqWTXkY8WRVEYMImNaZPHpu3CRNBwcx/oJMXMR6LWej9L5XGYsaxsf3eI/QspcjMZItjzBfE1ANf30bkfI7uY4Lyjc77cOxViWOgC+zKBUzInonehcY53rCkRmXEgHE6j+J6psUPfiizV+1RUjZ4w=; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: pkcs11library; ValueData: wztCsp11_3003.dll{break}wztCsp11_3003_GX.dll; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: class; ValueData: USB; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: type; ValueData: $00000005; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: multisz; ValueName: idstring; ValueData: Vid_096E&Pid_0702; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\WOW6432NODE\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: dword; ValueName: NoUnload; ValueData: $00000000; Check: IsWin64; Flags: uninsdeletekey
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: version; ValueData: {#SETUP_FILE_VERSION}; Flags: uninsdeletekey; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\NETCA\PKI\Devices\NETCAKeyFT3; ValueType: string; ValueName: UID; ValueData: {#UID}; Flags: uninsdeletekey; Check: IsWin64
;32λϵͳ
Root: HKLM; SubKey: SOFTWARE\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Path; ValueData: {pf}\NETCA\NETCA_Devices\; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: LanguageId; ValueData: 2052; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Version; ValueData: 10130204; Flags: uninsdeletevalue
;64λϵͳ
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Path; ValueData: {pf}\NETCA\NETCA_Devices\; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: LanguageId; ValueData: 2052; Flags: uninsdeletevalue; Check: IsWin64
Root: HKLM; SubKey: SOFTWARE\Wow6432Node\EnterSafe\ePass3003_wzt; ValueType: string; ValueName: Version; ValueData: 10130204; Flags: uninsdeletevalue; Check: IsWin64



[InstallDelete]
Name: {app}\Unins_FT3003.dat; Type: files
Name: {app}\Unins_FT3003.exe; Type: files
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
NewUninsName := 'Unins_FT3003';
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
