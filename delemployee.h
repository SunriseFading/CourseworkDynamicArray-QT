#ifndef DELEMPLOYEE_H
#define DELEMPLOYEE_H

#include <QDialog>

namespace Ui {class delemployee;}

class delemployee : public QDialog
{
    Q_OBJECT

public:
    explicit delemployee(QWidget *parent = nullptr);
    ~delemployee();
    void deldirector(QString &A, QString &F);
    void delteacher(QString &A, QString &F);
    void delguard(QString &A, QString &F);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::delemployee *ui;
};

#endif // DELEMPLOYEE_H
