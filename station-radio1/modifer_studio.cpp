#include "modifer_studio.h"
#include "ui_modifer_studio.h"

modifer_studio::modifer_studio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifer_studio)
{
    ui->setupUi(this);
}

modifer_studio::~modifer_studio()
{
    delete ui;
}
