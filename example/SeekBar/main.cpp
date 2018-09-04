/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QWidget>

#include "seekbar.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget w;
    w.resize(500, 500);

    QLabel *label = new QLabel(&w);
    label->setGeometry(0, 0, 30, 30);

    SeekBar *big_seek_bar = new SeekBar(&w);
    SeekBar *small_seek_bar = new SeekBar(&w);

    big_seek_bar->setGeometry(0, 40, 500, 32);
    big_seek_bar->setRange(0, 100);
    QObject::connect(big_seek_bar, &SeekBar::valueChanged,
                     [label, small_seek_bar](int value) {
                         label->setText(QString::number(value));
                         small_seek_bar->setValue(value - 10);
                     });

    small_seek_bar->setGeometry(30, 280, 300, 20);
    small_seek_bar->setRange(0, 100);
    QObject::connect(small_seek_bar, &SeekBar::valueChanged,
                     [label, big_seek_bar](int value) {
                         label->setText(QString::number(value));
                         big_seek_bar->setValue(value);
                     });

    QTimer::singleShot(3000, [big_seek_bar] { big_seek_bar->resize(200, 15); });

    w.show();
    return a.exec();
}
