/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "mywidget.h"

#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QTimer>

MyWidget::MyWidget(QWidget *parent) : MapShadowWidget(parent) {
    SetContentMargins(50, 50, 30, 70);
    setStyleSheet(QString(
            "QWidget#background {border-image: url(\":/background.png\") }"));

    QPushButton *label = new QPushButton("123", Center());
    label->setGeometry(20, 20, 50, 50);
    QGraphicsDropShadowEffect *effect_ = new QGraphicsDropShadowEffect;
    effect_->setBlurRadius(50);
    effect_->setOffset(0, 10);
    label->setGraphicsEffect(effect_);

    QTimer::singleShot(3000, [this] { resize(300, 300); });
}
