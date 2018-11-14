# Copyright (©) 2018 xyz1001 All rights reserved.
# Author: xyz1001 <zgzf1001@gmail.com>
#
# -*- coding: uft-8 -*-

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD

CONFIG += c++11

SOURCES += \
        $$PWD/drop_down_list.cpp \
        $$PWD/drop_down_box.cpp \
        $$PWD/selector.cpp

HEADERS += \
        $$PWD/drop_down_list.h \
        $$PWD/drop_down_box.h \
        $$PWD/selector.h

FORMS += \
        $$PWD/drop_down_list.ui \
        $$PWD/drop_down_box.ui

