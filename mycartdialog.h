#ifndef MYCARTDIALOG_H
#define MYCARTDIALOG_H

#include <QDialog>

namespace Ui {
class MyCartDialog;
}

class MyCartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyCartDialog(QWidget *parent = nullptr);
    void loadMyCart();
    ~MyCartDialog();

private:
    Ui::MyCartDialog *ui;
};

#endif // MYCARTDIALOG_H
