#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "libraries.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_user_button_clicked();

    void on_book_button_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
