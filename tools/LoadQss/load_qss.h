/* Copyright (©) 2017 zgzf1001@gmail.com */

#ifndef SRC_UTILS_LOAD_STYLE_SHEET_H_
#define SRC_UTILS_LOAD_STYLE_SHEET_H_

#include <QString>
#include <QWidget>

/**
 * 读取QSS文件并设置到widget上
 *
 * @param qss_file_path QSS文件名
 * @param widget    要设置QSS的widget
 *
 * @returns   设置成功与否
 */
bool LoadQss(const QString &qss_file_path, QWidget *widget);

#endif  // SRC_UTILS_LOAD_STYLE_SHEET_H_
