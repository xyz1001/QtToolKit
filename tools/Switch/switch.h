/* Copyright (©) 2017 zgzf1001@gmail.com */
#ifndef SRC_SWITCH_SWITCH_H_
#define SRC_SWITCH_SWITCH_H_

#include <QAbstractButton>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QRect>
#include <QRectF>
#include <QWidget>

#include <cstdint>
#include <memory>
#include <string>

struct SwitchOption {
    uint16_t slider_diameter;     // 滑块直径
    int16_t slider_margin;        // 滑块边缘与滑槽边缘的间距
    uint16_t box_width;           // 滑槽宽度
    uint16_t box_height;          // 滑槽高度
    QBrush slider_brush;          // 正常情况下滑块画刷
    QBrush disable_slider_brush;  // 禁用时滑块画刷
    QBrush turn_off_box_brush;    // 开关关闭时滑槽画刷
    QBrush turn_on_box_brush;     // 开关开启时滑槽画刷
    QBrush disable_box_brush;     // 禁用时滑槽画刷
};

class Switch final : public QAbstractButton {
    Q_OBJECT
    Q_PROPERTY(int slider_offset READ GetOffset WRITE SetOffset)

public:
    explicit Switch(const SwitchOption &option, QWidget *parent = 0);
    ~Switch();

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void enterEvent(QEvent *) override;

private:
    class SwitchImpl;
    std::unique_ptr<SwitchImpl> pimpl_;

    void SetOffset(int offset);
    int GetOffset() const;
    void Animation();
    QPropertyAnimation *animation_ = nullptr;
};

#endif  // SRC_SWITCH_SWITCH_H_
