/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#ifndef TOOLS_NINEPATCH_NINE_PATCH_H_
#define TOOLS_NINEPATCH_NINE_PATCH_H_

#include <QFrame>
#include <QGridLayout>
#include <QWidget>

struct NinePatchInfo {
    QString url;               // 点九图路径
    QRect stretch_area;        // 拉伸区域
    QMargins content_margins;  // 内容边框
};

class NinePatchWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 创建一个以点九图为背景的控件
     */
    explicit NinePatchWidget(const NinePatchInfo &info,
                             QWidget *parent = nullptr);
    virtual ~NinePatchWidget() = default;

public:
    QFrame *Center();

private:
    void InitCentralWidget();

private:
    NinePatchInfo info_;
    QFrame *central_widget_ = nullptr;
    QGridLayout *layout_ = nullptr;
};

#endif  // TOOLS_NINEPATCH_NINE_PATCH_H_
