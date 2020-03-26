// This is the application file of Project 9: A database of books.
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 5/2/2018

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "JoshLewisProj9.h"

using namespace std;
using namespace bookDataBase;

void addNewBook(vector<Book> &bookdata);
void printBooks(vector<Book> &bookdata);
void sortBooks(vector<Book> &bookdata);
void printMenu();

int main()

{
    vector<Book> bookdata;
    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: addNewBook(bookdata);
                break;
            case 2: printBooks(bookdata);
                break;
        }
    } while(choice != 3);
    
    
    return 0;
    
}

void addNewBook(vector<Book> &bookdata)
{
    string newAuthor, newTitle, newDate;
    
    cout << "Enter author name: " << endl;
    getline(cin, newAuthor);
    
    cout << "Enter book title: " << endl;
    getline(cin, newTitle);
    
    cout << "Enter published date: " << endl;
    getline(cin, newDate);
    
    Book b(newAuthor, newTitle, newDate);
    bookdata.push_back(b);
}

void printBooks(vector<Book> &bookdata)
{
    sortBooks(bookdata);
    cout << "The books entered so far, sorted by author: " << endl;
    
    for(int i = 0; i < bookdata.size; i++) {
        cout << bookdata[i].getAuthor() << ", " << bookdata[i].getTitle << ", " <<
        bookdata[i].getDate() << endl;
    }
}

void sortBooks(vector<Book> &bookdata)
{
    sort(bookdata.begin(), bookdata.end());
}

void printMenu()
{
    cout << "Select from the following choices: " << endl;
    cout << "1. Add new book to database" << endl;
    cout << "2. Print books sorted by author" << endl;
    cout << "3. Quit" << endl;
}
