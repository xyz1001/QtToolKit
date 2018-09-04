/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef TOOLS_SHADOWWIDGET_DROP_SHADOW_WIDGET_H_
#define TOOLS_SHADOWWIDGET_DROP_SHADOW_WIDGET_H_

#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QResizeEvent>
#include <QWidget>
#ifdef ENABLE_MOVABLE
#include "movable_widget.h"
#endif

#ifdef ENABLE_MOVABLE
class DropShadowWidget : public MovableWidget {
#else
class DropShadowWidget : public QWidget {
#endif
    Q_OBJECT

public:
    /**
     * @brief 创建一个带阴影边框的窗口
     *
     * @note 要对主窗口设置QSS，使用QFrame#center
     */
    explicit DropShadowWidget(QWidget *parent = nullptr);
    virtual ~DropShadowWidget() = default;

protected:
    /**
     * @note 默认为1px
     */
    void SetShadowBlurRadius(int pixel);
    /**
     * @note 默认颜色为半透明的深灰色(QColor(63, 63, 63, 180)).
     */
    void SetShadowColor(QColor color);
    /**
     * @note 默认偏移为(8,8)
     */
    void SetShadowOffset(qreal dx, qreal dy);

protected:
    QFrame *Center();

    void resizeEvent(QResizeEvent *event) override;

private:
    void InitCentralWidget();
    void UpdateLayout();

private:
    QGraphicsDropShadowEffect *effect_ = nullptr;
    QFrame *central_widget_ = nullptr;
};

#endif  // TOOLS_SHADOWWIDGET_DROP_SHADOW_WIDGET_H_
