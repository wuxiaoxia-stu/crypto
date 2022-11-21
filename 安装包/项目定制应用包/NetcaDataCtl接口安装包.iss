#define AppName "���轻�׶���_NetcaDataCtl"

[Setup]
AppName=NetcaDataCtl
AppVerName=NetcaDataCtl_V3.0.0.3
DefaultDirName={sys}\
DefaultGroupName=
OutputBaseFilename=���轻�׶���_NetcaDataCtl
Compression=lzma
UsePreviousGroup=true
AppendDefaultGroupName=false
CreateUninstallRegKey=false
UninstallLogMode=new
Uninstallable=false
DisableProgramGroupPage=true
DisableDirPage=true
AppendDefaultDirName=false
TerminalServicesAware=false
; ����64λģʽ
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;��װ����ʾ�û�������������
AlwaysRestart=false
;ж�غ���ʾ�û�������������
UninstallRestartComputer=false
VersionInfoVersion=3.0.0.3
VersionInfoCompany=�㶫ʡ����������֤���޹�˾
VersionInfoDescription={#AppName}
VersionInfoTextVersion=3.0.0.3
VersionInfoCopyright=(C)�㶫ʡ����������֤���޹�˾
VersionInfoProductName=NetcaDataCtl

[Files]
Source: Y:\svn\���轻��\���ݲ����ӿ�\NetcaDataCtl.dll; DestDir: {sys}; Check: IsOtherArch; Flags: ignoreversion
Source: Y:\svn\���轻��\���ݲ����ӿ�\NetcaDataCtl.dll; DestDir: {syswow64}; Check: IsWin64; Flags: ignoreversion
[Dirs]

[CustomMessages]
NameAndVersion=%1 �汾 %2
AdditionalIcons=����ͼ��:
CreateDesktopIcon=�����洴��ͼ��(&d)
CreateQuickLaunchIcon=�ڿ������������ͼ��(&Q)
ProgramOnTheWeb=�����ϵ� %1
UninstallProgram=ж�� %1
LaunchProgram=���� %1
AssocFileExtension=�� %1 ����չ�� %2 ����(&A)
AssocingFileExtension=���ڽ� %1 ����չ�� %2 ����...
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
[InstallDelete]
Name: {sys}\NetcaDataCtl.dll; Type: files
Name: {syswow64}\NetcaDataCtl.dll; Type: files; Check: IsWin64
