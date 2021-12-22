; ��� ����������
#define   Name       "Arkanoid"
; ������ ����������
#define   Version    "1.0.0"
; �����-�����������
#define   Publisher  "Sergey Korolev"
; ���� ����� ������������
#define   URL        "https://github.com/silwyc"
; ��� ������������ ������
#define   ExeName    "Arcanoid.exe"

;------------------------------------------------------------------------------
;   ��������� ���������
;------------------------------------------------------------------------------
[Setup]

; ���������� ������������� ����������, 
;��������������� ����� Tools -> Generate GUID
AppId={{ABB3E883-F668-4959-B588-C8497DF858B4}

; ������ ����������, ������������ ��� ���������
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; ���� ��������� ��-���������
DefaultDirName={pf}\{#Name}
; ��� ������ � ���� "����"
DefaultGroupName={#Name}

; �������, ���� ����� ������� ��������� setup � ��� ������������ �����
OutputDir=C:\.git\output
OutputBaseFileName=Arkanoid

; ���� ������
SetupIconFile=C:\.git\arkanoid\img\icon64.ico  

; ��������� ������
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;   ������������� ����� ��� �������� ���������
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;   ����������� - ��������� ������, ������� ���� ��������� ��� ���������
;------------------------------------------------------------------------------
[Tasks]
; �������� ������ �� ������� �����
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   �����, ������� ���� �������� � ����� �����������
;------------------------------------------------------------------------------
[Files]

; ����������� ����
Source: "C:\build\arkanoid\Release\Arkanoid.exe"; DestDir: "{app}"; Flags: ignoreversion

; ������������� �������
Source: "C:\.git\arkanoid\img\*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\.git\arkanoid\fonts\*"; DestDir: "{app}\fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\.git\arkanoid\sounds\*"; DestDir: "{app}\sounds\"; Flags: ignoreversion recursesubdirs createallsubdirs

; VS Redistributable package
Source: "C:\.git\arkanoid\installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
Source: "C:\.git\arkanoid\installer\oalinst.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;   ��������� �����������, ��� �� ������ ����� ������
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\Arkanoid.exe"; Tasks: desktopicon; IconFilename: "{app}\img\icon64.ico "

[Run]
;------------------------------------------------------------------------------
;   ��������� ����������������� ������ VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
Filename: {tmp}\oalinst.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: OpenAL is installed. Please wait...
