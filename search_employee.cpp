#include "search_employee.h"
#include "ui_search_employee.h"
#include <QMessageBox>
search_employee::search_employee(QWidget *parent) : QDialog(parent),
                                ui(new Ui::search_employee)
{
    ui->setupUi(this);
}
search_employee::~search_employee()
{
    delete ui;
}
void search_employee::search_get_director(QString &A, QString &F)
{
    if (ui->radioButton->isChecked())
    {
        A = ui->radioButton->text();
    }
    else
    {
        A = ui->radioButton_2->text();
    }
    F = ui->key->text();
}
void search_employee::search_get_teacher(QString &A, QString &F)
{
    A = ui->school->text();
    F = ui->key->text();
}
void search_employee::search_get_guard(QString &A, QString &F)
{
    A = ui->salary->text();
    F = ui->key->text();
}
void search_employee::on_pushButton_clicked()
{
    ui->key->setText(".");
    this->close();
}
void search_employee::on_pushButton_2_clicked()
{
    ui->key->setText("..");
    this->close();
}
void search_employee::on_pushButton_3_clicked()
{
    QString str = ui->salary->text();
    QString check_salary;
    QString only_digits = "^\\d*$";
    QRegExp *check_digits = new QRegExp(only_digits);
    check_salary = (check_digits->indexIn(str) != -1 ? "+" : "-");
    if (check_salary == "-")
    {
        QMessageBox::warning(this, "Error", "Incorrect data in salary field!");
    }
    else
    {
        ui->key->setText("...");
        this->close();
    }
}
