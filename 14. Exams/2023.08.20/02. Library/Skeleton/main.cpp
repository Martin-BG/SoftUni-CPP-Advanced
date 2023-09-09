#include <string>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

class Book {

    size_t id;
    string title;
    string author;

    string borrower;

public:
    Book() = default;

    Book(size_t id, istream & istr) : id(id) {

        getline(istr, author);
        getline(istr, title);

    }

    size_t getId() const { return id; }
    const string & getTitle() const { return title; }
    const string & getAuthor() const { return author; }
    const string & getBorrower() const { return borrower; }

    void setBorrowed(const string & reader = "") { borrower = reader; }

};

#include "input.h"

int main(void) {

    typedef map<size_t, Book> Books;
    Books books;

    read<Book>(books, cin);

    while(true) {

        size_t command;
        cin >> command;
        if (command == 0)
            break;

        int bookID;
        cin >> bookID;

        string borrower;
        switch(command) {
            case 1:
                print<Book>(books[bookID], cout);
                break;
            case 2:
                cin >> borrower;
                borrow<Book>(books[bookID], borrower);
                break;
            case 3:
                borrow<Book>(books[bookID]);
                break;
            
        }
    }

    print<map<size_t, Book> *>(&books, cout);

    return 0;
}