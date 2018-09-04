# Copyright (©) 2018 xyz1001 All rights reserved.
# Author: xyz1001 <zgzf1001@gmail.com>
#
# -*- coding: uft-8 -*-
#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app

DEFINES += ENABLE_MOVABLE

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix: QMAKE_CXXFLAGS += -Werror -Wall -Wextra

include($$PWD/../../tools/DropShadowWidget/DropShadowWidget.pri)
include($$PWD/../../tools/MovableWidget/MovableWidget.pri)

SOURCES += \
        ./main.cpp \
    mywidget.cpp

HEADERS += \
    mywidget.h
