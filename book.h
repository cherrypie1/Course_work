#ifndef BOOK_H
#define BOOK_H

#include "libraries.h"

class Book
{
private:
    QString name;
    QString author;
    int ID;
    int price;
public:
    Book();
    ~Book();
    Book(QString, QString, int, int);
    QString getName();
    QString getAuthor();
    int getId();
    int getPrice();
    void setName(QString bookname);
    void setAuthor(QString bookauthor);
    void setID(int id);
    void setPrice(int bookprice);
};

#endif // BOOK_H
