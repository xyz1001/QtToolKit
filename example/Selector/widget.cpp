/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QFile>
#include <QPushButton>

#include <cstdlib>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->item_selector_->SetPlaceholderText("Select an item");
    ui->widget_selector_->SetPlaceholderText("Select an item");

    QFile file(":/widget.qss");
    file.open(QFile::ReadOnly);
    auto qss = QString::fromLatin1(file.readAll());
    this->setStyleSheet(qss);
    file.close();
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_add_item_btn__clicked() {
    static int order = 0;
    ui->item_selector_->AddItem(QString::number(order++));
}

void Widget::on_remove_item_btn__clicked() {
    ui->item_selector_->RemoveItem(ui->item_selector_->Count() - 1);
}

void Widget::on_remove_widget_btn__clicked() {
    static int order = 0;
    auto btn = new QPushButton(QString::number(order++));
    ui->widget_selector_->AddItem(btn->text(), btn);
}

void Widget::on_add_widget_btn__clicked() {
    ui->widget_selector_->RemoveItem(ui->widget_selector_->Count() - 1);
}
