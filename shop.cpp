#include "shop.h"
#include "ui_shop.h"

Shop::Shop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if (db.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }
    query1 = new QSqlQuery(db);
    query1->exec("CREATE TABLE IF NOT EXISTS BOOK_SHOP(NAME TEXT, AUTHOR TEXT, ID INT, PRICE INT);");


    model1 = new QSqlTableModel(this,db);
    model1->setTable("BOOK_SHOP");
    model1->select();


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

    model2 = new QSqlTableModel(this,db);
    model2->setTable("ORDER_LIST");
    model2->select();

    ui->table->setModel(model1);
}

Shop::~Shop()
{
    delete ui;
}



void Shop::on_purchase_clicked()
{
    Purchase tap;
    tap.setModal(true);
    tap.exec();
}


void Shop::on_add_clicked()
{
    QString _name=nullptr;
    QString _author=nullptr;
    int _id=0;
    int _price=0;
        int rowidx = ui->table->selectionModel()->currentIndex().row();
           _name=(model1->index(rowidx , 0).data().toString());
           _author=(model1->index(rowidx , 1).data().toString());
          _id=(model1->index(rowidx , 2).data().toInt());
           _price=(model1->index(rowidx , 3).data().toInt());

             order.setName(_name);
             order.setAuthor(_author);
             order.setID(_id);
             order.setPrice(_price);

             _name=nullptr;
             _author=nullptr;
             _id=0;
             _price=0;

     QSqlQuery query2;
        if(query2.isActive())
                qDebug() << "123";

      query2.prepare("INSERT INTO ORDER_LIST(NAME, AUTHOR, ID, PRICE) VALUES(:name, :author, :id, :price)");
      query2.bindValue(":name", order.getName());
      query2.bindValue(":author", order.getAuthor());
      query2.bindValue(":id", order.getId());
      query2.bindValue(":price",order.getPrice());
      query2.exec();
      model2->select();
    }





