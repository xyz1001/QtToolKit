/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "nine_patch.h"

#include <QDebug>
#include <QPixmap>

NinePatchWidget::NinePatchWidget(const NinePatchInfo &info, QWidget *parent)
        : QWidget(parent), info_(info) {
    QPixmap pixmap(info_.url);
    if (pixmap.isNull()) {
        return;
    }

    setAttribute(Qt::WA_StyledBackground);

    auto qss = QString("NinePatchWidget{border-width: %2px %3px %4px %5px;"
                       "border-image: url(\"%1\") %2 %3 %4 %5;}")
                       .arg(info_.url)
                       .arg(info_.stretch_area.y())
                       .arg(pixmap.width() - info.stretch_area.x() -
                            info_.stretch_area.width())
                       .arg(pixmap.height() - info.stretch_area.y() -
                            info_.stretch_area.height())
                       .arg(info_.stretch_area.x());
    setStyleSheet(qss);

    InitCentralWidget();
}

QFrame *NinePatchWidget::Center() {
    return central_widget_;
}

void NinePatchWidget::InitCentralWidget() {
    layout_ = new QGridLayout(this);
    layout_->setContentsMargins(info_.content_margins);
    layout_->setSpacing(0);

    central_widget_ = new QFrame(this);
    layout_->addWidget(central_widget_);
}
