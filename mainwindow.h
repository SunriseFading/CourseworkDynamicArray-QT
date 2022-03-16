#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mycode.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void obr(int num);
private slots:
    void on_add_director_clicked();
    void on_add_teacher_clicked();
    void on_add_guard_clicked();
    void on_edit_director_clicked();
    void on_edit_teacher_clicked();
    void on_edit_guard_clicked();
    void on_del_clicked();
    void on_show_clicked();
    void on_search_clicked();
    void on_exit_clicked();
    void on_save_clicked();
    void on_load_clicked();

private:
        Ui::MainWindow *ui;
        myclass *s;
};
#endif // MAINWINDOW_H
