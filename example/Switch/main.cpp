#include <QApplication>
#include <QDebug>
#include <QWidget>

#include "switch.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget w;
    w.resize(100, 100);
    QHBoxLayout layout(&w);
    w.setLayout(&layout);

    // simple style
    SwitchOption simple_style;
    simple_style.slider_diameter = 22;
    simple_style.slider_margin = 3;
    simple_style.box_width = 58;
    simple_style.box_height = 28;
    simple_style.slider_brush = QBrush(Qt::white);
    simple_style.disable_slider_brush = QBrush(Qt::white);
    simple_style.turn_off_box_brush = QBrush(QColor(197, 204, 207));
    simple_style.turn_on_box_brush = QBrush(QColor(40, 193, 206));
    simple_style.disable_box_brush = QBrush(Qt::gray);

    Switch simple_switch(simple_style, &w);
    simple_switch.setChecked(true);

    // simple style
    SwitchOption material_design_style;
    material_design_style.slider_diameter = 22;
    material_design_style.slider_margin = -11;
    material_design_style.box_width = 40;
    material_design_style.box_height = 14;
    material_design_style.slider_brush = QBrush(Qt::white);
    material_design_style.disable_slider_brush = QBrush(Qt::white);
    material_design_style.turn_off_box_brush = QBrush(QColor(197, 204, 207));
    material_design_style.turn_on_box_brush = QBrush(QColor(40, 193, 206));
    material_design_style.disable_box_brush = QBrush(Qt::gray);

    Switch material_design_switch(material_design_style, &w);
    layout.addWidget(&material_design_switch);

    w.show();
    return a.exec();
}
