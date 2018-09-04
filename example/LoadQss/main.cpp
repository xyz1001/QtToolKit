#include <QApplication>
#include <QLabel>
#include <QWidget>

#include "load_qss.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget w;
    w.resize(200, 200);
    QLabel label(&w);

    LoadQss("label.qss", &label);

    w.show();

    return a.exec();
}
