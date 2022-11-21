#define AppName "���Ŷ��ư�װ��"
#define AppVerName "V1.0.2.2"

[Setup]
AppName={#AppName}
AppVerName={#AppVerName}
DefaultDirName={sys}\
DefaultGroupName=
OutputBaseFilename={#AppName}
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
VersionInfoVersion=1.0.2.2
VersionInfoCompany=�㶫ʡ����������֤���޹�˾
VersionInfoDescription={#AppName}
VersionInfoTextVersion=1.0.2.2
VersionInfoCopyright=(C)�㶫ʡ����������֤���޹�˾
VersionInfoProductName=netcapscertapphlp

[Files]
;���Ŷ���
Source: ..\..\..\..\CertAppHelper\COM-Dll\x86\netcapscertapphlp.dll; DestDir: {sys}; Flags: regserver restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\CertAppHelper\COM-Dll\x86\netcapscertapphlp.dll; DestDir: {syswow64}; Flags: regserver restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\CertAppHelper\COM-Dll\x64\netcapscertapphlp.dll; DestDir: {sys}; Flags: regserver restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
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
Name: {sys}\netcapscertapphlp.dll; Type: files
Name: {syswow64}\netcapscertapphlp.dll; Type: files; Check: IsWin64
