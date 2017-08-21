#ifndef RENDERING_AREA_H
#define RENDERING_AREA_H

#include <QWidget>
#include <QPen>

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
    void change_color();

private:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    Ui::rendering_area *ui;
    QPen pen;
};

#endif // RENDERING_AREA_H
