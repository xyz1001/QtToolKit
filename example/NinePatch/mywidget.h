/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef EXAMPLE_NINEPATCH_MYWIDGET_H_
#define EXAMPLE_NINEPATCH_MYWIDGET_H_

#include <QFrame>
#include <QGridLayout>
#include "nine_patch.h"

class MyWidget : public QWidget {
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);

private:
    NinePatchWidget *background_;
    QGridLayout *layout_;
};

#endif  // EXAMPLE_NINEPATCH_MYWIDGET_H_
