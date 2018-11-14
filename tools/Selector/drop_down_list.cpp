/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "drop_down_list.h"
#include "ui_drop_down_list.h"

#include <QDebug>
#include <QScroller>

DropDownList::DropDownList(QWidget *parent)
        : Super(parent), ui(new Ui::DropDownList) {
    ui->setupUi(this);
    ui->scroll_bar_->hide();

    // 开启触摸
    QScroller::grabGesture(ui->list_widget_->viewport(),
                           QScroller::LeftMouseButtonGesture);

    this->setWindowFlags(Qt::Popup | Qt::NoDropShadowWindowHint |
                         Qt::FramelessWindowHint);

    connect(ui->list_widget_->verticalScrollBar(), &QScrollBar::valueChanged,
            ui->scroll_bar_, &QScrollBar::setValue);
    connect(ui->list_widget_->verticalScrollBar(), &QScrollBar::rangeChanged,
            this, [this](int min, int max) {
                ui->scroll_bar_->setPageStep(
                        ui->list_widget_->verticalScrollBar()->pageStep());
                ui->scroll_bar_->setVisible(min != max);
                ui->scroll_bar_->setRange(min, max);
            });
    connect(ui->scroll_bar_, &QScrollBar::valueChanged,
            ui->list_widget_->verticalScrollBar(), &QScrollBar::setValue);
    connect(ui->list_widget_, &QListWidget::currentRowChanged, this,
            &DropDownList::CurrentIndexChanged);
    connect(ui->list_widget_, &QListWidget::currentRowChanged, this,
            &DropDownList::hide);
}

DropDownList::~DropDownList() {
    delete ui;
}

int DropDownList::Count() const {
    return ui->list_widget_->count();
}

int DropDownList::CurrentIndex() const {
    return ui->list_widget_->currentRow();
}

void DropDownList::SetCurrentIndex(int index) {
    if (isHidden()) {
        ui->list_widget_->setCurrentRow(index);
    }
}

QString DropDownList::Label(int index) const {
    auto item = ui->list_widget_->item(index);
    if (!item) {
        return "";
    }

    switch (item_mode_) {
    case kLabel:
        return item->text();
    case kWidget: {
        auto widget = ui->list_widget_->itemWidget(item);
        if (!widget) {
            return "";
        }
        return widget->property("label").toString();
    }
    default:
        return "";
    }
}

QWidget *DropDownList::Widget(int index) const {
    if (item_mode_ != kWidget) {
        qWarning("Cannot get QWidget from DropDownList not in kWidget mode");
        return nullptr;
    };
    return ui->list_widget_->itemWidget(ui->list_widget_->item(index));
}

void DropDownList::AddItem(const QString &label) {
    switch (item_mode_) {
    case kNone:
        item_mode_ = kLabel;
    case kLabel:
        ui->list_widget_->addItem(label);
        break;
    default:
        qWarning("Cannot add text item into DropDownList not in kLabel mode");
    }
}

void DropDownList::AddItem(QWidget *widget) {
    switch (item_mode_) {
    case kNone:
        item_mode_ = kWidget;
    case kWidget: {
        auto item = new QListWidgetItem;
        ui->list_widget_->addItem(item);
        ui->list_widget_->setItemWidget(item, widget);
        break;
    }
    default:
        qWarning(
                "Cannot add QWidget item into DropDownList not in kWidget "
                "mode");
    }
}

void DropDownList::InsertItem(int row, const QString &label) {
    switch (item_mode_) {
    case kNone:
        item_mode_ = kLabel;
    case kLabel:
        ui->list_widget_->insertItem(row, label);
        break;
    default:
        qWarning("Cannot add text item into DropDownList not in kLabel mode");
    }
}

void DropDownList::InsertItem(int row, QWidget *widget) {
    switch (item_mode_) {
    case kNone:
        item_mode_ = kWidget;
    case kWidget: {
        auto item = new QListWidgetItem;
        ui->list_widget_->insertItem(row, item);
        ui->list_widget_->setItemWidget(item, widget);
        break;
    }
    default:
        qWarning(
                "Cannot add QWidget item into DropDownList not in kWidget "
                "mode");
    }
}

void DropDownList::RemoveItem(int row) {
    ui->list_widget_->removeItemWidget(ui->list_widget_->item(row));
    delete ui->list_widget_->takeItem(row);
}

void DropDownList::showEvent(QShowEvent *event) {
    Super::showEvent(event);
    emit VisibilityChanged(true);
}

void DropDownList::hideEvent(QHideEvent *event) {
    Super::hideEvent(event);
    emit VisibilityChanged(false);
}

void DropDownList::resizeEvent(QResizeEvent *event) {
    Super::resizeEvent(event);
    ui->list_widget_->resize(size());

    ui->scroll_bar_->adjustSize();
    ui->scroll_bar_->resize(ui->scroll_bar_->width(), height());
    ui->scroll_bar_->move(width() - ui->scroll_bar_->width(), 0);
}
