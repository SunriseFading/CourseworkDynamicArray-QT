#ifndef EDITGUARD_H
#define EDITGUARD_H
#include <QDialog>

namespace Ui {class editguard;}

class editguard : public QDialog
{
    Q_OBJECT

public:
    explicit editguard(QWidget *parent = nullptr);
    ~editguard();
    void takeeditguard(QString &A, QString &B, QString &C, QString &D, QString &E, QString &E1, QString &G);
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::editguard *ui;
};

#endif // EDITGUARD_H
