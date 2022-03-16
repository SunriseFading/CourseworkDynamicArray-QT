#ifndef EDITDIRECTOR_H
#define EDITDIRECTOR_H

#include <QDialog>

namespace Ui {class editdirector;}

class editdirector : public QDialog
{
    Q_OBJECT

public:
    explicit editdirector(QWidget *parent = nullptr);
    ~editdirector();
    void takeeditdirector(QString &A, QString &B, QString &C, QString &D, QString &E, QString &G);
private slots:
    void on_pushButton_clicked();

private:
    Ui::editdirector *ui;
};

#endif // EDITDIRECTOR_H
