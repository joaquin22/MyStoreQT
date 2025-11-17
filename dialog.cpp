#include "dialog.h"
#include "ui_dialog.h"
#include "store.h"
#include "Product.h"

#include <string>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    Store *store = new Store();
    std::string name = ui->input_name->text().toStdString();
    std::string stock = ui->input_stock->text().toStdString();
    std::string price = ui->input_price->text().toStdString();

    Product product = {
        name,stock,price
    };
    store->saveJson(product,"productos.json");
}

