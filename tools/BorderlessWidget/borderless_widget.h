/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef SRC_WIDGETS_BORDERLESSWIDGET_BORDERLESS_WIDGET_H_
#define SRC_WIDGETS_BORDERLESSWIDGET_BORDERLESS_WIDGET_H_

#include <QMouseEvent>
#include <QWidget>

class BorderlessWidget : public QWidget {
    Q_OBJECT

public:
    explicit BorderlessWidget(QWidget *parent = nullptr);
    virtual ~BorderlessWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
#ifdef Q_OS_WIN
    bool nativeEvent(const QByteArray &eventType, void *message,
                     long *result) override;
#endif

private:
    QPoint previous_pos_;
};

#endif  // SRC_WIDGETS_BORDERLESSWIDGET_BORDERLESS_WIDGET_H_
