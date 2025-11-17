#include "item.h"
#include "ui_item.h"
#include "store.h"

Item::Item(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Item)
{
    ui->setupUi(this);

}

void Item::setData(std::string name,std::string stock,std::string price){
    const QString url = "D:/ULS/LP1/MyStoreQT/2922280_27002.jpg";
    ui->lbl_product_name->setText(QString::fromStdString(name));
    ui->lbl_price->setText(QString::fromStdString(price));
    ui->lbl_stock->setText(QString::fromStdString(stock));

    ui->lbl_image->setScaledContents(true);
    ui->lbl_image->setPixmap(url);
}

Item::~Item()
{
    delete ui;
}

void Item::on_pushButton_clicked()
{
    Store* store = Store::getInstance();

    std::string name = ui->lbl_product_name->text().toStdString();
    std::string stock = ui->lbl_stock->text().toStdString();
    std::string price = ui->lbl_price->text().toStdString();
    Product product = {
        name,stock,price

    };
    store->saveJson(product,"cart.json");
}


void Item::hideButton(){
    ui->pushButton->hide();
}
