/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "drop_down_box.h"
#include "ui_drop_down_box.h"

DropDownBox::DropDownBox(QWidget *parent)
        : Super(parent), ui(new Ui::DropDownBox) {
    ui->setupUi(this);
    ui->drop_down_->setAttribute(Qt::WA_TransparentForMouseEvents);
}

DropDownBox::~DropDownBox() {
    delete ui;
}

void DropDownBox::SetText(const QString &text) {
    ui->text_label_->setText(text);
}

void DropDownBox::SetPlaceholderText(const QString &text) {
    placeholder_text_ = text;
    ui->text_label_->setText(text);
}

void DropDownBox::SetEnabled(bool enabled) {
    ui->text_label_->setEnabled(enabled);
    if (!enabled) {
        ui->text_label_->setText(placeholder_text_);
    }
}

void DropDownBox::SetChecked(bool checked) {
    ui->drop_down_->setChecked(checked);
}

void DropDownBox::mousePressEvent(QMouseEvent *event) {
    Super::mousePressEvent(event);
    emit Clicked();
}

void DropDownBox::mouseReleaseEvent(QMouseEvent *event) {
    Super::mousePressEvent(event);
}
