/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef EXAMPLE_WIDGETS_BORDERLESSWIDGET_MYWIDGET_H_
#define EXAMPLE_WIDGETS_BORDERLESSWIDGET_MYWIDGET_H_

#include "borderless_widget.h"

class MyWidget : public BorderlessWidget {
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
};

#endif  // EXAMPLE_WIDGETS_BORDERLESSWIDGET_MYWIDGET_H_
