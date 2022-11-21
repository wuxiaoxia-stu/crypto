; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���
#define DEVICES_APPNAME "��֤ͨ�豸����_EtaxViton(32λ)"
#define NETCA "�㶫ʡ����������֤���޹�˾"
#define DEVICES_APPVERSION "1.0"
#define SETUP_FILE_VERSION "1.0.0.2"
#define UID "5CC70FA3-CE40-4C74-A5DF-9AE46A9C6217"
[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{5CC70FA3-CE40-4C74-A5DF-9AE46A9C6217}
AppName={#DEVICES_APPNAME}
AppVersion={#DEVICES_APPVERSION}
AppVerName={#DEVICES_APPNAME}
AppPublisher=�㶫ʡ����������֤���޹�˾
AppPublisherURL=https://www.cnca.net
AppSupportURL=https://www.cnca.net
AppUpdatesURL=https://www.cnca.net

DefaultDirName={pf}\NETCA\NETCA_Devices
AppCopyright={#NETCA}����������Ȩ����
OutputBaseFilename=NETCA_Devices_x86(EtaxViton)
Compression=lzma
SolidCompression=true
DisableDirPage=true
DisableProgramGroupPage=true

VersionInfoDescription={#DEVICES_APPNAME}
VersionInfoVersion ={#SETUP_FILE_VERSION}

ArchitecturesAllowed=x86 x64 ia64
;����ʾ����
UninstallRestartComputer =no

;����"���/ɾ������"�������ʾж��
ShowLanguageDialog=auto
CreateUninstallRegKey=true

[Languages]
Name: chinesesimp; MessagesFile: compiler:Languages\ChineseSimp-12-5.1.11.isl
Name: trad; MessagesFile: compiler:Languages\ChineseTrad-2-5.1.11.isl
Name: eng; MessagesFile: compiler:Default.isl

[Messages]
chinesesimp.SetupAppTitle=��֤ͨ�豸����_EtaxViton
chinesesimp.SetupWindowTitle=��֤ͨ�豸����_EtaxViton

trad.SetupAppTitle=�W�Cͨ�O����_EtaxViton
trad.SetupWindowTitle=�W�Cͨ�O����_EtaxViton

eng.SetupAppTitle=NETCADevices_EtaxViton
eng.SetupWindowTitle=NETCADevices_EtaxViton
[Files]
Source: ..\..\winX86\�豸����\����˰ͨ��ѶCOS\E1990\EtaxVitonProv.dll; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\�豸����\����˰ͨ��ѶCOS\E1990\EtaxVitonProv.dll_device.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\�豸����\����˰ͨ��ѶCOS\E1990\WZTTrans.dll; DestDir: {sys}; Flags: uninsrestartdelete restartreplace ignoreversion
Source: ..\..\winX86\�豸����\����˰ͨ��ѶCOS\E1990\EtaxVitonProv.dll_driver.ini; DestDir: {pf}\NETCA\NETCA_Devices; Flags: uninsrestartdelete restartreplace ignoreversion

[Registry]
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: dword; ValueName: mustLogin; ValueData: $00000000; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: string; ValueName: dllpath; ValueData: {pf}\NETCA\NETCA_Devices\EtaxVitonProv.dll; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: string; ValueName: signature; ValueData: GArlZhchJdr46i6b5bbcE+NNTUsWw/20UPbMlP3LCEJ9ClNMrCp2Y112LPpx2lMKm7ClPWL81jvTPB6jSG0RZgRgsi8uELlt27URwCRu2EXdNNFV3bEe62jsAURDi4pF1iQBvR6xkVWUie31NhWfOKSHx2of+N+41JuDSqvrDiQ=; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: string; ValueName: class; ValueData: USB; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: dword; ValueName: type; ValueData: $00000027; Flags: uninsdeletevalue
Root: HKLM; SubKey: SOFTWARE\NETCA\PKI\Devices\NETCAKeyEtaxViton; ValueType: multisz; ValueName: idstring; ValueData: Vid_1E89&Pid_1990{break}Vid_F02E&Pid_0101{break}Vid_F02E&Pid_0201; Flags: uninsdeletevalue

[InstallDelete]
Name: {app}\Unins_EtaxViton.dat; Type: files
Name: {app}\Unins_EtaxViton.exe; Type: files

[LangOptions]
chinesesimp.LanguageName=Chinese
chinesesimp.LanguageID=$0804

trad.LanguageName=TradChinese
trad.LanguageID=$0404

eng.LanguageName=English
eng.LanguageID=$0409
[Code]

procedure CurStepChanged(CurStep: TSetupStep);
var
uninspath, uninsname, NewUninsName: string;
begin
if CurStep=ssDone then
begin
// ָ���µ�ж���ļ�������������չ����������Ӧ�޸ģ�
NewUninsName := 'Unins_EtaxViton';

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
end  else  if RegKeyExists(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1') then
begin
  //MsgBox('��⵽ϵͳ��Ҫ��', mbInformation, MB_OK);
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'UninstallString', '"' + uninspath + NewUninsName + '.exe"');
  RegWriteStringValue(HKEY_LOCAL_MACHINE, 'SOFTWARE\WOW6432NODE\Microsoft\Windows\CurrentVersion\Uninstall\{{#UID}}_is1', 'QuietUninstallString', '"' + uninspath + NewUninsName + '.exe" /SILENT');
  //MsgBox('��⵽ϵͳ����', mbInformation, MB_OK);
end;
end;
end;
