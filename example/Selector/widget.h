/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_add_item_btn__clicked();

    void on_remove_item_btn__clicked();

    void on_remove_widget_btn__clicked();

    void on_add_widget_btn__clicked();

private:
    Ui::Widget *ui;
};

#endif  // WIDGET_H
