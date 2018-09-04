#ifndef SRC_UTILS_SCALE_H_
#define SRC_UTILS_SCALE_H_

#include <QMargins>
#include <QPoint>
#include <QRect>
#include <QSize>

#include <type_traits>

/**
 * 缩放比，为屏幕DPI与默认DPI的比例
 */
qreal ScaleFactor();

/**
 * 将QSS中的数值根据缩放比进行修改
 *
 * @param qss qss代码
 */
QString Scale(const QString &qss);

/**
 * 计算缩放后的数值
 *
 * @param pixel 默认情况下数值
 *
 * @returns 缩放后的数值
 */
template <typename T,
          typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
T Scale(T pixel) {
    if (pixel == 0) {
        return 0;
    }
    // 四舍五入取整，最小为1px
    return std::max<T>((pixel * ScaleFactor() + 0.5), 1);
}

/**
 * 用缩放之后的T类型的数值构造R类型的对象，T必须为数值类型
 */
template <typename R, typename T,
          typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
R Scale(T t1, T t2) {
    return R(Scale(t1), Scale(t2));
}

/**
 * 对上面函数的重载
 */
template <typename R, typename T,
          typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
R Scale(T t1, T t2, T t3, T t4) {
    return R(Scale(t1), Scale(t2), Scale(t3), Scale(t4));
}

#endif  // SRC_UTILS_SCALE_H_
