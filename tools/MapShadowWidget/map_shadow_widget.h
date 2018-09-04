/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef TOOLS_MAPSHADOWWIDGET_MAP_SHADOW_WIDGET_H_
#define TOOLS_MAPSHADOWWIDGET_MAP_SHADOW_WIDGET_H_

#include <QFrame>
#include <QResizeEvent>
#include <QWidget>
#ifdef ENABLE_MOVABLE
#include "movable_widget.h"
#endif

#ifdef ENABLE_MOVABLE
class MapShadowWidget : public MovableWidget {
#else
class MapShadowWidget : public QWidget {
#endif
    Q_OBJECT

public:
    /**
     * @brief 创建一个带阴影边框的窗口
     */
    explicit MapShadowWidget(QWidget *parent = nullptr);
    virtual ~MapShadowWidget() = default;

protected:
    /**
     * @note 默认为0px
     */
    void SetContentMargins(int left, int top, int right, int bottom);

protected:
    QFrame *Center();

    void resizeEvent(QResizeEvent *event) override;

private:
    void InitBackgroundWidget();
    void InitCentralWidget();
    void UpdateLayout();

private:
    QMargins content_margins_;
    QWidget *background_widget_ = nullptr;
    QFrame *central_widget_ = nullptr;
};

#endif  // TOOLS_MAPSHADOWWIDGET_MAP_SHADOW_WIDGET_H_
