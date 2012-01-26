# -------------------------------------------------
# Project created by QtCreator 2010-07-01T02:38:14
# -------------------------------------------------
QT += sql \
    gui \
    opengl

TARGET = WorldSpawnerTool
TEMPLATE = app
LIBS += -L/opt/local/lib -Ld:/workspace/SWGQTemplateLib/SWGQTemplateLib-build-desktop/debug -Ld:/workspace/QTIffStream/QTIffStream-build-desktop/debug \
        -Ld:/workspace/QTTreLib/QTTreLib-build-desktop/debug -llua5.1

INCLUDEPATH += /opt/local/include

#QMAKE_CXXFLAGS += -Wno-multichar -Wno-unused

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
    addlairtypetospawn.cpp \
    lootitemeditor.cpp \
    osgqtviewer.cpp \
    lootitemtemplate.cpp \
    lootluamanager.cpp \
    objectmodel3dviewer.cpp \
    lootgroup.cpp \
    lootitemtemplatemanager.cpp \
    lootitemtemplatetablewidgetitem.cpp \
    createnewlootgroup.cpp \
    lootmanager.cpp \
    badge.cpp \
    stfviewer.cpp \
    insertbadgeform.cpp \
    worldsnapshotobject.cpp \
    creaturelootsimulator.cpp \
    addlootgroupdialog.cpp \
    datamanager.cpp \
    splashscreen.cpp
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
    addlairtypetospawn.h \
    lootitemeditor.h \
    lootitemtemplate.h \
    lootluamanager.h \
    objectmodel3dviewer.h \
    lootgroup.h \
    lootitemtemplatemanager.h \
    lootitemtemplatetablewidgetitem.h \
    createnewlootgroup.h \
    lootmanager.h \
    chancelineedit.h \
    badge.h \
    stfviewer.h \
    insertbadgeform.h \
    worldsnapshotobject.h \
    creaturelootsimulator.h \
    addlootgroupdialog.h \
    datamanager.h \
    splashscreen.h
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
    addlairtypetospawn.ui \
    lootitemeditor.ui \
    objectmodel3dviewer.ui \
    lootitemtemplatemanager.ui \
    createnewlootgroup.ui \
    lootmanager.ui \
    stfviewer.ui \
    insertbadgeform.ui \
    creaturelootsimulator.ui \
    addlootgroupdialog.ui
RESOURCES += Resources.qrc

win32:CONFIG(release, debug|release): LIBS += -LC:/Users/cRush/Desktop/OpenSceneGraph-3.0.1/lib/ -L$$PWD/external/meshLib/lib -L$$PWD/external/treLib/lib -L$$PWD/external/lua/include -L$$PWD/external/swgOSG/lib -lswgRepository -lmeshLib -ltreLib -losg -losgViewer -losgText -losgDB -losgGA -losgAnimation -losgQt -lOpenThreads
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Users/cRush/Desktop/OpenSceneGraph-3.0.1/lib/ -L$$PWD/external/meshLib/lib -L$$PWD/external/treLib/lib -L$$PWD/external/swgOSG/lib -L$$PWD/external/lua/include -lswgRepositoryd -lmeshLibd -ltreLibd  -losgd -losgViewerd -losgTextd -losgDBd -losgGAd -losgAnimationd -losgQtd -losgQtd -lOpenThreadsd
else:unix:!symbian: LIBS += -L$$PWD/../../osg_vs9/OpenSceneGraph-3.0.1-build/lib/ -L$$PWD/external/meshLib/lib -L$$PWD/external/treLib/lib -L$$PWD/external/swgOSG/lib  -lswgRepository -lswg -lswgMsh -losg -losgViewer -ltreLib  -losgText -losgDB -losgGA -losgAnimation -losgQt

INCLUDEPATH += C:/Users/cRush/Desktop/OpenSceneGraph-3.0.1/include $$PWD/external/treLib/include $$PWD/external/lua/include $$PWD/external/meshLib/include $$PWD/external/swgOSG/include "C:/Program Files/boost/boost_1_48_0"
DEPENDPATH += C:/Users/cRush/Desktop/OpenSceneGraph-3.0.1/include $$PWD/external/treLib/include $$PWD/external/lua/include $$PWD/external/meshLib/include $$PWD/external/swgOSG/include "C:/Program Files/boost/boost_1_48_0"
