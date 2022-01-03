#include "book.h"

Book::Book(){

}

Book::Book(QString _name,  QString _author, int _id, int _price):name(_name), author(_author), ID(_id),price(_price){

}


Book::~Book(){

}

QString Book::getName(){
        return name;
    }

QString Book::getAuthor(){
    return author;
}

int Book::getId(){
    return ID;
}

int Book::getPrice(){
    return price;
}

void Book::setName(QString bookname)
{
    name=bookname;
}

void Book::setAuthor(QString bookauthor){
    author=bookauthor;
}

void Book::setID(int id){
    ID=id;
}

void Book::setPrice(int _price){
    price=_price;
}

