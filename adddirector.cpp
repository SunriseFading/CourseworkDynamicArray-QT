#include "adddirector.h"
#include "ui_adddirector.h"
#include <QMessageBox>
adddirector::adddirector(QWidget *parent) : QDialog(parent),
                                          ui(new Ui::adddirector)
{
    ui->setupUi(this);
}
adddirector::~adddirector()
{
    delete ui;
}
void adddirector::takedirector(QString &A, QString &B, QString &C, QString &D, QString &E)
{
    A = ui->fullname->text();
    B = ui->school->text();
    if (ui->radioButton->isChecked())
    {
        C = ui->radioButton->text();
    }
    if (ui->radioButton_2->isChecked())
    {
        C = ui->radioButton_2->text();
    }
    D = ui->salary->text();
    E = ui->experience->text();
}
void adddirector::on_pushButton_clicked()
{
    if (ui->fullname->text() == "" || ui->school->text() == "" || ui->salary->text() == "" || ui->experience->text() == "")
    {
        QMessageBox::warning(this, "Error", "You have not filled in all the fields!");
    }
    else
    {
        QString str1 = ui->fullname->text();
        QString str2 = ui->salary->text();
        QString str3 = ui->experience->text();
        QString check_fullname, check_salary, check_experience;
        QString only_digits = "^\\d*$";
        QString only_letters = "^(\\D+)(\\c*)+(\\D)$";
        QRegExp *check_letters = new QRegExp(only_letters);
        QRegExp *check_digits = new QRegExp(only_digits);
        check_fullname = (check_letters->indexIn(str1) != -1 ? "+" : "-");
        check_salary = (check_digits->indexIn(str2) != -1 ? "+" : "-");
        check_experience = (check_digits->indexIn(str3) != -1 ? "+" : "-");
        if (check_fullname == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in the full name field!");
        }
        else if (check_salary == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in salary field!");
        }
        else if (check_experience == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in experience field!");
        }
        else
        {
            this->close();
        }
    }
}
