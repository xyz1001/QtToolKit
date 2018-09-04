/* Copyright (©) 2017 zgzf1001@gmail.com */

#include "load_qss.h"

#include <QFile>

bool LoadQss(const QString &qss_file_path, QWidget *widget) {
    if (widget == nullptr) {
        return false;
    }

    QFile file(":/" + qss_file_path);
    if (file.open(QFile::ReadOnly)) {
        QString style_sheet = QString::fromLatin1(file.readAll());
        widget->setStyleSheet(style_sheet);
        file.close();
        return true;
    }
    return false;
}
