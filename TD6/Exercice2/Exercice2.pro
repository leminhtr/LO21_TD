QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

QT += xml
SOURCES += \
    main.cpp \
    Notes.cpp

DISTFILES += \
    notes.xml

HEADERS += \
    Notes.h
