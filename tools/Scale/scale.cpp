#include "scale.h"

#include <QApplication>
#include <QScreen>

#include <algorithm>

qreal ScaleFactor() {
    // 1080为无需通过缩放即为最佳显示大小时的分辨率高度
    static qreal scale = QApplication::primaryScreen()->geometry().height() /
                         static_cast<qreal>(1080);
    return scale;
}

QString Scale(const QString &qss) {
    QString scaled_qss(qss);
    QRegExp regex("(\\d+)px");
    int index = 0;
    while ((index = scaled_qss.indexOf(regex, index)) != -1) {
        scaled_qss.remove(index, regex.cap(0).length());
        auto scale_pixel = QString("%1px").arg(Scale(regex.cap(1).toInt()));
        scaled_qss.insert(index, scale_pixel);
        index += scale_pixel.size();
    }
    return scaled_qss;
}
