#include "item.h"
#include "ui_item.h"

Item::Item(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Item)
{
    ui->setupUi(this);

    const QString url = "D:/ULS/LP1/MyStoreQT/2922280_27002.jpg";
    ui->lbl_image->setScaledContents(true);
    ui->lbl_image->setPixmap(url);

}

Item::~Item()
{
    delete ui;
}
