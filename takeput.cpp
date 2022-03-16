#include "takeput.h"
#include "ui_takeput.h"

takeput::takeput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::takeput)
{
    ui->setupUi(this);
}

takeput::~takeput()
{
    delete ui;
}
void takeput::taker(QString sohr){
    sohr = ui->way->text();
}
void takeput::on_pushButton_clicked(){
    this->close();
}
