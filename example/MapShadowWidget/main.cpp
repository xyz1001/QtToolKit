/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <QApplication>

#include "mywidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyWidget w;
    w.resize(400, 500);
    w.show();

    return a.exec();
}
