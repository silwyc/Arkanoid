; Имя приложения
#define   Name       "Arkanoid"
; Версия приложения
#define   Version    "1.0.0"
; Фирма-разработчик
#define   Publisher  "Sergey Korolev"
; Сафт фирмы разработчика
#define   URL        "https://github.com/silwyc"
; Имя исполняемого модуля
#define   ExeName    "Arcanoid.exe"

;------------------------------------------------------------------------------
;   Параметры установки
;------------------------------------------------------------------------------
[Setup]

; Уникальный идентификатор приложения, 
;сгенерированный через Tools -> Generate GUID
AppId={{ABB3E883-F668-4959-B588-C8497DF858B4}

; Прочая информация, отображаемая при установке
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; Путь установки по-умолчанию
DefaultDirName={pf}\{#Name}
; Имя группы в меню "Пуск"
DefaultGroupName={#Name}

; Каталог, куда будет записан собранный setup и имя исполняемого файла
OutputDir=C:\.git\output
OutputBaseFileName=Arkanoid

; Файл иконки
SetupIconFile=C:\.git\arkanoid\img\icon64.ico  

; Параметры сжатия
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;   Устанавливаем языки для процесса установки
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;   Опционально - некоторые задачи, которые надо выполнить при установке
;------------------------------------------------------------------------------
[Tasks]
; Создание иконки на рабочем столе
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   Файлы, которые надо включить в пакет установщика
;------------------------------------------------------------------------------
[Files]

; Исполняемый файл
Source: "C:\build\arkanoid\Release\Arkanoid.exe"; DestDir: "{app}"; Flags: ignoreversion

; Прилагающиеся ресурсы
Source: "C:\.git\arkanoid\img\*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\.git\arkanoid\fonts\*"; DestDir: "{app}\fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\.git\arkanoid\sounds\*"; DestDir: "{app}\sounds\"; Flags: ignoreversion recursesubdirs createallsubdirs

; VS Redistributable package
Source: "C:\.git\arkanoid\installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
Source: "C:\.git\arkanoid\installer\oalinst.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;   Указываем установщику, где он должен взять иконки
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\Arkanoid.exe"; Tasks: desktopicon; IconFilename: "{app}\img\icon64.ico "

[Run]
;------------------------------------------------------------------------------
;   Установка распространяемого пакета VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
Filename: {tmp}\oalinst.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: OpenAL is installed. Please wait...
