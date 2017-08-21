#ifndef RENDERING_AREA_H
#define RENDERING_AREA_H

#include <QWidget>

namespace Ui {
class rendering_area;
}

class rendering_area : public QWidget
{
    Q_OBJECT

public:
    explicit rendering_area(QWidget *parent = 0);
    ~rendering_area();

private:
    Ui::rendering_area *ui;
};

#endif // RENDERING_AREA_H
