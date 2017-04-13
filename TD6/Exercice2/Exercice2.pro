QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    main.cpp \
    ../TD6_ressources/Notes.cpp

DISTFILES += \
    ../TD6_ressources/notes.xml

HEADERS += \
    ../TD6_ressources/Notes.h
