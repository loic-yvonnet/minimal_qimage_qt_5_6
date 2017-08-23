#ifndef RENDERING_AREA_H
#define RENDERING_AREA_H

#include <QWidget>
#include <QPointF>

#include <vector>

namespace Ui {
class rendering_area;
}

class rendering_area : public QWidget
{
    Q_OBJECT

public:
    explicit rendering_area(QWidget *parent = 0);
    ~rendering_area();

public slots:
    void generate();

private:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    Ui::rendering_area *ui;
    std::vector<QPointF> points;
    std::vector<QPointF> convex_hull;
};

#endif // RENDERING_AREA_H
