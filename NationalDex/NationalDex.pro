#-------------------------------------------------
#
# Project created by QtCreator 2019-04-08T15:48:09
#
#-------------------------------------------------

QT       += core gui texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NationalDex
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 resources_big

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    Moveset.cpp \
    Pokedex.cpp \
    Pokemon.cpp \
    PokemonEvolutions.cpp \
    PokemonWeakness.cpp \
    region.cpp \
    typeeffectchart.cpp \
    natureeffectchart.cpp

HEADERS += \
    dialog.h \
    mainwindow.h \
    Moveset.h \
    Pokedex.h \
    Pokemon.h \
    PokemonEvolutions.h \
    PokemonWeakness.h \
    region.h \
    typeeffectchart.h \
    natureeffectchart.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    region.ui \
    typeeffectchart.ui \
    natureeffectchart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    pokemon_images.qrc \
    pokemon_gifs.qrc

DISTFILES += \
    Alola.txt \
    AlolaAttacks.txt \
    AttackDex.txt \
    Hoenn.txt \
    Johto.txt \
    JohtoAttacks.txt \
    Kalos.txt \
    HoennAttacks.txt \
    KalosAttacks.txt \
    Kanto.txt \
    KantoAttacks.txt \
    Sinnoh.txt \
    SinnohAttacks.txt \
    Unova.txt \
    UnovaAttacks.txt \
    Galar.txt \
    GalarAttacks.txt
