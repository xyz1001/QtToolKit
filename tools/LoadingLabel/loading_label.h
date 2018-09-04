/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef RECEIVER_ITEMS_LOADING_LABEL_H_
#define RECEIVER_ITEMS_LOADING_LABEL_H_

#include <QHideEvent>
#include <QPaintEvent>
#include <QPixmap>
#include <QShowEvent>
#include <QTimer>
#include <QWidget>

class LoadingLabel final : public QWidget {
    Q_OBJECT

public:
    explicit LoadingLabel(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:
    void LoadPixmaps();

private:
    QVector<QPixmap> loading_pixmaps;
    QTimer timer_;
    int current_index_ = 0;
};

#endif  // RECEIVER_ITEMS_LOADING_LABEL_H_
