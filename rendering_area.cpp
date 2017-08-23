#include "rendering_area.h"
#include "ui_rendering_area.h"

#include <QPainter>
#include <QColor>

rendering_area::rendering_area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rendering_area),
    pen()
{
    ui->setupUi(this);

    pen.setWidth(10);
}

rendering_area::~rendering_area()
{
    delete ui;
}

void rendering_area::change_color()
{
    auto color = pen.color();
    color = color.fromHsl((color.hslHue() + 37) % 360, 125, 125);
    pen.setColor(color);

    this->update();
}

void rendering_area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set the (0, 0) at the middle of the widget
    const auto y = this->height() / 2;
    const auto x = this->width() / 2;
    painter.translate(x, y);

    // Draw a basic coordinate system
    QPen basic;
    painter.setPen(basic);
    painter.drawLine(-500, 0, 500, 0);
    painter.drawLine(0, -500, 0, 500);

    // Draw the colored point
    painter.setPen(pen);
    painter.drawPoint(0, 0);
}
