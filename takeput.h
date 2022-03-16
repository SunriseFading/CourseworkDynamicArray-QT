#ifndef TAKEPUT_H
#define TAKEPUT_H

#include <QDialog>

namespace Ui {
class takeput;
}

class takeput : public QDialog
{
    Q_OBJECT

public:
    explicit takeput(QWidget *parent = nullptr);
    ~takeput();
    void taker(QString sohr);
private slots:
    void on_pushButton_clicked();

private:
    Ui::takeput *ui;
};

#endif // TAKEPUT_H
