/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef DROP_DOWN_LIST_H
#define DROP_DOWN_LIST_H

#include <QFrame>
#include <QHideEvent>
#include <QListWidgetItem>
#include <QResizeEvent>
#include <QShowEvent>
#include <QStackedLayout>

namespace Ui {
class DropDownList;
}

class DropDownList : public QFrame {
    Q_OBJECT
    using Super = QFrame;

public:
    explicit DropDownList(QWidget *parent = nullptr);
    DropDownList(const DropDownList &) = delete;
    DropDownList operator=(const DropDownList &) = delete;

    ~DropDownList();

public:
    int Count() const;

    int CurrentIndex() const;
    void SetCurrentIndex(int index);

    QString Label(int index) const;
    QWidget *Widget(int index) const;

    void AddItem(const QString &label);
    void AddItem(QWidget *widget);

    void InsertItem(int row, const QString &label);
    void InsertItem(int row, QWidget *widget);

    void RemoveItem(int row);

signals:
    void CurrentIndexChanged(int index);
    void VisibilityChanged(bool visible);

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void AddDropShadow();

private:
    Ui::DropDownList *ui;

private:
    enum ItemMode { kLabel, kWidget, kNone };

    ItemMode item_mode_ = kNone;
};

#endif  // DROP_DOWN_LIST_H
