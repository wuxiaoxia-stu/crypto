; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "netcamcpwin2_ini"
#define MyAppVersion "1.0"
#define MyAppPublisher "NETCA"
#define SetupFileVersion "1.0.0.1"
#define MyAppURL "http://www.cnca.com/"
#define MyAppExeName "ServiceConfig.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{E16E6AB1-0430-41F0-AA43-CC3CF28ED241}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
CreateAppDir=no
OutputBaseFilename=netcamcpwin2_ini
Compression=lzma
SolidCompression=true
VersionInfoTextVersion={#SetupFileVersion}
VersionInfoVersion={#MyAppVersion}
VersionInfoProductVersion={#MyAppVersion}
CreateUninstallRegKey=false
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64

[Languages]
Name: chinesesimp; MessagesFile: compiler:Default.isl

[Files]
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

Source: Z:\rdrelease\�������\NETCA_CRYPTO\current\winX86\�豸����\����U��\netcamcpwin2_qingyuan.ini; DestDir: {sys}; Flags: ignoreversion; DestName: netcamcpwin2.ini
Source: Z:\rdrelease\�������\NETCA_CRYPTO\current\winX86\�豸����\����U��\netcamcpwin2_qingyuan.ini; DestDir: {syswow64}; Flags: ignoreversion; DestName: netcamcpwin2.ini; Check: IsWin64
[Code]
//���ϵͳλ��
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
