/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : MovableWidget(parent) {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}
