/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "borderless_widget.h"

#ifdef Q_OS_WIN
// clang-format off
#include <Windows.h>
#include <WinUser.h>
#include <dwmapi.h>
// clang-format on
#endif

BorderlessWidget::BorderlessWidget(QWidget *parent) : QWidget(parent) {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(winId());
    SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP | WS_CAPTION | WS_THICKFRAME);
    // 把client区域扩展到标题栏上和边框上，只留1个像素的余量
    const MARGINS shadow = {1, 1, 1, 1};
    DwmExtendFrameIntoClientArea(HWND(winId()), &shadow);
#endif
}

BorderlessWidget::~BorderlessWidget() = default;

void BorderlessWidget::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    previous_pos_ = event->pos();
}

void BorderlessWidget::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - previous_pos_;
        QPoint window_pos = this->pos() + diff;
        this->move(window_pos);
    }
}

#ifdef Q_OS_WIN
bool BorderlessWidget::nativeEvent(const QByteArray &eventType, void *message,
                                   long *result) {
    MSG *msg = reinterpret_cast<MSG *>(message);
    switch (msg->message) {
    case WM_NCCALCSIZE:
        *result = 0;
        return true;
    default:
        return QWidget::nativeEvent(eventType, message, result);
    }
}
#endif
