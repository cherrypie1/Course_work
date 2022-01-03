#ifndef SHOP_H
#define SHOP_H

#include "purchase.h"
#include "libraries.h"
#include "purchase.h"
#include "book.h"
#include "books.h"


namespace Ui {
class Shop;
}

class Shop : public QDialog
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = nullptr);
    ~Shop();

private slots:

    void on_purchase_clicked();

    void on_add_clicked();

private:
    Ui::Shop *ui;
    QSqlDatabase db;
    QSqlDatabase dba;
    QSqlQuery *query1;
    QSqlQuery *query2;
    QSqlTableModel *model1;
    QSqlTableModel *model2;
    Book order;
};

#endif // SHOP_H
