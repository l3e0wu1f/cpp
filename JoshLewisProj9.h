// This is the interface file of Project 9: A database of books.
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 5/2/2018

#ifndef JoshLewisProj9_h
#define JoshLewisProj9_h
#include <string>
#include "JoshLewisProj9.h"

using namespace std;
namespace bookDataBase {
    class Book {
    public:
        Book();
        Book(string new_author, string new_title, string new_date);
        void setData(string new_author, string new_title, string new_date);
        string getAuthor() const;
        string getTitle() const;
        string getDate() const;
        friend bool operator <(const Book &book1, const Book &book2);
    private:
        string author;
        string title;
        string date;
    };
}

#endif
