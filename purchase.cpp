#include "purchase.h"
#include "shop.h"
#include "ui_purchase.h"



Purchase::Purchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Purchase)
{
    ui->setupUi(this);

    dba = QSqlDatabase :: addDatabase("QSQLITE");
    dba.setDatabaseName("./order.db");
    if (dba.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }
    query2 = new QSqlQuery(dba);
    query2->exec("CREATE TABLE IF NOT EXISTS ORDER_LIST(NAME TEXT, AUTHOR TEXT, ID INT, PRICE INT);");

    model2 = new QSqlTableModel(this,dba);
    model2->setTable("ORDER_LIST");
    model2->select();
    ui->tableView->setModel(model2);

}

Purchase::~Purchase()
{
    delete ui;
}



void Purchase::on_ok_clicked()
{
    int _price=0;
    for(int row=0; row<model2->rowCount(); row++){
       _price=_price+(model2->index(row , 3).data().toInt());
    }

    QString q=QString::number(_price);
    ui->Count->setText(q);

    QFile file("D:/qtProjects/database/Data.txt");

      if(!file.open(QIODevice::Append | QIODevice::WriteOnly)){
          qDebug()<<"EROR";
      }
         if(ui->number->text() == "" || ui->surname->text() == "" ){
         QMessageBox::information(this, "error", "Вы заполнили не все поля");
         return;
      }

      QTextStream out(&file);

      QString sur = ui->surname->text();
      QString nam = ui->number->text();

      out << sur<<" "<<nam<<" "<< q <<" "<<"\\";

      file.flush();
      file.close();


     QSqlDatabase dba= QSqlDatabase::database();
     dba.close();
     QFile::remove("./order.db");

}


void Purchase::on_back_clicked()
{
    Shop bshow;
    bshow.setModal(true);
    bshow.exec();
}


void Purchase::on_delete_2_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if(selectedRow >= 0){
        model2->removeRow(selectedRow);
    }
    else{
        qDebug() << "no row selected";
    }
     model2->select();
}

