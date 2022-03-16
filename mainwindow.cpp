#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycode.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s = new myclass();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_add_director_clicked()
{
    QString A = "1";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_show_clicked()
{
    QString A = "4";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_del_clicked()
{
    QString A = "2";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_edit_director_clicked()
{
    QString A = "3";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_search_clicked()
{
    QString A = "5";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_exit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit the program?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    if (reply == QMessageBox::No)
    {
    }
}
//void MainWindow::on_sozdat_triggered()
//{
//    QString A = "6";
//    double number;
//    number = A.toDouble();
//    s->obr(number);
//}
//void MainWindow::on_sohrkak_triggered()
//{
//    QString A = "7";
//    double number;
//    number = A.toDouble();
//    s->obr(number);
//}
//void MainWindow::on_otkr_triggered()
void MainWindow::on_load_clicked()
{
    QString A = "8";
    double number;
    number = A.toDouble();
    s->obr(number);
}
//void MainWindow::on_sohr_triggered()
void MainWindow::on_save_clicked()
{
    QString A = "9";
    double number;
    number = A.toDouble();
    s->obr(number);
}
//void MainWindow::on_action_7_triggered()
//{
//    QMessageBox::information(0, "О программе", "Разработчик"  " ");
//}
void MainWindow::on_add_teacher_clicked()
{
    QString A = "13";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_add_guard_clicked()
{
    QString A = "14";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_edit_teacher_clicked()
{
    QString A = "15";
    double number;
    number = A.toDouble();
    s->obr(number);
}
void MainWindow::on_edit_guard_clicked()
{
    QString A = "16";
    double number;
    number = A.toDouble();
    s->obr(number);
}
