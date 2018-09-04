/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "mywidget.h"

#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QTimer>

NinePatchInfo GetNinePathInfo() {
    NinePatchInfo info;
    info.url = ":/background.png";
    info.stretch_area = QRect(74, 58, 1, 1);
    info.content_margins = QMargins(50, 30, 50, 70);
    return info;
}

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    background_ = new NinePatchWidget(GetNinePathInfo(), this);

    layout_ = new QGridLayout(this);
    layout_->setMargin(0);
    layout_->setSpacing(0);
    layout_->addWidget(background_);

    QPushButton *label = new QPushButton("123", background_->Center());
    label->setGeometry(20, 20, 50, 50);
    QGraphicsDropShadowEffect *effect_ = new QGraphicsDropShadowEffect;
    effect_->setBlurRadius(50);
    effect_->setOffset(0, 10);
    label->setGraphicsEffect(effect_);

    QTimer::singleShot(3000, [this] { resize(300, 300); });
}
