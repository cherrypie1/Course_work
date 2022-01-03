#ifndef PURCHASE_H
#define PURCHASE_H


#include "libraries.h"
#include <QDialog>

namespace Ui {
class Purchase;
}

class Purchase : public QDialog
{
    Q_OBJECT

public:
    explicit Purchase(QWidget *parent = nullptr);
    ~Purchase();


private slots:

    void on_ok_clicked();

    void on_back_clicked();

    void on_delete_2_clicked();

private:
    Ui::Purchase *ui;
    QSqlDatabase dba;
    QSqlQuery *query2;
    QSqlTableModel *model2;
};

#endif // PURCHASE_H
