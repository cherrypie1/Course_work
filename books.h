#ifndef BOOKS_H
#define BOOKS_H

#include "libraries.h"
#include "book.h"

namespace Ui {
class Books;
}

class Books : public QDialog
{
    Q_OBJECT

public:
    explicit Books(QWidget *parent = nullptr);
    ~Books();

private slots:
    void on_add_button_clicked();

    void on_delete_button_clicked();

private:
    Ui::Books *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    Book book;
};

#endif // BOOKS_H
