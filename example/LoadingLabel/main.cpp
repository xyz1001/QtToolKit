/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <QApplication>

#include "loading_label.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    LoadingLabel w;
    w.resize(80, 80);
    w.show();

    return a.exec();
}
