#ifndef TABSHOW_H
#define TABSHOW_H

#include <QDialog>

namespace Ui {class tabshow;}

class tabshow : public QDialog
{
    Q_OBJECT

public:
    explicit tabshow(QWidget *parent = nullptr);
    ~tabshow();
    void settab1(QString A, QString B, QString C, QString D, QString E);
    void settab2(QString A, QString B, QString C, QString D, QString E, QString E1, QString E2);
    void settab3(QString A, QString B, QString C, QString D, QString E, QString E1);
    void reset();
private slots:
    void on_pushButton_clicked();

private:
    Ui::tabshow *ui;

};

#endif // TABSHOW_H
