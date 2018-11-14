/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef SELECTOR_H
#define SELECTOR_H

#include <QFrame>
#include <QHBoxLayout>
#include <QResizeEvent>

class DropDownBox;
class DropDownList;

class Selector : public QFrame {
    Q_OBJECT
    using Super = QFrame;

public:
    explicit Selector(QWidget *parent = nullptr);

public:
    void SetPlaceholderText(const QString &text);
    void SetListHeight(int height);

    int Count() const;

    int CurrentIndex() const;
    void SetCurrentIndex(int index);

    QString Label(int index) const;
    QWidget *Widget(int index) const;

    void AddItem(const QString &label);
    void AddItem(QWidget *widget);

    void InsertItem(int index, const QString &label);
    void InsertItem(int index, QWidget *widget);

    void RemoveItem(int index);

    void UpdateCurrentItem();

signals:
    void CurrentIndexChanged(int index);

public slots:
    void Popup();
    void OnCurrentIndexChanged(int index);

signals:
    void Clicked();

protected:
    QSize sizeHint() const override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QHBoxLayout *layout_{};
    DropDownBox *button_{};
    DropDownList *list_{};
};

#endif  // SELECTOR_H
