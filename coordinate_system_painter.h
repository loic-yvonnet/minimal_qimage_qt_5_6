/**
 * Use QPainter to display a coordinate system.
 */

#ifndef COORDINATE_SYSTEM_PAINTER_H
#define COORDINATE_SYSTEM_PAINTER_H

#include <QPainter>
#include <QPointF>

#include <vector>

class QWidget;
class QPen;

/**
 * @brief The coordinate_system_painter class
 * is an abstract on top of QPainter to draw
 * points within a coordinate system.
 */
class coordinate_system_painter
{
public:
    coordinate_system_painter(QWidget* const widget);

    void set_pen(const QPen& pen);

    void draw_point(const QPointF& point);

    void draw_points(const std::vector<QPointF>& points);

    void draw_convex_hull(const std::vector<QPointF>& points);

private:
    QPointF rebase(const QPointF& point);

    QPainter painter;
};

#endif // COORDINATE_SYSTEM_PAINTER_H
