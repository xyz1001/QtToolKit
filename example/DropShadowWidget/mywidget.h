/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef EXAMPLE_SHADOWWIDGET_MYWIDGET_H_
#define EXAMPLE_SHADOWWIDGET_MYWIDGET_H_

#include <QFrame>
#include "drop_shadow_widget.h"

class MyWidget : public DropShadowWidget {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
};

#endif  // EXAMPLE_SHADOWWIDGET_MYWIDGET_H_
