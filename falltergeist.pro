TEMPLATE = app
CONFIG -= qt

SOURCES += main.cpp \
    Engine/Surface.cpp \
    Engine/Exception.cpp \
    Engine/State.cpp \
    Engine/Game.cpp \
    Engine/Screen.cpp \
    Engine/InteractiveSurface.cpp \
    Engine/Event.cpp \
    Engine/ResourceManager.cpp \
    Engine/CrossPlatform.cpp \
    Engine/Font.cpp \
    Engine/Animation.cpp\
    Engine/Player.cpp \
    Engine/SurfaceSet.cpp \
    Fallout/DatFile.cpp \
    Fallout/DatFileItem.cpp \
    Fallout/FrmFileType.cpp \
    Fallout/PalFileType.cpp \
    Fallout/LstFileType.cpp \
    Fallout/FonFileType.cpp \
    Fallout/AafFileType.cpp \
    Fallout/GcdFileType.cpp \
    Fallout/MsgFileType.cpp \
    Fallout/BioFileType.cpp \
    States/StartState.cpp \
    States/MainMenuState.cpp \
    States/NewGameState.cpp \
    States/PlayerEditState.cpp \
    UI/ImageButton.cpp \ 
    UI/TextArea.cpp \
    UI/FpsCounter.cpp \
    UI/BigCounter.cpp \
    UI/HiddenMask.cpp

HEADERS += \
    Engine/Surface.h \
    Engine/Exception.h \
    Engine/State.h \
    Engine/Game.h \
    Engine/Screen.h \
    Engine/InteractiveSurface.h \
    Engine/Event.h \
    Engine/ResourceManager.h \
    Engine/CrossPlatform.h \
    Engine/Font.h \
    Engine/Animation.h \
    Engine/Player.h \
    Engine/SurfaceSet.h \
    Fallout/DatFile.h \
    Fallout/DatFileItem.h \
    Fallout/FrmFileType.h \
    Fallout/PalFileType.h \
    Fallout/LstFileType.h \
    Fallout/FonFileType.h \
    Fallout/AafFileType.h \
    Fallout/GcdFileType.h \
    Fallout/MsgFileType.h \
    Fallout/BioFileType.h \
    States/StartState.h \
    States/MainMenuState.h \
    States/NewGameState.h \
    States/PlayerEditState.h \
    UI/ImageButton.h \
    UI/TextArea.h \
    UI/FpsCounter.h \
    UI/BigCounter.h \
    UI/HiddenMask.h

LIBS += -lSDL
