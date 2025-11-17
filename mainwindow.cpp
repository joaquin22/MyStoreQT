#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include "mycartdialog.h"
#include "item.h"
#include "store.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tienda Virtual");
    refreshView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addProducts_clicked()
{
    Dialog *productDialog = new Dialog(this);
    connect(productDialog, &Dialog::refreshView,
            this, &MainWindow::refreshView);
    productDialog->exec();
    productDialog->deleteLater();

}

void MainWindow::refreshView(){
    Store* store = Store::getInstance();
    json data = store->readJson("productos.json");
    //json products = data["products"];
    int num_col = 3;


    if (!data.is_null()){
        int i = 0;
        for (const auto& products : data["products"]) {
            Item *item = new Item();
            std::string name = products["name"];
            std::string stock = products["stock"];
            std::string price = products["price"];
            item->setData(name,stock,price);
            int row = i / num_col;
            int col = i % num_col;
            ui->QBox->addWidget(item,row,col);
            i++;
        }
    }

    ui->scrollArea->setWidgetResizable(true);
}

void MainWindow::on_myCart_clicked()
{
    MyCartDialog *myCartDialog = new MyCartDialog(this);
    myCartDialog->exec();
    myCartDialog->deleteLater();
}

