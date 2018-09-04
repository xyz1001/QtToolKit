/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "loading_label.h"

#include <QPainter>

LoadingLabel::LoadingLabel(QWidget *parent) : QWidget(parent) {
    LoadPixmaps();

    timer_.setInterval(150);
    connect(&timer_, &QTimer::timeout, [this] {
        ++current_index_;
        current_index_ = current_index_ % loading_pixmaps.size();
        update();
    });
}

void LoadingLabel::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.drawPixmap(rect(), loading_pixmaps[current_index_]);
}

void LoadingLabel::hideEvent(QHideEvent *event) {
    timer_.stop();
    QWidget::hideEvent(event);
}

void LoadingLabel::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    timer_.start();
}

void LoadingLabel::LoadPixmaps() {
    // 加载图片资源
    // 样式一
    size_t pixmap_count = 12;
    loading_pixmaps.reserve(pixmap_count);
    for (size_t i = 0; i < pixmap_count; ++i) {
        loading_pixmaps.push_back(
                QPixmap(QString(":/loading1/loading_%1").arg(i + 1)));
    }

    // 样式二
    // size_t pixmap_count = 8;
    // loading_pixmaps.reserve(pixmap_count);
    // for (size_t i = 0; i < pixmap_count; ++i) {
    // loading_pixmaps.push_back(
    // QPixmap(QString(":/loading2/loading_%1").arg(i + 1)));
    // }
}
