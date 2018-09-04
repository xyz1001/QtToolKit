#ifndef SEEKBAR_H
#define SEEKBAR_H

#include <QMouseEvent>
#include <QResizeEvent>
#include <QSlider>

class SeekBar : public QSlider {
    Q_OBJECT
public:
    explicit SeekBar(QWidget *parent = nullptr);

public:
    void setValue(int value);

private:
    void resizeEvent(QResizeEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void LoadStyleSheet();

private:
    bool handle_pressed = false;
};

#endif  // SEEKBAR_H
