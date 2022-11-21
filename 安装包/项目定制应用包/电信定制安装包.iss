#define AppName "电信定制安装包"
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
; 开启64位模式
ArchitecturesInstallIn64BitMode=x64 ia64
ArchitecturesAllowed=x86 x64 ia64
;安装后提示用户重新启动电脑
AlwaysRestart=false
;卸载后提示用户重新启动电脑
UninstallRestartComputer=false
VersionInfoVersion=1.0.2.2
VersionInfoCompany=广东省电子商务认证有限公司
VersionInfoDescription={#AppName}
VersionInfoTextVersion=1.0.2.2
VersionInfoCopyright=(C)广东省电子商务认证有限公司
VersionInfoProductName=netcapscertapphlp

[Files]
;电信定制
Source: ..\..\..\..\CertAppHelper\COM-Dll\x86\netcapscertapphlp.dll; DestDir: {sys}; Flags: regserver restartreplace uninsrestartdelete ignoreversion; Check: not IsWin64
Source: ..\..\..\..\CertAppHelper\COM-Dll\x86\netcapscertapphlp.dll; DestDir: {syswow64}; Flags: regserver restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
Source: ..\..\..\..\CertAppHelper\COM-Dll\x64\netcapscertapphlp.dll; DestDir: {sys}; Flags: regserver restartreplace uninsrestartdelete ignoreversion; Check: IsWin64
[Dirs]

[CustomMessages]
NameAndVersion=%1 版本 %2
AdditionalIcons=附加图标:
CreateDesktopIcon=在桌面创建图标(&d)
CreateQuickLaunchIcon=在快捷启动栏创建图标(&Q)
ProgramOnTheWeb=网络上的 %1
UninstallProgram=卸载 %1
LaunchProgram=运行 %1
AssocFileExtension=将 %1 与扩展名 %2 连接(&A)
AssocingFileExtension=正在将 %1 与扩展名 %2 连接...
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
