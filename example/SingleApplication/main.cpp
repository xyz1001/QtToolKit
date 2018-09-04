#include <QApplication>
#include <QWidget>

#include "single_application.h"

int main(int argc, char *argv[]) {
    SingleApplication a(argc, argv);

    QWidget w;
    QObject::connect(&a, &SingleApplication::ShowWindow, &w, &QWidget::show);
    w.show();
    return a.exec();
}
