/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "map_shadow_widget.h"

#include <QEvent>

MapShadowWidget::MapShadowWidget(QWidget *parent)
#ifdef ENABLE_MOVABLE
        : MovableWidget(parent) {
#else
        : QWidget(parent) {
#endif
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    InitBackgroundWidget();
    InitCentralWidget();
    UpdateLayout();
}

void MapShadowWidget::SetContentMargins(int left, int top, int right,
                                        int bottom) {
    content_margins_ = QMargins(left, top, right, bottom);
    UpdateLayout();
}

QFrame *MapShadowWidget::Center() {
    return central_widget_;
}

void MapShadowWidget::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    UpdateLayout();
}

void MapShadowWidget::InitBackgroundWidget() {
    background_widget_ = new QWidget(this);
    background_widget_->setObjectName("background");
}

void MapShadowWidget::InitCentralWidget() {
    central_widget_ = new QFrame(background_widget_);
    central_widget_->setObjectName("center");
}

void MapShadowWidget::UpdateLayout() {
    background_widget_->resize(size());

    Center()->resize(size() -
                     QSize(content_margins_.left() + content_margins_.right(),
                           content_margins_.bottom() + content_margins_.top()));
    Center()->move(content_margins_.left(), content_margins_.top());
}
