#-------------------------------------------------
#
# Project created by QtCreator 2012-04-18T18:03:42
#
#-------------------------------------------------

#QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS += -std=gnu++0x

QT       += core gui \
        opengl\

TARGET = StarWarsTD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tower.cpp \
    prismtower.cpp \
    enemy.cpp \
    arena.cpp \
    deathstar.cpp \
    explosion.cpp \
    movingobject.cpp \
    missile.cpp \
    deploy.cpp \
    factory.cpp \
    lifebar.cpp \
    customview.cpp \
    plasmatower.cpp \
    generator.cpp \
    target.cpp \
    hunter.cpp \
    agproperties.cpp \
    AI/src/algorytmGenetyczny.cpp \
    AI/src/selekcja.cpp

HEADERS  += mainwindow.h \
    tower.h \
    prismtower.h \
    enemy.h \
    arena.h \
    deathstar.h \
    explosion.h \
    movingobject.h \
    missile.h \
    deploy.h \
    factory.h \
    lifebar.h \
    customview.h \
    plasmatower.h \
    generator.h \
    target.h \
    hunter.h \
    agproperties.h \
    AI/includes/gen.h \
    AI/includes/osobnik.h \
    AI/includes/populacja.h \
    AI/includes/selekcja.h \
    AI/includes/algorytmGenetyczny.h \

FORMS    += mainwindow.ui \
    agproperties.ui

RESOURCES += \
    data.qrc


















































