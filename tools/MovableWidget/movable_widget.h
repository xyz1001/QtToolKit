/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef TOOLS_MOVABLEWIDGET_MOVABLE_WIDGET_H_
#define TOOLS_MOVABLEWIDGET_MOVABLE_WIDGET_H_

#include <QFrame>
#include <QMouseEvent>
#include <QPaintEvent>

class MovableWidget : public QFrame {
    Q_OBJECT

public:
    using QFrame::QFrame;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool is_moving_ = false;
    QPoint previous_pos_;
};

#endif  // TOOLS_MOVABLEWIDGET_MOVABLE_WIDGET_H_
