/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "drop_shadow_widget.h"

#include <QEvent>

DropShadowWidget::DropShadowWidget(QWidget *parent)
#ifdef ENABLE_MOVABLE
        : MovableWidget(parent) {
#else
        : QWidget(parent) {
#endif
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    InitCentralWidget();
}

void DropShadowWidget::SetShadowBlurRadius(int pixel) {
    effect_->setBlurRadius(pixel);
    UpdateLayout();
}

void DropShadowWidget::SetShadowColor(QColor color) {
    effect_->setColor(color);
}

void DropShadowWidget::SetShadowOffset(qreal dx, qreal dy) {
    effect_->setOffset(dx, dy);
    UpdateLayout();
}

QFrame *DropShadowWidget::Center() {
    return central_widget_;
}

void DropShadowWidget::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    UpdateLayout();
}

void DropShadowWidget::InitCentralWidget() {
    effect_ = new QGraphicsDropShadowEffect;
    central_widget_ = new QFrame(this);
    central_widget_->setObjectName("center");
    central_widget_->setGraphicsEffect(effect_);
    central_widget_->setStyleSheet("QFrame#center{background-color:#FFFFFF;}");
    UpdateLayout();
}

void DropShadowWidget::UpdateLayout() {
    auto blur_radius = effect_->blurRadius();
    Center()->resize(size() - QSize(2 * blur_radius, 2 * blur_radius));
    Center()->move(blur_radius - effect_->xOffset(),
                   blur_radius - effect_->yOffset());
}
