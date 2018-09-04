/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "movable_widget.h"

void MovableWidget::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    previous_pos_ = event->pos();
    is_moving_ = true;
}

void MovableWidget::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    if (event->buttons() & Qt::LeftButton && is_moving_) {
        QPoint diff = event->pos() - previous_pos_;
        QPoint window_pos = this->pos() + diff;
        this->move(window_pos);
    }
}

void MovableWidget::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    is_moving_ = false;
}
