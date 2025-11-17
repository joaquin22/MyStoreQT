#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include "item.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addProducts_clicked()
{
    Dialog *productDialog = new Dialog(this);
    productDialog->show();
/*
    int num_col = 3;

    for (int i = 0; i <10;i++){
        Item *item = new Item();
        int row = i / num_col;
        int col = i % num_col;
        ui->QBox->addWidget(item,row,col);
    }

    ui->scrollArea->setWidgetResizable(true);
*/
}

