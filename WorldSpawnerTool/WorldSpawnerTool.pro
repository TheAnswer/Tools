# -------------------------------------------------
# Project created by QtCreator 2010-07-01T02:38:14
# -------------------------------------------------
QT += sql
TARGET = WorldSpawnerTool
TEMPLATE = app
LIBS += -L/opt/local/lib -Ld:/workspace/SWGQTemplateLib/SWGQTemplateLib-build-desktop/debug -Ld:/workspace/QTIffStream/QTIffStream-build-desktop/debug \
        -Ld:/workspace/QTTreLib/QTTreLib-build-desktop/debug \
    -llua

INCLUDEPATH += /opt/local/include

QMAKE_CXXFLAGS += -Wno-multichar -Wno-unused

SOURCES += insertwindow.cpp \
    dynamicspawnarea.cpp \
    nobuildzone.cpp \
    cityregion.cpp \
    console.cpp \
    databaseconnection.cpp \
    main.cpp \
    mainwindow.cpp \
    region.cpp \
    worldmap.cpp \
    settings.cpp \
    creaturemanager.cpp \
    CreatureObject.cpp \
    planetspawnregion.cpp \
    preorcreaturemanager.cpp \
    LuaParser.cpp \
    lairtool.cpp \
    creatureluamanager.cpp \
    spawnluamanager.cpp \
    spawn.cpp \
    staticspawn.cpp \
    staticspawntableitem.cpp \
    planetselection.cpp \
    commands.cpp \
    lairluamanager.cpp \
    lairtemplate.cpp \
    lairtypes.cpp \
    LuaSerializerHelper.cpp \
    lairname.cpp \
    newlairmobile.cpp \
    lairspawneditor.cpp \
    lairgroup.cpp \
    loadingdialog.cpp \
    addlairtypetospawn.cpp
HEADERS += insertwindow.h \
    dynamicspawnarea.h \
    nobuildzone.h \
    cityregion.h \
    console.h \
    databaseconnection.h \
    mainwindow.h \
    region.h \
    worldmap.h \
    creature.h \
    LuaParser.h \
    ApplicationSettings.h \
    settings.h \
    creaturemanager.h \
    CreatureObject.h \
    planetspawnregion.h \
    utils.h \
    preorcreaturemanager.h \
    lairtool.h \
    creatureluamanager.h \
    spawnluamanager.h \
    spawn.h \
    staticspawn.h \
    staticspawntableitem.h \
    planetselection.h \
    commands.h \
    lairluamanager.h \
    lairtemplate.h \
    lairtypes.h \
    LuaSerializerHelper.h \
    lairname.h \
    newlairmobile.h \
    lairspawneditor.h \
    lairgroup.h \
    loadingdialog.h \
    addlairtypetospawn.h
FORMS += insertwindow.ui \
    console.ui \
    connect.ui \
    mainwindow.ui \
    settings.ui \
    creaturemanager.ui \
    preorcreaturemanager.ui \
    lairtool.ui \
    planetselection.ui \
    lairtypes.ui \
    lairname.ui \
    newlairmobile.ui \
    lairspawneditor.ui \
    loadingdialog.ui \
    addlairtypetospawn.ui
RESOURCES += Resources.qrc


























