#include "editdirector.h"
#include "ui_editdirector.h"
#include <QMessageBox>
editdirector::editdirector(QWidget *parent) : QDialog(parent),
                                              ui(new Ui::editdirector)
{
    ui->setupUi(this);
}
editdirector::~editdirector()
{
    delete ui;
}
void editdirector::takeeditdirector(QString &A, QString &B, QString &C, QString &D, QString &E, QString &G)
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
    G = ui->table_num->text();
}
void editdirector::on_pushButton_clicked()
{
    if (ui->table_num->text() == "" || ui->fullname->text() == "" || ui->school->text() == "" || ui->salary->text() == "" || ui->experience->text() == "")
    {
        QMessageBox::warning(this, "Error", "You have not filled in all the fields!");
    }
    else
    {
        QString str1 = ui->fullname->text();
        QString str2 = ui->salary->text();
        QString str3 = ui->experience->text();
        QString str4 = ui->table_num->text();
        QString check_fullname, check_salary, check_experience, check_table_num;
        QString only_digits = "^\\d*$";
        QString only_letters = "^(\\D+)(\\c*)+(\\D)$";
        QRegExp *check_letters = new QRegExp(only_letters);
        QRegExp *check_digits = new QRegExp(only_digits);
        check_fullname = (check_letters->indexIn(str1) != -1 ? "+" : "-");
        check_salary = (check_digits->indexIn(str2) != -1 ? "+" : "-");
        check_experience = (check_digits->indexIn(str3) != -1 ? "+" : "-");
        check_table_num = (check_digits->indexIn(str4) != -1 ? "+" : "-");
        if (check_table_num == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in the director table number field!");
        }
        else if (check_fullname == "-")
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
