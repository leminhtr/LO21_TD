QT += widgets
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11
QT += xml

SOURCES += \
    main.cpp \
    articleediteur.cpp \
    ../Exercice2/Notes.cpp

HEADERS += \
    ArticleEditeur.h \
    ../Exercice2/Notes.h

DISTFILES += \
    ../Exercice2/notes.xml
