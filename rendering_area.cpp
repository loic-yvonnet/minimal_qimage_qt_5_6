#include "rendering_area.h"
#include "ui_rendering_area.h"

rendering_area::rendering_area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rendering_area)
{
    ui->setupUi(this);
}

rendering_area::~rendering_area()
{
    delete ui;
}
