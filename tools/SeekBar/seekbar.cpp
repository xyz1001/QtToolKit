/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "seekbar.h"

#include <QFile>

SeekBar::SeekBar(QWidget *parent) : QSlider(parent) {
    setPageStep(0);
    setOrientation(Qt::Horizontal);
    LoadStyleSheet();
}

void SeekBar::setValue(int value) {
    blockSignals(true);
    QSlider::setValue(value);
    blockSignals(false);
}

void SeekBar::LoadStyleSheet() {
    QFile file(":/seekbar.qss");
    if (file.open(QFile::ReadOnly)) {
        QString style_sheet = QString::fromLatin1(file.readAll())
                                      .arg(height())
                                      .arg(height() * 0.2)
                                      .arg(height() * 0.8 / 2)
                                      .arg(height() * 0.1)
                                      .arg(height() / 2);
        setStyleSheet(style_sheet);
        file.close();
    }
}

void SeekBar::resizeEvent(QResizeEvent *event) {
    LoadStyleSheet();
    QWidget::resizeEvent(event);
}

void SeekBar::mouseReleaseEvent(QMouseEvent *event) {
    if (isSliderDown() && orientation() == Qt::Horizontal) {
        QSlider::setValue(minimum() + ((maximum() - minimum()) *
                                       (event->x() - height() / 2)) /
                                              (width() - height()));
    }
    QSlider::mouseReleaseEvent(event);
}
