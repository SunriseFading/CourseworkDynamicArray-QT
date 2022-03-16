#include "delemployee.h"
#include "ui_delemployee.h"
#include <QMessageBox>
delemployee::delemployee(QWidget *parent) : QDialog(parent),
                                ui(new Ui::delemployee)
{
    ui->setupUi(this);
}
delemployee::~delemployee()
{
    delete ui;
}
void delemployee::deldirector(QString &A, QString &F)
{
    A = ui->num_director->text();
    F = ui->key->text();
}
void delemployee::delteacher(QString &A, QString &F)
{
    A = ui->num_teacher->text();
    F = ui->key->text();
}
void delemployee::delguard(QString &A, QString &F)
{
    A = ui->num_guard->text();
    F = ui->key->text();
}
void delemployee::on_pushButton_clicked()
{
    QString del = ui->num_director->text();
    QString check_del;
    QString only_digits = "^\\d*$";
    QRegExp *check_digits = new QRegExp(only_digits);
    check_del = (check_digits->indexIn(del) != -1 ? "+" : "-");
    if (check_del == "-")
    {
        QMessageBox::warning(this, "Error", "Incorrect data in the director table number field!");
    }
    else
    {
        ui->key->setText(".");
        this->close();
    }
}
void delemployee::on_pushButton_2_clicked()
{
    QString del = ui->num_teacher->text();
    QString check_del;
    QString only_digits = "^\\d*$";
    QRegExp *check_digits = new QRegExp(only_digits);
    check_del = (check_digits->indexIn(del) != -1 ? "+" : "-");
    if (check_del == "-")
    {
        QMessageBox::warning(this, "Error", "Incorrect data in the teacher table number field!");
    }
    else
    {
        ui->key->setText("..");
        this->close();
    }
}
void delemployee::on_pushButton_3_clicked()
{
    QString del = ui->num_guard->text();
    QString check_del;
    QString only_digits = "^\\d*$";
    QRegExp *check_digits = new QRegExp(only_digits);
    check_del = (check_digits->indexIn(del) != -1 ? "+" : "-");
    if (check_del == "-")
    {
        QMessageBox::warning(this, "Error", "Incorrect data in the guard table number field!");
    }
    else
    {
        ui->key->setText("...");
        this->close();
    }
}
