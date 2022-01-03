#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "books.h"
#include "shop.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_user_button_clicked()
{
    Shop sshow;
    sshow.setModal(true);
    sshow.exec();
}


void MainWindow::on_book_button_clicked()
{
    Books bshow;
    bshow.setModal(true);
    bshow.exec();
}


