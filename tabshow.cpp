#include "tabshow.h"
#include "ui_tabshow.h"
int z = 0, t = 0, z2 = 0, t2 = 0, z3 = 0, t3 = 0;
tabshow::tabshow(QWidget *parent) : QDialog(parent),
                                    ui(new Ui::tabshow)
{
    ui->setupUi(this);
    ui->table1->setColumnCount(5);
    ui->table1->setRowCount(z);
    QStringList Title;
    Title << "Full name"
          << "School"
          << "Gender"
          << "Salary"
          << "Experience";
    ui->table1->setHorizontalHeaderLabels(Title);
    ui->table2->setColumnCount(7);
    ui->table2->setRowCount(z2);
    QStringList Title2;
    Title2 << "Full name"
           << "School"
           << "Gender"
           << "Salary"
           << "Subject"
           << "Hours"
           << "Experience";
    ui->table2->setHorizontalHeaderLabels(Title2);
    ui->table3->setColumnCount(6);
    ui->table3->setRowCount(z3);
    QStringList Title3;
    Title3 << "Full name"
           << "School"
           << "Gender"
           << "Salary"
           << "Days"
           << "Experience";
    ui->table3->setHorizontalHeaderLabels(Title3);
}
tabshow::~tabshow()
{
    delete ui;
}
void tabshow::settab1(QString A, QString B, QString C, QString D, QString E)
{
    z++;
    ui->table1->setRowCount(z);
    ui->table1->setItem(t, 0, new QTableWidgetItem(A));
    ui->table1->setItem(t, 1, new QTableWidgetItem(B));
    ui->table1->setItem(t, 2, new QTableWidgetItem(C));
    ui->table1->setItem(t, 3, new QTableWidgetItem(D));
    ui->table1->setItem(t, 4, new QTableWidgetItem(E));
    t++;
}
void tabshow::settab2(QString A, QString B, QString C, QString D, QString E, QString E1, QString E2)
{
    z2++;
    ui->table2->setRowCount(z2);
    ui->table2->setItem(t2, 0, new QTableWidgetItem(A));
    ui->table2->setItem(t2, 1, new QTableWidgetItem(B));
    ui->table2->setItem(t2, 2, new QTableWidgetItem(C));
    ui->table2->setItem(t2, 3, new QTableWidgetItem(D));
    ui->table2->setItem(t2, 4, new QTableWidgetItem(E));
    ui->table2->setItem(t2, 5, new QTableWidgetItem(E1));
    ui->table2->setItem(t2, 6, new QTableWidgetItem(E2));
    t2++;
}
void tabshow::settab3(QString A, QString B, QString C, QString D, QString E, QString E1)
{
    z3++;
    ui->table3->setRowCount(z3);
    ui->table3->setItem(t3, 0, new QTableWidgetItem(A));
    ui->table3->setItem(t3, 1, new QTableWidgetItem(B));
    ui->table3->setItem(t3, 2, new QTableWidgetItem(C));
    ui->table3->setItem(t3, 3, new QTableWidgetItem(D));
    ui->table3->setItem(t3, 4, new QTableWidgetItem(E));
    ui->table3->setItem(t3, 5, new QTableWidgetItem(E1));
    t3++;
}
void tabshow::reset()
{
    z = 0;
    t = 0;
    z2 = 0;
    t2 = 0;
    z3 = 0;
    t3 = 0;
}
void tabshow::on_pushButton_clicked() { this->close(); }
