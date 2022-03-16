#ifndef SEARCH_EMPLOYEE_H
#define SEARCH_EMPLOYEE_H
#include <QDialog>

namespace Ui {class search_employee;}

class search_employee : public QDialog
{
    Q_OBJECT

public:
    explicit search_employee(QWidget *parent = nullptr);
    ~search_employee();
    void search_get_director(QString &A, QString &F);
    void search_get_teacher(QString &A, QString &F);
    void search_get_guard(QString &A, QString &F);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::search_employee *ui;
};

#endif // SEARCH_EMPLOYEE_H
