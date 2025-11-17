#include "mycartdialog.h"
#include "ui_mycartdialog.h"
#include "store.h"
#include "item.h"

MyCartDialog::MyCartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyCartDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Mi Carrito");
    loadMyCart();
}


void MyCartDialog::loadMyCart(){
    Store* store = Store::getInstance();
    json data = store->readJson("cart.json");
    //json products = data["products"];
    int num_col = 3;


    if (!data.is_null()){
        int i = 0;
        for (const auto& products : data["products"]) {
            Item *item = new Item();
            std::string name = products["name"];
            std::string stock = products["stock"];
            std::string price = products["price"];
            item->hideButton();
            item->setData(name,stock,price);
            int row = i / num_col;
            int col = i % num_col;
            ui->QBox->addWidget(item,row,col);
            i++;
        }
    }

    ui->scrollArea->setWidgetResizable(true);
}

MyCartDialog::~MyCartDialog()
{
    delete ui;
}
