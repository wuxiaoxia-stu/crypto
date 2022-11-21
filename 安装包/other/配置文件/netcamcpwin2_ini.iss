; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "netcamcpwin2_ini"
#define MyAppVersion "1.0"
#define MyAppPublisher "NETCA"
#define SetupFileVersion "1.0.0.1"
#define MyAppURL "http://www.cnca.com/"
#define MyAppExeName "ServiceConfig.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
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
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

Source: Z:\rdrelease\软件发布\NETCA_CRYPTO\current\winX86\设备驱动\天翼U盾\netcamcpwin2_qingyuan.ini; DestDir: {sys}; Flags: ignoreversion; DestName: netcamcpwin2.ini
Source: Z:\rdrelease\软件发布\NETCA_CRYPTO\current\winX86\设备驱动\天翼U盾\netcamcpwin2_qingyuan.ini; DestDir: {syswow64}; Flags: ignoreversion; DestName: netcamcpwin2.ini; Check: IsWin64
[Code]
//检测系统位数
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
