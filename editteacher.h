#ifndef EDITTEACHER_H
#define EDITTEACHER_H
#include <QDialog>

namespace Ui {class editteacher;}

class editteacher : public QDialog
{
    Q_OBJECT

public:
    explicit editteacher(QWidget *parent = nullptr);
    ~editteacher();
    void takeeditteacher(QString &A, QString &B, QString &C, QString &D, QString &E, QString &E1, QString &E2, QString &G);
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::editteacher *ui;
};

#endif // EDITTEACHER_H
