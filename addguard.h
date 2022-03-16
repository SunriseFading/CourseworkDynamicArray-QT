#ifndef ADDGUARD_H
#define ADDGUARD_H

#include <QDialog>

namespace Ui {class addguard;}

class addguard : public QDialog
{
    Q_OBJECT

public:
    explicit addguard(QWidget *parent = nullptr);
    ~addguard();
    void takeguard(QString &A, QString &B, QString &C, QString &D, QString &E, QString &E1);
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::addguard *ui;
};

#endif // ADDGUARD_H
