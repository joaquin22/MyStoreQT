#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include <string>

namespace Ui {
class Item;
}

class Item : public QWidget
{
    Q_OBJECT

public:
    explicit Item(QWidget *parent = nullptr);
    void setData(std::string name,std::string stock,std::string price);
    void hideButton();
    ~Item();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Item *ui;
};

#endif // ITEM_H
