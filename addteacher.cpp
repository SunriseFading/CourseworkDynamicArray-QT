#include "addteacher.h"
#include "ui_addteacher.h"
#include <QMessageBox>
addteacher::addteacher(QWidget *parent) : QDialog(parent), ui(new Ui::addteacher)
{
    ui->setupUi(this);
}
addteacher::~addteacher()
{
    delete ui;
}
void addteacher::taketeacher(QString &A, QString &B, QString &C, QString &D, QString &E, QString &E1,
                               QString &E2)
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
      E = ui->subject->text();
      E1 = ui->hours->text();
      E2 = ui->experience->text();
  }
void addteacher::on_pushButton_2_clicked()
{
    if (ui->fullname->text() == "" || ui->salary->text() == "" || ui->school->text() == "" || ui->subject->text() == "" || ui->hours -> text() == "" || ui->experience->text() == "")
    {
        QMessageBox::warning(this, "Error", "You have not filled in all the fields!");
    }
    else
    {
        QString str1 = ui->fullname->text();
        QString str2 = ui->salary->text();
        QString str3 = ui->experience->text();
        QString str4 = ui->hours->text();
        QString str5 = ui->subject->text();
        QString check_fullname, check_salary, check_experience, check_hours, check_subject;
        QString only_digits = "^\\d*$";
        QString only_letters = "^(\\D+)(\\c*)+(\\D)$";
        QRegExp *check_letters = new QRegExp(only_letters);
        QRegExp *check_digits = new QRegExp(only_digits);
        check_fullname = (check_letters->indexIn(str1) != -1 ? "+" : "-");
        check_salary = (check_digits->indexIn(str2) != -1 ? "+" : "-");
        check_experience = (check_digits->indexIn(str3) != -1 ? "+" : "-");
        check_hours = (check_digits->indexIn(str4) != -1 ? "+" : "-");
        check_subject = (check_letters->indexIn(str5) != -1 ? "+" : "-");
        if (check_fullname == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in the full name field!");
        }
        else if (check_salary == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in salary field!");
        }
        else if (check_subject == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in subject field!");
        }
        else if (check_hours == "-")
        {
            QMessageBox::warning(this, "Error", "Incorrect data in hours per week field!");
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
