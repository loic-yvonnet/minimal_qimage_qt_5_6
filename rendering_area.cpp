#include "rendering_area.h"
#include "ui_rendering_area.h"
#include "qpoint_generator.h"
#include "coordinate_system_painter.h"

#include "hull/algorithms.hpp"

#include <QPainter>
#include <QColor>

rendering_area::rendering_area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rendering_area),
    points{}
{
    ui->setupUi(this);
}

rendering_area::~rendering_area()
{
    delete ui;
}

void rendering_area::generate()
{
    points = qpoint_generator::generate_points();

    convex_hull.clear();
    hull::convex::compute(points, convex_hull);

    this->update();
}

void rendering_area::paintEvent(QPaintEvent*)
{
    coordinate_system_painter painter(this);

    {
        QPen pen;
        pen.setWidth(5);
        painter.set_pen(pen);

        painter.draw_points(points);
    }

    {
        QPen pen;
        pen.setWidth(1);
        pen.setColor(QColor(200, 50, 50));
        painter.set_pen(pen);

        painter.draw_convex_hull(convex_hull);
    }

}
