TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_buildertest.h \

SOURCES += \
        "$$PWD"/main.cpp \

## Bind Gtest lib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/gtest/lib/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/gtest/lib/ -lgtestd
else:unix: LIBS += -L$$PWD/include/gtest/lib/ -lgtest

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

## Bind Qt project to test
INCLUDEPATH += "$$PWD"/../PizzaMakerGUI
VPATH += "$$PWD"/../PizzaMakerGUI

HEADERS += \
        Pizza.h \
        PizzaBuilder.h

SOURCES += \
        Pizza.cpp \
        PizzaBuilder.cpp
