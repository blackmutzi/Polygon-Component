TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

unix {

QMAKE_CXXFLAGS += -std=c++11 -Wdeprecated-declarations
INCLUDEPATH += $$PWD/include/

}


#SOURCES += main.cpp \
SOURCES +=  Interface/IComponent.cpp \
    Manager/DatabaseManager.cpp \
    Interface/IDatabase.cpp \
    Test/TestDatabase.cpp \
    Test/TestContainer.cpp \
    Manager/ComponentBuilder.cpp

HEADERS += \
    include/stdafx.h \
    include/icomponent.h \
    include/databasemanager.h \
    include/idatabase.h \
    include/testdatabase.h \
    include/testcontainer.h \
    include/itempdatabase.temp \
    include/componentbuilder.h \
    include/componentbuilder.temp

