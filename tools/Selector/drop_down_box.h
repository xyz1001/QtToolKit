/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef DROP_DOWN_BOX_H
#define DROP_DOWN_BOX_H

#include <QFrame>
#include <QMouseEvent>

namespace Ui {
class DropDownBox;
}

class DropDownBox : public QFrame {
    Q_OBJECT
    using Super = QFrame;

public:
    explicit DropDownBox(QWidget *parent = nullptr);
    DropDownBox(const DropDownBox &) = delete;
    DropDownBox operator=(const DropDownBox &) = delete;

    ~DropDownBox();

public:
    void SetText(const QString &text);
    void SetPlaceholderText(const QString &text);

public slots:
    void SetEnabled(bool enabled);
    void SetChecked(bool checked);

signals:
    void Clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::DropDownBox *ui;

private:
    QString placeholder_text_;
};

#endif  // DROP_DOWN_BOX_H
