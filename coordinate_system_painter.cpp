#include "coordinate_system_painter.h"

#include <QPen>
#include <QWidget>

#include <algorithm>

// First implementation with magic constants...
coordinate_system_painter::coordinate_system_painter(QWidget* const widget):
    painter(widget)
{
    painter.setRenderHint(QPainter::Antialiasing);

    // Set the (0, 0) at the middle of the widget
    {
        const auto y = widget->height() / 2;
        const auto x = widget->width() / 2;
        painter.translate(x, y);
    }

    // Draw grid (sub-optimal: should depend on viewport)
    {
        QPen grid_pen;
        grid_pen.setWidthF(0.5f);
        grid_pen.setColor(QColor(100, 100, 100));
        painter.setPen(grid_pen);
        for (int i = -500; i < 500; i += 10) {
            painter.drawLine(-500, i, 500, i); // x
            painter.drawLine(i, -500, i, 500); // y
        }
    }

    // Draw a basic coordinate system
    {
        QPen coord_pen;
        coord_pen.setWidth(4);
        painter.setPen(coord_pen);
        painter.drawLine(-500, 0, 500, 0);
        painter.drawLine(0, -500, 0, 500);
    }
}

void coordinate_system_painter::set_pen(const QPen& pen)
{
    painter.setPen(pen);
}

void coordinate_system_painter::draw_point(const QPointF& point)
{
    painter.drawPoint(rebase(point));
}

void coordinate_system_painter::draw_points(const std::vector<QPointF>& points)
{
    std::for_each(std::begin(points), std::end(points), [this](const auto& p)
    {
        draw_point(p);
    });
}

void coordinate_system_painter::draw_convex_hull(const std::vector<QPointF>& points)
{
    std::vector<QPointF> destination(points.size());
    std::transform(std::begin(points), std::end(points), std::begin(destination), [this](const auto& p)
    {
        return rebase(p);
    });

    painter.drawConvexPolygon(destination.data(), destination.size());
}

QPointF coordinate_system_painter::rebase(const QPointF& point)
{
    return QPointF{point.x() * 10, - point.y() * 10};
}
