#include "main_window.h"
#include "ui_main_window.h"

main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_window)
{
    ui->setupUi(this);

    connect(ui->button, SIGNAL(released()), ui->renderer, SLOT(generate()));
}

main_window::~main_window()
{
    delete ui;
}
