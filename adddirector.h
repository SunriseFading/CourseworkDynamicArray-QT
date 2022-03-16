#ifndef ADDDIRECTOR_H
#define ADDDIRECTOR_H

#include <QDialog>

namespace Ui {class adddirector;}

class adddirector : public QDialog
{
    Q_OBJECT

public:
    explicit adddirector(QWidget *parent = nullptr);
    ~adddirector();
    void takedirector(QString &A, QString &B, QString &C, QString &D, QString &E);
private slots:
    void on_pushButton_clicked();

private:
    Ui::adddirector *ui;
};

#endif // ADDDIRECTOR_H
