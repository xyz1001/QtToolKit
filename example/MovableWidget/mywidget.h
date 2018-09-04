/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef EXAMPLE_MOVABLEWIDGET_MYWIDGET_H_
#define EXAMPLE_MOVABLEWIDGET_MYWIDGET_H_

#include "movable_widget.h"

class MyWidget : public MovableWidget {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
};

#endif  // EXAMPLE_MOVABLEWIDGET_MYWIDGET_H_
