#define AppName "南方电网定制_CNCAPKI"
#define AppVerName "CNCAPKI_V1.0.2.0"

[Setup]
AppName=南方电网定制_CNCAPKI
AppVerName=CNCAPKI_V1.0.2.0
DefaultDirName={sys}\
DefaultGroupName=
OutputBaseFilename=南方电网定制_CNCAPki
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
VersionInfoVersion=1.0.2.0
VersionInfoCompany=广东省电子商务认证有限公司
VersionInfoDescription={#AppName}
VersionInfoTextVersion=1.0.2.0
VersionInfoCopyright=(C)广东省电子商务认证有限公司
VersionInfoProductName=CNCAPKI

[Files]
Source: Y:\svn\南方电网\应用开发接口\com接口\x86\CNCAPki.dll; DestDir: {sys}; Flags: regserver; Check: IsOtherArch
Source: Y:\svn\南方电网\应用开发接口\com接口\x64\CNCAPki.dll; DestDir: {sys}; Flags: regserver; Check: IsWin64
Source: Y:\svn\南方电网\应用开发接口\com接口\x86\CNCAPki.dll; DestDir: {syswow64}; Flags: regserver; Check: IsWin64
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
Name: {sys}\CNCAPki.dll; Type: files
Name: {syswow64}\CNCAPki.dll; Type: files; Check: IsWin64
