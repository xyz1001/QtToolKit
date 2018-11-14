/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "selector.h"

#include <QDebug>

#include "drop_down_box.h"
#include "drop_down_list.h"

Selector::Selector(QWidget *parent)
        : Super(parent),
          layout_(new QHBoxLayout(this)),
          button_(new DropDownBox(this)),
          list_(new DropDownList(this)) {
    layout_->addWidget(button_);
    layout_->setMargin(0);
    layout_->setSpacing(0);

    connect(button_, &DropDownBox::Clicked, this, &Selector::Popup);
    connect(list_, &DropDownList::CurrentIndexChanged, this,
            &Selector::OnCurrentIndexChanged);
    connect(list_, &DropDownList::VisibilityChanged, button_,
            &DropDownBox::SetChecked);
}

void Selector::SetPlaceholderText(const QString &text) {
    button_->SetPlaceholderText(text);
}

void Selector::SetListHeight(int height) {
    list_->resize(list_->width(), height);
}

int Selector::Count() const {
    return list_->Count();
}

int Selector::CurrentIndex() const {
    return list_->CurrentIndex();
}

QString Selector::Label(int index) const {
    return list_->Label(index);
}

QWidget *Selector::Widget(int index) const {
    return list_->Widget(index);
}

void Selector::AddItem(const QString &label) {
    list_->AddItem(label);
}

void Selector::AddItem(QWidget *widget) {
    list_->AddItem(widget);
}

void Selector::InsertItem(int index, const QString &label) {
    list_->InsertItem(index, label);
}

void Selector::InsertItem(int index, QWidget *widget) {
    list_->InsertItem(index, widget);
}

void Selector::RemoveItem(int index) {
    list_->RemoveItem(index);
}

void Selector::UpdateCurrentItem() {
    OnCurrentIndexChanged(list_->CurrentIndex());
}

void Selector::SetCurrentIndex(int index) {
    list_->SetCurrentIndex(index);
}

void Selector::Popup() {
    list_->move(mapToGlobal(QPoint(0, height() + 10)));
    list_->show();
}

void Selector::OnCurrentIndexChanged(int index) {
    button_->SetText(list_->Label(index));
    button_->SetEnabled(index != -1);
    emit CurrentIndexChanged(index);
}

QSize Selector::sizeHint() const {
    return QSize(300, 72);
}

void Selector::resizeEvent(QResizeEvent *event) {
    Super::resizeEvent(event);
    list_->resize(width(), list_->height());
}
