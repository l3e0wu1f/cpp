// This is the implementation file of Project 9: A database of books.
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 5/2/2018

#include <string>
#include "JoshLewisProj9.h"

namespace bookDatabase {
    Book::Book():author(""), title(""), date("") {}
    void Book(string new_author, string new_title, string new_date):author(new_author),
    title(new_title), date(new_date) {}
    void Book::setData(string new_author, string new_title, string new_date) {
        author = new_author;
        title = new_title;
        date = new_date;
    }
    string Book::getAuthor() const {
        return author;
    }
    string Book::getTitle() const {
        return title;
    }
    string Book::getDate() const {
        return date;
    }
    bool operator <(const Book &book1, const Book &book2) {
        return (book1.author < book2.author);
    }
}



