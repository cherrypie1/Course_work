#include "books.h"
#include "ui_books.h"

Books::Books(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Books)
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
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE IF NOT EXISTS BOOK_SHOP(NAME TEXT, AUTHOR TEXT, ID INT, PRICE INT);");

    model = new QSqlTableModel(this,db);
    model->setTable("BOOK_SHOP");
    model->select();

    ui->tableView->setModel(model);
}

Books::~Books()
{
    delete ui;
}

void Books::on_add_button_clicked()
{
    if(ui->name->text() == "" || ui->author->text() == "" ||ui->price->text() == "" ||ui->id->text() == ""){
       QMessageBox::information(this, "error", "Вы заполнили не все поля");
       return;
    }
    book.setName(ui->name->text());
    book.setAuthor(ui->author->text());
    book.setID(ui->id->text().toInt());
    book.setPrice(ui->price->text().toInt());
    QSqlQuery query;
    if(query.isActive())
        qDebug() << "123";
    query.prepare("INSERT INTO BOOK_SHOP(NAME, AUTHOR, ID, PRICE) VALUES(:name, :author, :id, :price)");
    query.bindValue(":name", book.getName());
    query.bindValue(":author", book.getAuthor());
    query.bindValue(":id", book.getId());
    query.bindValue(":price", book.getPrice());
    query.exec();
    ui->name->setText("");
    ui->author->setText("");
    ui->id->setText("");
    ui->price->setText("");
    model->select();
}




void Books::on_delete_button_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if(selectedRow >= 0){
        model->removeRow(selectedRow);
    }
    else{
        qDebug() << "no row selected";
    }
     model->select();
}


